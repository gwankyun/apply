#define CATCH_CONFIG_MAIN
#include <tuple>
#include <array>
#include <utility>
#include <catch2/catch.hpp>
#include <msgpack.hpp>
#include <boost/tuple/tuple.hpp>
#include <apply.hpp>

int f1(int a)
{
    return a;
}

int f2(int a, int b)
{
    return a + b;
}

int f3(int a, int b, int c)
{
    return a + b + c;
}

int f4(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int f5(int a, int b, int c, int d, int e)
{
    return a + b + c + d + e;
}

int f6(int a, int b, int c, int d, int e, int f)
{
    return a + b + c + d + e + f;
}

int f7(int a, int b, int c, int d, int e, int f, int g)
{
    return a + b + c + d + e + f + g;
}

int f8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return a + b + c + d + e + f + g + h;
}

int f9(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return a + b + c + d + e + f + g + h + i;
}

TEST_CASE("msgpack::type::tuple", "[lite::apply]")
{
    REQUIRE(lite::apply(f1, msgpack::type::make_tuple(1)) == 1);
    REQUIRE(lite::apply(f2, msgpack::type::make_tuple(1, 2)) == 3);
    REQUIRE(lite::apply(f3, msgpack::type::make_tuple(1, 2, 3)) == 6);
    REQUIRE(lite::apply(f4, msgpack::type::make_tuple(1, 2, 3, 4)) == 10);
    REQUIRE(lite::apply(f5, msgpack::type::make_tuple(1, 2, 3, 4, 5)) == 15);
    REQUIRE(lite::apply(f6, msgpack::type::make_tuple(1, 2, 3, 4, 5, 6)) == 21);
    REQUIRE(lite::apply(f7, msgpack::type::make_tuple(1, 2, 3, 4, 5, 6, 7)) == 28);
    REQUIRE(lite::apply(f8, msgpack::type::make_tuple(1, 2, 3, 4, 5, 6, 7, 8)) == 36);
    REQUIRE(lite::apply(f9, msgpack::type::make_tuple(1, 2, 3, 4, 5, 6, 7, 8, 9)) == 45);
}

#if APPLY_HAS_CXX_11
TEST_CASE("std::tuple", "[lite::apply]")
{
    REQUIRE(lite::apply(f1, std::make_tuple(1)) == 1);
    REQUIRE(lite::apply(f2, std::make_tuple(1, 2)) == 3);
    REQUIRE(lite::apply(f3, std::make_tuple(1, 2, 3)) == 6);
    REQUIRE(lite::apply(f4, std::make_tuple(1, 2, 3, 4)) == 10);
    REQUIRE(lite::apply(f5, std::make_tuple(1, 2, 3, 4, 5)) == 15);
    REQUIRE(lite::apply(f6, std::make_tuple(1, 2, 3, 4, 5, 6)) == 21);
    REQUIRE(lite::apply(f7, std::make_tuple(1, 2, 3, 4, 5, 6, 7)) == 28);
    REQUIRE(lite::apply(f8, std::make_tuple(1, 2, 3, 4, 5, 6, 7, 8)) == 36);
    REQUIRE(lite::apply(f9, std::make_tuple(1, 2, 3, 4, 5, 6, 7, 8, 9)) == 45);
}

TEST_CASE("std::array", "[lite::apply]")
{
    std::array<int, 1> a1{ 1 };
    REQUIRE(lite::apply(f1, a1) == 1);
    std::array<int, 2> a2{ 1, 2 };
    REQUIRE(lite::apply(f2, a2) == 3);
    std::array<int, 3> a3{ 1, 2, 3 };
    REQUIRE(lite::apply(f3, a3) == 6);
    std::array<int, 4> a4{ 1, 2, 3, 4 };
    REQUIRE(lite::apply(f4, a4) == 10);
    std::array<int, 5> a5{ 1, 2, 3, 4, 5 };
    REQUIRE(lite::apply(f5, a5) == 15);
    std::array<int, 6> a6{ 1, 2, 3, 4, 5, 6 };
    REQUIRE(lite::apply(f6, a6) == 21);
    std::array<int, 7> a7{ 1, 2, 3, 4, 5, 6, 7 };
    REQUIRE(lite::apply(f7, a7) == 28);
    std::array<int, 8> a8{ 1, 2, 3, 4, 5, 6, 7, 8 };
    REQUIRE(lite::apply(f8, a8) == 36);
    std::array<int, 9> a9{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    REQUIRE(lite::apply(f9, a9) == 45);
}
#endif // APPLY_HAS_CXX_11

TEST_CASE("boost::tuple", "[lite::apply]")
{
    REQUIRE(lite::apply(f1, boost::make_tuple(1)) == 1);
    REQUIRE(lite::apply(f2, boost::make_tuple(1, 2)) == 3);
    REQUIRE(lite::apply(f3, boost::make_tuple(1, 2, 3)) == 6);
    REQUIRE(lite::apply(f4, boost::make_tuple(1, 2, 3, 4)) == 10);
    REQUIRE(lite::apply(f5, boost::make_tuple(1, 2, 3, 4, 5)) == 15);
    REQUIRE(lite::apply(f6, boost::make_tuple(1, 2, 3, 4, 5, 6)) == 21);
    REQUIRE(lite::apply(f7, boost::make_tuple(1, 2, 3, 4, 5, 6, 7)) == 28);
    REQUIRE(lite::apply(f8, boost::make_tuple(1, 2, 3, 4, 5, 6, 7, 8)) == 36);
    REQUIRE(lite::apply(f9, boost::make_tuple(1, 2, 3, 4, 5, 6, 7, 8, 9)) == 45);
}

TEST_CASE("std::pair", "[lite::apply]")
{
    REQUIRE(lite::apply(f2, std::make_pair(1, 2)) == 3);
}

