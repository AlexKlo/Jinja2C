#ifndef TEMPLATE_ENV_WRAP_H
#define TEMPLATE_ENV_WRAP_H 

#ifdef __cplusplus

extern "C" {
#endif

jinja2cpp_template_env_t* jinja2cpp_template_env_create();

void jinja2cpp_template_env_destroy(jinja2cpp_template_env_t* tmpl_env);

void jinja2cpp_template_env_add_filesystem_handler(jinja2cpp_template_env_t* tmpl_env, const char* prefix, jinja2cpp_memory_file_system_t* file_system);

jinja2cpp_result_template_t* jinja2cpp_template_env_load_template(jinja2cpp_template_env_t* tmpl_env, const char* file_name);

void jinja2cpp_template_env_add_global(jinja2cpp_template_env_t* tmpl_env, const char* name, jinja2cpp_value_t* value);

void jinja2cpp_template_env_remove_global(jinja2cpp_template_env_t* tmpl_env, const char* name);

#ifdef __cplusplus
}
#endif

#endif // TEMPLATE_ENV_WRAP_H