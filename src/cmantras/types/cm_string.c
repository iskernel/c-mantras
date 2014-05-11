#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#include "../base/cm_helpers.h"
#include "cm_common_types.h"
#include "cm_string.h"

cmstring* cmstring_create_from_char_array(char* content)
{
    cmstring* string = NULL;
    cmsize length = 0;

    length = strlen(content);
    string = malloc(sizeof(cmstring));
    string->content = malloc(sizeof(char*) * length);
    strcpy(string->content, content);
    string->length = length;

    return string;
}

cmstring* cmstring_create_from_other_string(cmstring* string)
{
    cmstring* cmstring = NULL;

    cmstring = malloc(sizeof(cmstring));
    cmstring->content = malloc(sizeof(char*) * string->length);
    strcpy(cmstring->content, string->content);
    cmstring->length = string->length;

    return cmstring;
}

cmstring* cmstring_create_from_char(char character)
{
    cmstring* string = NULL;

    string = malloc(sizeof(cmstring));
    string->content = malloc( sizeof(char) );
    string->content[0] = character;
    string->length = 1;

    return string;
}

cmstring* cmstring_create_from_number(int64_t number, uint8_t radix)
{
    const int8_t DEFAULT_CONVERTED_CONTENT_SIZE = 16;

    cmstring* string = NULL;

    char* converted_content = malloc(sizeof(char)
                                     * DEFAULT_CONVERTED_CONTENT_SIZE);

    itoa(number, converted_content, radix);
    uint8_t length = strlen(converted_content);

    string = malloc(sizeof(cmstring));
    string->content = malloc(sizeof(char*) * length);
    strcpy(string->content, converted_content);
    string->length = length;

    return string;
}

int8_t cmstring_compare(cmstring* string1, cmstring* string2)
{
    int8_t result = strcmp(string1->content, string2->content);
    return result;
}

int8_t cmstring_compare_insensitive(cmstring* string1, cmstring* string2)
{
    char* str1_content = tolower(string1->content);
    char* str2_content = tolower(string2->content);
    int8_t result = strcmp(str1_content, str2_content);
    return result;
}

double cmstring_compare_ordinal(cmstring* string1, cmstring* string2)
{
    double nr1 = atof(string1->content);
    double nr2 = atof(string2->content);
    double result = nr1 - nr2;
    return result;
}

bool cmstring_are_equal(cmstring* string1, cmstring* string2)
{
    bool result = ( strcmp(string1->content, string2->content) == 0);
    return result;
}

cmstring* cmstring_concat(cmstring* string, ...)
{
    va_list args;
    char* content = NULL;
    cmstring* iterator = NULL;
    cmstring* result = NULL;
    uint32_t size = 0U;

    va_start(args, string);
    do
    {
        iterator = va_arg(args, cmstring*);
        if(iterator != NULL)
        {
            size += iterator->length;
        }
    }while(iterator!=NULL);
    va_end(args);

    content = malloc( sizeof(char) * size );

    va_start(args, string);
    do
    {
        iterator = va_arg(args, cmstring*);
        if(iterator != NULL)
        {
            strcat(content, iterator->content);
        }
    }while(iterator!=NULL);
    va_end(args);

    result = cmstring_create_from_char_array(content);

    return result;
}

bool cmstring_contains(cmstring* source, cmstring* substring)
{
    char *pch = strstr(source->content, substring->content);
    bool result = (pch != NULL);
    return result;
}

bool cmstring_contains_insensitive(cmstring* source, cmstring* substring)
{
    char* sourceContent = tolower(source->content);
    char* substringContent = tolower(substring->content);
    char* pch = strstr(sourceContent, substringContent);
    bool result = (pch != NULL);
    return result;
}

bool cmstring_ends_with(cmstring* source, cmstring* substring)
{
    bool result = (substring->length <= source->length)
                  && (strcmp(source->content + source->length
                             -substring->length,
                             substring->content) == 0);
    return result;
}

bool cmstring_ends_with_insensitive(cmstring* source, cmstring* substring)
{
    char* sourceContent = tolower(source->content);
    char* substringContent = tolower(substring->content);
    bool result =   (substring->length <= source->length)
                    && (strcmp(sourceContent + source->length
                            - substring->length,
                        substringContent) == 0);
    return result;
}

void string_destroy(cmstring* stringObj)
{
    free(stringObj->content);
    free(stringObj);
}
