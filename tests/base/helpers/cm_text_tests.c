#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../cm_test_base.h"
#include "cm_text_tests.h"

#include "cmantras/base/helpers/cm_text.h"

static void itoa__negative_number__is_converted()
{
    int64_t test_number = -88;

    char* number_as_string = NULL;
    bool condition = false;

    number_as_string = malloc(sizeof(char) * 20);
    itoa(test_number, number_as_string, 10);
    condition = (strcmp("-88", number_as_string) == 0);

    assert_is_true(condition, __func__);

    free(number_as_string);
}

static void itoa__positive_number__is_converted()
{
    int64_t tested_number = 88;

    char* number_as_string = NULL;
    bool condition = false;

    number_as_string = malloc(sizeof(char) * 20);
    itoa(tested_number, number_as_string, 10);
    condition = (strcmp("88", number_as_string) == 0);

    assert_is_true(condition, __func__);

    free(number_as_string);
}

static void itoa__unsigned_number__is_converted()
{
    uint64_t tested_number = 88;

    char* number_as_string = NULL;
    bool condition = false;

    number_as_string = malloc(sizeof(char) * 20);
    itoa(tested_number, number_as_string, 10);
    condition = (strcmp("88", number_as_string) == 0);

    assert_is_true(condition, __func__);

    free(number_as_string);
}

static void char_array_to_lower__normal_scenario__array_is_lowered()
{
    char array[] = "ARRAY";
    size_t length = strlen(array);

    bool condition = false;
    size_t index = 0;
    char_array_to_lower(array, length);

    for (index = 0; index < length; index++)
    {
        condition = (array[index] == tolower(array[index]));
        if (condition == false)
        {
            assert_fail(__func__);
        }
    }
    assert_win(__func__);
}

static void char_array_to_upper__normal_scenario__array_is_uppered()
{
    char array[] = "ARRAY";
    size_t length = strlen(array);
    bool condition = false;
    size_t index = 0;

    char_array_to_upper(array, length);

    for (index = 0; index < length; index++)
    {
        condition = (array[index] == toupper(array[index]));
        if (condition == false)
        {
            assert_fail(__func__);
        }
    }
    assert_win(__func__);
}

static void char_array_copy__normal_scenario__is_deep_copy()
{
    char* array = "ARRAY";
    char* new_array = char_array_copy(array, strlen(array));
    bool condition = (array != new_array) && (strcmp(array, new_array) == 0);

    assert_is_true(condition, __func__);

    free(new_array);
}

void cm_text_tests_run(void)
{
    itoa__negative_number__is_converted();
    itoa__positive_number__is_converted();
    itoa__unsigned_number__is_converted();
    char_array_to_lower__normal_scenario__array_is_lowered();
    char_array_to_upper__normal_scenario__array_is_uppered();
    char_array_copy__normal_scenario__is_deep_copy();
}
