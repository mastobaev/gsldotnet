/* LinearMultiFit.h
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

#include <gsl/gsl_multifit.h>
#include "Matrix.h"
#include "Vector.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>重回帰クラス</summary>
public ref class LinearMultiFit
{
public:
	///<summary>コンストラクタ</summary>
	///<param name="dataNumber">データの数</param>
	///<param name="variableNumber">変数の数</param>
	LinearMultiFit(size_t dataNumber, size_t variableNumber);

	///<summary>重回帰係数を求める</summary>
	///<param name="xMatrix">独立変数行列</param>
	///<param name="yVector">従属変数ベクトル</param>
	///<param name="cov">重回帰係数の共分散行列</param>
	///<param name="parameters">重回帰係数</param>
	///<param name="error">残差二乗和</param>
	void GetParameters(Matrix ^ xMatrix, Vector ^ yVector, Matrix ^ %cov, Vector ^ %parameters, [Out] double %error);

	///<summary>重回帰係数を求める（重み付き）</summary>
	///<param name="xMatrix">独立変数行列</param>
	///<param name="yVector">従属変数ベクトル</param>
	///<param name="cov">重回帰係数の共分散行列</param>
	///<param name="weight">重みベクトル</param>
	///<param name="parameters">重回帰係数</param>
	///<param name="error">残差二乗和</param>
	void GetParameters(Matrix ^ xMatrix, Vector ^ yVector, Matrix ^ %cov, Vector ^ weight, Vector ^ %parameters, [Out] double %error);

private:
	~LinearMultiFit();
	gsl_multifit_linear_workspace * wSpace;
};

}