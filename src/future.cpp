/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/future.hpp>

#include <cass/error_result.hpp>
#include <cass/prepared.hpp>
#include <cass/result.hpp>

namespace cass {

result_const_ptr future::get_result()
{
    ::CassResult const * res = ::cass_future_get_result(backend());
    return result_const_ptr(result::ptr(res), res != nullptr);
}

error_result_const_ptr future::get_error_result()
{
    ::CassErrorResult const * res = ::cass_future_get_error_result(backend());
    return error_result_const_ptr(error_result::ptr(res), res != nullptr);
}

prepared_const_ptr future::get_prepared()
{
    ::CassPrepared const * pr = ::cass_future_get_prepared(backend());
    return prepared_const_ptr(prepared::ptr(pr), pr != nullptr);
}

} // namespace cass
