#ifndef FILESYSTEM_HANDLER_WRAP_H
#define FILESYSTEM_HANDLER_WRAP_H

#ifdef __cplusplus

extern "C" {
#endif

jinja2cpp_memory_file_system_t* jinja2cpp_memory_file_system_create();
void jinja2cpp_memory_file_system_destroy(jinja2cpp_memory_file_system_t* fs);
void jinja2cpp_memory_file_system_add_file(jinja2cpp_memory_file_system_t* fs, const char* name, const char* content);

#ifdef __cplusplus
}
#endif

#endif // FILESYSTEM_HANDLER_WRAP_H