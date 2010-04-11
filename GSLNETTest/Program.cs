using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GSLNETTest
{
    class Program
    {
        static void Main(string[] args)
        {
            //BlasTester.Test();
            //BlasTester.Test2();
            //LinearAlgebraTester.TestLUDecomposition();
            //LinearAlgebraTester.TestInverse();
            //RootWithDerivativeTester.Test();
            //RootTester.Test();
            //MinimizationTester.Test();
            //MultiRootTester.Test();
            //WaveletTester.Test();
            MultiFitTester mt = new MultiFitTester(); mt.Test();
            //ODETester.Test();
            //ComplexTester.Test();
            //PolynomialTester.Test();
            //InterpolationTester.Test();
        }


    }
}
