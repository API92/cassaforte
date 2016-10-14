/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/user_type.hpp>

#include <cass/collection.hpp>
#include <cass/data_type.hpp>
#include <cass/tuple.hpp>

namespace cass {

user_type_ptr user_type::new_from_data_type(cass::data_type const *data_type)
{
    user_type t(::cass_user_type_new_from_data_type(data_type->backend()));
    return user_type_ptr(t, t.backend() != nullptr);
}

data_type_const_ptr user_type::data_type() const
{
    return data_type_const_ptr(cass::data_type(::cass_user_type_data_type(p)),
            false);
}

error user_type::set_collection(size_t index, collection const *value)
{
    return (error)::cass_user_type_set_collection(p, index, value->backend());
}

error user_type::set_collection_by_name(char const *name,
        collection const *value)
{
    return (error)::cass_user_type_set_collection_by_name(
            p, name, value->backend());
}

error user_type::set_collection_by_name_n(char const *name,
        size_t name_length, collection const *value)
{
    return (error)::cass_user_type_set_collection_by_name_n(
            p, name, name_length, value->backend());
}

error user_type::set_tuple(size_t index, tuple const *value)
{
    return (error)::cass_user_type_set_tuple(p, index, value->backend());
}

error user_type::set_tuple_by_name(char const *name, tuple const *value)
{
    return (error)::cass_user_type_set_tuple_by_name(p, name, value->backend());
}

error user_type::set_tuple_by_name_n(char const *name, size_t name_length,
        tuple const *value)
{
    return (error)::cass_user_type_set_tuple_by_name_n(p, name, name_length,
            value->backend());
}

} // namespace cass
