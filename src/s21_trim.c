#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src && trim_chars) {
    char *start_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);

    for (; *start_str && s21_strchr(trim_chars, *start_str); start_str++)
      ;
    for (; end_str != start_str && s21_strchr(trim_chars, *(end_str - 1));
         end_str--)
      ;
    result = (char *)calloc(end_str - start_str + 1, sizeof(char));

    if (result) {
      s21_memcpy(result, start_str, end_str - start_str);
      result[end_str - start_str] = '\0';
    }
  }

  return result;
}
