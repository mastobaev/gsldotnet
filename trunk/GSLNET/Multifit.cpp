/* Multifit.cpp
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

#include "Multifit.h"

#include <gsl/gsl_multifit_nlin.h>
#include <gsl/gsl_blas.h>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace GSLNET{

Multifit::Multifit(Multifit::SolverType sType, size_t dataNumber, size_t parameterNumber)
{
	//âñ@Ç…âûÇ∂Çƒèâä˙âª
	switch(sType){
		case SolverType::LevenbergMarquardtWithScaling:
			fSolver = gsl_multifit_fdfsolver_alloc(gsl_multifit_fdfsolver_lmsder, dataNumber, parameterNumber);
			break;
		case SolverType::LevenbergMarquardt:
			fSolver = gsl_multifit_fdfsolver_alloc(gsl_multifit_fdfsolver_lmder, dataNumber, parameterNumber);
			break;
	}

	//îzóÒÇèâä˙âª
	this->inputs = gcnew array<double>(parameterNumber);
	this->outputs = gcnew array<double>(dataNumber);
	this->jacobian = gcnew array<array<double>^>(parameterNumber);
	for(size_t i=0;i<parameterNumber;i++) jacobian[i] = gcnew array<double>(dataNumber);
	xVector = gsl_vector_alloc(parameterNumber);
	gVector = gsl_vector_alloc(parameterNumber);
}

GSLNET::ErrorNumber Multifit::Solve(GSLFunctions::DArrayToDArray ^eFnc, cli::array<double> ^ %initialX, double epsabs, double epsrel, int maxIteration, int %iterNum){

	this->eFnc = eFnc;
	int parameterNumber = initialX->Length;

	gsl_multifit_function_fdf fdf;
	fdf.f = &GSLNET::multifitErrorFunction;
	fdf.df = &GSLNET::multifitErrorFunctionFD;
	fdf.fdf = &GSLNET::multifitErrorFunctionFDF;
	fdf.n = outputs->Length;
	fdf.p = parameterNumber;
	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	fdf.params = ip.ToPointer();
	
	//èâä˙âª
	for(int i=0;i<parameterNumber;i++){
		gsl_vector_set(xVector, i, initialX[i]);
	}
	gsl_multifit_fdfsolver_set(fSolver, &fdf, xVector);

	iterNum = 0;
	int state;
	do{
		iterNum++;
		state = gsl_multifit_fdfsolver_iterate(fSolver);
		if(state != GSL_SUCCESS && state != GSL_CONTINUE) {
			for(int i=0;i<parameterNumber;i++) initialX[i] = gsl_vector_get(fSolver->x, i);
			return (ErrorNumber)state;
		}
		state = gsl_multifit_test_delta(fSolver->dx, fSolver->x, epsabs, epsrel);
	}while(state == GSL_CONTINUE && iterNum < maxIteration);

	for(int i=0;i<parameterNumber;i++) initialX[i] = gsl_vector_get(fSolver->x, i);

	gch.Free();

	if(maxIteration < iterNum) return ErrorNumber::GSL_EMAXITER;
	else return ErrorNumber::GSL_SUCCESS;
}

GSLNET::ErrorNumber Multifit::Solve(GSLFunctions::DArrayToDArray ^eFnc, cli::array<double> ^ %initialX, double epsabs, int maxIteration, int %iterNum){

	this->eFnc = eFnc;
	int parameterNumber = initialX->Length;

	gsl_multifit_function_fdf fdf;
	fdf.f = &GSLNET::multifitErrorFunction;
	fdf.df = &GSLNET::multifitErrorFunctionFD;
	fdf.fdf = &GSLNET::multifitErrorFunctionFDF;
	fdf.n = outputs->Length;
	fdf.p = parameterNumber;
	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	fdf.params = ip.ToPointer();

	//èâä˙âª
	for(int i=0;i<parameterNumber;i++){
		gsl_vector_set(xVector, i, initialX[i]);
	}
	gsl_multifit_fdfsolver_set(fSolver, &fdf, xVector);

	iterNum = 0;
	int state;
	do{
		iterNum++;
		state = gsl_multifit_fdfsolver_iterate(fSolver);
		if(state != GSL_SUCCESS && state != GSL_CONTINUE) {
			for(int i=0;i<parameterNumber;i++) initialX[i] = gsl_vector_get(fSolver->x, i);
			return (ErrorNumber)state;
		}
		gsl_multifit_gradient(fSolver->J, fSolver->f, gVector);
		state = gsl_multifit_test_gradient(gVector, epsabs);
	}while(state == GSL_CONTINUE && iterNum < maxIteration);

	for(int i=0;i<parameterNumber;i++) initialX[i] = gsl_vector_get(fSolver->x, i);

	gch.Free();

	if(maxIteration < iterNum) return ErrorNumber::GSL_EMAXITER;
	else return ErrorNumber::GSL_SUCCESS;
}

///<summary>écç∑ÇéÊìæÇ∑ÇÈ</summary>
double GSLNET::Multifit::GetResidualError(){
	return gsl_blas_dnrm2(fSolver->f);
}

GSLNET::Multifit::~Multifit(){
	gsl_vector_free(xVector);
	gsl_vector_free(gVector);
	gsl_multifit_fdfsolver_free(fSolver);
}

}
