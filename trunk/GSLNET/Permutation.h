/* Permutation.h
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

#include <gsl/gsl_permutation.h>

namespace GSLNET{

///<summary>置換ベクトルクラス</summary>
public ref class Permutation
{
public:
	///<summary>コンストラクタ</summary>
	///<param name="n">置換ベクトルの次元</param>
	Permutation(size_t n);

	///<summary>コンストラクタ</summary>
	///<param name="n">置換ベクトルの次元</param>
	///<param name="initVector">恒等置換となるように初期化するか</param>
	Permutation(size_t n, bool initVector);

	///<summary>置換ベクトルのサイズを取得する</summary>
	property size_t Size
	{
        size_t get() { return gsl_permutation_size(permutation); }
		private:
			void set(size_t value){}
    }

	///<summary>恒等置換となるように初期化する</summary>
	void Initialize();

	///<summary>置換ベクトルをコピーする</summary>
	///<param name="target">コピー先の置換ベクトル（初期化されている必要がある）</param>
	void Copy(Permutation %target);

	///<summary>要素を取得する</summary>
	///<param name="index">要素番号</param>
	///<returns>要素の値</returns>
	size_t GetValue(size_t index);

	///<summary>要素を入れ替える</summary>
	///<param name="i">要素1</param>
	///<param name="j">要素2</param>
	void Swap(size_t i, size_t j);

	///<summary>要素を逆にする</summary>
	void Reverse();

	///<summary>逆置換を計算してinvに設定する</summary>
	///<param name="inv">逆置換</param>
	void Inverse(Permutation inv);

	///<summary>辞書順で次の置換に進む</summary>
	///<returns>次の置換がある場合は真</returns>
	bool Next();

	///<summary>辞書順で前の置換に戻る</summary>
	///<returns>前の置換がある場合は真</returns>
	bool Prev();

private:
	~Permutation();

internal:
	gsl_permutation *permutation;

};

}