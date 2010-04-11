/* Vector.h
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

#include "Vector.h"

namespace GSLNET{

Vector::Vector(size_t n)
{
	vector = gsl_vector_calloc(n);
}

void Vector::SetValue(size_t index, double value){
	gsl_vector_set(vector, index, value);
}

void Vector::SetValue(double value){
	gsl_vector_set_all(vector, value);
}

void Vector::AddValue(size_t index, double value){
	gsl_vector_set(vector, index, gsl_vector_get(vector, index) + value);
}

void Vector::SubtractValue(size_t index, double value){
	gsl_vector_set(vector, index, gsl_vector_get(vector, index) - value);
}

double Vector::GetValue(size_t index){
	return gsl_vector_get(vector, index);
}

void Vector::CopyTo(Vector ^ %dest){
	gsl_vector_memcpy(dest->vector, this->vector);
}

Vector::~Vector(){
	gsl_vector_free(vector);
}

array<double> ^ Vector::ToArray(){
	array<double> ^ arr = gcnew array<double>(this->Size);
	for(size_t i=0;i<this->Size;i++){
		arr[i] = this->GetValue(i);
	}
	return arr;
}

void Vector::FromArray(array<double> ^ arr){
	for(size_t i=0;i<this->Size;i++){
		this->SetValue(i, arr[i]);
	}
}

}