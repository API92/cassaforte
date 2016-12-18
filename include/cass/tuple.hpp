/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassTuple_ CassTuple;

namespace cass {

class CASSA_IMPEXP tuple : delete_defaults {
public:
    static tuple * ptr(::CassTuple *p);

    ::CassTuple * backend();

    ::CassTuple const * backend() const;

    void free();
    static tuple_ptr new_ptr(size_t item_count);

    static tuple_ptr new_from_data_type(
            cass::data_type const *data_type);

    cass::data_type const * data_type() const;

    error set(size_t index, std::nullptr_t);
    error set(size_t index, int8_t value);
    error set(size_t index, int16_t value);
    error set(size_t index, int32_t value);
    error set(size_t index, uint32_t value);
    error set(size_t index, int64_t value);
    error set(size_t index, float value);
    error set(size_t index, double value);
    error set(size_t index, bool value);
    error set(size_t index, char const *value);
    error set(size_t index, std::experimental::string_view value);
    error set(size_t index, bytes_view value);
    error set(size_t index, custom c);
    error set(size_t index, uuid const &value);
    error set(size_t index, inet const &value);
    error set(size_t index, decimal d);
    error set(size_t index, tuple const *value);
    error set(size_t index, collection const *value);
    error set(size_t index, user_type const *value);

    error set_custom(size_t index, char const *class_name,
            byte_t const *value, size_t value_size);
};

} // namespace cass
