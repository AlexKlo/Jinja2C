#include "jinja2cpp_wrap.h"

jinja2cpp_template_env_t* jinja2cpp_template_env_create() {
    return new jinja2cpp_template_env_t{ new jinja2::TemplateEnv() };
}

void jinja2cpp_template_env_destroy(jinja2cpp_template_env_t* tmpl_env) {
    if (!tmpl_env || !tmpl_env->ptr) return;
    delete tmpl_env->ptr;
    delete tmpl_env;
}

void jinja2cpp_template_env_add_filesystem_handler(jinja2cpp_template_env_t* tmpl_env, const char* prefix, jinja2cpp_memory_file_system_t* file_system) {
    if (!tmpl_env || !tmpl_env->ptr || !prefix || !file_system || !file_system->ptr) return;
    tmpl_env->ptr->AddFilesystemHandler(std::string(prefix), *file_system->ptr);
}

jinja2cpp_result_template_t* jinja2cpp_template_env_load_template(jinja2cpp_template_env_t* tmpl_env, const char* file_name) {
    if (!tmpl_env || !tmpl_env->ptr || !file_name) {
        return new jinja2cpp_result_template_t{
            new nonstd::expected<jinja2::Template, jinja2cpp_error_info_t>(
                nonstd::unexpected<jinja2cpp_error_info_t>(jinja2cpp_error_info_t{nullptr})
            )
        };
    }

    auto templateResult = tmpl_env->ptr->LoadTemplate(file_name);
    if (!templateResult.has_value()) {
        auto* error_info = new jinja2::ErrorInfoTpl<char>(templateResult.error());
        return new jinja2cpp_result_template_t{
            new nonstd::expected<jinja2::Template, jinja2cpp_error_info_t>(
                nonstd::unexpected<jinja2cpp_error_info_t>(jinja2cpp_error_info_t{error_info})
            )
        };
    }

    return new jinja2cpp_result_template_t{
        new nonstd::expected<jinja2::Template, jinja2cpp_error_info_t>(
            std::move(templateResult.value())
        )
    };
}

void jinja2cpp_template_env_add_global(jinja2cpp_template_env_t* tmpl_env, const char* name, jinja2cpp_value_t* value) {
    if (!tmpl_env || !tmpl_env->ptr || !name || !value || !value->ptr) return;
    tmpl_env->ptr->AddGlobal(name, *value->ptr);
}

void jinja2cpp_template_env_remove_global(jinja2cpp_template_env_t* tmpl_env, const char* name) {
    if (!tmpl_env || !tmpl_env->ptr || !name) return;
    tmpl_env->ptr->RemoveGlobal(name);
}