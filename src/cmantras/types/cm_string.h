#ifndef CMOBJECTS_H
#define CMOBJECTS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "cm_common_types.h"

typedef struct
{
    char* content;
    cmsize length;
}cmstring;

cmstring* cmstring_create_from_char_array(char* content);
cmstring* cmstring_create_from_other_string(cmstring* string);
cmstring* cmstring_create_from_char(char character);
cmstring* cmstring_create_from_number(int64_t number, uint8_t radix);
cmstring* cmstring_concat(cmstring* string, ...);
int8_t cmstring_compare(cmstring* string1, cmstring* string2);
int8_t cmstring_compare_insensitive(cmstring* string1, cmstring* string2);
double cmstring_compare_ordinal(cmstring* string1, cmstring* string2);
bool cmstring_are_equal(cmstring* string1, cmstring* string2);
cmstring* cmstring_concat(cmstring* string, ...);
bool cmstring_contains(cmstring* source, cmstring* substring);
bool cmstring_contains_insensitive(cmstring* source, cmstring* substring);
bool cmstring_ends_with(cmstring* source, cmstring* substring);
bool cmstring_ends_with_insensitive(cmstring* source, cmstring* substring);
void string_destroy(cmstring* stringObj);

#endif // CMOBJECTS_H
