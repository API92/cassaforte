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

typedef wrapper_ptr<class collection> collection_ptr;

class collection : wrapper {
public:
    static collection * ptr(::CassCollection *p)
    {
        return reinterpret_cast<collection *>(p);
    }

    ::CassCollection * backend()
    {
        return reinterpret_cast<::CassCollection *>(this);
    }

    ::CassCollection const * backend() const
    {
        return reinterpret_cast<::CassCollection const *>(this);
    }

    inline void free();
    inline static collection_ptr new_ptr(collection_type type,
            size_t item_count);

    CASSA_IMPEXP static collection_ptr new_from_data_type(
            cass::data_type const *data_type, size_t item_count);

    CASSA_IMPEXP cass::data_type const * data_type() const;

    inline error append(int8_t value);
    inline error append(int16_t value);
    inline error append(int32_t value);
    inline error append(uint32_t value);
    inline error append(int64_t value);
    inline error append(float value);
    inline error append(double value);
    inline error append(bool value);
    inline error append(char const *value);
    inline error append(std::experimental::string_view value);
    inline error append(bytes_view value);
    inline error append(custom c);
    inline error append(uuid value);
    inline error append(inet value);
    inline error append(decimal d);
    inline error append(collection const *value);
    CASSA_IMPEXP error append(tuple const *value);
    CASSA_IMPEXP error append(user_type const *value);

    inline error append_custom(char const *class_name, byte_t const *value,
            size_t value_size);
};

inline void collection::free()
{
    ::cass_collection_free(backend());
}

inline collection_ptr collection::new_ptr(collection_type type,
        size_t item_count)
{
    return collection_ptr(collection::ptr(::cass_collection_new(
                static_cast<::CassCollectionType>(type), item_count)), true);
}

inline error collection::append(int8_t value)
{
    return error(::cass_collection_append_int8(backend(), value));
}

inline error collection::append(int16_t value)
{
    return error(::cass_collection_append_int16(backend(), value));
}

inline error collection::append(int32_t value)
{
    return error(::cass_collection_append_int32(backend(), value));
}

inline error collection::append(uint32_t value)
{
    return error(::cass_collection_append_uint32(backend(), value));
}

inline error collection::append(int64_t value)
{
    return error(::cass_collection_append_int64(backend(), value));
}

inline error collection::append(float value)
{
    return error(::cass_collection_append_float(backend(), value));
}

inline error collection::append(double value)
{
    return error(::cass_collection_append_double(backend(), value));
}

inline error collection::append(bool value)
{
    return error(::cass_collection_append_bool(
                backend(), value ? cass_true : cass_false));
}

inline error collection::append(char const *value)
{
    return error(::cass_collection_append_string(backend(), value));
}

inline error collection::append(std::experimental::string_view value)
{
    return error(::cass_collection_append_string_n(
                backend(), value.data(), value.size()));
}

inline error collection::append(bytes_view value)
{
    return error(::cass_collection_append_bytes(
                backend(), value.data(), value.size()));
}

inline error collection::append_custom(char const *class_name,
        byte_t const *value, size_t value_size)
{
    return error(::cass_collection_append_custom(
                backend(), class_name, value, value_size));
}

inline error collection::append(custom c)
{
    return error(::cass_collection_append_custom_n(
                backend(), c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

inline error collection::append(uuid value)
{
    return error(::cass_collection_append_uuid(backend(), value));
}

inline error collection::append(inet value)
{
    return error(::cass_collection_append_inet(backend(), value));
}

inline error collection::append(decimal d)
{
    return error(::cass_collection_append_decimal(
                backend(), d.varint, d.varint_size, d.scale));
}

inline error collection::append(collection const *value)
{
    return error(::cass_collection_append_collection(
                backend(), value->backend()));
}

} // namespace cass
