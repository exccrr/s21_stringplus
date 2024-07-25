#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  const unsigned char *pstr1 = (const unsigned char *)str1;
  for (int i = 0; str1[i] != '\0' && result == s21_NULL; i++) {
    for (int j = 0; str2[j] != '\0' && result == s21_NULL; j++) {
      if (str1[i] == str2[j]) {
        result = (char *)&pstr1[i];
        break;
      }
    }
  }
  return result;
}
// APPROVED & REQUIRES FUTURE TESTING