#include "s21_tests.h"

START_TEST(simple_lower_case) {
  const char s21_str[] = "ABC";

  ck_assert_str_eq(s21_to_lower(s21_str), "abc");
}
END_TEST

START_TEST(letters_and_numbers) {
  char s21_str[] = "ABC123ABC";

  ck_assert_str_eq(s21_to_lower(s21_str), "abc123abc");
}
END_TEST

START_TEST(lowercase) {
  char s21_str[] = "abc";

  ck_assert_str_eq(s21_to_lower(s21_str), "abc");
}
END_TEST

START_TEST(s21_to_lower_1) {
#line 3596
  char str1[] = "ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_2) {
#line 3602
  char str1[] = "aBc";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_3) {
#line 3608
  char str1[] = "abC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_4) {
#line 3614
  char str1[] = "ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_5) {
#line 3620
  char str1[] = "123";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "123");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_6) {
#line 3626
  char str1[] = "123ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "123abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_7) {
#line 3632
  char str1[] = "aBaBc";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "ababc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_8) {
#line 3638
  char str1[] = ".,/.,/.,";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, ".,/.,/.,");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_9) {
#line 3644
  char str1[] = "09876ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "09876abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_10) {
#line 3650
  char str1[] = "ABC123";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc123");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_11) {
#line 3656
  char str1[] = " ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, " ");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_12) {
#line 3662
  char str1[] = "";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_13) {
#line 3668
  char str1[] = "A1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_14) {
#line 3674
  char str1[] = " A1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, " a1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_15) {
#line 3680
  char str1[] = "A1A1A1 ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1 ");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_16) {
#line 3686
  char str1[] = "AA1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "aa1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_17) {
#line 3692
  char str1[] = "A1a1A1A";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1a");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_18) {
#line 3698
  char str1[] = "A1A1\0a1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1\0a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_19) {
#line 3704
  char str1[] = "A1a\n1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a\n1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_20) {
#line 3710
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abcdefghijklmnopqrstuvwxyz");
  free(str2);
}
END_TEST

Suite *suite_to_lower() {
  Suite *suite = suite_create("to_lower_suite");
  TCase *tcase_core = tcase_create("to_lower_tc");

  tcase_add_test(tcase_core, simple_lower_case);
  tcase_add_test(tcase_core, letters_and_numbers);
  tcase_add_test(tcase_core, lowercase);
  tcase_add_test(tcase_core, s21_to_lower_1);
  tcase_add_test(tcase_core, s21_to_lower_2);
  tcase_add_test(tcase_core, s21_to_lower_3);
  tcase_add_test(tcase_core, s21_to_lower_4);
  tcase_add_test(tcase_core, s21_to_lower_5);
  tcase_add_test(tcase_core, s21_to_lower_6);
  tcase_add_test(tcase_core, s21_to_lower_7);
  tcase_add_test(tcase_core, s21_to_lower_8);
  tcase_add_test(tcase_core, s21_to_lower_9);
  tcase_add_test(tcase_core, s21_to_lower_10);
  tcase_add_test(tcase_core, s21_to_lower_11);
  tcase_add_test(tcase_core, s21_to_lower_12);
  tcase_add_test(tcase_core, s21_to_lower_13);
  tcase_add_test(tcase_core, s21_to_lower_14);
  tcase_add_test(tcase_core, s21_to_lower_15);
  tcase_add_test(tcase_core, s21_to_lower_16);
  tcase_add_test(tcase_core, s21_to_lower_17);
  tcase_add_test(tcase_core, s21_to_lower_18);
  tcase_add_test(tcase_core, s21_to_lower_19);
  tcase_add_test(tcase_core, s21_to_lower_20);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
