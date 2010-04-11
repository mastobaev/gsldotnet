/* MatrixView.cpp
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

#include "MatrixView.h"

namespace GSLNET{

MatrixView::MatrixView(Matrix ^ matrix, size_t columnIndex, size_t rowIndex, size_t columnSize, size_t rowSize)
{
	this->columnIndex = columnIndex;
	this->rowIndex = rowIndex;
	this->rowSize = rowSize;
	this->columnSize = columnSize;
	this->matrix = matrix;
}

void MatrixView::Initialize(Matrix ^ matrix, size_t columnIndex, size_t rowIndex, size_t columnSize, size_t rowSize){
	this->columnIndex = columnIndex;
	this->rowIndex = rowIndex;
	this->rowSize = rowSize;
	this->columnSize = columnSize;
	this->matrix = matrix;
}

double MatrixView::GetValue(size_t rowIndex, size_t columnIndex){
	gsl_matrix_view mView = gsl_matrix_submatrix(matrix->matrix, this->columnIndex, this->rowIndex, this->columnSize, this->rowSize);
	return gsl_matrix_get(&mView.matrix, rowIndex, columnIndex);
}

void MatrixView::SetValue(size_t rowIndex, size_t columnIndex, double value){
	gsl_matrix_view mView = gsl_matrix_submatrix(matrix->matrix, this->columnIndex, this->rowIndex, this->columnSize, this->rowSize);
	gsl_matrix_set(&mView.matrix, rowIndex, columnIndex, value);
}

}