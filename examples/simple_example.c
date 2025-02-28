#include <stdio.h>
#include "jinja2cppwrapper/jinja2cpp_wrap.h"

int main() {
    const char* source =
        "{{ (\"Hello\", 'world') | join }}!!!\n"
        "{{ (\"Hello\", 'world') | join(', ') }}!!!\n"
        "{{ (\"Hello\", 'world') | join(d = '; ') }}!!!\n"
        "{{ (\"Hello\", 'world') | join(d = '; ') | lower }}!!!\n";

    jinja2cpp_template_t* tmpl = jinja2cpp_template_create();
    if (!tmpl) {
        fprintf(stderr, "Failed to create template\n");
        return 1;
    }

    jinja2cpp_result_void_t* result = jinja2cpp_load(tmpl, source, "simple_example");
    if (!jinja2cpp_result_has_value_void(result)) {
        const jinja2cpp_error_info_t* error_info = jinja2cpp_result_error_void(result);
        fprintf(stderr, "%s", jinja2cpp_error_info_to_string(error_info));
        return 1;
    }

    jinja2cpp_values_map_t* tmpl_vars = jinja2cpp_values_map_create();
    if (!tmpl_vars) {
        fprintf(stderr, "Failed to create template variables\n");
        return 1;
    }

    jinja2cpp_result_string_t* result_str = jinja2cpp_render_as_string(tmpl, tmpl_vars);
    if (!jinja2cpp_result_has_value_string(result_str)) {
        const jinja2cpp_error_info_t* error_info = jinja2cpp_result_error_string(result_str);
        fprintf(stderr, "%s", jinja2cpp_error_info_to_string(error_info));
        return 1;
    }

    printf("%s\n", jinja2cpp_result_value_string(result_str));

    jinja2cpp_template_destroy(tmpl);
    jinja2cpp_result_free_void(result);
    jinja2cpp_result_free_string(result_str);
    jinja2cpp_values_map_destroy(tmpl_vars);
    
    return 0;

}