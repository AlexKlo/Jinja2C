#include "jinja2cpp_wrap.h"

void jinja2cpp_result_free_void(jinja2cpp_result_void_t* result) {
    if (!result || !result->ptr) return;
    delete result->ptr;
    delete result;
}

void jinja2cpp_result_free_string(jinja2cpp_result_string_t* result) {
    if (!result || !result->ptr) return;
    if (result->ptr->has_value()) {
        free(const_cast<char*>(result->ptr->value()));
    }
    delete result->ptr;
    delete result;
}

void jinja2cpp_result_free_template(jinja2cpp_result_template_t* result) {
    if (!result || !result->ptr) return;
    delete result;
}

bool jinja2cpp_result_has_value_void(const jinja2cpp_result_void_t* result) {
    return result && result->ptr && result->ptr->has_value();
}

bool jinja2cpp_result_has_value_string(const jinja2cpp_result_string_t* result) {
    return result && result->ptr && result->ptr->has_value();
}

bool jinja2cpp_result_has_value_template(const jinja2cpp_result_template_t* result) {
    return result && result->ptr && result->ptr->has_value();
}

void jinja2cpp_result_value_void(const jinja2cpp_result_void_t* result) {
    if (!result || !result->ptr || !result->ptr->has_value()) return;
}

const char* jinja2cpp_result_value_string(const jinja2cpp_result_string_t* result) {
    return (result && result->ptr && result->ptr->has_value()) ? result->ptr->value() : nullptr;
}

jinja2cpp_template_t* jinja2cpp_result_value_template(const jinja2cpp_result_template_t* result) {
    if (!result || !result->ptr || !result->ptr->has_value()) return nullptr;
    jinja2cpp_template_t* wrapper = new jinja2cpp_template_t;
    wrapper->ptr = &(result->ptr->value());
    return wrapper;
}

const jinja2cpp_error_info_t* jinja2cpp_result_error_void(const jinja2cpp_result_void_t* result) {
    if (!result || !result->ptr || result->ptr->has_value()) return nullptr;
    return new jinja2cpp_error_info_t(result->ptr->error());
}

const jinja2cpp_error_info_t* jinja2cpp_result_error_string(const jinja2cpp_result_string_t* result) {
    if (!result || !result->ptr || result->ptr->has_value()) return nullptr;
    return new jinja2cpp_error_info_t(result->ptr->error());
}

const jinja2cpp_error_info_t* jinja2cpp_result_error_template(const jinja2cpp_result_template_t* result) {
    if (!result || !result->ptr || result->ptr->has_value()) return nullptr;
    return new jinja2cpp_error_info_t(result->ptr->error());
}