#ifndef CM_STRING_H
#define CM_STRING_H

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "cm_common.h"
#include "cm_helpers.h"
#include "cm_object.h"

struct cm_string_data
{
    char* content;
    cm_size_u length;
};

struct cm_interface_string;

struct cm_string
{
	struct cm_string_data *data;
	struct cm_interface_string* methods;
};

struct cm_interface_string
{
	struct cm_string* (*from_char_array)(char*);
	struct cm_string* (*from_string)(struct cm_string*);
	struct cm_string* (*from_char)(char);
	struct cm_string* (*from_integer)(int64_t, uint8_t);
	struct cm_string* (*from_real)(double);
	struct cm_string* (*to_lower)(struct cm_string*);
	struct cm_string* (*to_upper)(struct cm_string*);
	void (*destroy)(struct cm_string*);
	struct cm_string* (*concat)(struct cm_string*, ...);
	cm_cmp_size_i (*compare)(struct cm_string*, struct cm_string*);
	cm_cmp_size_i (*compare_insensitive)(struct cm_string*, struct cm_string*);
	double (*compare_ordinal)(struct cm_string*, struct cm_string*);
	bool (*are_equal)(struct cm_string*, struct cm_string*);
	bool (*contains)(struct cm_string*, struct cm_string*);
	bool (*contains_insensitive)(struct cm_string*, struct cm_string*);
	bool (*starts_with)(struct cm_string*, struct cm_string*);
	bool (*starts_with_insensitive)(struct cm_string*, struct cm_string*);
	bool (*ends_with)(struct cm_string*, struct cm_string*);
	bool (*ends_with_insensitive)(struct cm_string*, struct cm_string*);
	struct cm_object* (*to_object)(struct cm_string*);
};

void module_cm_string_initialize(void);

#endif // CM_STRING_H
