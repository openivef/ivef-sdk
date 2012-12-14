/******************************************************************************
 *   Copyright (C) 2006 Chris Lukassen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 ******************************************************************************/
package luky.util;


import java.awt.*;


/******************************************************************************
 * This class is a data holder for various colours, which you can now acces by
 * name in stead of RGB value.<br> 
 * It is based on <a href=http://web.njit.edu/~walsh> this page </a> 
 * by Copyright  2005 Kevin J. Walsh <p>
 * <p> <a name=top>
 * The color table has been roughly divided up into shades.  
 * Select one of these:
 * <a href="#Black">Black and Gray</a>;
 * <a href="#Blue">Blue</a>;
 * <a href="#Brown">Brown</a>;
 * <a href="#Black">Gray</a>;
 * <a href="#Green">Green</a>;
 * <a href="#Orange">Orange</a>;
 * <a href="#Red">Red</a>;
 * <a href="#Violet">Violet</a>;
 * <a href="#White">White</a>;
 * <a href="#Yellow">Yellow</a>;
 * to jump to that division.  
 * <p>
 * <a href="#top" name=Black>[Click for top]</a><a href="#top" name=Gray></a>
 * <table border cols=4 cellpadding=3 width="100%"><tr><th colspan=4>Shades of Black and Gray</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> black </td><td>0;0;0</td><td>000000</td></td><td bgcolor=#000000><font color=#000000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey </td><td>190;190;190</td><td>BEBEBE</td></td><td bgcolor=#BEBEBE><font color=#BEBEBE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DimGrey </td><td>105;105;105</td><td>696969</td></td><td bgcolor=#696969><font color=#696969>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightGray </td><td>211;211;211</td><td>D3D3D3</td></td><td bgcolor=#D3D3D3><font color=#D3D3D3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSlateGrey </td><td>119;136;153</td><td>778899</td></td><td bgcolor=#778899><font color=#778899>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateGray </td><td>112;128;144</td><td>708090</td></td><td bgcolor=#708090><font color=#708090>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateGray1 </td><td>198;226;255</td><td>C6E2FF</td></td><td bgcolor=#C6E2FF><font color=#C6E2FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateGray2 </td><td>185;211;238</td><td>B9D3EE</td></td><td bgcolor=#B9D3EE><font color=#B9D3EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateGray3 </td><td>159;182;205</td><td>9FB6CD</td></td><td bgcolor=#9FB6CD><font color=#9FB6CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateGray4 </td><td>108;123;139</td><td>6C7B8B</td></td><td bgcolor=#6C7B8B><font color=#6C7B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateGrey </td><td>112;128;144</td><td>708090</td></td><td bgcolor=#708090><font color=#708090>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey0 </td><td>0;0;0</td><td>000000</td></td><td bgcolor=#000000><font color=#000000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey1 </td><td>3;3;3</td><td>030303</td></td><td bgcolor=#030303><font color=#030303>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey2 </td><td>5;5;5</td><td>050505</td></td><td bgcolor=#050505><font color=#050505>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey3 </td><td>8;8;8</td><td>080808</td></td><td bgcolor=#080808><font color=#080808>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey4 </td><td>10;10;10</td><td>0A0A0A</td></td><td bgcolor=#0A0A0A><font color=#0A0A0A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey5 </td><td>13;13;13</td><td>0D0D0D</td></td><td bgcolor=#0D0D0D><font color=#0D0D0D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey6 </td><td>15;15;15</td><td>0F0F0F</td></td><td bgcolor=#0F0F0F><font color=#0F0F0F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey7 </td><td>18;18;18</td><td>121212</td></td><td bgcolor=#121212><font color=#121212>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey8 </td><td>20;20;20</td><td>141414</td></td><td bgcolor=#141414><font color=#141414>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey9 </td><td>23;23;23</td><td>171717</td></td><td bgcolor=#171717><font color=#171717>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey10 </td><td>26;26;26</td><td>1A1A1A</td></td><td bgcolor=#1A1A1A><font color=#1A1A1A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey11 </td><td>28;28;28</td><td>1C1C1C</td></td><td bgcolor=#1C1C1C><font color=#1C1C1C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey12 </td><td>31;31;31</td><td>1F1F1F</td></td><td bgcolor=#1F1F1F><font color=#1F1F1F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey13 </td><td>33;33;33</td><td>212121</td></td><td bgcolor=#212121><font color=#212121>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey14 </td><td>36;36;36</td><td>242424</td></td><td bgcolor=#242424><font color=#242424>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey15 </td><td>38;38;38</td><td>262626</td></td><td bgcolor=#262626><font color=#262626>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey16 </td><td>41;41;41</td><td>292929</td></td><td bgcolor=#292929><font color=#292929>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey17 </td><td>43;43;43</td><td>2B2B2B</td></td><td bgcolor=#2B2B2B><font color=#2B2B2B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey18 </td><td>46;46;46</td><td>2E2E2E</td></td><td bgcolor=#2E2E2E><font color=#2E2E2E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey19 </td><td>48;48;48</td><td>303030</td></td><td bgcolor=#303030><font color=#303030>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey20 </td><td>51;51;51</td><td>333333</td></td><td bgcolor=#333333><font color=#333333>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey21 </td><td>54;54;54</td><td>363636</td></td><td bgcolor=#363636><font color=#363636>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey22 </td><td>56;56;56</td><td>383838</td></td><td bgcolor=#383838><font color=#383838>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey23 </td><td>59;59;59</td><td>3B3B3B</td></td><td bgcolor=#3B3B3B><font color=#3B3B3B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey24 </td><td>61;61;61</td><td>3D3D3D</td></td><td bgcolor=#3D3D3D><font color=#3D3D3D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey25 </td><td>64;64;64</td><td>404040</td></td><td bgcolor=#404040><font color=#404040>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey26 </td><td>66;66;66</td><td>424242</td></td><td bgcolor=#424242><font color=#424242>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey27 </td><td>69;69;69</td><td>454545</td></td><td bgcolor=#454545><font color=#454545>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey28 </td><td>71;71;71</td><td>474747</td></td><td bgcolor=#474747><font color=#474747>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey29 </td><td>74;74;74</td><td>4A4A4A</td></td><td bgcolor=#4A4A4A><font color=#4A4A4A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey30 </td><td>77;77;77</td><td>4D4D4D</td></td><td bgcolor=#4D4D4D><font color=#4D4D4D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey31 </td><td>79;79;79</td><td>4F4F4F</td></td><td bgcolor=#4F4F4F><font color=#4F4F4F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey32 </td><td>82;82;82</td><td>525252</td></td><td bgcolor=#525252><font color=#525252>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey33 </td><td>84;84;84</td><td>545454</td></td><td bgcolor=#545454><font color=#545454>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey34 </td><td>87;87;87</td><td>575757</td></td><td bgcolor=#575757><font color=#575757>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey35 </td><td>89;89;89</td><td>595959</td></td><td bgcolor=#595959><font color=#595959>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey36 </td><td>92;92;92</td><td>5C5C5C</td></td><td bgcolor=#5C5C5C><font color=#5C5C5C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey37 </td><td>94;94;94</td><td>5E5E5E</td></td><td bgcolor=#5E5E5E><font color=#5E5E5E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey38 </td><td>97;97;97</td><td>616161</td></td><td bgcolor=#616161><font color=#616161>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey39 </td><td>99;99;99</td><td>636363</td></td><td bgcolor=#636363><font color=#636363>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey40 </td><td>102;102;102</td><td>666666</td></td><td bgcolor=#666666><font color=#666666>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey41 </td><td>105;105;105</td><td>696969</td></td><td bgcolor=#696969><font color=#696969>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey42 </td><td>107;107;107</td><td>6B6B6B</td></td><td bgcolor=#6B6B6B><font color=#6B6B6B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey43 </td><td>110;110;110</td><td>6E6E6E</td></td><td bgcolor=#6E6E6E><font color=#6E6E6E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey44 </td><td>112;112;112</td><td>707070</td></td><td bgcolor=#707070><font color=#707070>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey45 </td><td>115;115;115</td><td>737373</td></td><td bgcolor=#737373><font color=#737373>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey46 </td><td>117;117;117</td><td>757575</td></td><td bgcolor=#757575><font color=#757575>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey47 </td><td>120;120;120</td><td>787878</td></td><td bgcolor=#787878><font color=#787878>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey48 </td><td>122;122;122</td><td>7A7A7A</td></td><td bgcolor=#7A7A7A><font color=#7A7A7A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey49 </td><td>125;125;125</td><td>7D7D7D</td></td><td bgcolor=#7D7D7D><font color=#7D7D7D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey50 </td><td>127;127;127</td><td>7F7F7F</td></td><td bgcolor=#7F7F7F><font color=#7F7F7F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey51 </td><td>130;130;130</td><td>828282</td></td><td bgcolor=#828282><font color=#828282>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey52 </td><td>133;133;133</td><td>858585</td></td><td bgcolor=#858585><font color=#858585>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey53 </td><td>135;135;135</td><td>878787</td></td><td bgcolor=#878787><font color=#878787>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey54 </td><td>138;138;138</td><td>8A8A8A</td></td><td bgcolor=#8A8A8A><font color=#8A8A8A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey55 </td><td>140;140;140</td><td>8C8C8C</td></td><td bgcolor=#8C8C8C><font color=#8C8C8C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey56 </td><td>143;143;143</td><td>8F8F8F</td></td><td bgcolor=#8F8F8F><font color=#8F8F8F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey57 </td><td>145;145;145</td><td>919191</td></td><td bgcolor=#919191><font color=#919191>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey58 </td><td>148;148;148</td><td>949494</td></td><td bgcolor=#949494><font color=#949494>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey59 </td><td>150;150;150</td><td>969696</td></td><td bgcolor=#969696><font color=#969696>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey60 </td><td>153;153;153</td><td>999999</td></td><td bgcolor=#999999><font color=#999999>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey61 </td><td>156;156;156</td><td>9C9C9C</td></td><td bgcolor=#9C9C9C><font color=#9C9C9C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey62 </td><td>158;158;158</td><td>9E9E9E</td></td><td bgcolor=#9E9E9E><font color=#9E9E9E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey63 </td><td>161;161;161</td><td>A1A1A1</td></td><td bgcolor=#A1A1A1><font color=#A1A1A1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey64 </td><td>163;163;163</td><td>A3A3A3</td></td><td bgcolor=#A3A3A3><font color=#A3A3A3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey65 </td><td>166;166;166</td><td>A6A6A6</td></td><td bgcolor=#A6A6A6><font color=#A6A6A6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey66 </td><td>168;168;168</td><td>A8A8A8</td></td><td bgcolor=#A8A8A8><font color=#A8A8A8>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey67 </td><td>171;171;171</td><td>ABABAB</td></td><td bgcolor=#ABABAB><font color=#ABABAB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey68 </td><td>173;173;173</td><td>ADADAD</td></td><td bgcolor=#ADADAD><font color=#ADADAD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey69 </td><td>176;176;176</td><td>B0B0B0</td></td><td bgcolor=#B0B0B0><font color=#B0B0B0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey70 </td><td>179;179;179</td><td>B3B3B3</td></td><td bgcolor=#B3B3B3><font color=#B3B3B3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey71 </td><td>181;181;181</td><td>B5B5B5</td></td><td bgcolor=#B5B5B5><font color=#B5B5B5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey72 </td><td>184;184;184</td><td>B8B8B8</td></td><td bgcolor=#B8B8B8><font color=#B8B8B8>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey73 </td><td>186;186;186</td><td>BABABA</td></td><td bgcolor=#BABABA><font color=#BABABA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey74 </td><td>189;189;189</td><td>BDBDBD</td></td><td bgcolor=#BDBDBD><font color=#BDBDBD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey75 </td><td>191;191;191</td><td>BFBFBF</td></td><td bgcolor=#BFBFBF><font color=#BFBFBF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey76 </td><td>194;194;194</td><td>C2C2C2</td></td><td bgcolor=#C2C2C2><font color=#C2C2C2>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey77 </td><td>196;196;196</td><td>C4C4C4</td></td><td bgcolor=#C4C4C4><font color=#C4C4C4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey78 </td><td>199;199;199</td><td>C7C7C7</td></td><td bgcolor=#C7C7C7><font color=#C7C7C7>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey79 </td><td>201;201;201</td><td>C9C9C9</td></td><td bgcolor=#C9C9C9><font color=#C9C9C9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey80 </td><td>204;204;204</td><td>CCCCCC</td></td><td bgcolor=#CCCCCC><font color=#CCCCCC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey81 </td><td>207;207;207</td><td>CFCFCF</td></td><td bgcolor=#CFCFCF><font color=#CFCFCF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey82 </td><td>209;209;209</td><td>D1D1D1</td></td><td bgcolor=#D1D1D1><font color=#D1D1D1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey83 </td><td>212;212;212</td><td>D4D4D4</td></td><td bgcolor=#D4D4D4><font color=#D4D4D4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey84 </td><td>214;214;214</td><td>D6D6D6</td></td><td bgcolor=#D6D6D6><font color=#D6D6D6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey85 </td><td>217;217;217</td><td>D9D9D9</td></td><td bgcolor=#D9D9D9><font color=#D9D9D9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey86 </td><td>219;219;219</td><td>DBDBDB</td></td><td bgcolor=#DBDBDB><font color=#DBDBDB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey87 </td><td>222;222;222</td><td>DEDEDE</td></td><td bgcolor=#DEDEDE><font color=#DEDEDE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey88 </td><td>224;224;224</td><td>E0E0E0</td></td><td bgcolor=#E0E0E0><font color=#E0E0E0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey89 </td><td>227;227;227</td><td>E3E3E3</td></td><td bgcolor=#E3E3E3><font color=#E3E3E3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey90 </td><td>229;229;229</td><td>E5E5E5</td></td><td bgcolor=#E5E5E5><font color=#E5E5E5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey91 </td><td>232;232;232</td><td>E8E8E8</td></td><td bgcolor=#E8E8E8><font color=#E8E8E8>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey92 </td><td>235;235;235</td><td>EBEBEB</td></td><td bgcolor=#EBEBEB><font color=#EBEBEB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey93 </td><td>237;237;237</td><td>EDEDED</td></td><td bgcolor=#EDEDED><font color=#EDEDED>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey94 </td><td>240;240;240</td><td>F0F0F0</td></td><td bgcolor=#F0F0F0><font color=#F0F0F0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey95 </td><td>242;242;242</td><td>F2F2F2</td></td><td bgcolor=#F2F2F2><font color=#F2F2F2>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey96 </td><td>245;245;245</td><td>F5F5F5</td></td><td bgcolor=#F5F5F5><font color=#F5F5F5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey97 </td><td>247;247;247</td><td>F7F7F7</td></td><td bgcolor=#F7F7F7><font color=#F7F7F7>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey98 </td><td>250;250;250</td><td>FAFAFA</td></td><td bgcolor=#FAFAFA><font color=#FAFAFA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey99 </td><td>252;252;252</td><td>FCFCFC</td></td><td bgcolor=#FCFCFC><font color=#FCFCFC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> grey100 </td><td>255;255;255</td><td>FFFFFF</td></td><td bgcolor=#FFFFFF><font color=#FFFFFF>### SAMPLE ###</font></td></tr>
 * </table>
 * <a href="#top" name=Blue>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of Blue</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> AliceBlue </td><td>240;248;255</td><td>F0F8FF</td></td><td bgcolor=#F0F8FF><font color=#F0F8FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> BlueViolet </td><td>138;43;226</td><td>8A2BE2</td></td><td bgcolor=#8A2BE2><font color=#8A2BE2>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> CadetBlue </td><td>95;158;160</td><td>5F9EA0</td></td><td bgcolor=#5F9EA0><font color=#5F9EA0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> CadetBlue1 </td><td>152;245;255</td><td>98F5FF</td></td><td bgcolor=#98F5FF><font color=#98F5FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> CadetBlue2 </td><td>142;229;238</td><td>8EE5EE</td></td><td bgcolor=#8EE5EE><font color=#8EE5EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> CadetBlue3 </td><td>122;197;205</td><td>7AC5CD</td></td><td bgcolor=#7AC5CD><font color=#7AC5CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> CadetBlue4 </td><td>83;134;139</td><td>53868B</td></td><td bgcolor=#53868B><font color=#53868B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> CornflowerBlue </td><td>100;149;237</td><td>6495ED</td></td><td bgcolor=#6495ED><font color=#6495ED>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSlateBlue </td><td>72;61;139</td><td>483D8B</td></td><td bgcolor=#483D8B><font color=#483D8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkTurquoise </td><td>0;206;209</td><td>00CED1</td></td><td bgcolor=#00CED1><font color=#00CED1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepSkyBlue </td><td>0;191;255</td><td>00BFFF</td></td><td bgcolor=#00BFFF><font color=#00BFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepSkyBlue1 </td><td>0;191;255</td><td>00BFFF</td></td><td bgcolor=#00BFFF><font color=#00BFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepSkyBlue2 </td><td>0;178;238</td><td>00B2EE</td></td><td bgcolor=#00B2EE><font color=#00B2EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepSkyBlue3 </td><td>0;154;205</td><td>009ACD</td></td><td bgcolor=#009ACD><font color=#009ACD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepSkyBlue4 </td><td>0;104;139</td><td>00688B</td></td><td bgcolor=#00688B><font color=#00688B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DodgerBlue </td><td>30;144;255</td><td>1E90FF</td></td><td bgcolor=#1E90FF><font color=#1E90FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DodgerBlue1 </td><td>30;144;255</td><td>1E90FF</td></td><td bgcolor=#1E90FF><font color=#1E90FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DodgerBlue2 </td><td>28;134;238</td><td>1C86EE</td></td><td bgcolor=#1C86EE><font color=#1C86EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DodgerBlue3 </td><td>24;116;205</td><td>1874CD</td></td><td bgcolor=#1874CD><font color=#1874CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DodgerBlue4 </td><td>16;78;139</td><td>104E8B</td></td><td bgcolor=#104E8B><font color=#104E8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightBlue </td><td>173;216;230</td><td>ADD8E6</td></td><td bgcolor=#ADD8E6><font color=#ADD8E6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightBlue1 </td><td>191;239;255</td><td>BFEFFF</td></td><td bgcolor=#BFEFFF><font color=#BFEFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightBlue2 </td><td>178;223;238</td><td>B2DFEE</td></td><td bgcolor=#B2DFEE><font color=#B2DFEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightBlue3 </td><td>154;192;205</td><td>9AC0CD</td></td><td bgcolor=#9AC0CD><font color=#9AC0CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightBlue4 </td><td>104;131;139</td><td>68838B</td></td><td bgcolor=#68838B><font color=#68838B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightCyan </td><td>224;255;255</td><td>E0FFFF</td></td><td bgcolor=#E0FFFF><font color=#E0FFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightCyan1 </td><td>224;255;255</td><td>E0FFFF</td></td><td bgcolor=#E0FFFF><font color=#E0FFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightCyan2 </td><td>209;238;238</td><td>D1EEEE</td></td><td bgcolor=#D1EEEE><font color=#D1EEEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightCyan3 </td><td>180;205;205</td><td>B4CDCD</td></td><td bgcolor=#B4CDCD><font color=#B4CDCD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightCyan4 </td><td>122;139;139</td><td>7A8B8B</td></td><td bgcolor=#7A8B8B><font color=#7A8B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSkyBlue </td><td>135;206;250</td><td>87CEFA</td></td><td bgcolor=#87CEFA><font color=#87CEFA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSkyBlue1 </td><td>176;226;255</td><td>B0E2FF</td></td><td bgcolor=#B0E2FF><font color=#B0E2FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSkyBlue2 </td><td>164;211;238</td><td>A4D3EE</td></td><td bgcolor=#A4D3EE><font color=#A4D3EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSkyBlue3 </td><td>141;182;205</td><td>8DB6CD</td></td><td bgcolor=#8DB6CD><font color=#8DB6CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSkyBlue4 </td><td>96;123;139</td><td>607B8B</td></td><td bgcolor=#607B8B><font color=#607B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSlateBlue </td><td>132;112;255</td><td>8470FF</td></td><td bgcolor=#8470FF><font color=#8470FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSteelBlue </td><td>176;196;222</td><td>B0C4DE</td></td><td bgcolor=#B0C4DE><font color=#B0C4DE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSteelBlue1 </td><td>202;225;255</td><td>CAE1FF</td></td><td bgcolor=#CAE1FF><font color=#CAE1FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSteelBlue2 </td><td>188;210;238</td><td>BCD2EE</td></td><td bgcolor=#BCD2EE><font color=#BCD2EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSteelBlue3 </td><td>162;181;205</td><td>A2B5CD</td></td><td bgcolor=#A2B5CD><font color=#A2B5CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSteelBlue4 </td><td>110;123;139</td><td>6E7B8B</td></td><td bgcolor=#6E7B8B><font color=#6E7B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumAquamarine </td><td>102;205;170</td><td>66CDAA</td></td><td bgcolor=#66CDAA><font color=#66CDAA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumBlue </td><td>0;0;205</td><td>0000CD</td></td><td bgcolor=#0000CD><font color=#0000CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumSlateBlue </td><td>123;104;238</td><td>7B68EE</td></td><td bgcolor=#7B68EE><font color=#7B68EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumTurquoise </td><td>72;209;204</td><td>48D1CC</td></td><td bgcolor=#48D1CC><font color=#48D1CC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MidnightBlue </td><td>25;25;112</td><td>191970</td></td><td bgcolor=#191970><font color=#191970>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> NavyBlue </td><td>0;0;128</td><td>000080</td></td><td bgcolor=#000080><font color=#000080>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleTurquoise </td><td>175;238;238</td><td>AFEEEE</td></td><td bgcolor=#AFEEEE><font color=#AFEEEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleTurquoise1 </td><td>187;255;255</td><td>BBFFFF</td></td><td bgcolor=#BBFFFF><font color=#BBFFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleTurquoise2 </td><td>174;238;238</td><td>AEEEEE</td></td><td bgcolor=#AEEEEE><font color=#AEEEEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleTurquoise3 </td><td>150;205;205</td><td>96CDCD</td></td><td bgcolor=#96CDCD><font color=#96CDCD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleTurquoise4 </td><td>102;139;139</td><td>668B8B</td></td><td bgcolor=#668B8B><font color=#668B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PowderBlue </td><td>176;224;230</td><td>B0E0E6</td></td><td bgcolor=#B0E0E6><font color=#B0E0E6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RoyalBlue </td><td>65;105;225</td><td>4169E1</td></td><td bgcolor=#4169E1><font color=#4169E1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RoyalBlue1 </td><td>72;118;255</td><td>4876FF</td></td><td bgcolor=#4876FF><font color=#4876FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RoyalBlue2 </td><td>67;110;238</td><td>436EEE</td></td><td bgcolor=#436EEE><font color=#436EEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RoyalBlue3 </td><td>58;95;205</td><td>3A5FCD</td></td><td bgcolor=#3A5FCD><font color=#3A5FCD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RoyalBlue4 </td><td>39;64;139</td><td>27408B</td></td><td bgcolor=#27408B><font color=#27408B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RoyalBlue5 </td><td>00;34;102</td><td>002266</td></td><td bgcolor=#002266><font color=#002266>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SkyBlue </td><td>135;206;235</td><td>87CEEB</td></td><td bgcolor=#87CEEB><font color=#87CEEB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SkyBlue1 </td><td>135;206;255</td><td>87CEFF</td></td><td bgcolor=#87CEFF><font color=#87CEFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SkyBlue2 </td><td>126;192;238</td><td>7EC0EE</td></td><td bgcolor=#7EC0EE><font color=#7EC0EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SkyBlue3 </td><td>108;166;205</td><td>6CA6CD</td></td><td bgcolor=#6CA6CD><font color=#6CA6CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SkyBlue4 </td><td>74;112;139</td><td>4A708B</td></td><td bgcolor=#4A708B><font color=#4A708B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateBlue </td><td>106;90;205</td><td>6A5ACD</td></td><td bgcolor=#6A5ACD><font color=#6A5ACD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateBlue1 </td><td>131;111;255</td><td>836FFF</td></td><td bgcolor=#836FFF><font color=#836FFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateBlue2 </td><td>122;103;238</td><td>7A67EE</td></td><td bgcolor=#7A67EE><font color=#7A67EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateBlue3 </td><td>105;89;205</td><td>6959CD</td></td><td bgcolor=#6959CD><font color=#6959CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SlateBlue4 </td><td>71;60;139</td><td>473C8B</td></td><td bgcolor=#473C8B><font color=#473C8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SteelBlue </td><td>70;130;180</td><td>4682B4</td></td><td bgcolor=#4682B4><font color=#4682B4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SteelBlue1 </td><td>99;184;255</td><td>63B8FF</td></td><td bgcolor=#63B8FF><font color=#63B8FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SteelBlue2 </td><td>92;172;238</td><td>5CACEE</td></td><td bgcolor=#5CACEE><font color=#5CACEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SteelBlue3 </td><td>79;148;205</td><td>4F94CD</td></td><td bgcolor=#4F94CD><font color=#4F94CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SteelBlue4 </td><td>54;100;139</td><td>36648B</td></td><td bgcolor=#36648B><font color=#36648B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> aquamarine </td><td>127;255;212</td><td>7FFFD4</td></td><td bgcolor=#7FFFD4><font color=#7FFFD4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> aquamarine1 </td><td>127;255;212</td><td>7FFFD4</td></td><td bgcolor=#7FFFD4><font color=#7FFFD4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> aquamarine2 </td><td>118;238;198</td><td>76EEC6</td></td><td bgcolor=#76EEC6><font color=#76EEC6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> aquamarine3 </td><td>102;205;170</td><td>66CDAA</td></td><td bgcolor=#66CDAA><font color=#66CDAA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> aquamarine4 </td><td>69;139;116</td><td>458B74</td></td><td bgcolor=#458B74><font color=#458B74>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> azure </td><td>240;255;255</td><td>F0FFFF</td></td><td bgcolor=#F0FFFF><font color=#F0FFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> azure1 </td><td>240;255;255</td><td>F0FFFF</td></td><td bgcolor=#F0FFFF><font color=#F0FFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> azure2 </td><td>224;238;238</td><td>E0EEEE</td></td><td bgcolor=#E0EEEE><font color=#E0EEEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> azure3 </td><td>193;205;205</td><td>C1CDCD</td></td><td bgcolor=#C1CDCD><font color=#C1CDCD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> azure4 </td><td>131;139;139</td><td>838B8B</td></td><td bgcolor=#838B8B><font color=#838B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> blue </td><td>0;0;255</td><td>0000FF</td></td><td bgcolor=#0000FF><font color=#0000FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> blue1 </td><td>0;0;255</td><td>0000FF</td></td><td bgcolor=#0000FF><font color=#0000FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> blue2 </td><td>0;0;238</td><td>0000EE</td></td><td bgcolor=#0000EE><font color=#0000EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> blue3 </td><td>0;0;205</td><td>0000CD</td></td><td bgcolor=#0000CD><font color=#0000CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> blue4 </td><td>0;0;139</td><td>00008B</td></td><td bgcolor=#00008B><font color=#00008B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cyan </td><td>0;255;255</td><td>00FFFF</td></td><td bgcolor=#00FFFF><font color=#00FFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cyan1 </td><td>0;255;255</td><td>00FFFF</td></td><td bgcolor=#00FFFF><font color=#00FFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cyan2 </td><td>0;238;238</td><td>00EEEE</td></td><td bgcolor=#00EEEE><font color=#00EEEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cyan3 </td><td>0;205;205</td><td>00CDCD</td></td><td bgcolor=#00CDCD><font color=#00CDCD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cyan4 </td><td>0;139;139</td><td>008B8B</td></td><td bgcolor=#008B8B><font color=#008B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> navy </td><td>0;0;128</td><td>000080</td></td><td bgcolor=#000080><font color=#000080>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> turquoise </td><td>64;224;208</td><td>40E0D0</td></td><td bgcolor=#40E0D0><font color=#40E0D0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> turquoise1 </td><td>0;245;255</td><td>00F5FF</td></td><td bgcolor=#00F5FF><font color=#00F5FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> turquoise2 </td><td>0;229;238</td><td>00E5EE</td></td><td bgcolor=#00E5EE><font color=#00E5EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> turquoise3 </td><td>0;197;205</td><td>00C5CD</td></td><td bgcolor=#00C5CD><font color=#00C5CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> turquoise4 </td><td>0;134;139</td><td>00868B</td></td><td bgcolor=#00868B><font color=#00868B>### (c) 1999 /KJW ###</font></td></tr>
 * <tr align=center><td> DarkSlateGray </td><td>47;79;79</td><td>2F4F4F</td></td><td bgcolor=#2F4F4F><font color=#2F4F4F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSlateGray1 </td><td>151;255;255</td><td>97FFFF</td></td><td bgcolor=#97FFFF><font color=#97FFFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSlateGray2 </td><td>141;238;238</td><td>8DEEEE</td></td><td bgcolor=#8DEEEE><font color=#8DEEEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSlateGray3 </td><td>121;205;205</td><td>79CDCD</td></td><td bgcolor=#79CDCD><font color=#79CDCD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSlateGray4 </td><td>82;139;139</td><td>528B8B</td></td><td bgcolor=#528B8B><font color=#528B8B>### SAMPLE ###</font></td></tr>
 * </table>
 * <a href="#top" name=Brown>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of Brown</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> RosyBrown </td><td>188;143;143</td><td>BC8F8F</td></td><td bgcolor=#BC8F8F><font color=#BC8F8F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RosyBrown1 </td><td>255;193;193</td><td>FFC1C1</td></td><td bgcolor=#FFC1C1><font color=#FFC1C1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RosyBrown2 </td><td>238;180;180</td><td>EEB4B4</td></td><td bgcolor=#EEB4B4><font color=#EEB4B4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RosyBrown3 </td><td>205;155;155</td><td>CD9B9B</td></td><td bgcolor=#CD9B9B><font color=#CD9B9B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> RosyBrown4 </td><td>139;105;105</td><td>8B6969</td></td><td bgcolor=#8B6969><font color=#8B6969>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SaddleBrown </td><td>139;69;19</td><td>8B4513</td></td><td bgcolor=#8B4513><font color=#8B4513>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SandyBrown </td><td>244;164;96</td><td>F4A460</td></td><td bgcolor=#F4A460><font color=#F4A460>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> beige </td><td>245;245;220</td><td>F5F5DC</td></td><td bgcolor=#F5F5DC><font color=#F5F5DC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> brown </td><td>165;42;42</td><td>A52A2A</td></td><td bgcolor=#A52A2A><font color=#A52A2A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> brown1 </td><td>255;64;64</td><td>FF4040</td></td><td bgcolor=#FF4040><font color=#FF4040>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> brown2 </td><td>238;59;59</td><td>EE3B3B</td></td><td bgcolor=#EE3B3B><font color=#EE3B3B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> brown3 </td><td>205;51;51</td><td>CD3333</td></td><td bgcolor=#CD3333><font color=#CD3333>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> brown4 </td><td>139;35;35</td><td>8B2323</td></td><td bgcolor=#8B2323><font color=#8B2323>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> burlywood </td><td>222;184;135</td><td>DEB887</td></td><td bgcolor=#DEB887><font color=#DEB887>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> burlywood1 </td><td>255;211;155</td><td>FFD39B</td></td><td bgcolor=#FFD39B><font color=#FFD39B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> burlywood2 </td><td>238;197;145</td><td>EEC591</td></td><td bgcolor=#EEC591><font color=#EEC591>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> burlywood3 </td><td>205;170;125</td><td>CDAA7D</td></td><td bgcolor=#CDAA7D><font color=#CDAA7D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> burlywood4 </td><td>139;115;85</td><td>8B7355</td></td><td bgcolor=#8B7355><font color=#8B7355>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chocolate </td><td>210;105;30</td><td>D2691E</td></td><td bgcolor=#D2691E><font color=#D2691E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chocolate1 </td><td>255;127;36</td><td>FF7F24</td></td><td bgcolor=#FF7F24><font color=#FF7F24>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chocolate2 </td><td>238;118;33</td><td>EE7621</td></td><td bgcolor=#EE7621><font color=#EE7621>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chocolate3 </td><td>205;102;29</td><td>CD661D</td></td><td bgcolor=#CD661D><font color=#CD661D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chocolate4 </td><td>139;69;19</td><td>8B4513</td></td><td bgcolor=#8B4513><font color=#8B4513>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> peru </td><td>205;133;63</td><td>CD853F</td></td><td bgcolor=#CD853F><font color=#CD853F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tan </td><td>210;180;140</td><td>D2B48C</td></td><td bgcolor=#D2B48C><font color=#D2B48C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tan1 </td><td>255;165;79</td><td>FFA54F</td></td><td bgcolor=#FFA54F><font color=#FFA54F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tan2 </td><td>238;154;73</td><td>EE9A49</td></td><td bgcolor=#EE9A49><font color=#EE9A49>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tan3 </td><td>205;133;63</td><td>CD853F</td></td><td bgcolor=#CD853F><font color=#CD853F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tan4 </td><td>139;90;43</td><td>8B5A2B</td></td><td bgcolor=#8B5A2B><font color=#8B5A2B>### (c) 1999 walsh&#064;njit&#046;edu ###</font></td></tr>
 * </table>
 * 
 * <a href="#top" name=Green>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of Green</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> DarkGreen </td><td>0;100;0</td><td>006400</td></td><td bgcolor=#006400><font color=#006400>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkKhaki </td><td>189;183;107</td><td>BDB76B</td></td><td bgcolor=#BDB76B><font color=#BDB76B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOliveGreen </td><td>85;107;47</td><td>556B2F</td></td><td bgcolor=#556B2F><font color=#556B2F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOliveGreen1 </td><td>202;255;112</td><td>CAFF70</td></td><td bgcolor=#CAFF70><font color=#CAFF70>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOliveGreen2 </td><td>188;238;104</td><td>BCEE68</td></td><td bgcolor=#BCEE68><font color=#BCEE68>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOliveGreen3 </td><td>162;205;90</td><td>A2CD5A</td></td><td bgcolor=#A2CD5A><font color=#A2CD5A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOliveGreen4 </td><td>110;139;61</td><td>6E8B3D</td></td><td bgcolor=#6E8B3D><font color=#6E8B3D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSeaGreen </td><td>143;188;143</td><td>8FBC8F</td></td><td bgcolor=#8FBC8F><font color=#8FBC8F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSeaGreen1 </td><td>193;255;193</td><td>C1FFC1</td></td><td bgcolor=#C1FFC1><font color=#C1FFC1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSeaGreen2 </td><td>180;238;180</td><td>B4EEB4</td></td><td bgcolor=#B4EEB4><font color=#B4EEB4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSeaGreen3 </td><td>155;205;155</td><td>9BCD9B</td></td><td bgcolor=#9BCD9B><font color=#9BCD9B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSeaGreen4 </td><td>105;139;105</td><td>698B69</td></td><td bgcolor=#698B69><font color=#698B69>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> ForestGreen </td><td>34;139;34</td><td>228B22</td></td><td bgcolor=#228B22><font color=#228B22>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> GreenYellow </td><td>173;255;47</td><td>ADFF2F</td></td><td bgcolor=#ADFF2F><font color=#ADFF2F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LawnGreen </td><td>124;252;0</td><td>7CFC00</td></td><td bgcolor=#7CFC00><font color=#7CFC00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSeaGreen </td><td>32;178;170</td><td>20B2AA</td></td><td bgcolor=#20B2AA><font color=#20B2AA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LimeGreen </td><td>50;205;50</td><td>32CD32</td></td><td bgcolor=#32CD32><font color=#32CD32>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumSeaGreen </td><td>60;179;113</td><td>3CB371</td></td><td bgcolor=#3CB371><font color=#3CB371>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumSpringGreen </td><td>0;250;154</td><td>00FA9A</td></td><td bgcolor=#00FA9A><font color=#00FA9A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MintCream </td><td>245;255;250</td><td>F5FFFA</td></td><td bgcolor=#F5FFFA><font color=#F5FFFA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OliveDrab </td><td>107;142;35</td><td>6B8E23</td></td><td bgcolor=#6B8E23><font color=#6B8E23>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OliveDrab1 </td><td>192;255;62</td><td>C0FF3E</td></td><td bgcolor=#C0FF3E><font color=#C0FF3E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OliveDrab2 </td><td>179;238;58</td><td>B3EE3A</td></td><td bgcolor=#B3EE3A><font color=#B3EE3A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OliveDrab3 </td><td>154;205;50</td><td>9ACD32</td></td><td bgcolor=#9ACD32><font color=#9ACD32>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OliveDrab4 </td><td>105;139;34</td><td>698B22</td></td><td bgcolor=#698B22><font color=#698B22>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleGreen </td><td>152;251;152</td><td>98FB98</td></td><td bgcolor=#98FB98><font color=#98FB98>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleGreen1 </td><td>154;255;154</td><td>9AFF9A</td></td><td bgcolor=#9AFF9A><font color=#9AFF9A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleGreen2 </td><td>144;238;144</td><td>90EE90</td></td><td bgcolor=#90EE90><font color=#90EE90>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleGreen3 </td><td>124;205;124</td><td>7CCD7C</td></td><td bgcolor=#7CCD7C><font color=#7CCD7C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleGreen4 </td><td>84;139;84</td><td>548B54</td></td><td bgcolor=#548B54><font color=#548B54>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SeaGreen </td><td>46;139;87</td><td>2E8B57</td></td><td bgcolor=#2E8B57><font color=#2E8B57>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SeaGreen1 </td><td>84;255;159</td><td>54FF9F</td></td><td bgcolor=#54FF9F><font color=#54FF9F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SeaGreen2 </td><td>78;238;148</td><td>4EEE94</td></td><td bgcolor=#4EEE94><font color=#4EEE94>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SeaGreen3 </td><td>67;205;128</td><td>43CD80</td></td><td bgcolor=#43CD80><font color=#43CD80>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SeaGreen4 </td><td>46;139;87</td><td>2E8B57</td></td><td bgcolor=#2E8B57><font color=#2E8B57>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SpringGreen </td><td>0;255;127</td><td>00FF7F</td></td><td bgcolor=#00FF7F><font color=#00FF7F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SpringGreen1 </td><td>0;255;127</td><td>00FF7F</td></td><td bgcolor=#00FF7F><font color=#00FF7F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SpringGreen2 </td><td>0;238;118</td><td>00EE76</td></td><td bgcolor=#00EE76><font color=#00EE76>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SpringGreen3 </td><td>0;205;102</td><td>00CD66</td></td><td bgcolor=#00CD66><font color=#00CD66>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> SpringGreen4 </td><td>0;139;69</td><td>008B45</td></td><td bgcolor=#008B45><font color=#008B45>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> YellowGreen </td><td>154;205;50</td><td>9ACD32</td></td><td bgcolor=#9ACD32><font color=#9ACD32>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chartreuse </td><td>127;255;0</td><td>7FFF00</td></td><td bgcolor=#7FFF00><font color=#7FFF00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chartreuse1 </td><td>127;255;0</td><td>7FFF00</td></td><td bgcolor=#7FFF00><font color=#7FFF00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chartreuse2 </td><td>118;238;0</td><td>76EE00</td></td><td bgcolor=#76EE00><font color=#76EE00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chartreuse3 </td><td>102;205;0</td><td>66CD00</td></td><td bgcolor=#66CD00><font color=#66CD00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> chartreuse4 </td><td>69;139;0</td><td>458B00</td></td><td bgcolor=#458B00><font color=#458B00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> green </td><td>0;255;0</td><td>00FF00</td></td><td bgcolor=#00FF00><font color=#00FF00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> green1 </td><td>0;255;0</td><td>00FF00</td></td><td bgcolor=#00FF00><font color=#00FF00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> green2 </td><td>0;238;0</td><td>00EE00</td></td><td bgcolor=#00EE00><font color=#00EE00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> green3 </td><td>0;205;0</td><td>00CD00</td></td><td bgcolor=#00CD00><font color=#00CD00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> green4 </td><td>0;139;0</td><td>008B00</td></td><td bgcolor=#008B00><font color=#008B00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> khaki </td><td>240;230;140</td><td>F0E68C</td></td><td bgcolor=#F0E68C><font color=#F0E68C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> khaki1 </td><td>255;246;143</td><td>FFF68F</td></td><td bgcolor=#FFF68F><font color=#FFF68F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> khaki2 </td><td>238;230;133</td><td>EEE685</td></td><td bgcolor=#EEE685><font color=#EEE685>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> khaki3 </td><td>205;198;115</td><td>CDC673</td></td><td bgcolor=#CDC673><font color=#CDC673>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> khaki4 </td><td>139;134;78</td><td>8B864E</td></td><td bgcolor=#8B864E><font color=#8B864E>### SAMPLE ###</font></td></tr>
 * </table>
 * <a href="#top" name=Orange>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of Orange</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> DarkOrange </td><td>255;140;0</td><td>FF8C00</td></td><td bgcolor=#FF8C00><font color=#FF8C00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrange1 </td><td>255;127;0</td><td>FF7F00</td></td><td bgcolor=#FF7F00><font color=#FF7F00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrange2 </td><td>238;118;0</td><td>EE7600</td></td><td bgcolor=#EE7600><font color=#EE7600>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrange3 </td><td>205;102;0</td><td>CD6600</td></td><td bgcolor=#CD6600><font color=#CD6600>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrange4 </td><td>139;69;0</td><td>8B4500</td></td><td bgcolor=#8B4500><font color=#8B4500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkSalmon </td><td>233;150;122</td><td>E9967A</td></td><td bgcolor=#E9967A><font color=#E9967A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightCoral </td><td>240;128;128</td><td>F08080</td></td><td bgcolor=#F08080><font color=#F08080>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSalmon </td><td>255;160;122</td><td>FFA07A</td></td><td bgcolor=#FFA07A><font color=#FFA07A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSalmon1 </td><td>255;160;122</td><td>FFA07A</td></td><td bgcolor=#FFA07A><font color=#FFA07A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSalmon2 </td><td>238;149;114</td><td>EE9572</td></td><td bgcolor=#EE9572><font color=#EE9572>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSalmon3 </td><td>205;129;98</td><td>CD8162</td></td><td bgcolor=#CD8162><font color=#CD8162>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightSalmon4 </td><td>139;87;66</td><td>8B5742</td></td><td bgcolor=#8B5742><font color=#8B5742>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PeachPuff </td><td>255;218;185</td><td>FFDAB9</td></td><td bgcolor=#FFDAB9><font color=#FFDAB9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PeachPuff1 </td><td>255;218;185</td><td>FFDAB9</td></td><td bgcolor=#FFDAB9><font color=#FFDAB9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PeachPuff2 </td><td>238;203;173</td><td>EECBAD</td></td><td bgcolor=#EECBAD><font color=#EECBAD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PeachPuff3 </td><td>205;175;149</td><td>CDAF95</td></td><td bgcolor=#CDAF95><font color=#CDAF95>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PeachPuff4 </td><td>139;119;101</td><td>8B7765</td></td><td bgcolor=#8B7765><font color=#8B7765>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> bisque </td><td>255;228;196</td><td>FFE4C4</td></td><td bgcolor=#FFE4C4><font color=#FFE4C4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> bisque1 </td><td>255;228;196</td><td>FFE4C4</td></td><td bgcolor=#FFE4C4><font color=#FFE4C4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> bisque2 </td><td>238;213;183</td><td>EED5B7</td></td><td bgcolor=#EED5B7><font color=#EED5B7>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> bisque3 </td><td>205;183;158</td><td>CDB79E</td></td><td bgcolor=#CDB79E><font color=#CDB79E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> bisque4 </td><td>139;125;107</td><td>8B7D6B</td></td><td bgcolor=#8B7D6B><font color=#8B7D6B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> coral </td><td>255;127;80</td><td>FF7F50</td></td><td bgcolor=#FF7F50><font color=#FF7F50>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> coral1 </td><td>255;114;86</td><td>FF7256</td></td><td bgcolor=#FF7256><font color=#FF7256>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> coral2 </td><td>238;106;80</td><td>EE6A50</td></td><td bgcolor=#EE6A50><font color=#EE6A50>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> coral3 </td><td>205;91;69</td><td>CD5B45</td></td><td bgcolor=#CD5B45><font color=#CD5B45>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> coral4 </td><td>139;62;47</td><td>8B3E2F</td></td><td bgcolor=#8B3E2F><font color=#8B3E2F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> honeydew </td><td>240;255;240</td><td>F0FFF0</td></td><td bgcolor=#F0FFF0><font color=#F0FFF0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> honeydew1 </td><td>240;255;240</td><td>F0FFF0</td></td><td bgcolor=#F0FFF0><font color=#F0FFF0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> honeydew2 </td><td>224;238;224</td><td>E0EEE0</td></td><td bgcolor=#E0EEE0><font color=#E0EEE0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> honeydew3 </td><td>193;205;193</td><td>C1CDC1</td></td><td bgcolor=#C1CDC1><font color=#C1CDC1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> honeydew4 </td><td>131;139;131</td><td>838B83</td></td><td bgcolor=#838B83><font color=#838B83>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orange </td><td>255;165;0</td><td>FFA500</td></td><td bgcolor=#FFA500><font color=#FFA500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orange1 </td><td>255;165;0</td><td>FFA500</td></td><td bgcolor=#FFA500><font color=#FFA500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orange2 </td><td>238;154;0</td><td>EE9A00</td></td><td bgcolor=#EE9A00><font color=#EE9A00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orange3 </td><td>205;133;0</td><td>CD8500</td></td><td bgcolor=#CD8500><font color=#CD8500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orange4 </td><td>139;90;0</td><td>8B5A00</td></td><td bgcolor=#8B5A00><font color=#8B5A00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> salmon </td><td>250;128;114</td><td>FA8072</td></td><td bgcolor=#FA8072><font color=#FA8072>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> salmon1 </td><td>255;140;105</td><td>FF8C69</td></td><td bgcolor=#FF8C69><font color=#FF8C69>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> salmon2 </td><td>238;130;98</td><td>EE8262</td></td><td bgcolor=#EE8262><font color=#EE8262>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> salmon3 </td><td>205;112;84</td><td>CD7054</td></td><td bgcolor=#CD7054><font color=#CD7054>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> salmon4 </td><td>139;76;57</td><td>8B4C39</td></td><td bgcolor=#8B4C39><font color=#8B4C39>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> sienna </td><td>160;82;45</td><td>A0522D</td></td><td bgcolor=#A0522D><font color=#A0522D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> sienna1 </td><td>255;130;71</td><td>FF8247</td></td><td bgcolor=#FF8247><font color=#FF8247>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> sienna2 </td><td>238;121;66</td><td>EE7942</td></td><td bgcolor=#EE7942><font color=#EE7942>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> sienna3 </td><td>205;104;57</td><td>CD6839</td></td><td bgcolor=#CD6839><font color=#CD6839>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> sienna4 </td><td>139;71;38</td><td>8B4726</td></td><td bgcolor=#8B4726><font color=#8B4726>### SAMPLE ###</font></td></tr>
 * </table>
 * <a href="#top" name=Red>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of Red</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> DeepPink </td><td>255;20;147</td><td>FF1493</td></td><td bgcolor=#FF1493><font color=#FF1493>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepPink1 </td><td>255;20;147</td><td>FF1493</td></td><td bgcolor=#FF1493><font color=#FF1493>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepPink2 </td><td>238;18;137</td><td>EE1289</td></td><td bgcolor=#EE1289><font color=#EE1289>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepPink3 </td><td>205;16;118</td><td>CD1076</td></td><td bgcolor=#CD1076><font color=#CD1076>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DeepPink4 </td><td>139;10;80</td><td>8B0A50</td></td><td bgcolor=#8B0A50><font color=#8B0A50>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> HotPink </td><td>255;105;180</td><td>FF69B4</td></td><td bgcolor=#FF69B4><font color=#FF69B4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> HotPink1 </td><td>255;110;180</td><td>FF6EB4</td></td><td bgcolor=#FF6EB4><font color=#FF6EB4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> HotPink2 </td><td>238;106;167</td><td>EE6AA7</td></td><td bgcolor=#EE6AA7><font color=#EE6AA7>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> HotPink3 </td><td>205;96;144</td><td>CD6090</td></td><td bgcolor=#CD6090><font color=#CD6090>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> HotPink4 </td><td>139;58;98</td><td>8B3A62</td></td><td bgcolor=#8B3A62><font color=#8B3A62>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> IndianRed </td><td>205;92;92</td><td>CD5C5C</td></td><td bgcolor=#CD5C5C><font color=#CD5C5C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> IndianRed1 </td><td>255;106;106</td><td>FF6A6A</td></td><td bgcolor=#FF6A6A><font color=#FF6A6A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> IndianRed2 </td><td>238;99;99</td><td>EE6363</td></td><td bgcolor=#EE6363><font color=#EE6363>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> IndianRed3 </td><td>205;85;85</td><td>CD5555</td></td><td bgcolor=#CD5555><font color=#CD5555>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> IndianRed4 </td><td>139;58;58</td><td>8B3A3A</td></td><td bgcolor=#8B3A3A><font color=#8B3A3A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightPink </td><td>255;182;193</td><td>FFB6C1</td></td><td bgcolor=#FFB6C1><font color=#FFB6C1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightPink1 </td><td>255;174;185</td><td>FFAEB9</td></td><td bgcolor=#FFAEB9><font color=#FFAEB9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightPink2 </td><td>238;162;173</td><td>EEA2AD</td></td><td bgcolor=#EEA2AD><font color=#EEA2AD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightPink3 </td><td>205;140;149</td><td>CD8C95</td></td><td bgcolor=#CD8C95><font color=#CD8C95>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightPink4 </td><td>139;95;101</td><td>8B5F65</td></td><td bgcolor=#8B5F65><font color=#8B5F65>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumVioletRed </td><td>199;21;133</td><td>C71585</td></td><td bgcolor=#C71585><font color=#C71585>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MistyRose </td><td>255;228;225</td><td>FFE4E1</td></td><td bgcolor=#FFE4E1><font color=#FFE4E1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MistyRose1 </td><td>255;228;225</td><td>FFE4E1</td></td><td bgcolor=#FFE4E1><font color=#FFE4E1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MistyRose2 </td><td>238;213;210</td><td>EED5D2</td></td><td bgcolor=#EED5D2><font color=#EED5D2>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MistyRose3 </td><td>205;183;181</td><td>CDB7B5</td></td><td bgcolor=#CDB7B5><font color=#CDB7B5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MistyRose4 </td><td>139;125;123</td><td>8B7D7B</td></td><td bgcolor=#8B7D7B><font color=#8B7D7B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OrangeRed </td><td>255;69;0</td><td>FF4500</td></td><td bgcolor=#FF4500><font color=#FF4500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OrangeRed1 </td><td>255;69;0</td><td>FF4500</td></td><td bgcolor=#FF4500><font color=#FF4500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OrangeRed2 </td><td>238;64;0</td><td>EE4000</td></td><td bgcolor=#EE4000><font color=#EE4000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OrangeRed3 </td><td>205;55;0</td><td>CD3700</td></td><td bgcolor=#CD3700><font color=#CD3700>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OrangeRed4 </td><td>139;37;0</td><td>8B2500</td></td><td bgcolor=#8B2500><font color=#8B2500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleVioletRed </td><td>219;112;147</td><td>DB7093</td></td><td bgcolor=#DB7093><font color=#DB7093>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleVioletRed1 </td><td>255;130;171</td><td>FF82AB</td></td><td bgcolor=#FF82AB><font color=#FF82AB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleVioletRed2 </td><td>238;121;159</td><td>EE799F</td></td><td bgcolor=#EE799F><font color=#EE799F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleVioletRed3 </td><td>205;104;137</td><td>CD6889</td></td><td bgcolor=#CD6889><font color=#CD6889>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleVioletRed4 </td><td>139;71;93</td><td>8B475D</td></td><td bgcolor=#8B475D><font color=#8B475D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> VioletRed </td><td>208;32;144</td><td>D02090</td></td><td bgcolor=#D02090><font color=#D02090>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> VioletRed1 </td><td>255;62;150</td><td>FF3E96</td></td><td bgcolor=#FF3E96><font color=#FF3E96>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> VioletRed2 </td><td>238;58;140</td><td>EE3A8C</td></td><td bgcolor=#EE3A8C><font color=#EE3A8C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> VioletRed3 </td><td>205;50;120</td><td>CD3278</td></td><td bgcolor=#CD3278><font color=#CD3278>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> VioletRed4 </td><td>139;34;82</td><td>8B2252</td></td><td bgcolor=#8B2252><font color=#8B2252>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> firebrick </td><td>178;34;34</td><td>B22222</td></td><td bgcolor=#B22222><font color=#B22222>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> firebrick1 </td><td>255;48;48</td><td>FF3030</td></td><td bgcolor=#FF3030><font color=#FF3030>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> firebrick2 </td><td>238;44;44</td><td>EE2C2C</td></td><td bgcolor=#EE2C2C><font color=#EE2C2C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> firebrick3 </td><td>205;38;38</td><td>CD2626</td></td><td bgcolor=#CD2626><font color=#CD2626>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> firebrick4 </td><td>139;26;26</td><td>8B1A1A</td></td><td bgcolor=#8B1A1A><font color=#8B1A1A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> pink </td><td>255;192;203</td><td>FFC0CB</td></td><td bgcolor=#FFC0CB><font color=#FFC0CB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> pink1 </td><td>255;181;197</td><td>FFB5C5</td></td><td bgcolor=#FFB5C5><font color=#FFB5C5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> pink2 </td><td>238;169;184</td><td>EEA9B8</td></td><td bgcolor=#EEA9B8><font color=#EEA9B8>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> pink3 </td><td>205;145;158</td><td>CD919E</td></td><td bgcolor=#CD919E><font color=#CD919E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> pink4 </td><td>139;99;108</td><td>8B636C</td></td><td bgcolor=#8B636C><font color=#8B636C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> red </td><td>255;0;0</td><td>FF0000</td></td><td bgcolor=#FF0000><font color=#FF0000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> red1 </td><td>255;0;0</td><td>FF0000</td></td><td bgcolor=#FF0000><font color=#FF0000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> red2 </td><td>238;0;0</td><td>EE0000</td></td><td bgcolor=#EE0000><font color=#EE0000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> red3 </td><td>205;0;0</td><td>CD0000</td></td><td bgcolor=#CD0000><font color=#CD0000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> red4 </td><td>139;0;0</td><td>8B0000</td></td><td bgcolor=#8B0000><font color=#8B0000>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tomato </td><td>255;99;71</td><td>FF6347</td></td><td bgcolor=#FF6347><font color=#FF6347>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tomato1 </td><td>255;99;71</td><td>FF6347</td></td><td bgcolor=#FF6347><font color=#FF6347>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tomato2 </td><td>238;92;66</td><td>EE5C42</td></td><td bgcolor=#EE5C42><font color=#EE5C42>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tomato3 </td><td>205;79;57</td><td>CD4F39</td></td><td bgcolor=#CD4F39><font color=#CD4F39>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> tomato4 </td><td>139;54;38</td><td>8B3626</td></td><td bgcolor=#8B3626><font color=#8B3626>### SAMPLE ###</font></td></tr>
 * </table>
 * <a href="#top" name=Violet>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of Violet</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> DarkOrchid </td><td>153;50;204</td><td>9932CC</td></td><td bgcolor=#9932CC><font color=#9932CC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrchid1 </td><td>191;62;255</td><td>BF3EFF</td></td><td bgcolor=#BF3EFF><font color=#BF3EFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrchid2 </td><td>178;58;238</td><td>B23AEE</td></td><td bgcolor=#B23AEE><font color=#B23AEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrchid3 </td><td>154;50;205</td><td>9A32CD</td></td><td bgcolor=#9A32CD><font color=#9A32CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkOrchid4 </td><td>104;34;139</td><td>68228B</td></td><td bgcolor=#68228B><font color=#68228B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkViolet </td><td>148;0;211</td><td>9400D3</td></td><td bgcolor=#9400D3><font color=#9400D3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LavenderBlush </td><td>255;240;245</td><td>FFF0F5</td></td><td bgcolor=#FFF0F5><font color=#FFF0F5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LavenderBlush1 </td><td>255;240;245</td><td>FFF0F5</td></td><td bgcolor=#FFF0F5><font color=#FFF0F5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LavenderBlush2 </td><td>238;224;229</td><td>EEE0E5</td></td><td bgcolor=#EEE0E5><font color=#EEE0E5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LavenderBlush3 </td><td>205;193;197</td><td>CDC1C5</td></td><td bgcolor=#CDC1C5><font color=#CDC1C5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LavenderBlush4 </td><td>139;131;134</td><td>8B8386</td></td><td bgcolor=#8B8386><font color=#8B8386>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumOrchid </td><td>186;85;211</td><td>BA55D3</td></td><td bgcolor=#BA55D3><font color=#BA55D3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumOrchid1 </td><td>224;102;255</td><td>E066FF</td></td><td bgcolor=#E066FF><font color=#E066FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumOrchid2 </td><td>209;95;238</td><td>D15FEE</td></td><td bgcolor=#D15FEE><font color=#D15FEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumOrchid3 </td><td>180;82;205</td><td>B452CD</td></td><td bgcolor=#B452CD><font color=#B452CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumOrchid4 </td><td>122;55;139</td><td>7A378B</td></td><td bgcolor=#7A378B><font color=#7A378B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumPurple </td><td>147;112;219</td><td>9370DB</td></td><td bgcolor=#9370DB><font color=#9370DB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumPurple1 </td><td>171;130;255</td><td>AB82FF</td></td><td bgcolor=#AB82FF><font color=#AB82FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumPurple2 </td><td>159;121;238</td><td>9F79EE</td></td><td bgcolor=#9F79EE><font color=#9F79EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumPurple3 </td><td>137;104;205</td><td>8968CD</td></td><td bgcolor=#8968CD><font color=#8968CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> MediumPurple4 </td><td>93;71;139</td><td>5D478B</td></td><td bgcolor=#5D478B><font color=#5D478B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> lavender </td><td>230;230;250</td><td>E6E6FA</td></td><td bgcolor=#E6E6FA><font color=#E6E6FA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> magenta </td><td>255;0;255</td><td>FF00FF</td></td><td bgcolor=#FF00FF><font color=#FF00FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> magenta1 </td><td>255;0;255</td><td>FF00FF</td></td><td bgcolor=#FF00FF><font color=#FF00FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> magenta2 </td><td>238;0;238</td><td>EE00EE</td></td><td bgcolor=#EE00EE><font color=#EE00EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> magenta3 </td><td>205;0;205</td><td>CD00CD</td></td><td bgcolor=#CD00CD><font color=#CD00CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> magenta4 </td><td>139;0;139</td><td>8B008B</td></td><td bgcolor=#8B008B><font color=#8B008B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> maroon </td><td>176;48;96</td><td>B03060</td></td><td bgcolor=#B03060><font color=#B03060>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> maroon1 </td><td>255;52;179</td><td>FF34B3</td></td><td bgcolor=#FF34B3><font color=#FF34B3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> maroon2 </td><td>238;48;167</td><td>EE30A7</td></td><td bgcolor=#EE30A7><font color=#EE30A7>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> maroon3 </td><td>205;41;144</td><td>CD2990</td></td><td bgcolor=#CD2990><font color=#CD2990>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> maroon4 </td><td>139;28;98</td><td>8B1C62</td></td><td bgcolor=#8B1C62><font color=#8B1C62>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orchid </td><td>218;112;214</td><td>DA70D6</td></td><td bgcolor=#DA70D6><font color=#DA70D6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orchid1 </td><td>255;131;250</td><td>FF83FA</td></td><td bgcolor=#FF83FA><font color=#FF83FA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orchid2 </td><td>238;122;233</td><td>EE7AE9</td></td><td bgcolor=#EE7AE9><font color=#EE7AE9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orchid3 </td><td>205;105;201</td><td>CD69C9</td></td><td bgcolor=#CD69C9><font color=#CD69C9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> orchid4 </td><td>139;71;137</td><td>8B4789</td></td><td bgcolor=#8B4789><font color=#8B4789>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> plum </td><td>221;160;221</td><td>DDA0DD</td></td><td bgcolor=#DDA0DD><font color=#DDA0DD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> plum1 </td><td>255;187;255</td><td>FFBBFF</td></td><td bgcolor=#FFBBFF><font color=#FFBBFF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> plum2 </td><td>238;174;238</td><td>EEAEEE</td></td><td bgcolor=#EEAEEE><font color=#EEAEEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> plum3 </td><td>205;150;205</td><td>CD96CD</td></td><td bgcolor=#CD96CD><font color=#CD96CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> plum4 </td><td>139;102;139</td><td>8B668B</td></td><td bgcolor=#8B668B><font color=#8B668B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> purple </td><td>160;32;240</td><td>A020F0</td></td><td bgcolor=#A020F0><font color=#A020F0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> purple1 </td><td>155;48;255</td><td>9B30FF</td></td><td bgcolor=#9B30FF><font color=#9B30FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> purple2 </td><td>145;44;238</td><td>912CEE</td></td><td bgcolor=#912CEE><font color=#912CEE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> purple3 </td><td>125;38;205</td><td>7D26CD</td></td><td bgcolor=#7D26CD><font color=#7D26CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> purple4 </td><td>85;26;139</td><td>551A8B</td></td><td bgcolor=#551A8B><font color=#551A8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> thistle </td><td>216;191;216</td><td>D8BFD8</td></td><td bgcolor=#D8BFD8><font color=#D8BFD8>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> thistle1 </td><td>255;225;255</td><td>FFE1FF</td></td><td bgcolor=#FFE1FF><font color=#FFE1FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> thistle2 </td><td>238;210;238</td><td>EED2EE</td></td><td bgcolor=#EED2EE><font color=#EED2EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> thistle3 </td><td>205;181;205</td><td>CDB5CD</td></td><td bgcolor=#CDB5CD><font color=#CDB5CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> thistle4 </td><td>139;123;139</td><td>8B7B8B</td></td><td bgcolor=#8B7B8B><font color=#8B7B8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> violet </td><td>238;130;238</td><td>EE82EE</td></td><td bgcolor=#EE82EE><font color=#EE82EE>### SAMPLE ###</font></td></tr>
 * </table>
 * <a href="#top" name=White>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of White</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> AntiqueWhite </td><td>250;235;215</td><td>FAEBD7</td></td><td bgcolor=#FAEBD7><font color=#FAEBD7>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> AntiqueWhite1 </td><td>255;239;219</td><td>FFEFDB</td></td><td bgcolor=#FFEFDB><font color=#FFEFDB>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> AntiqueWhite2 </td><td>238;223;204</td><td>EEDFCC</td></td><td bgcolor=#EEDFCC><font color=#EEDFCC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> AntiqueWhite3 </td><td>205;192;176</td><td>CDC0B0</td></td><td bgcolor=#CDC0B0><font color=#CDC0B0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> AntiqueWhite4 </td><td>139;131;120</td><td>8B8378</td></td><td bgcolor=#8B8378><font color=#8B8378>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> FloralWhite </td><td>255;250;240</td><td>FFFAF0</td></td><td bgcolor=#FFFAF0><font color=#FFFAF0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> GhostWhite </td><td>248;248;255</td><td>F8F8FF</td></td><td bgcolor=#F8F8FF><font color=#F8F8FF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> NavajoWhite </td><td>255;222;173</td><td>FFDEAD</td></td><td bgcolor=#FFDEAD><font color=#FFDEAD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> NavajoWhite1 </td><td>255;222;173</td><td>FFDEAD</td></td><td bgcolor=#FFDEAD><font color=#FFDEAD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> NavajoWhite2 </td><td>238;207;161</td><td>EECFA1</td></td><td bgcolor=#EECFA1><font color=#EECFA1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> NavajoWhite3 </td><td>205;179;139</td><td>CDB38B</td></td><td bgcolor=#CDB38B><font color=#CDB38B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> NavajoWhite4 </td><td>139;121;94</td><td>8B795E</td></td><td bgcolor=#8B795E><font color=#8B795E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> OldLace </td><td>253;245;230</td><td>FDF5E6</td></td><td bgcolor=#FDF5E6><font color=#FDF5E6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> WhiteSmoke </td><td>245;245;245</td><td>F5F5F5</td></td><td bgcolor=#F5F5F5><font color=#F5F5F5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> gainsboro </td><td>220;220;220</td><td>DCDCDC</td></td><td bgcolor=#DCDCDC><font color=#DCDCDC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> ivory </td><td>255;255;240</td><td>FFFFF0</td></td><td bgcolor=#FFFFF0><font color=#FFFFF0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> ivory1 </td><td>255;255;240</td><td>FFFFF0</td></td><td bgcolor=#FFFFF0><font color=#FFFFF0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> ivory2 </td><td>238;238;224</td><td>EEEEE0</td></td><td bgcolor=#EEEEE0><font color=#EEEEE0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> ivory3 </td><td>205;205;193</td><td>CDCDC1</td></td><td bgcolor=#CDCDC1><font color=#CDCDC1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> ivory4 </td><td>139;139;131</td><td>8B8B83</td></td><td bgcolor=#8B8B83><font color=#8B8B83>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> linen </td><td>250;240;230</td><td>FAF0E6</td></td><td bgcolor=#FAF0E6><font color=#FAF0E6>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> seashell </td><td>255;245;238</td><td>FFF5EE</td></td><td bgcolor=#FFF5EE><font color=#FFF5EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> seashell1 </td><td>255;245;238</td><td>FFF5EE</td></td><td bgcolor=#FFF5EE><font color=#FFF5EE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> seashell2 </td><td>238;229;222</td><td>EEE5DE</td></td><td bgcolor=#EEE5DE><font color=#EEE5DE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> seashell3 </td><td>205;197;191</td><td>CDC5BF</td></td><td bgcolor=#CDC5BF><font color=#CDC5BF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> seashell4 </td><td>139;134;130</td><td>8B8682</td></td><td bgcolor=#8B8682><font color=#8B8682>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> snow </td><td>255;250;250</td><td>FFFAFA</td></td><td bgcolor=#FFFAFA><font color=#FFFAFA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> snow1 </td><td>255;250;250</td><td>FFFAFA</td></td><td bgcolor=#FFFAFA><font color=#FFFAFA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> snow2 </td><td>238;233;233</td><td>EEE9E9</td></td><td bgcolor=#EEE9E9><font color=#EEE9E9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> snow3 </td><td>205;201;201</td><td>CDC9C9</td></td><td bgcolor=#CDC9C9><font color=#CDC9C9>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> snow4 </td><td>139;137;137</td><td>8B8989</td></td><td bgcolor=#8B8989><font color=#8B8989>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> wheat </td><td>245;222;179</td><td>F5DEB3</td></td><td bgcolor=#F5DEB3><font color=#F5DEB3>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> wheat1 </td><td>255;231;186</td><td>FFE7BA</td></td><td bgcolor=#FFE7BA><font color=#FFE7BA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> wheat2 </td><td>238;216;174</td><td>EED8AE</td></td><td bgcolor=#EED8AE><font color=#EED8AE>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> wheat3 </td><td>205;186;150</td><td>CDBA96</td></td><td bgcolor=#CDBA96><font color=#CDBA96>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> wheat4 </td><td>139;126;102</td><td>8B7E66</td></td><td bgcolor=#8B7E66><font color=#8B7E66>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> white </td><td>255;255;255</td><td>FFFFFF</td></td><td bgcolor=#FFFFFF><font color=#FFFFFF>### SAMPLE ###</font></td></tr>
 * </table>
 * <a href="#top" name=Yellow>[Click for top]</a>
 * <table border rows=4 cellpadding=3 width="100%" <tr><th colspan=4>Shades of Yellow</th></tr>
 * <tr><th width="30%">Color Name</th><th width="15%">R/G/B</th><th width="14%">Hex</th><th>BG/FG color sample</th></tr>
 * <tr align=center><td> BlanchedAlmond </td><td>255;235;205</td><td>FFEBCD</td></td><td bgcolor=#FFEBCD><font color=#FFEBCD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkGoldenrod </td><td>184;134;11</td><td>B8860B</td></td><td bgcolor=#B8860B><font color=#B8860B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkGoldenrod1 </td><td>255;185;15</td><td>FFB90F</td></td><td bgcolor=#FFB90F><font color=#FFB90F>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkGoldenrod2 </td><td>238;173;14</td><td>EEAD0E</td></td><td bgcolor=#EEAD0E><font color=#EEAD0E>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkGoldenrod3 </td><td>205;149;12</td><td>CD950C</td></td><td bgcolor=#CD950C><font color=#CD950C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> DarkGoldenrod4 </td><td>139;101;8</td><td>8B6508</td></td><td bgcolor=#8B6508><font color=#8B6508>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LemonChiffon </td><td>255;250;205</td><td>FFFACD</td></td><td bgcolor=#FFFACD><font color=#FFFACD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LemonChiffon1 </td><td>255;250;205</td><td>FFFACD</td></td><td bgcolor=#FFFACD><font color=#FFFACD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LemonChiffon2 </td><td>238;233;191</td><td>EEE9BF</td></td><td bgcolor=#EEE9BF><font color=#EEE9BF>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LemonChiffon3 </td><td>205;201;165</td><td>CDC9A5</td></td><td bgcolor=#CDC9A5><font color=#CDC9A5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LemonChiffon4 </td><td>139;137;112</td><td>8B8970</td></td><td bgcolor=#8B8970><font color=#8B8970>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightGoldenrod </td><td>238;221;130</td><td>EEDD82</td></td><td bgcolor=#EEDD82><font color=#EEDD82>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightGoldenrod1 </td><td>255;236;139</td><td>FFEC8B</td></td><td bgcolor=#FFEC8B><font color=#FFEC8B>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightGoldenrod2 </td><td>238;220;130</td><td>EEDC82</td></td><td bgcolor=#EEDC82><font color=#EEDC82>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightGoldenrod3 </td><td>205;190;112</td><td>CDBE70</td></td><td bgcolor=#CDBE70><font color=#CDBE70>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightGoldenrod4 </td><td>139;129;76</td><td>8B814C</td></td><td bgcolor=#8B814C><font color=#8B814C>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightGoldenrodYellow </td><td>250;250;210</td><td>FAFAD2</td></td><td bgcolor=#FAFAD2><font color=#FAFAD2>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightYellow </td><td>255;255;224</td><td>FFFFE0</td></td><td bgcolor=#FFFFE0><font color=#FFFFE0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightYellow1 </td><td>255;255;224</td><td>FFFFE0</td></td><td bgcolor=#FFFFE0><font color=#FFFFE0>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightYellow2 </td><td>238;238;209</td><td>EEEED1</td></td><td bgcolor=#EEEED1><font color=#EEEED1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightYellow3 </td><td>205;205;180</td><td>CDCDB4</td></td><td bgcolor=#CDCDB4><font color=#CDCDB4>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> LightYellow4 </td><td>139;139;122</td><td>8B8B7A</td></td><td bgcolor=#8B8B7A><font color=#8B8B7A>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PaleGoldenrod </td><td>238;232;170</td><td>EEE8AA</td></td><td bgcolor=#EEE8AA><font color=#EEE8AA>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> PapayaWhip </td><td>255;239;213</td><td>FFEFD5</td></td><td bgcolor=#FFEFD5><font color=#FFEFD5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cornsilk </td><td>255;248;220</td><td>FFF8DC</td></td><td bgcolor=#FFF8DC><font color=#FFF8DC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cornsilk1 </td><td>255;248;220</td><td>FFF8DC</td></td><td bgcolor=#FFF8DC><font color=#FFF8DC>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cornsilk2 </td><td>238;232;205</td><td>EEE8CD</td></td><td bgcolor=#EEE8CD><font color=#EEE8CD>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cornsilk3 </td><td>205;200;177</td><td>CDC8B1</td></td><td bgcolor=#CDC8B1><font color=#CDC8B1>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> cornsilk4 </td><td>139;136;120</td><td>8B8878</td></td><td bgcolor=#8B8878><font color=#8B8878>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> gold </td><td>255;215;0</td><td>FFD700</td></td><td bgcolor=#FFD700><font color=#FFD700>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> gold1 </td><td>255;215;0</td><td>FFD700</td></td><td bgcolor=#FFD700><font color=#FFD700>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> gold2 </td><td>238;201;0</td><td>EEC900</td></td><td bgcolor=#EEC900><font color=#EEC900>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> gold3 </td><td>205;173;0</td><td>CDAD00</td></td><td bgcolor=#CDAD00><font color=#CDAD00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> gold4 </td><td>139;117;0</td><td>8B7500</td></td><td bgcolor=#8B7500><font color=#8B7500>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> goldenrod </td><td>218;165;32</td><td>DAA520</td></td><td bgcolor=#DAA520><font color=#DAA520>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> goldenrod1 </td><td>255;193;37</td><td>FFC125</td></td><td bgcolor=#FFC125><font color=#FFC125>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> goldenrod2 </td><td>238;180;34</td><td>EEB422</td></td><td bgcolor=#EEB422><font color=#EEB422>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> goldenrod3 </td><td>205;155;29</td><td>CD9B1D</td></td><td bgcolor=#CD9B1D><font color=#CD9B1D>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> goldenrod4 </td><td>139;105;20</td><td>8B6914</td></td><td bgcolor=#8B6914><font color=#8B6914>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> moccasin </td><td>255;228;181</td><td>FFE4B5</td></td><td bgcolor=#FFE4B5><font color=#FFE4B5>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> yellow </td><td>255;255;0</td><td>FFFF00</td></td><td bgcolor=#FFFF00><font color=#FFFF00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> yellow1 </td><td>255;255;0</td><td>FFFF00</td></td><td bgcolor=#FFFF00><font color=#FFFF00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> yellow2 </td><td>238;238;0</td><td>EEEE00</td></td><td bgcolor=#EEEE00><font color=#EEEE00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> yellow3 </td><td>205;205;0</td><td>CDCD00</td></td><td bgcolor=#CDCD00><font color=#CDCD00>### SAMPLE ###</font></td></tr>
 * <tr align=center><td> yellow4 </td><td>139;139;0</td><td>8B8B00</td></td><td bgcolor=#8B8B00><font color=#8B8B00>### SAMPLE ###</font></td></tr>
 * </table>
 * <p>
 * Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *  </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 ******************************************************************************/
public class Col {

    public final static Color black = new java.awt.Color(0, 0, 0); 
    public final static Color grey = new java.awt.Color(190, 190, 190); 
    public final static Color DimGrey = new java.awt.Color(105, 105, 105); 
    public final static Color LightGray = new java.awt.Color(211, 211, 211); 
    public final static Color LightSlateGrey = new java.awt.Color(119, 136, 153); 
    public final static Color SlateGray = new java.awt.Color(112, 128, 144); 
    public final static Color SlateGray1 = new java.awt.Color(198, 226, 255); 
    public final static Color SlateGray2 = new java.awt.Color(185, 211, 238); 
    public final static Color SlateGray3 = new java.awt.Color(159, 182, 205); 
    public final static Color SlateGray4 = new java.awt.Color(108, 123, 139); 
    public final static Color SlateGrey = new java.awt.Color(112, 128, 144); 
    public final static Color grey0 = new java.awt.Color(0, 0, 0); 
    public final static Color grey1 = new java.awt.Color(3, 3, 3); 
    public final static Color grey2 = new java.awt.Color(5, 5, 5); 
    public final static Color grey3 = new java.awt.Color(8, 8, 8); 
    public final static Color grey4 = new java.awt.Color(10, 10, 10); 
    public final static Color grey5 = new java.awt.Color(13, 13, 13); 
    public final static Color grey6 = new java.awt.Color(15, 15, 15); 
    public final static Color grey7 = new java.awt.Color(18, 18, 18); 
    public final static Color grey8 = new java.awt.Color(20, 20, 20); 
    public final static Color grey9 = new java.awt.Color(23, 23, 23); 
    public final static Color grey10 = new java.awt.Color(26, 26, 26); 
    public final static Color grey11 = new java.awt.Color(28, 28, 28); 
    public final static Color grey12 = new java.awt.Color(31, 31, 31); 
    public final static Color grey13 = new java.awt.Color(33, 33, 33); 
    public final static Color grey14 = new java.awt.Color(36, 36, 36); 
    public final static Color grey15 = new java.awt.Color(38, 38, 38); 
    public final static Color grey16 = new java.awt.Color(41, 41, 41); 
    public final static Color grey17 = new java.awt.Color(43, 43, 43); 
    public final static Color grey18 = new java.awt.Color(46, 46, 46); 
    public final static Color grey19 = new java.awt.Color(48, 48, 48); 
    public final static Color grey20 = new java.awt.Color(51, 51, 51); 
    public final static Color grey21 = new java.awt.Color(54, 54, 54); 
    public final static Color grey22 = new java.awt.Color(56, 56, 56); 
    public final static Color grey23 = new java.awt.Color(59, 59, 59); 
    public final static Color grey24 = new java.awt.Color(61, 61, 61); 
    public final static Color grey25 = new java.awt.Color(64, 64, 64); 
    public final static Color grey26 = new java.awt.Color(66, 66, 66); 
    public final static Color grey27 = new java.awt.Color(69, 69, 69); 
    public final static Color grey28 = new java.awt.Color(71, 71, 71); 
    public final static Color grey29 = new java.awt.Color(74, 74, 74); 
    public final static Color grey30 = new java.awt.Color(77, 77, 77); 
    public final static Color grey31 = new java.awt.Color(79, 79, 79); 
    public final static Color grey32 = new java.awt.Color(82, 82, 82); 
    public final static Color grey33 = new java.awt.Color(84, 84, 84); 
    public final static Color grey34 = new java.awt.Color(87, 87, 87); 
    public final static Color grey35 = new java.awt.Color(89, 89, 89); 
    public final static Color grey36 = new java.awt.Color(92, 92, 92); 
    public final static Color grey37 = new java.awt.Color(94, 94, 94); 
    public final static Color grey38 = new java.awt.Color(97, 97, 97); 
    public final static Color grey39 = new java.awt.Color(99, 99, 99); 
    public final static Color grey40 = new java.awt.Color(102, 102, 102); 
    public final static Color grey41 = new java.awt.Color(105, 105, 105); 
    public final static Color grey42 = new java.awt.Color(107, 107, 107); 
    public final static Color grey43 = new java.awt.Color(110, 110, 110); 
    public final static Color grey44 = new java.awt.Color(112, 112, 112); 
    public final static Color grey45 = new java.awt.Color(115, 115, 115); 
    public final static Color grey46 = new java.awt.Color(117, 117, 117); 
    public final static Color grey47 = new java.awt.Color(120, 120, 120); 
    public final static Color grey48 = new java.awt.Color(122, 122, 122); 
    public final static Color grey49 = new java.awt.Color(125, 125, 125); 
    public final static Color grey50 = new java.awt.Color(127, 127, 127); 
    public final static Color grey51 = new java.awt.Color(130, 130, 130); 
    public final static Color grey52 = new java.awt.Color(133, 133, 133); 
    public final static Color grey53 = new java.awt.Color(135, 135, 135); 
    public final static Color grey54 = new java.awt.Color(138, 138, 138); 
    public final static Color grey55 = new java.awt.Color(140, 140, 140); 
    public final static Color grey56 = new java.awt.Color(143, 143, 143); 
    public final static Color grey57 = new java.awt.Color(145, 145, 145); 
    public final static Color grey58 = new java.awt.Color(148, 148, 148); 
    public final static Color grey59 = new java.awt.Color(150, 150, 150); 
    public final static Color grey60 = new java.awt.Color(153, 153, 153); 
    public final static Color grey61 = new java.awt.Color(156, 156, 156); 
    public final static Color grey62 = new java.awt.Color(158, 158, 158); 
    public final static Color grey63 = new java.awt.Color(161, 161, 161); 
    public final static Color grey64 = new java.awt.Color(163, 163, 163); 
    public final static Color grey65 = new java.awt.Color(166, 166, 166); 
    public final static Color grey66 = new java.awt.Color(168, 168, 168); 
    public final static Color grey67 = new java.awt.Color(171, 171, 171); 
    public final static Color grey68 = new java.awt.Color(173, 173, 173); 
    public final static Color grey69 = new java.awt.Color(176, 176, 176); 
    public final static Color grey70 = new java.awt.Color(179, 179, 179); 
    public final static Color grey71 = new java.awt.Color(181, 181, 181); 
    public final static Color grey72 = new java.awt.Color(184, 184, 184); 
    public final static Color grey73 = new java.awt.Color(186, 186, 186); 
    public final static Color grey74 = new java.awt.Color(189, 189, 189); 
    public final static Color grey75 = new java.awt.Color(191, 191, 191); 
    public final static Color grey76 = new java.awt.Color(194, 194, 194); 
    public final static Color grey77 = new java.awt.Color(196, 196, 196); 
    public final static Color grey78 = new java.awt.Color(199, 199, 199); 
    public final static Color grey79 = new java.awt.Color(201, 201, 201); 
    public final static Color grey80 = new java.awt.Color(204, 204, 204); 
    public final static Color grey81 = new java.awt.Color(207, 207, 207); 
    public final static Color grey82 = new java.awt.Color(209, 209, 209); 
    public final static Color grey83 = new java.awt.Color(212, 212, 212); 
    public final static Color grey84 = new java.awt.Color(214, 214, 214); 
    public final static Color grey85 = new java.awt.Color(217, 217, 217); 
    public final static Color grey86 = new java.awt.Color(219, 219, 219); 
    public final static Color grey87 = new java.awt.Color(222, 222, 222); 
    public final static Color grey88 = new java.awt.Color(224, 224, 224); 
    public final static Color grey89 = new java.awt.Color(227, 227, 227); 
    public final static Color grey90 = new java.awt.Color(229, 229, 229); 
    public final static Color grey91 = new java.awt.Color(232, 232, 232); 
    public final static Color grey92 = new java.awt.Color(235, 235, 235); 
    public final static Color grey93 = new java.awt.Color(237, 237, 237); 
    public final static Color grey94 = new java.awt.Color(240, 240, 240); 
    public final static Color grey95 = new java.awt.Color(242, 242, 242); 
    public final static Color grey96 = new java.awt.Color(245, 245, 245); 
    public final static Color grey97 = new java.awt.Color(247, 247, 247); 
    public final static Color grey98 = new java.awt.Color(250, 250, 250); 
    public final static Color grey99 = new java.awt.Color(252, 252, 252); 
    public final static Color grey100 = new java.awt.Color(255, 255, 255); 
    public final static Color AliceBlue = new java.awt.Color(240, 248, 255); 
    public final static Color BlueViolet = new java.awt.Color(138, 43, 226); 
    public final static Color CadetBlue = new java.awt.Color(95, 158, 160); 
    public final static Color CadetBlue1 = new java.awt.Color(152, 245, 255); 
    public final static Color CadetBlue2 = new java.awt.Color(142, 229, 238); 
    public final static Color CadetBlue3 = new java.awt.Color(122, 197, 205); 
    public final static Color CadetBlue4 = new java.awt.Color(83, 134, 139); 
    public final static Color CornflowerBlue = new java.awt.Color(100, 149, 237); 
    public final static Color DarkSlateBlue = new java.awt.Color(72, 61, 139); 
    public final static Color DarkTurquoise = new java.awt.Color(0, 206, 209); 
    public final static Color DeepSkyBlue = new java.awt.Color(0, 191, 255); 
    public final static Color DeepSkyBlue1 = new java.awt.Color(0, 191, 255); 
    public final static Color DeepSkyBlue2 = new java.awt.Color(0, 178, 238); 
    public final static Color DeepSkyBlue3 = new java.awt.Color(0, 154, 205); 
    public final static Color DeepSkyBlue4 = new java.awt.Color(0, 104, 139); 
    public final static Color DodgerBlue = new java.awt.Color(30, 144, 255); 
    public final static Color DodgerBlue1 = new java.awt.Color(30, 144, 255); 
    public final static Color DodgerBlue2 = new java.awt.Color(28, 134, 238); 
    public final static Color DodgerBlue3 = new java.awt.Color(24, 116, 205); 
    public final static Color DodgerBlue4 = new java.awt.Color(16, 78, 139); 
    public final static Color LightBlue = new java.awt.Color(173, 216, 230); 
    public final static Color LightBlue1 = new java.awt.Color(191, 239, 255); 
    public final static Color LightBlue2 = new java.awt.Color(178, 223, 238); 
    public final static Color LightBlue3 = new java.awt.Color(154, 192, 205); 
    public final static Color LightBlue4 = new java.awt.Color(104, 131, 139); 
    public final static Color LightCyan = new java.awt.Color(224, 255, 255); 
    public final static Color LightCyan1 = new java.awt.Color(224, 255, 255); 
    public final static Color LightCyan2 = new java.awt.Color(209, 238, 238); 
    public final static Color LightCyan3 = new java.awt.Color(180, 205, 205); 
    public final static Color LightCyan4 = new java.awt.Color(122, 139, 139); 
    public final static Color LightSkyBlue = new java.awt.Color(135, 206, 250); 
    public final static Color LightSkyBlue1 = new java.awt.Color(176, 226, 255); 
    public final static Color LightSkyBlue2 = new java.awt.Color(164, 211, 238); 
    public final static Color LightSkyBlue3 = new java.awt.Color(141, 182, 205); 
    public final static Color LightSkyBlue4 = new java.awt.Color(96, 123, 139); 
    public final static Color LightSlateBlue = new java.awt.Color(132, 112, 255); 
    public final static Color LightSteelBlue = new java.awt.Color(176, 196, 222); 
    public final static Color LightSteelBlue1 = new java.awt.Color(202, 225, 255); 
    public final static Color LightSteelBlue2 = new java.awt.Color(188, 210, 238); 
    public final static Color LightSteelBlue3 = new java.awt.Color(162, 181, 205); 
    public final static Color LightSteelBlue4 = new java.awt.Color(110, 123, 139); 
    public final static Color MediumAquamarine = new java.awt.Color(102, 205,
            170); 
    public final static Color MediumBlue = new java.awt.Color(0, 0, 205); 
    public final static Color MediumSlateBlue = new java.awt.Color(123, 104, 238); 
    public final static Color MediumTurquoise = new java.awt.Color(72, 209, 204); 
    public final static Color MidnightBlue = new java.awt.Color(25, 25, 112); 
    public final static Color NavyBlue = new java.awt.Color(0, 0, 128); 
    public final static Color PaleTurquoise = new java.awt.Color(175, 238, 238); 
    public final static Color PaleTurquoise1 = new java.awt.Color(187, 255, 255); 
    public final static Color PaleTurquoise2 = new java.awt.Color(174, 238, 238); 
    public final static Color PaleTurquoise3 = new java.awt.Color(150, 205, 205); 
    public final static Color PaleTurquoise4 = new java.awt.Color(102, 139, 139); 
    public final static Color PowderBlue = new java.awt.Color(176, 224, 230); 
    public final static Color RoyalBlue = new java.awt.Color(65, 105, 225); 
    public final static Color RoyalBlue1 = new java.awt.Color(72, 118, 255); 
    public final static Color RoyalBlue2 = new java.awt.Color(67, 110, 238); 
    public final static Color RoyalBlue3 = new java.awt.Color(58, 95, 205); 
    public final static Color RoyalBlue4 = new java.awt.Color(39, 64, 139); 
    public final static Color RoyalBlue5 = new java.awt.Color(00, 34, 102); 
    public final static Color SkyBlue = new java.awt.Color(135, 206, 235); 
    public final static Color SkyBlue1 = new java.awt.Color(135, 206, 255); 
    public final static Color SkyBlue2 = new java.awt.Color(126, 192, 238); 
    public final static Color SkyBlue3 = new java.awt.Color(108, 166, 205); 
    public final static Color SkyBlue4 = new java.awt.Color(74, 112, 139); 
    public final static Color SlateBlue = new java.awt.Color(106, 90, 205); 
    public final static Color SlateBlue1 = new java.awt.Color(131, 111, 255); 
    public final static Color SlateBlue2 = new java.awt.Color(122, 103, 238); 
    public final static Color SlateBlue3 = new java.awt.Color(105, 89, 205); 
    public final static Color SlateBlue4 = new java.awt.Color(71, 60, 139); 
    public final static Color SteelBlue = new java.awt.Color(70, 130, 180); 
    public final static Color SteelBlue1 = new java.awt.Color(99, 184, 255); 
    public final static Color SteelBlue2 = new java.awt.Color(92, 172, 238); 
    public final static Color SteelBlue3 = new java.awt.Color(79, 148, 205); 
    public final static Color SteelBlue4 = new java.awt.Color(54, 100, 139); 
    public final static Color aquamarine = new java.awt.Color(127, 255, 212); 
    public final static Color aquamarine1 = new java.awt.Color(127, 255, 212); 
    public final static Color aquamarine2 = new java.awt.Color(118, 238, 198); 
    public final static Color aquamarine3 = new java.awt.Color(102, 205, 170); 
    public final static Color aquamarine4 = new java.awt.Color(69, 139, 116); 
    public final static Color azure = new java.awt.Color(240, 255, 255); 
    public final static Color azure1 = new java.awt.Color(240, 255, 255); 
    public final static Color azure2 = new java.awt.Color(224, 238, 238); 
    public final static Color azure3 = new java.awt.Color(193, 205, 205); 
    public final static Color azure4 = new java.awt.Color(131, 139, 139); 
    public final static Color blue = new java.awt.Color(0, 0, 255); 
    public final static Color blue1 = new java.awt.Color(0, 0, 255); 
    public final static Color blue2 = new java.awt.Color(0, 0, 238); 
    public final static Color blue3 = new java.awt.Color(0, 0, 205); 
    public final static Color blue4 = new java.awt.Color(0, 0, 139); 
    public final static Color cyan = new java.awt.Color(0, 255, 255); 
    public final static Color cyan1 = new java.awt.Color(0, 255, 255); 
    public final static Color cyan2 = new java.awt.Color(0, 238, 238); 
    public final static Color cyan3 = new java.awt.Color(0, 205, 205); 
    public final static Color cyan4 = new java.awt.Color(0, 139, 139); 
    public final static Color navy = new java.awt.Color(0, 0, 128); 
    public final static Color turquoise = new java.awt.Color(64, 224, 208); 
    public final static Color turquoise1 = new java.awt.Color(0, 245, 255); 
    public final static Color turquoise2 = new java.awt.Color(0, 229, 238); 
    public final static Color turquoise3 = new java.awt.Color(0, 197, 205); 
    public final static Color turquoise4 = new java.awt.Color(0, 134, 139); 
    public final static Color DarkSlateGray = new java.awt.Color(47, 79, 79); 
    public final static Color DarkSlateGray1 = new java.awt.Color(151, 255, 255); 
    public final static Color DarkSlateGray2 = new java.awt.Color(141, 238, 238); 
    public final static Color DarkSlateGray3 = new java.awt.Color(121, 205, 205); 
    public final static Color DarkSlateGray4 = new java.awt.Color(82, 139, 139); 
    public final static Color RosyBrown = new java.awt.Color(188, 143, 143); 
    public final static Color RosyBrown1 = new java.awt.Color(255, 193, 193); 
    public final static Color RosyBrown2 = new java.awt.Color(238, 180, 180); 
    public final static Color RosyBrown3 = new java.awt.Color(205, 155, 155); 
    public final static Color RosyBrown4 = new java.awt.Color(139, 105, 105); 
    public final static Color SaddleBrown = new java.awt.Color(139, 69, 19); 
    public final static Color SandyBrown = new java.awt.Color(244, 164, 96); 
    public final static Color beige = new java.awt.Color(245, 245, 220); 
    public final static Color brown = new java.awt.Color(165, 42, 42); 
    public final static Color brown1 = new java.awt.Color(255, 64, 64); 
    public final static Color brown2 = new java.awt.Color(238, 59, 59); 
    public final static Color brown3 = new java.awt.Color(205, 51, 51); 
    public final static Color brown4 = new java.awt.Color(139, 35, 35); 
    public final static Color burlywood = new java.awt.Color(222, 184, 135); 
    public final static Color burlywood1 = new java.awt.Color(255, 211, 155); 
    public final static Color burlywood2 = new java.awt.Color(238, 197, 145); 
    public final static Color burlywood3 = new java.awt.Color(205, 170, 125); 
    public final static Color burlywood4 = new java.awt.Color(139, 115, 85); 
    public final static Color chocolate = new java.awt.Color(210, 105, 30); 
    public final static Color chocolate1 = new java.awt.Color(255, 127, 36); 
    public final static Color chocolate2 = new java.awt.Color(238, 118, 33); 
    public final static Color chocolate3 = new java.awt.Color(205, 102, 29); 
    public final static Color chocolate4 = new java.awt.Color(139, 69, 19); 
    public final static Color peru = new java.awt.Color(205, 133, 63); 
    public final static Color tan = new java.awt.Color(210, 180, 140); 
    public final static Color tan1 = new java.awt.Color(255, 165, 79); 
    public final static Color tan2 = new java.awt.Color(238, 154, 73); 
    public final static Color tan3 = new java.awt.Color(205, 133, 63); 
    public final static Color tan4 = new java.awt.Color(139, 90, 43); 
    public final static Color DarkGreen = new java.awt.Color(0, 100, 0); 
    public final static Color DarkKhaki = new java.awt.Color(189, 183, 107); 
    public final static Color DarkOliveGreen = new java.awt.Color(85, 107, 47); 
    public final static Color DarkOliveGreen1 = new java.awt.Color(202, 255, 112); 
    public final static Color DarkOliveGreen2 = new java.awt.Color(188, 238, 104); 
    public final static Color DarkOliveGreen3 = new java.awt.Color(162, 205, 90); 
    public final static Color DarkOliveGreen4 = new java.awt.Color(110, 139, 61); 
    public final static Color DarkSeaGreen = new java.awt.Color(143, 188, 143); 
    public final static Color DarkSeaGreen1 = new java.awt.Color(193, 255, 193); 
    public final static Color DarkSeaGreen2 = new java.awt.Color(180, 238, 180); 
    public final static Color DarkSeaGreen3 = new java.awt.Color(155, 205, 155); 
    public final static Color DarkSeaGreen4 = new java.awt.Color(105, 139, 105); 
    public final static Color ForestGreen = new java.awt.Color(34, 139, 34); 
    public final static Color GreenYellow = new java.awt.Color(173, 255, 47); 
    public final static Color LawnGreen = new java.awt.Color(124, 252, 0); 
    public final static Color LightSeaGreen = new java.awt.Color(32, 178, 170); 
    public final static Color LimeGreen = new java.awt.Color(50, 205, 50); 
    public final static Color MediumSeaGreen = new java.awt.Color(60, 179, 113); 
    public final static Color MediumSpringGreen = new java.awt.Color(0, 250, 154); 
    public final static Color MintCream = new java.awt.Color(245, 255, 250); 
    public final static Color OliveDrab = new java.awt.Color(107, 142, 35); 
    public final static Color OliveDrab1 = new java.awt.Color(192, 255, 62); 
    public final static Color OliveDrab2 = new java.awt.Color(179, 238, 58); 
    public final static Color OliveDrab3 = new java.awt.Color(154, 205, 50); 
    public final static Color OliveDrab4 = new java.awt.Color(105, 139, 34); 
    public final static Color PaleGreen = new java.awt.Color(152, 251, 152); 
    public final static Color PaleGreen1 = new java.awt.Color(154, 255, 154); 
    public final static Color PaleGreen2 = new java.awt.Color(144, 238, 144); 
    public final static Color PaleGreen3 = new java.awt.Color(124, 205, 124); 
    public final static Color PaleGreen4 = new java.awt.Color(84, 139, 84); 
    public final static Color SeaGreen = new java.awt.Color(46, 139, 87); 
    public final static Color SeaGreen1 = new java.awt.Color(84, 255, 159); 
    public final static Color SeaGreen2 = new java.awt.Color(78, 238, 148); 
    public final static Color SeaGreen3 = new java.awt.Color(67, 205, 128); 
    public final static Color SeaGreen4 = new java.awt.Color(46, 139, 87); 
    public final static Color SpringGreen = new java.awt.Color(0, 255, 127); 
    public final static Color SpringGreen1 = new java.awt.Color(0, 255, 127); 
    public final static Color SpringGreen2 = new java.awt.Color(0, 238, 118); 
    public final static Color SpringGreen3 = new java.awt.Color(0, 205, 102); 
    public final static Color SpringGreen4 = new java.awt.Color(0, 139, 69); 
    public final static Color YellowGreen = new java.awt.Color(154, 205, 50); 
    public final static Color chartreuse = new java.awt.Color(127, 255, 0); 
    public final static Color chartreuse1 = new java.awt.Color(127, 255, 0); 
    public final static Color chartreuse2 = new java.awt.Color(118, 238, 0); 
    public final static Color chartreuse3 = new java.awt.Color(102, 205, 0); 
    public final static Color chartreuse4 = new java.awt.Color(69, 139, 0); 
    public final static Color green = new java.awt.Color(0, 255, 0); 
    public final static Color green1 = new java.awt.Color(0, 255, 0); 
    public final static Color green2 = new java.awt.Color(0, 238, 0); 
    public final static Color green3 = new java.awt.Color(0, 205, 0); 
    public final static Color green4 = new java.awt.Color(0, 139, 0); 
    public final static Color khaki = new java.awt.Color(240, 230, 140); 
    public final static Color khaki1 = new java.awt.Color(255, 246, 143); 
    public final static Color khaki2 = new java.awt.Color(238, 230, 133); 
    public final static Color khaki3 = new java.awt.Color(205, 198, 115); 
    public final static Color khaki4 = new java.awt.Color(139, 134, 78); 
    public final static Color DarkOrange = new java.awt.Color(255, 140, 0); 
    public final static Color DarkOrange1 = new java.awt.Color(255, 127, 0); 
    public final static Color DarkOrange2 = new java.awt.Color(238, 118, 0); 
    public final static Color DarkOrange3 = new java.awt.Color(205, 102, 0); 
    public final static Color DarkOrange4 = new java.awt.Color(139, 69, 0); 
    public final static Color DarkSalmon = new java.awt.Color(233, 150, 122); 
    public final static Color LightCoral = new java.awt.Color(240, 128, 128); 
    public final static Color LightSalmon = new java.awt.Color(255, 160, 122); 
    public final static Color LightSalmon1 = new java.awt.Color(255, 160, 122); 
    public final static Color LightSalmon2 = new java.awt.Color(238, 149, 114); 
    public final static Color LightSalmon3 = new java.awt.Color(205, 129, 98); 
    public final static Color LightSalmon4 = new java.awt.Color(139, 87, 66); 
    public final static Color PeachPuff = new java.awt.Color(255, 218, 185); 
    public final static Color PeachPuff1 = new java.awt.Color(255, 218, 185); 
    public final static Color PeachPuff2 = new java.awt.Color(238, 203, 173); 
    public final static Color PeachPuff3 = new java.awt.Color(205, 175, 149); 
    public final static Color PeachPuff4 = new java.awt.Color(139, 119, 101); 
    public final static Color bisque = new java.awt.Color(255, 228, 196); 
    public final static Color bisque1 = new java.awt.Color(255, 228, 196); 
    public final static Color bisque2 = new java.awt.Color(238, 213, 183); 
    public final static Color bisque3 = new java.awt.Color(205, 183, 158); 
    public final static Color bisque4 = new java.awt.Color(139, 125, 107); 
    public final static Color coral = new java.awt.Color(255, 127, 80); 
    public final static Color coral1 = new java.awt.Color(255, 114, 86); 
    public final static Color coral2 = new java.awt.Color(238, 106, 80); 
    public final static Color coral3 = new java.awt.Color(205, 91, 69); 
    public final static Color coral4 = new java.awt.Color(139, 62, 47); 
    public final static Color honeydew = new java.awt.Color(240, 255, 240); 
    public final static Color honeydew1 = new java.awt.Color(240, 255, 240); 
    public final static Color honeydew2 = new java.awt.Color(224, 238, 224); 
    public final static Color honeydew3 = new java.awt.Color(193, 205, 193); 
    public final static Color honeydew4 = new java.awt.Color(131, 139, 131); 
    public final static Color orange = new java.awt.Color(255, 165, 0); 
    public final static Color orange1 = new java.awt.Color(255, 165, 0); 
    public final static Color orange2 = new java.awt.Color(238, 154, 0); 
    public final static Color orange3 = new java.awt.Color(205, 133, 0); 
    public final static Color orange4 = new java.awt.Color(139, 90, 0); 
    public final static Color salmon = new java.awt.Color(250, 128, 114); 
    public final static Color salmon1 = new java.awt.Color(255, 140, 105); 
    public final static Color salmon2 = new java.awt.Color(238, 130, 98); 
    public final static Color salmon3 = new java.awt.Color(205, 112, 84); 
    public final static Color salmon4 = new java.awt.Color(139, 76, 57); 
    public final static Color sienna = new java.awt.Color(160, 82, 45); 
    public final static Color sienna1 = new java.awt.Color(255, 130, 71); 
    public final static Color sienna2 = new java.awt.Color(238, 121, 66); 
    public final static Color sienna3 = new java.awt.Color(205, 104, 57); 
    public final static Color sienna4 = new java.awt.Color(139, 71, 38); 
    public final static Color DeepPink = new java.awt.Color(255, 20, 147); 
    public final static Color DeepPink1 = new java.awt.Color(255, 20, 147); 
    public final static Color DeepPink2 = new java.awt.Color(238, 18, 137); 
    public final static Color DeepPink3 = new java.awt.Color(205, 16, 118); 
    public final static Color DeepPink4 = new java.awt.Color(139, 10, 80); 
    public final static Color HotPink = new java.awt.Color(255, 105, 180); 
    public final static Color HotPink1 = new java.awt.Color(255, 110, 180); 
    public final static Color HotPink2 = new java.awt.Color(238, 106, 167); 
    public final static Color HotPink3 = new java.awt.Color(205, 96, 144); 
    public final static Color HotPink4 = new java.awt.Color(139, 58, 98); 
    public final static Color IndianRed = new java.awt.Color(205, 92, 92); 
    public final static Color IndianRed1 = new java.awt.Color(255, 106, 106); 
    public final static Color IndianRed2 = new java.awt.Color(238, 99, 99); 
    public final static Color IndianRed3 = new java.awt.Color(205, 85, 85); 
    public final static Color IndianRed4 = new java.awt.Color(139, 58, 58); 
    public final static Color LightPink = new java.awt.Color(255, 182, 193); 
    public final static Color LightPink1 = new java.awt.Color(255, 174, 185); 
    public final static Color LightPink2 = new java.awt.Color(238, 162, 173); 
    public final static Color LightPink3 = new java.awt.Color(205, 140, 149); 
    public final static Color LightPink4 = new java.awt.Color(139, 95, 101); 
    public final static Color MediumVioletRed = new java.awt.Color(199, 21, 133); 
    public final static Color MistyRose = new java.awt.Color(255, 228, 225); 
    public final static Color MistyRose1 = new java.awt.Color(255, 228, 225); 
    public final static Color MistyRose2 = new java.awt.Color(238, 213, 210); 
    public final static Color MistyRose3 = new java.awt.Color(205, 183, 181); 
    public final static Color MistyRose4 = new java.awt.Color(139, 125, 123); 
    public final static Color OrangeRed = new java.awt.Color(255, 69, 0); 
    public final static Color OrangeRed1 = new java.awt.Color(255, 69, 0); 
    public final static Color OrangeRed2 = new java.awt.Color(238, 64, 0); 
    public final static Color OrangeRed3 = new java.awt.Color(205, 55, 0); 
    public final static Color OrangeRed4 = new java.awt.Color(139, 37, 0); 
    public final static Color PaleVioletRed = new java.awt.Color(219, 112, 147); 
    public final static Color PaleVioletRed1 = new java.awt.Color(255, 130, 171); 
    public final static Color PaleVioletRed2 = new java.awt.Color(238, 121, 159); 
    public final static Color PaleVioletRed3 = new java.awt.Color(205, 104, 137); 
    public final static Color PaleVioletRed4 = new java.awt.Color(139, 71, 93); 
    public final static Color VioletRed = new java.awt.Color(208, 32, 144); 
    public final static Color VioletRed1 = new java.awt.Color(255, 62, 150); 
    public final static Color VioletRed2 = new java.awt.Color(238, 58, 140); 
    public final static Color VioletRed3 = new java.awt.Color(205, 50, 120); 
    public final static Color VioletRed4 = new java.awt.Color(139, 34, 82); 
    public final static Color firebrick = new java.awt.Color(178, 34, 34); 
    public final static Color firebrick1 = new java.awt.Color(255, 48, 48); 
    public final static Color firebrick2 = new java.awt.Color(238, 44, 44); 
    public final static Color firebrick3 = new java.awt.Color(205, 38, 38); 
    public final static Color firebrick4 = new java.awt.Color(139, 26, 26); 
    public final static Color pink = new java.awt.Color(255, 192, 203); 
    public final static Color pink1 = new java.awt.Color(255, 181, 197); 
    public final static Color pink2 = new java.awt.Color(238, 169, 184); 
    public final static Color pink3 = new java.awt.Color(205, 145, 158); 
    public final static Color pink4 = new java.awt.Color(139, 99, 108); 
    public final static Color red = new java.awt.Color(255, 0, 0); 
    public final static Color red1 = new java.awt.Color(255, 0, 0); 
    public final static Color red2 = new java.awt.Color(238, 0, 0); 
    public final static Color red3 = new java.awt.Color(205, 0, 0); 
    public final static Color red4 = new java.awt.Color(139, 0, 0); 
    public final static Color tomato = new java.awt.Color(255, 99, 71); 
    public final static Color tomato1 = new java.awt.Color(255, 99, 71); 
    public final static Color tomato2 = new java.awt.Color(238, 92, 66); 
    public final static Color tomato3 = new java.awt.Color(205, 79, 57); 
    public final static Color tomato4 = new java.awt.Color(139, 54, 38); 
    public final static Color DarkOrchid = new java.awt.Color(153, 50, 204); 
    public final static Color DarkOrchid1 = new java.awt.Color(191, 62, 255); 
    public final static Color DarkOrchid2 = new java.awt.Color(178, 58, 238); 
    public final static Color DarkOrchid3 = new java.awt.Color(154, 50, 205); 
    public final static Color DarkOrchid4 = new java.awt.Color(104, 34, 139); 
    public final static Color DarkViolet = new java.awt.Color(148, 0, 211); 
    public final static Color LavenderBlush = new java.awt.Color(255, 240, 245); 
    public final static Color LavenderBlush1 = new java.awt.Color(255, 240, 245); 
    public final static Color LavenderBlush2 = new java.awt.Color(238, 224, 229); 
    public final static Color LavenderBlush3 = new java.awt.Color(205, 193, 197); 
    public final static Color LavenderBlush4 = new java.awt.Color(139, 131, 134); 
    public final static Color MediumOrchid = new java.awt.Color(186, 85, 211); 
    public final static Color MediumOrchid1 = new java.awt.Color(224, 102, 255); 
    public final static Color MediumOrchid2 = new java.awt.Color(209, 95, 238); 
    public final static Color MediumOrchid3 = new java.awt.Color(180, 82, 205); 
    public final static Color MediumOrchid4 = new java.awt.Color(122, 55, 139); 
    public final static Color MediumPurple = new java.awt.Color(147, 112, 219); 
    public final static Color MediumPurple1 = new java.awt.Color(171, 130, 255); 
    public final static Color MediumPurple2 = new java.awt.Color(159, 121, 238); 
    public final static Color MediumPurple3 = new java.awt.Color(137, 104, 205); 
    public final static Color MediumPurple4 = new java.awt.Color(93, 71, 139); 
    public final static Color lavender = new java.awt.Color(230, 230, 250); 
    public final static Color magenta = new java.awt.Color(255, 0, 255); 
    public final static Color magenta1 = new java.awt.Color(255, 0, 255); 
    public final static Color magenta2 = new java.awt.Color(238, 0, 238); 
    public final static Color magenta3 = new java.awt.Color(205, 0, 205); 
    public final static Color magenta4 = new java.awt.Color(139, 0, 139); 
    public final static Color maroon = new java.awt.Color(176, 48, 96); 
    public final static Color maroon1 = new java.awt.Color(255, 52, 179); 
    public final static Color maroon2 = new java.awt.Color(238, 48, 167); 
    public final static Color maroon3 = new java.awt.Color(205, 41, 144); 
    public final static Color maroon4 = new java.awt.Color(139, 28, 98); 
    public final static Color orchid = new java.awt.Color(218, 112, 214); 
    public final static Color orchid1 = new java.awt.Color(255, 131, 250); 
    public final static Color orchid2 = new java.awt.Color(238, 122, 233); 
    public final static Color orchid3 = new java.awt.Color(205, 105, 201); 
    public final static Color orchid4 = new java.awt.Color(139, 71, 137); 
    public final static Color plum = new java.awt.Color(221, 160, 221); 
    public final static Color plum1 = new java.awt.Color(255, 187, 255); 
    public final static Color plum2 = new java.awt.Color(238, 174, 238); 
    public final static Color plum3 = new java.awt.Color(205, 150, 205); 
    public final static Color plum4 = new java.awt.Color(139, 102, 139); 
    public final static Color purple = new java.awt.Color(160, 32, 240); 
    public final static Color purple1 = new java.awt.Color(155, 48, 255); 
    public final static Color purple2 = new java.awt.Color(145, 44, 238); 
    public final static Color purple3 = new java.awt.Color(125, 38, 205); 
    public final static Color purple4 = new java.awt.Color(85, 26, 139); 
    public final static Color thistle = new java.awt.Color(216, 191, 216); 
    public final static Color thistle1 = new java.awt.Color(255, 225, 255); 
    public final static Color thistle2 = new java.awt.Color(238, 210, 238); 
    public final static Color thistle3 = new java.awt.Color(205, 181, 205); 
    public final static Color thistle4 = new java.awt.Color(139, 123, 139); 
    public final static Color violet = new java.awt.Color(238, 130, 238); 
    public final static Color AntiqueWhite = new java.awt.Color(250, 235, 215); 
    public final static Color AntiqueWhite1 = new java.awt.Color(255, 239, 219); 
    public final static Color AntiqueWhite2 = new java.awt.Color(238, 223, 204); 
    public final static Color AntiqueWhite3 = new java.awt.Color(205, 192, 176); 
    public final static Color AntiqueWhite4 = new java.awt.Color(139, 131, 120); 
    public final static Color FloralWhite = new java.awt.Color(255, 250, 240); 
    public final static Color GhostWhite = new java.awt.Color(248, 248, 255); 
    public final static Color NavajoWhite = new java.awt.Color(255, 222, 173); 
    public final static Color NavajoWhite1 = new java.awt.Color(255, 222, 173); 
    public final static Color NavajoWhite2 = new java.awt.Color(238, 207, 161); 
    public final static Color NavajoWhite3 = new java.awt.Color(205, 179, 139); 
    public final static Color NavajoWhite4 = new java.awt.Color(139, 121, 94); 
    public final static Color OldLace = new java.awt.Color(253, 245, 230); 
    public final static Color WhiteSmoke = new java.awt.Color(245, 245, 245); 
    public final static Color gainsboro = new java.awt.Color(220, 220, 220); 
    public final static Color ivory = new java.awt.Color(255, 255, 240); 
    public final static Color ivory1 = new java.awt.Color(255, 255, 240); 
    public final static Color ivory2 = new java.awt.Color(238, 238, 224); 
    public final static Color ivory3 = new java.awt.Color(205, 205, 193); 
    public final static Color ivory4 = new java.awt.Color(139, 139, 131); 
    public final static Color linen = new java.awt.Color(250, 240, 230); 
    public final static Color seashell = new java.awt.Color(255, 245, 238); 
    public final static Color seashell1 = new java.awt.Color(255, 245, 238); 
    public final static Color seashell2 = new java.awt.Color(238, 229, 222); 
    public final static Color seashell3 = new java.awt.Color(205, 197, 191); 
    public final static Color seashell4 = new java.awt.Color(139, 134, 130); 
    public final static Color snow = new java.awt.Color(255, 250, 250); 
    public final static Color snow1 = new java.awt.Color(255, 250, 250); 
    public final static Color snow2 = new java.awt.Color(238, 233, 233); 
    public final static Color snow3 = new java.awt.Color(205, 201, 201); 
    public final static Color snow4 = new java.awt.Color(139, 137, 137); 
    public final static Color wheat = new java.awt.Color(245, 222, 179); 
    public final static Color wheat1 = new java.awt.Color(255, 231, 186); 
    public final static Color wheat2 = new java.awt.Color(238, 216, 174); 
    public final static Color wheat3 = new java.awt.Color(205, 186, 150); 
    public final static Color wheat4 = new java.awt.Color(139, 126, 102); 
    public final static Color white = new java.awt.Color(255, 255, 255); 
    public final static Color BlanchedAlmond = new java.awt.Color(255, 235, 205); 
    public final static Color DarkGoldenrod = new java.awt.Color(184, 134, 11); 
    public final static Color DarkGoldenrod1 = new java.awt.Color(255, 185, 15); 
    public final static Color DarkGoldenrod2 = new java.awt.Color(238, 173, 14); 
    public final static Color DarkGoldenrod3 = new java.awt.Color(205, 149, 12); 
    public final static Color DarkGoldenrod4 = new java.awt.Color(139, 101, 8); 
    public final static Color LemonChiffon = new java.awt.Color(255, 250, 205); 
    public final static Color LemonChiffon1 = new java.awt.Color(255, 250, 205); 
    public final static Color LemonChiffon2 = new java.awt.Color(238, 233, 191); 
    public final static Color LemonChiffon3 = new java.awt.Color(205, 201, 165); 
    public final static Color LemonChiffon4 = new java.awt.Color(139, 137, 112); 
    public final static Color LightGoldenrod = new java.awt.Color(238, 221, 130); 
    public final static Color LightGoldenrod1 = new java.awt.Color(255, 236, 139); 
    public final static Color LightGoldenrod2 = new java.awt.Color(238, 220, 130); 
    public final static Color LightGoldenrod3 = new java.awt.Color(205, 190, 112); 
    public final static Color LightGoldenrod4 = new java.awt.Color(139, 129, 76); 
    public final static Color LightGoldenrodYellow = new java.awt.Color(250, 250,
            210); 
    public final static Color LightYellow = new java.awt.Color(255, 255, 224); 
    public final static Color LightYellow1 = new java.awt.Color(255, 255, 224); 
    public final static Color LightYellow2 = new java.awt.Color(238, 238, 209); 
    public final static Color LightYellow3 = new java.awt.Color(205, 205, 180); 
    public final static Color LightYellow4 = new java.awt.Color(139, 139, 122); 
    public final static Color PaleGoldenrod = new java.awt.Color(238, 232, 170); 
    public final static Color PapayaWhip = new java.awt.Color(255, 239, 213); 
    public final static Color cornsilk = new java.awt.Color(255, 248, 220); 
    public final static Color cornsilk1 = new java.awt.Color(255, 248, 220); 
    public final static Color cornsilk2 = new java.awt.Color(238, 232, 205); 
    public final static Color cornsilk3 = new java.awt.Color(205, 200, 177); 
    public final static Color cornsilk4 = new java.awt.Color(139, 136, 120); 
    public final static Color gold = new java.awt.Color(255, 215, 0); 
    public final static Color gold1 = new java.awt.Color(255, 215, 0); 
    public final static Color gold2 = new java.awt.Color(238, 201, 0); 
    public final static Color gold3 = new java.awt.Color(205, 173, 0); 
    public final static Color gold4 = new java.awt.Color(139, 117, 0); 
    public final static Color goldenrod = new java.awt.Color(218, 165, 32); 
    public final static Color goldenrod1 = new java.awt.Color(255, 193, 37); 
    public final static Color goldenrod2 = new java.awt.Color(238, 180, 34); 
    public final static Color goldenrod3 = new java.awt.Color(205, 155, 29); 
    public final static Color goldenrod4 = new java.awt.Color(139, 105, 20); 
    public final static Color moccasin = new java.awt.Color(255, 228, 181); 
    public final static Color yellow = new java.awt.Color(255, 255, 0); 
    public final static Color yellow1 = new java.awt.Color(255, 255, 0); 
    public final static Color yellow2 = new java.awt.Color(238, 238, 0); 
    public final static Color yellow3 = new java.awt.Color(205, 205, 0); 
    public final static Color yellow4 = new java.awt.Color(139, 139, 0); 

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public Col() {}
}
