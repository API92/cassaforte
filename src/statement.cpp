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
    return (error)::cass_statement_set_paging_state(
            backend(), result->backend());
}

error statement::set_retry_policy(cass::retry_policy *retry_policy)
{
    return (error)::cass_statement_set_retry_policy(backend(), retry_policy->backend());
}

error statement::set_custom_payload(custom_payload const *payload)
{
    return (error)::cass_statement_set_custom_payload(
            backend(), (payload ? payload->backend() : nullptr));
}

template<>
error statement::bind(size_t index,
        cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection(
            backend(), index, collection->backend());
}

template<>
error statement::bind_by_name(char const *name,
        cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection_by_name(backend(), name,
            collection->backend());
}

template<>
error statement::bind_by_name_n(char const *name,
        size_t name_length, cass::collection const *collection)
{
    return (error)::cass_statement_bind_collection_by_name_n(
            backend(), name, name_length, collection->backend());
}

template<>
error statement::bind(size_t index, cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple(
            backend(), index, tuple->backend());
}

template<>
error statement::bind_by_name(char const *name, cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple_by_name(
            backend(), name, tuple->backend());
}

template<>
error statement::bind_by_name_n(char const *name, size_t name_length,
        cass::tuple const *tuple)
{
    return (error)::cass_statement_bind_tuple_by_name_n(
            backend(), name, name_length, tuple->backend());
}

template<>
error statement::bind(size_t index, cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type(
            backend(), index, user_type->backend());
}

template<>
error statement::bind_by_name(char const *name,
        cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type_by_name(backend(), name,
            user_type->backend());
}

template<>
error statement::bind_by_name_n(char const *name, size_t name_length,
        cass::user_type const *user_type)
{
    return (error)::cass_statement_bind_user_type_by_name_n(
            backend(), name, name_length, user_type->backend());
}

} // namespace cass
