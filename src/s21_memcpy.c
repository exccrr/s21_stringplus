#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *pdest = (unsigned char *)dest;
  const unsigned char *psrc = (const unsigned char *)src;
  s21_size_t size_of_c = sizeof(src[0]);

  for (s21_size_t i = 0; i < n / size_of_c; i++) {
    pdest[i] = psrc[i];
  }
  return dest;
}
// APPROVED & REQUIRES FUTURE TESTING