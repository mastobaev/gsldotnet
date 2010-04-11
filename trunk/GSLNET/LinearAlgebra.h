/* LinearAlgebra.h
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
#include "MatrixView.h"
#include "Vector.h"
#include "Permutation.h"
#include "ErrorNumber.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

///<summary>線形代数計算クラス</summary>
public ref class LinearAlgebra
{

public:
	///<summary>LU分解を行う</summary>
	///<param name="matrix">行列</param>
	///<param name="permutation">置換ベクトル</param>
	///<param name="signum">置換の符号（(-1)^n）</param>
	///<returns>エラーコード</returns>
	static ErrorNumber LUDecomposition(Matrix ^ %matrix, Permutation ^ %permutation, [Out] int %signum);

	///<summary>LU分解を行う</summary>
	///<param name="matrixView">行列</param>
	///<param name="permutation">置換ベクトル</param>
	///<param name="signum">置換の符号（(-1)^n）</param>
	///<returns>エラーコード</returns>
	static ErrorNumber LUDecomposition(MatrixView ^ %matrixView, Permutation ^ %permutation, [Out] int %signum);

	///<summary>LU分解結果を利用してAx=bを解く</summary>
	///<param name="lu">LU分解行列</param>
	///<param name="permutation">置換ベクトル</param>
	///<param name="b">ベクトルb</param>
	///<param name="x">解</param>
	///<returns>エラーコード</returns>
	static ErrorNumber LUSolve(Matrix ^ lu, Permutation ^ permutation, Vector ^ b, Vector ^ %x);

	///<summary>LU分解結果を利用してAx=bを解く</summary>
	///<param name="lu">LU分解行列</param>
	///<param name="permutation">置換ベクトル</param>
	///<param name="x">ベクトルb（解で上書きされる）</param>
	///<returns>エラーコード</returns>
	static ErrorNumber LUSolve(Matrix ^ lu, Permutation ^ permutation, Vector ^ %x);

	///<summary>LU分解結果を利用して逆行列を求める</summary>
	///<param name="lu">LU分解行列</param>
	///<param name="permutation">置換ベクトル</param>
	///<param name="inverse">逆行列</param>
	///<returns>エラーコード</returns>
	static ErrorNumber LUInvert(Matrix ^ lu, Permutation ^ permutation, Matrix ^ %inverse);

	///<summary>LU分解結果を利用して逆行列を求める</summary>
	///<param name="lu">LU分解行列</param>
	///<param name="permutation">置換ベクトル</param>
	///<param name="inverse">逆行列</param>
	///<returns>エラーコード</returns>
	static ErrorNumber LUInvert(MatrixView ^ lu, Permutation ^ permutation, MatrixView ^ %inverse);

	///<summary>QR分解を行う</summary>
	///<param name="matrix">行列</param>
	///<param name="tau">ハウスホルダーベクトル</param>
	///<returns>エラーコード</returns>
	static ErrorNumber QRDecomposition(Matrix ^ %matrix, Vector ^ %tau);

	///<summary>QR分解結果を利用してAx=bを解く</summary>
	///<param name="qr">QR分解行列</param>
	///<param name="tau">ハウスホルダーベクトル</param>
	///<param name="b">ベクトルb</param>
	///<param name="x">解</param>
	///<returns>エラーコード</returns>
	static ErrorNumber QRSolve(Matrix ^ qr, Vector ^ tau, Vector ^ b, Vector ^ %x);

	///<summary>QR分解結果を利用してAx=bを解く</summary>
	///<param name="qr">QR分解行列</param>
	///<param name="tau">ハウスホルダーベクトル</param>
	///<param name="x">ベクトルb（解で上書きされる）</param>
	///<returns>エラーコード</returns>
	static ErrorNumber QRSolve(Matrix ^ qr, Vector ^ tau, Vector ^ %x);

private:
	LinearAlgebra(void);
};

}