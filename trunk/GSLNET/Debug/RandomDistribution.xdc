<?xml version="1.0"?>
<doc>
<members>
<member name="T:GSLNET.Rng.GeneratorType" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="30">
<summary>乱数生成器の種類</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.MT19937" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="32">
<summary>メルセンヌ・ツイスター</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.Ranlux1" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="34">
<summary>Luxury Random Numbers Level1</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.Ranlux2" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="36">
<summary>Luxury Random Numbers Level2</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.Ranlux389" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="38">
<summary>リュッシャ－の方法</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.CombinedMultipleRecursive" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="40">
<summary>レキュエルの重再起結合乱数発生器</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.MultipleRecursive" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="42">
<summary>レキュエルの重再起結合乱数発生器（五次）</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.Taus" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="44">
<summary>タウスワース型乱数発生器</summary>
</member>
<member name="F:GSLNET.Rng.GeneratorType.Taus2" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="46">
<summary>タウスワース型乱数発生器2</summary>
</member>
<member name="M:GSLNET.Rng.#ctor(GSLNET.Rng.GeneratorType)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="50">
<summary>コンストラクタ</summary>
<param name="gType">乱数生成器の種類</param>
</member>
<member name="M:GSLNET.Rng.#ctor(GSLNET.Rng.GeneratorType,System.UInt32!System.Runtime.CompilerServices.IsLong)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="54">
<summary>コンストラクタ</summary>
<param name="gType">乱数生成器の種類</param>
<param name="s">乱数の種</param>
</member>
<member name="M:GSLNET.Rng.Uniform" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\rng.h" line="59">
<summary>0~1の範囲に一様に分布する乱数を作成する</summary>
</member>
<member name="T:GSLNET.RandomDistribution.GaussianGeneratorType" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\randomdistribution.h" line="30">
<summary>正規乱数生成法の種類</summary>
</member>
<member name="F:GSLNET.RandomDistribution.GaussianGeneratorType.BoxMuler" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\randomdistribution.h" line="32">
<summary>ボックス・ミューラー法</summary>
</member>
<member name="F:GSLNET.RandomDistribution.GaussianGeneratorType.Ziggurat" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\randomdistribution.h" line="34">
<summary>マルサグリア-ツァンのジッグラト</summary>
</member>
<member name="F:GSLNET.RandomDistribution.GaussianGeneratorType.Ratio" decl="false" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\randomdistribution.h" line="36">
<summary>キンダーマン-モナハン-レバの比による方法</summary>
</member>
<member name="M:GSLNET.RandomDistribution.Gaussian(GSLNET.RandomDistribution.GaussianGeneratorType,System.Double,GSLNET.Rng)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\randomdistribution.h" line="40">
<summary>標準偏差σの正規乱数を返す</summary>
<param name="gType">正規乱数生成法の種類</param>
<param name="sigma">標準偏差</param>
<param name="random">乱数オブジェクト</param>
</member>
<member name="M:GSLNET.RandomDistribution.GaussianPdf(System.Double,System.Double)" decl="true" source="e:\projects\数値計算ライブラリ\gslnet\gslnet\randomdistribution.h" line="46">
<summary>標準偏差σの正規分布の確率密度関数の値を返す</summary>
<param name="x">x</param>
<param name="sigma">標準偏差</param>
</member>
</members>
</doc>
