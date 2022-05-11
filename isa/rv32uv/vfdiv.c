// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matteo Perotti <mperotti@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "float_macros.h"
#include "vector_macros.h"

// Simple random test with similar values + 1 subnormal
void TEST_CASE1(void) {
  VSET(16, e16, m1);
  //              -0.8057, -0.8564,  0.3425, -0.3066, -0.7314, -0.6396,  0.7588,
  //              -0.3743,  0.8706, -0.3064,  0.0390,  0.6123,  0.0237, -0.6201,
  //              -0.4524,  0.3337
  VLOAD_16(v2, 0xba72, 0xbada, 0x357b, 0xb4e8, 0xb9da, 0xb91e, 0x3a12, 0xb5fd,
           0x3af7, 0xb4e7, 0x28fe, 0x38e6, 0x2612, 0xb8f6, 0xb73d, 0x3557);
  //              -0.4094,  0.0410, -0.7305,  0.9038, -0.3545,  0.2830, -0.7051,
  //              -0.7124, -0.6348,  0.1256,  0.5576,  0.1334,  0.8779, -0.4836,
  //              0.3215,  0.4167
  VLOAD_16(v3, 0xb68d, 0x293e, 0xb9d8, 0x3b3b, 0xb5ac, 0x3487, 0xb9a4, 0xb9b3,
           0xb914, 0x3005, 0x3876, 0x3045, 0x3b06, 0xb7bd, 0x3525, 0x36ab);
  asm volatile("vfdiv.vv v1, v2, v3");
  //               1.9678, -20.9062, -0.4690, -0.3394,  2.0625, -2.2598,
  //               -1.0762,  0.5254, -1.3711, -2.4395,  0.0699,  4.5898, 0.0270,
  //               1.2822, -1.4072,  0.8008
  VCMP_U16(1, v1, 0x3fdf, 0xcd3a, 0xb780, 0xb56d, 0x4020, 0xc085, 0xbc4e,
           0x3833, 0xbd7c, 0xc0e0, 0x2c79, 0x4496, 0x26ea, 0x3d20, 0xbda0,
           0x3a68);

  VSET(16, e32, m1);
  //               0.64838839,  0.00666664, -0.13619921,  0.21094505,
  //               -0.51040554, -0.77216595,  0.42111391,  0.82974166,
  //               -0.31227046,  0.68854737, -0.72970057,  0.10843290,
  //               -0.38442346,  0.18102080,  0.57249051,  0.76465768
  VLOAD_32(v2, 0x3f25fcc8, 0x3bda73da, 0xbe0b77ce, 0x3e5801fb, 0xbf02a9f0,
           0xbf45acab, 0x3ed79c3e, 0x3f5469f3, 0xbe9fe1ea, 0x3f3044a4,
           0xbf3acda8, 0x3dde1212, 0xbec4d327, 0x3e395d84, 0x3f128ebd,
           0x3f43c09b);
  //              -0.59629226, -0.46890569,  0.99662799, -0.49397555,
  //              0.80701596,  0.55786854, -0.26524273, -0.04642257,
  //              -0.67671824,  0.64403933,  0.06642481,  0.26544699,
  //              -0.00225505,  0.27478188,  0.76509053,  0.36194146
  VLOAD_32(v3, 0xbf18a69c, 0xbef01468, 0x3f7f2303, 0xbefcea5d, 0x3f4e9899,
           0x3f0ed079, 0xbe87cde5, 0xbd3e2597, 0xbf2d3d68, 0x3f24dfc3,
           0x3d8809bb, 0x3e87e8ab, 0xbb13c97d, 0x3e8cb036, 0x3f43dcf9,
           0x3eb95064);
  asm volatile("vfdiv.vv v1, v2, v3");
  //              -1.08736682, -0.01421745, -0.13666002, -0.42703542,
  //              -0.63246030, -1.38413608, -1.58765483, -17.87367058,
  //              0.46144828,  1.06910765, -10.98536205,  0.40849173,
  //              170.47213745,  0.65877998,  0.74826509,  2.11265564
  VCMP_U32(2, v1, 0xbf8b2ed5, 0xbc68f04d, 0xbe0bf09b, 0xbedaa462, 0xbf21e8ea,
           0xbfb12b5e, 0xbfcb3846, 0xc18efd46, 0x3eec42f2, 0x3f88d884,
           0xc12fc40a, 0x3ed125d4, 0x432a78dd, 0x3f28a5cd, 0x3f3f8e4c,
           0x400735c0);

  VSET(16, e64, m1);
  //              -0.6201645522687720,  0.7701971477336478,  0.3292637140913006,
  //              -0.8434179184761514, -0.7347451981263740,  0.6543864439701519,
  //              0.1228421097534835, -0.5052233099528094, -0.5128552707464591,
  //              0.9434287237802566, -0.5723896115412233, -0.5719579148082712,
  //              -0.6537028651114556,  0.1091378410914579, -0.7602559429758879,
  //              0.2908894437497427
  VLOAD_64(v2, 0xbfe3d86354c44060, 0x3fe8a5747d1fa1c6, 0x3fd512a81cf2063c,
           0xbfeafd479316e516, 0xbfe783085c9b10ee, 0x3fe4f0bbd6f98570,
           0x3fbf72949bf67da0, 0xbfe02aca132d92f2, 0xbfe0694f74edfe18,
           0x3fee30916f57c874, 0xbfe2510404c47868, 0xbfe24d7aaf5946b0,
           0xbfe4eb22455e9102, 0x3fbbf075223e6d60, 0xbfe854044575797c,
           0x3fd29deec1ea08a0);
  //               0.6660375425590812, -0.9603615652916235, -0.1168804546788573,
  //               -0.3258082002843947,  0.0488865860405421,
  //               -0.1515621417461690, -0.1189568642850463,
  //               -0.1213016259965920, -0.1369814061459547, 0.5914369694708146,
  //               0.7538814889966272,  0.2346701936201294,  0.9227364529293489,
  //               0.9447507336323382, -0.4250995717346850, -0.0882167932097473
  VLOAD_64(v3, 0x3fe5502df6e661fe, 0xbfeebb482d68699c, 0xbfbdebe0a2632640,
           0xbfd4da0aa33f5db0, 0x3fa907a9a083b220, 0xbfc36663650e4608,
           0xbfbe73f501bd2e10, 0xbfbf0d9f949b6370, 0xbfc1889b51c74ac0,
           0x3fe2ed0d3930b850, 0x3fe81fcc12899c0a, 0x3fce09ac4378e388,
           0x3fed870e9905133a, 0x3fee3b65e3fa5532, 0xbfdb34d4d5893894,
           0xbfb6956031cb3a60);
  asm volatile("vfdiv.vv v1, v2, v3");
  //              -0.9311255186696326, -0.8019866429158581, -2.8170981623573508,
  //              2.5886945685834193, -15.0295870019854370, -4.3176114854994303,
  //              -1.0326609606918302,  4.1650167984310764,  3.7439772679805032,
  //              1.5951466892987514, -0.7592567530780479, -2.4372840282141826,
  //              -0.7084394065458121,  0.1155202501636058,  1.7884185106880846,
  //              -3.2974384260161655
  VCMP_U64(3, v1, 0xbfedcbc7be65070a, 0xbfe9a9dfe464e0ca, 0xc006896ac2e79279,
           0x4004b5a57f7b305c, 0xc02e0f26070bd40a, 0xc011453bf1fc3753,
           0xbff085c77fe07008, 0x4010a8fa29e23558, 0x400df3aa5a978cad,
           0x3ff985b888edc5e0, 0xbfe84bd4d177987a, 0xc0037f8ec4c1f1c6,
           0xbfe6ab891e49fb2d, 0x3fbd92bc307a7a1b, 0x3ffc9d5cba6f762a,
           0xc00a612765c28153);
};

// Simple random test with similar values + 1 subnormal (masked)
// The numbers are the same of TEST_CASE1
void TEST_CASE2(void) {
  VSET(16, e16, m1);
  //              -0.8057, -0.8564,  0.3425, -0.3066, -0.7314, -0.6396,  0.7588,
  //              -0.3743,  0.8706, -0.3064,  0.0390,  0.6123,  0.0237, -0.6201,
  //              -0.4524,  0.3337
  VLOAD_16(v2, 0xba72, 0xbada, 0x357b, 0xb4e8, 0xb9da, 0xb91e, 0x3a12, 0xb5fd,
           0x3af7, 0xb4e7, 0x28fe, 0x38e6, 0x2612, 0xb8f6, 0xb73d, 0x3557);
  //              -0.4094,  0.0410, -0.7305,  0.9038, -0.3545,  0.2830, -0.7051,
  //              -0.7124, -0.6348,  0.1256,  0.5576,  0.1334,  0.8779, -0.4836,
  //              0.3215,  0.4167
  VLOAD_16(v3, 0xb68d, 0x293e, 0xb9d8, 0x3b3b, 0xb5ac, 0x3487, 0xb9a4, 0xb9b3,
           0xb914, 0x3005, 0x3876, 0x3045, 0x3b06, 0xb7bd, 0x3525, 0x36ab);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfdiv.vv v1, v2, v3, v0.t");
  //               0.0000, -20.9062,  0.0000, -0.3394,  0.0000, -2.2598, 0.0000,
  //               0.5254,  0.0000, -2.4395,  0.0000,  4.5898,  0.0000,  1.2822,
  //               0.0000,  0.8008
  VCMP_U16(4, v1, 0x0, 0xcd3a, 0x0, 0xb56d, 0x0, 0xc085, 0x0, 0x3833, 0x0,
           0xc0e0, 0x0, 0x4496, 0x0, 0x3d20, 0x0, 0x3a68);

  VSET(16, e32, m1);
  //               0.64838839,  0.00666664, -0.13619921,  0.21094505,
  //               -0.51040554, -0.77216595,  0.42111391,  0.82974166,
  //               -0.31227046,  0.68854737, -0.72970057,  0.10843290,
  //               -0.38442346,  0.18102080,  0.57249051,  0.76465768
  VLOAD_32(v2, 0x3f25fcc8, 0x3bda73da, 0xbe0b77ce, 0x3e5801fb, 0xbf02a9f0,
           0xbf45acab, 0x3ed79c3e, 0x3f5469f3, 0xbe9fe1ea, 0x3f3044a4,
           0xbf3acda8, 0x3dde1212, 0xbec4d327, 0x3e395d84, 0x3f128ebd,
           0x3f43c09b);
  //              -0.59629226, -0.46890569,  0.99662799, -0.49397555,
  //              0.80701596,  0.55786854, -0.26524273, -0.04642257,
  //              -0.67671824,  0.64403933,  0.06642481,  0.26544699,
  //              -0.00225505,  0.27478188,  0.76509053,  0.36194146
  VLOAD_32(v3, 0xbf18a69c, 0xbef01468, 0x3f7f2303, 0xbefcea5d, 0x3f4e9899,
           0x3f0ed079, 0xbe87cde5, 0xbd3e2597, 0xbf2d3d68, 0x3f24dfc3,
           0x3d8809bb, 0x3e87e8ab, 0xbb13c97d, 0x3e8cb036, 0x3f43dcf9,
           0x3eb95064);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfdiv.vv v1, v2, v3, v0.t");
  //               0.00000000, -0.01421745,  0.00000000, -0.42703542,
  //               0.00000000, -1.38413608,  0.00000000, -17.87367058,
  //               0.00000000,  1.06910765,  0.00000000,  0.40849173,
  //               0.00000000,  0.65877998,  0.00000000,  2.11265564
  VCMP_U32(5, v1, 0x0, 0xbc68f04d, 0x0, 0xbedaa462, 0x0, 0xbfb12b5e, 0x0,
           0xc18efd46, 0x0, 0x3f88d884, 0x0, 0x3ed125d4, 0x0, 0x3f28a5cd, 0x0,
           0x400735c0);

  VSET(16, e64, m1);
  //              -0.6201645522687720,  0.7701971477336478,  0.3292637140913006,
  //              -0.8434179184761514, -0.7347451981263740,  0.6543864439701519,
  //              0.1228421097534835, -0.5052233099528094, -0.5128552707464591,
  //              0.9434287237802566, -0.5723896115412233, -0.5719579148082712,
  //              -0.6537028651114556,  0.1091378410914579, -0.7602559429758879,
  //              0.2908894437497427
  VLOAD_64(v2, 0xbfe3d86354c44060, 0x3fe8a5747d1fa1c6, 0x3fd512a81cf2063c,
           0xbfeafd479316e516, 0xbfe783085c9b10ee, 0x3fe4f0bbd6f98570,
           0x3fbf72949bf67da0, 0xbfe02aca132d92f2, 0xbfe0694f74edfe18,
           0x3fee30916f57c874, 0xbfe2510404c47868, 0xbfe24d7aaf5946b0,
           0xbfe4eb22455e9102, 0x3fbbf075223e6d60, 0xbfe854044575797c,
           0x3fd29deec1ea08a0);
  //               0.6660375425590812, -0.9603615652916235, -0.1168804546788573,
  //               -0.3258082002843947,  0.0488865860405421,
  //               -0.1515621417461690, -0.1189568642850463,
  //               -0.1213016259965920, -0.1369814061459547, 0.5914369694708146,
  //               0.7538814889966272,  0.2346701936201294,  0.9227364529293489,
  //               0.9447507336323382, -0.4250995717346850, -0.0882167932097473
  VLOAD_64(v3, 0x3fe5502df6e661fe, 0xbfeebb482d68699c, 0xbfbdebe0a2632640,
           0xbfd4da0aa33f5db0, 0x3fa907a9a083b220, 0xbfc36663650e4608,
           0xbfbe73f501bd2e10, 0xbfbf0d9f949b6370, 0xbfc1889b51c74ac0,
           0x3fe2ed0d3930b850, 0x3fe81fcc12899c0a, 0x3fce09ac4378e388,
           0x3fed870e9905133a, 0x3fee3b65e3fa5532, 0xbfdb34d4d5893894,
           0xbfb6956031cb3a60);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfdiv.vv v1, v2, v3, v0.t");
  //               0.0000000000000000, -0.8019866429158581,
  //               0.0000000000000000,  2.5886945685834193,  0.0000000000000000,
  //               -4.3176114854994303, 0.0000000000000000,  4.1650167984310764,
  //               0.0000000000000000,  1.5951466892987514,  0.0000000000000000,
  //               -2.4372840282141826,  0.0000000000000000, 0.1155202501636058,
  //               0.0000000000000000, -3.2974384260161655
  VCMP_U64(6, v1, 0x0, 0xbfe9a9dfe464e0ca, 0x0, 0x4004b5a57f7b305c, 0x0,
           0xc011453bf1fc3753, 0x0, 0x4010a8fa29e23558, 0x0, 0x3ff985b888edc5e0,
           0x0, 0xc0037f8ec4c1f1c6, 0x0, 0x3fbd92bc307a7a1b, 0x0,
           0xc00a612765c28153);
};

// Simple random test with similar values (vector-scalar)
void TEST_CASE3(void) {
  VSET(16, e16, m1);
  //              -0.0933,  0.4983,  0.5918, -0.0608,  0.0790, -0.2864, -0.7656,
  //              0.4878,  0.8862,  0.4255,  0.9561, -0.7158, -0.3247,  0.9961,
  //              -0.4963, -0.4114
  VLOAD_16(v2, 0xadf9, 0x37f9, 0x38bc, 0xabc7, 0x2d0f, 0xb495, 0xba20, 0x37ce,
           0x3b17, 0x36cf, 0x3ba6, 0xb9ba, 0xb532, 0x3bf8, 0xb7f1, 0xb695);
  double dscalar_16;
  //                             -0.3206
  BOX_HALF_IN_DOUBLE(dscalar_16, 0xb521);
  asm volatile("vfdiv.vf v1, v2, %[A]" ::[A] "f"(dscalar_16));
  //               0.2910, -1.5547, -1.8457,  0.1896, -0.2466,  0.8936,  2.3887,
  //               -1.5215, -2.7656, -1.3271, -2.9824,  2.2324,  1.0127,
  //               -3.1074,  1.5488,  1.2832
  VCMP_U16(7, v1, 0x34a8, 0xbe37, 0xbf62, 0x3210, 0xb3e3, 0x3b25, 0x40c6,
           0xbe16, 0xc187, 0xbd4f, 0xc1f7, 0x4077, 0x3c0d, 0xc236, 0x3e31,
           0x3d22);

  VSET(16, e32, m1);
  //               0.74354362,  0.49774653,  0.25714639,  0.51635689,
  //               0.74569613,  0.41876560,  0.21346331,  0.08743033,
  //               -0.15111920, -0.93289024,  0.08753468, -0.33427054,
  //               0.06167563, -0.54564798,  0.78990245, -0.77273035
  VLOAD_32(v2, 0x3f3e58e0, 0x3efed8a2, 0x3e83a8b1, 0x3f042ff7, 0x3f3ee5f1,
           0x3ed66872, 0x3e5a9620, 0x3db30eac, 0xbe1abefe, 0xbf6ed1e5,
           0x3db34562, 0xbeab2582, 0x3d7c9f95, 0xbf0baf96, 0x3f4a370c,
           0xbf45d1a8);
  double dscalar_32;
  //                              -0.45971388
  BOX_FLOAT_IN_DOUBLE(dscalar_32, 0xbeeb5f9e);
  asm volatile("vfdiv.vf v1, v2, %[A]" ::[A] "f"(dscalar_32));
  //              -1.61740518, -1.08273113, -0.55936182, -1.12321365,
  //              -1.62208748, -0.91092664, -0.46433949, -0.19018422,
  //              0.32872447,  2.02928448, -0.19041122,  0.72712737,
  //              -0.13416091,  1.18692958, -1.71824801,  1.68089414
  VCMP_U32(8, v1, 0xbfcf0722, 0xbf8a96ef, 0xbf0f3255, 0xbf8fc576, 0xbfcfa090,
           0xbf69327c, 0xbeedbde7, 0xbe42bfa7, 0x3ea84e93, 0x4001dfcc,
           0xbe42fb28, 0x3f3a2504, 0xbe096179, 0x3f97ed4e, 0xbfdbef8c,
           0x3fd72789);

  VSET(16, e64, m1);
  //               -0.8580137874650531, -0.4775160339931992, 0.3831482495481682,
  //               -0.3582952848420831,  0.0009796501269754, 0.5485795361059773,
  //               -0.8055070333165963, -0.2632019868496005,
  //               -0.0782680309690278, -0.7119901734202212,
  //               -0.5084969452651125, -0.7586325258910223, 0.6253847342253853,
  //               0.5751160060426936,  0.0609762717873976, -0.7366654110036495
  VLOAD_64(v2, 0xbfeb74d95495be72, 0xbfde8f9f69544024, 0x3fd885803c550ed0,
           0xbfd6ee4f58ad4bcc, 0x3f500cf35070c000, 0x3fe18df6abda8f8e,
           0xbfe9c6b6af995e52, 0xbfd0d84d2570b86c, 0xbfb4095fa9559400,
           0xbfe6c89f9dbd3916, 0xbfe0459b62c0f228, 0xbfe846b7b80c4834,
           0x3fe40326d89d4d44, 0x3fe26759aeab8116, 0x3faf38482a5158c0,
           0xbfe792c3570b5cc2);
  double dscalar_64;
  //                                0.0072652319849018
  BOX_DOUBLE_IN_DOUBLE(dscalar_64, 0x3f7dc225dc5e3c00);
  asm volatile("vfdiv.vf v1, v2, %[A]" ::[A] "f"(dscalar_64));
  //              -118.0986084474836275,
  //              -65.7261922242188206,  52.7372354171766275,
  //              -49.3164272781202087,
  //              0.1348408597290880,  75.5075044053657223,
  //              -110.8714814599939871, -36.2276094413188474,
  //              -10.7729568899768022, -97.9996474854262800,
  //              -69.9904622896889919,
  //              -104.4195873535172723,  86.0791142698573424,  79.1600333255520070,
  //              8.3928870976336363, -101.3959929338175954
  VCMP_U64(9, v1, 0xc05d864f99ce434b, 0xc0506e79eef36846, 0x404a5e5dbaeb1cfe,
           0xc048a880b0658b57, 0x3fc142771d59b8f1, 0x4052e07af3c1e7c9,
           0xc05bb7c65a2c6fa6, 0xc0421d224e615cd6, 0xc0258bc101675622,
           0xc0587ffa39725bce, 0xc0517f63bbf188ac, 0xc05a1ada84ea4b00,
           0x40558510354c6bc9, 0x4053ca3dfc6ae106, 0x4020c9287f66b6b2,
           0xc0595957f2bf0c64);
};

// Simple random test with similar values (vector-scalar) (masked)
void TEST_CASE4(void) {
  VSET(16, e16, m1);
  //               -0.0933,  0.4983,  0.5918, -0.0608,  0.0790, -0.2864,
  //               -0.7656,  0.4878,  0.8862,  0.4255,  0.9561, -0.7158,
  //               -0.3247,  0.9961, -0.4963, -0.4114
  VLOAD_16(v2, 0xadf9, 0x37f9, 0x38bc, 0xabc7, 0x2d0f, 0xb495, 0xba20, 0x37ce,
           0x3b17, 0x36cf, 0x3ba6, 0xb9ba, 0xb532, 0x3bf8, 0xb7f1, 0xb695);
  double dscalar_16;
  //                             -0.3206
  BOX_HALF_IN_DOUBLE(dscalar_16, 0xb521);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfdiv.vf v1, v2, %[A], v0.t" ::[A] "f"(dscalar_16));
  //                0.0000, -1.5547,  0.0000,  0.1896,  0.0000,  0.8936, 0.0000,
  //                -1.5215,  0.0000, -1.3271,  0.0000,  2.2324,  0.0000,
  //                -3.1074,  0.0000,  1.2832
  VCMP_U16(10, v1, 0x0, 0xbe37, 0x0, 0x3210, 0x0, 0x3b25, 0x0, 0xbe16, 0x0,
           0xbd4f, 0x0, 0x4077, 0x0, 0xc236, 0x0, 0x3d22);

  VSET(16, e32, m1);
  //                0.74354362,  0.49774653,  0.25714639,  0.51635689,
  //                0.74569613,  0.41876560,  0.21346331,  0.08743033,
  //                -0.15111920, -0.93289024,  0.08753468, -0.33427054,
  //                0.06167563, -0.54564798,  0.78990245, -0.77273035
  VLOAD_32(v2, 0x3f3e58e0, 0x3efed8a2, 0x3e83a8b1, 0x3f042ff7, 0x3f3ee5f1,
           0x3ed66872, 0x3e5a9620, 0x3db30eac, 0xbe1abefe, 0xbf6ed1e5,
           0x3db34562, 0xbeab2582, 0x3d7c9f95, 0xbf0baf96, 0x3f4a370c,
           0xbf45d1a8);
  double dscalar_32;
  //                              -0.45971388
  BOX_FLOAT_IN_DOUBLE(dscalar_32, 0xbeeb5f9e);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfdiv.vf v1, v2, %[A], v0.t" ::[A] "f"(dscalar_32));
  //                0.00000000, -1.08273113,  0.00000000, -1.12321365,
  //                0.00000000, -0.91092664,  0.00000000, -0.19018422,
  //                0.00000000,  2.02928448,  0.00000000,  0.72712737,
  //                0.00000000,  1.18692958,  0.00000000,  1.68089414
  VCMP_U32(11, v1, 0x0, 0xbf8a96ef, 0x0, 0xbf8fc576, 0x0, 0xbf69327c, 0x0,
           0xbe42bfa7, 0x0, 0x4001dfcc, 0x0, 0x3f3a2504, 0x0, 0x3f97ed4e, 0x0,
           0x3fd72789);

  VSET(16, e64, m1);
  //                -0.8580137874650531, -0.4775160339931992,
  //                0.3831482495481682, -0.3582952848420831, 0.0009796501269754,
  //                0.5485795361059773, -0.8055070333165963,
  //                -0.2632019868496005, -0.0782680309690278,
  //                -0.7119901734202212, -0.5084969452651125,
  //                -0.7586325258910223,  0.6253847342253853,
  //                0.5751160060426936,  0.0609762717873976, -0.7366654110036495
  VLOAD_64(v2, 0xbfeb74d95495be72, 0xbfde8f9f69544024, 0x3fd885803c550ed0,
           0xbfd6ee4f58ad4bcc, 0x3f500cf35070c000, 0x3fe18df6abda8f8e,
           0xbfe9c6b6af995e52, 0xbfd0d84d2570b86c, 0xbfb4095fa9559400,
           0xbfe6c89f9dbd3916, 0xbfe0459b62c0f228, 0xbfe846b7b80c4834,
           0x3fe40326d89d4d44, 0x3fe26759aeab8116, 0x3faf38482a5158c0,
           0xbfe792c3570b5cc2);
  double dscalar_64;
  //                                0.0072652319849018
  BOX_DOUBLE_IN_DOUBLE(dscalar_64, 0x3f7dc225dc5e3c00);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfdiv.vf v1, v2, %[A], v0.t" ::[A] "f"(dscalar_64));
  //                0.0000000000000000, -65.7261922242188206,
  //                0.0000000000000000, -49.3164272781202087,
  //                0.0000000000000000,  75.5075044053657223,
  //                0.0000000000000000, -36.2276094413188474,
  //                0.0000000000000000, -97.9996474854262800,
  //                0.0000000000000000, -104.4195873535172723,
  //                0.0000000000000000,  79.1600333255520070,
  //                0.0000000000000000, -101.3959929338175954
  VCMP_U64(12, v1, 0x0, 0xc0506e79eef36846, 0x0, 0xc048a880b0658b57, 0x0,
           0x4052e07af3c1e7c9, 0x0, 0xc0421d224e615cd6, 0x0, 0xc0587ffa39725bce,
           0x0, 0xc05a1ada84ea4b00, 0x0, 0x4053ca3dfc6ae106, 0x0,
           0xc0595957f2bf0c64);
};

int main(void) {
  enable_vec();
  enable_fp();
  // Change RM to RTZ since there are issues with FDIV + RNE in fpnew
  // Update: there are issues also with RTZ...
  CHANGE_RM(RM_RTZ);

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}
