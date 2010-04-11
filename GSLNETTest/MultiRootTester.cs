using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    static class MultiRootTester
    {

        /// <summary>ローゼンブロックの方程式を解くテスト</summary>
        public static void Test()
        {
            MultiRoot mRoots = new MultiRoot(MultiRoot.SolverType.ScalingHybrid, 2);
            
            //ローゼンブロックの方程式
            double a = 1;
            double b = 10;
            GSLFunctions.DArrayToDArray eFnc = delegate(double[] inputs, ref double[] outputs)
            {
                outputs[0] = a * (1 - inputs[0]);
                outputs[1] = b * (inputs[1] - inputs[0] * inputs[0]);
                return GSLNET.ErrorNumber.GSL_SUCCESS;
            };

            //収束計算
            int iterNum;
            double[] initX = new double[] { -10, -5 };
            mRoots.Solve(eFnc, ref initX, 1.0e-7, 1.0e-7, 100, out iterNum);
            Console.WriteLine(initX[0] + " , " + initX[1]);

            mRoots.Solve(eFnc, ref initX, 1.0e-7, 100, out iterNum);
            Console.WriteLine(initX[0] + " , " + initX[1]);
        }

    }
}
