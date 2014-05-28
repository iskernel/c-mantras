#ifndef BASE_HELPERS_CM_TEXT_H
#define BASE_HELPERS_CM_TEXT_H

#include <stdint.h>

char* itoa(int64_t value, char *string, uint8_t radix);

void char_array_to_lower(char* array, size_t length);

void char_array_to_upper(char* array, size_t length);

char* char_array_copy(const char* array, size_t length);

#endif /* CM_HELPERS_TEXT_H_ */
