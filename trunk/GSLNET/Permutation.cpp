/* Permutation.cpp
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

#include "Permutation.h"

namespace GSLNET{

Permutation::Permutation(size_t n)
{
	permutation = gsl_permutation_calloc(n);
}

Permutation::Permutation(size_t n, bool initVector)
{
	if(initVector) permutation = gsl_permutation_calloc(n);
	else permutation = gsl_permutation_alloc(n);
}

void Permutation::Initialize(){
	gsl_permutation_init(permutation);
}

Permutation::~Permutation(){
	gsl_permutation_free(permutation);
}

void Permutation::Copy(Permutation %target){
	gsl_permutation_memcpy(target.permutation, permutation);
}

size_t Permutation::GetValue(size_t index){
	return gsl_permutation_get(permutation, index);
}

void Permutation::Swap(size_t i, size_t j){
	gsl_permutation_swap(permutation, i, j);
}

void Permutation::Reverse(){
	gsl_permutation_reverse(permutation);
}

void Permutation::Inverse(GSLNET::Permutation inv){
	gsl_permutation_inverse(inv.permutation, permutation);
}

bool Permutation::Next(){
	return (gsl_permutation_next(permutation) == GSL_SUCCESS);
}

bool Permutation::Prev(){
	return (gsl_permutation_prev(permutation) == GSL_SUCCESS);
}

}