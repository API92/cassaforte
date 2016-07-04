/*
 * Copyright (C) Andrey Pikas
 */

#include <cassandra.h>

namespace cass {

class custom_payload {
public:
    explicit custom_payload(::CassCustomPayload *p) : p(p) {}
    ::CassCustomPayload * backend() { return p; }
    ::CassCustomPayload const * backend() const { return p; }

private:
    ::CassCustomPayload *p;
};

} // namespace cass
