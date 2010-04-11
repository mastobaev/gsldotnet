using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Threading;

using GSLNET;

namespace GSLNETTest
{
    static class MinimizationTester
    {

        public static void Test()
        {

            GSLFunctions.DToD dtodFnc = delegate(double x)
            {
                return Math.Cos(x) + 1.0d;
            };

            Minimization mini = new Minimization(Minimization.SolverType.Brent);
            double xValue = 2;
            mini.Solve(dtodFnc, 0, 6, 0.001, 0, 100, ref xValue);
            Console.WriteLine(xValue + " : " + mini.Iteration());

            mini = new Minimization(Minimization.SolverType.GoldenSection);
            xValue = 2;
            mini.Solve(dtodFnc, 0, 6, 0.001, 0, 100, ref xValue);
            Console.WriteLine(xValue + " : " + mini.Iteration());

        }

    }
}
