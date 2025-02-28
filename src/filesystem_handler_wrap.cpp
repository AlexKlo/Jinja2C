#include "jinja2cpp_wrap.h"

jinja2cpp_memory_file_system_t* jinja2cpp_memory_file_system_create() {
    jinja2cpp_memory_file_system_t* fs = new jinja2cpp_memory_file_system_t();
    fs->ptr = new jinja2::MemoryFileSystem();
    return fs;
}

void jinja2cpp_memory_file_system_destroy(jinja2cpp_memory_file_system_t* fs) {
    if (!fs || !fs->ptr) return;
    delete fs->ptr;
    delete fs;
}

void jinja2cpp_memory_file_system_add_file(jinja2cpp_memory_file_system_t* fs, const char* name, const char* content) {
    if (!fs || !fs->ptr || !name || !content) return;
    fs->ptr->AddFile(name, content);
}