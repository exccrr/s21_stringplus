#include "s21_tests.h"

START_TEST(s21_strncat_1) {
  char s21_dest[] = "someIntellectualText";
  char s21_src[] = "i1";
  char dest[] = "someIntellectualText";
  char src[] = "i1";
  s21_size_t n = 5;

  ck_assert_str_eq(s21_strncat(s21_dest, s21_src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(s21_strncat_2) {
  char s1[50] = "a\n\0";
  char s2[50] = " \n\0";
  char s3[50] = "a\n\0";
  ck_assert_str_eq(s21_strncat(s1, s2, 3), strncat(s3, s2, 3));
}
END_TEST

START_TEST(s21_strncat_3) {
  char s1[50] = " \0";
  char s2[50] = "\n\0";
  char s3[50] = " \0";
  ck_assert_str_eq(s21_strncat(s1, s2, 1), strncat(s3, s2, 1));
}
END_TEST

START_TEST(s21_strncat_4) {
  char s1[50] = "\0";
  char s2[50] = "\n\0";
  char s3[50] = "\0";
  ck_assert_str_eq(s21_strncat(s1, s2, 1), strncat(s3, s2, 1));
}
END_TEST

START_TEST(s21_strncat_5) {
  char src[] = "\0";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;

  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);

  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(s21_strncat_6) {
  char str_1[20] = "hello";
  char str_2[20] = "hello";
  char *str_3 = "world";
  s21_size_t n = 3;
  char *s21_result = s21_strncat(str_1, str_3, n);
  char *lib_result = strncat(str_2, str_3, n);
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_7) {
  char str_1[20] = "";
  char *str_2 = "world";
  s21_size_t n = 3;
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_8) {
  char str_1[20] = "hello";
  char *str_2 = "";
  s21_size_t n = 3;
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_9) {
  char str_1[20] = "";
  char *str_2 = "";
  s21_size_t n = 3;
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_10) {
  char str_1[20] = "hello";
  char *str_2 = "world";
  s21_size_t n = 0;
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_11) {
  char str_1[20] = "";
  char *str_2 = "";
  s21_size_t n = 0;
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_12) {
  char str_1[20] = "hello";
  char *str_2 = "world";
  s21_size_t n = 0;
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

Suite *suite_strncat() {
  Suite *suite = suite_create("strncat_suite");
  TCase *tcase_core = tcase_create("strncat_tc");

  tcase_add_test(tcase_core, s21_strncat_1);
  tcase_add_test(tcase_core, s21_strncat_2);
  tcase_add_test(tcase_core, s21_strncat_3);
  tcase_add_test(tcase_core, s21_strncat_4);
  tcase_add_test(tcase_core, s21_strncat_5);
  tcase_add_test(tcase_core, s21_strncat_6);
  tcase_add_test(tcase_core, s21_strncat_7);
  tcase_add_test(tcase_core, s21_strncat_8);
  tcase_add_test(tcase_core, s21_strncat_9);
  tcase_add_test(tcase_core, s21_strncat_10);
  tcase_add_test(tcase_core, s21_strncat_11);
  tcase_add_test(tcase_core, s21_strncat_12);

  suite_add_tcase(suite, tcase_core);
  return suite;
}