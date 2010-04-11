<?xml version="1.0"?>
<doc>
<members>
<member name="T:GSLNET.Interpolation.Method" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="37">
<summary>保管法の種類</summary>
</member>
<member name="F:GSLNET.Interpolation.Method.Linear" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="39">
<summary>線形補間</summary>
</member>
<member name="F:GSLNET.Interpolation.Method.Polynomial" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="41">
<summary>多項式補間</summary>
</member>
<member name="F:GSLNET.Interpolation.Method.CSpline" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="43">
<summary>自然境界での三次スプライン</summary>
</member>
<member name="F:GSLNET.Interpolation.Method.CSpline_Periodic" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="45">
<summary>周期的境界の三次スプライン</summary>
</member>
<member name="F:GSLNET.Interpolation.Method.Akima" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="47">
<summary>自然境界での秋間スプライン</summary>
</member>
<member name="F:GSLNET.Interpolation.Method.Akima_Periodic" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="49">
<summary>周期的境界条件での秋間スプライン</summary>
</member>
<member name="P:GSLNET.Interpolation.DataNumber" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="53">
<summary>データ数を設定・取得する</summary>
</member>
<member name="M:GSLNET.Interpolation.#ctor(System.UInt32,GSLNET.Interpolation.Method)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="59">
<summary>コンストラクタ</summary>
<param name="size">データ数</param>
<param name="method">補間手法</param>
</member>
<member name="M:GSLNET.Interpolation.Initialize(System.Double[],System.Double[])" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="64">
<summary>初期化する</summary>
<param name="x">Xの値配列</param>
<param name="y">Yの値配列</param>
</member>
<member name="M:GSLNET.Interpolation.Evaluate(System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="69">
<summary>補間関数値を計算する</summary>
<param name="x">補間位置</param>
</member>
<member name="M:GSLNET.Interpolation.EvaluateDerivative(System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="73">
<summary>補間関数の微分値を計算する</summary>
<param name="x">補間位置</param>
</member>
<member name="M:GSLNET.Interpolation.EvaluateDerivative2(System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="77">
<summary>補間関数の二階微分値を計算する</summary>
<param name="x">補間位置</param>
</member>
<member name="M:GSLNET.Interpolation.EvaluateIntegral(System.Double,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\interpolation.h" line="81">
<summary>補間関数の積分値を計算する</summary>
<param name="x1">積分区間開始位置</param>
<param name="x2">積分区間終了位置</param>
</member>
<member name="P:GSLNET.SurfaceInterpolation.DataNumberX" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\surfaceinterpolation.h" line="36">
<summary>X方向のデータ数を設定・取得する</summary>
</member>
<member name="P:GSLNET.SurfaceInterpolation.DataNumberY" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\surfaceinterpolation.h" line="42">
<summary>Y方向のデータ数を設定・取得する</summary>
</member>
<member name="M:GSLNET.SurfaceInterpolation.Initialize(System.Double[],System.Double[],System.Double[0:,0:])" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\surfaceinterpolation.h" line="50">
<summary>初期化する</summary>
<param name="x">Xの値配列</param>
<param name="y">Yの値配列</param>
<param name="z">Zの値配列</param>
</member>
<member name="M:GSLNET.SurfaceInterpolation.Evaluate(System.Double,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\surfaceinterpolation.h" line="56">
<summary>補間関数値を計算する</summary>
<param name="x">Xの値</param>
<param name="y">Yの値</param>
</member>
</members>
</doc>
