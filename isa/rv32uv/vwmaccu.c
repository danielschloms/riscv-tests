// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1() {
  VSET(16, e16, m1);
  VLOAD_16(v6, 0x519d, 0x7122, 0x672c, 0x4d97, 0x436e, 0x3f1f, 0x423d, 0x44e8,
           0x3d7b, 0x5570, 0x1e90, 0x79f4, 0x456b, 0x0283, 0x02b5, 0x6865);
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xce, 0x96, 0x33, 0x88, 0xf8, 0x3f, 0x0c, 0xde, 0x1e, 0x9d, 0x5a,
          0x75, 0x73, 0x43, 0xd9, 0x43);
  VLOAD_8(v4, 0x51, 0x88, 0x16, 0xf6, 0x57, 0xab, 0xd8, 0x26, 0x2e, 0x35, 0x94,
          0xd1, 0xf0, 0xb9, 0x09, 0x8a);
  asm volatile("vwmaccu.vv v6, v2, v4");
  VSET(16, e16, m1);
  VCMP_U16(1, v6, 0x92cb, 0xc0d2, 0x6b8e, 0xd047, 0x97b6, 0x6934, 0x4c5d,
           0x65dc, 0x42df, 0x75f1, 0x5298, 0xd979, 0xb13b, 0x32ee, 0x0a56,
           0x8c83);

  VSET(16, e32, m1);
  VLOAD_32(v6, 0x1f50b763, 0x6d1a7f46, 0x17b8b2b5, 0x6b69c966, 0x25d945cb,
           0x3e6c375b, 0x314db8d3, 0x35ade27d, 0x74fa2d58, 0x735f513d,
           0x3cad4e4d, 0x628eb81a, 0x1c48c2f9, 0x14f08921, 0x77de05bf,
           0x528c354b);
  VSET(16, e16, m1);
  VLOAD_16(v2, 0x4ed5, 0xcf74, 0x3442, 0x280f, 0x795e, 0x3007, 0xdf3e, 0xb348,
           0x3865, 0xcb59, 0x1291, 0xa04b, 0xc5bd, 0x957f, 0xefe4, 0xe75d);
  VLOAD_16(v4, 0x7d39, 0xddd8, 0x17d7, 0x0574, 0x251a, 0x4ce4, 0x4817, 0x9de1,
           0xd773, 0xdcc8, 0xeb92, 0x8fa8, 0x9382, 0x4369, 0xb1c7, 0x9185);
  asm volatile("vwmaccu.vv v6, v2, v4");
  VSET(16, e32, m1);
  VCMP_U32(2, v6, 0x45e045d0, 0x20e0ad26, 0x1c968423, 0x6c443b32, 0x37702f57,
           0x4cd91197, 0x702b3765, 0xa43e9cc5, 0xa47055b7, 0x22beaac5,
           0x4dc2ffff, 0xbc81ce52, 0x8e38b3f3, 0x3c4e1738, 0x1e7523fb,
           0xd610159c);

  // VSET(16, e64, m1);
  // VLOAD_64(v6, 0x5118504f9237ea08, 0x6b71d4ee88073dde, 0x4420559f61e6927c,
  //          0x24eea54c6530475c, 0x289211cb16ebbbc9, 0x1a0b2b7644ecd474,
  //          0x159c16af3e71f736, 0x12dda0d2ca288012, 0x790fab107c1346b6,
  //          0x589cc8132c869645, 0x323623bba87568ce, 0x5ce2e94d5e335c5d,
  //          0x6e6b3c19c0d78ca0, 0x0502bed40a0600bc, 0x5ff6f4b3610e009c,
  //          0x40d6eb0605052915);
  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xd1247b78, 0xfd5d326b, 0x7fe40cf5, 0xfd802d90, 0x9ec23b7e,
  //          0x67219fe8, 0x9dc7f026, 0x257d8b7f, 0x782bc512, 0x42fa808b,
  //          0x48d3273d, 0x7ca0371d, 0x06409254, 0xb77ce3ba, 0x28aac174,
  //          0xd2e4cdbf);
  // VLOAD_32(v4, 0xab3b5969, 0xe91aa966, 0x336c2f4c, 0xfcc75a99, 0x1854180c,
  //          0xeec0354b, 0x8b4595bf, 0x9200fb5c, 0x0d627fcf, 0xdf0a8280,
  //          0x4b5733be, 0x4f3bd496, 0x10f5d788, 0x3499c99d, 0xdeee29dd,
  //          0x7e8643a4);
  // asm volatile("vwmaccu.vv v6, v2, v4");
  // VSET(16, e64, m1);
  // VCMP_U64(3, v6, 0xdcfc2b3ca5c34640, 0x52260af0834ff780, 0x5dd0d00a7e576638,
  //          0x1f3e3a8021c0226c, 0x37a86e0412f255b1, 0x7a39dcd00fe1b56c,
  //          0x6b728942b1a24190, 0x283f5f30c90c26b6, 0x7f5820d2b91f8e44,
  //          0x92f7bdf9f97b71c5, 0x47a4ceb4fab8af14, 0x83757ab9b866ab5b,
  //          0x6ed5464e986dd540, 0x2ab6573b8294b3ce, 0x8360dddc474a95c0,
  //          0xa91223c6b56bf471);
}

void TEST_CASE2() {
  VSET(16, e16, m1);
  VLOAD_16(v6, 0x519d, 0x7122, 0x672c, 0x4d97, 0x436e, 0x3f1f, 0x423d, 0x44e8,
           0x3d7b, 0x5570, 0x1e90, 0x79f4, 0x456b, 0x0283, 0x02b5, 0x6865);
  VSET(16, e8, m1);
  VLOAD_8(v2, 0xce, 0x96, 0x33, 0x88, 0xf8, 0x3f, 0x0c, 0xde, 0x1e, 0x9d, 0x5a,
          0x75, 0x73, 0x43, 0xd9, 0x43);
  VLOAD_8(v4, 0x51, 0x88, 0x16, 0xf6, 0x57, 0xab, 0xd8, 0x26, 0x2e, 0x35, 0x94,
          0xd1, 0xf0, 0xb9, 0x09, 0x8a);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmaccu.vv v6, v2, v4, v0.t");
  VSET(16, e16, m1);
  VCMP_U16(4, v6, 0x519d, 0xc0d2, 0x672c, 0xd047, 0x436e, 0x6934, 0x423d,
           0x65dc, 0x3d7b, 0x75f1, 0x1e90, 0xd979, 0x456b, 0x32ee, 0x02b5,
           0x8c83);

  VSET(16, e32, m1);
  VLOAD_32(v6, 0x1f50b763, 0x6d1a7f46, 0x17b8b2b5, 0x6b69c966, 0x25d945cb,
           0x3e6c375b, 0x314db8d3, 0x35ade27d, 0x74fa2d58, 0x735f513d,
           0x3cad4e4d, 0x628eb81a, 0x1c48c2f9, 0x14f08921, 0x77de05bf,
           0x528c354b);
  VSET(16, e16, m1);
  VLOAD_16(v2, 0x4ed5, 0xcf74, 0x3442, 0x280f, 0x795e, 0x3007, 0xdf3e, 0xb348,
           0x3865, 0xcb59, 0x1291, 0xa04b, 0xc5bd, 0x957f, 0xefe4, 0xe75d);
  VLOAD_16(v4, 0x7d39, 0xddd8, 0x17d7, 0x0574, 0x251a, 0x4ce4, 0x4817, 0x9de1,
           0xd773, 0xdcc8, 0xeb92, 0x8fa8, 0x9382, 0x4369, 0xb1c7, 0x9185);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmaccu.vv v6, v2, v4, v0.t");
  VSET(16, e32, m1);
  VCMP_U32(5, v6, 0x1f50b763, 0x20e0ad26, 0x17b8b2b5, 0x6c443b32, 0x25d945cb,
           0x4cd91197, 0x314db8d3, 0xa43e9cc5, 0x74fa2d58, 0x22beaac5,
           0x3cad4e4d, 0xbc81ce52, 0x1c48c2f9, 0x3c4e1738, 0x77de05bf,
           0xd610159c);

  // VSET(16, e64, m1);
  // VLOAD_64(v6, 0x5118504f9237ea08, 0x6b71d4ee88073dde, 0x4420559f61e6927c,
  //          0x24eea54c6530475c, 0x289211cb16ebbbc9, 0x1a0b2b7644ecd474,
  //          0x159c16af3e71f736, 0x12dda0d2ca288012, 0x790fab107c1346b6,
  //          0x589cc8132c869645, 0x323623bba87568ce, 0x5ce2e94d5e335c5d,
  //          0x6e6b3c19c0d78ca0, 0x0502bed40a0600bc, 0x5ff6f4b3610e009c,
  //          0x40d6eb0605052915);
  // VSET(16, e32, m1);
  // VLOAD_32(v2, 0xd1247b78, 0xfd5d326b, 0x7fe40cf5, 0xfd802d90, 0x9ec23b7e,
  //          0x67219fe8, 0x9dc7f026, 0x257d8b7f, 0x782bc512, 0x42fa808b,
  //          0x48d3273d, 0x7ca0371d, 0x06409254, 0xb77ce3ba, 0x28aac174,
  //          0xd2e4cdbf);
  // VLOAD_32(v4, 0xab3b5969, 0xe91aa966, 0x336c2f4c, 0xfcc75a99, 0x1854180c,
  //          0xeec0354b, 0x8b4595bf, 0x9200fb5c, 0x0d627fcf, 0xdf0a8280,
  //          0x4b5733be, 0x4f3bd496, 0x10f5d788, 0x3499c99d, 0xdeee29dd,
  //          0x7e8643a4);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // asm volatile("vwmaccu.vv v6, v2, v4, v0.t");
  // VSET(16, e64, m1);
  // VCMP_U64(6, v6, 0x5118504f9237ea08, 0x52260af0834ff780, 0x4420559f61e6927c,
  //          0x1f3e3a8021c0226c, 0x289211cb16ebbbc9, 0x7a39dcd00fe1b56c,
  //          0x159c16af3e71f736, 0x283f5f30c90c26b6, 0x790fab107c1346b6,
  //          0x92f7bdf9f97b71c5, 0x323623bba87568ce, 0x83757ab9b866ab5b,
  //          0x6e6b3c19c0d78ca0, 0x2ab6573b8294b3ce, 0x5ff6f4b3610e009c,
  //          0xa91223c6b56bf471);
}

void TEST_CASE3() {
  VSET(16, e16, m1);
  VLOAD_16(v6, 0x6f50, 0x0299, 0x3578, 0x0e45, 0x752b, 0x60c7, 0x7d0c, 0x0943,
           0x3f2d, 0x47bc, 0x4468, 0x616d, 0x5844, 0x3a7d, 0x32fe, 0x7813);
  VSET(16, e8, m1);
  uint64_t scalar = 5;
  VLOAD_8(v4, 0x01, 0xd6, 0x1e, 0x57, 0xcc, 0x31, 0x29, 0x06, 0x5a, 0xab, 0x1e,
          0x0a, 0x97, 0x6f, 0xe0, 0xfc);
  asm volatile("vwmaccu.vx v6, %[A], v4" ::[A] "r"(scalar));
  VSET(16, e16, m1);
  VCMP_U16(7, v6, 0x6f55, 0x06c7, 0x360e, 0x0ff8, 0x7927, 0x61bc, 0x7dd9,
           0x0961, 0x40ef, 0x4b13, 0x44fe, 0x619f, 0x5b37, 0x3ca8, 0x375e,
           0x7cff);

  VSET(16, e32, m1);
  VLOAD_32(v6, 0x681721c9, 0x5c07924a, 0x5147143e, 0x14da5785, 0x30a43e20,
           0x3498177e, 0x551df71d, 0x29656468, 0x12550807, 0x7dc95cbd,
           0x2167ff36, 0x194b0d6c, 0x79119a1d, 0x6d77fab6, 0x3e32c755,
           0x6e479bf4);
  VSET(16, e16, m1);
  scalar = 5383;
  VLOAD_16(v4, 0x9752, 0x45a4, 0xfde9, 0xa659, 0x957b, 0x1a3f, 0x2212, 0x5d43,
           0xdc08, 0x1fb8, 0x5e15, 0x08da, 0x0468, 0x4458, 0xe1e2, 0x4ef7);
  asm volatile("vwmaccu.vx v6, %[A], v4" ::[A] "r"(scalar));
  VSET(16, e32, m1);
  VCMP_U32(8, v6, 0x7484ff07, 0x61bfedc6, 0x6622229d, 0x228430f4, 0x3ceb6b7d,
           0x36bffa37, 0x57ea5f9b, 0x310e703d, 0x2467b43f, 0x806452c5,
           0x29224ac9, 0x1a052d62, 0x796e40f5, 0x7315111e, 0x50c07e83,
           0x74c407b5);

  // VSET(16, e64, m1);
  // VLOAD_64(v6, 0x27a0a02f7e9757d4, 0x7ff7bb4d394926a0, 0x09d25e3173571efd,
  //          0x11661c8ece6711ac, 0x1e5ffff32ed851dd, 0x0698334d63d206a9,
  //          0x79598c88fd85995f, 0x2fa78b4b7d90a222, 0x7d65cbfdfc7f2e1d,
  //          0x6c0101ef46924df6, 0x59ff3d4e018b50f4, 0x2c8ec8409f219401,
  //          0x20b183b4bb89c200, 0x28bee831261ca372, 0x5b9d142326bcef0a,
  //          0x1c2ad051e4e7281e);
  // VSET(16, e32, m1);
  // scalar = 6474219;
  // VLOAD_32(v4, 0x307dc235, 0x92187481, 0xa69319d1, 0x682b9abe, 0x8bdce4be,
  //          0x95ec65ce, 0x46915d6f, 0xd59243e6, 0x1d0943e5, 0x3ae27787,
  //          0x33c32e03, 0x8be66da2, 0x0fc78147, 0x2ce8d421, 0x9c9bc2fb,
  //          0x10c8c9f7);
  // asm volatile("vwmaccu.vx v6, %[A], v4" ::[A] "r"(scalar));
  // VSET(16, e64, m1);
  // VCMP_U64(9, v6, 0x27b3569317ce3b7b, 0x80301be52297620b, 0x0a12a5e3bda6ead8,
  //          0x118e4f69e7a94c16, 0x1e95f8d392f37a47, 0x06d20e0c989e38c3,
  //          0x7974c7d7abd08544, 0x2ff9f5bd60308c44, 0x7d710070e7f94e54,
  //          0x6c17bb12e5fd05e3, 0x5a1336d961fce8b5, 0x2cc4c4ceefc069b7,
  //          0x20b79a86595c2d2d, 0x28d03cbe630746bd, 0x5bd98349d9e5fe73,
  //          0x1c314a6c44597cdb);
}

void TEST_CASE4() {
  VSET(16, e16, m1);
  VLOAD_16(v6, 0x6f50, 0x0299, 0x3578, 0x0e45, 0x752b, 0x60c7, 0x7d0c, 0x0943,
           0x3f2d, 0x47bc, 0x4468, 0x616d, 0x5844, 0x3a7d, 0x32fe, 0x7813);
  VSET(16, e8, m1);
  uint64_t scalar = 5;
  VLOAD_8(v4, 0x01, 0xd6, 0x1e, 0x57, 0xcc, 0x31, 0x29, 0x06, 0x5a, 0xab, 0x1e,
          0x0a, 0x97, 0x6f, 0xe0, 0xfc);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmaccu.vx v6, %[A], v4, v0.t" ::[A] "r"(scalar));
  VSET(16, e16, m1);
  VCMP_U16(10, v6, 0x6f50, 0x06c7, 0x3578, 0x0ff8, 0x752b, 0x61bc, 0x7d0c,
           0x0961, 0x3f2d, 0x4b13, 0x4468, 0x619f, 0x5844, 0x3ca8, 0x32fe,
           0x7cff);

  VSET(16, e32, m1);
  VLOAD_32(v6, 0x681721c9, 0x5c07924a, 0x5147143e, 0x14da5785, 0x30a43e20,
           0x3498177e, 0x551df71d, 0x29656468, 0x12550807, 0x7dc95cbd,
           0x2167ff36, 0x194b0d6c, 0x79119a1d, 0x6d77fab6, 0x3e32c755,
           0x6e479bf4);
  VSET(16, e16, m1);
  scalar = 5383;
  VLOAD_16(v4, 0x9752, 0x45a4, 0xfde9, 0xa659, 0x957b, 0x1a3f, 0x2212, 0x5d43,
           0xdc08, 0x1fb8, 0x5e15, 0x08da, 0x0468, 0x4458, 0xe1e2, 0x4ef7);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmaccu.vx v6, %[A], v4, v0.t" ::[A] "r"(scalar));
  VSET(16, e32, m1);
  VCMP_U32(11, v6, 0x681721c9, 0x61bfedc6, 0x5147143e, 0x228430f4, 0x30a43e20,
           0x36bffa37, 0x551df71d, 0x310e703d, 0x12550807, 0x806452c5,
           0x2167ff36, 0x1a052d62, 0x79119a1d, 0x7315111e, 0x3e32c755,
           0x74c407b5);

  // VSET(16, e64, m1);
  // VLOAD_64(v6, 0x27a0a02f7e9757d4, 0x7ff7bb4d394926a0, 0x09d25e3173571efd,
  //          0x11661c8ece6711ac, 0x1e5ffff32ed851dd, 0x0698334d63d206a9,
  //          0x79598c88fd85995f, 0x2fa78b4b7d90a222, 0x7d65cbfdfc7f2e1d,
  //          0x6c0101ef46924df6, 0x59ff3d4e018b50f4, 0x2c8ec8409f219401,
  //          0x20b183b4bb89c200, 0x28bee831261ca372, 0x5b9d142326bcef0a,
  //          0x1c2ad051e4e7281e);
  // VSET(16, e32, m1);
  // scalar = 6474219;
  // VLOAD_32(v4, 0x307dc235, 0x92187481, 0xa69319d1, 0x682b9abe, 0x8bdce4be,
  //          0x95ec65ce, 0x46915d6f, 0xd59243e6, 0x1d0943e5, 0x3ae27787,
  //          0x33c32e03, 0x8be66da2, 0x0fc78147, 0x2ce8d421, 0x9c9bc2fb,
  //          0x10c8c9f7);
  // VLOAD_8(v0, 0xAA, 0xAA);
  // asm volatile("vwmaccu.vx v6, %[A], v4, v0.t" ::[A] "r"(scalar));
  // VSET(16, e64, m1);
  // VCMP_U64(12, v6, 0x27a0a02f7e9757d4, 0x80301be52297620b, 0x09d25e3173571efd,
  //          0x118e4f69e7a94c16, 0x1e5ffff32ed851dd, 0x06d20e0c989e38c3,
  //          0x79598c88fd85995f, 0x2ff9f5bd60308c44, 0x7d65cbfdfc7f2e1d,
  //          0x6c17bb12e5fd05e3, 0x59ff3d4e018b50f4, 0x2cc4c4ceefc069b7,
  //          0x20b183b4bb89c200, 0x28d03cbe630746bd, 0x5b9d142326bcef0a,
  //          0x1c314a6c44597cdb);
}

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}
