/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

#include <cass/defs.hpp>
#include <cass/wrapper_ptr.hpp>

namespace cass {

typedef wrapper_ptr<class error_result const> error_result_const_ptr;

class error_result {
public:
    explicit error_result(::CassErrorResult const *p) : p(p) {}
    ::CassErrorResult const * backend() const { return p; }

    inline static void free(error_result const e);

    inline error code() const;

    inline cass::consistency consistency() const;

    inline int32_t responses_received() const;

    inline int32_t responses_required() const;

    inline int32_t num_failures() const;

    inline bool data_present() const;

    inline cass::write_type write_type() const;

    inline error keyspace(char const **keyspace, size_t *keyspace_length) const;

    inline error table(char const **tbl, size_t *tbl_length) const;

    inline error function(char const **function, size_t *function_length);

    inline size_t num_arg_types() const;

    inline error arg_type(size_t index, char const **arg_type,
            size_t *arg_type_length) const;

private:
    ::CassErrorResult const *p;
};

inline void error_result::free(error_result const e)
{
    ::cass_error_result_free(e.p);
}

inline error error_result::code() const
{
    return (error)::cass_error_result_code(p);
}

inline consistency error_result::consistency() const
{
    return ::cass_error_result_consistency(p);
}

inline int32_t error_result::responses_received() const
{
    return ::cass_error_result_responses_received(p);
}

inline int32_t error_result::responses_required() const
{
    return ::cass_error_result_responses_required(p);
}

inline int32_t error_result::num_failures() const
{
    return ::cass_error_result_num_failures(p);
}

inline bool error_result::data_present() const
{
    return ::cass_error_result_data_present(p);
}

inline write_type error_result::write_type() const
{
    return ::cass_error_result_write_type(p);
}

inline error error_result::keyspace(char const **keyspace,
        size_t *keyspace_length) const
{
    return (error)::cass_error_result_keyspace(p, keyspace, keyspace_length);
}

inline error error_result::table(char const **tbl, size_t *tbl_length) const
{
    return (error)::cass_error_result_table(p, tbl, tbl_length);
}

inline error error_result::function(char const **function,
        size_t *function_length)
{
    return (error)::cass_error_result_function(p, function, function_length);
}

inline size_t error_result::num_arg_types() const
{
    return ::cass_error_num_arg_types(p);
}

inline error error_result::arg_type(size_t index, char const **arg_type,
        size_t *arg_type_length) const
{
    return (error)::cass_error_result_arg_type(
            p, index, arg_type, arg_type_length);
}

} // namespace cass
