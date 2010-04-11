/* LinearMultiFit.cpp
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

#include "LinearMultiFit.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

LinearMultiFit::LinearMultiFit(size_t dataNumber, size_t variableNumber)
{
	wSpace = gsl_multifit_linear_alloc(dataNumber, variableNumber);
}

LinearMultiFit::~LinearMultiFit(){
	gsl_multifit_linear_free(wSpace);
}

void LinearMultiFit::GetParameters(Matrix ^ xMatrix, Vector ^ yVector, Matrix ^ %cov, Vector ^ %parameters, [Out] double %error){
	double chi;
	gsl_multifit_linear(xMatrix->matrix, yVector->vector, parameters->vector, cov->matrix, &chi, wSpace);
	error = chi;
}

void LinearMultiFit::GetParameters(Matrix ^ xMatrix, Vector ^ yVector, Matrix ^ %cov, Vector ^ weight, Vector ^ %parameters, [Out] double %error){
	double chi;
	gsl_multifit_wlinear(xMatrix->matrix, weight->vector, yVector->vector, parameters->vector, cov->matrix, &chi, wSpace);
	error = chi;
}

}