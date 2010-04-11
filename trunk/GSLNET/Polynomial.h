/* Polynomial.h
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

#include "Complex.h"
#include "ErrorNumber.h"
#include <gsl/gsl_poly.h>
using namespace System::Runtime::InteropServices;

namespace GSLNET{

public ref class Polynomial
{

private:
	gsl_poly_complex_workspace * ws;
	double * a, * z;

	///<summary>デコンストラクタ</summary>
	~Polynomial();

public:
	///<summary>コンストラクタ</summary>
	///<param name="order">多項式の次数</param>
	Polynomial(size_t order);

	///<summary>多項式の解を計算する</summary>
	///<param name="coef">実数係数配列</param>
	///<param name="roots">解の配列</param>
	///<returns>求根が成功したか否か</returns>
	ErrorNumber Solve(array<double> ^ coef, array<Complex ^> ^ %roots);

	///<summary>実数変数xの実数係数の多項式の値を計算する</summary>
	///<param name="coef">実数係数配列</param>
	///<param name="x">実数変数</param>
	///<returns>多項式の値</returns>
	static double Evaluate(array<double> ^ coef, double x);

	///<summary>複素変数zの実数係数の多項式の値を計算する</summary>
	///<param name="coef">実数係数配列</param>
	///<param name="z">複素変数</param>
	///<returns>多項式の値</returns>
	static Complex ^ Evaluate(array<double> ^ coef, Complex z);

	///<summary>複素変数zの複素数係数の多項式の値を計算する</summary>
	///<param name="coef">複素数係数配列</param>
	///<param name="z">複素変数</param>
	///<returns>多項式の値</returns>
	static Complex ^ Evaluate(array<Complex ^> ^ coef, Complex z);

};

}