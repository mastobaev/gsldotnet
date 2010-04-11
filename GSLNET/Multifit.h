/* Multifit.h
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
#include <gsl/gsl_multifit_nlin.h>
#include <gsl/gsl_vector.h>

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>非線形最小二乗法ソルバークラス</summary>
public ref class Multifit
{
private:
	~Multifit();
	gsl_multifit_fdfsolver *fSolver;

internal:
	array<double>^ inputs;
	array<double>^ outputs;
	array<array<double>^>^ jacobian;
	GSLFunctions::DArrayToDArray ^eFnc;
	gsl_vector *xVector;
	gsl_vector *gVector;

public:
	///<summary>非線形最小二乗法の種類</summary>
	enum class SolverType {
		///<summary>スケーリング付のLevenberg-Marquardt法</summary>
		LevenbergMarquardtWithScaling,
		///<summary>Levenberg-Marquardt法</summary>
		LevenbergMarquardt,
	};

	///<summary>コンストラクタ</summary>
	///<param name="sType">非線形最小二乗法の種類</param>
	///<param name="dataNumber">データ点数</param>
	///<param name="parameterNumber">パラメータ数</param>
	Multifit(SolverType sType, size_t dataNumber, size_t parameterNumber);

	///<summary>反復計算によってパラメータを最適化する</summary>
	///<param name="initialX">探索開始点</param>
	///<param name="epsabs">絶対誤差</param>
	///<param name="epsrel">相対誤差</param>
	///<param name="maxIteration">最大反復回数</param>
	///<param name="iterNum">反復回数</param>
	///<returns>エラーコード</returns>
	///<remarks>ステップ幅と探索点を、絶対誤差および相対誤差を使って比較し、収束を判定する</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, double epsrel, int maxIteration, [Out] int %iterNum);

	///<summary>反復計算によってパラメータを最適化する</summary>
	///<param name="initialX">探索開始点</param>
	///<param name="epsabs">絶対誤差</param>
	///<param name="maxIteration">最大反復回数</param>
	///<param name="iterNum">反復回数</param>
	///<returns>エラーコード</returns>
	///<remarks>ステップ幅と探索点を、絶対誤差および相対誤差を使って比較し、収束を判定する</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, int maxIteration, [Out] int %iterNum);

	///<summary>残差を取得する</summary>
	///<returns>残差</returns>
	double GetResidualError();
};

int __cdecl multifitErrorFunction (const gsl_vector * x, void *params, gsl_vector * f)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Multifit^ mFit = (Multifit^)gch.Target;

	array<double>^ inputs = mFit->inputs;
	array<double>^ outputs= mFit->outputs;
	int dimension = inputs->Length;
	int paramNumber = outputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = gsl_vector_get(x,i);
	}

	mFit->eFnc(inputs, outputs);

	for(int i=0;i<paramNumber;i++){
		gsl_vector_set(f, i, outputs[i]);
	}

	return GSL_SUCCESS;
}

int __cdecl multifitErrorFunctionFD (const gsl_vector * x, void *params, gsl_matrix * jac)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Multifit^ mFit = (Multifit^)gch.Target;

	array<double>^ inputs = mFit->inputs;
	array<double>^ outputs= mFit->outputs;
	int dimension = inputs->Length;
	
	for(int i=0;i<dimension;i++){
		inputs[i] = gsl_vector_get(x,i);
	}
	Jacobian::Calculate(mFit->eFnc, inputs, mFit->jacobian);

	int dataNumber = mFit->jacobian[0]->Length;
	for(int i=0;i<dataNumber;i++){
		for(int j=0;j<dimension;j++){
			gsl_matrix_set(jac, i, j, mFit->jacobian[j][i]);
		}
	}

	return GSL_SUCCESS;
}

int __cdecl multifitErrorFunctionFDF (const gsl_vector * x, void *params, gsl_vector * f, gsl_matrix * jac)
{
	multifitErrorFunction(x, params, f);
	multifitErrorFunctionFD(x, params, jac);
	return GSL_SUCCESS;
}


}