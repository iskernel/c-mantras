#ifndef BASE_HELPERS_CM_NUMERIC_H
#define BASE_HELPERS_CM_NUMERIC_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>

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

size_t get_number_of_digits(int64_t value);

#endif /* CM_HELPERS_NUMERIC_H_ */
