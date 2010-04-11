using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    static class ComplexTester
    {
        public static void Test()
        {
            Complex cmplx = new Complex();
            cmplx = Complex.Rect(3, 5);
            Console.WriteLine(cmplx.RealPart + ", " + cmplx.ImaginaryPart);

            Console.Read();
        }
    }
}
