function [x_dJw_world_qHLeft] = dJw_world_qHLeft(x)
%dJw_world_qHLeft
%    x_dJw_world_qHLeft = dJw_world_qHLeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:12

t1=x(6);
t2=x(5);
t3=sin(t2);
t4=x(4);
t5=sin(t1);
t6=cos(t4);
t7=x(12);
t8=cos(t2);
t9=cos(t7);
t10=sin(t4);
t11=cos(t1);
t12=sin(t7);
t13=t10.*t11.*t3;
t14=t5.*t6;
t15=t13 + t14;
t16=(-1).*t11.*t3.*t6;
t17=t10.*t5;
t18=t16 + t17;
t19=t18.*t9;
t20=(-1).*t12.*t6.*t8;
t21=t19 + t20;
t22=(-1).*t10.*t8.*t9;
t23=t12.*t15;
t24=t22 + t23;
t25=t21.*t24;
t26=t15.*t9;
t27=t10.*t12.*t8;
t28=t26 + t27;
t29=(-1).*t6.*t8.*t9;
t30=t11.*t3.*t6;
t31=(-1).*t10.*t5;
t32=t30 + t31;
t33=t12.*t32;
t34=t29 + t33;
t35=t28.*t34;
t36=t25 + t35;
t37=x(21);
t38=x(22);
t39=x(28);
t40=t11.*t6;
t41=(-1).*t10.*t3.*t5;
t42=t40 + t41;
t43=t6.*t8.*t9;
t44=t12.*t18;
t45=t43 + t44;
t46=x(20);
t47=(-1).*t10.*t11;
t48=(-1).*t3.*t5.*t6;
t49=t47 + t48;
t50=t32.*t9;
t51=t12.*t6.*t8;
t52=t50 + t51;
t53=(-1).*t10.*t11.*t46;
t54=(-1).*t3.*t46.*t5.*t6;
t55=(-1).*t10.*t37.*t5.*t8;
t56=(-1).*t10.*t11.*t3.*t38;
t57=(-1).*t38.*t5.*t6;
t58=t53 + t54 + t55 + t56 + t57;
t59=t10.*t11;
t60=t3.*t5.*t6;
t61=t59 + t60;
t62=t11.*t3.*t46.*t6;
t63=(-1).*t10.*t46.*t5;
t64=t10.*t11.*t37.*t8;
t65=t11.*t38.*t6;
t66=(-1).*t10.*t3.*t38.*t5;
t67=t62 + t63 + t64 + t65 + t66;
t68=(-1).*t10.*t11.*t3.*t46;
t69=(-1).*t46.*t5.*t6;
t70=t11.*t37.*t6.*t8;
t71=(-1).*t10.*t11.*t38;
t72=(-1).*t3.*t38.*t5.*t6;
t73=t68 + t69 + t70 + t71 + t72;
t74=(-1).*t46.*t6.*t8.*t9;
t75=t10.*t3.*t37.*t9;
t76=t12.*t67;
t77=t15.*t39.*t9;
t78=t10.*t12.*t39.*t8;
t79=t74 + t75 + t76 + t77 + t78;
t80=t12.*t46.*t6.*t8;
t81=(-1).*t10.*t12.*t3.*t37;
t82=t67.*t9;
t83=t10.*t39.*t8.*t9;
t84=(-1).*t12.*t15.*t39;
t85=t80 + t81 + t82 + t83 + t84;
t86=t10.*t11.*t3.*t46;
t87=t46.*t5.*t6;
t88=(-1).*t11.*t37.*t6.*t8;
t89=t10.*t11.*t38;
t90=t3.*t38.*t5.*t6;
t91=t86 + t87 + t88 + t89 + t90;
t92=t42.*t52;
t93=t28.*t61;
t94=t92 + t93;
t95=t24.*t49;
t96=t42.*t45;
t97=t95 + t96;
t98=t45.*t58;
t99=(-1).*t11.*t46.*t6;
t100=t10.*t3.*t46.*t5;
t101=(-1).*t37.*t5.*t6.*t8;
t102=(-1).*t11.*t3.*t38.*t6;
t103=t10.*t38.*t5;
t104=t100 + t101 + t102 + t103 + t99;
t105=t104.*t24;
t106=(-1).*t10.*t46.*t8.*t9;
t107=(-1).*t3.*t37.*t6.*t9;
t108=t12.*t91;
t109=t18.*t39.*t9;
t110=(-1).*t12.*t39.*t6.*t8;
t111=t106 + t107 + t108 + t109 + t110;
t112=t111.*t42;
t113=t49.*t79;
t114=t105 + t112 + t113 + t98;
t115=t52.*t58;
t116=t11.*t46.*t6;
t117=(-1).*t10.*t3.*t46.*t5;
t118=t37.*t5.*t6.*t8;
t119=t11.*t3.*t38.*t6;
t120=(-1).*t10.*t38.*t5;
t121=t116 + t117 + t118 + t119 + t120;
t122=t121.*t28;
t123=t61.*t85;
t124=(-1).*t10.*t12.*t46.*t8;
t125=(-1).*t12.*t3.*t37.*t6;
t126=t73.*t9;
t127=t39.*t6.*t8.*t9;
t128=(-1).*t12.*t32.*t39;
t129=t124 + t125 + t126 + t127 + t128;
t130=t129.*t42;
t131=t115 + t122 + t123 + t130;
t132=t10.*t46.*t8.*t9;
t133=t3.*t37.*t6.*t9;
t134=t12.*t73;
t135=t32.*t39.*t9;
t136=t12.*t39.*t6.*t8;
t137=t132 + t133 + t134 + t135 + t136;
t138=t137.*t28;
t139=t21.*t79;
t140=t34.*t85;
t141=t10.*t12.*t46.*t8;
t142=t12.*t3.*t37.*t6;
t143=t9.*t91;
t144=(-1).*t39.*t6.*t8.*t9;
t145=(-1).*t12.*t18.*t39;
t146=t141 + t142 + t143 + t144 + t145;
t147=t146.*t24;
t148=t138 + t139 + t140 + t147;
t149=t11.*t8.*t9;
t150=(-1).*t12.*t3;
t151=t149 + t150;
t152=(-1).*t3.*t6.*t9;
t153=(-1).*t11.*t12.*t6.*t8;
t154=t152 + t153;
t155=t154.*t21;
t156=t10.*t3.*t9;
t157=t10.*t11.*t12.*t8;
t158=t156 + t157;
t159=t158.*t28;
t160=t8.*t9;
t161=(-1).*t11.*t12.*t3;
t162=t160 + t161;
t163=t151.*t162;
t164=t155 + t159 + t163;
t165=t3.*t9;
t166=t11.*t12.*t8;
t167=t165 + t166;
t168=(-1).*t11.*t3.*t37.*t9;
t169=(-1).*t12.*t37.*t8;
t170=(-1).*t38.*t5.*t8.*t9;
t171=(-1).*t3.*t39.*t9;
t172=(-1).*t11.*t12.*t39.*t8;
t173=t168 + t169 + t170 + t171 + t172;
t174=t37.*t8.*t9;
t175=(-1).*t11.*t12.*t3.*t37;
t176=(-1).*t12.*t38.*t5.*t8;
t177=t11.*t39.*t8.*t9;
t178=(-1).*t12.*t3.*t39;
t179=t174 + t175 + t176 + t177 + t178;
t180=(-1).*t11.*t3.*t9;
t181=(-1).*t12.*t8;
t182=t180 + t181;
t183=t10.*t11.*t8.*t9;
t184=(-1).*t10.*t12.*t3;
t185=t183 + t184;
t186=(-1).*t11.*t6.*t8.*t9;
t187=t12.*t3.*t6;
t188=t186 + t187;
t189=(-1).*t182.*t5.*t8;
t190=t188.*t61;
t191=t185.*t42;
t192=t189 + t190 + t191;
t193=t167.*t3.*t5;
t194=(-1).*t10.*t24.*t5.*t8;
t195=t45.*t5.*t6.*t8;
t196=t193 + t194 + t195;
t197=(-1).*t24.*t46.*t5.*t6.*t8;
t198=(-1).*t10.*t45.*t46.*t5.*t8;
t199=t167.*t37.*t5.*t8;
t200=t10.*t24.*t3.*t37.*t5;
t201=(-1).*t3.*t37.*t45.*t5.*t6;
t202=t11.*t167.*t3.*t38;
t203=(-1).*t10.*t11.*t24.*t38.*t8;
t204=t11.*t38.*t45.*t6.*t8;
t205=t111.*t5.*t6.*t8;
t206=(-1).*t10.*t5.*t79.*t8;
t207=t179.*t3.*t5;
t208=t197 + t198 + t199 + t200 + t201 + t202 + t203 + t204 + t205 +  ...
  t206 + t207;
t209=t182.*t3.*t37.*t5;
t210=(-1).*t11.*t182.*t38.*t8;
t211=t185.*t58;
t212=t121.*t188;
t213=t10.*t11.*t46.*t8.*t9;
t214=(-1).*t10.*t12.*t3.*t46;
t215=t11.*t3.*t37.*t6.*t9;
t216=t12.*t37.*t6.*t8;
t217=t38.*t5.*t6.*t8.*t9;
t218=t3.*t39.*t6.*t9;
t219=t11.*t12.*t39.*t6.*t8;
t220=t213 + t214 + t215 + t216 + t217 + t218 + t219;
t221=t220.*t61;
t222=t11.*t46.*t6.*t8.*t9;
t223=(-1).*t12.*t3.*t46.*t6;
t224=(-1).*t10.*t11.*t3.*t37.*t9;
t225=(-1).*t10.*t12.*t37.*t8;
t226=(-1).*t10.*t38.*t5.*t8.*t9;
t227=(-1).*t10.*t3.*t39.*t9;
t228=(-1).*t10.*t11.*t12.*t39.*t8;
t229=t222 + t223 + t224 + t225 + t226 + t227 + t228;
t230=t229.*t42;
t231=(-1).*t11.*t37.*t8.*t9;
t232=t12.*t3.*t37;
t233=t3.*t38.*t5.*t9;
t234=(-1).*t39.*t8.*t9;
t235=t11.*t12.*t3.*t39;
t236=t231 + t232 + t233 + t234 + t235;
t237=(-1).*t236.*t5.*t8;
t238=t209 + t210 + t211 + t212 + t221 + t230 + t237;
t239=(-1).*t3.*t37.*t9;
t240=(-1).*t11.*t12.*t37.*t8;
t241=t12.*t3.*t38.*t5;
t242=(-1).*t11.*t3.*t39.*t9;
t243=(-1).*t12.*t39.*t8;
t244=t239 + t240 + t241 + t242 + t243;
t245=t151.*t244;
t246=t162.*t173;
t247=t10.*t3.*t46.*t9;
t248=t10.*t11.*t12.*t46.*t8;
t249=(-1).*t37.*t6.*t8.*t9;
t250=t11.*t12.*t3.*t37.*t6;
t251=t12.*t38.*t5.*t6.*t8;
t252=(-1).*t11.*t39.*t6.*t8.*t9;
t253=t12.*t3.*t39.*t6;
t254=t247 + t248 + t249 + t250 + t251 + t252 + t253;
t255=t21.*t254;
t256=t3.*t46.*t6.*t9;
t257=t11.*t12.*t46.*t6.*t8;
t258=t10.*t37.*t8.*t9;
t259=(-1).*t10.*t11.*t12.*t3.*t37;
t260=(-1).*t10.*t12.*t38.*t5.*t8;
t261=t10.*t11.*t39.*t8.*t9;
t262=(-1).*t10.*t12.*t3.*t39;
t263=t256 + t257 + t258 + t259 + t260 + t261 + t262;
t264=t263.*t28;
t265=t158.*t85;
t266=t146.*t154;
t267=t245 + t246 + t255 + t264 + t265 + t266;
t268=t12.*t21.*t61;
t269=t12.*t28.*t42;
t270=(-1).*t12.*t151.*t5.*t8;
t271=t268 + t269 + t270;
t272=t8.^2;
t273=t5.^2;
t274=t61.^2;
t275=t42.^2;
t276=(-1).*t10.*t11.*t3;
t277=(-1).*t5.*t6;
t278=t276 + t277;
t279=t272.*t273.*t9;
t280=t274.*t9;
t281=t275.*t9;
t282=t279 + t280 + t281;
t283=(-1).*t11.*t167.*t8;
t284=t24.*t278;
t285=t32.*t45;
t286=t283 + t284 + t285;
t287=(-2).*t273.*t3.*t37.*t8.*t9;
t288=2.*t11.*t272.*t38.*t5.*t9;
t289=2.*t42.*t58.*t9;
t290=2.*t121.*t61.*t9;
t291=(-1).*t12.*t272.*t273.*t39;
t292=(-1).*t12.*t274.*t39;
t293=(-1).*t12.*t275.*t39;
t294=t287 + t288 + t289 + t290 + t291 + t292 + t293;
t295=t11.*t167.*t3.*t37;
t296=t167.*t38.*t5.*t8;
t297=t45.*t73;
t298=(-1).*t11.*t3.*t46.*t6;
t299=t10.*t46.*t5;
t300=(-1).*t10.*t11.*t37.*t8;
t301=(-1).*t11.*t38.*t6;
t302=t10.*t3.*t38.*t5;
t303=t298 + t299 + t300 + t301 + t302;
t304=t24.*t303;
t305=t111.*t32;
t306=t278.*t79;
t307=(-1).*t11.*t179.*t8;
t308=t295 + t296 + t297 + t304 + t305 + t306 + t307;
t309=t12.*t151.*t3.*t37.*t5;
t310=(-1).*t11.*t12.*t151.*t38.*t8;
t311=t12.*t28.*t58;
t312=t12.*t121.*t21;
t313=t21.*t39.*t61.*t9;
t314=t28.*t39.*t42.*t9;
t315=(-1).*t151.*t39.*t5.*t8.*t9;
t316=(-1).*t12.*t173.*t5.*t8;
t317=t12.*t42.*t85;
t318=t12.*t146.*t61;
t319=t309 + t310 + t311 + t312 + t313 + t314 + t315 + t316 + t317 +  ...
  t318;
t320=t21.^2;
t321=t28.^2;
t322=t151.^2;
t323=t320 + t321 + t322;
t324=(-1).*t3.*t9;
t325=(-1).*t11.*t12.*t8;
t326=t324 + t325;
t327=t10.*t8.*t9;
t328=(-1).*t12.*t15;
t329=t327 + t328;
t330=(-1).*t12.*t18;
t331=t29 + t330;
t332=(-1).*t326.*t5.*t8;
t333=t329.*t42;
t334=t331.*t61;
t335=t332 + t333 + t334;
t336=t3.*t326.*t37.*t5;
t337=(-1).*t11.*t326.*t38.*t8;
t338=t329.*t58;
t339=t121.*t331;
t340=(-1).*t12.*t91;
t341=(-1).*t18.*t39.*t9;
t342=t132 + t133 + t136 + t340 + t341;
t343=t342.*t61;
t344=t46.*t6.*t8.*t9;
t345=(-1).*t10.*t3.*t37.*t9;
t346=(-1).*t12.*t67;
t347=(-1).*t15.*t39.*t9;
t348=(-1).*t10.*t12.*t39.*t8;
t349=t344 + t345 + t346 + t347 + t348;
t350=t349.*t42;
t351=(-1).*t37.*t8.*t9;
t352=t11.*t12.*t3.*t37;
t353=t12.*t38.*t5.*t8;
t354=(-1).*t11.*t39.*t8.*t9;
t355=t12.*t3.*t39;
t356=t351 + t352 + t353 + t354 + t355;
t357=(-1).*t356.*t5.*t8;
t358=t336 + t337 + t338 + t339 + t343 + t350 + t357;
t359=2.*t151.*t173;
t360=2.*t28.*t85;
t361=2.*t146.*t21;
t362=t359 + t360 + t361;
x_dJw_world_qHLeft=[0,0,0,0,0,0,0,0,0,t114.*t151 + t131.*t167 + t3.*t36.*t37.*t5 + ( ...
  -1).*t11.*t36.*t38.*t8 + (-1).*t148.*t5.*t8 + t179.*t94 + t173.* ...
  t97,t131.*t24 + t114.*t28 + t148.*t42 + t36.*t58 + t79.*t94 +  ...
  t85.*t97,t114.*t21 + t121.*t36 + t131.*t45 + t148.*t61 + t111.* ...
  t94 + t146.*t97,t179.*t192 + t173.*t196 + t151.*t208 + t167.*t238  ...
  + t164.*t3.*t37.*t5 + (-1).*t11.*t164.*t38.*t8 + (-1).*t267.*t5.* ...
  t8,t238.*t24 + t208.*t28 + t267.*t42 + t164.*t58 + t192.*t79 +  ...
  t196.*t85,t121.*t164 + t111.*t192 + t146.*t196 + t208.*t21 +  ...
  t238.*t45 + t267.*t61,t179.*t282 + t173.*t286 + t167.*t294 +  ...
  t151.*t308 + t271.*t3.*t37.*t5 + (-1).*t11.*t271.*t38.*t8 + (-1).* ...
  t319.*t5.*t8,t24.*t294 + t28.*t308 + t319.*t42 + t271.*t58 +  ...
  t282.*t79 + t286.*t85,t121.*t271 + t111.*t282 + t146.*t286 + t21.* ...
  t308 + t294.*t45 + t319.*t61,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,t179.* ...
  t335 + t167.*t358 + t3.*t323.*t37.*t5 + (-1).*t11.*t323.*t38.*t8 + ...
   (-1).*t362.*t5.*t8,t24.*t358 + t362.*t42 + t323.*t58 + t335.*t79, ...
  t121.*t323 + t111.*t335 + t358.*t45 + t362.*t61,0,0,0,0,0,0,0,0,0, ...
  0,0,0];

end %function