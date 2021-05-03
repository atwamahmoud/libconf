#include <libconf.hpp>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("test_sayHello")
{
    std::string value = libconf::sayHello();
    REQUIRE(value == std::string("Hello, World"));
}