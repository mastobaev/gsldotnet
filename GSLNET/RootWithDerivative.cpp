/* RootWithDerivative.cpp
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

#include "RootWithDerivative.h"
#include "ErrorNumber.h"
#include <gsl/gsl_errno.h>

using namespace System::Runtime::InteropServices;
using namespace System;

namespace GSLNET{

RootWithDerivative::RootWithDerivative(SolverType sType)
{
	//Žû‘©”»’èŠî€‰Šú‰»
	ConvergenceType = Convergence::Delta;
	DeltaH = 0.000001;
	RelativeError = 0.0001;
	AbsoluteError = 0.0001;

	//‰ð–@‚É‰ž‚¶‚Ä‰Šú‰»
	switch(sType){
		case RootWithDerivative::SolverType::Newton:
			solver = gsl_root_fdfsolver_alloc(gsl_root_fdfsolver_newton);
			break;
		case RootWithDerivative::SolverType::Secant:
			solver = gsl_root_fdfsolver_alloc(gsl_root_fdfsolver_secant);
			break;
		case RootWithDerivative::SolverType::Steffenson:
			solver = gsl_root_fdfsolver_alloc(gsl_root_fdfsolver_steffenson);
			break;
	}
}

RootWithDerivative::~RootWithDerivative(){
	gsl_root_fdfsolver_free(solver);
}

ErrorNumber RootWithDerivative::Solve(GSLFunctions::DToD ^eFnc, int maxIteration, double %xValue){
	hasFDFunction = false;
	this->eFnc = eFnc;

	return solve(maxIteration, xValue);
}

ErrorNumber RootWithDerivative::Solve(GSLFunctions::DToD ^eFnc, GSLFunctions::DToD ^ eFncDF, int maxIteration, double %xValue){
	hasFDFunction = true;
	this->eFnc = eFnc;
	this->eFncDF = eFncDF;

	return solve(maxIteration, xValue);
}

ErrorNumber RootWithDerivative::solve(int maxIteration, double %xValue){
	gsl_function_fdf fdf;
	fdf.f = &rootWithDerivativeFunction;
	fdf.df = &rootWithDerivativeFunctionDF;
	fdf.fdf = &rootWithDerivativeFunctionFDF;

	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	fdf.params = ip.ToPointer();

	gsl_root_fdfsolver_set(solver, &fdf, xValue);

	int status;
	iteration = 0;
	double oldX = gsl_root_fdfsolver_root(solver);
	do{
		iteration++;

		status = gsl_root_fdfsolver_iterate(solver);
		if(status != (int)ErrorNumber::GSL_SUCCESS) break;
		xValue=gsl_root_fdfsolver_root(solver);

		switch(ConvergenceType){
			case Convergence::Delta:
				status = gsl_root_test_delta(xValue, oldX, AbsoluteError, RelativeError);
				oldX = xValue;
				break;
			case Convergence::Residual:
				status = gsl_root_test_residual(eFnc(xValue), AbsoluteError);
				break;
		}

		if(maxIteration < iteration) {
			status = (int)ErrorNumber::GSL_EMAXITER;
			break;
		}
	}
	while (status == GSL_CONTINUE);

	xValue = gsl_root_fdfsolver_root(solver);

	gch.Free();

	return (GSLNET::ErrorNumber)status;
}

}