/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassDataType_ CassDataType;

namespace cass {

class CASSA_IMPEXP data_type : delete_defaults {
public:
    static data_type * ptr(::CassDataType *p);

    static data_type const * ptr(::CassDataType const *p);

    ::CassDataType * backend();
    ::CassDataType const * backend() const;

    void free();
    static data_type_ptr new_ptr(value_type type);

    data_type_ptr new_from_existing() const;

    static data_type_ptr new_tuple(size_t item_count);

    static data_type_ptr new_udt(size_t field_count);

    value_type type() const;

    bool is_frozen() const;

    error type_name(char const **type_name,
            size_t *type_name_length) const;

    error set_type_name(char const *type_name);
    error set_type_name_n(char const *type_name,
            size_t type_name_length);

    error keyspace(char const **keyspace, size_t *keyspace_length) const;

    error set_keyspace(char const *keyspace);
    error set_keyspace_n(char const *keyspace, size_t keyspace_length);

    error class_name(char const **class_name,
            size_t *class_name_length) const;

    error set_class_name(char const *class_name);
    error set_class_name_n(char const *class_name,
            size_t class_name_length);

    size_t sub_type_count() const;

    data_type const * sub_data_type(size_t index) const;
    data_type const * sub_data_type_by_name(char const *name) const;
    data_type const * sub_data_type_by_name_n(char const *name,
            size_t name_length) const;

    error sub_type_name(size_t index, char const **name,
            size_t *name_length) const;

    error add_sub_type(data_type const *sub_data_type);
    error add_sub_type_by_name(char const *name,
            data_type const *sub_data_type);
    error add_sub_type_by_name_n(char const *name, size_t name_length,
            data_type const *sub_data_type);

    error add_sub_value_type(value_type sub_value_type);
    error add_sub_value_type_by_name(char const *name,
            value_type sub_value_type);
    error add_sub_value_type_by_name_n(char const *name,
            size_t name_length, value_type sub_value_type);
};

} // namespace cass
