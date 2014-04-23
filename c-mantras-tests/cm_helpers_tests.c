#include "cm_test_base.h"
#include "cm_helpers.h"
#include "cm_helpers_tests.h"


static void itoa_negativeNumber_isConverted()
{
    int64_t testedNumber = -88;

    char* numberAsString = NULL;
    bool condition = false;

    numberAsString= malloc(sizeof(char)*20);
    itoa(testedNumber, numberAsString, 10);
    condition = (strcmp("-88", numberAsString) == 0);

    assert_is_true(condition, __func__);
}

static void itoa_positiveNumber_isConverted()
{
    int64_t testedNumber = 88;

    char* numberAsString = NULL;
    bool condition = false;

    numberAsString= malloc(sizeof(char)*20);
    itoa(testedNumber, numberAsString, 10);
    condition = (strcmp("88", numberAsString) == 0);

    assert_is_true(condition, __func__);
}

static void itoa_unsignedNumber_isConverted()
{
    uint64_t testedNumber = 88;

    char* numberAsString = NULL;
    bool condition = false;

    numberAsString= malloc(sizeof(char)*20);
    itoa(testedNumber, numberAsString, 10);
    condition = (strcmp("88", numberAsString) == 0);

    assert_is_true(condition, __func__);
}

void cmhelpers_runTests()
{
    itoa_negativeNumber_isConverted();
    itoa_positiveNumber_isConverted();
    itoa_unsignedNumber_isConverted();
}
