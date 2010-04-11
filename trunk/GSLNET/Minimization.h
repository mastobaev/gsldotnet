/* Minimization.h
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
#include <gsl/gsl_min.h>

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>一次元関数最適化クラス</summary>
public ref class Minimization
{
public:
	///<summary>一次元関数最適化法の種類</summary>
	enum class SolverType {
		///<summary>黄金探索法</summary>
		GoldenSection,
		///<summary>Brent法</summary>
		Brent,
	};

	///<summary>コンストラクタ</summary>
	///<param name="sType">一次元関数最適化法の種類</param>
	Minimization(SolverType sType);

	///<summary>反復計算によってf(x)が最小化するxを求める</summary>
	///<param name="minimizeFunction">最小化する関数f(x)</param>
	///<param name="lowerX">x下限</param>
	///<param name="upperX">x上限</param>
	///<param name="epsAbs">絶対誤差</param>
	///<param name="epsRel">相対誤差</param>
	///<param name="maxIter">最大反復回数</param>
	///<param name="xValue">xの初期値</param>
	ErrorNumber Solve(GSLFunctions::DToD ^ minimizeFunction, double lowerX, double upperX, 
		double epsAbs, double epsRel, int maxIter, double %xValue);

	///<summary>反復計算回数を取得する</summary>
	int Iteration(){
		return this->iteration;
	}

private:
	~Minimization();
	gsl_min_fminimizer *minimizer;
	int iteration;

internal:
	GSLFunctions::DToD ^eFnc;

};

double __cdecl minimizationFunction (double x, void * params)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	Minimization^ min = (Minimization^)gch.Target;
	return min->eFnc(x);
}

}
