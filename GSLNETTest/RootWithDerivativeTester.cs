using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    static class RootWithDerivativeTester
    {
        public static void Test() {

            GSLFunctions.DToD dtodFnc = delegate(double x)
            {
                return x * x - 5;
            };

            GSLFunctions.DToD dtodFncDF = delegate(double x)
            {
                return 2 * x;
            };

            RootWithDerivative root;
            double xValue;

            xValue = 2;
            root = new RootWithDerivative(RootWithDerivative.SolverType.Newton);
            root.ConvergenceType = RootWithDerivative.Convergence.Delta;
            root.Solve(dtodFnc, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---");

            xValue = 2;
            root.ConvergenceType = RootWithDerivative.Convergence.Residual;
            root.Solve(dtodFnc, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---***---");

            xValue = 2;
            root = new RootWithDerivative(RootWithDerivative.SolverType.Secant);
            root.ConvergenceType = RootWithDerivative.Convergence.Delta;
            root.Solve(dtodFnc, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---");

            xValue = 2;
            root.ConvergenceType = RootWithDerivative.Convergence.Residual;
            root.Solve(dtodFnc, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---***---");

            xValue = 2;
            root = new RootWithDerivative(RootWithDerivative.SolverType.Steffenson);
            root.ConvergenceType = RootWithDerivative.Convergence.Delta;
            root.Solve(dtodFnc, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---");

            xValue = 2;
            root.ConvergenceType = RootWithDerivative.Convergence.Residual;
            root.Solve(dtodFnc, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---***---***---");

            xValue = 2;
            root = new RootWithDerivative(RootWithDerivative.SolverType.Newton);
            root.ConvergenceType = RootWithDerivative.Convergence.Delta;
            root.Solve(dtodFnc, dtodFncDF, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---");

            xValue = 2;
            root.ConvergenceType = RootWithDerivative.Convergence.Residual;
            root.Solve(dtodFnc, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---***---");

            xValue = 2;
            root = new RootWithDerivative(RootWithDerivative.SolverType.Secant);
            root.ConvergenceType = RootWithDerivative.Convergence.Delta;
            root.Solve(dtodFnc, dtodFncDF, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---");

            xValue = 2;
            root.ConvergenceType = RootWithDerivative.Convergence.Residual;
            root.Solve(dtodFnc, dtodFncDF, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---***---");

            xValue = 2;
            root = new RootWithDerivative(RootWithDerivative.SolverType.Steffenson);
            root.ConvergenceType = RootWithDerivative.Convergence.Delta;
            root.Solve(dtodFnc, dtodFncDF, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);

            Console.WriteLine("---");

            xValue = 2;
            root.ConvergenceType = RootWithDerivative.Convergence.Residual;
            root.Solve(dtodFnc, dtodFncDF, 100, ref xValue);
            Console.WriteLine(root.Iteration() + " : " + xValue);
        }
    }
}
