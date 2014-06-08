#include <string.h>

#include "cm_classical_ciphers_tests.h"

#include "cmantras/text/cm_string.h"
#include "cmantras/cryptography/cm_classical_ciphers.h"

#include "../cm_test_base.h"

static void cm_classical_ciphers_caesar_apply__encode_decode__is_successful(
        void)
{
    struct cm_string* message = cm_string_create_from_char_array(
            "The quick, brown fox jumps over the lazy dog!");

    struct cm_string* encoded = cm_classical_ciphers_caesar_apply(message, 3,
                                                                  false);
    struct cm_string* decoded = cm_classical_ciphers_caesar_apply(encoded,
                                                                  26 - 3,
                                                                  false);

    assert_is_true((strcmp(message->content, decoded->content) == 0), __func__);

    cm_string_destroy(message);
    cm_string_destroy(encoded);
    cm_string_destroy(decoded);
}

static void cm_classical_ciphers_disk_apply__encode_decode__is_successful(void)
{
    struct cm_string* original_alphabet = cm_string_create_from_char_array(
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!?, ");
    struct cm_string* other_alphabet = cm_string_create_from_char_array(
            "ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba!?, ");
    struct cm_string* message = cm_string_create_from_char_array(
            "The quick, brown fox jumps over the lazy dog!");

    struct cm_string* encoded = cm_classical_ciphers_disk_apply(
            message, original_alphabet, other_alphabet, 1);
    struct cm_string* decoded = cm_classical_ciphers_disk_apply(
            encoded, other_alphabet, original_alphabet, -1);

    assert_is_true((strcmp(decoded->content, message->content) == 0), __func__);

    cm_string_destroy(original_alphabet);
    cm_string_destroy(other_alphabet);
    cm_string_destroy(message);
    cm_string_destroy(encoded);
    cm_string_destroy(decoded);
}

static void cm_classical_ciphers_substitution_apply__encode_decode__is_successful(
        void)
{
    struct cm_string* original_alphabet = cm_string_create_from_char_array(
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!?, ");
    struct cm_string* other_alphabet = cm_string_create_from_char_array(
            "ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba!?, ");
    struct cm_string* message = cm_string_create_from_char_array(
            "The quick, brown fox jumps over the lazy dog!");

    struct cm_string* encoded = cm_classical_ciphers_substitution_apply(
            message, original_alphabet, other_alphabet);
    struct cm_string* decoded = cm_classical_ciphers_substitution_apply(
            encoded, other_alphabet, original_alphabet);

    assert_is_true((strcmp(decoded->content, message->content) == 0), __func__);

    cm_string_destroy(original_alphabet);
    cm_string_destroy(other_alphabet);
    cm_string_destroy(message);
    cm_string_destroy(encoded);
    cm_string_destroy(decoded);
}

void cm_classical_ciphers_tests_run(void)
{
    cm_classical_ciphers_caesar_apply__encode_decode__is_successful();
    cm_classical_ciphers_disk_apply__encode_decode__is_successful();
    cm_classical_ciphers_substitution_apply__encode_decode__is_successful();
}
