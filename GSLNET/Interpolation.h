/* Interpolation.h
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

#pragma once

#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>

namespace GSLNET{

public ref class Interpolation
{
private:
	size_t number;
	gsl_spline * spline;
	gsl_interp_accel * acc;
	double *x, *y;
	~Interpolation();

public:
	///<summary>保管法の種類</summary>
	enum class Method {
		///<summary>線形補間</summary>
		Linear,
		///<summary>多項式補間</summary>
		Polynomial,
		///<summary>自然境界での三次スプライン</summary>
		CSpline,
		///<summary>周期的境界の三次スプライン</summary>
		CSpline_Periodic,
		///<summary>自然境界での秋間スプライン</summary>
		Akima,
		///<summary>周期的境界条件での秋間スプライン</summary>
		Akima_Periodic
	};

	///<summary>データ数を設定・取得する</summary>
	property size_t DataNumber
	{
		size_t get() { return number; }
    }

	///<summary>コンストラクタ</summary>
	///<param name="size">データ数</param>
	///<param name="method">補間手法</param>
	Interpolation(size_t size, Method method);

	///<summary>初期化する</summary>
	///<param name="x">Xの値配列</param>
	///<param name="y">Yの値配列</param>
	void Initialize(array<double> ^ x, array<double> ^ y);

	///<summary>補間関数値を計算する</summary>
	///<param name="x">補間位置</param>
	double Evaluate(double x);

	///<summary>補間関数の微分値を計算する</summary>
	///<param name="x">補間位置</param>
	double EvaluateDerivative(double x);

	///<summary>補間関数の二階微分値を計算する</summary>
	///<param name="x">補間位置</param>
	double EvaluateDerivative2(double x);

	///<summary>補間関数の積分値を計算する</summary>
	///<param name="x1">積分区間開始位置</param>
	///<param name="x2">積分区間終了位置</param>
	double EvaluateIntegral(double x1, double x2);

};

}