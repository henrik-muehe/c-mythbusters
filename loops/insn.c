#include <stdint.h>
#include <assert.h>

__attribute__((noinline))
void insn_down(int argc) {
  const int64_t l=100000000ll+argc;
  for (int64_t i=l; i!=0; --i) asm volatile("nop"::"r"(i));
}

__attribute__((noinline))
void insn_up_lt(int argc) {
  const int64_t l=100000000ll+argc;
    for (int64_t i=0; i < l; ++i) asm volatile ("nop"::"r"(i));
}

__attribute__((noinline))
void insn_up_eq(int argc) {
  const int64_t l=100000000ll+argc;
    for (int64_t i=0; i!=l; ++i) asm volatile ("nop"::"r"(i));
}

int main(int argc,char* argv[]) {
  char c=(argc>1)?argv[1][0]:0;
  if (c=='u') {
    insn_up_eq(argc);
  } else if (c=='d') {
    insn_down(argc);
  } else if (c=='l') {
    insn_up_lt(argc);
  } else assert(0&&"unknown case specified");
}
