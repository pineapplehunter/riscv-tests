// See LICENSE for license details.

//**************************************************************************
// Median filter (c version)
//--------------------------------------------------------------------------

#include "median.h"
#include "encoding.h"

void median1(int n, DTYPE input[], DTYPE results[]) {
  int A, B, C, i;

  // Zero the ends
  results[0] = 0;
  results[n - 1] = 0;

  // Do the filter
  for (i = 1; i < (n - 1); i++) {

    A = input[i - 1];
    B = input[i];
    C = input[i + 1];

    if (A < B) {
      if (B < C)
        results[i] = B;
      else if (C < A)
        results[i] = A;
      else
        results[i] = C;
    }

    else {
      if (A < C)
        results[i] = A;
      else if (C < B)
        results[i] = B;
      else
        results[i] = C;
    }
  }
}

static volatile int finish_count = 0;

const int from_arr[4] = {1, 100, 200, 300};
const int to_arr[4] = {100, 200, 300, 399};

void median2(int n, DTYPE input[], DTYPE results[]) {
  int threadid = read_csr(mhartid);

  int from = from_arr[threadid];
  int to = to_arr[threadid];

  // Zero the ends
  results[0] = 0;
  results[n - 1] = 0;

  // Do the filter
  for (int i = from; i < to; i++) {

    int A = input[i - 1];
    int B = input[i];
    int C = input[i + 1];

    if (A < B) {
      if (B < C)
        results[i] = B;
      else if (C < A)
        results[i] = A;
      else
        results[i] = C;
    }

    else {
      if (A < C)
        results[i] = A;
      else if (C < B)
        results[i] = B;
      else
        results[i] = C;
    }
  }

  int one = 1;
  asm("amoadd.w zero,%[one],(%[ptr])"
      :
      : [one] "r"(one), [ptr] "r"(&finish_count));

  while (finish_count != CORE_COUNT)
    ;
  return;
}

const int elements_at_once = 64 / sizeof(DTYPE);
