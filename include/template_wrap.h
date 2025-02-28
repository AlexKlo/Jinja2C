#ifndef TEMPLATE_C_H
#define TEMPLATE_C_H

#ifdef __cplusplus

extern "C" {
#endif

jinja2cpp_template_t* jinja2cpp_template_create();
jinja2cpp_template_t* jinja2cpp_template_create_template_env(jinja2cpp_template_env_t* tmpl_env);
void jinja2cpp_template_destroy(jinja2cpp_template_t* tmpl);

jinja2cpp_result_void_t* jinja2cpp_load(jinja2cpp_template_t* tmpl, const char* src, const char* tpl_name);
jinja2cpp_result_string_t* jinja2cpp_render_as_string(jinja2cpp_template_t* tmpl, const jinja2cpp_values_map_t* tmpl_vars);

#ifdef __cplusplus
}
#endif

#endif // TEMPLATE_C_H