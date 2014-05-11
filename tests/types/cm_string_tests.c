#include "../cm_test_base.h"
#include "cm_string_tests.h"
#include "cmantras/types/cm_common_types.h"
#include "cmantras/types/cm_string.h"



static void cmstring_createFromCharArray_fromCharArray_isCreated()
{
    const char* TEST_CONTENT = "test content";
    char* content = NULL;
    cmstring* string = NULL;
    cmsize expectedLength = 0;
    bool condition = false;

    expectedLength = strlen(TEST_CONTENT);
    content = malloc(sizeof(char) * expectedLength);
    strcpy(content, TEST_CONTENT);
    string = cmstring_create_from_char_array(content);

    condition = (string->length == expectedLength)
                && (strcmp(string->content, TEST_CONTENT)==0);

    assert_is_true(condition, __func__);
}

static void cmstring_createFromOtherString_fromOtherString_isCreated()
{
    cmstring* string1 = NULL;
    cmstring* string2 = NULL;
    bool condition = false;

    string1 = cmstring_create_from_char_array("test content");
    string2 = cmstring_create_from_other_string(string1);
    condition = ( strcmp(string1->content, string2->content) == 0)
                && (string1->length == string2->length);
    assert_is_true(condition, __func__);
}

static void cmstring_createFromChar_fromChar_isCreated()
{
    char char1 = 'r';
    bool condition = false;
    cmstring* string = NULL;

    string = cmstring_create_from_char(char1);
    condition = (string->length == 1) && (strcmp(string->content, "r") ==0);
    assert_is_true(condition, __func__);
}

static void cmstring_createFromNumber_positiveNumber_isCreated()
{
    bool condition = false;
    cmstring* string = NULL;

    string = cmstring_create_from_number(88, 10);
    condition = (string->length == 2) && (strcmp(string->content, "88") ==0);
    assert_is_true(condition, __func__);
}

static void cmstring_createFromNumber_negativeNumber_isCreated()
{
    bool condition = false;
    cmstring* string = NULL;

    string = cmstring_create_from_number(-88, 10);
    condition = (string->length == 3) && (strcmp(string->content, "-88") ==0);
    assert_is_true(condition, __func__);
}


void cmstring_runTests()
{
    cmstring_createFromCharArray_fromCharArray_isCreated();
    cmstring_createFromOtherString_fromOtherString_isCreated();
    cmstring_createFromChar_fromChar_isCreated();
    cmstring_createFromNumber_positiveNumber_isCreated();
    cmstring_createFromNumber_negativeNumber_isCreated();
}
