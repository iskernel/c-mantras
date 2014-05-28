#ifndef CM_TESTS_BASE_H_
#define CM_TESTS_BASE_H_

#include <stdbool.h>

void assert_is_true(bool condition, const char* test_name);
void assert_is_false(bool condition, const char* test_name);
void assert_win(const char* test_name);
void assert_fail(const char* test_name);

void run_if(bool condition, const char* message, void (*function)(void));
#endif
