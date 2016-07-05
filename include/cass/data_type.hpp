/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class data_type> data_type_ptr;
typedef wrapper_const_ptr<class data_type const> data_type_const_ptr;

class data_type {
public:
    data_type(::CassDataType *p) : p(p) {}
    data_type(::CassDataType const *pc) : pc(pc) {}
    ::CassDataType * backend() { return p; }
    ::CassDataType const * backend() const { return pc; }

    inline static void free(data_type const);
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

    inline data_type_const_ptr sub_data_type(size_t index) const;
    inline data_type_const_ptr sub_data_type_by_name(char const *name) const;
    inline data_type_const_ptr sub_data_type_by_name_n(char const *name,
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

private:
    friend class aggregate_meta;
    friend class collection;
    friend class column_meta;
    friend class function_meta;
    friend class keyspace_meta;
    friend class prepared;
    friend class result;
    friend class tuple;
    friend class user_type;
    template<typename T>
    friend class wrapper_ptr;
    template<typename T>
    friend class wrapper_const_ptr;
    template<typename T, void (*)(T)>
    friend class shared_res;

    data_type(const data_type &) = default;
    data_type(data_type &&) = default;
    void operator = (const data_type &) = delete;
    void operator = (data_type &&) = delete;
    void set_backend(::CassDataType const *pc_new) const { pc = pc_new; }

    union {
        ::CassDataType *p;
        mutable ::CassDataType const *pc;
    };
};


inline void data_type::free(data_type const d)
{
    ::cass_data_type_free(d.p);
}

inline data_type_ptr data_type::new_ptr(value_type type)
{
    return data_type_ptr(data_type(::cass_data_type_new(type)), true);
}

inline data_type_ptr data_type::new_from_existing() const
{
    return data_type_ptr(data_type(::cass_data_type_new_from_existing(pc)),
            true);
}

inline data_type_ptr data_type::new_tuple(size_t item_count)
{
    return data_type_ptr(data_type(::cass_data_type_new_tuple(item_count)),
            true);
}

inline data_type_ptr data_type::new_udt(size_t field_count)
{
    return data_type_ptr(data_type(::cass_data_type_new_udt(field_count)),
            true);
}

inline value_type data_type::type() const
{
    return ::cass_data_type_type(pc);
}

inline bool data_type::is_frozen() const
{
    return ::cass_data_type_is_frozen(pc) == cass_true;
}

inline error data_type::type_name(char const **type_name,
        size_t *type_name_length) const
{
    return ::cass_data_type_type_name(pc, type_name, type_name_length);
}

inline error data_type::set_type_name(char const *type_name)
{
    return ::cass_data_type_set_type_name(p, type_name);
}

inline error data_type::data_type::set_type_name_n(char const *type_name,
        size_t type_name_length)
{
    return ::cass_data_type_set_type_name_n(p, type_name, type_name_length);
}

inline error data_type::keyspace(char const **keyspace,
        size_t *keyspace_length) const
{
    return ::cass_data_type_keyspace(pc, keyspace, keyspace_length);
}

inline error data_type::set_keyspace(char const *keyspace)
{
    return ::cass_data_type_set_keyspace(p, keyspace);
}

inline error data_type::set_keyspace_n(char const *keyspace,
        size_t keyspace_length)
{
    return ::cass_data_type_set_keyspace_n(p, keyspace, keyspace_length);
}

inline error data_type::class_name(char const **class_name,
        size_t *class_name_length) const
{
    return ::cass_data_type_class_name(pc, class_name, class_name_length);
}

inline error data_type::set_class_name(char const *class_name)
{
    return ::cass_data_type_set_class_name(p, class_name);
}

inline error data_type::set_class_name_n(char const *class_name,
        size_t class_name_length)
{
    return ::cass_data_type_set_class_name_n(p, class_name, class_name_length);
}

inline size_t data_type::sub_type_count() const
{
    return ::cass_data_type_sub_type_count(pc);
}

inline data_type_const_ptr data_type::sub_data_type(size_t index) const
{
    return data_type_const_ptr(data_type(::cass_data_type_sub_data_type(
                    pc, index)), false);
}

inline data_type_const_ptr data_type::sub_data_type_by_name(
        char const *name) const
{
    return data_type_const_ptr(data_type(::cass_data_type_sub_data_type_by_name(
                    pc, name)), false);
}

inline data_type_const_ptr data_type::sub_data_type_by_name_n(char const *name,
        size_t name_length) const
{
    return data_type_const_ptr(data_type(
                ::cass_data_type_sub_data_type_by_name_n(
                    pc, name,name_length)), false);
}

inline error data_type::sub_type_name(size_t index, char const **name,
        size_t *name_length) const
{
    return ::cass_data_type_sub_type_name(pc, index, name, name_length);
}

inline error data_type::add_sub_type(data_type const *sub_data_type)
{
    return ::cass_data_type_add_sub_type(p, sub_data_type->backend());
}

inline error data_type::add_sub_type_by_name(char const *name,
        data_type const *sub_data_type)
{
    return ::cass_data_type_add_sub_type_by_name(p, name,
            sub_data_type->backend());
}

inline error data_type::add_sub_type_by_name_n(char const *name,
        size_t name_length, data_type const *sub_data_type)
{
    return ::cass_data_type_add_sub_type_by_name_n(p, name, name_length,
            sub_data_type->backend());
}

inline error data_type::add_sub_value_type(value_type sub_value_type)
{
    return ::cass_data_type_add_sub_value_type(p, sub_value_type);
}

inline error data_type::add_sub_value_type_by_name(char const *name,
        value_type sub_value_type)
{
    return ::cass_data_type_add_sub_value_type_by_name(p, name, sub_value_type);
}

inline error data_type::add_sub_value_type_by_name_n(char const *name,
        size_t name_length, value_type sub_value_type)
{
    return ::cass_data_type_add_sub_value_type_by_name_n(p, name, name_length,
            sub_value_type);
}

} // namespace cass
