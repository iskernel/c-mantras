#ifndef CM_HELPERS_H
#define CM_HELPERS_H

#include <stdint.h>
#include <stdbool.h>
#include "cm_common.h"

int64_t itoa(int64_t value, char *string, uint8_t radix);

char* char_array_to_lower(char* array, cm_size_u length);

cm_size_u get_number_of_digits(int64_t value);

char* char_array_copy(char* array, cm_size_u length);

bool double_is_within(double value, double min_value, double max_value);

#endif // CM_HELPERS_H
