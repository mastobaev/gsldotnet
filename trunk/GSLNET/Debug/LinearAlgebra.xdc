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
<member name="F:GSLNET.ErrorNumber.GSL_SUCCESS" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="26">
<summary>成功</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_FAILURE" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="28">
<summary>失敗</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_CONTINUE" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="30">
<summary>iteration has not converged</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EDOM" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="32">
<summary>input domain error, e.g sqrt(-1)</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ERANGE" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="34">
<summary>output range error, e.g. exp(1e100)</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EFAULT" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="36">
<summary>invalid pointer</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EINVAL" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="38">
<summary>invalid argument supplied by user</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EFAILED" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="40">
<summary>generic failure</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EFACTOR" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="42">
<summary>factorization failed</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ESANITY" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="44">
<summary>sanity check failed - shouldn't happen</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ENOMEM" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="46">
<summary>malloc failed</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EBADFUNC" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="48">
<summary>problem with user-supplied function</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ERUNAWAY" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="50">
<summary>iterative process is out of control</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EMAXITER" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="52">
<summary>exceeded max number of iterations</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EZERODIV" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="54">
<summary>tried to divide by zero</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EBADTOL" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="56">
<summary>user specified an invalid tolerance</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ETOL" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="58">
<summary>failed to reach the specified tolerance</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EUNDRFLW" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="60">
<summary>underflow</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EOVRFLW" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="62">
<summary>overflow</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ELOSS" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="64">
<summary>loss of accuracy</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EROUND" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="66">
<summary>failed because of roundoff error</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EBADLEN" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="68">
<summary>matrix, vector lengths are not conformant</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ENOTSQR" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="70">
<summary>matrix not square</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ESING" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="72">
<summary>apparent singularity detected</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EDIVERGE" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="74">
<summary>integral or series is divergent</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EUNSUP" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="76">
<summary>requested feature is not supported by the hardware</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EUNIMPL" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="78">
<summary>requested feature not (yet) implemented</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ECACHE" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="80">
<summary>cache limit exceeded</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ETABLE" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="82">
<summary>table limit exceeded</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ENOPROG" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="84">
<summary>iteration is not making progress towards solution</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ENOPROGJ" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="86">
<summary>jacobian evaluations are not improving the solution</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ETOLF" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="88">
<summary>cannot reach the specified tolerance in F</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ETOLX" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="90">
<summary>cannot reach the specified tolerance in X</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_ETOLG" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="92">
<summary>cannot reach the specified tolerance in gradient</summary>
</member>
<member name="F:GSLNET.ErrorNumber.GSL_EOF" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="94">
<summary>end of file</summary>
</member>
<member name="T:GSLNET.ErrorNumber" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\errornumber.h" line="24">
<summary>GSLNETエラーコード</summary>
</member>
<member name="T:GSLNET.LinearAlgebra" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="32">
<summary>線形代数計算クラス</summary>
</member>
<member name="M:GSLNET.LinearAlgebra.LUDecomposition(GSLNET.Matrix@,GSLNET.Permutation@,System.Int32@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="37">
<summary>LU分解を行う</summary>
<param name="matrix">行列</param>
<param name="permutation">置換ベクトル</param>
<param name="signum">置換の符号（(-1)^n）</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.LUDecomposition(GSLNET.MatrixView@,GSLNET.Permutation@,System.Int32@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="44">
<summary>LU分解を行う</summary>
<param name="matrixView">行列</param>
<param name="permutation">置換ベクトル</param>
<param name="signum">置換の符号（(-1)^n）</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.LUSolve(GSLNET.Matrix,GSLNET.Permutation,GSLNET.Vector,GSLNET.Vector@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="51">
<summary>LU分解結果を利用してAx=bを解く</summary>
<param name="lu">LU分解行列</param>
<param name="permutation">置換ベクトル</param>
<param name="b">ベクトルb</param>
<param name="x">解</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.LUSolve(GSLNET.Matrix,GSLNET.Permutation,GSLNET.Vector@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="59">
<summary>LU分解結果を利用してAx=bを解く</summary>
<param name="lu">LU分解行列</param>
<param name="permutation">置換ベクトル</param>
<param name="x">ベクトルb（解で上書きされる）</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.LUInvert(GSLNET.Matrix,GSLNET.Permutation,GSLNET.Matrix@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="66">
<summary>LU分解結果を利用して逆行列を求める</summary>
<param name="lu">LU分解行列</param>
<param name="permutation">置換ベクトル</param>
<param name="inverse">逆行列</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.LUInvert(GSLNET.MatrixView,GSLNET.Permutation,GSLNET.MatrixView@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="73">
<summary>LU分解結果を利用して逆行列を求める</summary>
<param name="lu">LU分解行列</param>
<param name="permutation">置換ベクトル</param>
<param name="inverse">逆行列</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.QRDecomposition(GSLNET.Matrix@,GSLNET.Vector@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="80">
<summary>QR分解を行う</summary>
<param name="matrix">行列</param>
<param name="tau">ハウスホルダーベクトル</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.QRSolve(GSLNET.Matrix,GSLNET.Vector,GSLNET.Vector,GSLNET.Vector@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="86">
<summary>QR分解結果を利用してAx=bを解く</summary>
<param name="qr">QR分解行列</param>
<param name="tau">ハウスホルダーベクトル</param>
<param name="b">ベクトルb</param>
<param name="x">解</param>
<returns>エラーコード</returns>
</member>
<member name="M:GSLNET.LinearAlgebra.QRSolve(GSLNET.Matrix,GSLNET.Vector,GSLNET.Vector@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\linearalgebra.h" line="94">
<summary>QR分解結果を利用してAx=bを解く</summary>
<param name="qr">QR分解行列</param>
<param name="tau">ハウスホルダーベクトル</param>
<param name="x">ベクトルb（解で上書きされる）</param>
<returns>エラーコード</returns>
</member>
</members>
</doc>
