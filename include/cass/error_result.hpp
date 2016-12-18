/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "delete_defaults.hpp"
#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassErrorResult_ CassErrorResult;

namespace cass {

class CASSA_IMPEXP error_result : delete_defaults {
public:
    static error_result const * ptr(::CassErrorResult const *p);

    ::CassErrorResult const * backend() const;

    void free() const;

    error code() const;

    cass::consistency consistency() const;

    int32_t num_failures() const;

    bool data_present() const;

    cass::write_type write_type() const;

    error keyspace(char const **keyspace, size_t *keyspace_length) const;

    error table(char const **tbl, size_t *tbl_length) const;

    error function(char const **function, size_t *function_length);

    size_t num_arg_types() const;

    error arg_type(size_t index, char const **arg_type,
            size_t *arg_type_length) const;
};

} // namespace cass
