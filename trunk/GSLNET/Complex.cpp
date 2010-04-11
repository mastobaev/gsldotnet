
#include "Complex.h"
#include <stdlib.h>

namespace GSLNET{

Complex::Complex(void)
{
	cmplx = (gsl_complex *)malloc(sizeof(gsl_complex) );
	*cmplx = gsl_complex_rect(0, 0);
}

Complex::~Complex(){
	free(cmplx);
}

Complex ^ Complex::Rect(double x, double y)
{
	Complex ^ cmp = gcnew Complex();
	*cmp->cmplx = gsl_complex_rect(x, y);
	return cmp;
}

Complex ^ Complex::Polar(double r, double theta)
{
	Complex ^ cmp = gcnew Complex();
	*cmp->cmplx = gsl_complex_polar(r, theta);
	return cmp;
}

}