using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using GSLNET;

namespace GSLNETTest
{
    static class LinearAlgebraTester
    {
        public static void TestLUDecomposition()
        {
            //-----------------------------
            //| 0.18 | 0.41 | 0.14 | 0.51 |
            //| 0.60 | 0.24 | 0.30 | 0.13 |
            //| 0.57 | 0.99 | 0.97 | 0.19 |
            //| 0.96 | 0.58 | 0.66 | 0.85 |
            //-----------------------------

            Matrix matrix = new Matrix(4, 4);
            matrix.SetValue(0, 0, 0.18);
            matrix.SetValue(0, 1, 0.60);
            matrix.SetValue(0, 2, 0.57);
            matrix.SetValue(0, 3, 0.96);
            matrix.SetValue(1, 0, 0.41);
            matrix.SetValue(1, 1, 0.24);
            matrix.SetValue(1, 2, 0.99);
            matrix.SetValue(1, 3, 0.58);
            matrix.SetValue(2, 0, 0.14);
            matrix.SetValue(2, 1, 0.30);
            matrix.SetValue(2, 2, 0.97);
            matrix.SetValue(2, 3, 0.66);
            matrix.SetValue(3, 0, 0.51);
            matrix.SetValue(3, 1, 0.13);
            matrix.SetValue(3, 2, 0.19);
            matrix.SetValue(3, 3, 0.85);
            Vector b = new Vector(4);
            b.SetValue(0, 1);
            b.SetValue(1, 2);
            b.SetValue(2, 3);
            b.SetValue(3, 4);
            Vector x = new Vector(4);

            //LU分解による解法
            int sig;
            Permutation perm = new Permutation(4);
            LinearAlgebra.LUDecomposition(ref matrix, ref perm, out sig);
            LinearAlgebra.LUSolve(matrix, perm, b, ref x);
            LinearAlgebra.LUSolve(matrix, perm, ref b);

            //QR分解による解法
            /*Vector tau = new Vector(4);
            LinearAlgebra.QRDecomposition(ref matrix, ref tau);
            LinearAlgebra.QRSolve(matrix, tau, b, ref x);*/

            Console.WriteLine(x.GetValue(0));
            Console.WriteLine(x.GetValue(1));
            Console.WriteLine(x.GetValue(2));
            Console.WriteLine(x.GetValue(3));
        }

        public static void TestInverse()
        {
            //----------------------
            //| 0.18 | 0.41 | 0.14 |
            //| 0.60 | 0.24 | 0.30 |
            //| 0.57 | 0.99 | 0.97 |
            //----------------------

            Matrix matrix = new Matrix(3, 3);
            Matrix matrix2 = new Matrix(4, 4);
            matrix.SetValue(0, 0, 0.18);
            matrix.SetValue(0, 1, 0.41);
            matrix.SetValue(0, 2, 0.14);
            matrix.SetValue(1, 0, 0.60);
            matrix.SetValue(1, 1, 0.24);
            matrix.SetValue(1, 2, 0.30);
            matrix.SetValue(2, 0, 0.57);
            matrix.SetValue(2, 1, 0.99);
            matrix.SetValue(2, 2, 0.97);
            double[,] test = matrix.ToArray();
            for (uint i = 0; i < matrix.Columns; i++)
            {
                for (uint j = 0; j < matrix.Rows; j++)
                {
                    matrix2.SetValue(i + 1, j + 1, matrix.GetValue(i, j));
                }
            }

            //LU分解による方法
            Matrix inv = new Matrix(3, 3);
            int sig;
            Permutation perm = new Permutation(3);
            perm.Initialize();
            LinearAlgebra.LUDecomposition(ref matrix, ref perm, out sig);
            LinearAlgebra.LUInvert(matrix, perm, ref inv);
            for (uint i = 0; i < inv.Columns; i++)
            {
                for (uint j = 0; j < inv.Rows; j++)
                {
                    Console.Write(inv.GetValue(i, j).ToString("F4").PadLeft(8) + " | ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            //部分行列のテスト
            perm.Initialize();
            Matrix inv2 = new Matrix(4, 4);
            MatrixView mView = new MatrixView(matrix2, 1, 1, 3, 3);
            MatrixView mViewINV = new MatrixView(inv2, 0, 1, 3, 3);
            LinearAlgebra.LUDecomposition(ref mView, ref perm, out sig);
            LinearAlgebra.LUInvert(mView, perm, ref mViewINV);
            for (uint i = 0; i < mViewINV.ColumnSize; i++)
            {
                for (uint j = 0; j < mViewINV.RowSize; j++)
                {
                    Console.Write(mViewINV.GetValue(i, j).ToString("F4").PadLeft(8) + " | ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            for (uint i = 0; i < inv2.Columns; i++)
            {
                for (uint j = 0; j < inv2.Rows; j++)
                {
                    Console.Write(inv2.GetValue(i, j).ToString("F4").PadLeft(8) + " | ");
                }
                Console.WriteLine();
            }

            Console.Read();
        }

    }
}
