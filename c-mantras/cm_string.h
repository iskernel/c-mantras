#ifndef CMOBJECTS_H
#define CMOBJECTS_H

#include "cm_base.h"

typedef struct
{
    char* content;
    cmsize length;
}cmstring;

cmstring* cmstring_create_from_char_array(char* content);
cmstring* cmstring_create_from_other_string(cmstring* string);
cmstring* cmstring_create_from_char(char character);
cmstring* cmstring_create_from_number(int64_t number, uint8_t radix);
cmstring* cmstring_combine(cmstring* string, ...);

#endif // CMOBJECTS_H
