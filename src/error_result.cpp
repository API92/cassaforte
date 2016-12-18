/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/error_result.hpp>

#include <cassandra.h>

#include <cass/wrapper_ptr_def.hpp>

namespace cass {

error_result const * error_result::ptr(::CassErrorResult const *p)
{
    return reinterpret_cast<error_result const *>(p);
}

::CassErrorResult const * error_result::backend() const
{
    return reinterpret_cast<::CassErrorResult const *>(this);
}

void error_result::free() const
{
    ::cass_error_result_free(backend());
}

error error_result::code() const
{
    return (error)::cass_error_result_code(backend());
}

consistency error_result::consistency() const
{
    return (cass::consistency)::cass_error_result_consistency(backend());
}

int32_t error_result::num_failures() const
{
    return ::cass_error_result_num_failures(backend());
}

bool error_result::data_present() const
{
    return ::cass_error_result_data_present(backend());
}

write_type error_result::write_type() const
{
    return (cass::write_type)::cass_error_result_write_type(backend());
}

error error_result::keyspace(char const **keyspace,
        size_t *keyspace_length) const
{
    return (error)::cass_error_result_keyspace(
            backend(), keyspace, keyspace_length);
}

error error_result::table(char const **tbl, size_t *tbl_length) const
{
    return (error)::cass_error_result_table(backend(), tbl, tbl_length);
}

error error_result::function(char const **function,
        size_t *function_length)
{
    return (error)::cass_error_result_function(
            backend(), function, function_length);
}

size_t error_result::num_arg_types() const
{
    return ::cass_error_num_arg_types(backend());
}

error error_result::arg_type(size_t index, char const **arg_type,
        size_t *arg_type_length) const
{
    return (error)::cass_error_result_arg_type(
            backend(), index, arg_type, arg_type_length);
}

template class wrapper_ptr<error_result const>;

} // namespace cass
