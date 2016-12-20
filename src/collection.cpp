/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/collection.hpp>

#include <cassandra.h>

#include <cass/custom.hpp>
#include <cass/decimal.hpp>
#include <cass/data_type.hpp>
#include <cass/inet.hpp>
#include <cass/tuple.hpp>
#include <cass/user_type.hpp>
#include <cass/uuid.hpp>
#include <cass/wrapper_ptr_def.hpp>

namespace cass {

collection_ptr collection::new_from_data_type(
        cass::data_type const *data_type, size_t item_count)
{
    return collection_ptr(collection::ptr(::cass_collection_new_from_data_type(
                    data_type->backend(), item_count)));
}

data_type const * collection::data_type() const
{
    return cass::data_type::ptr(::cass_collection_data_type(backend()));
}

error collection::append(tuple const *value)
{
    return (error)::cass_collection_append_tuple(backend(), value->backend());
}

error collection::append(user_type const *value)
{
    return (error)::cass_collection_append_user_type(
            backend(), value->backend());
}

collection * collection::ptr(::CassCollection *p)
{
    return reinterpret_cast<collection *>(p);
}

::CassCollection * collection::backend()
{
    return reinterpret_cast<::CassCollection *>(this);
}

::CassCollection const * collection::backend() const
{
    return reinterpret_cast<::CassCollection const *>(this);
}

void collection::free()
{
    ::cass_collection_free(backend());
}

collection_ptr collection::new_ptr(collection_type type,
        size_t item_count)
{
    return collection_ptr(collection::ptr(::cass_collection_new(
                static_cast<::CassCollectionType>(type), item_count)));
}

error collection::append(int8_t value)
{
    return error(::cass_collection_append_int8(backend(), value));
}

error collection::append(int16_t value)
{
    return error(::cass_collection_append_int16(backend(), value));
}

error collection::append(int32_t value)
{
    return error(::cass_collection_append_int32(backend(), value));
}

error collection::append(uint32_t value)
{
    return error(::cass_collection_append_uint32(backend(), value));
}

error collection::append(int64_t value)
{
    return error(::cass_collection_append_int64(backend(), value));
}

error collection::append(float value)
{
    return error(::cass_collection_append_float(backend(), value));
}

error collection::append(double value)
{
    return error(::cass_collection_append_double(backend(), value));
}

error collection::append(bool value)
{
    return error(::cass_collection_append_bool(
                backend(), value ? cass_true : cass_false));
}

error collection::append(char const *value)
{
    return error(::cass_collection_append_string(backend(), value));
}

error collection::append(std::experimental::string_view value)
{
    return error(::cass_collection_append_string_n(
                backend(), value.data(), value.size()));
}

error collection::append(bytes_view value)
{
    return error(::cass_collection_append_bytes(
                backend(), value.data(), value.size()));
}

error collection::append_custom(char const *class_name,
        byte_t const *value, size_t value_size)
{
    return error(::cass_collection_append_custom(
                backend(), class_name, value, value_size));
}

error collection::append(custom c)
{
    return error(::cass_collection_append_custom_n(
                backend(), c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

error collection::append(uuid const &value)
{
    return error(::cass_collection_append_uuid(backend(), *value.backend()));
}

error collection::append(inet const &value)
{
    return error(::cass_collection_append_inet(backend(), *value.backend()));
}

error collection::append(decimal d)
{
    return error(::cass_collection_append_decimal(
                backend(), d.varint, d.varint_size, d.scale));
}

error collection::append(collection const *value)
{
    return error(::cass_collection_append_collection(
                backend(), value->backend()));
}

template class wrapper_ptr<collection>;

} // namespace cass
