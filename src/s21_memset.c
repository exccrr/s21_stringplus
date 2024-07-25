#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  s21_size_t size_of_c = sizeof(str[0]);

  for (s21_size_t i = 0; i < n / size_of_c; i++) {
    ptr[i] = (unsigned char)c;
  }
  return str;
}
// APPROVED & REQUIRES FUTURE TESTING