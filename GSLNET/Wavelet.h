/* Wavelet.h
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

using namespace System::Runtime::InteropServices;

#include <gsl/gsl_wavelet.h>

namespace GSLNET{

public ref class Wavelet
{
public:
	///<summary>ウェーブレットの種類</summary>
	enum class WaveletType {
		///<summary>ドブシ・ウェーブレット</summary>
		Daubechies,
		///<summary>ハール・ウェーブレット</summary>
		Haar,
		///<summary>ベータスプライン・ウェーブレット</summary>
		BSpline,
	};

	///<summary>方向</summary>
	enum class WaveletDirection {
		///<summary>順</summary>
		Forward,
		///<summary>逆</summary>
		Inverse,
	};

	///<summary>コンストラクタ</summary>
	///<param name="wType">ウェーブレットの種類</param>
	///<param name="k">ウェーブレット・ファミリーのメンバー</param>
	Wavelet(WaveletType wType, size_t k);

	///<summary>変換処理を行う</summary>
	///<param name="data">変換するデータ</param>
	///<param name="dir">通常の変換か逆変換か</param>
	int Transform(array<double> ^ %data, WaveletDirection dir);

private:
	~Wavelet();
	gsl_wavelet *wavelet;
	gsl_wavelet_workspace *wSpace;
};

}
