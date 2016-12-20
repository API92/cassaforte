/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/tuple.hpp>

#include <cassandra.h>

#include <cass/collection.hpp>
#include <cass/custom.hpp>
#include <cass/data_type.hpp>
#include <cass/decimal.hpp>
#include <cass/inet.hpp>
#include <cass/user_type.hpp>
#include <cass/uuid.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

tuple * tuple::ptr(::CassTuple *p)
{
    return reinterpret_cast<tuple *>(p);
}

::CassTuple * tuple::backend()
{
    return reinterpret_cast<::CassTuple *>(this);
}

::CassTuple const * tuple::backend() const
{
    return reinterpret_cast<::CassTuple const *>(this);
}

void tuple::free()
{
    ::cass_tuple_free(backend());
}

tuple_ptr tuple::new_ptr(size_t item_count)
{
    return tuple_ptr(tuple::ptr(::cass_tuple_new(item_count)));
}

error tuple::set(size_t index, std::nullptr_t)
{
    return error(::cass_tuple_set_null(backend(), index));
}

error tuple::set(size_t index, int8_t value)
{
    return error(::cass_tuple_set_int8(backend(), index, value));
}

error tuple::set(size_t index, int16_t value)
{
    return error(::cass_tuple_set_int16(backend(), index, value));
}

error tuple::set(size_t index, int32_t value)
{
    return error(::cass_tuple_set_int32(backend(), index, value));
}

error tuple::set(size_t index, uint32_t value)
{
    return error(::cass_tuple_set_uint32(backend(), index, value));
}

error tuple::set(size_t index, int64_t value)
{
    return error(::cass_tuple_set_int64(backend(), index, value));
}

error tuple::set(size_t index, float value)
{
    return error(::cass_tuple_set_float(backend(), index, value));
}

error tuple::set(size_t index, double value)
{
    return error(::cass_tuple_set_double(backend(), index, value));
}

error tuple::set(size_t index, bool value)
{
    return error(::cass_tuple_set_bool(
                backend(), index, value ? cass_true : cass_false));
}

error tuple::set(size_t index, char const *value)
{
    return error(::cass_tuple_set_string(backend(), index, value));
}

error tuple::set(size_t index, std::experimental::string_view value)
{
    return error(::cass_tuple_set_string_n(
                backend(), index, value.data(), value.size()));
}

error tuple::set(size_t index, bytes_view value)
{
    return error(::cass_tuple_set_bytes(
                backend(), index, value.data(), value.size()));
}

error tuple::set_custom(size_t index, char const *class_name,
        byte_t const *value, size_t value_size)
{
    return error(::cass_tuple_set_custom(
                backend(), index, class_name, value, value_size));
}

error tuple::set(size_t index, custom c)
{
    return error(::cass_tuple_set_custom_n(
                backend(), index, c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

error tuple::set(size_t index, uuid const &value)
{
    return error(::cass_tuple_set_uuid(backend(), index, *value.backend()));
}

error tuple::set(size_t index, inet const &value)
{
    return (error)::cass_tuple_set_inet(backend(), index, *value.backend());
}

error tuple::set(size_t index, decimal d)
{
    return error(::cass_tuple_set_decimal(
                backend(), index, d.varint, d.varint_size, d.scale));
}

error tuple::set(size_t index, tuple const *value)
{
    return error(::cass_tuple_set_tuple(backend(), index, value->backend()));
}

tuple_ptr tuple::new_from_data_type(cass::data_type const *data_type)
{
    return tuple_ptr(ptr(::cass_tuple_new_from_data_type(
                    data_type->backend())));
}

data_type const * tuple::data_type() const
{
    return cass::data_type::ptr(::cass_tuple_data_type(backend()));
}

error tuple::set(size_t index, collection const *value)
{
    return (error)::cass_tuple_set_collection(
                backend(), index, value->backend());
}

error tuple::set(size_t index, user_type const *value)
{
    return (error)::cass_tuple_set_user_type(
                backend(), index, value->backend());
}

template class wrapper_ptr<tuple>;

} // namespace cass
