/* Minimization.cpp
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

#include <gsl/gsl_errno.h>
#include "Minimization.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace GSLNET{

Minimization::Minimization(SolverType sType)
{
	//‰ð–@‚É‰ž‚¶‚Ä‰Šú‰»
	switch(sType){
		case SolverType::Brent:
			minimizer = gsl_min_fminimizer_alloc(gsl_min_fminimizer_brent);
			break;
		case SolverType::GoldenSection:
			minimizer = gsl_min_fminimizer_alloc(gsl_min_fminimizer_goldensection);
			break;
	}
}

Minimization::~Minimization(){
	gsl_min_fminimizer_free(minimizer);
}

ErrorNumber Minimization::Solve(GSLNET::GSLFunctions::DToD ^minimizeFunction, double lowerX, double upperX,
								double epsAbs, double epsRel, int maxIter, double %xValue){

	this->eFnc = minimizeFunction;

	gsl_function fnc;
	fnc.function = &minimizationFunction;

	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	fnc.params = ip.ToPointer();

	gsl_min_fminimizer_set(minimizer, &fnc, xValue, lowerX, upperX);

	int status;
	iteration=0;
	do{
		iteration++;
		status = gsl_min_fminimizer_iterate(minimizer);
		double a = gsl_min_fminimizer_x_lower(minimizer);
		double b = gsl_min_fminimizer_x_upper(minimizer);
		status = gsl_min_test_interval(a, b, epsAbs, epsRel);
	}
	while (status == GSL_CONTINUE && iteration < maxIter);

	xValue = gsl_min_fminimizer_x_minimum(minimizer);

	gch.Free();

	return (ErrorNumber)status;
}

}
