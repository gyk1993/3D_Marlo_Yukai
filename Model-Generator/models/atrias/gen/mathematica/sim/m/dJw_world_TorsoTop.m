function [x_dJw_world_TorsoTop] = dJw_world_TorsoTop(x)
%dJw_world_TorsoTop
%    x_dJw_world_TorsoTop = dJw_world_TorsoTop(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:17

t1=x(5);
t2=x(6);
t3=x(4);
t4=sin(t1);
t5=cos(t3);
t6=sin(t2);
t7=cos(t1);
t8=sin(t3);
t9=cos(t2);
t10=x(21);
t11=t4.*t8.*t9;
t12=t5.*t6;
t13=t11 + t12;
t14=t5.*t9;
t15=(-1).*t4.*t6.*t8;
t16=t14 + t15;
t17=(-1).*t13.*t5.*t7;
t18=(-1).*t4.*t5.*t9;
t19=t6.*t8;
t20=t18 + t19;
t21=(-1).*t20.*t7.*t8;
t22=t17 + t21;
t23=(-1).*t8.*t9;
t24=(-1).*t4.*t5.*t6;
t25=t23 + t24;
t26=(-1).*t25.*t7.*t8;
t27=t16.*t5.*t7;
t28=t26 + t27;
t29=x(22);
t30=x(20);
t31=t4.*t5.*t9;
t32=(-1).*t6.*t8;
t33=t31 + t32;
t34=(-1).*t30.*t8.*t9;
t35=(-1).*t30.*t4.*t5.*t6;
t36=(-1).*t10.*t6.*t7.*t8;
t37=(-1).*t29.*t4.*t8.*t9;
t38=(-1).*t29.*t5.*t6;
t39=t34 + t35 + t36 + t37 + t38;
t40=t8.*t9;
t41=t4.*t5.*t6;
t42=t40 + t41;
t43=t30.*t4.*t5.*t9;
t44=(-1).*t30.*t6.*t8;
t45=t10.*t7.*t8.*t9;
t46=t29.*t5.*t9;
t47=(-1).*t29.*t4.*t6.*t8;
t48=t43 + t44 + t45 + t46 + t47;
t49=t13.*t42;
t50=t16.*t33;
t51=t49 + t50;
t52=(-1).*t25.*t30.*t5.*t7;
t53=(-1).*t16.*t30.*t7.*t8;
t54=t10.*t25.*t4.*t8;
t55=(-1).*t10.*t16.*t4.*t5;
t56=t39.*t5.*t7;
t57=(-1).*t30.*t5.*t9;
t58=t30.*t4.*t6.*t8;
t59=(-1).*t10.*t5.*t6.*t7;
t60=(-1).*t29.*t4.*t5.*t9;
t61=t29.*t6.*t8;
t62=t57 + t58 + t59 + t60 + t61;
t63=(-1).*t62.*t7.*t8;
t64=t52 + t53 + t54 + t55 + t56 + t63;
t65=t13.*t30.*t7.*t8;
t66=(-1).*t20.*t30.*t5.*t7;
t67=t10.*t13.*t4.*t5;
t68=t10.*t20.*t4.*t8;
t69=t30.*t4.*t8.*t9;
t70=t30.*t5.*t6;
t71=(-1).*t10.*t5.*t7.*t9;
t72=t29.*t8.*t9;
t73=t29.*t4.*t5.*t6;
t74=t69 + t70 + t71 + t72 + t73;
t75=(-1).*t7.*t74.*t8;
t76=(-1).*t48.*t5.*t7;
t77=t65 + t66 + t67 + t68 + t75 + t76;
t78=t33.*t39;
t79=t30.*t5.*t9;
t80=(-1).*t30.*t4.*t6.*t8;
t81=t10.*t5.*t6.*t7;
t82=t29.*t4.*t5.*t9;
t83=(-1).*t29.*t6.*t8;
t84=t79 + t80 + t81 + t82 + t83;
t85=t13.*t84;
t86=(-1).*t30.*t4.*t8.*t9;
t87=(-1).*t30.*t5.*t6;
t88=t10.*t5.*t7.*t9;
t89=(-1).*t29.*t8.*t9;
t90=(-1).*t29.*t4.*t5.*t6;
t91=t86 + t87 + t88 + t89 + t90;
t92=t16.*t91;
t93=t42.*t48;
t94=t78 + t85 + t92 + t93;
t95=t5.^2;
t96=t7.^2;
t97=t8.^2;
t98=t4.^2;
t99=t6.*t95.*t96;
t100=t6.*t96.*t97;
t101=t6.*t98;
t102=t100 + t101 + t99;
t103=t9.*t96;
t104=t13.*t4.*t8;
t105=(-1).*t20.*t4.*t5;
t106=t103 + t104 + t105;
t107=t9.^2;
t108=t6.^2;
t109=t4.*t6.*t7.*t9;
t110=(-1).*t42.*t5.*t7.*t9;
t111=t16.*t7.*t8.*t9;
t112=t109 + t110 + t111;
t113=2.*t10.*t4.*t6.*t7;
t114=(-2).*t10.*t4.*t6.*t7.*t95;
t115=(-2).*t10.*t4.*t6.*t7.*t97;
t116=t29.*t9.*t95.*t96;
t117=t29.*t9.*t96.*t97;
t118=t29.*t9.*t98;
t119=t113 + t114 + t115 + t116 + t117 + t118;
t120=t30.*t42.*t7.*t8.*t9;
t121=t16.*t30.*t5.*t7.*t9;
t122=t10.*t6.*t9.*t96;
t123=(-1).*t10.*t6.*t9.*t98;
t124=t10.*t4.*t42.*t5.*t9;
t125=(-1).*t10.*t16.*t4.*t8.*t9;
t126=t107.*t29.*t4.*t7;
t127=(-1).*t108.*t29.*t4.*t7;
t128=t29.*t42.*t5.*t6.*t7;
t129=(-1).*t16.*t29.*t6.*t7.*t8;
t130=t39.*t7.*t8.*t9;
t131=(-1).*t5.*t7.*t84.*t9;
t132=t120 + t121 + t122 + t123 + t124 + t125 + t126 + t127 + t128 +  ...
  t129 + t130 + t131;
t133=t13.*t30.*t4.*t5;
t134=t20.*t30.*t4.*t8;
t135=(-2).*t10.*t4.*t7.*t9;
t136=t10.*t13.*t7.*t8;
t137=(-1).*t10.*t20.*t5.*t7;
t138=(-1).*t29.*t6.*t96;
t139=(-1).*t4.*t5.*t74;
t140=t4.*t48.*t8;
t141=t133 + t134 + t135 + t136 + t137 + t138 + t139 + t140;
t142=t42.^2;
t143=t16.^2;
t144=(-1).*t4.*t7.*t9;
t145=(-1).*t4.*t8.*t9;
t146=(-1).*t5.*t6;
t147=t145 + t146;
t148=(-1).*t147.*t7.*t8;
t149=t33.*t5.*t7;
t150=t144 + t148 + t149;
t151=t108.*t96;
t152=t142 + t143 + t151;
t153=(-2).*t10.*t108.*t4.*t7;
t154=2.*t29.*t6.*t9.*t96;
t155=2.*t16.*t39;
t156=2.*t42.*t84;
t157=t153 + t154 + t155 + t156;
t158=(-1).*t147.*t30.*t5.*t7;
t159=(-1).*t30.*t33.*t7.*t8;
t160=(-1).*t10.*t9.*t96;
t161=t10.*t9.*t98;
t162=t10.*t147.*t4.*t8;
t163=(-1).*t10.*t33.*t4.*t5;
t164=t29.*t4.*t6.*t7;
t165=t5.*t7.*t91;
t166=(-1).*t30.*t4.*t5.*t9;
t167=t30.*t6.*t8;
t168=(-1).*t10.*t7.*t8.*t9;
t169=(-1).*t29.*t5.*t9;
t170=t29.*t4.*t6.*t8;
t171=t166 + t167 + t168 + t169 + t170;
t172=(-1).*t171.*t7.*t8;
t173=t158 + t159 + t160 + t161 + t162 + t163 + t164 + t165 + t172;
x_dJw_world_TorsoTop=[0,0,0,0,0,0,0,0,0,t10.*t22.*t4.*t6 + t10.*t51.*t7 + (-1).*t28.* ...
  t29.*t6.*t7 + (-1).*t6.*t7.*t77 + (-1).*t10.*t28.*t4.*t9 + (-1).* ...
  t22.*t29.*t7.*t9 + t64.*t7.*t9 + t4.*t94,t22.*t39 + t28.*t48 +  ...
  t13.*t64 + (-1).*t30.*t5.*t51.*t7 + t16.*t77 + t10.*t4.*t51.*t8 +  ...
  (-1).*t7.*t8.*t94,(-1).*t10.*t4.*t5.*t51 + t20.*t64 + t28.*t74 +  ...
  t42.*t77 + (-1).*t30.*t51.*t7.*t8 + t22.*t84 + t5.*t7.*t94,t132.* ...
  t4 + t10.*t106.*t4.*t6 + t10.*t112.*t7 + (-1).*t141.*t6.*t7 + (-1) ...
  .*t102.*t29.*t6.*t7 + (-1).*t10.*t102.*t4.*t9 + t119.*t7.*t9 + ( ...
  -1).*t106.*t29.*t7.*t9,t119.*t13 + t141.*t16 + t106.*t39 + t102.* ...
  t48 + (-1).*t112.*t30.*t5.*t7 + t10.*t112.*t4.*t8 + (-1).*t132.* ...
  t7.*t8,t119.*t20 + t141.*t42 + (-1).*t10.*t112.*t4.*t5 + t132.* ...
  t5.*t7 + t102.*t74 + (-1).*t112.*t30.*t7.*t8 + t106.*t84,t157.*t4  ...
  + t10.*t152.*t7 + (-1).*t150.*t29.*t6.*t7 + (-1).*t10.*t150.*t4.* ...
  t9 + t173.*t7.*t9,t13.*t173 + t150.*t48 + (-1).*t152.*t30.*t5.*t7  ...
  + t10.*t152.*t4.*t8 + (-1).*t157.*t7.*t8,t173.*t20 + (-1).*t10.* ...
  t152.*t4.*t5 + t157.*t5.*t7 + t150.*t74 + (-1).*t152.*t30.*t7.*t8, ...
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];

end %function