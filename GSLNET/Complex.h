/* Complex.h
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
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

namespace GSLNET{

public ref class Complex
{
internal:
	gsl_complex * cmplx;

public:
	///<summary>コンストラクタ</summary>
	Complex(void);

	///<summary>デコンストラクタ</summary>
	~Complex();

	///<summary>実部を設定・取得する</summary>
	property double RealPart
	{
		double get() { return GSL_REAL(*cmplx); }
		void set(double value){ GSL_SET_REAL(cmplx, value);}
    }

	///<summary>虚部を設定・取得する</summary>
	property double ImaginaryPart
	{
		double get() { return GSL_IMAG(*cmplx); }
		void set(double value){ GSL_SET_IMAG(cmplx, value);}
    }

	///<summary>直交座標系での座標値を与えて複素数を作成する</summary>
	///<param name="x">直交座標系でのx</param>
	///<param name="y">直交座標系でのy</param>
	///<returns>複素数オブジェクト</returns>
	static Complex ^ Rect(double x, double y);

	///<summary>極座標系での座標値を与えて複素数を作成する</summary>
	///<param name="r">極座標系でのr</param>
	///<param name="theta">極座標系でのtheta</param>
	///<returns>複素数オブジェクト</returns>
	static Complex ^ Polar(double r, double theta);

};

}