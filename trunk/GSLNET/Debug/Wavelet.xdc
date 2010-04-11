<?xml version="1.0"?>
<doc>
<members>
<member name="T:GSLNET.Wavelet.WaveletType" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="31">
<summary>ウェーブレットの種類</summary>
</member>
<member name="F:GSLNET.Wavelet.WaveletType.Daubechies" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="33">
<summary>ドブシ・ウェーブレット</summary>
</member>
<member name="F:GSLNET.Wavelet.WaveletType.Haar" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="35">
<summary>ハール・ウェーブレット</summary>
</member>
<member name="F:GSLNET.Wavelet.WaveletType.BSpline" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="37">
<summary>ベータスプライン・ウェーブレット</summary>
</member>
<member name="T:GSLNET.Wavelet.WaveletDirection" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="41">
<summary>方向</summary>
</member>
<member name="F:GSLNET.Wavelet.WaveletDirection.Forward" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="43">
<summary>順</summary>
</member>
<member name="F:GSLNET.Wavelet.WaveletDirection.Inverse" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="45">
<summary>逆</summary>
</member>
<member name="M:GSLNET.Wavelet.#ctor(GSLNET.Wavelet.WaveletType,System.UInt32)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="49">
<summary>コンストラクタ</summary>
<param name="wType">ウェーブレットの種類</param>
<param name="k">ウェーブレット・ファミリーのメンバー</param>
</member>
<member name="M:GSLNET.Wavelet.Transform(System.Double[]@,GSLNET.Wavelet.WaveletDirection)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\wavelet.h" line="54">
<summary>変換処理を行う</summary>
<param name="data">変換するデータ</param>
<param name="dir">通常の変換か逆変換か</param>
</member>
</members>
</doc>
