/* Interpolation.cpp
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

#include "Interpolation.h"

namespace GSLNET{

Interpolation::Interpolation(size_t size, Method method)
{
	number = size;

	//åüçıópÉÅÉÇÉäóÃàÊ
	acc = gsl_interp_accel_alloc();

	//ï‚ä‘ñ@Çê›íË
	if(method == Method::Linear) spline = gsl_spline_alloc(gsl_interp_linear, size);
	else if(method == Method::Polynomial) spline = gsl_spline_alloc(gsl_interp_polynomial, size);
	else if(method == Method::CSpline) spline = gsl_spline_alloc(gsl_interp_cspline, size);
	else if(method == Method::CSpline_Periodic) spline = gsl_spline_alloc(gsl_interp_cspline_periodic, size);
	else if(method == Method::Akima) spline = gsl_spline_alloc(gsl_interp_akima, size);
	else spline = gsl_spline_alloc(gsl_interp_akima_periodic, size);
	
}

Interpolation::~Interpolation(){
	gsl_interp_accel_free(acc);
	gsl_spline_free(spline);
	free(x);
	free(y);
}

void Interpolation::Initialize(array<double> ^ x, array<double> ^ y){
	this->x = (double *)malloc(sizeof(double) * (x->Length));
	this->y = (double *)malloc(sizeof(double) * (y->Length));
	for(int i=0;i<x->Length;i++){
		*(this->x+i) = x[i];
		*(this->y+i) = y[i];
	}
	//èâä˙âª
	gsl_spline_init(spline, this->x, this->y, x->Length);
}

double Interpolation::Evaluate(double x){
	return gsl_spline_eval(spline, x, acc);
}

double Interpolation::EvaluateDerivative(double x){
	return gsl_spline_eval_deriv(spline, x, acc);
}

double Interpolation::EvaluateDerivative2(double x){
	return gsl_spline_eval_deriv2(spline, x, acc);
}

double Interpolation::EvaluateIntegral(double x1, double x2){
	return gsl_spline_eval_integ(spline, x1, x2, acc);
}

}