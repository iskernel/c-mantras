#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include "../cm_test_base.h"
#include "cm_string_tests.h"

#include "cmantras/text/cm_string.h"

static void cm_string_create_from_char_array__char_array_defined__is_created()
{
    const char* TEST_CONTENT = "test content";
    char* content = NULL;
    struct cm_string* string = NULL;
    cm_size expectedLength = 0;
    bool condition = false;

    expectedLength = strlen(TEST_CONTENT);
    content = malloc(sizeof(char) * expectedLength);
    strcpy(content, TEST_CONTENT);
    string = cm_string_create_from_char_array(content);

    condition = (string->length == expectedLength)
                 && (strcmp(string->content, TEST_CONTENT) == 0);

    assert_is_true(condition, __func__);
}

static void cm_string_create_from_string__other_string_defined__is_created()
{
    struct cm_string* string1 = NULL;
    struct cm_string* string2 = NULL;
    bool condition = false;

    string1 = cm_string_create_from_char_array("test content");
    string2 = cm_string_create_from_string(string1);
    condition = (strcmp(string1->content, string2->content) == 0)
                 && (string1->length == string2->length);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_char__a_char__isCreated()
{
    char char1 = 'r';
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_char(char1);
    condition = (string->length == 1)
                 && (strcmp(string->content, "r") == 0);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_integer__positive_integer__is_created()
{
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_integer(88, 10);
    condition = (string->length == 2)
            && (strcmp(string->content, "88") == 0);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_integer__negative_integer__is_created()
{
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_integer(-88, 10);
    condition = (string->length == 3)
            && (strcmp(string->content, "-88") == 0);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_real__positive_real__is_created()
{
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_real(23.32);
    condition = (string->length == 9)
            && (strcmp(string->content, "23.320000") == 0);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_real__negative_real__is_created()
{
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_real(-23.32);
    condition = (string->length == 10)
            && (strcmp(string->content, "-23.320000") == 0);
    assert_is_true(condition, __func__);
}

static void cm_string_to_lower__normal_string__string_is_lower()
{
    struct cm_string* string = NULL;
    bool condition = false;

    string = cm_string_create_from_char_array("This is a CHAR array");
    cm_string_to_lower(string);
    condition = (strcmp(string->content, "this is a char array") == 0);

    assert_is_true(condition, __func__);
}

static void cm_string_to_upper__normal_string__string_is_upper()
{
    struct cm_string* string = NULL;
    bool condition = false;

    string = cm_string_create_from_char_array("This is a CHAR array");
    cm_string_to_upper(string);
    condition = (strcmp(string->content, "THIS IS A CHAR ARRAY") == 0);

    assert_is_true(condition, __func__);
}

static void cm_string_compare__normal_strings__comparation_as_expected()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    cm_cmp_size cmp = 0;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("This is string1");
    string_2 = cm_string_create_from_char_array("This is string2");

    cmp = cm_string_compare(string_1, string_2);
    condition = (cmp == -1);

    assert_is_true(condition, __func__);
}

static void cm_string_compare_insensitive__normal_strings__comparation_as_expected()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    cm_cmp_size cmp = 0;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("THis is StRing1");
    string_2 = cm_string_create_from_char_array("ThIs iS sTrIng2");

    cmp = cm_string_compare_insensitive(string_1, string_2);
    condition = (cmp == -1);

    assert_is_true(condition, __func__);
}

static void cm_string_compare_ordinal__normal_strings__within_expected_range()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    double cmp = 0.0;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("22.33");
    string_2 = cm_string_create_from_char_array("33.22");

    cmp = cm_string_compare_ordinal(string_1, string_2);
    condition = (cmp >= -11) && (cmp <= -10);

    assert_is_true(condition, __func__);
}

static void cm_string_compare_are_equal__string_are_equal__is_true()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("This is string");
    string_2 = cm_string_create_from_char_array("This is string");

    condition = (cm_string_are_equal(string_1, string_2) == true);

    assert_is_true(condition, __func__);
}

static void cm_string_concat__multiple_string__concatenation_successful()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    struct cm_string* string_3 = NULL;
    struct cm_string* result = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("12345");
    string_2 = cm_string_create_from_char_array("54321");
    string_3 = cm_string_create_from_char_array("12345");

    result = cm_string_concat(string_1, string_2, string_3, NULL);
    condition = (strcmp(result->content, "123455432112345") == 0);

    assert_is_true(condition, __func__);
}

static void cm_string_contains__string_contains_substring__is_true()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("1234554321");
    string_2 = cm_string_create_from_char_array("54321");

    condition = cm_string_contains(string_1, string_2);

    assert_is_true(condition, __func__);
}

static void cm_string_contains_insensitive__string_contains_substring__is_true()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("abcdef");
    string_2 = cm_string_create_from_char_array("DEF");

    condition = cm_string_contains_insensitive(string_1, string_2);

    assert_is_true(condition, __func__);
}

static void cm_string_ends_with__string_ends_with_substring__is_true()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("abcdef");
    string_2 = cm_string_create_from_char_array("def");

    condition = cm_string_ends_with(string_1, string_2);

    assert_is_true(condition, __func__);
}

static void cm_string_ends_with_insensitive__string_ends_with_substring__is_true()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("abcdef");
    string_2 = cm_string_create_from_char_array("DEF");

    condition = cm_string_ends_with_insensitive(string_1, string_2);

    assert_is_true(condition, __func__);
}

static void cm_string_starts_with__string_ends_with_substring__is_true()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("abcdef");
    string_2 = cm_string_create_from_char_array("abc");

    condition = cm_string_starts_with(string_1, string_2);

    assert_is_true(condition, __func__);
}

static void cm_string_starts_with_insensitive__string_ends_with_substring__is_true()
{
    struct cm_string* string_1 = NULL;
    struct cm_string* string_2 = NULL;
    bool condition = false;

    string_1 = cm_string_create_from_char_array("abcdef");
    string_2 = cm_string_create_from_char_array("ABC");

    condition = cm_string_starts_with_insensitive(string_1, string_2);

    assert_is_true(condition, __func__);
}

void cm_string_run_tests()
{
    cm_string_create_from_char_array__char_array_defined__is_created();
    cm_string_create_from_string__other_string_defined__is_created();
    cm_string_create_from_char__a_char__isCreated();
    cm_string_create_from_integer__positive_integer__is_created();
    cm_string_create_from_integer__negative_integer__is_created();
    cm_string_create_from_real__positive_real__is_created();
    cm_string_create_from_real__negative_real__is_created();
    cm_string_to_lower__normal_string__string_is_lower();
    cm_string_to_upper__normal_string__string_is_upper();
    cm_string_compare__normal_strings__comparation_as_expected();
    cm_string_compare_insensitive__normal_strings__comparation_as_expected();
    cm_string_compare_ordinal__normal_strings__within_expected_range();
    cm_string_compare_are_equal__string_are_equal__is_true();
    cm_string_concat__multiple_string__concatenation_successful();
    cm_string_contains__string_contains_substring__is_true();
    cm_string_contains_insensitive__string_contains_substring__is_true();
    cm_string_ends_with__string_ends_with_substring__is_true();
    cm_string_ends_with_insensitive__string_ends_with_substring__is_true();
    cm_string_starts_with__string_ends_with_substring__is_true();
    cm_string_starts_with_insensitive__string_ends_with_substring__is_true();
}
