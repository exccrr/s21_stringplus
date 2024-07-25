#include "s21_tests.h"

START_TEST(strrchr_1) {
#line 2749
  char str1[] = "abc";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_2) {
#line 2754
  char str1[] = "abc";
  int n = 'd';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_3) {
#line 2759
  char str1[] = "abc";
  int n = '1';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_4) {
#line 2764
  char str1[] = "abc";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_5) {
#line 2769
  char str1[] = "";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_6) {
#line 2774
  char str1[] = " ";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_7) {
#line 2779
  char str1[] = " ";
  int n = ' ';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_8) {
#line 2784
  char str1[] = " ";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_9) {
#line 2789
  char str1[] = "021";
  int n = '0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_10) {
#line 2794
  char str1[] = "ab\nc";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_11) {
#line 2799
  char str1[] = "ab\nc";
  int n = '\n';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_12) {
#line 2804
  char str1[] = "Some meaningless text";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_13) {
#line 2809
  char str1[] = "ab\0c";
  int n = 'a';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_14) {
#line 2814
  char str1[] = "ab\0c";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_15) {
#line 2819
  char str1[] = "";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_16) {
#line 2824
  char str1[] = "\0\0\0";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_17) {
#line 2829
  char str1[] = " ";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_18) {
#line 2834
  char str1[] = "";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_19) {
#line 2839
  char str1[] = "ab,c";
  int n = ',';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(strrchr_20) {
#line 2844
  char str1[] = "abcdefghijklmnopqrst";
  int n = 't';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

Suite* suite_strrchr() {
  Suite* suite = suite_create("strrchr_suite");
  TCase* tcase_core = tcase_create("strrchr_tc");
  tcase_add_test(tcase_core, strrchr_1);
  tcase_add_test(tcase_core, strrchr_2);
  tcase_add_test(tcase_core, strrchr_3);
  tcase_add_test(tcase_core, strrchr_4);
  tcase_add_test(tcase_core, strrchr_5);
  tcase_add_test(tcase_core, strrchr_6);
  tcase_add_test(tcase_core, strrchr_7);
  tcase_add_test(tcase_core, strrchr_8);
  tcase_add_test(tcase_core, strrchr_9);
  tcase_add_test(tcase_core, strrchr_10);
  tcase_add_test(tcase_core, strrchr_11);
  tcase_add_test(tcase_core, strrchr_12);
  tcase_add_test(tcase_core, strrchr_13);
  tcase_add_test(tcase_core, strrchr_14);
  tcase_add_test(tcase_core, strrchr_15);
  tcase_add_test(tcase_core, strrchr_16);
  tcase_add_test(tcase_core, strrchr_17);
  tcase_add_test(tcase_core, strrchr_18);
  tcase_add_test(tcase_core, strrchr_19);
  tcase_add_test(tcase_core, strrchr_20);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
