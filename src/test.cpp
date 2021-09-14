#define CATCH_CONFIG_MAIN
#include <tuple>
#include <array>
#include <utility>
#include <type_traits>
#include <catch2/catch.hpp>
#include <msgpack.hpp>
#include <boost/tuple/tuple.hpp>
#include <apply.hpp>

int g_result;

int f1(int a)
{
    return a;
}

void g1(int& a)
{
    a = 0;
}

void h1(int a)
{
    g_result = a;
}

int f2(int a, int b)
{
    return a + b;
}

void g2(int& a, int b)
{
    a = b;
}

void h2(int a, int b)
{
    g_result = a + b;
}

int f3(int a, int b, int c)
{
    return a + b + c;
}

void g3(int& a, int b, int c)
{
    a = b + c;
}

void h3(int a, int b, int c)
{
    g_result = a + b + c;
}

int f4(int a, int b, int c, int d)
{
    return a + b + c + d;
}

void g4(int& a, int b, int c, int d)
{
    a = b + c + d;
}

void h4(int a, int b, int c, int d)
{
    g_result = a + b + c + d;
}

int f5(int a, int b, int c, int d, int e)
{
    return a + b + c + d + e;
}

void g5(int& a, int b, int c, int d, int e)
{
    a = b + c + d + e;
}

void h5(int a, int b, int c, int d, int e)
{
    g_result = a + b + c + d + e;
}

int f6(int a, int b, int c, int d, int e, int f)
{
    return a + b + c + d + e + f;
}

void g6(int& a, int b, int c, int d, int e, int f)
{
    a = b + c + d + e + f;
}

void h6(int a, int b, int c, int d, int e, int f)
{
    g_result = a + b + c + d + e + f;
}

int f7(int a, int b, int c, int d, int e, int f, int g)
{
    return a + b + c + d + e + f + g;
}

void g7(int& a, int b, int c, int d, int e, int f, int g)
{
    a = b + c + d + e + f + g;
}

void h7(int a, int b, int c, int d, int e, int f, int g)
{
    g_result = a + b + c + d + e + f + g;
}

int f8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return a + b + c + d + e + f + g + h;
}

void g8(int& a, int b, int c, int d, int e, int f, int g, int h)
{
    a = b + c + d + e + f + g + h;
}

void h8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    g_result = a + b + c + d + e + f + g + h;
}

int f9(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return a + b + c + d + e + f + g + h + i;
}

void g9(int& a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    a = b + c + d + e + f + g + h + i;
}

void h9(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    g_result = a + b + c + d + e + f + g + h + i;
}

int update(int& a, int& b)
{
    a += 1;
    b += 1;
    return 0;
}

void add1(int& a, int& b)
{
    a += 1;
    b += 1;
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
    int result = 100;
    lite::apply(g1, msgpack::type::tuple<int&>(result));
    REQUIRE(result == 0);
    lite::apply(g2, msgpack::type::tuple<int&, int>(result, 1));
    REQUIRE(result == 1);
    lite::apply(g3, msgpack::type::tuple<int&, int, int>(result, 1, 2));
    REQUIRE(result == 3);
    lite::apply(g4, msgpack::type::tuple<int&, int, int, int>(result, 1, 2, 3));
    REQUIRE(result == 6);
    lite::apply(g5, msgpack::type::tuple<int&, int, int, int, int>(result, 1, 2, 3, 4));
    REQUIRE(result == 10);
    lite::apply(g6, msgpack::type::tuple<int&, int, int, int, int, int>(result, 1, 2, 3, 4, 5));
    REQUIRE(result == 15);
    lite::apply(g7, msgpack::type::tuple<int&, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6));
    REQUIRE(result == 21);
    lite::apply(g8, msgpack::type::tuple<int&, int, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6, 7));
    REQUIRE(result == 28);
    lite::apply(g9, msgpack::type::tuple<int&, int, int, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(result == 36);
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
    int result = 100;
    lite::apply(g1, std::tuple<int&>(result));
    REQUIRE(result == 0);
    lite::apply(g2, std::tuple<int&, int>(result, 1));
    REQUIRE(result == 1);
    lite::apply(g3, std::tuple<int&, int, int>(result, 1, 2));
    REQUIRE(result == 3);
    lite::apply(g4, std::tuple<int&, int, int, int>(result, 1, 2, 3));
    REQUIRE(result == 6);
    lite::apply(g5, std::tuple<int&, int, int, int, int>(result, 1, 2, 3, 4));
    REQUIRE(result == 10);
    lite::apply(g6, std::tuple<int&, int, int, int, int, int>(result, 1, 2, 3, 4, 5));
    REQUIRE(result == 15);
    lite::apply(g7, std::tuple<int&, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6));
    REQUIRE(result == 21);
    lite::apply(g8, std::tuple<int&, int, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6, 7));
    REQUIRE(result == 28);
    lite::apply(g9, std::tuple<int&, int, int, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(result == 36);
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
    lite::apply(h1, a1);
    REQUIRE(g_result == 1);
    lite::apply(h2, a2);
    REQUIRE(g_result == 3);
    lite::apply(h3, a3);
    REQUIRE(g_result == 6);
    lite::apply(h4, a4);
    REQUIRE(g_result == 10);
    lite::apply(h5, a5);
    REQUIRE(g_result == 15);
    lite::apply(h6, a6);
    REQUIRE(g_result == 21);
    lite::apply(h7, a7);
    REQUIRE(g_result == 28);
    lite::apply(h8, a8);
    REQUIRE(g_result == 36);
    lite::apply(h9, a9);
    REQUIRE(g_result == 45);
}

TEST_CASE("boost::array", "[lite::apply]")
{
    boost::array<int, 1> a1{ 1 };
    REQUIRE(lite::apply(f1, a1) == 1);
    boost::array<int, 2> a2{ 1, 2 };
    REQUIRE(lite::apply(f2, a2) == 3);
    boost::array<int, 3> a3{ 1, 2, 3 };
    REQUIRE(lite::apply(f3, a3) == 6);
    boost::array<int, 4> a4{ 1, 2, 3, 4 };
    REQUIRE(lite::apply(f4, a4) == 10);
    boost::array<int, 5> a5{ 1, 2, 3, 4, 5 };
    REQUIRE(lite::apply(f5, a5) == 15);
    boost::array<int, 6> a6{ 1, 2, 3, 4, 5, 6 };
    REQUIRE(lite::apply(f6, a6) == 21);
    boost::array<int, 7> a7{ 1, 2, 3, 4, 5, 6, 7 };
    REQUIRE(lite::apply(f7, a7) == 28);
    boost::array<int, 8> a8{ 1, 2, 3, 4, 5, 6, 7, 8 };
    REQUIRE(lite::apply(f8, a8) == 36);
    boost::array<int, 9> a9{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    REQUIRE(lite::apply(f9, a9) == 45);
    lite::apply(h1, a1);
    REQUIRE(g_result == 1);
    lite::apply(h2, a2);
    REQUIRE(g_result == 3);
    lite::apply(h3, a3);
    REQUIRE(g_result == 6);
    lite::apply(h4, a4);
    REQUIRE(g_result == 10);
    lite::apply(h5, a5);
    REQUIRE(g_result == 15);
    lite::apply(h6, a6);
    REQUIRE(g_result == 21);
    lite::apply(h7, a7);
    REQUIRE(g_result == 28);
    lite::apply(h8, a8);
    REQUIRE(g_result == 36);
    lite::apply(h9, a9);
    REQUIRE(g_result == 45);
}

TEST_CASE("std::tuple mutable", "[lite::apply]")
{
    int a = 0;
    int b = 1;
    REQUIRE(lite::apply(update, std::tuple<int&, int&>(a, b)) == 0);
    REQUIRE(a == 1);
    REQUIRE(b == 2);
}
#endif

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

    boost::tuple<int> t1(1);
    REQUIRE(lite::apply(f1, t1) == 1);
    boost::tuple<int, int> t2(1, 2);
    REQUIRE(lite::apply(f2, t2) == 3);

    int result = 100;
    lite::apply(g1, boost::tuple<int&>(result));
    REQUIRE(result == 0);
    lite::apply(g2, boost::tuple<int&, int>(result, 1));
    REQUIRE(result == 1);
    lite::apply(g3, boost::tuple<int&, int, int>(result, 1, 2));
    REQUIRE(result == 3);
    lite::apply(g4, boost::tuple<int&, int, int, int>(result, 1, 2, 3));
    REQUIRE(result == 6);
    lite::apply(g5, boost::tuple<int&, int, int, int, int>(result, 1, 2, 3, 4));
    REQUIRE(result == 10);
    lite::apply(g6, boost::tuple<int&, int, int, int, int, int>(result, 1, 2, 3, 4, 5));
    REQUIRE(result == 15);
    lite::apply(g7, boost::tuple<int&, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6));
    REQUIRE(result == 21);
    lite::apply(g8, boost::tuple<int&, int, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6, 7));
    REQUIRE(result == 28);
    lite::apply(g9, boost::tuple<int&, int, int, int, int, int, int, int, int>(result, 1, 2, 3, 4, 5, 6, 7, 8));
    REQUIRE(result == 36);
}

TEST_CASE("std::pair", "[lite::apply]")
{
    REQUIRE(lite::apply(f2, std::make_pair(1, 2)) == 3);
}

TEST_CASE("boost::tuple mutable", "[lite::apply]")
{
    int a = 0;
    int b = 1;
    REQUIRE(lite::apply(update, boost::tuple<int&, int&>(a, b)) == 0);
    REQUIRE(a == 1);
    REQUIRE(b == 2);
}

TEST_CASE("msgpace::type::tuple mutable", "[lite::apply]")
{
    int a = 0;
    int b = 1;
    REQUIRE(lite::apply(update, msgpack::type::tuple<int&, int&>(a, b)) == 0);
    REQUIRE(a == 1);
    REQUIRE(b == 2);
}
