/* Blas.h
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
#include <gsl/gsl_blas.h>
#include "Vector.h"
#include "Matrix.h"
#include "VectorView.h"
#include "MatrixView.h"

namespace GSLNET{

public ref class Blas
{
public:
	///<summary>転置の種類</summary>
	enum class TransposeType {
		///<summary>転置無し</summary>
		NoTranspose,
		///<summary>転置行列</summary>
		TransPose,
		///<summary>共役転置行列</summary>
		ConjugateTranspose,
	};

	///<summary>行列と行列の積と和を計算する（C = α op(A) op(B) + βC）</summary>
	///<param name="transA">行列Aの転置状態</param>
	///<param name="transB">行列Bの転置状態</param>
	///<param name="alpha">第一項の係数</param>
	///<param name="mA">行列A</param>
	///<param name="mB">行列B</param>
	///<param name="beta">第二項の係数</param>
	///<param name="mC">行列C（解が上書きされる）</param>
	static void DGemm(TransposeType transA, TransposeType transB, double alpha, const Matrix ^ mA, const Matrix ^ mB, double beta, Matrix ^ %mC);

	///<summary>行列と行列の積と和を計算する（C = α op(A) op(B) + βC）</summary>
	///<param name="transA">行列Aの転置状態</param>
	///<param name="transB">行列Bの転置状態</param>
	///<param name="alpha">第一項の係数</param>
	///<param name="mA">行列A</param>
	///<param name="mB">行列B</param>
	///<param name="beta">第二項の係数</param>
	///<param name="mC">行列C（解が上書きされる）</param>
	static void DGemm(TransposeType transA, TransposeType transB, double alpha, MatrixView ^ mA, MatrixView ^ mB, double beta, MatrixView ^ %mC);

	///<summary>行列とベクトルの積と和を計算する（y = α op(A) x + βy）</summary>
	///<param name="transA">行列Aの転置状態</param>
	///<param name="alpha">第一項の係数</param>
	///<param name="mA">行列A</param>
	///<param name="vX">ベクトルX</param>
	///<param name="beta">第二項の係数</param>
	///<param name="vY">ベクトルY（解が上書きされる）</param>
	static void DGemv(TransposeType transA, double alpha, const Matrix ^ mA, const Vector ^ vX, double beta, Vector ^ %vY);

	///<summary>行列とベクトルの積と和を計算する（y = α op(A) x + βy）</summary>
	///<param name="transA">行列Aの転置状態</param>
	///<param name="alpha">第一項の係数</param>
	///<param name="mA">行列A</param>
	///<param name="vX">ベクトルX</param>
	///<param name="beta">第二項の係数</param>
	///<param name="vY">ベクトルY（解が上書きされる）</param>
	static void DGemv(TransposeType transA, double alpha, MatrixView ^ mA, VectorView ^ vX, double beta, VectorView ^ %vY);

private:
	Blas(void);
	static CBLAS_TRANSPOSE_t getTrns(TransposeType tType);
};

}