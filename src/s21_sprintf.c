#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *p = "";
  int res = 0;
  int precision = 6;
  va_list args;
  va_start(args, format);
  char temp[S21_TEXTMAX];
  int size = (int)s21_strlen(format);
  int i = 0;
  long long num = -1;
  int minus_flag = 0;
  int num_flag = 0;
  s21_size_t len = 0;
  while (*format != 0 && i < size) {
    if (*format++ == '%') {
      if (*format == '-') {
        minus_flag = 1;
        format++;
      }
      s21_size_t width = 0;
      if (*format >= '0' && *format <= '9') {
        width = get_num((char **)&format);
      }
      if (*format == '+') {
        handle_plus_flag(args, str, &i, &num, &num_flag);
        format++;
      } else if (*format == ' ') {
        handle_space_flag(args, str, &i, &num, &num_flag);
        format++;
      }
      if (*format == '.') {
        format++;
        precision = get_num((char **)&format);
      }
      if (*format == 'h') {
        format++;
        num = cast_to_short(args, format, &num_flag);
        num_flag = 1;
      }
      if (*format == 'l') {
        format++;
        num = cast_to_long(args, format);
        num_flag = 1;
      }
      if (*format == 'l') {
        format++;
        num = cast_to_long(args, format);
      }
      switch (*format++) {
        case 'c':
          handle_char(args, str, &i, width, &size, &minus_flag);
          break;
        case 'd':
          handle_decimal(temp, args, p, len, &i, str, num, &size, width,
                         &num_flag, &minus_flag);
          break;
        case 'f':
          handle_float(args, p, temp, len, &i, str, precision, &size, width,
                       &minus_flag);
          break;
        case 's':
          handle_string(args, p, len, &i, str, width, &size, &minus_flag);
          break;
        case 'o':
          handle_octal(args, str, &i, num, width, &size, &minus_flag);
          break;
        case 'x':
          handle_hex(args, str, &i, 1, num, width, &size, &minus_flag);
          break;
        case 'X':
          handle_hex(args, str, &i, 0, num, width, &size, &minus_flag);
          break;
        case 'u':
          handle_unsigned(temp, args, p, len, &i, str, &size, num, width,
                          &num_flag, &minus_flag);
          break;
        case '%':
          handle_percent(str, &i, &size);
      }
    } else {
      str[i++] = *(format - 1);
      str[i] = 0;
    }
  }
  va_end(args);
  return res;
}

void handle_plus_flag(va_list args, char *str, int *i, long long int *num,
                      int *num_flag) {
  *num = va_arg(args, int);
  *num_flag = 1;
  if (*num >= 0) {
    s21_memset(&str[*i], '+', 1);
    *i += 1;
  }
}

void handle_space_flag(va_list args, char *str, int *i, long long int *num,
                       int *num_flag) {
  *num = va_arg(args, int);
  *num_flag = 1;
  if (*num >= 0) {
    s21_memset(&str[*i], ' ', 1);
    *i += 1;
  }
}

int get_num(char **str) {
  char ch;
  char temp[10];
  char *copy = temp;
  char *str_copy = *str;
  while ((ch = *str_copy) != '.' && ch < ':') {
    *copy++ = ch;
    str_copy++;
  }
  *str = str_copy;
  *copy = 0;
  return atoi(temp);
}

void fill_width_padding(s21_size_t num_padding, char *str, int *i, int *size,
                        int *minus_flag) {
  char padding = ' ';
  for (int j = 0; j < (int)num_padding; j++) {
    s21_strncat(str, &padding, 1);
    (*i)++;
    (*size)++;
  }
  *minus_flag = 0;
}

void handle_char(va_list args, char *str, int *i, s21_size_t width, int *size,
                 int *minus_flag) {
  char c = va_arg(args, int);
  if (width > 1 && !*minus_flag) {
    s21_size_t num_padding = width - 1;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
  str[*i] = c;
  *i += 1;
  *size += 1;
  if (*minus_flag && width > 1) {
    s21_size_t num_padding = width - 1;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
}

void handle_decimal(char *temp, va_list args, char *p, s21_size_t len, int *i,
                    char *str, long long int num, int *size, s21_size_t width,
                    int *num_flag, int *minus_flag) {
  if (*num_flag) {
    p = s21_itoa(S21_TEXTMAX, temp, (int)num);
    *num_flag = 0;
  } else {
    p = s21_itoa(S21_TEXTMAX, temp, va_arg(args, int));
  }
  len = s21_strlen(p);
  if (width > len && !*minus_flag) {
    s21_size_t num_padding = width - len;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
  s21_strncat(str, p, len);
  *i += len;
  *size += len;
  if (*minus_flag && width > len) {
    s21_size_t num_padding = width - len;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
}

void handle_float(va_list args, char *p, char *temp, s21_size_t len, int *i,
                  char *str, int precision, int *size, s21_size_t width,
                  int *minus_flag) {
  float value = (float)va_arg(args, double);
  p = s21_ftoa(temp, S21_TEXTMAX, value, precision);
  len = s21_strlen(p);
  if (width > len && !*minus_flag) {
    s21_size_t num_padding = width - len;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
  s21_strncat(&str[*i], p, len);
  *i += len;
  *size += len;
  if (*minus_flag && width > len) {
    s21_size_t num_padding = width - len;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
}

void handle_string(va_list args, char *p, unsigned char len, int *i, char *str,
                   s21_size_t width, int *size, int *minus_flag) {
  p = va_arg(args, char *);
  len = (unsigned char)s21_strlen(p);
  if (width > len && !*minus_flag) {
    s21_size_t num_padding = width - len;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
  s21_memset(&str[*i], ' ', 0);
  s21_strncat(&str[*i], p, len);
  *i += len;
  *size += len;
  if (*minus_flag && width > len) {
    s21_size_t num_padding = width - len;
    fill_width_padding(num_padding, str, i, size, minus_flag);
  }
}

void handle_octal(va_list args, char *str, int *i, long long int num,
                  s21_size_t width, int *size, int *minus_flag) {
  if (num == -1) {
    num = va_arg(args, int);
  }
  if (num == 0) {
    if (width > 0 && !*minus_flag) {
      int num_padding = (int)width - 1;
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
    s21_memset(&str[*i], '0', 1);
    *i += 1;
    *size += 1;
  } else {
    char str2[100] = "";
    int rez = 0;
    int j = 0;
    while (num != 0 && num > 0) {
      rez = num % 8;
      num = num / 8;
      s21_memset(&str2[j], rez + '0', 1);
      j++;
    }
    s21_reverse(str2);
    s21_size_t len_str2 = s21_strlen(str2);
    if (width > len_str2 && !*minus_flag) {
      int num_padding = (int)(width - len_str2);
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
    s21_memcpy(&str[*i], str2, len_str2);
    *i += len_str2;
    *size += len_str2;
    if (*minus_flag && width > len_str2) {
      s21_size_t num_padding = width - len_str2;
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
  }
}

void handle_hex(va_list args, char *str, int *i, int spec_x, long long int num,
                s21_size_t width, int *size, int *minus_flag) {
  if (num == -1) {
    num = va_arg(args, int);
  }
  if (num == 0) {
    if (width > 0 && !*minus_flag) {
      int num_padding = (int)width - 1;
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
    s21_memset(&str[*i], '0', 1);
    *i += 1;
    *size += 1;
  } else {
    char str2[100] = "";
    int rez = 0;
    int j = 0;
    char *format = spec_x ? "0123456789abcdef" : "0123456789ABCDEF";
    while (num != 0 && num > 0) {
      rez = num % 16;
      num = num / 16;
      if (rez) s21_memset(&str2[j], format[rez], 1);
      j++;
    }
    s21_reverse(str2);
    s21_size_t len_str2 = s21_strlen(str2);
    if (width > len_str2 && !*minus_flag) {
      s21_size_t num_padding = width - len_str2;
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
    s21_memcpy(&str[*i], str2, len_str2);
    *i += len_str2;
    *size += len_str2;
    if (*minus_flag && width > len_str2) {
      s21_size_t num_padding = width - len_str2;
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
  }
}

char *s21_itoa(int input, char *buff, int num) {
  int base = 10;
  char *p;
  if (num < 0) {
    num = -num;
    p = s21_convert(buff, input, num, base);
    *--p = '-';
  } else {
    p = s21_convert(buff, input, num, base);
  }
  return p;
}

char *s21_convert(char *buff, int size, unsigned int num, int base) {
  char *p;
  p = &buff[size - 1];
  *p = '\0';
  if (num != 0) {
    while (num != 0) {
      *--p = "0123456789ABCDEF"[num % base];
      num /= base;
    }
  } else {
    *--p = '0';
  }
  return p;
}

char *s21_reverse(char *str) {
  char tmp;
  s21_size_t i, j;
  s21_size_t len_str = s21_strlen(str);
  for (i = 0, j = len_str - 1; i < j; i++, j--) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
  return str;
}

char *f_to_str(char *buff, int size, float value, int digits, int *flag) {
  int i = 0;
  int factor = 10;
  int num = (int)value;
  int sub;
  char *p;
  p = &buff[size - 1];
  *p = '\0';
  if (value < 0) {
    num *= -1;
    value *= -1;
  }
  while (i++ < digits) {
    value = value * factor;
    num = num * factor;
    sub = value - num;
    *(p - digits) = sub + '0';
    p++;
    num += sub;
  }
  i = 0;
  int copy_value = value * 10;
  if (copy_value % 10 >= 5) {
    num = num + 1;
    double ost = num - value;
    if (ost <= 0.11573) {
      *flag = 1;
    }
    while (i++ < digits) {
      p--;
      *(p - digits) = (num % 10) + '0';
      num = num / 10;
    }
  }
  return &buff[size - 1] - digits;
}

char *s21_ftoa(char *buff, int size, float value, int digits) {
  char *p;
  int flag = 0;
  char *q;
  p = f_to_str(buff, size, value, digits, &flag);
  if (*p != '\0') {
    *--p = '.';
  }
  if (flag == 1) {
    value += 1;
  }
  q = s21_itoa((int)(p - &buff[0]), buff, (int)value);
  if (value > -1 && value < 0) {
    *--q = '-';
  }
  int p_count = (int)s21_strlen(p);
  s21_strncat(q, p, p_count);
  return q;
}

long long cast_to_short(va_list args, const char *format, int *num_flag) {
  long long int num;
  if (*format == 'd' || *format == 'i') {
    num = (short int)va_arg(args, long long int);
  } else {
    num = (unsigned short)va_arg(args, long long int);
  }
  *num_flag = 1;
  return num;
}

long long cast_to_long(va_list args, const char *format) {
  long long num;
  if (*format == 'd' || *format == 'i') {
    num = (long)va_arg(args, long long);
  } else {
    num = (unsigned long)va_arg(args, long long);
  }
  return num;
}

void s21_utoa(long long int n, char s[]) {
  long long int sign;
  int i;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  s21_reverse(s);
}

void handle_unsigned(char *temp, va_list args, char *p, unsigned char len,
                     int *i, char *str, int *size, long long num,
                     s21_size_t width, int *num_flag, int *minus_flag) {
  if (num == -1 && !*num_flag) {
    num = va_arg(args, unsigned int);
  }
  if ((num >= 0) && num <= INT_MAX) {
    *num_flag = 1;
    handle_decimal(temp, args, p, len, i, str, num, size, width, num_flag,
                   minus_flag);
  } else {
    char str2[1000];
    s21_utoa(num, str2);
    s21_size_t len_str2 = s21_strlen(str2);
    if (width > len_str2 && !*minus_flag) {
      s21_size_t num_padding = width - len_str2;
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
    s21_memcpy(&str[*i], str2, len_str2);
    *i += len_str2;
    *size += len_str2;
    if (*minus_flag && width > len) {
      s21_size_t num_padding = width - len;
      fill_width_padding(num_padding, str, i, size, minus_flag);
    }
  }
}

void handle_percent(char *str, int *i, int *size) {
  s21_memset(&str[*i], '%', 1);
  *i += 1;
  *size += 1;
}