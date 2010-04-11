<?xml version="1.0"?>
<doc>
<members>
<member name="M:GSLNET.Matrix.#ctor(System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="37">
<summary>コンストラクタ</summary>
<param name="columnNumber">列数</param>
<param name="rowNumber">行数</param>
</member>
<member name="P:GSLNET.Matrix.Rows" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="42">
<summary>列数を取得する</summary>
</member>
<member name="P:GSLNET.Matrix.Columns" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="50">
<summary>行数を取得する</summary>
</member>
<member name="M:GSLNET.Matrix.GetValue(System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="58">
<summary>行列成分を取得する</summary>
<param name="columnIndex">行番号</param>
<param name="rowIndex">列番号</param>
<returns>行列成分(rowIndex, columnIndex)の値</returns>
</member>
<member name="M:GSLNET.Matrix.SetValue(System.UInt32,System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="64">
<summary>行列成分を設定する</summary>
<param name="columnIndex">行番号</param>
<param name="rowIndex">列番号</param>
<param name="value">行列成分(columnIndex, rowIndex)の値</param>
</member>
<member name="M:GSLNET.Matrix.AddValue(System.UInt32,System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="70">
<summary>行列成分に加算する</summary>
<param name="columnIndex">行番号</param>
<param name="rowIndex">列番号</param>
<param name="value">行列成分(columnIndex, rowIndex)に加算する値</param>
</member>
<member name="M:GSLNET.Matrix.SubtractValue(System.UInt32,System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="76">
<summary>行列成分から減算する</summary>
<param name="columnIndex">行番号</param>
<param name="rowIndex">列番号</param>
<param name="value">行列成分(columnIndex, rowIndex)から減算する値</param>
</member>
<member name="M:GSLNET.Matrix.InitializeValue(System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="82">
<summary>すべての行列成分の値を初期化する</summary>
<param name="value">初期化する値</param>
</member>
<member name="M:GSLNET.Matrix.MakeUnitMatrix" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="86">
<summary>単位行列にする</summary>
</member>
<member name="M:GSLNET.Matrix.ToArray" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrix.h" line="89">
<summary>配列に変換する</summary>
<returns>配列</returns>
</member>
<member name="M:GSLNET.Vector.#ctor(System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="35">
<summary>コンストラクタ</summary>
<param name="n">要素数</param>
</member>
<member name="P:GSLNET.Vector.Size" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="39">
<summary>ベクトルのサイズを取得する</summary>
</member>
<member name="M:GSLNET.Vector.SetValue(System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="47">
<summary>要素に値を設定する</summary>
<param name="index">要素番号</param>
<param name="value">設定する実数値</param>
</member>
<member name="M:GSLNET.Vector.SetValue(System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="52">
<summary>全要素に値を設定する</summary>
<param name="value">設定する実数値</param>
</member>
<member name="M:GSLNET.Vector.AddValue(System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="56">
<summary>要素に加算する</summary>
<param name="index">要素番号</param>
<param name="value">要素に加算する値</param>
</member>
<member name="M:GSLNET.Vector.SubtractValue(System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="61">
<summary>要素から減算する</summary>
<param name="index">要素番号</param>
<param name="value">要素から減算する値</param>
</member>
<member name="M:GSLNET.Vector.GetValue(System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="66">
<summary>要素の値を取得する</summary>
<param name="index">要素番号</param>
<returns>要素の値</returns>
</member>
<member name="M:GSLNET.Vector.CopyTo(GSLNET.Vector@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="71">
<summary>ベクトルをコピーする</summary>
<param name="dest">コピー先のベクトル</param>
</member>
<member name="M:GSLNET.Vector.ToArray" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="75">
<summary>配列に変換する</summary>
<returns>配列</returns>
</member>
<member name="M:GSLNET.Vector.FromArray(System.Double[])" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vector.h" line="79">
<summary>配列を読み込む</summary>
<param name="arr">配列</param>
</member>
<member name="T:GSLNET.LinearMultiFit" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearmultifit.h" line="30">
<summary>重回帰クラス</summary>
</member>
<member name="M:GSLNET.LinearMultiFit.#ctor(System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearmultifit.h" line="34">
<summary>コンストラクタ</summary>
<param name="dataNumber">データの数</param>
<param name="variableNumber">変数の数</param>
</member>
<member name="M:GSLNET.LinearMultiFit.GetParameters(GSLNET.Matrix,GSLNET.Vector,GSLNET.Matrix@,GSLNET.Vector@,System.Double@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearmultifit.h" line="39">
<summary>重回帰係数を求める</summary>
<param name="xMatrix">独立変数行列</param>
<param name="yVector">従属変数ベクトル</param>
<param name="cov">重回帰係数の共分散行列</param>
<param name="parameters">重回帰係数</param>
<param name="error">残差二乗和</param>
</member>
<member name="M:GSLNET.LinearMultiFit.GetParameters(GSLNET.Matrix,GSLNET.Vector,GSLNET.Matrix@,GSLNET.Vector,GSLNET.Vector@,System.Double@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearmultifit.h" line="47">
<summary>重回帰係数を求める（重み付き）</summary>
<param name="xMatrix">独立変数行列</param>
<param name="yVector">従属変数ベクトル</param>
<param name="cov">重回帰係数の共分散行列</param>
<param name="weight">重みベクトル</param>
<param name="parameters">重回帰係数</param>
<param name="error">残差二乗和</param>
</member>
</members>
</doc>
