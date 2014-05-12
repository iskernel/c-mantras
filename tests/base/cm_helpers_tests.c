#include "cmantras/base/cm_helpers.h"

#include "../cm_test_base.h"
#include "cm_helpers_tests.h"


static void itoa__negative_number_is_converted()
{
    int64_t testedNumber = -88;

    char* numberAsString = NULL;
    bool condition = false;

    numberAsString= malloc(sizeof(char)*20);
    itoa(testedNumber, numberAsString, 10);
    condition = (strcmp("-88", numberAsString) == 0);

    assert_is_true(condition, __func__);
}

static void itoa__positive_number_is_converted()
{
    int64_t testedNumber = 88;

    char* numberAsString = NULL;
    bool condition = false;

    numberAsString= malloc(sizeof(char)*20);
    itoa(testedNumber, numberAsString, 10);
    condition = (strcmp("88", numberAsString) == 0);

    assert_is_true(condition, __func__);
}

static void itoa__unsigned_number_is_converted()
{
    uint64_t testedNumber = 88;

    char* numberAsString = NULL;
    bool condition = false;

    numberAsString= malloc(sizeof(char)*20);
    itoa(testedNumber, numberAsString, 10);
    condition = (strcmp("88", numberAsString) == 0);

    assert_is_true(condition, __func__);
}

void cm_helpers_run_tests()
{
	itoa__negative_number_is_converted();
	itoa__positive_number_is_converted();
	itoa__unsigned_number_is_converted();
}
