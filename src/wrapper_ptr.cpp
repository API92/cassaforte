/*
 * Copyright (C) Andrey Pikas
 */

#include <cass/wrapper_ptr_def.hpp>

#include <cassert>

#include <falloc/cache.hpp>

namespace cass {
namespace detail {

///
/// counter_type
///

typedef falloc::object_cache<counter_type> counter_cache;

void * counter_type::operator new (std::size_t sz, std::nothrow_t) noexcept
{
    assert(sz == sizeof(counter_type));
    (void)sz;
    return counter_cache::alloc_with_new_handler();
}

void counter_type::operator delete(void *p)
{
    counter_cache::free(reinterpret_cast<counter_type *>(p));
}

} // namespace detail
} // namespace cass
