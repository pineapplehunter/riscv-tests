// See LICENSE for license details.

//**************************************************************************
// Median filter bencmark
//--------------------------------------------------------------------------
//
// This benchmark performs a 1D three element median filter. The
// input data (and reference data) should be generated using the
// median_gendata.pl perl script and dumped to a file named
// dataset1.h.

#include "util.h"

#include "median.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"

//--------------------------------------------------------------------------
// Main

int main(int argc, char *argv[]) {
  short results_data[DATA_SIZE];

  // #if PREALLOCATE
  //   // If needed we preallocate everything in the caches
  //   median2(DATA_SIZE, input_data, results_data);
  // #endif

  // Do the filter
  setStats(1);
  median2(DATA_SIZE, input_data, results_data);
  setStats(0);

  int threadid = read_csr(mhartid);
  if (threadid == 0)
    printf("median done\n");

  // Check the results
  if (threadid == 0) {
    for (int i = 0; i < DATA_SIZE; i++)
      printf("%d, ", results_data[i]);
    printf("\n");
    int res = verifyShort(DATA_SIZE, results_data, verify_data);
    printf("verify done with %d\n", res);
    return res;
  } else {
    while (1)
      ;
  }
}

thread_entry(int cid, int nc) {}
