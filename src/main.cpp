#include <cass/session.hpp>

namespace cass {

void test()
{
    cluster c(nullptr);
    session_ptr s(session::new_ptr());
    s->connect(&c);
}

} // namespace cass
