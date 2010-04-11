/* RandomDistribution.cpp
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
#include "RandomDistribution.h"

#include <gsl/gsl_randist.h>

namespace GSLNET{

RandomDistribution::RandomDistribution(void) { }

double RandomDistribution::Gaussian(GaussianGeneratorType gType, double sigma, GSLNET::Rng ^random){
	switch(gType){
		case GaussianGeneratorType::BoxMuler:
			return gsl_ran_gaussian(random->rnd, sigma);
		case GaussianGeneratorType::Ratio:
			return gsl_ran_gaussian_ratio_method(random->rnd, sigma);
		case GaussianGeneratorType::Ziggurat:
			return gsl_ran_gaussian_ziggurat(random->rnd, sigma);
		default:
			return gsl_ran_gaussian(random->rnd, sigma);
	}
}

double RandomDistribution::GaussianPdf(double x, double sigma){
	return gsl_ran_gaussian_pdf(x, sigma);
}

}