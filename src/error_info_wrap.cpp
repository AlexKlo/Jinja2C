#include "jinja2cpp_wrap.h"

jinja2cpp_error_code_t jinja2cpp_error_info_get_code(const jinja2cpp_error_info_t* error_info) {
    if (!error_info || !error_info->ptr) {
        return JINJA2CPP_ERROR_UNSPECIFIED;
    }
    return static_cast<jinja2cpp_error_code_t>(error_info->ptr->GetCode());
}

const char* jinja2cpp_error_info_to_string(const jinja2cpp_error_info_t* error_info) {
    if (!error_info || !error_info->ptr) {
        return "Unknown error";
    }
    thread_local std::string error_message = error_info->ptr->ToString();
    return error_message.c_str();
}