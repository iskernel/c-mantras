#ifndef CM_HELPERS_H
#define CM_HELPERS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include "cmantras/base/cm_base_common.h"

int64_t itoa(int64_t value, char *string, uint8_t radix);

char* char_array_to_lower(char* array, cm_size_u length);

cm_size_u get_number_of_digits(int64_t value);

char* char_array_copy(char* array, cm_size_u length);

/*
 * Description:
 * 	Checks if a value is within a specified interval
 * Parameters:
 *  value - the value who is checked
 *  min_value - the lower limit of the interval
 *  max_value - the upper limit of the interval
 * Returns:
 *  true if the value is within the interval
 *  false if the value is not within the interval
 */
bool double_is_within(double value, double min_value, double max_value);

/*
 * Description:
 * 	Checks if a value is within a specified interval
 * Parameters:
 *  value - the value who is checked
 *  min_value - the lower limit of the interval
 *  max_value - the upper limit of the interval
 * Returns:
 *  true if the value is within the interval
 *  false if the value is not within the interval
 */
bool uint8_is_within(uint8_t value, uint8_t min_value, uint8_t max_value);

double double_get_min(uint8_t number_of_args, double arg, ...);

double double_get_max(uint8_t number_of_args, double arg, ...);

#endif // CM_HELPERS_H
