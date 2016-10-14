/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/statement.hpp>

#include <cass/collection.hpp>
#include <cass/custom_payload.hpp>
#include <cass/result.hpp>
#include <cass/retry_policy.hpp>
#include <cass/tuple.hpp>
#include <cass/user_type.hpp>

namespace cass {

error statement::set_paging_state(cass::result const *result)
{
    return (error)::cass_statement_set_paging_state(p, result->backend());
}

error statement::set_retry_policy(cass::retry_policy *retry_policy)
{
    return (error)::cass_statement_set_retry_policy(p, retry_policy->backend());
}

error statement::set_custom_payload(custom_payload const *payload)
{
    return (error)::cass_statement_set_custom_payload(
            p, (payload ? payload->backend() : nullptr));
}

error statement::bind_collection(size_t index,
        cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection(
            p, index, collection->backend());
}

error statement::bind_collection_by_name(char const *name,
        cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection_by_name(p, name,
            collection->backend());
}

error statement::bind_collection_by_name_n(char const *name,
        size_t name_length, cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection_by_name_n(
            p, name, name_length, collection->backend());
}

error statement::bind_tuple(size_t index, cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple(p, index, tuple->backend());
}

error statement::bind_tuple_by_name(char const *name, cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple_by_name(
            p, name, tuple->backend());
}

error statement::bind_tuple_by_name_n(char const *name, size_t name_length,
        cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple_by_name_n(p, name, name_length,
            tuple->backend());
}

error statement::bind_user_type(size_t index, cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type(
            p, index, user_type->backend());
}

error statement::bind_user_type_by_name(char const *name,
        cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type_by_name(p, name,
            user_type->backend());
}

error statement::bind_user_type_by_name_n(char const *name, size_t name_length,
        cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type_by_name_n(
            p, name, name_length, user_type->backend());
}

} // namespace cass
