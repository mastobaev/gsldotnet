using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using GSLNET;

namespace GSLNETTest
{
    static class WaveletTester
    {

        public static void Test()
        {
            StreamReader sReader = new StreamReader("test.txt");
            List<double> dt = new List<double>();
            string buff;
            while ((buff = sReader.ReadLine()) != null)
            {
                if (dt.Count == 256) break;
                dt.Add(double.Parse(buff));
            }
            sReader.Close();

            double[] data = dt.ToArray();

            Wavelet wavelet = new Wavelet(Wavelet.WaveletType.Daubechies, 4);
            wavelet.Transform(ref data, Wavelet.WaveletDirection.Forward);
            uint[] ui = new uint[data.Length];
            double[] dbAbs = new double[data.Length];
            for (int i = 0; i < data.Length; i++) dbAbs[i] = Math.Abs(data[i]);
            Sort.SortDataIndex(dbAbs, ref ui);

            double[] dt1 = new double[data.Length];
            double[] dt2 = new double[data.Length];
            double[] dt3 = new double[data.Length];
            double[] dt4 = new double[data.Length];
            Array.Copy(data, dt1, data.Length - 1);
            Array.Copy(data, dt2, data.Length - 1);
            Array.Copy(data, dt3, data.Length - 1);
            Array.Copy(data, dt4, data.Length - 1);

            for (int i = 0; i < dt1.Length - 40; i++) dt1[ui[i]] = 0;
            for (int i = 0; i < dt2.Length - 80; i++) dt2[ui[i]] = 0;
            for (int i = 0; i < dt3.Length - 60; i++) dt3[ui[i]] = 0;
            for (int i = 0; i < dt4.Length - 40; i++) dt4[ui[i]] = 0;

            wavelet.Transform(ref data, Wavelet.WaveletDirection.Inverse);
            wavelet.Transform(ref dt1, Wavelet.WaveletDirection.Inverse);
            wavelet.Transform(ref dt2, Wavelet.WaveletDirection.Inverse);
            wavelet.Transform(ref dt3, Wavelet.WaveletDirection.Inverse);
            wavelet.Transform(ref dt4, Wavelet.WaveletDirection.Inverse);

            wavelet.Transform(ref data, Wavelet.WaveletDirection.Forward);
            StreamWriter sWriter = new StreamWriter("ttt.csv");
            for (int i = 0; i < data.Length; i++)
            {
                sWriter.WriteLine(data[i] + "," + dt1[i] + "," + dt2[i] + "," + dt3[i] + "," + dt4[i]);
            }
            sWriter.Close();

        }

    }
}
