<?xml version="1.0"?>
<doc>
<members>
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
<member name="P:GSLNET.VectorView.Index" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vectorview.h" line="38">
<summary>要素番号を取得する</summary>
</member>
<member name="P:GSLNET.VectorView.Size" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vectorview.h" line="44">
<summary>要素数を取得する</summary>
</member>
<member name="M:GSLNET.VectorView.#ctor(GSLNET.Vector,System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vectorview.h" line="50">
<summary>コンストラクタ</summary>
<param name="index">要素番号</param>
<param name="size">要素数</param>
</member>
<member name="M:GSLNET.VectorView.Initialize(GSLNET.Vector,System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vectorview.h" line="55">
<summary>初期化する</summary>
<param name="index">要素番号</param>
<param name="size">要素数</param>
</member>
<member name="M:GSLNET.VectorView.SetValue(System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vectorview.h" line="60">
<summary>要素に値を設定する</summary>
<param name="index">要素番号</param>
<param name="value">設定する実数値</param>
</member>
<member name="M:GSLNET.VectorView.GetValue(System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\vectorview.h" line="65">
<summary>要素の値を取得する</summary>
<param name="index">要素番号</param>
<returns>要素の値</returns>
</member>
<member name="P:GSLNET.MatrixView.ColumnIndex" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="40">
<summary>行番号を取得する</summary>
</member>
<member name="P:GSLNET.MatrixView.RowIndex" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="46">
<summary>列番号を取得する</summary>
</member>
<member name="P:GSLNET.MatrixView.ColumnSize" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="52">
<summary>行数を取得する</summary>
</member>
<member name="P:GSLNET.MatrixView.RowSize" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="58">
<summary>列数を取得する</summary>
</member>
<member name="M:GSLNET.MatrixView.#ctor(GSLNET.Matrix,System.UInt32,System.UInt32,System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="64">
<summary>コンストラクタ</summary>
<param name="columnIndex">行番号</param>
<param name="rowIndex">列番号</param>
<param name="columnSize">行数</param>
<param name="rowSize">列数</param>
</member>
<member name="M:GSLNET.MatrixView.Initialize(GSLNET.Matrix,System.UInt32,System.UInt32,System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="71">
<summary>初期化する</summary>
<param name="columnIndex">行番号</param>
<param name="rowIndex">列番号</param>
<param name="columnSize">行数</param>
<param name="rowSize">列数</param>
</member>
<member name="M:GSLNET.MatrixView.GetValue(System.UInt32,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="78">
<summary>行列成分を取得する</summary>
<param name="rowIndex">行番号</param>
<param name="columnIndex">列番号</param>
<returns>行列成分(rowIndex, columnIndex)の値</returns>
</member>
<member name="M:GSLNET.MatrixView.SetValue(System.UInt32,System.UInt32,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\matrixview.h" line="84">
<summary>行列成分を設定する</summary>
<param name="rowIndex">行番号</param>
<param name="columnIndex">列番号</param>
<param name="value">行列成分(rowIndex, columnIndex)の値</param>
</member>
<member name="T:GSLNET.Blas.TransposeType" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="32">
<summary>転置の種類</summary>
</member>
<member name="F:GSLNET.Blas.TransposeType.NoTranspose" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="34">
<summary>転置無し</summary>
</member>
<member name="F:GSLNET.Blas.TransposeType.TransPose" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="36">
<summary>転置行列</summary>
</member>
<member name="F:GSLNET.Blas.TransposeType.ConjugateTranspose" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="38">
<summary>共役転置行列</summary>
</member>
<member name="M:GSLNET.Blas.DGemm(GSLNET.Blas.TransposeType,GSLNET.Blas.TransposeType,System.Double,GSLNET.Matrix!System.Runtime.CompilerServices.IsConst,GSLNET.Matrix!System.Runtime.CompilerServices.IsConst,System.Double,GSLNET.Matrix@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="42">
<summary>行列と行列の積と和を計算する（C = α op(A) op(B) + βC）</summary>
<param name="transA">行列Aの転置状態</param>
<param name="transB">行列Bの転置状態</param>
<param name="alpha">第一項の係数</param>
<param name="mA">行列A</param>
<param name="mB">行列B</param>
<param name="beta">第二項の係数</param>
<param name="mC">行列C（解が上書きされる）</param>
</member>
<member name="M:GSLNET.Blas.DGemm(GSLNET.Blas.TransposeType,GSLNET.Blas.TransposeType,System.Double,GSLNET.MatrixView,GSLNET.MatrixView,System.Double,GSLNET.MatrixView@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="52">
<summary>行列と行列の積と和を計算する（C = α op(A) op(B) + βC）</summary>
<param name="transA">行列Aの転置状態</param>
<param name="transB">行列Bの転置状態</param>
<param name="alpha">第一項の係数</param>
<param name="mA">行列A</param>
<param name="mB">行列B</param>
<param name="beta">第二項の係数</param>
<param name="mC">行列C（解が上書きされる）</param>
</member>
<member name="M:GSLNET.Blas.DGemv(GSLNET.Blas.TransposeType,System.Double,GSLNET.Matrix!System.Runtime.CompilerServices.IsConst,GSLNET.Vector!System.Runtime.CompilerServices.IsConst,System.Double,GSLNET.Vector@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="62">
<summary>行列とベクトルの積と和を計算する（y = α op(A) x + βy）</summary>
<param name="transA">行列Aの転置状態</param>
<param name="alpha">第一項の係数</param>
<param name="mA">行列A</param>
<param name="vX">ベクトルX</param>
<param name="beta">第二項の係数</param>
<param name="vY">ベクトルY（解が上書きされる）</param>
</member>
<member name="M:GSLNET.Blas.DGemv(GSLNET.Blas.TransposeType,System.Double,GSLNET.MatrixView,GSLNET.VectorView,System.Double,GSLNET.VectorView@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\blas.h" line="71">
<summary>行列とベクトルの積と和を計算する（y = α op(A) x + βy）</summary>
<param name="transA">行列Aの転置状態</param>
<param name="alpha">第一項の係数</param>
<param name="mA">行列A</param>
<param name="vX">ベクトルX</param>
<param name="beta">第二項の係数</param>
<param name="vY">ベクトルY（解が上書きされる）</param>
</member>
</members>
</doc>
