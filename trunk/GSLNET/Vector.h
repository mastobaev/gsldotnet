/* Vector.cpp
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
#include <gsl/gsl_vector.h>

namespace GSLNET{

public ref class Vector
{

private:
	~Vector();

internal:
	gsl_vector * vector;

public:
	///<summary>コンストラクタ</summary>
	///<param name="n">要素数</param>
	Vector(size_t n);

	///<summary>ベクトルのサイズを取得する</summary>
	property size_t Size
	{
		size_t get() { return vector->size; }
		private:
			void set(size_t value){}
    }

	///<summary>要素に値を設定する</summary>
	///<param name="index">要素番号</param>
	///<param name="value">設定する実数値</param>
	void SetValue(size_t index, double value);

	///<summary>全要素に値を設定する</summary>
	///<param name="value">設定する実数値</param>
	void SetValue(double value);

	///<summary>要素に加算する</summary>
	///<param name="index">要素番号</param>
	///<param name="value">要素に加算する値</param>
	void AddValue(size_t index, double value);

	///<summary>要素から減算する</summary>
	///<param name="index">要素番号</param>
	///<param name="value">要素から減算する値</param>
	void SubtractValue(size_t index, double value);

	///<summary>要素の値を取得する</summary>
	///<param name="index">要素番号</param>
	///<returns>要素の値</returns>
	double GetValue(size_t index);

	///<summary>ベクトルをコピーする</summary>
	///<param name="dest">コピー先のベクトル</param>
	void CopyTo(Vector ^ %dest);

	///<summary>配列に変換する</summary>
	///<returns>配列</returns>
	array<double> ^ ToArray();

	///<summary>配列を読み込む</summary>
	///<param name="arr">配列</param>
	void FromArray(array<double> ^ arr);

};

}