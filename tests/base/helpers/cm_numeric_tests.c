#include "cm_numeric_tests.h"

#include "../../cm_test_base.h"
#include "cmantras/base/helpers/cm_numeric.h"

static void get_number_of_digits__positive_number__is_calculated_corectly()
{
    size_t digits = get_number_of_digits(1234567);
    bool condition = (digits == 7);

    assert_is_true(condition, __func__);
}

static void get_number_of_digits__negative_number__is_calculated_corectly()
{
    size_t digits = get_number_of_digits(-1234567);
    bool condition = (digits == 7);

    assert_is_true(condition, __func__);
}

static void double_is_within__is_within__returns_true()
{
    bool condition = double_is_within(2.0, 1.0, 3.0);
    assert_is_true(condition, __func__);
}

static void double_is_within__is_not_within__returns_false()
{
    bool condition = (double_is_within(-2.0, 1.0, 3.0) == false);
    assert_is_true(condition, __func__);
}

static void uint8_is_within__is_within__returns_true()
{
    bool condition = uint8_is_within(2, 1, 3);
    assert_is_true(condition, __func__);
}

static void uint8_is_within__is_not_within__returns_false()
{
    bool condition = (uint8_is_within(-2, 1, 3) == false);
    assert_is_true(condition, __func__);
}

static void double_get_min__normal_case__min_returned()
{
    double min = double_get_min(3, 1.0, 2.0, 3.0);
    bool condition = (min == 1.0);
    assert_is_true(condition, __func__);
}

static void double_get_max__normal_case__min_returned()
{
    bool condition = (double_get_max(3, 1.0, 2.0, 3.0) == 3.0);
    assert_is_true(condition, __func__);
}

void cm_numeric_tests_run(void)
{
    get_number_of_digits__positive_number__is_calculated_corectly();
    get_number_of_digits__negative_number__is_calculated_corectly();
    double_is_within__is_within__returns_true();
    double_is_within__is_not_within__returns_false();
    uint8_is_within__is_within__returns_true();
    uint8_is_within__is_not_within__returns_false();
    double_get_min__normal_case__min_returned();
    double_get_max__normal_case__min_returned();
}
