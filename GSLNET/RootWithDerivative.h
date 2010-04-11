/* RootWithDerivative.h
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

#include <gsl/gsl_roots.h>
#include <gsl/gsl_deriv.h>
#include "GSLFunctions.h"
#include "ErrorNumber.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class RootWithDerivative
{
public:

	///<summary>解法の種類</summary>
	enum class SolverType {
		///<summary>ニュートン法</summary>
		Newton,
		///<summary>割線法</summary>
		Secant,
		///<summary>ステフェンソンの方法</summary>
		Steffenson,
	};

	///<summary>収束判定基準</summary>
	enum class Convergence {
		///<summary>残差の収束：|f| ＜ epsabs</summary>
		Residual,
		///<summary>変化量の収束：|x1-x0| ＜ epsabs + epsrel |x1|</summary>
		Delta,
	};

	///<summary>収束判定基準を設定・取得する</summary>
	Convergence ConvergenceType;

	///<summary>相対誤差を設定・取得する</summary>
	double RelativeError;

	///<summary>絶対誤差を設定・取得する</summary>
	double AbsoluteError;

	///<summary>微分値径算用差分を設定・取得する</summary>
	double DeltaH;

	///<summary>反復計算回数を取得する</summary>
	int Iteration(){
		return this->iteration;
	}

	///<summary>コンストラクタ</summary>
	///<param name="sType">解法の種類</param>
	RootWithDerivative(SolverType sType);

	///<summary>反復計算によってf(x)=0となるxを求める</summary>
	///<param name="eFnc">関数f(x)</param>
	///<param name="maxIteration">最大反復回数</param>
	///<param name="xValue">初期値</param>
	///<returns>エラーコード</returns>
	ErrorNumber Solve(GSLFunctions::DToD ^ eFnc, int maxIteration, double %xValue);

	///<summary>反復計算によってf(x)=0となるxを求める</summary>
	///<param name="eFnc">関数f(x)</param>
	///<param name="eFncDF">微分値計算関数df(x)</param>
	///<param name="maxIteration">最大反復回数</param>
	///<param name="xValue">初期値</param>
	///<returns>エラーコード</returns>
	ErrorNumber RootWithDerivative::Solve(GSLFunctions::DToD ^eFnc, GSLFunctions::DToD ^ eFncDF, int maxIteration, double %xValue);

private:
	ErrorNumber solve(int maxIteration, double %xValue);
	gsl_root_fdfsolver * solver;
	~RootWithDerivative();
	int iteration;

internal:
	bool hasFDFunction;
	GSLFunctions::DToD ^ eFnc;
	GSLFunctions::DToD ^ eFncDF;

};

double __cdecl rootWithDerivativeFunction (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	RootWithDerivative^ root = (RootWithDerivative^)gch.Target;
	return root->eFnc(x);
}

double __cdecl rootWithDerivativeFunctionDF (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	RootWithDerivative^ root = (RootWithDerivative^)gch.Target;

	if(root->hasFDFunction){
		return root->eFncDF(x);
	}
	else{
		return (root->eFnc(x + root->DeltaH) - root->eFnc(x)) / root->DeltaH;
	}
}

void __cdecl rootWithDerivativeFunctionFDF (double x, void * params, double *y, double *dy)
{
	*y = rootWithDerivativeFunction(x, params);
	*dy = rootWithDerivativeFunctionDF(x, params);
}

}