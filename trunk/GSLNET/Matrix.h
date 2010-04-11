/* Matrix.h
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

#include <gsl/gsl_matrix.h>

namespace GSLNET{

public ref class Matrix
{

private:
	~Matrix();
	Matrix(gsl_matrix *mat);

internal:
	gsl_matrix * matrix;

public:
	///<summary>コンストラクタ</summary>
	///<param name="columnNumber">列数</param>
	///<param name="rowNumber">行数</param>
	Matrix(size_t columnNumber, size_t rowNumber);

	///<summary>列数を取得する</summary>
	property size_t Rows
	{
		size_t get() { return (*matrix).size2; }
		private:
			void set(size_t value){}
    }

	///<summary>行数を取得する</summary>
	property size_t Columns
	{
		size_t get() { return (*matrix).size1; }
		private:
			void set(size_t value){}
    }

	///<summary>行列成分を取得する</summary>
	///<param name="columnIndex">行番号</param>
	///<param name="rowIndex">列番号</param>
	///<returns>行列成分(rowIndex, columnIndex)の値</returns>
	double GetValue(size_t columnIndex, size_t rowIndex);

	///<summary>行列成分を設定する</summary>
	///<param name="columnIndex">行番号</param>
	///<param name="rowIndex">列番号</param>
	///<param name="value">行列成分(columnIndex, rowIndex)の値</param>
	void SetValue(size_t columnIndex, size_t rowIndex, double value);

	///<summary>行列成分に加算する</summary>
	///<param name="columnIndex">行番号</param>
	///<param name="rowIndex">列番号</param>
	///<param name="value">行列成分(columnIndex, rowIndex)に加算する値</param>
	void AddValue(size_t columnIndex, size_t rowIndex, double value);

	///<summary>行列成分から減算する</summary>
	///<param name="columnIndex">行番号</param>
	///<param name="rowIndex">列番号</param>
	///<param name="value">行列成分(columnIndex, rowIndex)から減算する値</param>
	void SubtractValue(size_t columnIndex, size_t rowIndex, double value);

	///<summary>すべての行列成分の値を初期化する</summary>
	///<param name="value">初期化する値</param>
	void InitializeValue(double value);

	///<summary>単位行列にする</summary>
	void MakeUnitMatrix();

	///<summary>配列に変換する</summary>
	///<returns>配列</returns>
	array<double, 2> ^ ToArray();

};

}