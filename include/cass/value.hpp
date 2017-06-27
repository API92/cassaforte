/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef class CassValue_ CassValue;

namespace cass {

class CASSA_IMPEXP value : delete_defaults {
public:
    static value const * ptr(::CassValue const *p);

    ::CassValue const * backend() const;

    cass::data_type const * data_type() const;

    error get(int8_t *output) const;
    error get(int16_t *output) const;
    error get(int32_t *output) const;
    error get(uint32_t *output) const;
    error get(int64_t *output) const;
    error get(float *output) const;
    error get(double *output) const;
    error get(bool *output) const;
    error get(uuid *output) const;
    error get(inet *output) const;
    error get(std::string_view *output) const;
    error get(bytes_view *output) const;
    error get(decimal *output) const;

    value_type type() const;

    bool is_null() const;

    bool is_collection() const;

    size_t item_count() const;

    value_type primary_sub_type() const;

    value_type secondary_sub_type() const;
};

} // namespace cass
