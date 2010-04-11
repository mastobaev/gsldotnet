/* MultiRoot.h
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
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_vector.h>

using namespace System::Runtime::InteropServices;

namespace GSLNET {

///<summary>多次元関数求根クラス（微分値は有限差分近似する）</summary>
public ref class MultiRoot
{

public:
	///<summary>多次元関数求根法の種類</summary>
	enum class SolverType {
		///<summary>スケーリング付のパウエルの修正組み合わせ法</summary>
		ScalingHybrid,
		///<summary>パウエルの修正組み合わせ法</summary>
		Hybrid,
		///<summary>ニュートン・ラプソン法</summary>
		Newton,
		///<summary>ブロイデン法</summary>
		Broyden
	};

	///<summary>コンストラクタ</summary>
	///<param name="type">多次元関数求根法の種類</param>
	///<param name="n">次元数</param>
	MultiRoot(SolverType type, size_t n);

	///<summary>現時点の解を返す</summary>
	array<double>^ GetRoots();

	///<summary>現時点の関数値f(x)を返す</summary>
	array<double>^ GetOutputs();

	///<summary>直前に取ったステップ幅dXを返す</summary>
	array<double>^ GetDx();

	///<summary>反復計算によって根を求める</summary>
	///<param name="initialX">探索開始点</param>
	///<param name="epsabs">絶対誤差</param>
	///<param name="epsrel">相対誤差</param>
	///<param name="maxIteration">最大反復回数</param>
	///<param name="iterNum">反復回数</param>
	///<remarks>ステップ幅と探索点を、絶対誤差および相対誤差を使って比較し、収束を判定する</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, double epsrel, int maxIteration, [Out] int %iterNum);

	///<summary>反復計算によって根を求める</summary>
	///<param name="initialX">探索開始点</param>
	///<param name="epsabs">絶対誤差</param>
	///<param name="maxIteration">最大反復回数</param>
	///<param name="iterNum">反復回数</param>
	///<remarks>関数出力f(x)と絶対誤差によって収束を判定する</remarks>
	ErrorNumber Solve(GSLFunctions::DArrayToDArray ^eFnc, array<double>^ %initialX, double epsabs, int maxIteration, [Out] int %iterNum);

private:
	gsl_multiroot_fsolver *fSolver;
	array<double>^ dX;
	~MultiRoot();

internal:
	array<double>^ inputs;
	array<double>^ outputs;
	GSLFunctions::DArrayToDArray ^eFnc;

};

int __cdecl multiRootErrorFunction (const gsl_vector * x, void *params, gsl_vector * f)
{
	System::IntPtr ip = System::IntPtr(params);
	GCHandle gch = GCHandle::FromIntPtr(ip);
	MultiRoot^ mRoot = (MultiRoot^)gch.Target;

	array<double>^ inputs = mRoot->inputs;
	array<double>^ outputs= mRoot->outputs;
	int dimension = inputs->Length;
	for(int i=0;i<dimension;i++){
		inputs[i] = gsl_vector_get(x,i);
	}
	int eNum = (int)mRoot->eFnc(inputs, outputs);
	for(int i=0;i<dimension;i++){
		gsl_vector_set(f, i, outputs[i]);
	}
	return GSL_SUCCESS;
}

}