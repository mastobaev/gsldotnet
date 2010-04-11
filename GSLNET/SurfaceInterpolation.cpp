/* SurfaceInterpolation.cpp
 * 
 * Copyright (C) 2009 E.Togashi
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

#include "SurfaceInterpolation.h"

namespace GSLNET{

SurfaceInterpolation::SurfaceInterpolation(size_t sizeX, size_t sizeY, Interpolation::Method method)
{
	xNumber = sizeX;
	yNumber = sizeY;

	//Y方向の補間オブジェクト
	ipY = gcnew Interpolation(sizeY, method);
	yy = gcnew array<double>(sizeY);
	zy = gcnew array<double>(sizeY);

	//X方向の補間オブジェクト
	ips = gcnew array<Interpolation^>(sizeY);
	for(size_t i=0;i<sizeY;i++) ips[i] = gcnew Interpolation(sizeX, method);
}

void SurfaceInterpolation::Initialize(array<double> ^ x, array<double> ^ y, array<double, 2> ^ z){
	array<double> ^ zz = gcnew array<double>(x->Length);
	y->CopyTo(yy,0);

	for(int i=0;i<y->Length;i++){
		for(int j=0;j<x->Length;j++) zz[j] = z[j,i];
		ips[i]->Initialize(x, zz);
	}
}

double SurfaceInterpolation::Evaluate(double x, double y){
	for(size_t i=0;i<DataNumberY;i++){
		zy[i] = ips[i]->Evaluate(x);
	}
	ipY->Initialize(yy, zy);
	return ipY->Evaluate(y);
}

}