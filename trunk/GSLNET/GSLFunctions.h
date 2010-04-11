/* GSLFunctions.h
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

namespace GSLNET{

public ref class GSLFunctions
{
public:

	///<summary>入力ベクトルから出力ベクトルを計算する関数</summary>
	///<param name="inputs">入力ベクトル</param>
	///<param name="outputs">出力ベクトル</param>
	delegate GSLNET::ErrorNumber DArrayToDArray(array<double> ^ inputs, array<double> ^ %outputs);

	///<summary>時刻と入力ベクトルから出力ベクトルを計算する関数</summary>
	///<param name="t">時刻</param>
	///<param name="inputs">入力ベクトル</param>
	///<param name="outputs">出力ベクトル</param>
	delegate GSLNET::ErrorNumber TDArrayToDArray(double t, array<double> ^ inputs, array<double> ^ %outputs);

	///<summary>時刻と入力ベクトルを与える関数</summary>
	///<param name="t">時刻</param>
	///<param name="inputs">入力ベクトル</param>
	delegate void TDArray(double t, array<double> ^ inputs);

	///<summary>実数値入力から実数値出力を計算する関数</summary>
	///<param name="input">実数値入力</param>
	///<returns>実数値出力</returns>
	delegate double DToD(double input);

};

}