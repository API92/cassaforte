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
    ::CassUserType * t = ::cass_user_type_new_from_data_type(
            data_type->backend());
    return user_type_ptr(ptr(t), t != nullptr);
}

data_type const * user_type::data_type() const
{
    return cass::data_type::ptr(::cass_user_type_data_type(backend()));
}

template<>
error user_type::set(size_t index, collection const *value)
{
    return (error)::cass_user_type_set_collection(
            backend(), index, value->backend());
}

template<>
error user_type::set_by_name(char const *name,
        collection const *value)
{
    return (error)::cass_user_type_set_collection_by_name(
            backend(), name, value->backend());
}

template<>
error user_type::set_by_name_n(char const *name,
        size_t name_length, collection const *value)
{
    return (error)::cass_user_type_set_collection_by_name_n(
            backend(), name, name_length, value->backend());
}

template<>
error user_type::set(size_t index, tuple const *value)
{
    return (error)::cass_user_type_set_tuple(
            backend(), index, value->backend());
}

template<>
error user_type::set_by_name(char const *name, tuple const *value)
{
    return (error)::cass_user_type_set_tuple_by_name(
            backend(), name, value->backend());
}

template<>
error user_type::set_by_name_n(char const *name, size_t name_length,
        tuple const *value)
{
    return (error)::cass_user_type_set_tuple_by_name_n(
            backend(), name, name_length, value->backend());
}

} // namespace cass
