#include "jinja2cpp_wrap.h"

jinja2cpp_values_map_t* jinja2cpp_values_map_create() { 
    return new jinja2cpp_values_map_t{ new jinja2::ValuesMap() }; 
}

void jinja2cpp_values_map_destroy(jinja2cpp_values_map_t* map) {
    if (!map || !map->ptr) return;

    map->ptr->clear();
    delete map->ptr;
    delete map;
}

jinja2cpp_values_list_t* jinja2cpp_values_list_create() { 
    return new jinja2cpp_values_list_t{ new jinja2::ValuesList() }; 
}

void jinja2cpp_values_list_destroy(jinja2cpp_values_list_t* list) {
    if (!list || !list->ptr) return;

    list->ptr->clear(); 
    delete list->ptr;
    delete list;
}

jinja2cpp_value_t* jinja2cpp_value_create_empty() { 
    return new jinja2cpp_value_t{ new jinja2::Value() }; 
}

jinja2cpp_value_t* jinja2cpp_value_create_string(const char* value) { 
    return new jinja2cpp_value_t{ new jinja2::Value(value ? value : "") }; 
}

jinja2cpp_value_t* jinja2cpp_value_create_int(int value) {
    return new jinja2cpp_value_t{ new jinja2::Value(value) }; 
}

jinja2cpp_value_t* jinja2cpp_value_create_double(double value) {
    return new jinja2cpp_value_t{ new jinja2::Value(value) }; 
}

jinja2cpp_value_t* jinja2cpp_value_create_list(jinja2cpp_values_list_t* list) { 
    if (!list || !list->ptr) return nullptr;

    auto* value = new jinja2::Value(std::move(*list->ptr));
    jinja2cpp_values_list_destroy(list);
    return new jinja2cpp_value_t{ value };
}

jinja2cpp_value_t* jinja2cpp_value_create_map(jinja2cpp_values_map_t* map) { 
    if (!map || !map->ptr) return nullptr;

    auto* value = new jinja2::Value(std::move(*map->ptr));
    jinja2cpp_values_map_destroy(map);
    return new jinja2cpp_value_t{ value };
}

void jinja2cpp_value_destroy(jinja2cpp_value_t* value) { 
    if (!value || !value->ptr) return;

    delete value->ptr;
    delete value;
}

bool jinja2cpp_value_is_string(const jinja2cpp_value_t* value) {
    if (!value || !value->ptr) return false;

    return static_cast<const jinja2cpp_value_t*>(value)->ptr->isString();
}

bool jinja2cpp_value_is_list(const jinja2cpp_value_t* value) {
    if (!value || !value->ptr) return false;

    return static_cast<const jinja2cpp_value_t*>(value)->ptr->isList();
}

bool jinja2cpp_value_is_map(const jinja2cpp_value_t* value) {
    if (!value || !value->ptr) return false;

    return static_cast<const jinja2cpp_value_t*>(value)->ptr->isMap();
}

bool jinja2cpp_value_is_empty(const jinja2cpp_value_t* value) {
    if (!value || !value->ptr) return false;

    return static_cast<const jinja2cpp_value_t*>(value)->ptr->isEmpty();
}

const char* jinja2cpp_value_as_string(const jinja2cpp_value_t* value) {
    if (!value || !value->ptr || !value->ptr->isString()) return nullptr;

    return value->ptr->asString().c_str();
}

jinja2cpp_values_list_t* jinja2cpp_value_as_list(jinja2cpp_value_t* value) {
    if (!value || !value->ptr) return nullptr;

    return new jinja2cpp_values_list_t{ new std::vector<jinja2::Value>(value->ptr->asList()) };
}

jinja2cpp_values_map_t* jinja2cpp_value_as_map(jinja2cpp_value_t* value) {
    if (!value || !value->ptr) return nullptr;

    return new jinja2cpp_values_map_t{ new jinja2::ValuesMap(value->ptr->asMap()) };
}

void jinja2cpp_values_map_set(jinja2cpp_values_map_t* map, const char* key, jinja2cpp_value_t* value) {
    if (!map || !map->ptr || !key || !value || !value->ptr) return;
    (*map->ptr)[key] = std::move(*value->ptr);
    jinja2cpp_value_destroy(value);
}

jinja2cpp_value_t* jinja2cpp_values_map_get(const jinja2cpp_values_map_t* map, const char* key) {
    if (!map || !map->ptr || !key) return nullptr;
    
    auto it = map->ptr->find(key);
    if (it == map->ptr->end()) return nullptr;

    return new jinja2cpp_value_t{ new jinja2::Value(it->second) };
}

size_t jinja2cpp_values_map_size(const jinja2cpp_values_map_t* map) {
    return (map && map->ptr) ? map->ptr->size() : 0;
}

void jinja2cpp_values_list_push(jinja2cpp_values_list_t* list, jinja2cpp_value_t* value) {
    if (!list || !list->ptr || !value || !value->ptr) return;

    list->ptr->push_back(std::move(*value->ptr));
    jinja2cpp_value_destroy(value);
}

jinja2cpp_value_t* jinja2cpp_values_list_get(const jinja2cpp_values_list_t* list, size_t index) {
    if (!list || !list->ptr || index >= list->ptr->size()) return nullptr;
    
    return new jinja2cpp_value_t{ new jinja2::Value((*list->ptr)[index]) };
}

size_t jinja2cpp_values_list_size(const jinja2cpp_values_list_t* list) {
    return (list && list->ptr) ? list->ptr->size() : 0;
}