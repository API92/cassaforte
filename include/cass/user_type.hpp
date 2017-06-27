/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassUserType_ CassUserType;

namespace cass {

class CASSA_IMPEXP user_type : delete_defaults {
public:
    static user_type * ptr(::CassUserType *p);

    ::CassUserType * backend();
    ::CassUserType const * backend() const;

    void free();

    static user_type_ptr new_from_data_type(
            cass::data_type const *data_type);

    cass::data_type const * data_type() const;

    error set(size_t index, std::nullptr_t);
    error set_by_name(char const *name, std::nullptr_t);
    error set_by_name_n(char const *name, size_t name_length,
            std::nullptr_t);

    error set(size_t index, int8_t value);
    error set_by_name(char const *name, int8_t value);
    error set_by_name_n(char const *name, size_t name_length,
            int8_t value);

    error set(size_t index, int16_t value);
    error set_by_name(char const *name, int16_t value);
    error set_by_name_n(char const *name,
            size_t name_length, int16_t value);

    error set(size_t index, int32_t value);
    error set_by_name(char const *name, int32_t value);
    error set_by_name_n(char const *name,
            size_t name_length, int32_t value);

    error set(size_t index, uint32_t value);
    error set_by_name(char const *name, uint32_t value);
    error set_by_name_n(char const *name,
            size_t name_length, uint32_t value);

    error set(size_t index, int64_t value);
    error set_by_name(char const *name, int64_t value);
    error set_by_name_n(char const *name,
            size_t name_length, int64_t value);

    error set(size_t index, float value);
    error set_by_name(char const *name, float value);
    error set_by_name_n(
            char const *name, size_t name_length, float value);

    error set(size_t index, double value);
    error set_by_name(char const *name, double value);
    error set_by_name_n(char const *name,
            size_t name_length, double value);

    error set(size_t index, bool value);
    error set_by_name(char const *name, bool value);
    error set_by_name_n(char const *name, size_t name_length,
            bool value);

    error set(size_t index, char const *value);
    error set(size_t index, std::string_view value);
    error set_by_name(char const *name, char const *value);
    error set_by_name_n(char const *name, size_t name_length,
            std::string_view value);

    error set(size_t index, bytes_view value);
    error set_by_name(char const *name, bytes_view value);
    error set_by_name_n(char const *name,
            size_t name_length, bytes_view value);

    error set(size_t index, custom c);
    error set_by_name_n(char const *name, size_t name_length, custom c);

    error set(size_t index, uuid const &value);
    error set_by_name(char const *name, uuid const &value);
    error set_by_name_n(char const *name, size_t name_length,
            uuid const &value);

    error set(size_t index, inet const &value);
    error set_by_name(char const *name, inet const &value);
    error set_by_name_n(char const *name, size_t name_length,
            inet const &value);

    error set(size_t index, decimal d);
    error set_by_name(char const *name, decimal d);
    error set_by_name_n(char const *name, size_t name_length,
            decimal d);

    error set(size_t index, user_type const *value);
    error set_by_name(char const *name, user_type const *value);
    error set_by_name_n(char const *name,
            size_t name_length, user_type const *value);

    error set(size_t index, collection const *value);
    error set_by_name(char const *name, collection const *value);
    error set_by_name_n(char const *name,
            size_t name_length, collection const *value);

    error set(size_t index, tuple const *value);
    error set_by_name(char const *name, tuple const *value);
    error set_by_name_n(
            char const *name, size_t name_length, tuple const *value);

    template<typename T>
    error set_by_name(std::string_view name, T value)
    {
        return set_by_name_n(name.data(), name.size(), value);
    }

    error set_custom(size_t index, char const *class_name,
            std::byte const *value, size_t value_size);
    error set_custom_by_name(char const *name, char const *class_name,
            std::byte const *value, size_t value_size);
};

} // namespace cass
