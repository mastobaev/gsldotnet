using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using GSLNET;

namespace GSLNETTest
{
    static class InterpolationTester
    {
        public static void Test()
        {
            Interpolation ip = new Interpolation(10, Interpolation.Method.CSpline);
            double[] x = new double[10];
            double[] y = new double[10];
            for (int i = 0; i < 10; i++)
            {
                x[i] = i + 0.5 * Math.Sin(i);
                y[i] = i + Math.Cos(i * i);
            }
            ip.Initialize(x, y);
            using (StreamWriter sWriter = new StreamWriter("out.csv"))
            {
                for (double xi = x[0]; xi <= x[9]; xi += 0.01)
                {
                    sWriter.WriteLine(xi + "," + ip.Evaluate(xi));
                }
            }

            using (StreamReader sReader = new StreamReader("interpolate.csv"))
            using (StreamWriter sWriter = new StreamWriter("interpolateResult.csv"))
            {
                string[] xs = sReader.ReadLine().Split(',');
                string[] ys = sReader.ReadLine().Split(',');
                x = new double[xs.Length];
                y = new double[ys.Length];
                for (int i = 0; i < xs.Length; i++) x[i] = double.Parse(xs[i]);
                for (int i = 0; i < ys.Length; i++) y[i] = double.Parse(ys[i]);
                double[,] z = new double[x.Length, y.Length];
                string[] zs;
                for (int i = 0; i < ys.Length; i++)
                {
                    zs = sReader.ReadLine().Split(',');
                    for (int j = 0; j < zs.Length; j++) z[j, i] = double.Parse(zs[j]);
                }
                SurfaceInterpolation ips = new SurfaceInterpolation((uint)x.Length, (uint)y.Length, Interpolation.Method.CSpline);
                ips.Initialize(x, y, z);

                double dx = (x[x.Length - 1] - x[0]) / 20d;
                double dy = (y[y.Length - 1] - y[0]) / 20d;
                for (int i = 0; i < 21; i++)
                {
                    for (int j = 0; j < 21; j++)
                    {
                        sWriter.Write(ips.Evaluate(x[0] + dx * j, y[0] + dy * i) + ",");
                    }
                    sWriter.WriteLine();
                }
            }
        }
    }
}
