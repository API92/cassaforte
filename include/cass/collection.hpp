/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassCollection_ CassCollection;

namespace cass {

class CASSA_IMPEXP collection : delete_defaults {
public:
    static collection * ptr(::CassCollection *p);

    ::CassCollection * backend();
    ::CassCollection const * backend() const;

    void free();
    static collection_ptr new_ptr(collection_type type,
            size_t item_count);

    static collection_ptr new_from_data_type(
            cass::data_type const *data_type, size_t item_count);

    cass::data_type const * data_type() const;

    error append(int8_t value);
    error append(int16_t value);
    error append(int32_t value);
    error append(uint32_t value);
    error append(int64_t value);
    error append(float value);
    error append(double value);
    error append(bool value);
    error append(char const *value);
    error append(std::string_view value);
    error append(bytes_view value);
    error append(custom c);
    error append(uuid const &value);
    error append(inet const &value);
    error append(decimal d);
    error append(collection const *value);
    error append(tuple const *value);
    error append(user_type const *value);

    error append_custom(char const *class_name, std::byte const *value,
            size_t value_size);
};

} // namespace cass
