/* Jacobian.h
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

#include "GSLFunctions.h"
#include "ErrorNumber.h"

namespace GSLNET{

public ref class Jacobian
{

public:

	///<summary>ヤコビ行列を計算する</summary>
	///<param name="fnc">出力ベクトル（m次元）計算関数</param>
	///<param name="inputs">入力ベクトル（n次元）</param>
	///<param name="jacobian">ヤコビ行列（n×m次元）</param>
	static void Calculate(GSLFunctions::DArrayToDArray ^ fnc, array<double> ^ inputs, array<array<double>^>^ %jacobian);

	///<summary>ヤコビ行列を計算する</summary>
	///<param name="fnc">出力ベクトル（m次元）計算関数</param>
	///<param name="fnc">時刻</param>
	///<param name="inputs">入力ベクトル（n次元）</param>
	///<param name="jacobian">ヤコビ行列（n×m次元）</param>
	///<param name="dydt">時間に対する出力微分ベクトル</param>
	static void Calculate(GSLFunctions::TDArrayToDArray ^ fnc, double t, array<double> ^ inputs, array<array<double>^>^ %jacobian, array<double> ^ %dydt);

	///<summary>ヤコビ行列計算用有限差分値を設定・取得する</summary>
	static double Delta = 1e-7;

private:
	Jacobian(void);
};

}