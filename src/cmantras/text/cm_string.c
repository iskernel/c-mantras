#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#include "cmantras/base/cm_base_types.h"
#include "cmantras/base/cm_error_log.h"
#include "cmantras/base/helpers/cm_text.h"
#include "cm_string.h"

struct cm_interface_string cm_string_methods;

static struct cm_string* cm_string_create(char* content, cm_size length)
{
	struct cm_string* string = NULL;

	string = malloc(sizeof(struct cm_string));
	string->data = malloc(sizeof(struct cm_string_data));
	string->data->content = malloc( (length + 1) * sizeof(char));
	strcpy(string->data->content, content);
	string->data->length = length;
	string->methods = &cm_string_methods;

	return string;
}

struct cm_string* cm_string_create_from_char_array(char* content)
{
	struct cm_string* string = NULL;
	cm_size length = 0;

	length = strlen(content);
	string = cm_string_create(content, length);

	return string;
}

struct cm_string* cm_string_create_from_string(struct cm_string* string)
{
	struct cm_string* cmstring = NULL;

	cmstring = cm_string_create(string->data->content, string->data->length);

	return cmstring;
}

struct cm_string* cm_string_create_from_char(char character)
{
	struct cm_string* string = NULL;

	string = malloc(sizeof(struct cm_string));
	string->data = malloc(sizeof(struct cm_string_data));
	string->data->content = malloc(2 * sizeof(char));
	string->data->content[0] = character;
	string->data->length = 1;
	string->methods = &cm_string_methods;

	return string;
}

struct cm_string* cm_string_create_from_integer(int64_t number, uint8_t radix)
{
	const int8_t DEFAULT_CONVERTED_CONTENT_SIZE = 16;

	struct cm_string* string = NULL;
	cm_size length = 0U;
	char* converted_content = NULL;

	converted_content = malloc(sizeof(char) * (DEFAULT_CONVERTED_CONTENT_SIZE + 1));

	itoa(number, converted_content, radix);
	length = strlen(converted_content);

	string = cm_string_create(converted_content, length);

	return string;
}

struct cm_string* cm_string_create_from_real(double number)
{
	const int8_t DEFAULT_CONVERTED_CONTENT_SIZE = 64;

	struct cm_string* string = NULL;
	char* content = NULL;
	cm_size length = 0U;

	content = malloc(sizeof(char) * (DEFAULT_CONVERTED_CONTENT_SIZE +1));
	sprintf(content, "%lf", number);
	length = strlen(content);
	string = cm_string_create(content, length);

	return string;
}

struct cm_string* cm_string_to_lower(struct cm_string* string)
{
	uint32_t index = 0U;

	for (; index < string->data->length; index++)
	{
		string->data->content[index] = tolower(string->data->content[index]);
	}

	return string;
}

struct cm_string* cm_string_to_upper(struct cm_string* string)
{
	uint32_t index = 0U;

	for (; index < string->data->length; index++)
	{
		string->data->content[index] = toupper(string->data->content[index]);
	}

	return string;
}

cm_cmp_size cm_string_compare(struct cm_string* string1,
		struct cm_string* string2)
{
	cm_cmp_size result = strcmp(string1->data->content,
			string2->data->content);
	return result;
}

cm_cmp_size cm_string_compare_insensitive(struct cm_string* string1,
		struct cm_string* string2)
{
	cm_cmp_size result = 0;
	char* content1 = NULL;
	char* content2 = NULL;

	content1 = char_array_copy(string1->data->content, string1->data->length);
	content2 = char_array_copy(string2->data->content, string2->data->length);

	char_array_to_lower(content1, string1->data->length);
	char_array_to_lower(content2, string2->data->length);

	result = strcmp(content1, content2);

	return result;
}

double cm_string_compare_ordinal(struct cm_string* string1,
		struct cm_string* string2)
{
	double nr1 = 0.0;
	double nr2 = 0.0;
	double result = 0.0;

	nr1 = atof(string1->data->content);
	nr2 = atof(string2->data->content);
	result = nr1 - nr2;

	return result;
}

bool cm_string_are_equal(struct cm_string* string1, struct cm_string* string2)
{
	bool result = false;
	cm_cmp_size compare_result = 0;

	compare_result = strcmp(string1->data->content, string2->data->content);
	result = (compare_result == 0);

	return result;
}

struct cm_string* cm_string_concat(struct cm_string* string, ...)
{
	va_list args;
	char* content = NULL;
	struct cm_string* iterator = NULL;
	struct cm_string* result = NULL;
	cm_size size = 0U;

	va_start(args, string);
	for (iterator = string; iterator != NULL; iterator =
			va_arg(args, struct cm_string *))
	{
		size += iterator->data->length;
	}
	va_end(args);

	content = malloc(sizeof(char) * size);

	va_start(args, string);
	for (iterator = string; iterator != NULL; iterator =
			va_arg(args, struct cm_string *))
	{
		strcat(content, iterator->data->content);
	}
	va_end(args);

	result = cm_string_create_from_char_array(content);

	return result;
}

bool cm_string_contains(struct cm_string* source, struct cm_string* substring)
{
	char *pch = strstr(source->data->content, substring->data->content);
	bool result = (pch != NULL);
	return result;
}

bool cm_string_contains_insensitive(struct cm_string* source, struct cm_string* substring)
{
	char* source_content = NULL;
	char* substring_content = NULL;
	char* pch = NULL;
	bool ret_val = NULL;

	source_content = char_array_copy(source->data->content,
			source->data->length);
	substring_content = char_array_copy(substring->data->content,
			substring->data->length);
	char_array_to_lower(source_content, source->data->length);
	char_array_to_lower(substring_content,
			substring->data->length);

	pch = strstr(source_content, substring_content);
	ret_val = (pch != NULL);

	return ret_val;
}

bool cm_string_ends_with(struct cm_string* source, struct cm_string* substring)
{
	bool result = (substring->data->length <= source->data->length)
			&& (strcmp(
					source->data->content + source->data->length
							- substring->data->length, substring->data->content)
					== 0);
	return result;
}

bool cm_string_ends_with_insensitive(struct cm_string* source,
		struct cm_string* substring)
{
	char* source_content = NULL;
	char* substring_content = NULL;

	source_content = char_array_copy(source->data->content,
			source->data->length);
	substring_content = char_array_copy(substring->data->content,
			substring->data->length);
	char_array_to_lower(source_content, source->data->length);
	char_array_to_lower(substring_content, substring->data->length);

	bool result = (substring->data->length <= source->data->length)
			&& (strcmp(
					source_content + source->data->length
							- substring->data->length, substring_content) == 0);
	return result;
}

bool cm_string_starts_with(struct cm_string* source,
		struct cm_string* substring)
{
	bool result = (substring->data->length <= source->data->length)
			&& (strncmp(source->data->content, substring->data->content,
					substring->data->length) == 0);
	return result;
}

bool cm_string_starts_with_insensitive(struct cm_string* source,
		struct cm_string* substring)
{
	char* source_content = NULL;
	char* substring_content = NULL;

	source_content = char_array_copy(source->data->content,
			source->data->length);
	substring_content = char_array_copy(substring->data->content,
			substring->data->length);
	char_array_to_lower(source_content, source->data->length);
	char_array_to_lower(substring_content, substring->data->length);

	bool result = (substring->data->length <= source->data->length)
			&& (strncmp(source_content, substring_content,
					substring->data->length) == 0);
	return result;
}

void cm_string_destroy(struct cm_string* stringObj)
{
	free(stringObj->data->content);
	free(stringObj->data);
	free(stringObj);
}

struct cm_object_interface* cm_string_get_object_interface(void)
{
	struct cm_object_interface* interface = NULL;

	interface = cm_object_interface_create((void*) &cm_string_destroy,
										   (void*) &cm_string_are_equal,
										   (void*) &cm_string_compare,
										   (void*) &cm_string_create_from_string);
	return interface;
}

void module_cm_string_init(void)
{
	cm_string_methods.to_lower = &cm_string_to_lower;
	cm_string_methods.to_upper = &cm_string_to_upper;
	cm_string_methods.are_equal = &cm_string_are_equal;
	cm_string_methods.compare = &cm_string_compare;
	cm_string_methods.compare_insensitive = &cm_string_compare_insensitive;
	cm_string_methods.compare_ordinal = &cm_string_compare_ordinal;
	cm_string_methods.concat = &cm_string_concat;
	cm_string_methods.contains = &cm_string_contains;
	cm_string_methods.contains_insensitive = &cm_string_contains_insensitive;
	cm_string_methods.destroy = &cm_string_destroy;
	cm_string_methods.ends_with = &cm_string_ends_with;
	cm_string_methods.ends_with_insensitive = &cm_string_ends_with_insensitive;
	cm_string_methods.from_char = &cm_string_create_from_char;
	cm_string_methods.from_char_array = &cm_string_create_from_char_array;
	cm_string_methods.from_integer = &cm_string_create_from_integer;
	cm_string_methods.from_real = &cm_string_create_from_real;
	cm_string_methods.from_string = &cm_string_create_from_string;
	cm_string_methods.starts_with = &cm_string_starts_with;
	cm_string_methods.starts_with_insensitive = &cm_string_starts_with_insensitive;
	cm_string_methods.destroy = &cm_string_destroy;
	cm_string_methods.to_object = &cm_string_get_object_interface;
}
