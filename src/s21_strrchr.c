#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = s21_NULL;
  int size = s21_strlen(str);
  for (int i = size; result == s21_NULL && i >= 0; i--) {
    if (str[i] == c) result = (str + i);
  }
  return (char *)result;
}
// APPROVED & NEED MORE TESTS