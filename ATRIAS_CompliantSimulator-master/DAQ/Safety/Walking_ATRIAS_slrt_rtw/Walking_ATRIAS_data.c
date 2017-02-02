/*
 * Walking_ATRIAS_data.c
 *
 * Code generation for model "Walking_ATRIAS".
 *
 * Model version              : 1.290
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Wed Jul 20 18:48:36 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Walking_ATRIAS.h"
#include "Walking_ATRIAS_private.h"

/* Invariant block signals (auto storage) */
const ConstB_Walking_ATRIAS_T Walking_ATRIAS_ConstB = {
  { 0.0, 0.0, 0.0 }
  ,                                    /* '<S45>/Make3x1' */

  { 0.0, 0.0, 0.0 }
  ,                                    /* '<S45>/Data Type Conversion141' */
  -50.0
  ,                                    /* '<S8>/Gain' */
  0.0
  /* '<S8>/Constant2' */
};

/* Block parameters (auto storage) */
P_Walking_ATRIAS_T Walking_ATRIAS_P = {
  {
    { 265016179.0, 175692059.0, 264841319.0, 261930868.0, 142485911.0,
      142166702.0, 142260475.0, 142165657.0, 7028.0, 1032.0 },

    { 38047.0, 20883.0, 68107.0 },

    { 9.8039216e-9, 9.8039216e-9, 9.8039216e-9, -9.8039216e-9, -9.8039216e-9,
      9.8039216e-9, -9.8039216e-9, 9.8039216e-9, 0.00076699039394282058,
      0.00076699039394282058 },

    { 2.8361600344907854, 3.4470252726888009, 2.8361600344907854,
      3.4470252726888009, 2.8361600344907854, 3.4470252726888009,
      2.8361600344907854, 3.4470252726888009, -0.077000000000000013, -0.0587 },

    { 4294967296.0, 4294967296.0, 4294967296.0, 4294967296.0, 4294967296.0,
      4294967296.0, 4294967296.0, 4294967296.0, 8192.0, 8192.0 },

    { 0.00044879895051282761, -0.00044879895051282761, 0.00044879895051282761,
      -0.00044879895051282761, -9.8890179063846047e-6, -9.8890179063846047e-6 },

    { 65536.0, 65536.0, 65536.0, 65536.0, 65536.0, 65536.0 },

    { -5.0248301886792454e-6, 6.3576763925729441e-6, 2.396844e-5 },

    { 0.0, 0.0, 0.0 },

    { 131072.0, 131072.0, 131072.0 },

    { 65536.0, 65536.0, 65536.0, 65536.0, 65536.0, 65536.0, 131072.0, 131072.0,
      131072.0 },

    { -1.0, -1.0, 19900.0, 60.0, 60.0, -1.0, 1.0, -1.0, 1.0 },

    { 0.0, 0.0, -1.0, 0.70710678118654746, -0.70710678118654746, 0.0,
      -0.70710678118654746, -0.70710678118654746, 0.0 },

    { 0.0, 0.0, -1.0, 0.0, -1.0, 0.0, -1.0, 0.0, 0.0 }
  },

  { 0.35, -0.23, 0.4, -0.3 },

  { 0.0, 0.0 },

  { 5.0, 3.0 },
  0.0,

  { 0.0, 0.0 },
  0.2,
  0.2,
  0.0,
  0.2,
  0.1,
  0.25,

  { 3.2417433982462267, 2.9285764017774873, 0.64659219132093759,
    1.0456271635465242, 3.2133749139399521, 2.8912792281547492,
    0.78847497046484949, 1.090617210697715, 3.1416952160672222,
    2.9464984153260767, 0.814587813360147, 1.7863738823234532,
    3.0513529634458778, 3.1308578355548482, 0.855331189638417,
    1.5012074441249381, 2.9679267464598444, 3.275100120247382,
    0.97577768290612066, 0.65545659062427108, 2.9285998924108085,
    3.242523685276022, 1.0528313471560824, 0.63883817815917532,
    3.1653934508220418, 3.0146493047291019, 0.64654254442323533,
    1.0787513575978043, 3.1491152843554424, 2.9961512366103853,
    0.75463585827326374, 1.1590232176854272, 3.1091466923408708,
    3.0163571664534361, 0.78151348566927781, 1.7504548606330048,
    3.0674968031198295, 3.1068308701599632, 0.83999819533271847,
    1.4656021977649596, 3.0336965461295611, 3.1825778149019057,
    0.9762983122025195, 0.68927868291239824, 3.01463584014677,
    3.1658014567302937, 1.0848612929717956, 0.6396461392784647,
    3.1674161547529587, 3.17358908126033, 0.64648124507115079,
    1.0994723466350238, 3.1642771105293006, 3.1744536526478866,
    0.74572578519952559, 1.1899933399654419, 3.1586242933082929,
    3.1586071617682441, 0.77821451492136862, 1.7511473493963092,
    3.1623214267166952, 3.1590757780883756, 0.84713636132684544,
    1.4593041745079984, 3.1723675773339863, 3.1693054061886681,
    0.98730148298738329, 0.69511498147256967, 3.1735066278489077,
    3.1674942491328721, 1.1052528346302744, 0.6398137463433049,
    3.095842588075072, 3.258474818884765, 0.64651066224156262,
    1.1047881280587626, 3.1051956562222007, 3.2789197512499237,
    0.75827716211735785, 1.1861689557409723, 3.1291269256886318,
    3.2202153647994036, 0.79319230722087375, 1.7706549220552288,
    3.1781360907931995, 3.131296382997875, 0.8604674616889767,
    1.4734674759043411, 3.2364231239082759, 3.0816030383544364,
    1.0009106825533478, 0.6859739753703904, 3.2582609298087757,
    3.095607930909563, 1.1108723457086889, 0.63956628514992553,
    3.0187084227129413, 3.3452978340390116, 0.64652176371420911,
    1.0992126747045172, 3.040026519422784, 3.3837948539944858,
    0.79523008868205269, 1.1473251016402553, 3.0937883882000881,
    3.282205565675222, 0.83643268213856747, 1.8276543478285125,
    3.193438857060094, 3.1009790683091216, 0.89637493385492129,
    1.5173778409978205, 3.3038531570661913, 2.98849146423344, 1.0255497196702896,
    0.64948332187404434, 3.3449946532320087, 3.0181469214824723,
    1.1063419530466929, 0.63868384742058359, 3.2961818386919832,
    2.9926859498540983, 0.700580759590226, 0.6365461738367113,
    3.2610712103071551, 2.9647096273349316, 0.69052364856716764,
    0.58477537905364374, 3.180945942709752, 3.02994956294778,
    0.61269649741443477, 1.602065876638874, 3.0950095396457584,
    3.209051676226383, 0.64338009082627012, 1.6040666836364785,
    3.0210505971859511, 3.3362950401204343, 0.65802487341164628,
    0.872609308763975, 2.9926745566571444, 3.2969491154360959,
    0.64548332542162612, 0.69439611333427576, 3.2291983255921433,
    3.0812600495839275, 0.68893229866835881, 0.65899818698964052,
    3.2094938741271033, 3.0677221188127151, 0.64938521557435314,
    0.66233575541225442, 3.1765835325455467, 3.0932143094835407,
    0.62248590921945457, 1.5865735453333483, 3.1380310816013752,
    3.1843454168816763, 0.66697088945534011, 1.5757686183266486,
    3.0946258529494659, 3.2505734842899159, 0.62718524262610309,
    0.88534437981113168, 3.0811281641602406, 3.2296745582142581,
    0.66646610316892951, 0.683771943869369, 3.1674585457844637,
    3.1676730540107809, 0.68657585249051389, 0.679133996920954,
    3.1649660339380663, 3.1706212930237165, 0.64240838875063888,
    0.701943318361935, 3.1674430709220642, 3.1549475203366431, 0.635283317050525,
    1.5866502166682559, 3.1688871576362194, 3.1571596191078282,
    0.65417727092058309, 1.5581330693436661, 3.16394058745484,
    3.1685805312892183, 0.62794023123295983, 0.8831414190466893,
    3.1674340527244924, 3.1676260149357822, 0.68614358338181392,
    0.68180913298874479, 3.0936007640622369, 3.2418151836203233,
    0.67016541819042041, 0.67355182495420229, 3.1077243995582298,
    3.2609200839973536, 0.63906343508991037, 0.68626799238334457,
    3.1458745832549631, 3.2019944307532184, 0.64417710065029921,
    1.6073786807422576, 3.1893938841686147, 3.1166765168963364,
    0.64814264886202111, 1.5625734711497312, 3.2210623231401563,
    3.0746876215729464, 0.63188050506327065, 0.85266405756713148,
    3.2414272366259329, 3.0934979819406783, 0.68108806402712885,
    0.66509715881851617, 3.0158951870832249, 3.3181359766898755,
    0.6455102310285119, 0.64846857304089056, 3.0457789066010257,
    3.3515669847066434, 0.653773514157704, 0.61703415551188368, 3.11616111063472,
    3.2478459458590621, 0.64017037463799087, 1.6538431311125121,
    3.2070790814514032, 3.0741049122990463, 0.64155975715641156,
    1.5861589672666918, 3.2822079908336868, 2.9777640867003585,
    0.64800031172975248, 0.78255968702804624, 3.317647318708036,
    3.0154938864931538, 0.65751869197642032, 0.63921292287491716,
    3.3201908139702532, 2.9938877910153625, 1.1414746143883407,
    0.64837787239319788, 3.2824508570806126, 2.9812040830820203,
    1.0595130021945636, 0.47465302722957792, 3.1677222775841622,
    3.076449857348809, 0.92933350174683582, 1.638867145801284,
    3.0653860663073331, 3.256452118933201, 0.84057451533437955,
    1.8860539385877049, 3.0053026813512611, 3.3681148279074291,
    0.809831824233133, 1.5040949895027955, 2.9941194259260806,
    3.3206785771306269, 0.65813579165851821, 1.1386479064825414,
    3.2443517463138392, 3.0829150307864044, 1.1193848441162344,
    0.64041514111664344, 3.2256527800994155, 3.0785122461424912,
    1.0144399944722342, 0.51647972917509855, 3.1655955744359865,
    3.1193633901811957, 0.87425567877413557, 1.5733962413602844,
    3.1139875482508197, 3.2077540614089024, 0.77574691762951131,
    1.8225609709277428, 3.0864756107537326, 3.267456765633991, 0.754314564399159,
    1.4968199920203584, 3.0829741009386615, 3.2446099080444553,
    0.64896535017187829, 1.1171710105635355, 3.1735070729047008,
    3.167481695269089, 1.1052587652330406, 0.63799368482137919,
    3.1742009379297373, 3.172705043545351, 0.99379441526703094,
    0.52813661914315269, 3.1623939244978714, 3.1605918828627484,
    0.85379159563471141, 1.5523966776477178, 3.1571889180033237,
    3.162069449357352, 0.75512331155288615, 1.8043462197492062,
    3.1616833888380893, 3.1722656655729118, 0.73692652125524494,
    1.4802143242411705, 3.1673566779259419, 3.1735236528096467,
    0.646371785625249, 1.1030517111310947, 3.0265069881428333, 3.17629709999972,
    1.0935809788497821, 0.6398810987701592, 3.048020083953995,
    3.1932760780595313, 0.99058219091228006, 0.51920619117160616,
    3.0804451874344059, 3.1216664168605126, 0.85399245004379853,
    1.5691246304421314, 3.119212933791597, 3.0336397212209483, 0.763035237178382,
    1.8032249691437352, 3.1588217436310142, 2.9979351026852825,
    0.75052197956242317, 1.4650584785814011, 3.17594096680234,
    3.0262974617682241, 0.64841143639419752, 1.0912752697014259,
    2.952070935419826, 3.264759529495489, 1.0895143088216321, 0.647567903773807,
    2.9936574106228235, 3.2907262061441074, 1.0119955886916556,
    0.47904477784414057, 3.07712224892693, 3.1598016838441452,
    0.89003984701290473, 1.6306677845791215, 3.1646129676519896,
    2.9805795159870838, 0.817528126863245, 1.8476834439040493, 3.23876853601387,
    2.8982962676598145, 0.80386782228790721, 1.4395491999996028,
    3.2641938515163478, 2.9516495131062594, 0.65731284022744652,
    1.0864885389540309 },
  0.0,
  0.16,
  0.0,
  4.0,
  80.0,
  80.0,
  0.0,
  0.087266462599716474,
  100.0,
  1500.0,
  1500.0,
  0.0,
  0.05,
  120.0,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,
  -0.02,
  0.35,

  { 2.9983278361431558, 3.0421868570484154, 3.0828141288380944,
    3.1238332506354043, 3.1605377378073043, 3.192343602973569,
    3.2265814444177057, 3.2636325041983758, 3.3049464322364495,
    3.3344765905737277, 3.2839917833037306, 3.237646196525886,
    3.1979993781066547, 3.1603848280335844, 3.1181505054809593,
    3.0714791964917763, 3.0208197968215824, 2.9663653251740847 },
  0.03,
  180.0,
  0.2,
  0,
  0,
  0,
  0,
  1,
  0
};

/* Constant parameters (auto storage) */
const ConstP_Walking_ATRIAS_T Walking_ATRIAS_ConstP = {
  /* Computed Parameter: EtherCATRxVar4_P1_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar4_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar4_P2_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  2328.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  8.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: type_size)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  32.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_dim)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  1.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  3.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sample_time)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  0.001,

  /* Computed Parameter: EtherCATRxVar4_P1_S_m
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar4_P1_n
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar4_P2_S_g
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  1952.0,

  /* Computed Parameter: EtherCATRxVar4_P1_S_a
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar4_P1_m
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar4_P2_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  1200.0,

  /* Computed Parameter: EtherCATRxVar4_P1_S_c
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar4_P1_e
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar4_P2_S_c
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  1576.0,

  /* Computed Parameter: EtherCATRxVar8_P1_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  { 1.0, 64.0 },

  /* Computed Parameter: EtherCATRxVar8_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar8_P2_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  2280.0,

  /* Computed Parameter: EtherCATRxVar8_P1_S_g
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  { 1.0, 64.0 },

  /* Computed Parameter: EtherCATRxVar8_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar8_P2_S_e
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  1904.0,

  /* Computed Parameter: EtherCATRxVar8_P1_S_j
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  { 1.0, 64.0 },

  /* Computed Parameter: EtherCATRxVar8_P1_d
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar8_P2_S_o
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  1152.0,

  /* Computed Parameter: EtherCATRxVar8_P1_S_l
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  { 1.0, 64.0 },

  /* Computed Parameter: EtherCATRxVar8_P1_m
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar8_P2_S_b
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  1528.0,

  /* Computed Parameter: EtherCATRxVar4_P1_S_e
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  { 1.0, 57.0 },

  /* Computed Parameter: EtherCATRxVar4_P1_em
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 72.0, 105.0, 112.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar4_P2_S_m
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  2640.0,

  /* Computed Parameter: EtherCATRxVar4_P1_S_o
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar4_P1_mc
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 72.0, 105.0, 112.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar4_P2_S_e
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  632.0,

  /* Computed Parameter: EtherCATRxVar_P1_Size
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar_P1
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar_P2_Size
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  2376.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  6.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: type_size)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  16.0,

  /* Computed Parameter: EtherCATRxVar_P1_Si_a
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar_P2_Si_a
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  2000.0,

  /* Computed Parameter: EtherCATRxVar_P1_Si_k
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar_P1_i
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar_P2_Si_b
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  1248.0,

  /* Computed Parameter: EtherCATRxVar_P1_Si_n
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar_P1_p
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar_P2_Si_m
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  1624.0,

  /* Computed Parameter: EtherCATRxVar2_P1_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  { 1.0, 77.0 },

  /* Computed Parameter: EtherCATRxVar2_P1
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0,
    97.0, 108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar2_P2_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  2784.0,

  /* Computed Parameter: EtherCATRxVar2_P1_S_i
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar2_P1_g
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar2_P2_S_m
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  776.0,

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S38>/Unit Delay'
   *   '<S38>/Unit Delay10'
   *   '<S38>/Unit Delay6'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(6,1)
   * Referenced by: '<S38>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: EtherCATRxVar6_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  { 1.0, 47.0 },

  /* Computed Parameter: EtherCATRxVar6_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 82.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 46.0, 88.0 },

  /* Computed Parameter: EtherCATRxVar6_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  840.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   */
  2.0,

  /* Computed Parameter: EtherCATRxVar1_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  { 1.0, 47.0 },

  /* Computed Parameter: EtherCATRxVar1_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 82.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 46.0, 89.0 },

  /* Computed Parameter: EtherCATRxVar1_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  872.0,

  /* Computed Parameter: EtherCATRxVar2_P1_S_n
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  { 1.0, 47.0 },

  /* Computed Parameter: EtherCATRxVar2_P1_e
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 82.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 46.0, 90.0 },

  /* Computed Parameter: EtherCATRxVar2_P2_S_e
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  904.0,

  /* Computed Parameter: EtherCATRxVar9_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  { 1.0, 51.0 },

  /* Computed Parameter: EtherCATRxVar9_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 65.0, 99.0, 99.0, 101.0, 108.0, 101.0, 114.0, 97.0, 116.0, 105.0,
    111.0, 110.0, 46.0, 88.0 },

  /* Computed Parameter: EtherCATRxVar9_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  936.0,

  /* Computed Parameter: EtherCATRxVar11_P1_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  { 1.0, 51.0 },

  /* Computed Parameter: EtherCATRxVar11_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 65.0, 99.0, 99.0, 101.0, 108.0, 101.0, 114.0, 97.0, 116.0, 105.0,
    111.0, 110.0, 46.0, 89.0 },

  /* Computed Parameter: EtherCATRxVar11_P2_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  968.0,

  /* Computed Parameter: EtherCATRxVar12_P1_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  { 1.0, 51.0 },

  /* Computed Parameter: EtherCATRxVar12_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 65.0, 99.0, 99.0, 101.0, 108.0, 101.0, 114.0, 97.0, 116.0, 105.0,
    111.0, 110.0, 46.0, 90.0 },

  /* Computed Parameter: EtherCATRxVar12_P2_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  1000.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  { 1.0, 50.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0, 116.0, 97.0, 116.0,
    117.0, 115.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  1032.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  4.0,

  /* Computed Parameter: EtherCATRxVar5_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  { 1.0, 52.0 },

  /* Computed Parameter: EtherCATRxVar5_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0, 101.0, 113.0,
    117.0, 101.0, 110.0, 99.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar5_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  1040.0,

  /* Expression: [1 0; 1 0; 0 1; 1 0; 1 0; 0 1]
   * Referenced by: '<S20>/Gain1'
   */
  { 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 },

  /* Expression: [2*pi*ones(8,1); zeros(5,1)]
   * Referenced by: '<S28>/Constant'
   */
  { 6.2831853071795862, 6.2831853071795862, 6.2831853071795862,
    6.2831853071795862, 6.2831853071795862, 6.2831853071795862,
    6.2831853071795862, 6.2831853071795862, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1./[50 50 26.7 50 50 26.7]
   * Referenced by: '<S2>/Gain2'
   */
  { 0.02, 0.02, 0.037453183520599252, 0.02, 0.02, 0.037453183520599252 },

  /* Expression: [10; 10; 5.5; 10; 10; 5.5]
   * Referenced by: '<S8>/TorqueToCurrent'
   */
  { 10.0, 10.0, 5.5, 10.0, 10.0, 5.5 },

  /* Computed Parameter: EtherCATRxVar6_P1_S_m
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar6_P1_i
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    49.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar6_P2_S_k
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  2536.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var '
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var '
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  5.0,

  /* Computed Parameter: EtherCATRxVar7_P1_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar7_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    50.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar7_P2_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  2552.0,

  /* Computed Parameter: EtherCATRxVar6_P1_S_c
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar6_P1_a
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    49.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar6_P2_S_c
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  2160.0,

  /* Computed Parameter: EtherCATRxVar7_P1_S_l
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar7_P1_d
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    50.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar7_P2_S_b
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  2176.0,

  /* Computed Parameter: EtherCATRxVar_P1_Si_g
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  { 1.0, 75.0 },

  /* Computed Parameter: EtherCATRxVar_P1_f
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0, 117.0,
    114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar_P2_Si_i
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  2768.0,

  /* Computed Parameter: EtherCATRxVar6_P1_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar6_P1_ik
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    49.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar6_P2_S_d
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  1408.0,

  /* Computed Parameter: EtherCATRxVar7_P1_S_k
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar7_P1_b
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    50.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar7_P2__b3
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  1424.0,

  /* Computed Parameter: EtherCATRxVar6_P1_S_h
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar6_P1_b
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    49.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar6_P2_S_p
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  1784.0,

  /* Computed Parameter: EtherCATRxVar7_P1_S_o
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  { 1.0, 76.0 },

  /* Computed Parameter: EtherCATRxVar7_P1_h
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    50.0, 32.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar7_P2_S_k
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  1800.0,

  /* Computed Parameter: EtherCATRxVar_P1_Si_p
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  { 1.0, 74.0 },

  /* Computed Parameter: EtherCATRxVar_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0,
    117.0, 114.0, 114.0, 101.0, 110.0, 116.0, 46.0, 65.0, 109.0, 112.0, 32.0,
    77.0, 101.0, 97.0, 115.0, 117.0, 114.0, 101.0, 100.0, 32.0, 67.0, 117.0,
    114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar_P2_Si_p
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  760.0,

  /* Computed Parameter: EtherCATRxVar10_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar10_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 76.0, 111.0, 103.0, 105.0,
    99.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar10_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  2424.0,

  /* Computed Parameter: EtherCATRxVar10_P1__g
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar10_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 76.0, 111.0, 103.0, 105.0,
    99.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar10_P2__l
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  2048.0,

  /* Computed Parameter: EtherCATRxVar6_P1_S_a
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  { 1.0, 57.0 },

  /* Computed Parameter: EtherCATRxVar6_P1_j
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 76.0, 111.0, 103.0,
    105.0, 99.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar6_P2_S_m
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  2704.0,

  /* Computed Parameter: EtherCATRxVar10_P1__e
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar10_P1_m
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 76.0, 111.0, 103.0, 105.0,
    99.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar10_P2__e
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  1296.0,

  /* Computed Parameter: EtherCATRxVar10_P1__k
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar10_P1_c
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 76.0, 111.0, 103.0, 105.0,
    99.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar10_P2__g
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  1672.0,

  /* Computed Parameter: EtherCATRxVar6_P1_S_p
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar6_P1_h
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 76.0, 111.0, 103.0, 105.0,
    99.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar6_P2_S_g
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  696.0,

  /* Computed Parameter: EtherCATRxVar11_P1__c
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar11_P1_g
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar11_P2__p
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  2408.0,

  /* Computed Parameter: EtherCATRxVar11_P1__e
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar11_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar11_P2__k
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  2032.0,

  /* Computed Parameter: EtherCATRxVar1_P1_S_c
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  { 1.0, 57.0 },

  /* Computed Parameter: EtherCATRxVar1_P1_k
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0,
    111.0, 114.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar1_P2_S_h
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  2688.0,

  /* Computed Parameter: EtherCATRxVar11_P1__m
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar11_P1_e
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar11_P2__j
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  1280.0,

  /* Computed Parameter: EtherCATRxVar11_P1_en
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar11_P1_a
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar11_P2_po
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  1656.0,

  /* Computed Parameter: EtherCATRxVar1_P1_S_e
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  { 1.0, 56.0 },

  /* Computed Parameter: EtherCATRxVar1_P1_e
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 80.0, 111.0, 119.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 86.0, 111.0, 108.0, 116.0, 97.0, 103.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar1_P2_S_i
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  680.0,

  /* Computed Parameter: EtherCATRxVar12_P1__k
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar12_P1_g
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 48.0 },

  /* Computed Parameter: EtherCATRxVar12_P2__o
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  2440.0,

  /* Computed Parameter: EtherCATRxVar13_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar13_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 49.0 },

  /* Computed Parameter: EtherCATRxVar13_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  2456.0,

  /* Computed Parameter: EtherCATRxVar14_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar14_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 50.0 },

  /* Computed Parameter: EtherCATRxVar14_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  2472.0,

  /* Computed Parameter: EtherCATRxVar15_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar15_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 51.0 },

  /* Computed Parameter: EtherCATRxVar15_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  2488.0,

  /* Computed Parameter: EtherCATRxVar16_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar16_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 52.0 },

  /* Computed Parameter: EtherCATRxVar16_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  2504.0,

  /* Computed Parameter: EtherCATRxVar17_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar17_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 53.0 },

  /* Computed Parameter: EtherCATRxVar17_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  2520.0,

  /* Computed Parameter: EtherCATRxVar12_P1__n
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar12_P1_p
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 48.0 },

  /* Computed Parameter: EtherCATRxVar12_P2__k
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  2064.0,

  /* Computed Parameter: EtherCATRxVar13_P1__o
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar13_P1_n
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 49.0 },

  /* Computed Parameter: EtherCATRxVar13_P2__k
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  2080.0,

  /* Computed Parameter: EtherCATRxVar14_P1__j
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar14_P1_c
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 50.0 },

  /* Computed Parameter: EtherCATRxVar14_P2__c
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  2096.0,

  /* Computed Parameter: EtherCATRxVar15_P1__b
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar15_P1_a
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 51.0 },

  /* Computed Parameter: EtherCATRxVar15_P2__m
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  2112.0,

  /* Computed Parameter: EtherCATRxVar16_P1__b
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar16_P1_h
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 52.0 },

  /* Computed Parameter: EtherCATRxVar16_P2__h
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  2128.0,

  /* Computed Parameter: EtherCATRxVar17_P1__m
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar17_P1_d
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 53.0 },

  /* Computed Parameter: EtherCATRxVar17_P2__n
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  2144.0,

  /* Computed Parameter: EtherCATRxVar12_P1__p
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  { 1.0, 62.0 },

  /* Computed Parameter: EtherCATRxVar12_P1_l
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0,
    111.0, 114.0, 32.0, 48.0 },

  /* Computed Parameter: EtherCATRxVar12_P2_kk
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  2720.0,

  /* Computed Parameter: EtherCATRxVar13_P1__e
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  { 1.0, 62.0 },

  /* Computed Parameter: EtherCATRxVar13_P1_j
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0,
    111.0, 114.0, 32.0, 49.0 },

  /* Computed Parameter: EtherCATRxVar13_P2__f
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  2736.0,

  /* Computed Parameter: EtherCATRxVar14_P1__b
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  { 1.0, 62.0 },

  /* Computed Parameter: EtherCATRxVar14_P1_n
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0,
    111.0, 114.0, 32.0, 50.0 },

  /* Computed Parameter: EtherCATRxVar14_P2_ce
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  2752.0,

  /* Computed Parameter: EtherCATRxVar12_P1_pv
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar12_P1_k
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 48.0 },

  /* Computed Parameter: EtherCATRxVar12_P2__c
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  1312.0,

  /* Computed Parameter: EtherCATRxVar13_P1__g
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar13_P_jx
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 49.0 },

  /* Computed Parameter: EtherCATRxVar13_P2__h
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  1328.0,

  /* Computed Parameter: EtherCATRxVar14_P1__p
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar14_P1_p
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 50.0 },

  /* Computed Parameter: EtherCATRxVar14_P2__b
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  1344.0,

  /* Computed Parameter: EtherCATRxVar15_P1_bc
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar15_P1_c
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 51.0 },

  /* Computed Parameter: EtherCATRxVar15_P2__n
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  1360.0,

  /* Computed Parameter: EtherCATRxVar16_P1__c
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar16_P1_a
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 52.0 },

  /* Computed Parameter: EtherCATRxVar16_P2__e
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  1376.0,

  /* Computed Parameter: EtherCATRxVar17_P1__j
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar17_P1_k
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 53.0 },

  /* Computed Parameter: EtherCATRxVar17_P2__m
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  1392.0,

  /* Computed Parameter: EtherCATRxVar12_P1__o
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar12_P_pi
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 48.0 },

  /* Computed Parameter: EtherCATRxVar12_P2_kj
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  1688.0,

  /* Computed Parameter: EtherCATRxVar13_P1__h
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar13_P1_o
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 49.0 },

  /* Computed Parameter: EtherCATRxVar13_P2__n
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  1704.0,

  /* Computed Parameter: EtherCATRxVar14_P1__c
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar14_P1_g
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 50.0 },

  /* Computed Parameter: EtherCATRxVar14_P2_ck
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  1720.0,

  /* Computed Parameter: EtherCATRxVar15_P1__j
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar15_P1_d
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 51.0 },

  /* Computed Parameter: EtherCATRxVar15_P2__l
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  1736.0,

  /* Computed Parameter: EtherCATRxVar16_P1_c1
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar16_P1_o
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 52.0 },

  /* Computed Parameter: EtherCATRxVar16_P2__p
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  1752.0,

  /* Computed Parameter: EtherCATRxVar17_P1__l
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar17_P1_c
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 53.0 },

  /* Computed Parameter: EtherCATRxVar17_P2__h
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  1768.0,

  /* Computed Parameter: EtherCATRxVar12_P1_pu
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar12_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 48.0 },

  /* Computed Parameter: EtherCATRxVar12_P2__n
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  712.0,

  /* Computed Parameter: EtherCATRxVar13_P1__f
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar13_P1_d
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 49.0 },

  /* Computed Parameter: EtherCATRxVar13_P2_fq
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  728.0,

  /* Computed Parameter: EtherCATRxVar14_P1__f
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar14_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0, 114.0,
    115.0, 46.0, 84.0, 104.0, 101.0, 114.0, 109.0, 105.0, 115.0, 116.0, 111.0,
    114.0, 32.0, 50.0 },

  /* Computed Parameter: EtherCATRxVar14_P2__d
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  744.0,

  /* Computed Parameter: EtherCATRxVar5_P1_S_l
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  { 1.0, 70.0 },

  /* Computed Parameter: EtherCATRxVar5_P1_p
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0, 115.0, 116.0, 97.0, 109.0,
    112.0 },

  /* Computed Parameter: EtherCATRxVar5_P2_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  1232.0,

  /* Computed Parameter: EtherCATRxVar19_P1_Si
   * Referenced by: '<S60>/EtherCAT Rx Var 19'
   */
  { 1.0, 62.0 },

  /* Computed Parameter: EtherCATRxVar19_P1
   * Referenced by: '<S60>/EtherCAT Rx Var 19'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0,
    116.0, 97.0, 116.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 4'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 4'
   */
  2608.0,

  /* Computed Parameter: EtherCATRxVar16_P1__p
   * Referenced by: '<S60>/EtherCAT Rx Var 16'
   */
  { 1.0, 68.0 },

  /* Computed Parameter: EtherCATRxVar16_P1_b
   * Referenced by: '<S60>/EtherCAT Rx Var 16'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 69.0,
    114.0, 114.0, 111.0, 114.0, 32.0, 70.0, 108.0, 97.0, 103.0, 115.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Tx Var 5'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Tx Var 5'
   */
  2624.0,

  /* Computed Parameter: EtherCATRxVar15_P1__l
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  { 1.0, 64.0 },

  /* Computed Parameter: EtherCATRxVar15_P_av
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 67.0,
    111.0, 117.0, 110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar15_P2__b
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  2616.0,

  /* Computed Parameter: EtherCATRxVar5_P1__lt
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  { 1.0, 87.0 },

  /* Computed Parameter: EtherCATRxVar5_P1_g
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0,
    97.0, 108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0,
    101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar5_P2_S_c
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  2800.0,

  /* Computed Parameter: EtherCATRxVar3_P1_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  { 1.0, 59.0 },

  /* Computed Parameter: EtherCATRxVar3_P1
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 72.0, 105.0, 112.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 84.0, 105.0, 109.0, 101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar3_P2_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  2672.0,

  /* Computed Parameter: EtherCATRxVar9_P1_S_i
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  { 1.0, 74.0 },

  /* Computed Parameter: EtherCATRxVar9_P1_j
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0,
    115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar9_P2_S_d
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  1184.0,

  /* Computed Parameter: EtherCATRxVar17_P1__n
   * Referenced by: '<S60>/EtherCAT Rx Var 17'
   */
  { 1.0, 59.0 },

  /* Computed Parameter: EtherCATRxVar17_P1_g
   * Referenced by: '<S60>/EtherCAT Rx Var 17'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 73.0, 68.0
  },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Tx Var 3'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Tx Var 3'
   */
  2600.0,

  /* Computed Parameter: EtherCATRxVar18_P1_Si
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  { 1.0, 68.0 },

  /* Computed Parameter: EtherCATRxVar18_P1
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 76.0, 105.0,
    109.0, 105.0, 116.0, 32.0, 83.0, 119.0, 105.0, 116.0, 99.0, 104.0 },

  /* Computed Parameter: EtherCATRxVar18_P2_Si
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  624.0,

  /* Computed Parameter: EtherCATRxVar1_P1_S_j
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  { 1.0, 86.0 },

  /* Computed Parameter: EtherCATRxVar1_P1_j
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0,
    101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar1_P2_S_e
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  1264.0,

  /* Computed Parameter: EtherCATRxVar19_P1__h
   * Referenced by: '<S59>/EtherCAT Rx Var 19'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar19_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 19'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0, 116.0, 97.0,
    116.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 4'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 4'
   */
  600.0,

  /* Computed Parameter: EtherCATRxVar16_P1__l
   * Referenced by: '<S59>/EtherCAT Rx Var 16'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATRxVar16_P_hj
   * Referenced by: '<S59>/EtherCAT Rx Var 16'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 69.0, 114.0,
    114.0, 111.0, 114.0, 32.0, 70.0, 108.0, 97.0, 103.0, 115.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Tx Var 5'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Tx Var 5'
   */
  616.0,

  /* Computed Parameter: EtherCATRxVar15_P1__o
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  { 1.0, 63.0 },

  /* Computed Parameter: EtherCATRxVar15_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 67.0, 111.0,
    117.0, 110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar15_P2_bp
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  608.0,

  /* Computed Parameter: EtherCATRxVar5_P1_S_g
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  { 1.0, 86.0 },

  /* Computed Parameter: EtherCATRxVar5_P1_k
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0,
    101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar5_P2_S_b
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  792.0,

  /* Computed Parameter: EtherCATRxVar3_P1_S_i
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  { 1.0, 58.0 },

  /* Computed Parameter: EtherCATRxVar3_P1_n
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 72.0, 105.0, 112.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 84.0, 105.0, 109.0, 101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar3_P2_S_b
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  664.0,

  /* Computed Parameter: EtherCATRxVar17_P1_nw
   * Referenced by: '<S59>/EtherCAT Rx Var 17'
   */
  { 1.0, 58.0 },

  /* Computed Parameter: EtherCATRxVar17_P_ky
   * Referenced by: '<S59>/EtherCAT Rx Var 17'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 73.0, 68.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Tx Var 3'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Tx Var 3'
   */
  592.0,

  /* Computed Parameter: EtherCATRxVar18_P1__e
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  { 1.0, 69.0 },

  /* Computed Parameter: EtherCATRxVar18_P1_p
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 76.0,
    105.0, 109.0, 105.0, 116.0, 32.0, 83.0, 119.0, 105.0, 116.0, 99.0, 104.0 },

  /* Computed Parameter: EtherCATRxVar18_P2__a
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  2632.0,

  /* Computed Parameter: EtherCATRxVar16_P1__k
   * Referenced by: '<S61>/EtherCAT Rx Var 16'
   */
  { 1.0, 58.0 },

  /* Computed Parameter: EtherCATRxVar16_P1_m
   * Referenced by: '<S61>/EtherCAT Rx Var 16'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 73.0, 68.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Tx Var '
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Tx Var '
   */
  808.0,

  /* Computed Parameter: EtherCATRxVar17_P1__b
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  { 1.0, 63.0 },

  /* Computed Parameter: EtherCATRxVar17_P1_p
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 67.0, 111.0,
    117.0, 110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar17_P2__p
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  824.0,

  /* Computed Parameter: EtherCATRxVar15_P1__d
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATRxVar15_P1_i
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 69.0, 114.0,
    114.0, 111.0, 114.0, 32.0, 70.0, 108.0, 97.0, 103.0, 115.0 },

  /* Computed Parameter: EtherCATRxVar15_P2__c
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  832.0,

  /* Computed Parameter: EtherCATRxVar23_P1_Si
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  { 1.0, 66.0 },

  /* Computed Parameter: EtherCATRxVar23_P1
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 84.0, 111.0,
    101.0, 32.0, 83.0, 101.0, 110.0, 115.0, 111.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar23_P2_Si
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  1136.0,

  /* Computed Parameter: EtherCATRxVar2_P1_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar2_P1_l
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 49.0
  },

  /* Computed Parameter: EtherCATRxVar2_P2_S_g
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  1440.0,

  /* Computed Parameter: EtherCATRxVar3_P1_S_k
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar3_P1_e
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 50.0
  },

  /* Computed Parameter: EtherCATRxVar3_P2_S_p
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  1456.0,

  /* Computed Parameter: EtherCATRxVar23_P1__d
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  { 1.0, 66.0 },

  /* Computed Parameter: EtherCATRxVar23_P1_g
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 84.0, 111.0,
    101.0, 32.0, 83.0, 101.0, 110.0, 115.0, 111.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar23_P2__o
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  1512.0,

  /* Computed Parameter: EtherCATRxVar21_P1_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  { 1.0, 68.0 },

  /* Computed Parameter: EtherCATRxVar21_P1
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 76.0, 105.0,
    109.0, 105.0, 116.0, 32.0, 83.0, 119.0, 105.0, 116.0, 99.0, 104.0 },

  /* Computed Parameter: EtherCATRxVar21_P2_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  1504.0,

  /* Computed Parameter: EtherCATRxVar20_P1_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 20'
   */
  { 1.0, 58.0 },

  /* Computed Parameter: EtherCATRxVar20_P1
   * Referenced by: '<S68>/EtherCAT Rx Var 20'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 73.0, 68.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Tx Var 3'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Tx Var 3'
   */
  1472.0,

  /* Computed Parameter: EtherCATRxVar22_P1_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 22'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar22_P1
   * Referenced by: '<S68>/EtherCAT Rx Var 22'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0, 116.0, 97.0,
    116.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 4'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 4'
   */
  1480.0,

  /* Computed Parameter: EtherCATRxVar18_P1__d
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  { 1.0, 63.0 },

  /* Computed Parameter: EtherCATRxVar18_P1_k
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 67.0, 111.0,
    117.0, 110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar18_P2__b
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  1488.0,

  /* Computed Parameter: EtherCATRxVar19_P1_hi
   * Referenced by: '<S68>/EtherCAT Rx Var 19'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATRxVar19_P1_k
   * Referenced by: '<S68>/EtherCAT Rx Var 19'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 69.0, 114.0,
    114.0, 111.0, 114.0, 32.0, 70.0, 108.0, 97.0, 103.0, 115.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Tx Var 5'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Tx Var 5'
   */
  1496.0,

  /* Computed Parameter: EtherCATRxVar5_P1_S_k
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  { 1.0, 70.0 },

  /* Computed Parameter: EtherCATRxVar5_P1_a
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0, 115.0, 116.0, 97.0, 109.0,
    112.0 },

  /* Computed Parameter: EtherCATRxVar5_P2_S_a
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  1608.0,

  /* Computed Parameter: EtherCATRxVar9_P1_S_a
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  { 1.0, 74.0 },

  /* Computed Parameter: EtherCATRxVar9_P1_l
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0,
    115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar9_P2_S_h
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  1560.0,

  /* Computed Parameter: EtherCATRxVar1_P1_S_i
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  { 1.0, 86.0 },

  /* Computed Parameter: EtherCATRxVar1_P1_d
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0,
    101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar1_P2_S_g
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  1640.0,

  /* Computed Parameter: EtherCATRxVar21_P1__p
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  { 1.0, 68.0 },

  /* Computed Parameter: EtherCATRxVar21_P1_p
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 76.0, 105.0,
    109.0, 105.0, 116.0, 32.0, 83.0, 119.0, 105.0, 116.0, 99.0, 104.0 },

  /* Computed Parameter: EtherCATRxVar21_P2__h
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  1128.0,

  /* Computed Parameter: EtherCATRxVar2_P1_S_m
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar2_P1_c
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 49.0
  },

  /* Computed Parameter: EtherCATRxVar2_P2_S_d
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  1816.0,

  /* Computed Parameter: EtherCATRxVar3_P1__kr
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar3_P1_h
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 50.0
  },

  /* Computed Parameter: EtherCATRxVar3_P2_S_i
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  1832.0,

  /* Computed Parameter: EtherCATRxVar20_P1__b
   * Referenced by: '<S66>/EtherCAT Rx Var 20'
   */
  { 1.0, 58.0 },

  /* Computed Parameter: EtherCATRxVar20_P1_n
   * Referenced by: '<S66>/EtherCAT Rx Var 20'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 73.0, 68.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Tx Var 3'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Tx Var 3'
   */
  1096.0,

  /* Computed Parameter: EtherCATRxVar23_P1__l
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  { 1.0, 66.0 },

  /* Computed Parameter: EtherCATRxVar23_P1_c
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 84.0, 111.0,
    101.0, 32.0, 83.0, 101.0, 110.0, 115.0, 111.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar23_P2__a
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  2264.0,

  /* Computed Parameter: EtherCATRxVar21_P1__i
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  { 1.0, 68.0 },

  /* Computed Parameter: EtherCATRxVar21_P1_n
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 76.0, 105.0,
    109.0, 105.0, 116.0, 32.0, 83.0, 119.0, 105.0, 116.0, 99.0, 104.0 },

  /* Computed Parameter: EtherCATRxVar21_P2__n
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  2256.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   */
  { 1.0, 61.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0, 116.0, 97.0,
    116.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 4'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 4'
   */
  2232.0,

  /* Computed Parameter: EtherCATRxVar18_P1__g
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  { 1.0, 63.0 },

  /* Computed Parameter: EtherCATRxVar18_P1_o
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 67.0, 111.0,
    117.0, 110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar18_P2__h
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  2240.0,

  /* Computed Parameter: EtherCATRxVar19_P1__e
   * Referenced by: '<S67>/EtherCAT Rx Var 19'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATRxVar19_P1_i
   * Referenced by: '<S67>/EtherCAT Rx Var 19'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 69.0, 114.0,
    114.0, 111.0, 114.0, 32.0, 70.0, 108.0, 97.0, 103.0, 115.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Tx Var 5'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Tx Var 5'
   */
  2248.0,

  /* Computed Parameter: EtherCATRxVar5_P1_S_h
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  { 1.0, 70.0 },

  /* Computed Parameter: EtherCATRxVar5_P1_d
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0, 115.0, 116.0, 97.0, 109.0,
    112.0 },

  /* Computed Parameter: EtherCATRxVar5_P2_S_g
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  2360.0,

  /* Computed Parameter: EtherCATRxVar9_P1_S_l
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  { 1.0, 74.0 },

  /* Computed Parameter: EtherCATRxVar9_P1_p
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0,
    115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar9_P2_S_a
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  2312.0,

  /* Computed Parameter: EtherCATRxVar22_P1__f
   * Referenced by: '<S66>/EtherCAT Rx Var 22'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar22_P1_d
   * Referenced by: '<S66>/EtherCAT Rx Var 22'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0, 116.0, 97.0,
    116.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 4'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 4'
   */
  1104.0,

  /* Computed Parameter: EtherCATRxVar1_P1__c1
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  { 1.0, 86.0 },

  /* Computed Parameter: EtherCATRxVar1_P1_g
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0,
    101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar1_P2_S_o
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  2392.0,

  /* Computed Parameter: EtherCATRxVar18_P1__k
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  { 1.0, 63.0 },

  /* Computed Parameter: EtherCATRxVar18_P1_i
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 67.0, 111.0,
    117.0, 110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar18_P2__p
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  1112.0,

  /* Computed Parameter: EtherCATRxVar2_P1_S_a
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar2_P1_d
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 49.0
  },

  /* Computed Parameter: EtherCATRxVar2_P2__en
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  2568.0,

  /* Computed Parameter: EtherCATRxVar3_P1__kp
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar3_P1_m
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 50.0
  },

  /* Computed Parameter: EtherCATRxVar3_P2_S_h
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  2584.0,

  /* Computed Parameter: EtherCATRxVar23_P1__o
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  { 1.0, 66.0 },

  /* Computed Parameter: EtherCATRxVar23_P1_j
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 84.0, 111.0,
    101.0, 32.0, 83.0, 101.0, 110.0, 115.0, 111.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar23_P2__i
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  1888.0,

  /* Computed Parameter: EtherCATRxVar21_P1_if
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  { 1.0, 68.0 },

  /* Computed Parameter: EtherCATRxVar21_P1_m
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 76.0, 105.0,
    109.0, 105.0, 116.0, 32.0, 83.0, 119.0, 105.0, 116.0, 99.0, 104.0 },

  /* Computed Parameter: EtherCATRxVar21_P2__d
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  1880.0,

  /* Computed Parameter: EtherCATRxVar20_P1__a
   * Referenced by: '<S69>/EtherCAT Rx Var 20'
   */
  { 1.0, 58.0 },

  /* Computed Parameter: EtherCATRxVar20_P1_k
   * Referenced by: '<S69>/EtherCAT Rx Var 20'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 73.0, 68.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  1848.0,

  /* Computed Parameter: EtherCATRxVar22_P1__d
   * Referenced by: '<S69>/EtherCAT Rx Var 22'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATRxVar22_P1_a
   * Referenced by: '<S69>/EtherCAT Rx Var 22'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 83.0, 116.0, 97.0,
    116.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 4'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 4'
   */
  1856.0,

  /* Computed Parameter: EtherCATRxVar18_P1__f
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  { 1.0, 63.0 },

  /* Computed Parameter: EtherCATRxVar18_P1_b
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 67.0, 111.0,
    117.0, 110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATRxVar18_P2__f
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  1864.0,

  /* Computed Parameter: EtherCATRxVar19_P1__f
   * Referenced by: '<S66>/EtherCAT Rx Var 19'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATRxVar19_P1_e
   * Referenced by: '<S66>/EtherCAT Rx Var 19'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 69.0, 114.0,
    114.0, 111.0, 114.0, 32.0, 70.0, 108.0, 97.0, 103.0, 115.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Tx Var 5'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Tx Var 5'
   */
  1120.0,

  /* Computed Parameter: EtherCATRxVar19_P1__i
   * Referenced by: '<S69>/EtherCAT Rx Var 19'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATRxVar19_P1_n
   * Referenced by: '<S69>/EtherCAT Rx Var 19'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 32.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 69.0, 114.0,
    114.0, 111.0, 114.0, 32.0, 70.0, 108.0, 97.0, 103.0, 115.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Tx Var 5'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Tx Var 5'
   */
  1872.0,

  /* Computed Parameter: EtherCATRxVar5_P1__ko
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  { 1.0, 70.0 },

  /* Computed Parameter: EtherCATRxVar5_P1_kn
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0,
    114.0, 46.0, 76.0, 101.0, 103.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0,
    101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0, 115.0, 116.0, 97.0, 109.0,
    112.0 },

  /* Computed Parameter: EtherCATRxVar5_P2__gf
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  1984.0,

  /* Computed Parameter: EtherCATRxVar9_P1_S_m
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  { 1.0, 74.0 },

  /* Computed Parameter: EtherCATRxVar9_P1_d
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0, 110.0, 99.0, 111.0,
    100.0, 101.0, 114.0, 46.0, 77.0, 111.0, 116.0, 111.0, 114.0, 32.0, 69.0,
    110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0, 101.0,
    115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar9_P2__db
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  1936.0,

  /* Computed Parameter: EtherCATRxVar1_P1_S_f
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  { 1.0, 86.0 },

  /* Computed Parameter: EtherCATRxVar1_P1_i
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 73.0, 110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0,
    108.0, 32.0, 69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 46.0, 73.0,
    110.0, 99.0, 114.0, 101.0, 109.0, 101.0, 110.0, 116.0, 97.0, 108.0, 32.0,
    69.0, 110.0, 99.0, 111.0, 100.0, 101.0, 114.0, 32.0, 84.0, 105.0, 109.0,
    101.0, 115.0, 116.0, 97.0, 109.0, 112.0 },

  /* Computed Parameter: EtherCATRxVar1_P2_S_j
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  2016.0,

  /* Computed Parameter: EtherCATRxVar2_P1_S_k
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar2_P1_i
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 49.0
  },

  /* Computed Parameter: EtherCATRxVar2_P2_S_c
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  2192.0,

  /* Computed Parameter: EtherCATRxVar3_P1_S_d
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  { 1.0, 60.0 },

  /* Computed Parameter: EtherCATRxVar3_P1_h3
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 46.0,
    75.0, 110.0, 101.0, 101.0, 32.0, 70.0, 111.0, 114.0, 99.0, 101.0, 32.0, 50.0
  },

  /* Computed Parameter: EtherCATRxVar3_P2__it
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  2208.0,

  /* Computed Parameter: EtherCATTxVar3_P1_Siz
   * Referenced by: '<S59>/EtherCAT Tx Var 3'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar3_P1
   * Referenced by: '<S59>/EtherCAT Tx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 109.0, 109.0,
    97.0, 110.0, 100.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_Siz
   * Referenced by: '<S59>/EtherCAT Tx Var 4'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar4_P1
   * Referenced by: '<S59>/EtherCAT Tx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 117.0, 110.0,
    116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_Siz
   * Referenced by: '<S59>/EtherCAT Tx Var 5'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATTxVar5_P1
   * Referenced by: '<S59>/EtherCAT Tx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 67.0, 117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  7.0,

  /* Computed Parameter: EtherCATTxVar3_P1_S_d
   * Referenced by: '<S60>/EtherCAT Tx Var 3'
   */
  { 1.0, 62.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_g
   * Referenced by: '<S60>/EtherCAT Tx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 109.0,
    109.0, 97.0, 110.0, 100.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_S_k
   * Referenced by: '<S60>/EtherCAT Tx Var 4'
   */
  { 1.0, 62.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_h
   * Referenced by: '<S60>/EtherCAT Tx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 117.0,
    110.0, 116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_S_i
   * Referenced by: '<S60>/EtherCAT Tx Var 5'
   */
  { 1.0, 68.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_e
   * Referenced by: '<S60>/EtherCAT Tx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 49.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0,
    65.0, 83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 72.0, 105.0, 112.0, 32.0, 40.0,
    77.0, 101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0,
    41.0, 46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0,
    101.0, 114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 77.0, 111.0, 116.0,
    111.0, 114.0, 32.0, 67.0, 117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATRxVar4_P1_S_h
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  { 1.0, 55.0 },

  /* Computed Parameter: EtherCATRxVar4_P1_f
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 46.0, 84.0, 101.0, 109.0,
    112.0, 101.0, 114.0, 97.0, 116.0, 117.0, 114.0, 101.0 },

  /* Computed Parameter: EtherCATRxVar4_P2_S_b
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  1048.0,

  /* Computed Parameter: EtherCATTxVar_P1_Size
   * Referenced by: '<S61>/EtherCAT Tx Var '
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar_P1
   * Referenced by: '<S61>/EtherCAT Tx Var '
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 109.0, 109.0,
    97.0, 110.0, 100.0 },

  /* Computed Parameter: EtherCATTxVar1_P1_Siz
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar1_P1
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  { 66.0, 111.0, 120.0, 32.0, 52.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 73.0, 77.0, 85.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 117.0, 110.0,
    116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATTxVar1_P2_Siz
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  816.0,

  /* Computed Parameter: EtherCATPDOReceive5_P
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  { 1.0, 37.0 },

  /* Computed Parameter: EtherCATPDOReceive5_
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  { 66.0, 111.0, 120.0, 32.0, 51.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 32.0, 119.0,
    111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOReceive5_a
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  3040.0,

  /* Computed Parameter: EtherCATPDOReceive_P1
   * Referenced by: '<S71>/EtherCAT PDO Receive'
   */
  { 1.0, 45.0 },

  /* Computed Parameter: EtherCATPDOReceive_P
   * Referenced by: '<S71>/EtherCAT PDO Receive'
   */
  { 66.0, 111.0, 120.0, 32.0, 51.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 84.0, 111.0, 114.0, 113.0, 117.0, 101.0, 32.0, 97.0,
    99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0, 117.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit2'
   */
  3024.0,

  /* Computed Parameter: EtherCATPDOReceive1_P
   * Referenced by: '<S71>/EtherCAT PDO Receive1'
   */
  { 1.0, 47.0 },

  /* Computed Parameter: EtherCATPDOReceive1_
   * Referenced by: '<S71>/EtherCAT PDO Receive1'
   */
  { 66.0, 111.0, 120.0, 32.0, 51.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 80.0, 111.0, 115.0, 105.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 97.0, 99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0, 117.0,
    101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Transmit'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Transmit'
   */
  2992.0,

  /* Computed Parameter: EtherCATPDOReceive2_P
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  { 1.0, 51.0 },

  /* Computed Parameter: EtherCATPDOReceive2_
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  { 66.0, 111.0, 120.0, 32.0, 51.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0, 102.0, 32.0,
    111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 100.0,
    105.0, 115.0, 112.0, 108.0, 97.0, 121.0 },

  /* Computed Parameter: EtherCATPDOReceive2_e
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  3056.0,

  /* Computed Parameter: EtherCATPDOTransmit_P
   * Referenced by: '<S71>/EtherCAT PDO Transmit'
   */
  { 1.0, 40.0 },

  /* Computed Parameter: EtherCATPDOTransmit_
   * Referenced by: '<S71>/EtherCAT PDO Transmit'
   */
  { 66.0, 111.0, 120.0, 32.0, 51.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 32.0,
    84.0, 111.0, 114.0, 113.0, 117.0, 101.0 },

  /* Computed Parameter: EtherCATPDOTransmit1_
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  { 1.0, 39.0 },

  /* Computed Parameter: EtherCATPDOTransmit1
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  { 66.0, 111.0, 120.0, 32.0, 51.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0,
    32.0, 119.0, 111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOTransmit_d
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  3008.0,

  /* Computed Parameter: EtherCATPDOTransmit2_
   * Referenced by: '<S71>/EtherCAT PDO Transmit2'
   */
  { 1.0, 44.0 },

  /* Computed Parameter: EtherCATPDOTransmit2
   * Referenced by: '<S71>/EtherCAT PDO Transmit2'
   */
  { 66.0, 111.0, 120.0, 32.0, 51.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0, 102.0,
    32.0, 111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0 },

  /* Computed Parameter: EtherCATPDOReceive5_m
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  { 1.0, 38.0 },

  /* Computed Parameter: EtherCATPDOReceive_o
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 48.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0,
    32.0, 68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 32.0,
    119.0, 111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOReceive5_g
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  3200.0,

  /* Computed Parameter: EtherCATPDOReceive__o
   * Referenced by: '<S88>/EtherCAT PDO Receive'
   */
  { 1.0, 46.0 },

  /* Computed Parameter: EtherCATPDOReceive_a
   * Referenced by: '<S88>/EtherCAT PDO Receive'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 48.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0,
    32.0, 68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 84.0, 111.0, 114.0, 113.0, 117.0, 101.0, 32.0,
    97.0, 99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0, 117.0,
    101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit2'
   */
  3184.0,

  /* Computed Parameter: EtherCATPDOReceive1_h
   * Referenced by: '<S88>/EtherCAT PDO Receive1'
   */
  { 1.0, 48.0 },

  /* Computed Parameter: EtherCATPDOReceive_b
   * Referenced by: '<S88>/EtherCAT PDO Receive1'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 48.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0,
    32.0, 68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 80.0, 111.0, 115.0, 105.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 97.0, 99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0,
    117.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Transmit'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Transmit'
   */
  3152.0,

  /* Computed Parameter: EtherCATPDOReceive2_b
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  { 1.0, 52.0 },

  /* Computed Parameter: EtherCATPDOReceive_h
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 48.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0,
    32.0, 68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0, 102.0,
    32.0, 111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0,
    100.0, 105.0, 115.0, 112.0, 108.0, 97.0, 121.0 },

  /* Computed Parameter: EtherCATPDOReceive2_l
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  3216.0,

  /* Computed Parameter: EtherCATPDOTransmit_p
   * Referenced by: '<S88>/EtherCAT PDO Transmit'
   */
  { 1.0, 41.0 },

  /* Computed Parameter: EtherCATPDOTransmi_j
   * Referenced by: '<S88>/EtherCAT PDO Transmit'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 48.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0,
    32.0, 68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0,
    112.0, 117.0, 116.0, 115.0, 46.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    32.0, 84.0, 111.0, 114.0, 113.0, 117.0, 101.0 },

  /* Computed Parameter: EtherCATPDOTransmit_l
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  { 1.0, 40.0 },

  /* Computed Parameter: EtherCATPDOTransmi_n
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 48.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0,
    32.0, 68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0,
    112.0, 117.0, 116.0, 115.0, 46.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0,
    108.0, 32.0, 119.0, 111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOTransmit_n
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  3168.0,

  /* Computed Parameter: EtherCATPDOTransmit_k
   * Referenced by: '<S88>/EtherCAT PDO Transmit2'
   */
  { 1.0, 45.0 },

  /* Computed Parameter: EtherCATPDOTransmi_f
   * Referenced by: '<S88>/EtherCAT PDO Transmit2'
   */
  { 66.0, 111.0, 120.0, 32.0, 49.0, 48.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0,
    32.0, 68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0,
    112.0, 117.0, 116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0,
    102.0, 32.0, 111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0 },

  /* Computed Parameter: EtherCATPDOReceive5_o
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  { 1.0, 37.0 },

  /* Computed Parameter: EtherCATPDOReceive_n
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  { 66.0, 111.0, 120.0, 32.0, 50.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 32.0, 119.0,
    111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOReceive5_k
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  2960.0,

  /* Computed Parameter: EtherCATPDOReceive__p
   * Referenced by: '<S105>/EtherCAT PDO Receive'
   */
  { 1.0, 45.0 },

  /* Computed Parameter: EtherCATPDOReceive_j
   * Referenced by: '<S105>/EtherCAT PDO Receive'
   */
  { 66.0, 111.0, 120.0, 32.0, 50.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 84.0, 111.0, 114.0, 113.0, 117.0, 101.0, 32.0, 97.0,
    99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0, 117.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit2'
   */
  2944.0,

  /* Computed Parameter: EtherCATPDOReceive1_o
   * Referenced by: '<S105>/EtherCAT PDO Receive1'
   */
  { 1.0, 47.0 },

  /* Computed Parameter: EtherCATPDOReceive_i
   * Referenced by: '<S105>/EtherCAT PDO Receive1'
   */
  { 66.0, 111.0, 120.0, 32.0, 50.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 80.0, 111.0, 115.0, 105.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 97.0, 99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0, 117.0,
    101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Transmit'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Transmit'
   */
  2912.0,

  /* Computed Parameter: EtherCATPDOReceive2_n
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  { 1.0, 51.0 },

  /* Computed Parameter: EtherCATPDOReceive_m
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  { 66.0, 111.0, 120.0, 32.0, 50.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0, 102.0, 32.0,
    111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 100.0,
    105.0, 115.0, 112.0, 108.0, 97.0, 121.0 },

  /* Computed Parameter: EtherCATPDOReceive_nt
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  2976.0,

  /* Computed Parameter: EtherCATPDOTransmit_m
   * Referenced by: '<S105>/EtherCAT PDO Transmit'
   */
  { 1.0, 40.0 },

  /* Computed Parameter: EtherCATPDOTransm_nh
   * Referenced by: '<S105>/EtherCAT PDO Transmit'
   */
  { 66.0, 111.0, 120.0, 32.0, 50.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 32.0,
    84.0, 111.0, 114.0, 113.0, 117.0, 101.0 },

  /* Computed Parameter: EtherCATPDOTransmit_h
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  { 1.0, 39.0 },

  /* Computed Parameter: EtherCATPDOTransmi_p
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  { 66.0, 111.0, 120.0, 32.0, 50.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0,
    32.0, 119.0, 111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOTransmit_a
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  2928.0,

  /* Computed Parameter: EtherCATPDOTransmit_e
   * Referenced by: '<S105>/EtherCAT PDO Transmit2'
   */
  { 1.0, 44.0 },

  /* Computed Parameter: EtherCATPDOTransm_fh
   * Referenced by: '<S105>/EtherCAT PDO Transmit2'
   */
  { 66.0, 111.0, 120.0, 32.0, 50.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0, 102.0,
    32.0, 111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0 },

  /* Computed Parameter: EtherCATPDOReceive5_p
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  { 1.0, 37.0 },

  /* Computed Parameter: EtherCATPDOReceive_g
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  { 66.0, 111.0, 120.0, 32.0, 57.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 83.0, 116.0, 97.0, 116.0, 117.0, 115.0, 32.0, 119.0,
    111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOReceive_kx
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  3120.0,

  /* Computed Parameter: EtherCATPDOReceive__f
   * Referenced by: '<S122>/EtherCAT PDO Receive'
   */
  { 1.0, 45.0 },

  /* Computed Parameter: EtherCATPDOReceive_e
   * Referenced by: '<S122>/EtherCAT PDO Receive'
   */
  { 66.0, 111.0, 120.0, 32.0, 57.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 84.0, 111.0, 114.0, 113.0, 117.0, 101.0, 32.0, 97.0,
    99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0, 117.0, 101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  3104.0,

  /* Computed Parameter: EtherCATPDOReceive1_d
   * Referenced by: '<S122>/EtherCAT PDO Receive1'
   */
  { 1.0, 47.0 },

  /* Computed Parameter: EtherCATPDOReceiv_ja
   * Referenced by: '<S122>/EtherCAT PDO Receive1'
   */
  { 66.0, 111.0, 120.0, 32.0, 57.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 80.0, 111.0, 115.0, 105.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 97.0, 99.0, 116.0, 117.0, 97.0, 108.0, 32.0, 118.0, 97.0, 108.0, 117.0,
    101.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  3072.0,

  /* Computed Parameter: EtherCATPDOReceive3_P
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  { 1.0, 51.0 },

  /* Computed Parameter: EtherCATPDOReceive3_
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  { 66.0, 111.0, 120.0, 32.0, 57.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 73.0, 110.0, 112.0, 117.0,
    116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0, 102.0, 32.0,
    111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 100.0,
    105.0, 115.0, 112.0, 108.0, 97.0, 121.0 },

  /* Computed Parameter: EtherCATPDOReceive3_f
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  3136.0,

  /* Computed Parameter: EtherCATPDOTransmit_g
   * Referenced by: '<S122>/EtherCAT PDO Transmit'
   */
  { 1.0, 40.0 },

  /* Computed Parameter: EtherCATPDOTransmi_e
   * Referenced by: '<S122>/EtherCAT PDO Transmit'
   */
  { 66.0, 111.0, 120.0, 32.0, 57.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 32.0,
    84.0, 111.0, 114.0, 113.0, 117.0, 101.0 },

  /* Computed Parameter: EtherCATPDOTransmi_mm
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  { 1.0, 39.0 },

  /* Computed Parameter: EtherCATPDOTransmi_m
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  { 66.0, 111.0, 120.0, 32.0, 57.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0,
    32.0, 119.0, 111.0, 114.0, 100.0 },

  /* Computed Parameter: EtherCATPDOTransmi_gs
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  3088.0,

  /* Computed Parameter: EtherCATPDOTransmi_gc
   * Referenced by: '<S122>/EtherCAT PDO Transmit2'
   */
  { 1.0, 44.0 },

  /* Computed Parameter: EtherCATPDOTransm_ea
   * Referenced by: '<S122>/EtherCAT PDO Transmit2'
   */
  { 66.0, 111.0, 120.0, 32.0, 57.0, 32.0, 40.0, 69.0, 108.0, 109.0, 111.0, 32.0,
    68.0, 114.0, 105.0, 118.0, 101.0, 41.0, 46.0, 79.0, 117.0, 116.0, 112.0,
    117.0, 116.0, 115.0, 46.0, 77.0, 111.0, 100.0, 101.0, 32.0, 111.0, 102.0,
    32.0, 111.0, 112.0, 101.0, 114.0, 97.0, 116.0, 105.0, 111.0, 110.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_S_e
   * Referenced by: '<S66>/EtherCAT Tx Var 3'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_h
   * Referenced by: '<S66>/EtherCAT Tx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 109.0, 109.0,
    97.0, 110.0, 100.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_S_f
   * Referenced by: '<S66>/EtherCAT Tx Var 4'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_c
   * Referenced by: '<S66>/EtherCAT Tx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 117.0, 110.0,
    116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_S_j
   * Referenced by: '<S66>/EtherCAT Tx Var 5'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_n
   * Referenced by: '<S66>/EtherCAT Tx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 53.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 67.0, 117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_S_o
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_k
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 109.0, 109.0,
    97.0, 110.0, 100.0 },

  /* Computed Parameter: EtherCATTxVar3_P2_Siz
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  { 1.0, 1.0 },

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  2224.0,

  /* Computed Parameter: EtherCATTxVar4_P1_S_p
   * Referenced by: '<S67>/EtherCAT Tx Var 4'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_ct
   * Referenced by: '<S67>/EtherCAT Tx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 117.0, 110.0,
    116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_S_o
   * Referenced by: '<S67>/EtherCAT Tx Var 5'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_g
   * Referenced by: '<S67>/EtherCAT Tx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 56.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 67.0, 117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_S_b
   * Referenced by: '<S68>/EtherCAT Tx Var 3'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_b
   * Referenced by: '<S68>/EtherCAT Tx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 109.0, 109.0,
    97.0, 110.0, 100.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_S_b
   * Referenced by: '<S68>/EtherCAT Tx Var 4'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_p
   * Referenced by: '<S68>/EtherCAT Tx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 117.0, 110.0,
    116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATTxVar5_P1__og
   * Referenced by: '<S68>/EtherCAT Tx Var 5'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_g4
   * Referenced by: '<S68>/EtherCAT Tx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 54.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 67.0, 117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_S_i
   * Referenced by: '<S69>/EtherCAT Tx Var 3'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar3_P1_d
   * Referenced by: '<S69>/EtherCAT Tx Var 3'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 109.0, 109.0,
    97.0, 110.0, 100.0 },

  /* Computed Parameter: EtherCATTxVar4_P1__bt
   * Referenced by: '<S69>/EtherCAT Tx Var 4'
   */
  { 1.0, 61.0 },

  /* Computed Parameter: EtherCATTxVar4_P1_m
   * Referenced by: '<S69>/EtherCAT Tx Var 4'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 67.0, 111.0, 117.0, 110.0,
    116.0, 101.0, 114.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_S_k
   * Referenced by: '<S69>/EtherCAT Tx Var 5'
   */
  { 1.0, 67.0 },

  /* Computed Parameter: EtherCATTxVar5_P1_a
   * Referenced by: '<S69>/EtherCAT Tx Var 5'
   */
  { 66.0, 111.0, 120.0, 32.0, 55.0, 32.0, 40.0, 65.0, 84.0, 82.0, 73.0, 65.0,
    83.0, 32.0, 50.0, 46.0, 49.0, 32.0, 76.0, 101.0, 103.0, 32.0, 40.0, 77.0,
    101.0, 100.0, 117.0, 108.0, 108.0, 97.0, 32.0, 49.0, 46.0, 53.0, 41.0, 41.0,
    46.0, 117.0, 67.0, 111.0, 110.0, 116.0, 114.0, 111.0, 108.0, 108.0, 101.0,
    114.0, 73.0, 110.0, 112.0, 117.0, 116.0, 46.0, 77.0, 111.0, 116.0, 111.0,
    114.0, 32.0, 67.0, 117.0, 114.0, 114.0, 101.0, 110.0, 116.0 },

  /* Pooled Parameter (Expression: 4)
   * Referenced by:
   *   '<S62>/ModeOfOperation'
   *   '<S63>/ModeOfOperation'
   *   '<S64>/ModeOfOperation'
   *   '<S65>/ModeOfOperation'
   */
  4
};
