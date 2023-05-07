#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <arrayd/arrayd.hpp>

TEST_CASE("[arrayD] - ArrayD ctor") {
    CHECK(ArrayD() == ArrayD(0));
    CHECK_THROWS(ArrayD(-1));
    SUBCASE("Constructor with size") {
        ArrayD test{ 0, 0 };
        CHECK(test == ArrayD(2));
    }
    CHECK(ArrayD(ArrayD(2)) == ArrayD(2));
}

TEST_CASE("[arrayD] - ArrayD operator=") {
    SUBCASE("Simple") {
        ArrayD test;
        ArrayD test2(2);
        test = test2;
        CHECK(test.ssize() == 2);
    }
    SUBCASE("With data") {
        ArrayD test;
        ArrayD test2(2);
        test2[0] = 1;
        test2[1] = 2;
        test = test2;
        REQUIRE(test.ssize() == 2);
        bool equal = test[0] == 1 && test[1] == 2;
        CHECK(equal);
    }
    SUBCASE("Copy of yourself") {
        ArrayD test(2);
        CHECK_NOTHROW(test = test);
    }
}

TEST_CASE("[arrayD] - ArrayD insert") {
    SUBCASE("Simple") {
        ArrayD test(2);
        test.insert(1, 1);
        REQUIRE(test.ssize() == 3);
        CHECK((test[0] == 0 && test[1] == 1 && test[2] == 0));
    }
    SUBCASE("Negative index") {
        ArrayD test(2);
        CHECK_THROWS(test.insert(-1, 1));
    }
    SUBCASE("Index is larger than size") {
        ArrayD test(2);
        CHECK_THROWS(test.insert(3, 1));
    }
    SUBCASE("Many inserts") {
        ArrayD a(3);
        a.insert(2, 2);
        a.insert(0, 3);
        a.insert(1, -4);
        a.insert(6, 7);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayD{ 3, -4, 0, 2, 0, 7 });
        CHECK_THROWS(a[7]);
        CHECK_THROWS(a[-1]);
        CHECK_THROWS(a.insert(-1, 2));
        CHECK_THROWS(a.insert(8, 2));
        CHECK_THROWS(a.insert('b', 1));
        CHECK_THROWS(a.insert('b', 'a'));
    }
}

TEST_CASE("[arrayD] - ArrayD resize") {
    CHECK(ArrayD().ssize() == 0);
    SUBCASE("Simple") {
        ArrayD test;
        test.resize(2);
        CHECK(test == ArrayD(2));
    }
    SUBCASE("With auto init") {
        ArrayD a(3);
        a[1] = 3;
        a[2] = -5;
        a.resize(5);
        CHECK(a.ssize() == 5);
        CHECK(a == ArrayD{ 0, 3, -5, 0, 0 });
        CHECK_THROWS(a[5]);
        CHECK_THROWS(a.resize(0));
    }
}

TEST_CASE("[arrayd] - ArrayD push_back") {
    SUBCASE("Simple") {
        ArrayD a;
        a.push_back(1);
        a.push_back(2);
        CHECK(a.ssize() == 2);
        CHECK((a[0] == 1 && a[1] == 2));
        CHECK_THROWS(a[2]);
        CHECK_THROWS(a[-1]);
    }
    SUBCASE("not default") {
        ArrayD a(3);
        a.push_back(2);
        a.push_back(3);
        CHECK(a.ssize() == 5);
        CHECK(a == ArrayD{ 0, 0, 0, 2, 3 });
        CHECK_THROWS(a[5]);
        CHECK_THROWS(a[-1]);
    }
}

TEST_CASE("[arrayd] - ArrayD remove") {
    SUBCASE("Simple") {
        ArrayD a;
        CHECK_THROWS(a.remove(0));
        CHECK_THROWS(a.remove(2));
        CHECK_THROWS(a.remove(-1));
    }
    SUBCASE("Complex") {
        ArrayD a(3);
        a.insert(3, 2);
        a.insert(0, 3);
        a.insert(1, -4);
        a.insert(6, 7);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayD{ 3, -4, 0, 0, 2, 7 });
        a.remove(0);
        CHECK(a == ArrayD{ -4, 0, 0, 2, 7 });
    }
}
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
//
//#include <arrayd/arrayd.hpp>
//
//TEST_CASE("[arrayd] - ctor") {
//    SUBCASE("default") {
//        ArrayD a;
//        CHECK(a.ssize() == 0);
//        CHECK_THROWS(a[0]);
//    }
//    SUBCASE("ctor - size") {
//        ArrayD a(3);
//        CHECK(a.ssize() == 3);
//        CHECK(a[2] == 0.0);
//        CHECK(a[0] == 0.0);
//        CHECK_THROWS(a[-1]);
//        CHECK_THROWS(a[3]);
//    }
//    SUBCASE("ctor - copy") {
//        ArrayD a(3);
//        ArrayD b(a);
//        CHECK(b.ssize() == 3);
//        CHECK(b[2] == 0.0);
//        CHECK(b[0] == 0.0);
//        CHECK_THROWS(b[-1]);
//        CHECK_THROWS(b[3]);
//    }
//    
//}
//TEST_CASE("[arrayd] - operator=") {
//    ArrayD a(3);
//    a[2] = 3.2;
//    a[0] = 5.5;
//    ArrayD b = a;
//    CHECK(b.ssize() == 3);
//    CHECK(b[2] == 3.2);
//    CHECK(b[0] == 5.5);
//    CHECK_THROWS(b[-1]);
//    CHECK_THROWS(b[3]);
//}
//
//TEST_CASE("[arrayd] - push_back") {
//    SUBCASE("default") {
//        ArrayD a;
//        a.push_back(2.1);
//        a.push_back(3.3);
//        CHECK(a.ssize() == 2);
//        CHECK(a[0] == 2.1);
//        CHECK(a[1] == 3.3);
//        CHECK_THROWS(a[2]);
//        CHECK_THROWS(a[-1]);
//    }
//    SUBCASE("not default") {
//        ArrayD a(3);
//        a.push_back(2.1);
//        a.push_back(3.3);
//        CHECK(a.ssize() == 5);
//        CHECK(a[0] == 0.0);
//        CHECK(a[2] == 0.0);
//        CHECK(a[3] == 2.1);
//        CHECK(a[4] == 3.3);
//        CHECK_THROWS(a[5]);
//        CHECK_THROWS(a[-1]);
//    }
//}
//TEST_CASE("[arrayd] - insert") {
//    SUBCASE("default") {
//        ArrayD a;
//        a.insert(0, 2);
//        a.insert(0, 3);
//        a.insert(1, 4);
//        CHECK(a.ssize() == 3);
//        CHECK(a[0] == 3.0);
//        CHECK(a[1] == 4.0);
//        CHECK(a[2] == 2.0);
//        CHECK_THROWS(a[3]);
//        CHECK_THROWS(a[-1]);
//        CHECK_THROWS(a.insert(-1, 2));
//        CHECK_THROWS(a.insert(4, 2));
//    }
//    SUBCASE("not default") {
//        ArrayD a(3);
//        a.insert(3, 2);
//        a.insert(0, 3);
//        a.insert(1, -4.1);
//        a.insert(6, 7);
//        CHECK(a.ssize() == 7);
//        CHECK(a[0] == 3.0);
//        CHECK(a[1] == -4.1);
//        CHECK(a[2] == 0.0);
//        CHECK(a[4] == 0.0);
//        CHECK(a[5] == 2);
//        CHECK(a[6] == 7);
//        CHECK_THROWS(a[7]);
//        CHECK_THROWS(a[-1]);
//        CHECK_THROWS(a.insert(-1, 2));
//        CHECK_THROWS(a.insert(8, 2));
//        CHECK_THROWS(a.insert('b', 1));
//        CHECK_THROWS(a.insert('b', 'a'));
//    }
//}
//TEST_CASE("[arrayd] - remove") {
//    SUBCASE("default") {
//        ArrayD a;
//        CHECK_THROWS(a.remove(0));
//        CHECK_THROWS(a.remove(2));
//        CHECK_THROWS(a.remove(-1));
//    }
//    SUBCASE("not default") {
//        ArrayD a(3);
//        a.insert(3, 2);
//        a.insert(0, 3);
//        a.insert(1, -4.1);
//        a.insert(6, 7);
//        a.remove(2);
//        CHECK(a[0] == 3.0);
//        CHECK(a[1] == -4.1);
//        CHECK(a[2] == 0.0);
//        CHECK(a[3] == 0.0);
//        CHECK(a[4] == 2);
//        CHECK(a[5] == 7);
//        CHECK(a.ssize() == 6);
//        a.remove(0);
//        CHECK(a[0] == -4.1);
//        CHECK(a[1] == 0.0);
//        CHECK(a[2] == 0.0);
//        CHECK(a[3] == 2);
//        CHECK(a[4] == 7);
//        CHECK(a.ssize() == 5);
//        CHECK_THROWS(a.remove(5));
//        a.remove(4);
//        CHECK(a[0] == -4.1);
//        CHECK(a[1] == 0.0);
//        CHECK(a[2] == 0.0);
//        CHECK(a[3] == 2);
//        CHECK(a.ssize() == 4);
//        CHECK_THROWS(a[4]);
//        CHECK_THROWS(a[-1]);
//    }
//}
//TEST_CASE("[arrayd] - resize") {
//    SUBCASE("default") {
//        ArrayD a;
//        CHECK_THROWS(a.resize(-1));
//        a.resize(2);
//        CHECK(a.ssize() == 2);
//        CHECK(a[0] == 0.0);
//        CHECK(a[1] == 0.0);
//        CHECK_THROWS(a[2]);
//        CHECK_THROWS(a.resize(0));
//    }
//    SUBCASE("not default") {
//        ArrayD a(3);
//        a[1] = 3;
//        a[2] = -5.3;
//        a.resize(5);
//        CHECK(a.ssize() == 5);
//        CHECK(a[0] == 0.0);
//        CHECK(a[1] == 3);
//        CHECK(a[2] == -5.3);
//        CHECK(a[3] == 0.0);
//        CHECK(a[4] == 0.0);
//        CHECK_THROWS(a[5]);
//        a.resize(3);
//        CHECK(a.ssize() == 3);
//        CHECK(a[0] == 0.0);
//        CHECK(a[1] == 3);
//        CHECK(a[2] == -5.3);
//        a.resize(2);
//        CHECK(a.ssize() == 2);
//        CHECK(a[0] == 0.0);
//        CHECK(a[1] == 3);
//        CHECK_THROWS(a[2]);
//        a.resize(5);
//        CHECK(a[4] == 0);
//        CHECK(a[1] == 3);
//        CHECK(a[2] == 0);
//        a.resize(1);
//        CHECK(a[0] == 0.0);
//        CHECK_THROWS(a.resize(0));
//    }
//}

