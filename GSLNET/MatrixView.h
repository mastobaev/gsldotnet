/* MatrixView.h
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

#include "Matrix.h"
#include <gsl/gsl_matrix.h>

namespace GSLNET{

public ref class MatrixView
{
private:
	size_t columnIndex;
	size_t rowIndex;
	size_t rowSize;
	size_t columnSize;

internal:
	Matrix ^ matrix;

public:

	///<summary>行番号を取得する</summary>
	property size_t ColumnIndex
	{
		size_t get() { return columnIndex; }
    }

	///<summary>列番号を取得する</summary>
	property size_t RowIndex
	{
		size_t get() { return rowIndex; }
    }

	///<summary>行数を取得する</summary>
	property size_t ColumnSize
	{
		size_t get() { return columnSize; }
    }

	///<summary>列数を取得する</summary>
	property size_t RowSize
	{
		size_t get() { return rowSize; }
    }

	///<summary>コンストラクタ</summary>
	///<param name="columnIndex">行番号</param>
	///<param name="rowIndex">列番号</param>
	///<param name="columnSize">行数</param>
	///<param name="rowSize">列数</param>
	MatrixView(Matrix ^ matrix, size_t columnIndex, size_t rowIndex, size_t columnSize, size_t rowSize);

	///<summary>初期化する</summary>
	///<param name="columnIndex">行番号</param>
	///<param name="rowIndex">列番号</param>
	///<param name="columnSize">行数</param>
	///<param name="rowSize">列数</param>
	void Initialize(Matrix ^ matrix, size_t columnIndex, size_t rowIndex, size_t columnSize, size_t rowSize);

	///<summary>行列成分を取得する</summary>
	///<param name="rowIndex">行番号</param>
	///<param name="columnIndex">列番号</param>
	///<returns>行列成分(rowIndex, columnIndex)の値</returns>
	double GetValue(size_t rowIndex, size_t columnIndex);

	///<summary>行列成分を設定する</summary>
	///<param name="rowIndex">行番号</param>
	///<param name="columnIndex">列番号</param>
	///<param name="value">行列成分(rowIndex, columnIndex)の値</param>
	void SetValue(size_t rowIndex, size_t columnIndex, double value);
};

}
