/* OrdinaryDifferentialEquations.h
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

#pragma once

#include "ErrorNumber.h"
#include "GSLFunctions.h"
#include "Jacobian.h"
#include <gsl/gsl_odeiv.h>
#include <gsl/gsl_vector.h>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class OrdinaryDifferentialEquations
{
public:
	///<summary>常微分方程式の解法の種類</summary>
	enum class SolverType {
		///<summary>埋め込み型RK23公式</summary>
		RungeKutta2,
		///<summary>四次のルンゲ・クッタ法</summary>
		RungeKutta4,
		///<summary>埋め込み型RKF45公式</summary>
		RungeKuttaFehlberg,
		///<summary>埋め込み型RKCK45公式</summary>
		RungeKuttCashKarp,
		///<summary>埋め込み型RKPD89公式</summary>
		RungeKuttaPrinceDormand,
		///<summary>二次の陰的ルンゲ・クッタ法</summary>
		ImplicitRungeKutta2,
		///<summary>四次の陰的ルンゲ・クッタ法</summary>
		ImplicitRungeKutta4,
		///<summary>陰的ブリルシュ・ストア法</summary>
		BulirschStoer,
		///<summary>M=1の陰的ギア法</summary>
		ImplicitGear1,
		///<summary>M=2の陰的ギア法</summary>
		ImplicitGear2,
	};

	///<summary>コンストラクタ</summary>
	///<param name="sType">常微分方程式の解法の種類</param>
	///<param name="dimension">次数</param>
	OrdinaryDifferentialEquations(SolverType sType, int dimension);

	///<summary>常微分方程式の解法の種類を取得する</summary>
	property SolverType Solver {
        SolverType get() { return this->sType; }
    }

	///<summary>標準のステップ幅調整関数を設定する</summary>
	///<param name="eps_abs">絶対誤差</param>
	///<param name="eps_rel">相対誤差</param>
	///<param name="a_y">解y(t)に対するスケーリング係数</param>
	///<param name="a_dydt">導関数y'(t)に対するスケーリング係数</param>
	void SetStandardControl(double eps_abs, double eps_rel, double a_y, double a_dydt);

	///<summary>解の値に対する誤差に基づいてステップ幅調整を行うように設定する</summary>
	///<param name="eps_abs">絶対誤差</param>
	///<param name="eps_rel">相対誤差</param>
	void SetYControl(double eps_abs, double eps_rel);

	///<summary>解の微分値に対する誤差に基づいてステップ幅調整を行うように設定する</summary>
	///<param name="eps_abs">絶対誤差</param>
	///<param name="eps_rel">相対誤差</param>
	void SetYPControl(double eps_abs, double eps_rel);

	///<summary>スケーリングつきのステップ幅調整関数を設定する</summary>
	///<param name="eps_abs">絶対誤差</param>
	///<param name="eps_rel">相対誤差</param>
	///<param name="a_y">解y(t)に対するスケーリング係数</param>
	///<param name="a_dydt">導関数y'(t)に対するスケーリング係数</param>
	///<param name="scale">各要素に対するスケーリング配列</param>
	void SetScaledControl(double eps_abs, double eps_rel, double a_y, double a_dydt, array<double> ^ scale);

	///<summary>初期値問題を解く</summary>
	///<param name="eFnc">微分値計算関数</param>
	///<param name="initialTime">初期時刻</param>
	///<param name="endTime">最終時刻</param>
	///<param name="initialTStep">初期ΔT</param>
	///<param name="variables">状態変数初期値</param>
	ErrorNumber Solve(GSLFunctions::TDArrayToDArray ^eFnc, double %initialTime, double endTime, double %initialTStep, array<double> ^ %variables, [Out] int %iterNum);

	///<summary>途中経過書き出し処理</summary>
	GSLFunctions::TDArray ^ IntermediateOutput;

private:
	int dimension;
	~OrdinaryDifferentialEquations();
	gsl_odeiv_step *fSolver;
	SolverType sType;
	gsl_odeiv_control *odeCtrl;
	gsl_odeiv_evolve *evolve;
	double * yVector;

internal:
	GSLFunctions::TDArrayToDArray ^eFnc;
	array<double>^ inputs;
	array<double>^ outputs;
	array<double>^ dydt;
	array<array<double>^>^ jacobian;
};

int __cdecl odeErrorFunction (double t, const double y[], double dydt[], void* params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	OrdinaryDifferentialEquations^ ode = (OrdinaryDifferentialEquations^)gch.Target;

	array<double>^ inputs = ode->inputs;
	array<double>^ outputs= ode->outputs;
	int dimension = inputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = y[i];
	}

	ode->eFnc(t, inputs, outputs);

	for(int i=0;i<dimension;i++){
		dydt[i] = outputs[i];
	}

	return GSL_SUCCESS;
}

int __cdecl odeErrorFunctionFD(double t, const double y[], double * dfdy, double dydt[], void* params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	OrdinaryDifferentialEquations^ ode = (OrdinaryDifferentialEquations^)gch.Target;

	array<double>^ inputs = ode->inputs;
	array<double>^ outputs= ode->outputs;
	array<array<double>^>^ jacobian = ode->jacobian;
	int dimension = inputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = y[i];
	}

	Jacobian::Calculate(ode->eFnc, t, inputs, ode->jacobian, ode->dydt);

	int counter=0;
	for(int i=0;i<dimension;i++){
		dydt[i] = ode->dydt[i];
		for(int j=0;j<dimension;j++){
			dfdy[counter] = ode->jacobian[j][i];
			counter++;
		}
	}

	return GSL_SUCCESS;
}

}