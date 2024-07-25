#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  int index = 0;
  s21_size_t needle_len = s21_strlen(needle);
  if (needle_len == 0) result = (char *)&haystack[index];
  while (haystack[index] != '\0' && result == s21_NULL) {
    for (s21_size_t i = 0; i < needle_len; i++) {
      if (haystack[index + i] != needle[i]) break;
      if (i + 1 == needle_len) result = (char *)&haystack[index];
    }
    index++;
  }
  return result;
}
// APPROVED