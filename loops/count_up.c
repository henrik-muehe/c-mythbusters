#include <stdint.h>

int main() {
  int64_t i;
  for (i=0; i<100000000ll; ++i) {
    asm("nop");
  }
}
