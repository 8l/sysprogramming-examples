/* (C) IT Sky Consulting GmbH 2014
 * http://www.it-sky-consulting.com/
 * Author: Karl Brodowsky
 * Date: 2014-02-27
 * License: GPL v2 (See https://de.wikipedia.org/wiki/GNU_General_Public_License )
 */

#include <stdio.h>
#include <string.h>
#include <alloca.h>

#include <sortcommon.h>
#include <itskylib.h>

/* how often do given byte values occur in typical executable binary files (taken from /usr/bin)? */
static long binary_byte_count[] = { 207059223, 10124271,  5166309,  3843289,  4245729,  4293868,  1771579,  1847228,   
                                    5452286,  1331936,  2398333,  1379059,  1397002,  1192199,  4884078,  9316287,   
                                    4668677,   934628,  1186935,   715390,  1375870,  1074543,   628673,  1158625,   
                                    2932591,   572600,   546600,   501615,   981199,   592116,   520894,  2953651,   
                                    12643026,   898935,   963689,   771939, 11803808,  1378336,   596333,   868292,   
                                    2934133,  1751707,   805172,   572216,  1305354,  1313105,  2447518,  1069802,   
                                    2864039,  3807780,  1139233,   891687,  1211563,  1294378,   809474,   682632,   
                                    1877984,  1729864,  1084647,  1117751,  1096989,  1349510,   563642,   582210,   
                                    3251289,  7324753,  2433057,  2314447,  5978076,  9074391,  1299307,  1403967,   
                                    25815366,  4865014,   812967,   914110,  6670217,  1870346,  1775301,  1400804,   
                                    2521895,   792318,  1570867,  2543127,  2628572,  1650403,  1049658,   990401,   
                                    1241831,   640727,   682269,  1092521,  1520637,  1121049,   684743,  5245111,   
                                    1291413,  4421941,  1664138,  3913940,  3620681,  6923932,  4352764,  1867528,   
                                    2223560,  4465834,   520913,   939607,  4385524,  2162222,  4617786,  4031284,   
                                    3014483,   501842,  4963924,  4472462,  8135123,  3520052,  1449718,  1137382,   
                                    1664854,  1120629,   557034,   867370,  1610105,   829927,   581444,   611868,   
                                    2235852,  1011336,   564300,  5844408,  4705586,  4610849,   984826,   615623,   
                                    1187677, 14627408,   491927, 11026817,  1184232,  5471578,   725023,   755505,   
                                    1462013,   392677,   429187,   425237,   887069,   609790,   406777,   383887,   
                                    754540,   362599,   368855,   353008,   519767,   360716,   347706,   367328,   
                                    840853,   327680,   376018,   373841,   463693,   343515,   409549,   358728,   
                                    801064,   342812,   436662,   367754,   558490,   321990,   324123,   379326,   
                                    816721,   351589,   362392,   376347,   736462,   422170,  1150659,   707705,   
                                    1414724,   849932,  1395852,   519543,  1086139,   491563,  1819648,  1139191,   
                                    4355573,  1880747,  1100096,  1964779,  1380673,  1003427,  1569712,  2881644,   
                                    960825,   951041,   559682,   433018,   517092,   463789,   476157,   439558,   
                                    1173610,   588985,  1193384,   504787,   497007,   539327,   524822,   452205,   
                                    1123584,   460902,   506357,   712950,   511484,   473275,   653174,  1726437,   
                                    1401843,   626589,   744526,   568197,   703566,   552659,   749596,   860595,   
                                    8102787,  2986334,   761643,  1558424,  1028793,   905397,   867451,  1290987,   
                                    2038501,   670664,  1095208,   814119,   614252,   670354,  1548360,  1041605,   
                                    1885445,   929025,  1032897,  1250163,  1244361,  1433448,  2618042, 22596132 };

/* calculated with ruby script calculate-fmetric (currently only for information as intermediate result) */
static long binary_byte_count_printable_prefered[] = {         4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                            2864039,      3807780,      1139233,       891687,      1211563,      1294378,       809474,       682632,
                                                            1877984,      1729864,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,      7324753,      2433057,      2314447,      5978076,      9074391,      1299307,      1403967,
                                                           25815366,      4865014,       812967,       914110,      6670217,      1870346,      1775301,      1400804,
                                                            2521895,       792318,      1570867,      2543127,      2628572,      1650403,      1049658,       990401,
                                                            1241831,       640727,       682269,         4671,         4671,         4671,         4671,         4671,
                                                               4671,      4421941,      1664138,      3913940,      3620681,      6923932,      4352764,      1867528,
                                                            2223560,      4465834,       520913,       939607,      4385524,      2162222,      4617786,      4031284,
                                                            3014483,       501842,      4963924,      4472462,      8135123,      3520052,      1449718,      1137382,
                                                            1664854,      1120629,       557034,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                               4671,         4671,         4671,         4671,         4671,         4671,         4671,         4671,
                                                             840853,       327680,       376018,       373841,       463693,       343515,       409549,       358728,
                                                             801064,       342812,       436662,       367754,       558490,       321990,       324123,       379326,
                                                             816721,       351589,       362392,       376347,       736462,       422170,      1150659,       707705,
                                                            1414724,       849932,      1395852,       519543,      1086139,       491563,      1819648,      1139191,
                                                            4355573,      1880747,      1100096,      1964779,      1380673,      1003427,      1569712,      2881644,
                                                             960825,       951041,       559682,       433018,       517092,       463789,       476157,       439558,
                                                            1173610,       588985,      1193384,       504787,       497007,       539327,       524822,       452205,
                                                            1123584,       460902,       506357,       712950,       511484,       473275,       653174,      1726437,
                                                            1401843,       626589,       744526,       568197,       703566,       552659,       749596,       860595,
                                                            8102787,      2986334,       761643,      1558424,      1028793,       905397,       867451,      1290987,
                                                            2038501,       670664,      1095208,       814119,       614252,       670354,      1548360,      1041605,
                                                            1885445,       929025,      1032897,      1250163,      1244361,      1433448,      2618042,     22596132 };

/* calculated with ruby script calculate-fmetric (currently only for information as intermediate result) */
static long binary_accumulated_count[] = {         0,    207059223,    217183494,    222349803,    226193092,    230438821,    234732689,    236504268,
                                           238351496,    243803782,    245135718,    247534051,    248913110,    250310112,    251502311,    256386389,
                                           265702676,    270371353,    271305981,    272492916,    273208306,    274584176,    275658719,    276287392,
                                           277446017,    280378608,    280951208,    281497808,    281999423,    282980622,    283572738,    284093632,
                                           287047283,    299690309,    300589244,    301552933,    302324872,    314128680,    315507016,    316103349,
                                           316971641,    319905774,    321657481,    322462653,    323034869,    324340223,    325653328,    328100846,
                                           329170648,    332034687,    335842467,    336981700,    337873387,    339084950,    340379328,    341188802,
                                           341871434,    343749418,    345479282,    346563929,    347681680,    348778669,    350128179,    350691821,
                                           351274031,    354525320,    361850073,    364283130,    366597577,    372575653,    381650044,    382949351,
                                           384353318,    410168684,    415033698,    415846665,    416760775,    423430992,    425301338,    427076639,
                                           428477443,    430999338,    431791656,    433362523,    435905650,    438534222,    440184625,    441234283,
                                           442224684,    443466515,    444107242,    444789511,    445882032,    447402669,    448523718,    449208461,
                                           454453572,    455744985,    460166926,    461831064,    465745004,    469365685,    476289617,    480642381,
                                           482509909,    484733469,    489199303,    489720216,    490659823,    495045347,    497207569,    501825355,
                                           505856639,    508871122,    509372964,    514336888,    518809350,    526944473,    530464525,    531914243,
                                           533051625,    534716479,    535837108,    536394142,    537261512,    538871617,    539701544,    540282988,
                                           540894856,    543130708,    544142044,    544706344,    550550752,    555256338,    559867187,    560852013,
                                           561467636,    562655313,    577282721,    577774648,    588801465,    589985697,    595457275,    596182298,
                                           596937803,    598399816,    598792493,    599221680,    599646917,    600533986,    601143776,    601550553,
                                           601934440,    602688980,    603051579,    603420434,    603773442,    604293209,    604653925,    605001631,
                                           605368959,    606209812,    606537492,    606913510,    607287351,    607751044,    608094559,    608504108,
                                           608862836,    609663900,    610006712,    610443374,    610811128,    611369618,    611691608,    612015731,
                                           612395057,    613211778,    613563367,    613925759,    614302106,    615038568,    615460738,    616611397,
                                           617319102,    618733826,    619583758,    620979610,    621499153,    622585292,    623076855,    624896503,
                                           626035694,    630391267,    632272014,    633372110,    635336889,    636717562,    637720989,    639290701,
                                           642172345,    643133170,    644084211,    644643893,    645076911,    645594003,    646057792,    646533949,
                                           646973507,    648147117,    648736102,    649929486,    650434273,    650931280,    651470607,    651995429,
                                           652447634,    653571218,    654032120,    654538477,    655251427,    655762911,    656236186,    656889360,
                                           658615797,    660017640,    660644229,    661388755,    661956952,    662660518,    663213177,    663962773,
                                           664823368,    672926155,    675912489,    676674132,    678232556,    679261349,    680166746,    681034197,
                                           682325184,    684363685,    685034349,    686129557,    686943676,    687557928,    688228282,    689776642,
                                           690818247,    692703692,    693632717,    694665614,    695915777,    697160138,    698593586,    701211628 };

/* calculated with ruby script calculate-fmetric (currently only for information as intermediate result) */
static long binary_printable_preferred_accumulated_count[] = {            0,         4671,         9342,        14013,        18684,        23355,        28026,        32697,
                                                                      37368,        42039,        46710,        51381,        56052,        60723,        65394,        70065,
                                                                      74736,        79407,        84078,        88749,        93420,        98091,       102762,       107433,
                                                                     112104,       116775,       121446,       126117,       130788,       135459,       140130,       144801,
                                                                     149472,       154143,       158814,       163485,       168156,       172827,       177498,       182169,
                                                                     186840,       191511,       196182,       200853,       205524,       210195,       214866,       219537,
                                                                     224208,      3088247,      6896027,      8035260,      8926947,     10138510,     11432888,     12242362,
                                                                   12924994,     14802978,     16532842,     16537513,     16542184,     16546855,     16551526,     16556197,
                                                                   16560868,     16565539,     23890292,     26323349,     28637796,     34615872,     43690263,     44989570,
                                                                   46393537,     72208903,     77073917,     77886884,     78800994,     85471211,     87341557,     89116858,
                                                                   90517662,     93039557,     93831875,     95402742,     97945869,    100574441,    102224844,    103274502,
                                                                  104264903,    105506734,    106147461,    106829730,    106834401,    106839072,    106843743,    106848414,
                                                                  106853085,    106857756,    111279697,    112943835,    116857775,    120478456,    127402388,    131755152,
                                                                  133622680,    135846240,    140312074,    140832987,    141772594,    146158118,    148320340,    152938126,
                                                                  156969410,    159983893,    160485735,    165449659,    169922121,    178057244,    181577296,    183027014,
                                                                  184164396,    185829250,    186949879,    187506913,    187511584,    187516255,    187520926,    187525597,
                                                                  187530268,    187534939,    187539610,    187544281,    187548952,    187553623,    187558294,    187562965,
                                                                  187567636,    187572307,    187576978,    187581649,    187586320,    187590991,    187595662,    187600333,
                                                                  187605004,    187609675,    187614346,    187619017,    187623688,    187628359,    187633030,    187637701,
                                                                  187642372,    187647043,    187651714,    187656385,    187661056,    187665727,    187670398,    187675069,
                                                                  187679740,    188520593,    188848273,    189224291,    189598132,    190061825,    190405340,    190814889,
                                                                  191173617,    191974681,    192317493,    192754155,    193121909,    193680399,    194002389,    194326512,
                                                                  194705838,    195522559,    195874148,    196236540,    196612887,    197349349,    197771519,    198922178,
                                                                  199629883,    201044607,    201894539,    203290391,    203809934,    204896073,    205387636,    207207284,
                                                                  208346475,    212702048,    214582795,    215682891,    217647670,    219028343,    220031770,    221601482,
                                                                  224483126,    225443951,    226394992,    226954674,    227387692,    227904784,    228368573,    228844730,
                                                                  229284288,    230457898,    231046883,    232240267,    232745054,    233242061,    233781388,    234306210,
                                                                  234758415,    235881999,    236342901,    236849258,    237562208,    238073692,    238546967,    239200141,
                                                                  240926578,    242328421,    242955010,    243699536,    244267733,    244971299,    245523958,    246273554,
                                                                  247134149,    255236936,    258223270,    258984913,    260543337,    261572130,    262477527,    263344978,
                                                                  264635965,    266674466,    267345130,    268440338,    269254457,    269868709,    270539063,    272087423,
                                                                  273129028,    275014473,    275943498,    276976395,    278226558,    279470919,    280904367,    283522409 };


/* assuming a two-byte factor including all bytes, what factor should be used for each potential byte value when doing the metric function for fsort?
 * This is based on the table above..
 * calculated with ruby script calculate-fmetric
 */
static double factors_all[] = {  0.00000000000000, 0.28606936046113, 0.30005687421754, 0.30719455536094, 0.31250437547119, 0.31837019956791, 0.32430253165564, 0.32675011387001,
                                 0.32930221140486, 0.33683499331369, 0.33867517253476, 0.34198866699080, 0.34389395051526, 0.34582402377117, 0.34747114482442, 0.35421890060974,
                                 0.36709011796171, 0.37354027953500, 0.37483154505003, 0.37647139345397, 0.37745976362563, 0.37936064128409, 0.38084521088859, 0.38171377438672,
                                 0.38331451019536, 0.38736612605535, 0.38815722008838, 0.38891239298125, 0.38960541539372, 0.39096102257870, 0.39177907957218, 0.39249873751008,
                                 0.39657944949361, 0.41404683061149, 0.41528878330898, 0.41662019898764, 0.41768669625758, 0.43399462862902, 0.43589891326946, 0.43672279639555,
                                 0.43792241326620, 0.44197615952612, 0.44439628693674, 0.44550869833172, 0.44629926183715, 0.44810271583714, 0.44991687848166, 0.45329832606382,
                                 0.45477634558657, 0.45873325121576, 0.46399401271962, 0.46556795688402, 0.46679989587290, 0.46847376988608, 0.47026205963860, 0.47138041460069,
                                 0.47232352689891, 0.47491811637941, 0.47730806588755, 0.47880659499976, 0.48035086001289, 0.48186644061401, 0.48373089976267, 0.48450961758133,
                                 0.48531398862040, 0.48980591200072, 0.49992566120043, 0.50328712972074, 0.50648472876279, 0.51474393283653, 0.52728095095305, 0.52907605052480,
                                 0.53101574650153, 0.56668179959828, 0.57340321689837, 0.57452639772749, 0.57578931593660, 0.58500476977478, 0.58758880672957, 0.59004153119331,
                                 0.59197685722518, 0.59546106275512, 0.59655571529103, 0.59872599735598, 0.60223953664161, 0.60587112522806, 0.60815129282394, 0.60960148175256,
                                 0.61096980225799, 0.61268549400465, 0.61357071109600, 0.61451332187983, 0.61602272957118, 0.61812361475649, 0.61967243622809, 0.62061846504658,
                                 0.62786501763949, 0.62964921100045, 0.63575848647989, 0.63805763010886, 0.64346506039117, 0.64846732922565, 0.65803331122065, 0.66404701298035,
                                 0.66662715663618, 0.66969918780644, 0.67586910507840, 0.67658878926637, 0.67788693367974, 0.68394589607605, 0.68693318375034, 0.69331303521808,
                                 0.69888258589546, 0.70304734229431, 0.70374067832597, 0.71059874793274, 0.71677782233227, 0.72801716439183, 0.73288040597962, 0.73488331072880,
                                 0.73645469758434, 0.73875483042624, 0.74030307163327, 0.74107265995601, 0.74227100300776, 0.74449549559955, 0.74564210806472, 0.74644542081174,
                                 0.74729076681908, 0.75037978039915, 0.75177702433033, 0.75255665123016, 0.76063118195914, 0.76713233635406, 0.77350260378529, 0.77486322196933,
                                 0.77571375581826, 0.77735462935628, 0.79756359754971, 0.79824323519273, 0.81347769054037, 0.81511380452732, 0.82267323992216, 0.82367491887625,
                                 0.82471871122244, 0.82673860252617, 0.82728111812451, 0.82787407529314, 0.82846157521163, 0.82968713405338, 0.83052960913268, 0.83109160504165,
                                 0.83162197653145, 0.83266443565070, 0.83316539601620, 0.83367499956066, 0.83416270917018, 0.83488081006482, 0.83537916891082, 0.83585955337091,
                                 0.83636704723917, 0.83752875487270, 0.83798147176538, 0.83850097158395, 0.83901746369782, 0.83965809374578, 0.84013268799439, 0.84069851364954,
                                 0.84119412590990, 0.84230086176473, 0.84277448476098, 0.84337776925741, 0.84388585167973, 0.84465745158632, 0.84510230727562, 0.84555010988000,
                                 0.84607417997287, 0.84720254726200, 0.84768829640622, 0.84818897078418, 0.84870892514333, 0.84972640801751, 0.85030967062304, 0.85189940074696,
                                 0.85287715345854, 0.85483171111622, 0.85600596213558, 0.85793444657184, 0.85865223799203, 0.86015282842505, 0.86083196317210, 0.86334595666673,
                                 0.86491984280467, 0.87093742542909, 0.87353583222153, 0.87505570539890, 0.87777020931635, 0.87967772271466, 0.88106403971132, 0.88323272604870,
                                 0.88721395443453, 0.88854141326144, 0.88985535468700, 0.89062860143970, 0.89122685145017, 0.89194125661211, 0.89258201929197, 0.89323986938189,
                                 0.89384715494070, 0.89546859376031, 0.89628232501956, 0.89793108324785, 0.89862848803942, 0.89931514412059, 0.90006026876529, 0.90078535355852,
                                 0.90141011198885, 0.90296243577162, 0.90359920982334, 0.90429878369914, 0.90528378280995, 0.90599044005828, 0.90664430842797, 0.90754672207438,
                                 0.90993193689993, 0.91186869839583, 0.91273438267642, 0.91376300663038, 0.91454801755648, 0.91552005189886, 0.91628359579897, 0.91731922437527,
                                 0.91850820720684, 0.92970287442069, 0.93382874065898, 0.93488101315742, 0.93703410419363, 0.93845546640727, 0.93970634688968, 0.94090480184960,
                                 0.94268840665649, 0.94550476358529, 0.94643134110637, 0.94794446110940, 0.94906923352134, 0.94991787322092, 0.95084402245149, 0.95298320924329,
                                 0.95442227228954, 0.95702716975568, 0.95831069426501, 0.95973772649246, 0.96146492958296, 0.96318411673287, 0.96516454313781, 0.96878158366249 };

/* assuming a two-byte factor rarely having non-printable bytes, what factor should be used for each potential byte value when doing the metric function for fsort?
 * This is based on the table above..
 * calculated with ruby script calculate-fmetric
 */
static double factors_printable_pref[] = {  0.00000000000000, 0.00001525879479, 0.00003051758959, 0.00004577638438, 0.00006103517918, 0.00007629397397, 0.00009155276877, 0.00010681156356,
                                            0.00012207035836, 0.00013732915315, 0.00015258794795, 0.00016784674274, 0.00018310553754, 0.00019836433233, 0.00021362312713, 0.00022888192192,
                                            0.00024414071672, 0.00025939951151, 0.00027465830631, 0.00028991710110, 0.00030517589590, 0.00032043469069, 0.00033569348549, 0.00035095228028,
                                            0.00036621107507, 0.00038146986987, 0.00039672866466, 0.00041198745946, 0.00042724625425, 0.00044250504905, 0.00045776384384, 0.00047302263864,
                                            0.00048828143343, 0.00050354022823, 0.00051879902302, 0.00053405781782, 0.00054931661261, 0.00056457540741, 0.00057983420220, 0.00059509299700,
                                            0.00061035179179, 0.00062561058659, 0.00064086938138, 0.00065612817618, 0.00067138697097, 0.00068664576577, 0.00070190456056, 0.00071716335536,
                                            0.00073242215015, 0.01008840232255, 0.02252730911846, 0.02624885109458, 0.02916173248062, 0.03311955547312, 0.03734791091925, 0.03999222641010,
                                            0.04222218607791, 0.04835701212884, 0.05400797333605, 0.05402323213085, 0.05403849092564, 0.05405374972044, 0.05406900851523, 0.05408426731003,
                                            0.05409952610482, 0.05411478489962, 0.07804261683058, 0.08599070449640, 0.09355132788249, 0.11307995878629, 0.14272334781577, 0.14696780486746,
                                            0.15155415561712, 0.23588542779576, 0.25177800974819, 0.25443373585137, 0.25741986663918, 0.27920952034068, 0.28531939527309, 0.29111878590850,
                                            0.29569480405958, 0.30393309956354, 0.30652137140560, 0.31165293578216, 0.31996059003822, 0.32854736819094, 0.33393875348439, 0.33736768005829,
                                            0.34060303129434, 0.34465973101577, 0.34675279926935, 0.34898157312203, 0.34899683191682, 0.34901209071162, 0.34902734950641, 0.34904260830121,
                                            0.34905786709600, 0.34907312589080, 0.36351831756574, 0.36895457109865, 0.38174027165509, 0.39356798058174, 0.41618644719726, 0.43040565778732,
                                            0.43650632713554, 0.44377004919803, 0.45835862650345, 0.46006029736043, 0.46312971941154, 0.47745594736779, 0.48451929607230, 0.49960425624791,
                                            0.51277328543128, 0.52262072227765, 0.52426009373931, 0.54047578581658, 0.55508601486507, 0.58166108925758, 0.59316007258770, 0.59789587851198,
                                            0.60161137381091, 0.60704996630701, 0.61071073444062, 0.61253040207061, 0.61254566086541, 0.61256091966020, 0.61257617845500, 0.61259143724979,
                                            0.61260669604459, 0.61262195483938, 0.61263721363418, 0.61265247242897, 0.61266773122377, 0.61268299001856, 0.61269824881336, 0.61271350760815,
                                            0.61272876640295, 0.61274402519774, 0.61275928399254, 0.61277454278733, 0.61278980158213, 0.61280506037692, 0.61282031917172, 0.61283557796651,
                                            0.61285083676131, 0.61286609555610, 0.61288135435090, 0.61289661314569, 0.61291187194048, 0.61292713073528, 0.61294238953007, 0.61295764832487,
                                            0.61297290711966, 0.61298816591446, 0.61300342470925, 0.61301868350405, 0.61303394229884, 0.61304920109364, 0.61306445988843, 0.61307971868323,
                                            0.61309497747802, 0.61584179901080, 0.61691223400937, 0.61814057515713, 0.61936180468076, 0.62087655448482, 0.62199871781043, 0.62333659495653,
                                            0.62450845471657, 0.62712529719002, 0.62824516401965, 0.62967161142977, 0.63087295649955, 0.63269738045694, 0.63374922788489, 0.63480804320180,
                                            0.63604719062084, 0.63871517994723, 0.63986371867622, 0.64104754765573, 0.64227696355054, 0.64468277012989, 0.64606187640232, 0.64982074378827,
                                            0.65213260963504, 0.65675410036663, 0.65953058034469, 0.66409042175593, 0.66578761722244, 0.66933571658438, 0.67094150955071, 0.67688576890218,
                                            0.68060717367655, 0.69483556045042, 0.70097941241658, 0.70457310522723, 0.71099146523111, 0.71550172127601, 0.71877962465527, 0.72390741598367,
                                            0.73332090655691, 0.73645964162622, 0.73956641522083, 0.74139473309459, 0.74280927661941, 0.74449846538371, 0.74601352879178, 0.74756899484896,
                                            0.74900490264652, 0.75283874425627, 0.75476278648538, 0.75866122398643, 0.76031021590424, 0.76193379283093, 0.76369561685582, 0.76541005727582,
                                            0.76688727913413, 0.77055770039097, 0.77206333281198, 0.77371745346193, 0.77604645319409, 0.77771732225785, 0.77926337366151, 0.78139710263417,
                                            0.78703686883180, 0.79161628109289, 0.79366316462354, 0.79609531393918, 0.79795144783471, 0.80024979277554, 0.80205516855642, 0.80450388008350,
                                            0.80731519297291, 0.83378463508357, 0.84354011735604, 0.84602818291885, 0.85111909964317, 0.85447986634694, 0.85743753430473, 0.86027124374672,
                                            0.86448852178477, 0.87114771006308, 0.87333857376512, 0.87691629890527, 0.87957578825648, 0.88158237040598, 0.88377222142843, 0.88883026199971,
                                            0.89223288177112, 0.89839208073320, 0.90142693447634, 0.90480110775126, 0.90888502568683, 0.91294999018044, 0.91763264675954, 0.92618502647313 };

/* metric assuming even distribution */
double metric_full(const void *element, void *ignored) {
  const char *str = *(const char_ptr *) element;
  const char *str_ptr = str;
  double result = 0.0;
  double factor = 1.0;
  while (*str_ptr != '\000' && factor > 0) {
    result += ((unsigned char) (* str_ptr)) * factor;
    factor /= 256.0;
    str_ptr++;
  }
  return result;
}

/* metric assuming distribution of almost only printable characters (according to what is_string_char() in lib.c understands) */
double metric_binary_printable_pref(const void *element, void *ignored) {
  const char *str = *(const char_ptr *) element;
  const char *str_ptr = str;
  double result = 0.0;
  double factor = 1.0;
  while (*str_ptr != '\000' && factor > 0) {
    size_t c = (unsigned char) (* str_ptr);
    result += factors_printable_pref[c] * factor;
    factor /= 65536.0;
    str_ptr++;
  }
  return result;
}
