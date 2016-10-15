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

class collection {
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
    inline static collection_ptr new_ptr(colletion_type type,
            size_t item_count);

    CASSA_IMPEXP static collection_ptr new_from_data_type(
            cass::data_type const *data_type, size_t item_count);

    CASSA_IMPEXP cass::data_type const * data_type() const;

    template<typename T>
    error append(T value);

    inline error append_custom(char const *class_name, byte_t const *value,
            size_t value_size);
};

inline void collection::free()
{
    ::cass_collection_free(backend());
}

inline collection_ptr collection::new_ptr(colletion_type type,
        size_t item_count)
{
    return collection_ptr(collection::ptr(::cass_collection_new(
                    type, item_count)), true);
}

template<>
inline error collection::append(int8_t value)
{
    return error(::cass_collection_append_int8(backend(), value));
}

template<>
inline error collection::append(int16_t value)
{
    return error(::cass_collection_append_int16(backend(), value));
}

template<>
inline error collection::append(int32_t value)
{
    return error(::cass_collection_append_int32(backend(), value));
}

template<>
inline error collection::append(uint32_t value)
{
    return error(::cass_collection_append_uint32(backend(), value));
}

template<>
inline error collection::append(int64_t value)
{
    return error(::cass_collection_append_int64(backend(), value));
}

template<>
inline error collection::append(float value)
{
    return error(::cass_collection_append_float(backend(), value));
}

template<>
inline error collection::append(double value)
{
    return error(::cass_collection_append_double(backend(), value));
}

template<>
inline error collection::append(bool value)
{
    return error(::cass_collection_append_bool(
                backend(), value ? cass_true : cass_false));
}

template<>
inline error collection::append(char const *value)
{
    return error(::cass_collection_append_string(backend(), value));
}

template<>
inline error collection::append(std::experimental::string_view value)
{
    return error(::cass_collection_append_string_n(
                backend(), value.data(), value.size()));
}

template<>
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

template<>
inline error collection::append(custom c)
{
    return error(::cass_collection_append_custom_n(
                backend(), c.class_name.data(), c.class_name.size(),
                c.value.data(), c.value.size()));
}

template<>
inline error collection::append(uuid value)
{
    return error(::cass_collection_append_uuid(backend(), value));
}

template<>
inline error collection::append(inet value)
{
    return error(::cass_collection_append_inet(backend(), value));
}

template<>
inline error collection::append(decimal d)
{
    return error(::cass_collection_append_decimal(
                backend(), d.varint, d.varint_size, d.scale));
}

template<>
inline error collection::append(collection const *value)
{
    return error(::cass_collection_append_collection(
                backend(), value->backend()));
}

template<>
CASSA_IMPEXP error collection::append(tuple const *value);

template<>
CASSA_IMPEXP error collection::append(user_type const *value);

} // namespace cass
