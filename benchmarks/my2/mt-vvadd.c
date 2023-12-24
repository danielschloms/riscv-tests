// See LICENSE for license details.

//**************************************************************************
// Vector-vector add benchmark
//--------------------------------------------------------------------------
// Author  : Andrew Waterman
// TA      : Christopher Celio
// Student :
//
// This benchmark adds two vectors and writes the results to a
// third vector. The input data (and reference data) should be
// generated using the vvadd_gendata.pl perl script and dumped
// to a file named dataset.h

//--------------------------------------------------------------------------
// Includes

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset.h"


//--------------------------------------------------------------------------
// Basic Utilities and Multi-thread Support

#include "util.h"


//--------------------------------------------------------------------------
// vvadd function

extern void __attribute__((noinline)) vvadd(int coreid, int ncores, size_t n, const data_t* x, const data_t* y, data_t* z);


static data_t results_data[DATA_SIZE];
static int idle = 1;
//--------------------------------------------------------------------------
// Main
//
// all threads start executing thread_entry(). Use their "coreid" to
// differentiate between threads (each thread is running on a separate core).
void thread2(int cid, int nc) {
    // while(idle) {}
    // barrier(nc);
    barrier(nc); vvadd(cid, nc, DATA_SIZE, results_data, input2_data, results_data); barrier(nc);
}

volatile static void (*func)(int, int) = 0;

void thread_entry(int cid, int nc) {
  // static allocates data in the binary, which is visible to both threads

  if(cid == 0) {
    size_t i;
    for (i = 0; i < DATA_SIZE; i++)
          results_data[i] = input1_data[i];
    func = thread2;
    thread2(cid, nc);
    int res;
    res = verifyDouble(DATA_SIZE, results_data, verify_data);
    printf("res=%d\n", res);
    if(res) exit(res);
  } else {
    while (!func) {printf("a\n");}
    func(cid, nc);
    func = 0;
  }
  barrier(nc);


  exit(0);
}
