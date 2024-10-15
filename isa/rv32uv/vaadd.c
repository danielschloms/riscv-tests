// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

// Rounding mode rnu
void TEST_CASE1(void) {
  __asm__ volatile("csrwi vxrm, 0");
  VSET(4, e8, m1);
  VLOAD_8(v1, 2, -2, -3, 4);
  VLOAD_8(v2, 3, 3, -3, 4);
  __asm__ volatile("vaadd.vv v3, v1, v2" ::);
  VCMP_I8(1, v3, 3, 1, -3, 4);
}

void TEST_CASE2(void) {
  __asm__ volatile("csrwi vxrm, 0");
  VSET(4, e8, m1);
  VLOAD_8(v1, 1, -2, -3, 4);
  VLOAD_8(v2, 1, 3, -3, 4);
  VLOAD_8(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vv v3, v1, v2, v0.t" ::);
  VCMP_I8(2, v3, 0, 1, 0, 4);
}

void TEST_CASE3(void) {
  __asm__ volatile("csrwi vxrm, 0");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 4, -4);
  const uint32_t scalar = 5;
  __asm__ volatile("vaadd.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_I32(3, v3, 3, 2, 5, 1);
}

// Dont use VCLEAR here, it results in a glitch where are values are off by 1
void TEST_CASE4(void) {
  __asm__ volatile("csrwi vxrm, 0");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 3, -4);
  const uint32_t scalar = 5;
  VLOAD_32(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_I32(4, v3, 0, 2, 0, 1);
}

// Rounding mode rne
void TEST_CASE5(void) {
  __asm__ volatile("csrwi vxrm, 1");
  VSET(4, e8, m1);
  VLOAD_8(v1, 2, -2, -3, 4);
  VLOAD_8(v2, 3, 2, -3, 4);
  __asm__ volatile("vaadd.vv v3, v1, v2" ::);
  VCMP_I8(1, v3, 2, 0, -3, 4);
}

void TEST_CASE6(void) {
  __asm__ volatile("csrwi vxrm, 1");
  VSET(4, e8, m1);
  VLOAD_8(v1, 1, -2, -3, 4);
  VLOAD_8(v2, 1, 2, -3, 4);
  VLOAD_8(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vv v3, v1, v2, v0.t" ::);
  VCMP_I8(2, v3, 0, 0, 0, 4);
}

void TEST_CASE7(void) {
  __asm__ volatile("csrwi vxrm, 1");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 3, -4);
  const uint32_t scalar = 5;
  __asm__ volatile("vaadd.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_I32(3, v3, 3, 2, 4, 0);
  int a = 5;
}

// Dont use VCLEAR here, it results in a glitch where are values are off by 1
void TEST_CASE8(void) {
  __asm__ volatile("csrwi vxrm, 1");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 3, -4);
  const uint32_t scalar = 5;
  VLOAD_32(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_I32(4, v3, 0, 2, 0, 0);
}

// Rounding mode rdn
void TEST_CASE9(void) {
  __asm__ volatile("csrwi vxrm, 2");
  VSET(4, e8, m1);
  VLOAD_8(v1, 1, -2, -3, 4);
  VLOAD_8(v2, 1, 2, -3, 4);
  __asm__ volatile("vaadd.vv v3, v1, v2" ::);
  VCMP_I8(1, v3, 1, 0, -3, 4);
}

void TEST_CASE10(void) {
  __asm__ volatile("csrwi vxrm, 2");
  VSET(4, e8, m1);
  VLOAD_8(v1, 1, -2, -3, 4);
  VLOAD_8(v2, 1, 2, -3, 4);
  VLOAD_8(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vv v3, v1, v2, v0.t" ::);
  VCMP_I8(2, v3, 0, 0, 0, 4);
}

void TEST_CASE11(void) {
  __asm__ volatile("csrwi vxrm, 2");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 3, -4);
  const uint32_t scalar = 5;
  __asm__ volatile("vaadd.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_I32(3, v3, 3, 1, 4, 0);
}

// Dont use VCLEAR here, it results in a glitch where are values are off by 1
void TEST_CASE12(void) {
  __asm__ volatile("csrwi vxrm, 2");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 3, -4);
  const uint32_t scalar = 5;
  VLOAD_32(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_I32(4, v3, 0, 1, 0, 0);
}

// Rounding mode rod
void TEST_CASE13(void) {
  __asm__ volatile("csrwi vxrm, 3");
  VSET(4, e8, m1);
  VLOAD_8(v1, 1, -2, -3, 4);
  VLOAD_8(v2, 1, 2, -3, 4);
  __asm__ volatile("vaadd.vv v3, v1, v2" ::);
  VCMP_I8(1, v3, 1, 0, -3, 4);
}

void TEST_CASE14(void) {
  __asm__ volatile("csrwi vxrm, 3");
  VSET(4, e8, m1);
  VLOAD_8(v1, 1, -2, -3, 4);
  VLOAD_8(v2, 1, 2, -3, 4);
  VLOAD_8(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vv v3, v1, v2, v0.t" ::);
  VCMP_I8(2, v3, 0, 0, 0, 4);
}

void TEST_CASE15(void) {
  __asm__ volatile("csrwi vxrm, 3");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 3, -4);
  const uint32_t scalar = 5;
  __asm__ volatile("vaadd.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_I32(3, v3, 3, 1, 4, 1);
}

// Dont use VCLEAR here, it results in a glitch where are values are off by 1
void TEST_CASE16(void) {
  __asm__ volatile("csrwi vxrm, 3");
  VSET(4, e32, m1);
  VLOAD_32(v1, 1, -2, 3, -4);
  const uint32_t scalar = 5;
  VLOAD_32(v0, 0xA, 0x0, 0x0, 0x0);
  VCLEAR(v3);
  __asm__ volatile("vaadd.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_I32(4, v3, 0, 1, 0, 1);
}

int main(void) {
  INIT_CHECK();
  enable_vec();
  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();
  TEST_CASE5();
  TEST_CASE6();
  TEST_CASE7();
  TEST_CASE8();
  TEST_CASE9();
  TEST_CASE10();
  TEST_CASE11();
  TEST_CASE12();
  TEST_CASE13();
  TEST_CASE14();
  TEST_CASE15();
  TEST_CASE16();
  EXIT_CHECK();
}
