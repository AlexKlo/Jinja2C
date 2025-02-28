#ifndef JINJA2CPP_WRAP_H
#define JINJA2CPP_WRAP_H

#include "jinja2cpp/template.h"
#include <jinja2cpp/filesystem_handler.h>
#include <jinja2cpp/template_env.h>
#include <stdbool.h>
#include <stddef.h>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct jinja2cpp_error_info_t {
    jinja2::ErrorInfo* ptr;
} jinja2cpp_error_info_t;

typedef struct jinja2cpp_memory_file_system_t {
    jinja2::MemoryFileSystem* ptr;
} jinja2cpp_memory_file_system_t;

typedef struct jinja2cpp_result_void_t {
    nonstd::expected<void, jinja2cpp_error_info_t>* ptr;
} jinja2cpp_result_void_t;

typedef struct jinja2cpp_result_string_t {
    nonstd::expected<const char*, jinja2cpp_error_info_t>* ptr;
} jinja2cpp_result_string_t;

typedef struct jinja2cpp_result_template_t {
    nonstd::expected<jinja2::Template, jinja2cpp_error_info_t>* ptr;
} jinja2cpp_result_template_t;

typedef struct jinja2cpp_value_t {
    jinja2::Value* ptr;
} jinja2cpp_value_t;

typedef struct jinja2cpp_values_list_t {
    jinja2::ValuesList* ptr;
} jinja2cpp_values_list_t;

typedef struct jinja2cpp_values_map_t {
    jinja2::ValuesMap* ptr;
} jinja2cpp_values_map_t;

typedef struct jinja2cpp_template_env_t {
    jinja2::TemplateEnv* ptr;
} jinja2cpp_template_env_t;

typedef struct jinja2cpp_template_t {
    jinja2::Template* ptr;
} jinja2cpp_template_t;

#include "error_info_wrap.h"
#include "filesystem_handler_wrap.h"
#include "result_wrap.h"
#include "value_wrap.h"
#include "template_env_wrap.h"
#include "template_wrap.h"

#ifdef __cplusplus
}
#endif

#endif // JINJA2CPP_WRAP_H