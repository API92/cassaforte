/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include "forward.hpp"
#include "impexp.hpp"

typedef struct CassInet_ CassInet;

namespace cass {

class CASSA_IMPEXP inet
{
public:
    inet();
    ~inet();
    inet(inet const &rhs);
    inet & operator = (inet const &rhs);
    inet(inet &&rhs);
    inet & operator = (inet &&rhs);
    explicit inet(::CassInet const &base);

    ::CassInet * backend();
    ::CassInet const * backend() const;

    static inet init_v4(uint8_t const *address);

    static inet init_v6(uint8_t const *address);

    void string(char *output) const;

    error from_string(char const *str);
    error from_string_n(char const *str, size_t str_length);

private:
    void *_impl;
};

} // namespace cass
