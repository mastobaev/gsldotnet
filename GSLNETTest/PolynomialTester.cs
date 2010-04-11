using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    class PolynomialTester
    {
        public static void Test()
        {
            double[] coef = new double[] { 1, 2, 5, 4 };
            Console.WriteLine(Polynomial.Evaluate(coef, 5));

            Polynomial pol = new Polynomial(5);
            Complex[] cmps = new Complex[5];
            for (int i = 0; i < cmps.Length; i++) cmps[i] = new Complex();
            coef = new double[] { -1, 0, 0, 0, 0, 1 };
            pol.Solve(coef, ref cmps);
            for (int i = 0; i < cmps.Length; i++)
            {
                Console.WriteLine(cmps[i].RealPart + ", " + cmps[i].ImaginaryPart);
            }

            Console.Read();
        }
    }
}
