using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    static class RootTester
    {
        public static void Test() {

            GSLFunctions.DToD dtodFnc = delegate(double x)
            {
                Console.WriteLine(x);

                return x * x - 5;
            };

            Root root;
            double xValue;

            root = new Root(Root.SolverType.FalsePosition);
            root.ConvergenceType = Root.Convergence.Delta;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---");

            root.ConvergenceType = Root.Convergence.Interval;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---");

            root.ConvergenceType = Root.Convergence.Residual;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---***---");

            root = new Root(Root.SolverType.BrentDekker);
            root.ConvergenceType = Root.Convergence.Delta;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---");

            root.ConvergenceType = Root.Convergence.Interval;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---");

            root.ConvergenceType = Root.Convergence.Residual;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---***---");

            root = new Root(Root.SolverType.FalsePosition);
            root.ConvergenceType = Root.Convergence.Delta;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---");

            root.ConvergenceType = Root.Convergence.Interval;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);

            Console.WriteLine("---");

            root.ConvergenceType = Root.Convergence.Residual;
            root.Solve(dtodFnc, 0, 5, 100, out xValue);
        }
    }
}
