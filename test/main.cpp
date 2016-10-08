#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <cstring>
#include <string>

#include "../include/fixed_string.hpp"

TEST_CASE("fixed string test", "[basic_fixed_string]")
{
        using namespace fappy;

        constexpr auto max_size_ = 10;

        fixed_string_char<max_size_> str;

        REQUIRE(str.size() == 0);
        REQUIRE(str.max_size() == max_size_);

        SECTION("assign string shorter than max size")
        {
                const char* str__ = "gsomix";
                str               = str__;
                REQUIRE(str.size() == std::strlen(str__));
                REQUIRE(str.as_std_string() == std::string(str__));
        }
        SECTION("assign string larger than max size")
        {
                const char* str__ = "forneverbatmann";
                str               = str__;
                REQUIRE(str.size() == str.max_size());
                REQUIRE(str.as_std_string() == std::string(str__, str__ + 10));
        }
}
