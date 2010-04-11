/* RandomDistribution.h
 * 
 * Copyright (C) 2008 E.Togashi
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#pragma once

#include "Rng.h"

namespace GSLNET{

public ref class RandomDistribution
{

public:
	///<summary>正規乱数生成法の種類</summary>
	enum class GaussianGeneratorType {
		///<summary>ボックス・ミューラー法</summary>
		BoxMuler,
		///<summary>マルサグリア-ツァンのジッグラト</summary>
		Ziggurat,
		///<summary>キンダーマン-モナハン-レバの比による方法</summary>
		Ratio,
	};

	///<summary>標準偏差σの正規乱数を返す</summary>
	///<param name="gType">正規乱数生成法の種類</param>
	///<param name="sigma">標準偏差</param>
	///<param name="random">乱数オブジェクト</param>
	static double Gaussian(GaussianGeneratorType gType, double sigma, Rng ^ random);

	///<summary>標準偏差σの正規分布の確率密度関数の値を返す</summary>
	///<param name="x">x</param>
	///<param name="sigma">標準偏差</param>
	static double GaussianPdf(double x, double sigma);

private:
	RandomDistribution();

};

}