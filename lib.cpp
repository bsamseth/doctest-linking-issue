#include "lib.h"
#include "doctest.h"  // Everything builds without this line.

bool dummy()
{
    return true;
}

TEST_CASE("test from lib.cpp")
{
    CHECK(bool(1) == true);
}
