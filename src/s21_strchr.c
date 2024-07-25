#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  int index = 0;
  while (str[index] != '\0') {
    if (str[index] == c) {
      result = (char *)&str[index];
      break;
    }
    index++;
  }
  if (c == '\0') result = "";
  return result;
}
// APPROVED