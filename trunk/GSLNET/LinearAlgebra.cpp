/* LinearAlgebra.cpp
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

#include "LinearAlgebra.h"
#include <gsl/gsl_linalg.h>
using namespace System;

namespace GSLNET{

LinearAlgebra::LinearAlgebra(void){}

ErrorNumber LinearAlgebra::LUDecomposition(Matrix ^ %matrix, Permutation ^ %permutation, [Out] int %signum)
{
	int sig;
	int errNum = gsl_linalg_LU_decomp(matrix->matrix, permutation->permutation, &sig);
	signum = sig;
	return (ErrorNumber)errNum;
}

ErrorNumber LinearAlgebra::LUDecomposition(MatrixView ^ %matrix, Permutation ^ %permutation, [Out] int %signum)
{
	gsl_matrix_view mView = gsl_matrix_submatrix(matrix->matrix->matrix, matrix->ColumnIndex, matrix->RowIndex, matrix->ColumnSize, matrix->RowSize);
	int sig;
	int errNum = gsl_linalg_LU_decomp(&mView.matrix, permutation->permutation, &sig);
	signum = sig;
	return (ErrorNumber)errNum;
}

ErrorNumber LinearAlgebra::LUSolve(Matrix ^ lu, Permutation ^ permutation, Vector ^ b, Vector ^ %x)
{
	return (ErrorNumber) gsl_linalg_LU_solve(lu->matrix, permutation->permutation, b->vector, x->vector);
}

ErrorNumber LinearAlgebra::LUSolve(Matrix ^ lu, Permutation ^ permutation, Vector ^ %x)
{
	return (ErrorNumber) gsl_linalg_LU_svx(lu->matrix, permutation->permutation, x->vector);
}

ErrorNumber LinearAlgebra::LUInvert(Matrix ^ lu, Permutation ^ permutation, Matrix ^ %inverse)
{
	return (ErrorNumber) gsl_linalg_LU_invert(lu->matrix, permutation->permutation, inverse->matrix);
}

ErrorNumber LinearAlgebra::LUInvert(MatrixView ^ lu, Permutation ^ permutation, MatrixView ^ %inverse)
{
	gsl_matrix_view mViewLU = gsl_matrix_submatrix(lu->matrix->matrix, lu->ColumnIndex, lu->RowIndex, lu->ColumnSize, lu->RowSize);
	gsl_matrix_view mViewINV = gsl_matrix_submatrix(inverse->matrix->matrix, inverse->ColumnIndex, inverse->RowIndex, inverse->ColumnSize, inverse->RowSize);
	return (ErrorNumber) gsl_linalg_LU_invert(&mViewLU.matrix, permutation->permutation, &mViewINV.matrix);
}

ErrorNumber LinearAlgebra::QRDecomposition(Matrix ^ %matrix, Vector ^ %tau)
{
	return (ErrorNumber) gsl_linalg_QR_decomp(matrix->matrix, tau->vector);
}

ErrorNumber LinearAlgebra::QRSolve(Matrix ^ qr, Vector ^ tau, Vector ^ b, Vector ^ %x)
{
	return (ErrorNumber) gsl_linalg_QR_solve(qr->matrix, tau->vector, b->vector, x->vector);
}

ErrorNumber LinearAlgebra::QRSolve(Matrix ^ qr, Vector ^ tau, Vector ^ %x)
{
	return (ErrorNumber) gsl_linalg_QR_svx(qr->matrix, tau->vector, x->vector);
}

}