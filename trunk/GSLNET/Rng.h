/* Rng.h
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

#include <gsl/gsl_rng.h>

namespace GSLNET{

public ref class Rng
{

public:
	///<summary>乱数生成器の種類</summary>
	enum class GeneratorType {
		///<summary>メルセンヌ・ツイスター</summary>
		MT19937,
		///<summary>Luxury Random Numbers Level1</summary>
		Ranlux1,
		///<summary>Luxury Random Numbers Level2</summary>
		Ranlux2,
		///<summary>リュッシャ－の方法</summary>
		Ranlux389,
		///<summary>レキュエルの重再起結合乱数発生器</summary>
		CombinedMultipleRecursive,
		///<summary>レキュエルの重再起結合乱数発生器（五次）</summary>
		MultipleRecursive,
		///<summary>タウスワース型乱数発生器</summary>
		Taus,
		///<summary>タウスワース型乱数発生器2</summary>
		Taus2,		
	};

	///<summary>コンストラクタ</summary>
	///<param name="gType">乱数生成器の種類</param>
	Rng(GeneratorType gType);

	///<summary>コンストラクタ</summary>
	///<param name="gType">乱数生成器の種類</param>
	///<param name="s">乱数の種</param>
	Rng(GeneratorType gType, unsigned long int s);

	///<summary>0~1の範囲に一様に分布する乱数を作成する</summary>
	double Uniform();

internal:
	gsl_rng * rnd;

};

}