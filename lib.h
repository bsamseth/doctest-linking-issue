#pragma once
#include "doctest.h"

bool dummy();


TEST_CASE("test from lib.h")
{
    CHECK(dummy() == true);
}
