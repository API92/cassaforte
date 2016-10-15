/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/impexp.hpp>
#include <cass/inet.hpp>
#include <cass/uuid.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class tuple> tuple_ptr;

class tuple {
public:
    explicit tuple(::CassTuple *p) : p(p) {}
    ::CassTuple * backend() { return p; }
    ::CassTuple const * backend() const { return p; }

    inline static void free(tuple const t);
    inline static tuple_ptr new_ptr(size_t item_count);

    CASSA_IMPEXP static tuple_ptr new_from_data_type(
            cass::data_type const *data_type);

    CASSA_IMPEXP data_type_const_ptr data_type() const;

    template<typename T>
    error set(size_t index, T value);

    inline error set_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);

private:
    ::CassTuple *p;
};

inline void tuple::free(tuple const t)
{
    ::cass_tuple_free(t.p);
}

inline tuple_ptr tuple::new_ptr(size_t item_count)
{
    return tuple_ptr(tuple(::cass_tuple_new(item_count)), true);
}

template<>
inline error tuple::set(size_t index, nullptr_t)
{
    return error(::cass_tuple_set_null(p, index));
}

template<>
inline error tuple::set(size_t index, int8_t value)
{
    return error(::cass_tuple_set_int8(p, index, value));
}

template<>
inline error tuple::set(size_t index, int16_t value)
{
    return error(::cass_tuple_set_int16(p, index, value));
}

template<>
inline error tuple::set(size_t index, int32_t value)
{
    return error(::cass_tuple_set_int32(p, index, value));
}

template<>
inline error tuple::set(size_t index, uint32_t value)
{
    return error(::cass_tuple_set_uint32(p, index, value));
}

template<>
inline error tuple::set(size_t index, int64_t value)
{
    return error(::cass_tuple_set_int64(p, index, value));
}

template<>
inline error tuple::set(size_t index, float value)
{
    return error(::cass_tuple_set_float(p, index, value));
}

template<>
inline error tuple::set(size_t index, double value)
{
    return error(::cass_tuple_set_double(p, index, value));
}

template<>
inline error tuple::set(size_t index, bool value)
{
    return error(::cass_tuple_set_bool(
                p, index, value ? cass_true : cass_false));
}

template<>
inline error tuple::set(size_t index, char const *value)
{
    return error(::cass_tuple_set_string(p, index, value));
}

template<>
inline error tuple::set(size_t index, std::experimental::string_view value)
{
    return error(::cass_tuple_set_string_n(
                p, index, value.data(), value.size()));
}

template<>
inline error tuple::set(size_t index, bytes_view value)
{
    return error(::cass_tuple_set_bytes(p, index, value.data(), value.size()));
}

inline error tuple::set_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return error(::cass_tuple_set_custom(
                p, index, class_name, value, value_size));
}

template<>
inline error tuple::set(size_t index, custom c)
{
    return error(::cass_tuple_set_custom_n(
                p, index, c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

template<>
inline error tuple::set(size_t index, uuid value)
{
    return error(::cass_tuple_set_uuid(p, index, value));
}

template<>
inline error tuple::set(size_t index, inet value)
{
    return error(::cass_tuple_set_inet(p, index, value));
}

template<>
inline error tuple::set(size_t index, decimal d)
{
    return error(::cass_tuple_set_decimal(
                p, index, d.varint, d.varint_size, d.scale));
}

template<>
inline error tuple::set(size_t index, tuple const *value)
{
    return error(::cass_tuple_set_tuple(p, index, value->backend()));
}

template<>
CASSA_IMPEXP error tuple::set(size_t index, collection const *value);

template<>
CASSA_IMPEXP error tuple::set(size_t index, user_type const *value);

} // namespace cass
