#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#include "cm_classical_ciphers.h"

#include "cmantras/base/cm_error_log.h"
#include "cmantras/text/cm_string.h"

static const uint8_t NUMBER_OF_DIGITS = 10;
static const uint8_t NUMBER_OF_LETTERS = 26;

struct cm_string* cm_classical_ciphers_caesar_apply(struct cm_string* message,
                                                    int8_t shift,
                                                    bool shift_non_alphanumeric)
{
    struct cm_string* coded_message = NULL;
    cm_index index = 0;
    char* coded_message_content = NULL;

    cm_error_log_critical_if((message == NULL), __func__, " message is null");
    coded_message_content = malloc(sizeof(char) * (message->length + 1));
    cm_error_log_critical_if((coded_message_content == NULL), __func__,
                             " not enough memory");

    for (index = 0; index < message->length; index++)
    {
        if (islower(message->content[index]) != 0)
        {
            coded_message_content[index] = (((uint8_t) (message->content[index]
                    - 'a') + shift) % NUMBER_OF_LETTERS) + 'a';
        }
        else if (isupper(message->content[index]) != 0)
        {
            coded_message_content[index] = (((uint8_t) (message->content[index]
                    - 'A') + shift) % NUMBER_OF_LETTERS) + 'A';
        }
        else if (isdigit(message->content[index]) != 0)
        {
            coded_message_content[index] = (((uint8_t) (message->content[index]
                    - 'A') + shift) % NUMBER_OF_DIGITS) + 'A';
        }
        else
        {
            if (shift_non_alphanumeric == true)
            {
                coded_message_content[index] = (message->content[index] + shift)
                        % UCHAR_MAX;
            }
            else
            {
                coded_message_content[index] = message->content[index];
            }
        }
    }
    coded_message_content[message->length] = '\0';
    coded_message = cm_string_create_from_char_array(coded_message_content);
    free(coded_message_content);
    return coded_message;
}

struct cm_string* cm_classical_ciphers_disk_apply(
        struct cm_string* message, struct cm_string* original_alphabet,
        struct cm_string* other_alphabet, int8_t shift)
{
    struct cm_string* result = NULL;
    char* content = NULL;
    char* pointer = NULL;
    cm_index index = 0;
    cm_index position = 0;

    cm_error_log_critical_if((message == NULL), __func__, " message is null");
    cm_error_log_critical_if((original_alphabet == NULL), __func__,
                             " message is null");
    cm_error_log_critical_if((other_alphabet == NULL), __func__,
                             " message is null");
    cm_error_log_critical_if(
            ((other_alphabet->length != original_alphabet->length)), __func__,
            " length is not the same in the alphabets");

    content = malloc(sizeof(char) * (message->length + 1));
    cm_error_log_critical_if((content == NULL), __func__, " not enough memory");

    for (index = 0; index < message->length; index++)
    {
        pointer = strchr(original_alphabet->content, message->content[index]);
        cm_error_log_critical_if((pointer == NULL), __func__,
                                 " character not found in alphabet.");
        position = ( (pointer - original_alphabet->content)  - shift ) % original_alphabet->length;
        content[index] = other_alphabet->content[position];
    }
    content[message->length] = '\0';

    result = cm_string_create_from_char_array(content);
    free(content);
    return result;
}

struct cm_string* cm_classical_ciphers_substitution_apply(
        struct cm_string* message, struct cm_string* original_alphabet,
        struct cm_string* other_alphabet)
{
    struct cm_string* result = cm_classical_ciphers_disk_apply(
            message, original_alphabet, other_alphabet, 0U);
    return result;
}

