#include "s21_tests.h"

START_TEST(s21_strcspn_1) {
  char s1[] = "H e l l o\0";
  char s2[] = "lo\0";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_2) {
  char s1[] = "Hello\0";
  char s2[] = "HE\0";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_3) {
  char s1[] = "Hello\0";
  char s2[] = "\0";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_4) {
  char s1[] = "Hello\0";
  char s2[] = "Hello\0";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_5) {
  char s1[] = "Hello\0";
  char s2[] = "hELLO\0";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn_6) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_7) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_8) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_9) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_10) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_11) {
  char *str = "hello, world";
  char *keys = "wl";
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcspn_12) {
  char *str = "";
  char *keys = "wl";
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcspn_13) {
  char *str = "hello, world";
  char *keys = "";
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcspn_14) {
  char *str = "";
  char *keys = "";
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcspn_15) {
  char test1[] = "DawnBreaker";
  char test2[] = "Dawn";
  char test3[] = "Primal Beast";
  char test4[] = "beast";
  char test5[] = "0/";
  char test6[] = "//#";
  char test7[] = " ";
  char test8[] = "0987654321";
  char test9[] = "0";
  char test10[] = "1";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
  ck_assert_uint_eq(s21_strcspn(test8, test9), strcspn(test8, test9));
  ck_assert_uint_eq(s21_strcspn(test8, test10), strcspn(test8, test10));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *suite = suite_create("strcspn_suite");
  TCase *tcase_core = tcase_create("strcspn_tc");

  tcase_add_test(tcase_core, s21_strcspn_1);
  tcase_add_test(tcase_core, s21_strcspn_2);
  tcase_add_test(tcase_core, s21_strcspn_3);
  tcase_add_test(tcase_core, s21_strcspn_4);
  tcase_add_test(tcase_core, s21_strcspn_5);
  tcase_add_test(tcase_core, s21_strcspn_6);
  tcase_add_test(tcase_core, s21_strcspn_7);
  tcase_add_test(tcase_core, s21_strcspn_8);
  tcase_add_test(tcase_core, s21_strcspn_9);
  tcase_add_test(tcase_core, s21_strcspn_10);
  tcase_add_test(tcase_core, s21_strcspn_11);
  tcase_add_test(tcase_core, s21_strcspn_12);
  tcase_add_test(tcase_core, s21_strcspn_13);
  tcase_add_test(tcase_core, s21_strcspn_14);
  tcase_add_test(tcase_core, s21_strcspn_15);
  suite_add_tcase(suite, tcase_core);
  return suite;
}