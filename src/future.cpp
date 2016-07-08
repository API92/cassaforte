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
    result res(::cass_future_get_result(p));
    return result_const_ptr(res, res.backend() ? true : false);
}

error_result_const_ptr future::get_error_result()
{
    return error_result_const_ptr(error_result(
                ::cass_future_get_error_result(p)), true);
}

prepared_const_ptr future::get_prepared()
{
    prepared pr(::cass_future_get_prepared(p));
    return prepared_const_ptr(pr, pr.backend() ? true : false);
}

} // namespace cass
