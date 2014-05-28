#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "cm_error_log.h"

void cm_error_log_warning_vargs(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	vfprintf(stderr, format, argptr);
	va_end(argptr);
	fprintf(stderr,"\n");
}

void cm_error_log_critical_vargs(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	vfprintf(stderr, format, argptr);
	va_end(argptr);
	fprintf(stderr,"\n");
	exit(0);
}

void cm_error_log_warning_vargs_if(bool condition, const char* format, ...)
{
	if(condition == true)
	{
		va_list argptr;
		va_start(argptr, format);
		vfprintf(stderr, format, argptr);
		va_end(argptr);
		fprintf(stderr,"\n");
	}
}

void cm_error_log_critical_vargs_if(bool condition, const char* format, ...)
{
	if(condition == true)
	{
		va_list argptr;
		va_start(argptr, format);
		vfprintf(stderr, format, argptr);
		va_end(argptr);
		fprintf(stderr,"\n");
		exit(0);
	}
}

void cm_error_log_warning(const char* function, const char* message)
{
	fprintf(stderr, "%s %s", function, message);
}

void cm_error_log_critical(const char* function, const char* message)
{
	cm_error_log_warning(function, message);
	exit(0);
}

void cm_error_log_warning_if(bool condition, const char* function, const char* message)
{
	if( condition == true)
	{
		cm_error_log_warning(function, message);
	}
}

void cm_error_log_critical_if(bool condition, const char* function, const char* message)
{
	if( condition == true)
	{
		cm_error_log_critical(function, message);
	}
}
