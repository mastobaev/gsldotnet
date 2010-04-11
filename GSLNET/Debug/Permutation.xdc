<?xml version="1.0"?>
<doc>
<members>
<member name="T:GSLNET.Permutation" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="26">
<summary>置換ベクトルクラス</summary>
</member>
<member name="M:GSLNET.Permutation.#ctor(System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="30">
<summary>コンストラクタ</summary>
<param name="n">置換ベクトルの次元</param>
</member>
<member name="M:GSLNET.Permutation.#ctor(System.UInt32,System.Boolean)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="34">
<summary>コンストラクタ</summary>
<param name="n">置換ベクトルの次元</param>
<param name="initVector">恒等置換となるように初期化するか</param>
</member>
<member name="P:GSLNET.Permutation.Size" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="39">
<summary>置換ベクトルのサイズを取得する</summary>
</member>
<member name="M:GSLNET.Permutation.Initialize" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="47">
<summary>恒等置換となるように初期化する</summary>
</member>
<member name="M:GSLNET.Permutation.Copy(GSLNET.Permutation!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="50">
<summary>置換ベクトルをコピーする</summary>
<param name="target">コピー先の置換ベクトル（初期化されている必要がある）</param>
</member>
<member name="M:GSLNET.Permutation.GetValue(System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="54">
<summary>要素を取得する</summary>
<param name="index">要素番号</param>
<returns>要素の値</returns>
</member>
<member name="M:GSLNET.Permutation.Swap(System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="59">
<summary>要素を入れ替える</summary>
<param name="i">要素1</param>
<param name="j">要素2</param>
</member>
<member name="M:GSLNET.Permutation.Reverse" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="64">
<summary>要素を逆にする</summary>
</member>
<member name="M:GSLNET.Permutation.Inverse(GSLNET.Permutation!System.Runtime.CompilerServices.IsByValue)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="67">
<summary>逆置換を計算してinvに設定する</summary>
<param name="inv">逆置換</param>
</member>
<member name="M:GSLNET.Permutation.Next" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="71">
<summary>辞書順で次の置換に進む</summary>
<returns>次の置換がある場合は真</returns>
</member>
<member name="M:GSLNET.Permutation.Prev" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\permutation.h" line="75">
<summary>辞書順で前の置換に戻る</summary>
<returns>前の置換がある場合は真</returns>
</member>
</members>
</doc>
