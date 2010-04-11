/* Root.cpp
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

#include "Root.h"
#include "ErrorNumber.h"
#include <gsl/gsl_errno.h>

using namespace System::Runtime::InteropServices;
using namespace System;

namespace GSLNET{

Root::Root(SolverType sType)
{
	//Žû‘©”»’èŠî€‰Šú‰»
	ConvergenceType = Convergence::Interval;
	RelativeError = 0.0001;
	AbsoluteError = 0.0001;

	//‰ð–@‚É‰ž‚¶‚Ä‰Šú‰»
	switch(sType){
		case Root::SolverType::Bisection:
			solver = gsl_root_fsolver_alloc(gsl_root_fsolver_bisection);
			break;
		case Root::SolverType::BrentDekker:
			solver = gsl_root_fsolver_alloc(gsl_root_fsolver_falsepos);
			break;
		case Root::SolverType::FalsePosition:
			solver = gsl_root_fsolver_alloc(gsl_root_fsolver_brent);
			break;
	}
}

Root::~Root(){
	gsl_root_fsolver_free(solver);
}

ErrorNumber Root::Solve(GSLFunctions::DToD ^ eFnc, double lowerX, double upperX, int maxIteration, [Out] double %xValue){

	this->eFnc = eFnc;

	gsl_function f;
	f.function = &rootsFunction;

	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	f.params = ip.ToPointer();

	gsl_root_fsolver_set(solver, &f, lowerX, upperX);

	int status;
	iteration = 0;
	double oldX = gsl_root_fsolver_root(solver);
	do{
		iteration++;

		status = gsl_root_fsolver_iterate(solver);
		if(status != (int)ErrorNumber::GSL_SUCCESS) break;
		xValue=gsl_root_fsolver_root(solver);

		switch(ConvergenceType){
			case Convergence::Delta:
				status = gsl_root_test_delta(xValue, oldX, AbsoluteError, RelativeError);
				oldX = xValue;
				break;
			case Convergence::Interval:
				lowerX = gsl_root_fsolver_x_lower(solver);
				upperX = gsl_root_fsolver_x_upper(solver);
				status=gsl_root_test_interval(lowerX, upperX, AbsoluteError, RelativeError);
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

	xValue = gsl_root_fsolver_root(solver);

	gch.Free();

	return (GSLNET::ErrorNumber)status;
}

}