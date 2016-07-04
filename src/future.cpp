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
    return result_const_ptr(result(::cass_future_get_result(p)), true);
}

error_result_const_ptr future::get_error_result()
{
    return error_result_const_ptr(error_result(
                ::cass_future_get_error_result(p)), true);
}

prepared_const_ptr future::get_prepared()
{
    return prepared_const_ptr(prepared(::cass_future_get_prepared(p)), true);
}

} // namespace cass
