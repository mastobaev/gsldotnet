/* SurfaceInterpolation.h
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

#include "Interpolation.h"

namespace GSLNET{

public ref class SurfaceInterpolation
{

private:
	Interpolation ^ ipY;
	array<double> ^ yy, ^ zy;
	array<Interpolation^> ^ ips;
	size_t xNumber, yNumber;

public:
	///<summary>X方向のデータ数を設定・取得する</summary>
	property size_t DataNumberX
	{
		size_t get() { return xNumber; }
    }

	///<summary>Y方向のデータ数を設定・取得する</summary>
	property size_t DataNumberY
	{
		size_t get() { return yNumber; }
    }

	SurfaceInterpolation(size_t sizeX, size_t sizeY, Interpolation::Method method);

	///<summary>初期化する</summary>
	///<param name="x">Xの値配列</param>
	///<param name="y">Yの値配列</param>
	///<param name="z">Zの値配列</param>
	void Initialize(array<double> ^ x, array<double> ^ y, array<double, 2> ^ z);

	///<summary>補間関数値を計算する</summary>
	///<param name="x">Xの値</param>
	///<param name="y">Yの値</param>
	double Evaluate(double x, double y);
};

}