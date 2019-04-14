Desired functionallity:

  - Library has tests written directely in the source
  - Possible to link a standalone executable to the library, without any doctest-related code

Now, if the library includes the `doctest.h` header, an executable simply using the library fails to link due to missing symbols for doctest.
Building the test runner works just fine, but it seems that defining a separate `main` function without any doctest mentions causes the failiure.

Current behaviour:

``` bash
> cmake . -Bbuild
-- The CXX compiler identification is GNU 8.2.0
... (finishes without any issues)

> cmake --build build
Scanning dependencies of target lib
[ 20%] Building CXX object CMakeFiles/lib.dir/lib.cpp.o
[ 20%] Built target lib
Scanning dependencies of target exec
[ 40%] Building CXX object CMakeFiles/exec.dir/exec.cpp.o
[ 60%] Linking CXX executable exec
Undefined symbols for architecture x86_64:
  "doctest::detail::setTestSuite(doctest::detail::TestSuite const&)", referenced from:
      __static_initialization_and_destruction_0(int, int) in lib.cpp.o
  "doctest::detail::TestSuite::TestSuite()", referenced from:
      __static_initialization_and_destruction_0(int, int) in lib.cpp.o
  "doctest::detail::TestSuite::~TestSuite()", referenced from:
      __static_initialization_and_destruction_0(int, int) in lib.cpp.o
  "doctest::detail::TestSuite::operator*(char const*)", referenced from:
      __static_initialization_and_destruction_0(int, int) in lib.cpp.o
ld: symbol(s) not found for architecture x86_64
collect2: error: ld returned 1 exit status
make[2]: *** [exec] Error 1
make[1]: *** [CMakeFiles/exec.dir/all] Error 2
make: *** [all] Error 2

```
