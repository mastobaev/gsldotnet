/* Matrix.cpp
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

#include "Matrix.h"

namespace GSLNET{

Matrix::Matrix(gsl_matrix *mat){
	matrix = mat;
}

Matrix::Matrix(size_t columnNumber, size_t rowNumber)
{
	matrix = gsl_matrix_calloc(columnNumber, rowNumber);
}

double Matrix::GetValue(size_t columnIndex, size_t rowIndex){
	return gsl_matrix_get(matrix, columnIndex, rowIndex);
}

void Matrix::SetValue(size_t columnIndex, size_t rowIndex, double value){
	gsl_matrix_set(matrix, columnIndex, rowIndex, value);
}

void Matrix::AddValue(size_t columnIndex, size_t rowIndex, double value){
	gsl_matrix_set(matrix, columnIndex, rowIndex, gsl_matrix_get(matrix, columnIndex, rowIndex) + value);
}

void Matrix::SubtractValue(size_t columnIndex, size_t rowIndex, double value){
	gsl_matrix_set(matrix, columnIndex, rowIndex, gsl_matrix_get(matrix, columnIndex, rowIndex) - value);
}

void Matrix::InitializeValue(double value){
	gsl_matrix_set_all(matrix, value);
}

void Matrix::MakeUnitMatrix(){
	gsl_matrix_set_identity(matrix);
}

Matrix::~Matrix(){
	gsl_matrix_free(matrix);
}


array<double, 2> ^ Matrix::ToArray(){
	array<double, 2> ^ arr = gcnew array<double, 2>(this->Columns, this->Rows);
	for(size_t i=0;i<this->Columns;i++){
		for(size_t j=0;j<this->Rows;j++){
			arr[i,j] = this->GetValue(i,j);
		}
	}
	return arr;
}

}