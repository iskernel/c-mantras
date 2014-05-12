#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#include "cm_helpers.h"
#include "cm_common.h"
#include "cm_string.h"

struct cm_interface_string* DEFAULT_CM_STRING_INTERFACE = NULL;

static struct cm_string* cm_string_create(char* content, cm_size_u length)
{
	struct cm_string* string = NULL;

	string = malloc(sizeof(struct cm_string));
	string->data = malloc(sizeof(struct cm_string_data));
	string->data->content = malloc(length * sizeof(char) );
	strcpy(string->data->content, content);
	string->data->length = length;
	string->methods = DEFAULT_CM_STRING_INTERFACE;

	return string;
}

struct cm_string* cm_string_create_from_char_array(char* content)
{
	struct cm_string* string = NULL;
	cm_size_u length = 0;

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
	string->data->content = malloc(2*sizeof(char));
	string->data->content[0] = character;
	string->data->length = 1;
	string->methods = DEFAULT_CM_STRING_INTERFACE;

	return string;
}

struct cm_string* cm_string_create_from_integer(int64_t number, uint8_t radix)
{
	const int8_t DEFAULT_CONVERTED_CONTENT_SIZE = 16;

	struct cm_string* string = NULL;
	cm_size_u length = 0U;
	char* converted_content = NULL;

	converted_content = malloc(sizeof(char) * DEFAULT_CONVERTED_CONTENT_SIZE);

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
	cm_size_u length = 0U;

	content = malloc(sizeof(char) * DEFAULT_CONVERTED_CONTENT_SIZE);
	sprintf(content, "%lf", number);
	length = strlen(content);
	string = cm_string_create(content, length);

	return string;
}

static struct cm_string* cm_string_to_lower(struct cm_string* string)
{
	uint32_t index = 0U;

	for (; index < string->data->length; index++)
	{
		string->data->content[index] = tolower(string->data->content[index]);
	}

	return string;
}

static struct cm_string* cm_string_to_upper(struct cm_string* string)
{
	uint32_t index = 0U;

	for (; index < string->data->length; index++)
	{
		string->data->content[index] = toupper(string->data->content[index]);
	}

	return string;
}

static cm_cmp_size_i cm_string_compare(struct cm_string* string1,
		struct cm_string* string2)
{
	cm_cmp_size_i result = strcmp(string1->data->content,
			string2->data->content);
	return result;
}

static cm_cmp_size_i cm_string_compare_insensitive(struct cm_string* string1,
		struct cm_string* string2)
{
	cm_cmp_size_i result = 0;
	char* content1 = NULL;
	char* content2 = NULL;

	memcpy(content1, string1->data->content,
			string1->data->length * sizeof(char));
	memcpy(content2, string2->data->content,
			string2->data->length * sizeof(char));
	content1 = char_array_to_lower(content1, string1->data->length);
	content2 = char_array_to_lower(content2, string2->data->length);
	result = strcmp(content1, content2);

	return result;
}

static double cm_string_compare_ordinal(struct cm_string* string1,
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

static bool cm_string_are_equal(struct cm_string* string1,
		struct cm_string* string2)
{
	bool result = false;
	cm_cmp_size_i compare_result = 0;

	compare_result = strcmp(string1->data->content, string2->data->content);
	result = (compare_result == 0);

	return result;
}

static struct cm_string* cm_string_concat(struct cm_string* string, ...)
{
	va_list args;
	char* content = NULL;
	struct cm_string* iterator = NULL;
	struct cm_string* result = NULL;
	cm_size_u size = 0U;

	va_start(args, string);
	do
	{
		iterator = va_arg(args, struct cm_string*);
		if (iterator != NULL)
		{
			size += iterator->data->length;
		}
	} while (iterator != NULL);
	va_end(args);

	content = malloc(sizeof(char) * size);

	va_start(args, string);
	do
	{
		iterator = va_arg(args, struct cm_string*);
		if (iterator != NULL)
		{
			strcat(content, iterator->data->content);
		}
	} while (iterator != NULL);
	va_end(args);

	result = cm_string_create_from_char_array(content);

	return result;
}

static bool cm_string_contains(struct cm_string* source,
		struct cm_string* substring)
{
	char *pch = strstr(source->data->content, substring->data->content);
	bool result = (pch != NULL);
	return result;
}

static bool cm_string_contains_insensitive(struct cm_string* source,
		struct cm_string* substring)
{
	char* source_content = NULL;
	char* substring_content = NULL;
	char* pch = NULL;
	bool ret_val = NULL;

	memcpy(source_content, source->data->content,
			source->data->length * sizeof(char));
	memcpy(substring_content, substring->data->content,
			substring->data->length * sizeof(char));
	source_content = char_array_to_lower(source_content, source->data->length);
	substring_content = char_array_to_lower(substring_content,
			substring->data->length);

	pch = strstr(source_content, substring_content);
	ret_val = (pch != NULL);

	return ret_val;
}

static bool cm_string_ends_with(struct cm_string* source,
		struct cm_string* substring)
{
	bool result = (substring->data->length <= source->data->length)
			&& (strcmp(
					source->data->content + source->data->length
							- substring->data->length, substring->data->content)
					== 0);
	return result;
}

static bool cm_string_ends_with_insensitive(struct cm_string* source,
		struct cm_string* substring)
{
	char* source_content = NULL;
	char* substring_content = NULL;

	memcpy(source_content, source->data->content,
			source->data->length * sizeof(char));
	memcpy(substring_content, substring->data->content,
			substring->data->length * sizeof(char));
	source_content = char_array_to_lower(source_content, source->data->length);
	substring_content = char_array_to_lower(substring_content,
			substring->data->length);

	source_content = char_array_to_lower(source_content, source->data->length);
	substring_content = char_array_to_lower(substring_content,
			substring->data->length);

	bool result = (substring->data->length <= source->data->length)
			&& (strcmp(
					source_content + source->data->length
							- substring->data->length, substring_content) == 0);
	return result;
}

static bool cm_string_starts_with(struct cm_string* source,
		struct cm_string* substring)
{
	bool result = (substring->data->length <= source->data->length)
			&& (strncmp(source->data->content, substring->data->content,
					substring->data->length) == 0);
	return result;
}

static bool cm_string_starts_with_insensitive(struct cm_string* source,
		struct cm_string* substring)
{
	char* source_content = NULL;
	char* substring_content = NULL;

	memcpy(source_content, source->data->content,
			source->data->length * sizeof(char));
	memcpy(substring_content, substring->data->content,
			substring->data->length * sizeof(char));
	source_content = char_array_to_lower(source_content, source->data->length);
	substring_content = char_array_to_lower(substring_content,
			substring->data->length);

	source_content = char_array_to_lower(source_content, source->data->length);
	substring_content = char_array_to_lower(substring_content,
			substring->data->length);

	bool result = (substring->data->length <= source->data->length)
			&& (strncmp(source_content, substring_content,
					substring->data->length) == 0);
	return result;
}

static void cm_string_destroy(struct cm_string* stringObj)
{
	if(stringObj!=NULL)
	{
		if(stringObj->data->content != NULL)
		{
			free(stringObj->data->content);
		}
		free(stringObj);
	}
}

static struct cm_object* cm_string_to_cm_object(struct cm_string* string)
{
	struct cm_object* object = NULL;
	struct cm_interface_object* interface = NULL;

	interface = cm_object_interface_create(&(*cm_string_destroy),
			&cm_string_are_equal, &cm_string_compare,
			&cm_string_create_from_string);
	object = cm_object_create(string, interface);

	return object;
}

void module_cm_string_initialize(void)
{
	DEFAULT_CM_STRING_INTERFACE = malloc(sizeof(struct cm_interface_object));
	DEFAULT_CM_STRING_INTERFACE->to_lower = &cm_string_to_lower;
	DEFAULT_CM_STRING_INTERFACE->to_upper = &cm_string_to_upper;
	DEFAULT_CM_STRING_INTERFACE->are_equal = &cm_string_are_equal;
	DEFAULT_CM_STRING_INTERFACE->compare = &cm_string_compare;
	DEFAULT_CM_STRING_INTERFACE->compare_insensitive =
			&cm_string_compare_insensitive;
	DEFAULT_CM_STRING_INTERFACE->compare_ordinal = &cm_string_compare_ordinal;
	DEFAULT_CM_STRING_INTERFACE->concat = &cm_string_concat;
	DEFAULT_CM_STRING_INTERFACE->contains = &cm_string_contains;
	DEFAULT_CM_STRING_INTERFACE->contains_insensitive =
			&cm_string_contains_insensitive;
	DEFAULT_CM_STRING_INTERFACE->destroy = &cm_string_destroy;
	DEFAULT_CM_STRING_INTERFACE->ends_with = &cm_string_ends_with;
	DEFAULT_CM_STRING_INTERFACE->ends_with_insensitive =
			&cm_string_ends_with_insensitive;
	DEFAULT_CM_STRING_INTERFACE->from_char = &cm_string_create_from_char;
	DEFAULT_CM_STRING_INTERFACE->from_char_array =
			&cm_string_create_from_char_array;
	DEFAULT_CM_STRING_INTERFACE->from_integer = &cm_string_create_from_integer;
	DEFAULT_CM_STRING_INTERFACE->from_real = &cm_string_create_from_real;
	DEFAULT_CM_STRING_INTERFACE->from_string =
			&cm_string_create_from_string;
	DEFAULT_CM_STRING_INTERFACE->starts_with = &cm_string_starts_with;
	DEFAULT_CM_STRING_INTERFACE->starts_with_insensitive =
			&cm_string_starts_with_insensitive;
	DEFAULT_CM_STRING_INTERFACE->destroy = &cm_string_destroy;
	DEFAULT_CM_STRING_INTERFACE->to_object = &cm_string_to_cm_object;
}
