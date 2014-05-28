#include <string.h>

#include "cm_generic_tests.h"
#include "cmantras/base/helpers/cm_generic.h"

#include "../../cm_test_base.h"

void cm_swap_content__swap_char_arrays__are_swapped(void)
{
	char* value_1 = malloc(5 * sizeof(char));
	char* value_2 = malloc(5 * sizeof(char));
	bool condition = false;

	strcpy(value_1,"val1");
	strcpy(value_2,"val2");
	cm_swap_content(value_1, value_2, 5);
	condition = (strcmp(value_2, "val1") == 0);

	assert_is_true(condition, __func__);

	free(value_1);
	free(value_2);
}

void cm_generic_run_tests(void)
{
	cm_swap_content__swap_char_arrays__are_swapped();
}
