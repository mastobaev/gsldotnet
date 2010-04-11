/* Jacobian.cpp
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

#include "Jacobian.h"

#include "math.h"

namespace GSLNET{

Jacobian::Jacobian(void){
}

void Jacobian::Calculate(GSLFunctions::DArrayToDArray ^fnc, array<double> ^ inputs, array<array<double>^>^ %jacobian){
	int iNum = inputs->Length;
	int oNum = jacobian[0]->Length;
	array<double> ^ iBuff = gcnew array<double>(iNum);
	array<double> ^ baseOut = gcnew array<double>(oNum);
	inputs->CopyTo(iBuff, 0);
	fnc(inputs, baseOut);
	for(int i=0;i<iNum;i++){
		if(i != 0) iBuff[i - 1] = inputs[i-1];
		iBuff[i] += Delta;

		fnc(iBuff, jacobian[i]);
		for(int j=0;j<oNum;j++) jacobian[i][j] = (jacobian[i][j] - baseOut[j]) / Delta;
	}
}

void Jacobian::Calculate(GSLFunctions::TDArrayToDArray ^fnc, double t, array<double> ^ inputs, array<array<double>^>^ %jacobian, array<double> ^ %dydt){
	int iNum = inputs->Length;
	int oNum = jacobian[0]->Length;
	array<double> ^ iBuff = gcnew array<double>(iNum);
	array<double> ^ baseOut = gcnew array<double>(oNum);
	inputs->CopyTo(iBuff, 0);
	fnc(t, inputs, baseOut);
	for(int i=0;i<iNum;i++){
		if(i != 0) iBuff[i - 1] = inputs[i-1];
		iBuff[i] += Delta;

		fnc(t, iBuff, jacobian[i]);
		for(int j=0;j<oNum;j++) jacobian[i][j] = (jacobian[i][j] - baseOut[j]) / Delta;
	}

	fnc(t + Delta, inputs, dydt);
	for(int i=0;i<iNum;i++) dydt[i] =  (dydt[i] - baseOut[i]) / Delta;
}

}