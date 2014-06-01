#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include"cm_test_base.h"

static void separate_test(const char* test_name, char** function,
                          char** scenario, char** expected_result)
{
    const char* delimiter = "__";
    char* iterator_1 = NULL;
    char* iterator_2 = NULL;
    uint32_t length = 0;

    iterator_1 = strstr(test_name, delimiter);
    length = iterator_1 - test_name;
    *function = malloc(sizeof(char) * (length + 1));
    strncpy(*function, test_name, length);
    (*function)[length] = '\0';

    iterator_1 += 2 * sizeof(char);
    iterator_2 = strstr(iterator_1, delimiter);
    length = iterator_2 - iterator_1;
    *scenario = malloc(sizeof(char) * (length + 1));
    strncpy(*scenario, iterator_1, length);
    (*scenario)[length] = '\0';

    iterator_2 += 2 * sizeof(char);
    length = strlen(test_name) - (iterator_2 - test_name);
    *expected_result = malloc(sizeof(char) * (length + 1));
    strncpy(*expected_result, iterator_2, length);
    (*expected_result)[length] = '\0';
}

void assert_is_true(bool condition, const char* test_name)
{
    char* function = NULL;
    char* scenario = NULL;
    char* expected_result = NULL;

    separate_test(test_name, &function, &scenario, &expected_result);

    if (condition == true)
    {
        printf("%30s  %30s %30s %10s \n", function, scenario, expected_result,
               "SUCCESS");
    }
    else
    {
        printf("%30s %30s %30s 10%s \n", function, scenario, expected_result,
               "FAILED");
    }
    free(function);
    free(scenario);
    free(expected_result);
}

void assert_is_false(bool condition, const char* test_name)
{
    char* function = NULL;
    char* scenario = NULL;
    char* expected_result = NULL;

    separate_test(test_name, &function, &scenario, &expected_result);

    if (condition == false)
    {
        printf("%30s  %30s %30s %10s \n", function, scenario, expected_result,
               "SUCCESS");
    }
    else
    {
        printf("%30s %30s %30s 10%s \n", function, scenario, expected_result,
               "FAILED");
    }
    free(function);
    free(scenario);
    free(expected_result);
}

void assert_win(const char* test_name)
{
    char* function = NULL;
    char* scenario = NULL;
    char* expected_result = NULL;

    separate_test(test_name, &function, &scenario, &expected_result);
    printf("%30s  %30s %30s %10s \n", function, scenario, expected_result,
           "SUCCESS");

    free(function);
    free(scenario);
    free(expected_result);
}

void assert_fail(const char* test_name)
{
    char* function = NULL;
    char* scenario = NULL;
    char* expected_result = NULL;

    separate_test(test_name, &function, &scenario, &expected_result);
    printf("%30s %30s %30s 10%s \n", function, scenario, expected_result,
           "FAILED");

    free(function);
    free(scenario);
    free(expected_result);
}

void run_if(bool condition, const char* message, void (*function)(void))
{
    if (condition == true)
    {
        puts("===========================================");
        puts(message);
        printf("%30s  %30s %30s %10s \n", "FUNCTION", "SCENARIO",
               "EXPECTED_RESULT", "STATUS");
        function();
        printf("%s finished with success\n", message);
        puts("===========================================");
    }
}
