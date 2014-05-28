#ifndef CM_ERROR_HANDLING_H_
#define CM_ERROR_HANDLING_H_

#include <stdbool.h>

void cm_error_log_warning(const char* function, const char* message);
void cm_error_log_critical(const char* function, const char* message);
void cm_error_log_warning_if(bool condition, const char* function, const char* message);
void cm_error_log_critical_if(bool condition, const char* function, const char* message);

void cm_error_log_warning_vargs(const char* format, ...);
void cm_error_log_critical_vargs(const char* format, ...);
void cm_error_log_warning_vargs_if(bool condition, const char* format, ...);
void cm_error_log_critical_vargs_if(bool condition, const char* format, ...);


#endif /* CM_ERROR_HANDLING_H_ */
