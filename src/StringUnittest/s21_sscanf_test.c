#include "s21_tests.h"
#define BUFF_SIZE 1024
/* sscanf TEST */

START_TEST(s21_sscanf_c_test) {
  char c1, c2;

  // 1. Считываем первый символ.
  s21_sscanf("TU", "%c", &c1);
  sscanf("TU", "%c", &c2);
  ck_assert_int_eq(c1, c2);

  // 2. Пропускаем первый символ и считываем второй.
  s21_sscanf("TU", "%*c%c", &c1);
  sscanf("TU", "%*c%c", &c2);
  ck_assert_int_eq(c1, c2);

  // 3. Считываем два символа.
  char c3, c4;
  s21_sscanf("TU", "%c%c", &c1, &c3);
  sscanf("TU", "%c%c", &c2, &c4);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c3, c4);

  // 3. Ставим пробел после спецификтора символа.
  s21_sscanf("TU", "%c %c", &c1, &c3);
  sscanf("TU", "%c %c", &c2, &c4);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c3, c4);

  // 4. Пишем спецификатор символа слитно со спецификатором целого числа.
  int i;
  s21_sscanf("350 TU", "%d%c %c", &i, &c1, &c3);
  sscanf("350 TU", "%d%c %c", &i, &c2, &c4);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c3, c4);

  // 5. Добавляем символы в шаблон.
  //  s21_sscanf("tupity unity", "tupity un%city", &c1);
  //  sscanf("tupity unity", "tupity un%city", &c2);
  //  ck_assert_int_eq(c1, c2);

  // 6. Пробуем считать символ по неправильному шаблону.
  //  s21_sscanf("tupity unity", "?)))@!+#!%c", &c1);
  //  sscanf("tupity unity", "?)))@!+#!%c", &c2);
  //  ck_assert_int_eq(c1, c2);
}

// Спецификатор d - знаковое десятичное целое число.
START_TEST(s21_sscanf_d_test) {
  int int_s21, int_orig;

  // 1. Считываем положительное число.
  s21_sscanf("350", "%d", &int_s21);
  sscanf("350", "%d", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 2. Считываем отрицательное число.
  s21_sscanf("-350", "%d", &int_s21);
  sscanf("-350", "%d", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 3. Считываем ноль.
  s21_sscanf("0", "%d", &int_s21);
  sscanf("0", "%d", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 4. Пробуем считать число из пустой строки.
  s21_sscanf("", "%d", &int_s21);
  sscanf("", "%d", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 5. Считываем число, выходящее за рамки.
  s21_sscanf("-2147483650", "%d", &int_s21);
  sscanf("-2147483650", "%d", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 6. Добавляем символы в шаблон.
  //  s21_sscanf("tupity 350 unity", "tupity %d unity", &int_s21);
  //  sscanf("tupity 350 unity", "tupity %d unity", &int_orig);
  //  ck_assert_int_eq(int_s21, int_orig);
}

// Спецификатор s - строка символов.
START_TEST(s21_sscanf_s_test) {
  char buf_21[100];
  char buf_orig[100];

  // 1. Считываем первое слово.
  s21_sscanf("hello, world", "%s", buf_21);
  sscanf("hello, world", "%s", buf_orig);
  ck_assert_str_eq(buf_21, buf_orig);

  // 2. Считываем четыре символа из первого слова.
  s21_sscanf("hello, world", "%4s", buf_21);
  sscanf("hello, world", "%4s", buf_orig);
  ck_assert_str_eq(buf_21, buf_orig);

  // 3. Пропускаем первое слово и считываем второе.
  s21_sscanf("hello, world", "%*s%s", buf_21);
  sscanf("hello, world", "%*s%s", buf_orig);
  ck_assert_str_eq(buf_21, buf_orig);

  // 5. Пробуем считать 20 символов из строки.
  s21_sscanf("hello, world", "%20s", buf_21);
  sscanf("hello, world", "%20s", buf_orig);
  ck_assert_str_eq(buf_21, buf_orig);

  // 6. Добавляем символы в шаблон.
  //  s21_sscanf("tupity unity", "tup%s unity", buf_21);
  //  sscanf("tupity unity", "tup%s unity", buf_orig);
  //  ck_assert_str_eq(buf_21, buf_orig);

  // 7. Пробуем считать строку по неправильному шаблону.
  //  s21_sscanf("tupity unity", "?)))@!+#!%s", buf_21);
  //  sscanf("tupity unity", "?)))@!+#!%s", buf_orig);
  //  ck_assert_str_eq(buf_21, buf_orig);
}

// Спецификатор u - беззнаковое десятичное целое число.
START_TEST(s21_sscanf_u_test) {
  int int_s21, int_orig;

  // 1. Считываем положительное число.
  s21_sscanf("350", "%u", &int_s21);
  sscanf("350", "%u", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 2. Считываем отрицательное число.
  s21_sscanf("-350", "%u", &int_s21);
  sscanf("-350", "%u", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 3. Считываем ноль.
  s21_sscanf("0", "%u", &int_s21);
  sscanf("0", "%u", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 4. Пробуем считать число из пустой строки.
  s21_sscanf("", "%u", &int_s21);
  sscanf("", "%u", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 5. Считываем число, выходящее за рамки значений типа int.
  s21_sscanf("2147483650", "%u", &int_s21);
  sscanf("2147483650", "%u", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 6. Добавляем символы в шаблон.
  //  s21_sscanf("tupity 350 unity", "tupity %u unity", &int_s21);
  //  sscanf("tupity 350 unity", "tupity %u unity", &int_orig);
  //  ck_assert_int_eq(int_s21, int_orig);
}

// Спецификаторы x и X - беззнаковое шестнадцатеричное целое число (любые
// буквы).
START_TEST(s21_sscanf_xX_test) {
  int int_s21, int_orig;

  // 1. Считываем положительное число.
  s21_sscanf("0x15E", "%x", &int_s21);
  sscanf("0x15E", "%x", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  s21_sscanf("0x15E", "%X", &int_s21);
  sscanf("0x15E", "%X", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 2. Считываем ноль.
  s21_sscanf("0", "%x", &int_s21);
  sscanf("0", "%x", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  s21_sscanf("0", "%X", &int_s21);
  sscanf("0", "%X", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 3. Пробуем считать число из пустой строки.
  s21_sscanf("", "%x", &int_s21);
  sscanf("", "%x", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  s21_sscanf("", "%X", &int_s21);
  sscanf("", "%X", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 5. Считываем число, выходящее за рамки значений типа int.
  s21_sscanf("0xFFFFFFFF", "%x", &int_s21);
  sscanf("0xFFFFFFFF", "%x", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  s21_sscanf("0xFFFFFFFF", "%X", &int_s21);
  sscanf("0xFFFFFFFF", "%X", &int_orig);
  ck_assert_int_eq(int_s21, int_orig);

  // 6. Добавляем символы в шаблон.
  //  s21_sscanf("tupity 0x15E unity", "tupity %x unity", &int_s21);
  //  sscanf("tupity 0x15E unity", "tupity %x unity", &int_orig);
  //  ck_assert_int_eq(int_s21, int_orig);

  //  s21_sscanf("tupity 0x15E unity", "tupity %X unity", &int_s21);
  //  sscanf("tupity 0x15E unity", "tupity %X unity", &int_orig);
  //  ck_assert_int_eq(int_s21, int_orig);
}

// Спецификатор p - адрес указателя.
START_TEST(s21_sscanf_p_test) {
  void **p_1, **p_2;

  // 1. Считываем адрес.
  sscanf("0x12345678", "%p", &p_1);
  sscanf("0x12345678", "%p", &p_2);
  ck_assert_ptr_eq(p_1, p_2);

  // 2. Пробуем считать адрес в строке, в которой его нет.
  sscanf("tupity unity", "%p", &p_1);
  sscanf("tupity unity", "%p", &p_2);
  ck_assert_ptr_eq(p_1, p_2);

  // 3. Добавляем символы в шаблон.
  //  s21_sscanf("tupity0x7fFfFfFfunity", "tupity%punity", &p_1);
  //  sscanf("tupity0x7fFfFfFfunity", "tupity%punity", &p_2);
  //  ck_assert_ptr_eq(p_1, p_2);
}

// Спецификатор n - количество символов, считанных до появления %n.
START_TEST(s21_sscanf_n_test) {
  int int_s21, int_orig;
  char c1, c2;
  char str_1[100], str_2[100];

  // 1. Спецификатор в конце строки.
  //  s21_sscanf("tupity unity%n", "%c %s %n", &c1, str_1, &int_s21);
  //  sscanf("tupity unity%n", "%c %s %n", &c2, str_2, &int_orig);
  //  ck_assert_int_eq(int_s21, int_orig);

  // 2. Спецификатор в начале строки.
  s21_sscanf("%ntupity unity", "%n %c %s", &int_s21, &c1, str_1);
  sscanf("%ntupity unity", "%n %c %s", &int_orig, &c2, str_2);
  ck_assert_int_eq(int_s21, int_orig);

  // 3. Спецификатор в середине строки.
  s21_sscanf("%ntupity unity", "%c %n %s", &c1, &int_s21, str_1);
  sscanf("%ntupity unity", "%c %n %s", &c2, &int_orig, str_2);
  ck_assert_int_eq(int_s21, int_orig);
}

// Спецификатор % - символ %.
START_TEST(s21_sscanf_percent_test) {
  char c1, c2;
  s21_sscanf("%%", "%c", &c1);
  sscanf("%%", "%c", &c2);
  ck_assert_int_eq(c1, c2);
}

START_TEST(sscanf_test_l) {
  int r1 = 0, r2 = 0;
  unsigned long lu1 = 0, lu2 = 0;
  long ld1 = 0, ld2 = 0;

  wchar_t lc1, lc2;

  r1 = sscanf("a", "%lc", &lc1);
  r2 = s21_sscanf("a", "%lc", &lc2);
  ck_assert_int_eq(lc1, lc2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12345", "%lu", &lu1);
  r2 = s21_sscanf("12345", "%lu", &lu2);
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12345", "%ld", &ld1);
  r2 = s21_sscanf("12345", "%ld", &ld2);
  ck_assert_int_eq(ld1, ld2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_L) {
  int r1 = 0, r2 = 0;
  long double Lf1 = 0, Lf2 = 0;

  r1 = sscanf("123.45", "%Lf", &Lf1);
  r2 = s21_sscanf("123.45", "%Lf", &Lf2);
  ck_assert_msg((int)Lf1 == (int)Lf2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_u) {
  int r1 = 0, r2 = 0;
  unsigned u1 = 0, u2 = 0;

  r1 = sscanf("", "%u", &u1);
  r2 = s21_sscanf("", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x12345", "%2u", &u1);
  r2 = s21_sscanf("0x12345", "%2u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%u", &u1);
  r2 = s21_sscanf("123.456", "%u", &u2);
  ck_assert_msg(u1 == u2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_h) {
  int r1 = 0, r2 = 0;
  unsigned short hu1 = 0, hu2 = 0;

  r1 = sscanf("12345", "%hu", &hu1);
  r2 = s21_sscanf("12345", "%hu", &hu2);
  ck_assert_int_eq(hu1, hu2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_s) {
  int r1 = 0, r2 = 0;
  char s1[100], s2[100];

  r1 = sscanf("shrek amogus", "%*s%2s", s1);
  r2 = s21_sscanf("shrek amogus", "%*s%2s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_f) {
  int r1 = 0, r2 = 0;
  float f1 = 0, f2 = 0;

  r1 = sscanf("12e-3", "%f", &f1);
  r2 = s21_sscanf("12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123.45", "%f", &f1);
  r2 = s21_sscanf("-123.45", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12.345", "%5f", &f1);
  r2 = s21_sscanf("-12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12.345", "%5f", &f1);
  r2 = s21_sscanf("12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_o) {
  int r1 = 0, r2 = 0;
  unsigned o1 = 0, o2 = 0;

  r1 = sscanf("12345678", "%3o", &o1);
  r2 = s21_sscanf("12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%o", &o1);
  r2 = s21_sscanf("123.456", "%o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_x) {
  int r1 = 0, r2 = 0;
  unsigned x1 = 0, x2 = 0;

  r1 = sscanf("0x12345", "%x", &x1);
  r2 = s21_sscanf("0x12345", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("AMOGUS", "%x", &x1);
  r2 = s21_sscanf("AMOGUS", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("amogus", "%x", &x1);
  r2 = s21_sscanf("amogus", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x1234567890123456789", "%x", &x1);
  r2 = s21_sscanf("0x1234567890123456789", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  x1 = 0, x2 = 0;
  r1 = sscanf("0x123", "%x", &x1);
  r2 = s21_sscanf("0x123", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123456", "%x", &x1);
  r2 = s21_sscanf("123456", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_proc) {
  int r1 = 0, r2 = 0;
  char proc1[100] = {0}, proc2[100] = {0};

  r1 = sscanf("123.456", "%%%9s", proc1);
  r2 = s21_sscanf("123.456", "%%%9s", proc2);
  ck_assert_str_eq(proc1, proc2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_n) {
  int n1 = 0, n2 = 0, r1 = 0, r2 = 0;

  r1 = sscanf("123.456", "%n", &n1);
  r2 = s21_sscanf("123.456", "%n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_d) {
  int r1 = 0, r2 = 0, d1 = 0, d2 = 0;

  r1 = sscanf("123", "%002d", &d1);
  r2 = s21_sscanf("123", "%002d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_EOF1) {
  char fstr[] = "%d";
  char str[] = "        ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a2);
  int16_t res2 = sscanf(str, fstr, &a1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF2) {
  char fstr[] = "%d ";
  char str[] = "               ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF3) {
  char fstr[] = "%d ";
  char str[] = "  ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_only_chars1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   a     b c d";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars2) {
  char fstr[] = "%c%c%c%c";
  char str[] = "abcd";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1 a 3   c           ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   000 0    ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars2) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars3) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_chars_flags1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags3) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags5) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcde";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster1) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster2) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcd ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_only_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_ints2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 3000";
  const char fstr[] = "%hd %hd %hd %hd";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%1lld %3lld %1lld %4lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%1lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "11337 ++3 -5 ------4";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_signed_ints4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1 01 10 0";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// [%s] //
START_TEST(sscanf_strings1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings_mixed3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[] = "%s%ld%s%d%s%d%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

// strings_mixed1
START_TEST(sscanf_strings_mixed1) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double e1 = 0, e2 = 0;

  const char str[] =
      "4444444"
      "eeeeeee\teeeeeee";
  const char fstr[] = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_strings_mixed2) {
  int b1 = 0, b2 = 0, a1 = 0, a2 = 0;
  long long v1, v2;

  const char str[] = "1 1 1 1 1 -1";
  const char fstr[] = "%1s %5d %1s %1s %d %lld";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1);
  int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2);

  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// [%f] / [%g] / %[%G] //
START_TEST(sscanf_floats1) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_double_eq_tol(a1, a2, 1e-06);
  ck_assert_double_eq_tol(b1, b2, 1e-06);
  ck_assert_double_eq_tol(c1, c2, 1e-06);
  ck_assert_double_eq_tol(d1, d2, 1e-06);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_floats2) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "0.00001 -4123123 4. .1";
  const char fstr[] = "%lf %lf %lf %lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_double_eq_tol(a1, a2, 1e-06);
  ck_assert_double_eq_tol(b1, b2, 1e-06);
  ck_assert_double_eq_tol(c1, c2, 1e-06);
  ck_assert_double_eq_tol(d1, d2, 1e-06);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(sscanf_floats3) {
//   float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
//
//   const char str[] = ". . . .";
//   const char fstr[] = "%f %f %f %f";
//
//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
//
//   ck_assert_double_eq_tol(a1, a2, 1e-06);
//   ck_assert_double_eq_tol(b1, b2, 1e-06);
//   ck_assert_double_eq_tol(c1, c2, 1e-06);
//   ck_assert_double_eq_tol(d1, d2, 1e-06);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(sscanf_floats4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "513.41 -4.14135 414.3333 +112.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_double_eq_tol(a1, a2, 1e-06);
  ck_assert_double_eq_tol(b1, b2, 1e-06);
  ck_assert_double_eq_tol(c1, c2, 1e-06);
  ck_assert_double_eq_tol(d1, d2, 1e-06);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_floats5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "53.1 -4.1135 411231.333 +2.0001";
  const char fstr[] = "%*f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_floats_sci1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_double_eq_tol(a1, a2, 1e-06);
  ck_assert_double_eq_tol(b1, b2, 1e-06);
  ck_assert_double_eq_tol(c1, c2, 1e-06);
  ck_assert_double_eq_tol(d1, d2, 1e-06);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_floats_sci2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "inf 1.31e+4 NaN 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_float_infinite(a1);
  ck_assert_float_infinite(a2);
  ck_assert_double_eq_tol(b1, b2, 1e-06);
  ck_assert_float_nan(c1);
  ck_assert_float_nan(c2);
  ck_assert_double_eq_tol(d1, d2, 1e-06);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_floats_sci3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "inF InF inF INF";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_float_infinite(a1);
  ck_assert_float_infinite(a2);
  ck_assert_float_infinite(b1);
  ck_assert_float_infinite(b2);
  ck_assert_float_infinite(c1);
  ck_assert_float_infinite(c2);
  ck_assert_float_infinite(d1);
  ck_assert_float_infinite(d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_floats_sci4) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Nan NAN 0.0000 0";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats_sci5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] =
      "nAN           INF                   -0.1111         1e-10";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

// [%u] - Беззнаковое десятичное целое число
START_TEST(sscanf_uint1) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_uint2) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                         d2 = 0;
  const char str[] = "-1337 233333331 5008 3000";
  const char fstr[] = "%llu %2llu %5llu %4llu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_uint3) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double v1, v2;

  const char str[] =
      "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
      "anurobich+ 21 -5008 -33000 0.3333";
  const char fstr[] = "%*s %*s %llu %s %llu %llu %lld %Lf";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
  int16_t res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);

  ck_assert_str_eq(s1, s2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_ldouble_eq_tol(v1, v2, 0.0001);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_uint4) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_uint5) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_uint6) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_upeer_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xFFFFFFFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x1";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X1";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_short) {
  uint16_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%hX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_longlong) {
  unsigned long long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%llX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xfffffffffffffffffff";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x1";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X1";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_short) {
  uint16_t a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%hx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%lx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*x";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upper_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_base_version) {
  uint32_t a1, a2;
  const char str[] = "777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_fail) {
  uint32_t a1, a2;
  const char str[] = "q1";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs5) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[] = "NULL";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

Suite *suite_sscanf(void) {
  Suite *suite = suite_create("sscanf_suite");
  TCase *tcase_core = tcase_create("sscanf_tc");

  tcase_add_test(tcase_core, s21_sscanf_c_test);
  tcase_add_test(tcase_core, s21_sscanf_s_test);
  tcase_add_test(tcase_core, s21_sscanf_d_test);
  tcase_add_test(tcase_core, s21_sscanf_u_test);
  tcase_add_test(tcase_core, s21_sscanf_xX_test);
  tcase_add_test(tcase_core, s21_sscanf_p_test);
  tcase_add_test(tcase_core, s21_sscanf_n_test);
  tcase_add_test(tcase_core, s21_sscanf_percent_test);
  tcase_add_test(tcase_core, sscanf_test_d);
  tcase_add_test(tcase_core, sscanf_test_n);
  tcase_add_test(tcase_core, sscanf_test_proc);
  tcase_add_test(tcase_core, sscanf_test_x);
  tcase_add_test(tcase_core, sscanf_test_o);
  tcase_add_test(tcase_core, sscanf_test_f);
  tcase_add_test(tcase_core, sscanf_test_s);
  tcase_add_test(tcase_core, sscanf_test_h);
  tcase_add_test(tcase_core, sscanf_test_u);
  tcase_add_test(tcase_core, sscanf_test_L);
  tcase_add_test(tcase_core, sscanf_test_l);
  tcase_add_test(tcase_core, sscanf_EOF1);
  tcase_add_test(tcase_core, sscanf_EOF2);
  tcase_add_test(tcase_core, sscanf_EOF3);
  tcase_add_test(tcase_core, sscanf_only_chars1);
  tcase_add_test(tcase_core, sscanf_only_chars2);
  tcase_add_test(tcase_core, sscanf_only_chars3);
  tcase_add_test(tcase_core, sscanf_only_chars4);
  tcase_add_test(tcase_core, sscanf_only_chars5);
  tcase_add_test(tcase_core, sscanf_special_symbols_as_chars1);
  tcase_add_test(tcase_core, sscanf_special_symbols_as_chars2);
  tcase_add_test(tcase_core, sscanf_special_symbols_as_chars3);

  tcase_add_test(tcase_core, sscanf_chars_flags1);
  tcase_add_test(tcase_core, sscanf_chars_flags3);
  tcase_add_test(tcase_core, sscanf_chars_flags4);
  tcase_add_test(tcase_core, sscanf_chars_flags5);
  tcase_add_test(tcase_core, sscanf_chars_aster1);
  tcase_add_test(tcase_core, sscanf_chars_aster2);

  tcase_add_test(tcase_core, sscanf_only_ints1);
  tcase_add_test(tcase_core, sscanf_only_ints2);
  tcase_add_test(tcase_core, sscanf_only_ints3);

  tcase_add_test(tcase_core, sscanf_ints_nwidth1);
  tcase_add_test(tcase_core, sscanf_ints_nwidth2);

  tcase_add_test(tcase_core, sscanf_signed_ints1);
  tcase_add_test(tcase_core, sscanf_signed_ints4);

  tcase_add_test(tcase_core, sscanf_strings1);
  tcase_add_test(tcase_core, sscanf_strings2);
  tcase_add_test(tcase_core, sscanf_strings3);
  tcase_add_test(tcase_core, sscanf_strings4);
  tcase_add_test(tcase_core, sscanf_strings5);
  tcase_add_test(tcase_core, sscanf_strings6);
  tcase_add_test(tcase_core, sscanf_uint1);
  tcase_add_test(tcase_core, sscanf_uint2);
  tcase_add_test(tcase_core, sscanf_uint3);
  tcase_add_test(tcase_core, sscanf_uint4);
  tcase_add_test(tcase_core, sscanf_uint5);
  tcase_add_test(tcase_core, sscanf_uint6);
  tcase_add_test(tcase_core, sscanf_strings_mixed1);
  tcase_add_test(tcase_core, sscanf_strings_mixed2);
  tcase_add_test(tcase_core, sscanf_strings_mixed3);

  tcase_add_test(tcase_core, sscanf_floats1);
  tcase_add_test(tcase_core, sscanf_floats2);
  //  tcase_add_test(tcase_core, sscanf_floats3);
  tcase_add_test(tcase_core, sscanf_floats4);
  tcase_add_test(tcase_core, sscanf_floats5);

  tcase_add_test(tcase_core, sscanf_floats_sci1);
  tcase_add_test(tcase_core, sscanf_floats_sci2);
  tcase_add_test(tcase_core, sscanf_floats_sci3);
  tcase_add_test(tcase_core, sscanf_floats_sci4);
  tcase_add_test(tcase_core, sscanf_floats_sci5);

  tcase_add_test(tcase_core, sscanf_upeer_hex_base_version);
  tcase_add_test(tcase_core, sscanf_upeer_hex_overflow);
  tcase_add_test(tcase_core, sscanf_upeer_hex_0x);
  tcase_add_test(tcase_core, sscanf_upeer_hex_0X);
  tcase_add_test(tcase_core, sscanf_upeer_hex_empty);
  tcase_add_test(tcase_core, sscanf_upeer_hex_fail);
  tcase_add_test(tcase_core, sscanf_upeer_hex_spaces_tabs_sns);
  tcase_add_test(tcase_core, sscanf_upeer_hex_short);
  tcase_add_test(tcase_core, sscanf_upeer_hex_long);
  tcase_add_test(tcase_core, sscanf_upeer_hex_longlong);
  tcase_add_test(tcase_core, sscanf_upeer_hex_2x);
  tcase_add_test(tcase_core, sscanf_upeer_hex_star);
  tcase_add_test(tcase_core, sscanf_upeer_hex_nohex);
  tcase_add_test(tcase_core, sscanf_upeer_hex_lower);
  tcase_add_test(tcase_core, sscanf_upeer_hex_sign);
  tcase_add_test(tcase_core, upper_hex_len);

  tcase_add_test(tcase_core, sscanf_lower_hex_base_version);
  tcase_add_test(tcase_core, sscanf_lower_hex_overflow);
  tcase_add_test(tcase_core, sscanf_lower_hex_0x);
  tcase_add_test(tcase_core, sscanf_lower_hex_0X);
  tcase_add_test(tcase_core, sscanf_lower_hex_empty);
  tcase_add_test(tcase_core, sscanf_lower_hex_fail);
  tcase_add_test(tcase_core, sscanf_lower_hex_spaces_tabs_sns);
  tcase_add_test(tcase_core, sscanf_lower_hex_short);
  tcase_add_test(tcase_core, sscanf_lower_hex_long);
  tcase_add_test(tcase_core, sscanf_lower_hex_2x);
  tcase_add_test(tcase_core, sscanf_lower_hex_star);
  tcase_add_test(tcase_core, sscanf_lower_hex_nohex);
  tcase_add_test(tcase_core, sscanf_lower_hex_lower);
  tcase_add_test(tcase_core, sscanf_lower_hex_sign);
  tcase_add_test(tcase_core, sscanf_lower_hex_len);

  tcase_add_test(tcase_core, sscanf_octal_base_version);
  tcase_add_test(tcase_core, sscanf_octal_0x);
  tcase_add_test(tcase_core, sscanf_octal_0X);
  tcase_add_test(tcase_core, sscanf_octal_empty);
  tcase_add_test(tcase_core, sscanf_octal_fail);
  tcase_add_test(tcase_core, sscanf_octal_spaces_tabs_sns);
  tcase_add_test(tcase_core, sscanf_mixed_ptrs5);

  suite_add_tcase(suite, tcase_core);
  return suite;
}