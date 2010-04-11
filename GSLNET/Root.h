/* Root.h
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
#include "GSLFunctions.h"
#include "ErrorNumber.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class Root
{
public:

	///<summary>解法の種類</summary>
	enum class SolverType {
		///<summary>二分法</summary>
		Bisection,
		///<summary>失敗点法</summary>
		FalsePosition,
		///<summary>ブレント法</summary>
		BrentDekker,
	};

	///<summary>収束判定基準</summary>
	enum class Convergence {
		///<summary>残差の収束：|f| ＜ epsabs</summary>
		Residual,
		///<summary>区間の収束：|a-b| ＜ epsabs + epsrel min(|a|,|b|)</summary>
		Interval,
		///<summary>変化量の収束：|x1-x0| ＜ epsabs + epsrel |x1|</summary>
		Delta,
	};

	///<summary>収束判定基準を設定・取得する</summary>
	Convergence ConvergenceType;

	///<summary>相対誤差を設定・取得する</summary>
	double RelativeError;

	///<summary>絶対誤差を設定・取得する</summary>
	double AbsoluteError;

	///<summary>コンストラクタ</summary>
	///<param name="sType">解法の種類</param>
	Root(SolverType sType);

	///<summary>反復計算によってf(x)=0となるxを求める</summary>
	///<param name="eFnc">関数f(x)</param>
	///<param name="lowerX">探索範囲下限</param>
	///<param name="upperX">探索範囲上限</param>
	///<param name="maxIteration">最大反復回数</param>
	///<param name="xValue">解</param>
	///<returns>エラーコード</returns>
	ErrorNumber Solve(GSLFunctions::DToD ^ eFnc, double lowerX, double upperX, int maxIteration, [Out] double %xValue);

	///<summary>反復計算回数を取得する</summary>
	int Iteration(){
		return this->iteration;
	}

private:
	gsl_root_fsolver * solver;
	~Root();
	int iteration;

internal:
	GSLFunctions::DToD ^ eFnc;

};

double __cdecl rootsFunction (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Root^ root = (Root^)gch.Target;
	return root->eFnc(x);
}

}