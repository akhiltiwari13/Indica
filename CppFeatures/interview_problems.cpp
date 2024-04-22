/* some cpp problems encountered over the time. some of them are cpp version
 * specific. */
#include <iostream>
#include <sys/_types/_int32_t.h>

using namespace std;

/* The `sizeof` operator returns the size of an object in bytes. The size of a
 * `struct` is determined by the size of its members and the padding added by
 * the compiler to ensure proper alignment of its members in memory. The size of
 * the `struct sz` you provided depends on the compiler and the architecture it
 * is being compiled for. */

/* In general, the size of a `struct` is at least as large as the sum of the
 * sizes of its members, but it can be larger due to padding. For example, on a
 * typical x86-64 architecture with 8-byte alignment, the size of `struct sz`
 * would be 16 bytes. This is because the `int8_t` member `f1` would take up 1
 * byte, followed by 1 byte of padding to align the `int16_t` member `f2`, which
 * takes up 2 bytes. The next member, `int32_t f3`, would require 4-byte
 * alignment, so 2 more bytes of padding would be added before it. The last
 * member, `int32_t f4`, would take up another 4 bytes, bringing the total size
 * to 16 bytes. */

/* It's important to note that this is just one possible result and that the
 * actual size may vary depending on the compiler and architecture. You can use
 * the `sizeof` operator to determine the exact size of the `struct` on your
 * system. For example, you could write a simple program like this: */

/* #pragma pack(8) */
struct sz {
  int16_t f2{};
  int8_t f1{};
  int32_t f3{};
  int32_t f4{};
  int64_t f5{};
};

/* Yes, it is possible that `sizeof(sz)` returns 12 on an M1 Mac. The M1 chip is based on the ARM architecture, which has different alignment requirements than the x86-64 architecture. On ARM, the natural alignment of a `struct` is determined by the largest alignment requirement of its members. In the case of `struct sz`, the largest alignment requirement is 4 bytes (for the `int32_t` members), so the `struct` will be aligned on a 4-byte boundary. */

/* This means that the `int8_t` member `f1` will take up 1 byte, followed by 1 byte of padding to align the `int16_t` member `f2`, which takes up 2 bytes. The next member, `int32_t f3`, is already aligned on a 4-byte boundary, so no additional padding is needed. The last member, `int32_t f4`, takes up another 4 bytes, bringing the total size to 12 bytes. */

/* It's important to note that this is just one possible result and that the actual size may vary depending on the compiler and its settings. You can use the `sizeof` operator to determine the exact size of the `struct` on your system. */


/* for testing. */
int main(int argc, char *argv[]) {
  // size of unpacked struct
  sz szobj{};

  cout << "sizeof(sz): " << sizeof(szobj) << std::endl;
  cout << "alignof(sz): " << alignof(szobj) << std::endl;

  return 0;
}
