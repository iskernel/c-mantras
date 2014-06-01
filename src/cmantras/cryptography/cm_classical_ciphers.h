#ifndef CM_CLASSICAL_CIPHERS_H_
#define CM_CLASSICAL_CIPHERS_H_

#include <stdint.h>
#include <string.h>
#include <math.h>

#include "cmantras/text/cm_string.h"

struct cm_string* cm_classical_ciphers_caesar_apply(struct cm_string* message,
                                                    int8_t shift,
                                                    bool shift_non_alphanumeric);
struct cm_string* cm_classical_ciphers_disk_apply(
        struct cm_string* message, struct cm_string* original_alphabet,
        struct cm_string* other_alphabet, int8_t shift);
struct cm_string* cm_classical_ciphers_substitution_apply(
        struct cm_string* message, struct cm_string* original_alphabet,
        struct cm_string* other_alphabet);
#endif
