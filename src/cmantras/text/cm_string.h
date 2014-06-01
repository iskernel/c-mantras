#ifndef CM_STRING_H
#define CM_STRING_H

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "cmantras/base/cm_base_types.h"
#include "cmantras/base/helpers/cm_text.h"

struct cm_string
{
    char* content;
    cm_size length;
};

struct cm_string* cm_string_create_from_char_array(char* content);

struct cm_string* cm_string_create_from_string(struct cm_string* string);

struct cm_string* cm_string_create_from_char(char character);

struct cm_string* cm_string_create_from_integer(int64_t number, uint8_t radix);

struct cm_string* cm_string_create_from_real(double number);

void cm_string_to_lower(struct cm_string* string);

void cm_string_to_upper(struct cm_string* string);

cm_cmp_size cm_string_compare(struct cm_string* string1,
                              struct cm_string* string2);

cm_cmp_size cm_string_compare_insensitive(struct cm_string* string1,
                                          struct cm_string* string2);

double cm_string_compare_ordinal(struct cm_string* string1,
                                 struct cm_string* string2);

bool cm_string_are_equal(struct cm_string* string1, struct cm_string* string2);

struct cm_string* cm_string_concat(struct cm_string* string, ...);

bool cm_string_contains(struct cm_string* source, struct cm_string* substring);

bool cm_string_contains_insensitive(struct cm_string* source,
                                    struct cm_string* substring);

bool cm_string_ends_with(struct cm_string* source, struct cm_string* substring);

bool cm_string_ends_with_insensitive(struct cm_string* source,
                                     struct cm_string* substring);

bool cm_string_starts_with(struct cm_string* source,
                           struct cm_string* substring);

bool cm_string_starts_with_insensitive(struct cm_string* source,
                                       struct cm_string* substring);

void cm_string_destroy(struct cm_string* stringObj);

#endif // CM_STRING_H
