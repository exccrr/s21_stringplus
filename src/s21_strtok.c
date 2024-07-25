#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = s21_NULL;
  if (str != s21_NULL) {
    next_token = str;
  } else if (next_token == s21_NULL) {
    return s21_NULL;  // No more tokens
  }

  // Skipping leading delimiters
  while (*next_token != '\0' && s21_strchr(delim, *next_token) != s21_NULL) {
    next_token++;
  }

  if (*next_token == '\0') {
    return s21_NULL;  // No more tokens
  }

  char *result = next_token;

  // Finding the end of the current token
  while (*next_token != '\0' && s21_strchr(delim, *next_token) == s21_NULL) {
    next_token++;
  }

  if (*next_token != '\0') {
    *next_token = '\0';  // Replace delimiter with s21_NULL terminator
    next_token++;        // Move to the next character after the delimiter
  } else {
    next_token = s21_NULL;  // No more tokens after this
  }

  return result;
}

// APPROVED & REQUIRES FURTHER TESTING