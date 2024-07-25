#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t length = s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++) {
    dest[length + i] = src[i];
  }
  dest[length + n] = '\0';
  return dest;
}
// APPROVED & NEED MORE TESTS