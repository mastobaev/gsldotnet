/* OrdinaryDifferentialEquations.cpp
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

#include "OrdinaryDifferentialEquations.h"
#include "ErrorNumber.h"
#include <gsl/gsl_odeiv.h>

namespace GSLNET{

OrdinaryDifferentialEquations::OrdinaryDifferentialEquations(SolverType sType, int dimension)
{
	this->dimension = dimension;
	this->sType = sType;
	switch(sType){
		case SolverType::RungeKutta2:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_rk2, dimension);
			break;
		case SolverType::RungeKutta4:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_rk4, dimension);
			break;
		case SolverType::RungeKuttaFehlberg:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_rkf45, dimension);
			break;
		case SolverType::RungeKuttCashKarp:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_rkck, dimension);
			break;
		case SolverType::RungeKuttaPrinceDormand:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_rk8pd, dimension);
			break;
		case SolverType::ImplicitRungeKutta2:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_rk2imp, dimension);
			break;
		case SolverType::ImplicitRungeKutta4:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_rk4imp, dimension);
			break;
		case SolverType::BulirschStoer:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_bsimp, dimension);
			
			break;
		case SolverType::ImplicitGear1:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_gear1, dimension);
			break;
		case SolverType::ImplicitGear2:
			fSolver = gsl_odeiv_step_alloc(gsl_odeiv_step_gear2, dimension);
			break;	
	}
	//時間発展型ソルバのための領域確保
	evolve=gsl_odeiv_evolve_alloc(dimension);

	//状態変数の領域確保
	yVector = new double[dimension];

	//配列を初期化
	this->inputs = gcnew array<double>(dimension);
	this->outputs = gcnew array<double>(dimension);
	this->dydt = gcnew array<double>(dimension);
	this->jacobian = gcnew array<array<double>^>(dimension);
	for(int i=0;i<dimension;i++) jacobian[i] = gcnew array<double>(dimension);
}

void OrdinaryDifferentialEquations::SetStandardControl(double eps_abs, double eps_rel, double a_y, double a_dydt){
	odeCtrl = gsl_odeiv_control_standard_new(eps_abs, eps_rel, a_y, a_dydt);
}


void OrdinaryDifferentialEquations::SetYControl(double eps_abs, double eps_rel){
	odeCtrl = gsl_odeiv_control_y_new(eps_abs, eps_rel);
}

void OrdinaryDifferentialEquations::SetYPControl(double eps_abs, double eps_rel){
	odeCtrl = gsl_odeiv_control_yp_new(eps_abs, eps_rel);
}

void OrdinaryDifferentialEquations::SetScaledControl(double eps_abs, double eps_rel, double a_y, double a_dydt, array<double> ^ scale){
	double *scaling = (double*)malloc(sizeof(double) * dimension);
	for(int i=0;i<scale->Length;i++) scaling[i] = scale[i];
	odeCtrl = gsl_odeiv_control_scaled_new(eps_abs, eps_rel, a_y, a_dydt, scaling, dimension);
}

OrdinaryDifferentialEquations::~OrdinaryDifferentialEquations(){
	gsl_odeiv_step_free(fSolver);
	gsl_odeiv_control_free(odeCtrl);
	gsl_odeiv_evolve_free(evolve);

	delete(yVector);
}

ErrorNumber OrdinaryDifferentialEquations::Solve(GSLFunctions::TDArrayToDArray ^eFnc, double %initialTime, double endTime, double %initialTStep, array<double> ^ %variables, [Out] int %iterNum){
	this->eFnc = eFnc;
	GCHandle gch = GCHandle::Alloc(this, GCHandleType::Normal);
	IntPtr ip = GCHandle::ToIntPtr(gch);
	gsl_odeiv_system sys = {&odeErrorFunction, &odeErrorFunctionFD, dimension, ip.ToPointer()};
	for(int i=0;i<dimension;i++) yVector[i] = variables[i];
	double iniT = initialTime;
	double tStep = initialTStep;

	iterNum = 0;
	while(iniT < endTime){
		iterNum++;
		int status = gsl_odeiv_evolve_apply(evolve, odeCtrl, fSolver, &sys, &iniT, endTime, &tStep, yVector);
		if(status != GSL_SUCCESS) break;
		if(IntermediateOutput) IntermediateOutput(iniT, this->inputs);
	}
	initialTime = iniT;
	initialTStep = tStep;
	for(int i=0;i<dimension;i++) variables[i] = yVector[i];

	gch.Free();

	return ErrorNumber::GSL_SUCCESS;
}

}

