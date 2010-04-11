using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    static class ODETester
    {

        /// <summary>常微分方程式テスト</summary>
        public static void Test()
        {
            OrdinaryDifferentialEquations ode = new OrdinaryDifferentialEquations(OrdinaryDifferentialEquations.SolverType.BulirschStoer, 2);
            ode.SetYControl(1e-6, 0);
            double initialT = 0;
            double t1 = 100;
            double timeStep = 100;
            double[] y = new double[] { 1, 0 };

            //出力式
            GSLFunctions.TDArrayToDArray fnc = delegate(double t, double[] inputs, ref double[] outputs)
            {
                outputs[0] = inputs[1];
                outputs[1] = -inputs[0] - 10d * inputs[1] * (inputs[0] * inputs[0] - 1d);
                return GSLNET.ErrorNumber.GSL_SUCCESS;
            };

            System.IO.StreamWriter sWriter = new System.IO.StreamWriter("odeOut.csv");
            GSLFunctions.TDArray fncOut = delegate(double t, double[] inputs)
            {
                Console.WriteLine(t + " , " + inputs[0] + " , " + inputs[1]);
                sWriter.WriteLine(t + " , " + inputs[0] + " , " + inputs[1]);
            };            

            ode.IntermediateOutput = fncOut;
            int iterNum;
            ode.Solve(fnc, ref initialT, t1, ref timeStep, ref y, out iterNum);

            sWriter.Close();
        }

    }
}
