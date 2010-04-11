/* VectorView.cpp
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

#include "VectorView.h"

namespace GSLNET{

VectorView::VectorView(Vector ^ vector, size_t index, size_t size)
{
	this->index = index;
	this->size = size;
	this->vector = vector;
}

void VectorView::Initialize(Vector ^ vector, size_t index, size_t size)
{
	this->index = index;
	this->size = size;
	this->vector = vector;
}

void VectorView::SetValue(size_t index, double value)
{
	gsl_vector_view vv = gsl_vector_subvector(vector->vector, this->index, size);
	gsl_vector_set(&vv.vector, index, value);
}

double VectorView::GetValue(size_t index)
{
	gsl_vector_view vv = gsl_vector_subvector(vector->vector, this->index, size);
	return gsl_vector_get(&vv.vector, index);
}

}