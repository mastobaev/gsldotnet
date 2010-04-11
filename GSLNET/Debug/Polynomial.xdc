<?xml version="1.0"?>
<doc>
<members>
<member name="M:GSLNET.Complex.#ctor" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\complex.h" line="32">
<summary>コンストラクタ</summary>
</member>
<member name="M:GSLNET.Complex.Dispose" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\complex.h" line="35">
<summary>デコンストラクタ</summary>
</member>
<member name="P:GSLNET.Complex.RealPart" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\complex.h" line="38">
<summary>実部を設定・取得する</summary>
</member>
<member name="P:GSLNET.Complex.ImaginaryPart" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\complex.h" line="45">
<summary>虚部を設定・取得する</summary>
</member>
<member name="M:GSLNET.Complex.Rect(System.Double,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\complex.h" line="52">
<summary>直交座標系での座標値を与えて複素数を作成する</summary>
<param name="x">直交座標系でのx</param>
<param name="y">直交座標系でのy</param>
<returns>複素数オブジェクト</returns>
</member>
<member name="M:GSLNET.Complex.Polar(System.Double,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\complex.h" line="58">
<summary>極座標系での座標値を与えて複素数を作成する</summary>
<param name="r">極座標系でのr</param>
<param name="theta">極座標系でのtheta</param>
<returns>複素数オブジェクト</returns>
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
<member name="M:GSLNET.Polynomial.Dispose" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\polynomial.h" line="36">
<summary>デコンストラクタ</summary>
</member>
<member name="M:GSLNET.Polynomial.#ctor(System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\polynomial.h" line="40">
<summary>コンストラクタ</summary>
<param name="order">多項式の次数</param>
</member>
<member name="M:GSLNET.Polynomial.Solve(System.Double[],GSLNET.Complex[]@)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\polynomial.h" line="44">
<summary>多項式の解を計算する</summary>
<param name="coef">実数係数配列</param>
<param name="roots">解の配列</param>
<returns>求根が成功したか否か</returns>
</member>
<member name="M:GSLNET.Polynomial.Evaluate(System.Double[],System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\polynomial.h" line="50">
<summary>実数変数xの実数係数の多項式の値を計算する</summary>
<param name="coef">実数係数配列</param>
<param name="x">実数変数</param>
<returns>多項式の値</returns>
</member>
<member name="M:GSLNET.Polynomial.Evaluate(System.Double[],GSLNET.Complex!System.Runtime.CompilerServices.IsByValue)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\polynomial.h" line="56">
<summary>複素変数zの実数係数の多項式の値を計算する</summary>
<param name="coef">実数係数配列</param>
<param name="z">複素変数</param>
<returns>多項式の値</returns>
</member>
<member name="M:GSLNET.Polynomial.Evaluate(GSLNET.Complex[],GSLNET.Complex!System.Runtime.CompilerServices.IsByValue)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\polynomial.h" line="62">
<summary>複素変数zの複素数係数の多項式の値を計算する</summary>
<param name="coef">複素数係数配列</param>
<param name="z">複素変数</param>
<returns>多項式の値</returns>
</member>
</members>
</doc>
