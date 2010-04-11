/* MultiRoot.cpp
 * 
 * Copyright (C) 2008 E.Togashi
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "MultiRoot.h"

#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_errno.h>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace GSLNET{

MultiRoot::MultiRoot(SolverType type, size_t n)
{
	//解法に応じて初期化
	switch(type){
		case SolverType::Broyden:
			fSolver = gsl_multiroot_fsolver_alloc(gsl_multiroot_fsolver_broyden, n);
			break;
		case SolverType::Hybrid:
			fSolver = gsl_multiroot_fsolver_alloc(gsl_multiroot_fsolver_hybrid, n);
			break;
		case SolverType::Newton:
			fSolver = gsl_multiroot_fsolver_alloc(gsl_multiroot_fsolver_dnewton, n);
			break;
		case SolverType::ScalingHybrid:
			fSolver = gsl_multiroot_fsolver_alloc(gsl_multiroot_fsolver_hybrids, n);
			break;
	}

	//配列を初期化
	this->inputs = gcnew array<double>(n);
	this->outputs = gcnew array<double>(n);
	this->dX = gcnew array<double>(n);
}

ErrorNumber MultiRoot::Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, double epsrel, int maxIteration, [Out] int %iterNum){
	//配列を初期化
	int dimension = initialX->Length;
	initialX->CopyTo(inputs, 0);

	gsl_vector *x = gsl_vector_alloc(dimension);
	for(int i=0;i<dimension;i++){
		gsl_vector_set(x, i, initialX[i]);
	}

	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	this->eFnc = eFnc;
	gsl_multiroot_function func= {&multiRootErrorFunction, dimension, ip.ToPointer()};
	gsl_multiroot_fsolver_set(fSolver, &func, x);

	iterNum = 0;
	while(true){
		if(maxIteration < iterNum) return ErrorNumber::GSL_EMAXITER;

		int state = gsl_multiroot_fsolver_iterate(fSolver);
		if(state != GSL_SUCCESS) {
			for(int i=0;i<dimension;i++) initialX[i] = gsl_vector_get(fSolver->x, i);		
			return (ErrorNumber)state;
		}

		state = gsl_multiroot_test_delta(gsl_multiroot_fsolver_dx(fSolver), gsl_multiroot_fsolver_root(fSolver), epsabs, epsrel);
		if(state == GSL_SUCCESS) break;

		iterNum++;
	}

	for(int i=0;i<dimension;i++){
		initialX[i] = gsl_vector_get(fSolver->x, i);
	}

	gch.Free();

	return ErrorNumber::GSL_SUCCESS;
}

ErrorNumber MultiRoot::Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, int maxIteration, [Out] int %iterNum){
	//配列を初期化
	int dimension = initialX->Length;
	initialX->CopyTo(inputs, 0);

	gsl_vector *x = gsl_vector_alloc(dimension);
	for(int i=0;i<dimension;i++){
		gsl_vector_set(x, i, initialX[i]);
	}
	
	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	this->eFnc = eFnc;
	gsl_multiroot_function func= {&multiRootErrorFunction, dimension, ip.ToPointer()};
	gsl_multiroot_fsolver_set(fSolver, &func, x);

	iterNum = 0;
	while(true){
		if(maxIteration < iterNum) return ErrorNumber::GSL_EMAXITER;

		int state = gsl_multiroot_fsolver_iterate(fSolver);
		if(state != GSL_SUCCESS) {
			for(int i=0;i<dimension;i++) initialX[i] = gsl_vector_get(fSolver->x, i);
			return (ErrorNumber)state;
		}

		state = gsl_multiroot_test_residual(gsl_multiroot_fsolver_f(fSolver), epsabs);
		if(state == GSL_SUCCESS) break;

		iterNum++;
	}

	for(int i=0;i<dimension;i++){
		initialX[i] = gsl_vector_get(fSolver->x, i);
	}

	gch.Free();

	return ErrorNumber::GSL_SUCCESS;
}

array<double>^ MultiRoot::GetRoots(){
	int dimension = inputs->Length;
	gsl_vector *vec = gsl_multiroot_fsolver_root(fSolver);
	for(int i=0;i<dimension;i++){
		inputs[i] = gsl_vector_get(vec,i);
	}
	return inputs;
}

array<double>^ MultiRoot::GetOutputs(){
	int dimension = inputs->Length;
	gsl_vector *vec = gsl_multiroot_fsolver_f(fSolver);
	for(int i=0;i<dimension;i++){
		outputs[i] = gsl_vector_get(vec,i);
	}
	return outputs;
}

array<double>^ MultiRoot::GetDx(){
	int dimension = inputs->Length;
	gsl_vector *vec = gsl_multiroot_fsolver_dx(fSolver);
	for(int i=0;i<dimension;i++){
		dX[i] = gsl_vector_get(vec,i);
	}
	return dX;
}

MultiRoot::~MultiRoot(){
	gsl_multiroot_fsolver_free(fSolver);
}


}