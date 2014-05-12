#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include "../cm_test_base.h"
#include "cm_string_tests.h"

#include "cmantras/base/cm_common.h"
#include "cmantras/base/cm_string.h"

static void setup()
{
	module_cm_string_initialize();
}

static void cm_string_create_from_char_array__char_array_defined__is_created()
{
    const char* TEST_CONTENT = "test content";
    char* content = NULL;
    struct cm_string* string = NULL;
    cm_size_u expectedLength = 0;
    bool condition = false;

    expectedLength = strlen(TEST_CONTENT);
    content = malloc(sizeof(char) * expectedLength);
    strcpy(content, TEST_CONTENT);
    string = cm_string_create_from_char_array(content);

    condition = (string->data->length == expectedLength)
                && (strcmp(string->data->content, TEST_CONTENT)==0);

    assert_is_true(condition, __func__);
}

static void cm_string_create_from_string__other_string_defined__is_created()
{
	struct cm_string* string1 = NULL;
	struct cm_string* string2 = NULL;
    bool condition = false;

    string1 = cm_string_create_from_char_array("test content");
    string2 = cm_string_create_from_string(string1);
    condition = ( strcmp(string1->data->content, string2->data->content) == 0)
                && (string1->data->length == string2->data->length);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_char__a_char__isCreated()
{
    char char1 = 'r';
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_char(char1);
    condition = (string->data->length == 1) && (strcmp(string->data->content, "r") ==0);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_integer__positive_integer__is_created()
{
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_integer(88, 10);
    condition = (string->data->length == 2) && (strcmp(string->data->content, "88") ==0);
    assert_is_true(condition, __func__);
}

static void cm_string_create_from_integer__negative_integer__is_created()
{
    bool condition = false;
    struct cm_string* string = NULL;

    string = cm_string_create_from_integer(-88, 10);
    condition = (string->data->length == 3) && (strcmp(string->data->content, "-88") ==0);
    assert_is_true(condition, __func__);
}

void cm_string_run_tests()
{
	setup();
	cm_string_create_from_char_array__char_array_defined__is_created();
	cm_string_create_from_string__other_string_defined__is_created();
	cm_string_create_from_char__a_char__isCreated();
	cm_string_create_from_integer__positive_integer__is_created();
	cm_string_create_from_integer__negative_integer__is_created();
}
