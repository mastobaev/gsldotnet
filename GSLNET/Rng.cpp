/* Rng.cpp
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

#include "Rng.h"
#include <gsl/gsl_rng.h>

namespace GSLNET{

Rng::Rng(GeneratorType gType)
{
	switch(gType){
		case GeneratorType::CombinedMultipleRecursive:
			rnd = gsl_rng_alloc(gsl_rng_cmrg);
			break;
		case GeneratorType::MT19937:
			rnd = gsl_rng_alloc(gsl_rng_mt19937);
			break;
		case GeneratorType::MultipleRecursive:
			rnd = gsl_rng_alloc(gsl_rng_mrg);
			break;
		case GeneratorType::Ranlux1:
			rnd = gsl_rng_alloc(gsl_rng_ranlxd1);
			break;
		case GeneratorType::Ranlux2:
			rnd = gsl_rng_alloc(gsl_rng_ranlxd2);
			break;
		case GeneratorType::Ranlux389:
			rnd = gsl_rng_alloc(gsl_rng_ranlux389);
			break;
		case GeneratorType::Taus:
			rnd = gsl_rng_alloc(gsl_rng_taus);
			break;
		case GeneratorType::Taus2:
			rnd = gsl_rng_alloc(gsl_rng_taus2);
			break;
	}
}

Rng::Rng(GeneratorType gType, unsigned long s){
	Rng::Rng(gType);
	gsl_rng_set(rnd, s);
}

double Rng::Uniform(){
	return gsl_rng_uniform(rnd);	
}

}