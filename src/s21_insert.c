#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const void *src, const void *str, s21_size_t start_index) {
  void *result = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    const unsigned char *psrc = (const unsigned char *)src;
    const unsigned char *pstr = (const unsigned char *)str;

    s21_size_t size_of_str = s21_strlen((const char *)pstr);
    s21_size_t size_of_src = s21_strlen((const char *)psrc);

    result =
        calloc(size_of_src + size_of_str + 1, 1);  // Allocate memory properly
    if (result != s21_NULL && start_index <= size_of_src) {
      s21_memcpy(result, psrc, start_index);
      s21_memcpy((unsigned char *)result + start_index, pstr, size_of_str);
      s21_memcpy((unsigned char *)result + start_index + size_of_str,
                 psrc + start_index, size_of_src - start_index);

      ((char *)result)[size_of_src + size_of_str] =
          '\0';  // Add null terminator
    }

    else {
      result = s21_NULL;
    }
  }

  return result;
}
// APPROVED
