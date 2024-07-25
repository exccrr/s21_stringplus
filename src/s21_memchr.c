#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)str;

  s21_size_t size_of_c = sizeof(str[0]);
  void *result = s21_NULL;
  for (s21_size_t i = 0; i < n / size_of_c; i++) {
    if (ptr[i] == (unsigned char)c) {
      result = (void *)&ptr[i];
      break;
    }
  }
  return result;
}
// APPROVED & REQUIRES FUTURE TESTING