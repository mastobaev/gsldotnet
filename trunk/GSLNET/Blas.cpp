/* Blas.cpp
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

#include "Blas.h"

namespace GSLNET{

Blas::Blas(void){}

void Blas::DGemm(TransposeType transA, TransposeType transB, double alpha, const Matrix ^ mA, const Matrix ^ mB, double beta, Matrix ^ %mC){
	gsl_blas_dgemm(getTrns(transA), getTrns(transB), alpha, mA->matrix,  mB->matrix, beta, mC->matrix);
}

void Blas::DGemm(TransposeType transA, TransposeType transB, double alpha, MatrixView ^ mA, MatrixView ^ mB, double beta, MatrixView ^ %mC){
	gsl_matrix_view mViewA = gsl_matrix_submatrix(mA->matrix->matrix, mA->ColumnIndex, mA->RowIndex, mA->ColumnSize, mA->RowSize);
	gsl_matrix_view mViewB = gsl_matrix_submatrix(mB->matrix->matrix, mB->ColumnIndex, mB->RowIndex, mB->ColumnSize, mB->RowSize);
	gsl_matrix_view mViewC = gsl_matrix_submatrix(mC->matrix->matrix, mC->ColumnIndex, mC->RowIndex, mC->ColumnSize, mC->RowSize);
	gsl_blas_dgemm(getTrns(transA), getTrns(transB), alpha, &mViewA.matrix,  &mViewB.matrix, beta, &mViewC.matrix);
}

void Blas::DGemv(TransposeType transA, double alpha, const Matrix ^ mA, const Vector ^ vX, double beta, Vector ^ %vY){
	gsl_blas_dgemv(getTrns(transA), alpha, mA->matrix, vX->vector, beta, vY->vector);
}

void Blas::DGemv(TransposeType transA, double alpha, MatrixView ^ mA, VectorView ^ vX, double beta, VectorView ^ %vY){
	gsl_matrix_view mView = gsl_matrix_submatrix(mA->matrix->matrix, mA->ColumnIndex, mA->RowIndex, mA->ColumnSize, mA->RowSize);
	gsl_vector_view vViewX = gsl_vector_subvector(vX->vector->vector, vX->Index, vX->Size);
	gsl_vector_view vViewY = gsl_vector_subvector(vY->vector->vector, vY->Index, vY->Size);
	gsl_blas_dgemv(getTrns(transA), alpha, &mView.matrix, &vViewX.vector, beta, &vViewY.vector);
}

CBLAS_TRANSPOSE_t Blas::getTrns(TransposeType tType){
	if(tType == TransposeType::NoTranspose) return CblasNoTrans;
	else if(tType == TransposeType::TransPose) return CblasTrans;
	else return CblasConjTrans;
}

}
