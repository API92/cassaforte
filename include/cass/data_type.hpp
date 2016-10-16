/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<data_type> data_type_ptr;

class data_type : wrapper {
public:
    static data_type * ptr(::CassDataType *p)
    {
        return reinterpret_cast<data_type *>(p);
    }

    static data_type const * ptr(::CassDataType const *p)
    {
        return reinterpret_cast<data_type const *>(p);
    }

    ::CassDataType * backend()
    {
        return reinterpret_cast<::CassDataType *>(this);
    }

    ::CassDataType const * backend() const
    {
        return reinterpret_cast<::CassDataType const *>(this);
    }

    inline void free();
    inline static data_type_ptr new_ptr(value_type type);

    inline data_type_ptr new_from_existing() const;

    inline static data_type_ptr new_tuple(size_t item_count);

    inline static data_type_ptr new_udt(size_t field_count);

    inline value_type type() const;

    inline bool is_frozen() const;

    inline error type_name(char const **type_name,
            size_t *type_name_length) const;

    inline error set_type_name(char const *type_name);
    inline error set_type_name_n(char const *type_name,
            size_t type_name_length);

    inline error keyspace(char const **keyspace, size_t *keyspace_length) const;

    inline error set_keyspace(char const *keyspace);
    inline error set_keyspace_n(char const *keyspace, size_t keyspace_length);

    inline error class_name(char const **class_name,
            size_t *class_name_length) const;

    inline error set_class_name(char const *class_name);
    inline error set_class_name_n(char const *class_name,
            size_t class_name_length);

    inline size_t sub_type_count() const;

    inline data_type const * sub_data_type(size_t index) const;
    inline data_type const * sub_data_type_by_name(char const *name) const;
    inline data_type const * sub_data_type_by_name_n(char const *name,
            size_t name_length) const;

    inline error sub_type_name(size_t index, char const **name,
            size_t *name_length) const;

    inline error add_sub_type(data_type const *sub_data_type);
    inline error add_sub_type_by_name(char const *name,
            data_type const *sub_data_type);
    inline error add_sub_type_by_name_n(char const *name, size_t name_length,
            data_type const *sub_data_type);

    inline error add_sub_value_type(value_type sub_value_type);
    inline error add_sub_value_type_by_name(char const *name,
            value_type sub_value_type);
    inline error add_sub_value_type_by_name_n(char const *name,
            size_t name_length, value_type sub_value_type);
};


inline void data_type::free()
{
    ::cass_data_type_free(backend());
}

inline data_type_ptr data_type::new_ptr(value_type type)
{
    return data_type_ptr(data_type::ptr(::cass_data_type_new(type)), true);
}

inline data_type_ptr data_type::new_from_existing() const
{
    return data_type_ptr(data_type::ptr(::cass_data_type_new_from_existing(
                    backend())), true);
}

inline data_type_ptr data_type::new_tuple(size_t item_count)
{
    return data_type_ptr(data_type::ptr(::cass_data_type_new_tuple(item_count)),
            true);
}

inline data_type_ptr data_type::new_udt(size_t field_count)
{
    return data_type_ptr(data_type::ptr(::cass_data_type_new_udt(field_count)),
            true);
}

inline value_type data_type::type() const
{
    return ::cass_data_type_type(backend());
}

inline bool data_type::is_frozen() const
{
    return ::cass_data_type_is_frozen(backend()) == cass_true;
}

inline error data_type::type_name(char const **type_name,
        size_t *type_name_length) const
{
    return error(::cass_data_type_type_name(
                backend(), type_name, type_name_length));
}

inline error data_type::set_type_name(char const *type_name)
{
    return error(::cass_data_type_set_type_name(backend(), type_name));
}

inline error data_type::data_type::set_type_name_n(char const *type_name,
        size_t type_name_length)
{
    return error(::cass_data_type_set_type_name_n(
                backend(), type_name, type_name_length));
}

inline error data_type::keyspace(char const **keyspace,
        size_t *keyspace_length) const
{
    return error(::cass_data_type_keyspace(
                backend(), keyspace, keyspace_length));
}

inline error data_type::set_keyspace(char const *keyspace)
{
    return error(::cass_data_type_set_keyspace(backend(), keyspace));
}

inline error data_type::set_keyspace_n(char const *keyspace,
        size_t keyspace_length)
{
    return error(::cass_data_type_set_keyspace_n(
                backend(), keyspace, keyspace_length));
}

inline error data_type::class_name(char const **class_name,
        size_t *class_name_length) const
{
    return error(::cass_data_type_class_name(
                backend(), class_name, class_name_length));
}

inline error data_type::set_class_name(char const *class_name)
{
    return error(::cass_data_type_set_class_name(backend(), class_name));
}

inline error data_type::set_class_name_n(char const *class_name,
        size_t class_name_length)
{
    return error(::cass_data_type_set_class_name_n(
                backend(), class_name, class_name_length));
}

inline size_t data_type::sub_type_count() const
{
    return ::cass_data_type_sub_type_count(backend());
}

inline data_type const * data_type::sub_data_type(size_t index) const
{
    return data_type::ptr(::cass_data_type_sub_data_type(backend(), index));
}

inline data_type const * data_type::sub_data_type_by_name(
        char const *name) const
{
    return data_type::ptr(
            ::cass_data_type_sub_data_type_by_name(backend(), name));
}

inline data_type const * data_type::sub_data_type_by_name_n(char const *name,
        size_t name_length) const
{
    return data_type::ptr(::cass_data_type_sub_data_type_by_name_n(
                    backend(), name,name_length));
}

inline error data_type::sub_type_name(size_t index, char const **name,
        size_t *name_length) const
{
    return error(::cass_data_type_sub_type_name(
                backend(), index, name, name_length));
}

inline error data_type::add_sub_type(data_type const *sub_data_type)
{
    return error(::cass_data_type_add_sub_type(
                backend(), sub_data_type->backend()));
}

inline error data_type::add_sub_type_by_name(char const *name,
        data_type const *sub_data_type)
{
    return error(::cass_data_type_add_sub_type_by_name(backend(), name,
            sub_data_type->backend()));
}

inline error data_type::add_sub_type_by_name_n(char const *name,
        size_t name_length, data_type const *sub_data_type)
{
    return error(::cass_data_type_add_sub_type_by_name_n(
                backend(), name, name_length, sub_data_type->backend()));
}

inline error data_type::add_sub_value_type(value_type sub_value_type)
{
    return error(::cass_data_type_add_sub_value_type(
                backend(), sub_value_type));
}

inline error data_type::add_sub_value_type_by_name(char const *name,
        value_type sub_value_type)
{
    return error(::cass_data_type_add_sub_value_type_by_name(
                backend(), name, sub_value_type));
}

inline error data_type::add_sub_value_type_by_name_n(char const *name,
        size_t name_length, value_type sub_value_type)
{
    return error(::cass_data_type_add_sub_value_type_by_name_n(
                backend(), name, name_length, sub_value_type));
}

} // namespace cass
