#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *newstr = s21_NULL;
  s21_size_t size = s21_strlen(str);
  newstr = (char *)calloc(size + 1, 1);
  for (unsigned long long i = 0; i < size; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      newstr[i] = str[i] - 32;
    } else {
      newstr[i] = str[i];
    }
  }
  return newstr;
}