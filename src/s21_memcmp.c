#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ptr1 = (const unsigned char *)str1;
  const unsigned char *ptr2 = (const unsigned char *)str2;
  int result = 0;
  s21_size_t size_of_c = sizeof(str1[0]);

  for (s21_size_t i = 0; i < n / size_of_c; i++) {
    if (ptr1[i] != ptr2[i]) {
      result = ptr1[i] - ptr2[i];
      break;
    }
  }
  return result;
}
// APPROVED & REQUIRES FUTURE TESTING