#ifndef RESULT_WRAP_H
#define RESULT_WRAP_H

#ifdef __cplusplus

extern "C" {
#endif

void jinja2cpp_result_free_void(jinja2cpp_result_void_t* result);
void jinja2cpp_result_free_string(jinja2cpp_result_string_t* result);
void jinja2cpp_result_free_template(jinja2cpp_result_template_t* result);

bool jinja2cpp_result_has_value_void(const jinja2cpp_result_void_t* result);
bool jinja2cpp_result_has_value_string(const jinja2cpp_result_string_t* result);
bool jinja2cpp_result_has_value_template(const jinja2cpp_result_template_t* result);

void jinja2cpp_result_value_void(const jinja2cpp_result_void_t* result);
const char* jinja2cpp_result_value_string(const jinja2cpp_result_string_t* result);
jinja2cpp_template_t* jinja2cpp_result_value_template(const jinja2cpp_result_template_t* result);

const jinja2cpp_error_info_t* jinja2cpp_result_error_void(const jinja2cpp_result_void_t* result);
const jinja2cpp_error_info_t* jinja2cpp_result_error_string(const jinja2cpp_result_string_t* result);
const jinja2cpp_error_info_t* jinja2cpp_result_error_template(const jinja2cpp_result_template_t* result);

#ifdef __cplusplus
}
#endif

#endif // RESULT_WRAP_H