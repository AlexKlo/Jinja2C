#include "jinja2cpp_wrap.h"

jinja2cpp_template_t* jinja2cpp_template_create() {
    return new jinja2cpp_template_t{ new jinja2::Template() };
}

jinja2cpp_template_t* jinja2cpp_template_create_template_env(jinja2cpp_template_env_t* tmpl_env) {
    return new jinja2cpp_template_t{ new jinja2::Template(tmpl_env->ptr)};
}

void jinja2cpp_template_destroy(jinja2cpp_template_t* tmpl) {
    if (!tmpl || !tmpl->ptr) return;
    delete tmpl->ptr;
    delete tmpl;
}

jinja2cpp_result_void_t* jinja2cpp_load(jinja2cpp_template_t* tmpl, const char* src, const char* tpl_name) {
    if (!tmpl || !tmpl->ptr || !src) {
        return new jinja2cpp_result_void_t{
            new nonstd::expected<void, jinja2cpp_error_info_t>(
                nonstd::unexpected<jinja2cpp_error_info_t>(jinja2cpp_error_info_t{nullptr})
            )
        };
    }

    auto result = tmpl->ptr->Load(src, tpl_name ? std::string(tpl_name) : std::string());
    if (!result.has_value()) {
        jinja2cpp_error_info_t error_info{ new jinja2::ErrorInfoTpl<char>(result.error()) };

        return new jinja2cpp_result_void_t{
            new nonstd::expected<void, jinja2cpp_error_info_t>(
                nonstd::unexpected<jinja2cpp_error_info_t>(std::move(error_info))
            )
        };
    }

    return new jinja2cpp_result_void_t{ new nonstd::expected<void, jinja2cpp_error_info_t>() };
}

jinja2cpp_result_string_t* jinja2cpp_render_as_string(jinja2cpp_template_t* tmpl, const jinja2cpp_values_map_t* tmpl_vars) {
    if (!tmpl || !tmpl->ptr || !tmpl_vars) {
        return new jinja2cpp_result_string_t{
            new nonstd::expected<const char*, jinja2cpp_error_info_t>(
                nonstd::unexpected<jinja2cpp_error_info_t>(jinja2cpp_error_info_t{nullptr})
            )
        };
    }

    auto result = tmpl->ptr->RenderAsString(*tmpl_vars->ptr);

    if (!result.has_value()) {
        jinja2cpp_error_info_t error_info{ new jinja2::ErrorInfoTpl<char>(result.error()) };

        return new jinja2cpp_result_string_t{
            new nonstd::expected<const char*, jinja2cpp_error_info_t>(
                nonstd::unexpected<jinja2cpp_error_info_t>(std::move(error_info))
            )
        };
    }

    char* result_cstr = strdup(result->c_str());
    return new jinja2cpp_result_string_t{
        new nonstd::expected<const char*, jinja2cpp_error_info_t>(result_cstr)
    };
}