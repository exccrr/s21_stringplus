#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t span = 0;
  short match = 0;
  for (int i = 0; str1[i] != '\0' && match == 0; i++) {
    for (int j = 0; str2[j] != '\0' && match == 0; j++) {
      if (str1[i] == str2[j]) match = 1;
    }
    if (match == 0) span++;
  }
  return span;
}
// APPROVED && REQUIRES FUTURE TESTING