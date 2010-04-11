using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    class MultiFitTester
    {

        /// <summary>非線形最小二乗法テスト</summary>
        public void Test()
        {
            Multifit mFit = new Multifit(Multifit.SolverType.LevenbergMarquardtWithScaling, 40, 3);

            //学習データ作成
            double[] ops = new double[40];
            Random rnd = new Random();

            //出力式
            GSLFunctions.DArrayToDArray fnc = delegate(double[] inputs, ref double[] outputs)
            {
                double a = inputs[0];
                double lambda = inputs[1];
                double b = inputs[2];
                for (int i = 0; i < outputs.Length; i++)
                {
                    double t = i;
                    double yi = a * Math.Exp(-lambda * t) + b;
                    outputs[i] = yi - (1.0 + 5 * Math.Exp(-0.1 * t));
                }
                return GSLNET.ErrorNumber.GSL_SUCCESS;

            };

            int iterNum;
            double[] param = new double[] { 1, 0, 0 };
            GSLNET.ErrorNumber eNum = mFit.Solve(fnc, ref param, 1e-5, 500, out iterNum);
            //メモリ解放
            mFit.Dispose();

            Console.WriteLine("終了");
            Console.Read();
        }

    }
}
