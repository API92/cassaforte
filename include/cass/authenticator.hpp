/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#include <cassandra.h>

namespace cass {

class authenticator {
public:
    explicit authenticator(::CassAuthenticator *p) : p(p) {}
    ::CassAuthenticator * backend() { return p; }
    ::CassAuthenticator const * backend() const { return p; }

private:
    ::CassAuthenticator *p;
};

} // namespace cass
