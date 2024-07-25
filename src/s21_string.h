#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#define s21_NULL ((void *)0)
#define S21_TEXTMAX 2048

typedef unsigned long s21_size_t;

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strerror(int errnum);
void *s21_insert(const void *src, const void *str, s21_size_t start_index);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *src, const char *format, ...);
typedef struct {
  int star;
  int width;
  int len_h;
  int len_l;
  int len_L;
} currentFlagParameters;

typedef struct {
  int c;
  int d;
  int i;
  int e;
  int E;
  int f;
  int g;
  int G;
  int o;
  int s;
  int u;
  int x;
  int X;
  int p;
  int n;
} specifiers;

void writeFlag(specifiers *spec, char ch);
int find_space(char c);
int isNum(char c);
double checkNAN(char *str);
double checkINF(char *str);
int getChar(char *str);
void skip_space(char **src);
void extractSubstring(char **src, char **buf, char **temp, int *len,
                      currentFlagParameters *flag);
void copySubstring(char *destination, char *source, int length);
int getFloatLength(char *str);
int searchSpecificators(int *index, const char *format, specifiers *specifier);
void searchLengthFlags(currentFlagParameters *fl, const char *ch, int i);
int searchTypeSpecificators(int *begin, const char *format,
                            currentFlagParameters *flags);
int searchWidth(int *start, const char *format, currentFlagParameters *flags);
long double convertToDouble(char *str);
void convert_double(long double num, void *ptr, currentFlagParameters *f);
long long int convertToInt(const char *str);
void convert_int(long long int num, void *ptr, currentFlagParameters *f);
void convert_uni(va_list args, char *temp, currentFlagParameters *flag);
void get_hex(char **src, char *buf, specifiers *spec, int *len, int *sdvig);
void convert_size_hex(currentFlagParameters *f, va_list args,
                      long long unsigned int *num, specifiers *spec);
void get_string(va_list args, currentFlagParameters *flag, char *t1,
                specifiers *s);
int parser(const char *format, int *index, specifiers *spec,
           currentFlagParameters *fl, int *stop);
void scan_d(char **src, currentFlagParameters *flag, va_list args, int *count,
            int *stop_scan, int *for_n);
void scan_i(char **src, specifiers *spec);
void scan_u(char **src, currentFlagParameters *flag, va_list args, int *count,
            int *stop_scan, int *for_n);
void scan_n(va_list args, currentFlagParameters *flag, int *stop_scan,
            int *for_n);
void scan_f(char **src, va_list args, currentFlagParameters *flag, int *count,
            int *stop_scan, int *for_n);
void scan_s(char **str, va_list args, currentFlagParameters *flag, int *count,
            specifiers *s, int *stop_scan, int *skip, int *for_n);
void scan_x(char **src, currentFlagParameters *f, va_list args,
            specifiers *spec, int *result, int *stop_scan, int *for_n);

long long unsigned int convertToHexadecimal(char *str, specifiers *spec,
                                            int *sign);

void checkPowerHexadecimal(char *str, long long unsigned int *num, int *i,
                           int *powd, specifiers *spec);

void convertTo16(char *str, long long unsigned int *num, int *i, int *powd);

int search_hex(const char *str, specifiers *spec);
int sscanf(const char *str, const char *format, ...);
wchar_t *wcscpy(wchar_t *dest, const wchar_t *src);
char *s21_itoa(int input, char *buff, int num);
char *s21_convert(char *buff, int size, unsigned int num, int base);
void d_specific(char *temp, va_list list, char *p, s21_size_t len, int *i,
                char *str, long long int num, int *size, s21_size_t width,
                int *num_flag, int *minus_flag);
void c_specific(va_list list, char *str, int *i, s21_size_t width, int *size,
                int *minus_flag);
void f_specific(va_list, char *, char *, s21_size_t, int *, char *, int, int *,
                s21_size_t width, int *minus_flag);
void s_specific(va_list, char *, unsigned char, int *, char *, s21_size_t width,
                int *size, int *minus_flag);
void flag_plus(va_list list, char *str, int *i, long long int *num,
               int *num_flag);
void flag_space(va_list list, char *str, int *i, long long int *num,
                int *num_flag);
char *s21_ftoa(char *buff, int size, float val, int digits);
int get_num(char **str);
int atoi(const char *str);
void o_specific(va_list list, char *str, int *i, long long int num,
                s21_size_t width, int *size, int *minus_flag);
char *s21_reverse(char *str);
void x_specific(va_list list, char *str, int *i, int spec_x, long long int num,
                s21_size_t width, int *size, int *minus_flag);
void percent_specific(char *str, int *i, int *size);
long long cast_to_h(va_list list, const char *format, int *num_flag);
void u_specific(char *temp, va_list list, char *p, unsigned char len, int *i,
                char *str, int *size, long long int num, s21_size_t width,
                int *num_flag, int *minus_flag);
void s21_utoa(long long int n, char s[]);
long long cast_to_l(va_list list, const char *format);
void handle_plus_flag(va_list args, char *str, int *i, long long int *num,
                      int *num_flag);
void handle_space_flag(va_list args, char *str, int *i, long long int *num,
                       int *num_flag);
void fill_width_padding(s21_size_t num_padding, char *str, int *i, int *size,
                        int *minus_flag);
void handle_char(va_list args, char *str, int *i, s21_size_t width, int *size,
                 int *minus_flag);
void handle_decimal(char *temp, va_list args, char *p, s21_size_t len, int *i,
                    char *str, long long int num, int *size, s21_size_t width,
                    int *num_flag, int *minus_flag);
void handle_float(va_list args, char *p, char *temp, s21_size_t len, int *i,
                  char *str, int precision, int *size, s21_size_t width,
                  int *minus_flag);
void handle_string(va_list args, char *p, unsigned char len, int *i, char *str,
                   s21_size_t width, int *size, int *minus_flag);
void handle_octal(va_list args, char *str, int *i, long long int num,
                  s21_size_t width, int *size, int *minus_flag);
void handle_hex(va_list args, char *str, int *i, int spec_x, long long int num,
                s21_size_t width, int *size, int *minus_flag);
char *s21_itoa(int input, char *buff, int num);
char *s21_convert(char *buff, int size, unsigned int num, int base);
char *f_to_str(char *buff, int size, float value, int digits, int *flag);
char *s21_ftoa(char *buff, int size, float value, int digits);
long long cast_to_short(va_list args, const char *format, int *num_flag);
long long cast_to_long(va_list args, const char *format);
void handle_unsigned(char *temp, va_list args, char *p, unsigned char len,
                     int *i, char *str, int *size, long long num,
                     s21_size_t width, int *num_flag, int *minus_flag);
void handle_percent(char *str, int *i, int *size);