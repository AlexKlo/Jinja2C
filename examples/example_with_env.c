#include <stdio.h>
#include "jinja2cppwrapper/jinja2cpp_wrap.h"

int main() {
    const char* source = 
        "    <title>Jinja Global Variable Example</title>\n"
        "    <h1>{{ GLOBAL_VAR }}</h1>\n";

    jinja2cpp_template_env_t* tmpl_env = jinja2cpp_template_env_create();
    if (!tmpl_env) {
        fprintf(stderr, "Failed to create template environment\n");
        return 1;
    }

    jinja2cpp_template_env_add_global(tmpl_env, "GLOBAL_VAR", jinja2cpp_value_create_string("Hello, World!"));

    jinja2cpp_memory_file_system_t* fs = jinja2cpp_memory_file_system_create();
    jinja2cpp_template_env_add_filesystem_handler(tmpl_env, "", fs);
    jinja2cpp_memory_file_system_add_file(fs, "main.j2", source);

    jinja2cpp_template_t* tmpl;
    jinja2cpp_result_template_t* result_with_tmpl = jinja2cpp_template_env_load_template(tmpl_env, "main.j2");
    if (!jinja2cpp_result_has_value_template(result_with_tmpl)) {
        const jinja2cpp_error_info_t* error_info = jinja2cpp_result_error_template(result_with_tmpl);
        fprintf(stderr, "%s", jinja2cpp_error_info_to_string(error_info));
        return 1;
    }
    else {
        tmpl = jinja2cpp_result_value_template(result_with_tmpl);
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
    jinja2cpp_result_free_template(result_with_tmpl);
    jinja2cpp_result_free_string(result_str);
    jinja2cpp_values_map_destroy(tmpl_vars);
    jinja2cpp_memory_file_system_destroy(fs);
    
    return 0;

}