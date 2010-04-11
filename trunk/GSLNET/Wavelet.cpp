/* Wavelet.cpp
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

#include "Wavelet.h"

using namespace System::Runtime::InteropServices;

namespace GSLNET{

Wavelet::Wavelet(WaveletType wType, size_t k)
{
	//ウェーブレットに応じて初期化
	switch(wType){
		case Wavelet::WaveletType::Daubechies:
			wavelet = gsl_wavelet_alloc(gsl_wavelet_daubechies, k);
			break;
		case Wavelet::WaveletType::Haar:
			wavelet = gsl_wavelet_alloc(gsl_wavelet_haar, k);
			break;
		case Wavelet::WaveletType::BSpline:
			wavelet = gsl_wavelet_alloc(gsl_wavelet_bspline, k);
			break;
	}
}

int Wavelet::Transform(array<double> ^ %data, Wavelet::WaveletDirection dir){
	size_t n = data->Length;
	size_t stride = 1;
	//領域確保
	wSpace = gsl_wavelet_workspace_alloc(n);
	pin_ptr<double> nativeDouble = &data[0];
	if(dir == Wavelet::WaveletDirection::Forward){
		return gsl_wavelet_transform_forward(wavelet, nativeDouble, stride, n, wSpace);
	}else{
		return gsl_wavelet_transform_inverse(wavelet, nativeDouble, stride, n, wSpace);
	}
}

Wavelet::~Wavelet(){
	gsl_wavelet_free(wavelet);
	gsl_wavelet_workspace_free(wSpace);
}

}