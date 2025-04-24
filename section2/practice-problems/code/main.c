#include <limits.h>
#include <stdint.h> // for int64_t
#include <stdio.h>  // for printf

int main() {

  int ival = 12345;
  float fval = 12345.0;

  uint32_t u = UINT_MAX; // 11111111111111111111111111111111 32bits
  uint64_t x = UINT_MAX; // 11111111111111111111111111111111 32bits
  unsigned long z = ULONG_MAX; // 1111111111111111111111111111111111111111111111111111111111111111
                               // 64bits
  return 0;
}
