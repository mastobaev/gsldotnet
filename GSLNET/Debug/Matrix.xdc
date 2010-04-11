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
</members>
</doc>
