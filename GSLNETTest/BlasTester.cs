using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    static class BlasTester
    {
        public static void Test() {

            Matrix mA = new Matrix(2, 3);
            Matrix mB = new Matrix(3, 2);
            Matrix mC = new Matrix(2, 2);

            mA.SetValue(0, 0, 0.11);
            mA.SetValue(0, 1, 0.12);
            mA.SetValue(0, 2, 0.13);
            mA.SetValue(1, 0, 0.21);
            mA.SetValue(1, 1, 0.22);
            mA.SetValue(1, 2, 0.23);

            mB.SetValue(0, 0, 1011);
            mB.SetValue(0, 1, 1012);
            mB.SetValue(1, 0, 1021);
            mB.SetValue(1, 1, 1022);
            mB.SetValue(2, 0, 1031);
            mB.SetValue(2, 1, 1032);

            Blas.DGemm(Blas.TransposeType.NoTranspose, Blas.TransposeType.NoTranspose, 1.0, mA, mB, 0.0, ref mC);

            Console.WriteLine(mC.GetValue(0, 0) + " , " + mC.GetValue(0, 1));
            Console.WriteLine(mC.GetValue(1, 0) + " , " + mC.GetValue(1, 1));
        }

        public static void Test2()
        {
            const uint MARGIN = 1;

            Matrix mA = new Matrix(2 + MARGIN, 3 + MARGIN);
            Matrix mB = new Matrix(3, 2);
            Matrix mC = new Matrix(2, 2);

            mA.SetValue(0 + MARGIN, 0 + MARGIN, 0.11);
            mA.SetValue(0 + MARGIN, 1 + MARGIN, 0.12);
            mA.SetValue(0 + MARGIN, 2 + MARGIN, 0.13);
            mA.SetValue(1 + MARGIN, 0 + MARGIN, 0.21);
            mA.SetValue(1 + MARGIN, 1 + MARGIN, 0.22);
            mA.SetValue(1 + MARGIN, 2 + MARGIN, 0.23);

            mB.SetValue(0, 0, 1011);
            mB.SetValue(0, 1, 1012);
            mB.SetValue(1, 0, 1021);
            mB.SetValue(1, 1, 1022);
            mB.SetValue(2, 0, 1031);
            mB.SetValue(2, 1, 1032);

            MatrixView mViewA = new MatrixView(mA, MARGIN, MARGIN, mA.Columns - MARGIN, mA.Rows - MARGIN);
            MatrixView mViewB = new MatrixView(mB, 0, 0, mB.Columns, mB.Rows);
            MatrixView mViewC = new MatrixView(mC, 0, 0, mC.Columns, mC.Rows);
            Blas.DGemm(Blas.TransposeType.NoTranspose, Blas.TransposeType.NoTranspose, 1.0, mViewA, mViewB, 0.0, ref mViewC);

            Console.WriteLine(mC.GetValue(0, 0) + " , " + mC.GetValue(0, 1));
            Console.WriteLine(mC.GetValue(1, 0) + " , " + mC.GetValue(1, 1));
        }

    }
}
