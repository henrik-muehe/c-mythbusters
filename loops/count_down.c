#include <stdint.h>
int main() {
  for (int64_t i=100000000ll; i!=0; --i) {
    asm("nop");
  }
}

