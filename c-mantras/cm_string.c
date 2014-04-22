#include <stdlib.h>
#include <string.h>

#include "cm_string.h"

string* string_createFromCharArray(char* content, cmSize length)
{
    string* newString;

    newString = malloc(sizeof(string));
    newString->content = malloc(sizeof(char*) * length);
    strcpy(newString->content, content);
    newString->length = length;

    return newString;
}

string* string_createFromOtherString(string* stringObj)
{
    string* newString;

    newString = malloc(sizeof(string));
    newString->content = malloc(sizeof(char*) * stringObj->length);
    strcpy(newString->content, stringObj->content);
    newString->length = stringObj->length;

    return newString;
}

string* string_createFromChar(char character)
{
    string* newString;

    newString = malloc(sizeof(string));
    newString->content = malloc( sizeof(char) );
    newString->content[0] = character;
    newString->length = 1;

    return newString;
}

string* string_createFromNumber(int64_t number)
{

}


void string_destroy(string* stringObj)
{
    free(stringObj->content);
    free(stringObj);
}
