/* Polynomial.cpp
 * 
 * Copyright (C) 2009 E.Togashi
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

#include "Polynomial.h"
#include "Complex.h"
#include <gsl/gsl_errno.h>
using namespace System;

namespace GSLNET{

Polynomial::Polynomial(size_t order){
	ws = gsl_poly_complex_workspace_alloc(order + 1);
	a = (double *)malloc(sizeof(double) * (order + 1));
	z = (double *)malloc(sizeof(double) * (order + 1) * 2);
}

Polynomial::~Polynomial(){
	free(a);
	free(z);
	gsl_poly_complex_workspace_free(ws);
}

ErrorNumber Polynomial::Solve(array<double> ^ coef, array<Complex ^> ^ %roots){
	for(int i=0;i<coef->Length;i++){
		a[i] = coef[i];
	}
	int suc = gsl_poly_complex_solve(a, coef->Length, ws, z);
	for(int i=0;i<coef->Length - 1;i++){
		roots[i]->RealPart = z[2*i];
		roots[i]->ImaginaryPart = z[2*i + 1];
	}

	if(suc == GSL_SUCCESS) return ErrorNumber::GSL_SUCCESS;
	else return ErrorNumber::GSL_FAILURE;
}

double Polynomial::Evaluate(array<double> ^ coef, double x){
	double * c;
	c = (double *)malloc(sizeof(double) * coef->Length);
	for(int i=0;i<coef->Length;i++){
		c[i] = coef[i];
	}
	double rtn = gsl_poly_eval(c, coef->Length, x);
	free(c);
	return rtn;
}

Complex ^ Polynomial::Evaluate(array<double> ^ coef, Complex z){
	double * c;
	c = (double *)malloc(sizeof(double) * coef->Length);
	for(int i=0;i<coef->Length;i++){
		c[i] = coef[i];
	}
	Complex ^ zz = gcnew Complex();
	*zz->cmplx = gsl_poly_complex_eval(c, coef->Length, *z.cmplx);
	free(c);
	return zz;
}

Complex ^ Polynomial::Evaluate(array<Complex ^> ^ coef, Complex z){
	gsl_complex * c;
	c = (gsl_complex *)malloc(sizeof(gsl_complex) * coef->Length);
	for(int i=0;i<coef->Length;i++){
		c[i] = *coef[i]->cmplx;
	}
	Complex ^ zz = gcnew Complex();
	*zz->cmplx = gsl_complex_poly_complex_eval(c, coef->Length, *z.cmplx);
	free(c);
	return zz;
}

}
