#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <arrayt/arrayt.hpp>
//#include "../prj.lab/matrixs/include/matrixs/matrixs.hpp"
//#include "../prj.lab/rational/include/rational/rational.hpp"
//#include "../prj.lab/arrayd/include/arrayd/arrayd.hpp"


TEST_CASE("[arrayT] - ArrayT ctor") {
    SUBCASE("T = long double") {
        CHECK(ArrayT<long double>() == ArrayT<long double>(0));
        CHECK_THROWS(ArrayT<long double>(-1));
        SUBCASE("Constructor with size") {
            ArrayT<long double> test{ 0.0, 0.0 };
            CHECK(test == ArrayT<long double>(2));
        }
        CHECK(ArrayT<long double>(ArrayT<long double>(2)) == ArrayT<long double>(2));
    }

    SUBCASE("T = char") {
        CHECK(ArrayT<char>() == ArrayT<char>(0));
        CHECK_THROWS(ArrayT<char>(-1));
        SUBCASE("Constructor with size") {
            ArrayT<char> test{ 0, 0 };
            CHECK(test == ArrayT<char>(2));
        }
        CHECK(ArrayT<char>(ArrayT<char>(2)) == ArrayT<char>(2));
    }

    SUBCASE("T = unsigned long long") {
        CHECK(ArrayT<unsigned long long>() == ArrayT<unsigned long long>(0));
        CHECK_THROWS(ArrayT<unsigned long long>(-1));
        SUBCASE("Constructor with size") {
            ArrayT<unsigned long long> test{ 0, 0 };
            CHECK(test == ArrayT<unsigned long long>(2));
        }
        CHECK(ArrayT<unsigned long long>(ArrayT<unsigned long long>(2)) == ArrayT<unsigned long long>(2));
    }

    SUBCASE("T = string") {
        CHECK(ArrayT<std::string>() == ArrayT<std::string>(0));
        CHECK_THROWS(ArrayT<std::string>(-1));
        SUBCASE("Constructor with size") {
            ArrayT<std::string> test{ "", "" };
            CHECK(test == ArrayT<std::string>(2));
        }
        CHECK(ArrayT<std::string>(ArrayT<std::string>(2)) == ArrayT<std::string>(2));
    }

    SUBCASE("T = bool") {
        CHECK(ArrayT<bool>() == ArrayT<bool>(false));
        CHECK_THROWS(ArrayT<bool>(-1));
        SUBCASE("Constructor with size") {
            ArrayT<bool> test{ false, 0 };
            CHECK(test == ArrayT<bool>(2));
        }
        CHECK(ArrayT<bool>(ArrayT<bool>(2)) == ArrayT<bool>(2));
    }

    SUBCASE("T = std::vector<int>") {
        CHECK(ArrayT<std::vector<int>>() == ArrayT<std::vector<int>>(0));
        CHECK_THROWS(ArrayT<std::vector<int>>(-1));
        SUBCASE("Constructor with size") {
            ArrayT<std::vector<int>> test{ std::vector<int>(0), std::vector<int>(0)};
            CHECK(test == ArrayT<std::vector<int>>(2));
        }
        CHECK(ArrayT<std::vector<int>>(ArrayT<std::vector<int>>(2)) == ArrayT<std::vector<int>>(2));
    }

   /* SUBCASE("T = MatrixS") {
        CHECK(ArrayT<MatrixS>() == ArrayT<MatrixS>(0));
        CHECK_THROWS(ArrayT<MatrixS>(-1));
        SUBCASE("Constructor with size") {
            ArrayT<MatrixS> test{ {0, 0} };
            CHECK(test == ArrayT<MatrixS>(2));
        }
        CHECK(ArrayT<MatrixS>(ArrayT<MatrixS>(2)) == ArrayT<MatrixS>(2));
    }*/
}

TEST_CASE("[arrayT] - ArrayT operator=") {
    SUBCASE("Simple T = short") {
        ArrayT<short> test;
        CHECK(test.ssize() == 0);
        CHECK_THROWS(test[0]);
        ArrayT<short> test2(2);
        test = test2;
        CHECK(test.ssize() == 2);
        CHECK(test[0] == 0);
        CHECK(test[1] == 0);
        CHECK_THROWS(test[2]);
    }
    SUBCASE("Simple T = char") {
        ArrayT<char> test;
        CHECK(test.ssize() == 0);
        CHECK_THROWS(test[0]);
        ArrayT<char> test2(2);
        test = test2;
        CHECK(test.ssize() == 2);
        CHECK(test[0] == 0);
        CHECK(test[1] == 0);
        CHECK_THROWS(test[2]);
    }
    SUBCASE("Simple T = double") {
        ArrayT<double> test;
        CHECK(test.ssize() == 0);
        CHECK_THROWS(test[0]);
        ArrayT<double> test2(2);
        test = test2;
        CHECK(test.ssize() == 2);
        CHECK(test[0] == 0.0);
        CHECK(test[1] == 0.0);
        CHECK_THROWS(test[2]);
    }
    SUBCASE("Simple T = std::string") {
        ArrayT<std::string> test;
        CHECK(test.ssize() == 0);
        CHECK_THROWS(test[0]);
        ArrayT<std::string> test2(2);
        test = test2;
        CHECK(test.ssize() == 2);
        CHECK(test[0] == "");
        CHECK(test[1] == "");
        CHECK_THROWS(test[2]);
    }
    SUBCASE("Simple T = bool") {
        ArrayT<bool> test;
        CHECK(test.ssize() == 0);
        CHECK_THROWS(test[0]);
        ArrayT<bool> test2(3);
        test = test2;
        CHECK(test.ssize() == 3);
        CHECK(test[0] == false);
        CHECK(test[1] == 0);
        CHECK(test[2] == false);
        CHECK_THROWS(test[3]);
    }
    SUBCASE("Simple T = std::vector<std::string>") {
        ArrayT<std::vector<std::string>> test;
        CHECK(test.ssize() == 0);
        CHECK_THROWS(test[0]);
        ArrayT<std::vector<std::string>> test2(2);
        test = test2;
        CHECK(test.ssize() == 2);
        CHECK(test[0] == std::vector<std::string>(0));
        CHECK(test[1] == std::vector<std::string>(0));
        CHECK_THROWS(test[2]);
    }
    //SUBCASE("Simple T = Rational") {////////////////////////////////////////////
    //    ArrayT<Rational> test;
    //    CHECK(test.ssize() == 0);
    //    CHECK_THROWS(test[0]);
    //    ArrayT<Rational> test2(3);
    //    test = test2;
    //    CHECK(test.ssize() == 3);
    //    CHECK(test[0] == Rational(0, 2));
    //    CHECK(test[1] == Rational(0, 1));
    //    CHECK(test[2] == Rational(0, 3));
    //    CHECK_THROWS(test[3]);
    //}
    SUBCASE("With data T = long double") {
        ArrayT<long double> test;
        ArrayT<long double> test2(3);
        test2[0] = 1.71232312332;
        test2[2] = 4.5;
        test = test2;
        CHECK(test.ssize() == 3);
        CHECK(test[0] == 1.71232312332);
        CHECK(test[1] == 0);
        CHECK(test[2] == 4.5);
        CHECK(test2[0] == 1.71232312332);
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test2[3]);
        CHECK_THROWS(test[-1]);
        CHECK_THROWS(test2[-1]);
    }
    SUBCASE("With data T = unsigned long long") {
        ArrayT<unsigned long long> test;
        ArrayT<unsigned long long> test2(4);
        test2[0] = 2.3;
        test2[1] = 1;
        test2[2] = 4.5;
        test = test2;
        CHECK(test.ssize() == 4);
        CHECK(test[0] == 2);
        CHECK(test[1] == 1);
        CHECK(test[2] == 4);
        CHECK(test[3] == 0);
        CHECK(test2[0] == 2);
        CHECK(test2[1] == 1);
        CHECK(test2[2] == 4);
        CHECK(test2[3] == 0);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test2[4]);
        CHECK_THROWS(test[-1]);
        CHECK_THROWS(test2[-1]);
    }
    SUBCASE("With data T = char") {
        ArrayT<char> test;
        ArrayT<char> test2(4);
        test2[0] = '1';
        test2[1] = 'a';
        test2[2] = 'B';
        test = test2;
        CHECK(test.ssize() == 4);
        CHECK(test[0] == '1');
        CHECK(test[1] == 'a');
        CHECK(test[2] == 'B');
        CHECK(test[3] == 0);
        CHECK(test2[0] == '1');
        CHECK(test2[1] == 'a');
        CHECK(test2[2] == 'B');
        CHECK(test2[3] == 0);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test2[4]);
        CHECK_THROWS(test[-1]);
        CHECK_THROWS(test2[-1]);
    }
    SUBCASE("With data T = std::string") {
        ArrayT<std::string> test;
        ArrayT<std::string> test2(4);
        test2[0] = "asfdsadsdsasdsaddsasadsa";
        test2[1] = "1234";
        test2[3] = "w";
        test = test2;
        CHECK(test.ssize() == 4);
        CHECK(test[0] == "asfdsadsdsasdsaddsasadsa");
        CHECK(test[1] == "1234");
        CHECK(test[2] == "");
        CHECK(test[3] == "w");
        CHECK(test2[0] == "asfdsadsdsasdsaddsasadsa");
        CHECK(test2[1] == "1234");
        CHECK(test2[2] == "");
        CHECK(test2[3] == "w");
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test2[4]);
        CHECK_THROWS(test[-1]);
        CHECK_THROWS(test2[-1]);
    }
    SUBCASE("With data T = bool") {
        ArrayT<bool> test;
        ArrayT<bool> test2(7);
        test2[0] = false;
        test2[1] = true;
        test2[3] = false * true;
        test2[4] = false + true;
        test2[5] = 0;
        test2[6] = 1;
        test = test2;
        CHECK(test.ssize() == 7);
        CHECK(test[0] == 0);
        CHECK(test[1] == 1);
        CHECK(test[2] == false);
        CHECK(test[2] == 0);
        CHECK(test[3] == 0);
        CHECK(test[3] == false);
        CHECK(test[4] == 1);
        CHECK(test[4] == true);
        CHECK(test[5] == false);
        CHECK(test[6] == true);
        CHECK(test2[0] == 0);
        CHECK(test2[1] == 1);
        CHECK(test2[2] == false);
        CHECK(test2[2] == 0);
        CHECK(test2[3] == 0);
        CHECK(test2[3] == false);
        CHECK(test2[4] == 1);
        CHECK(test2[4] == true);
        CHECK(test2[5] == false);
        CHECK(test2[6] == true);
        CHECK_THROWS(test[8]);
        CHECK_THROWS(test2[8]);
        CHECK_THROWS(test[-1]);
        CHECK_THROWS(test2[-1]);
    }
    SUBCASE("With data T = std::vector<double>") {
        ArrayT<std::vector<double>> test;
        ArrayT<std::vector<double>> test2(3);
        test2[0] = { 1.71232312332, 4.6, 3.7 };
        test2[2] = { 4.5, 1.5, 0, 12 };
        test = test2;
        CHECK(test.ssize() == 3);
        CHECK(test[0] == std::vector<double>{ 1.71232312332, 4.6, 3.7 });
        CHECK(test[1] == std::vector<double>(0));
        CHECK(test[2] == std::vector<double>{ 4.5, 1.5, 0, 12 });
        CHECK(test2[0] == std::vector<double>{ 1.71232312332, 4.6, 3.7 });
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test2[3]);
        CHECK_THROWS(test[-1]);
        CHECK_THROWS(test2[-1]);
    }
    //SUBCASE("With data T = ArrayD") {/////////////////////
    //    ArrayT<ArrayD> test;
    //    ArrayT<ArrayD> test2(3);
    //    test2[0] = ArrayD{ 1.71232312332, 4.6, 3.7 };
    //    test2[2] = ArrayD{ 4.5, 1.5, 0, 12 };
    //    test = test2;
    //    CHECK(test.ssize() == 3);
    //    CHECK(test[0] == ArrayD{ 1.71232312332, 4.6, 3.7 });
    //    CHECK(test[1] == ArrayD(0));
    //    CHECK(test[2] == ArrayD{ 4.5, 1.5, 0, 12 });
    //    CHECK(test2[0] == ArrayD{ 1.71232312332, 4.6, 3.7 });
    //    CHECK_THROWS(test[3]);
    //    CHECK_THROWS(test2[3]);
    //    CHECK_THROWS(test[-1]);
    //    CHECK_THROWS(test2[-1]);
    //}
    SUBCASE("Copy of yourself T = double") {
        ArrayT<double> test(2);
        CHECK_NOTHROW(test = test);
    }
    SUBCASE("Copy of yourself T = char") {
        ArrayT<char> test(2);
        CHECK_NOTHROW(test = test);
    }
    SUBCASE("Copy of yourself T = string") {
        ArrayT<std::string> test(2);
        CHECK_NOTHROW(test = test);
    }
    SUBCASE("Copy of yourself T = bool") {
        ArrayT<bool> test(2);
        CHECK_NOTHROW(test = test);
    }
    SUBCASE("Copy of yourself T = long") {
        ArrayT<long> test(2);
        CHECK_NOTHROW(test = test);
    }
    SUBCASE("Copy of yourself T = std::vector<char>") {
        ArrayT< std::vector<char>> test(2);
        CHECK_NOTHROW(test = test);
    }
    //SUBCASE("Copy of yourself T = MatrixS") {////////////////
    //    ArrayT<MatrixS> test(2);
    //    CHECK_NOTHROW(test = test);
    //}
}

TEST_CASE("[arrayT] - ArrayT insert") {
    SUBCASE("Simple T = double") {
        ArrayT<double> test(2);
        test.insert(1, 1);
        CHECK(test.ssize() == 3);
        CHECK(test[0] == 0);
        CHECK(test[1] == 1);
        CHECK(test[2] == 0);
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test[-1]);
        test.insert(0, 1.7743);
        CHECK(test.ssize() == 4);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == 1.7743);
        CHECK(test[1] == 0);
        CHECK(test[2] == 1);
        CHECK(test[3] == 0);
        test.insert(4, 24512);
        CHECK(test.ssize() == 5);
        CHECK_THROWS(test[5]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == 1.7743);
        CHECK(test[1] == 0);
        CHECK(test[2] == 1);
        CHECK(test[3] == 0);
        CHECK(test[4] == 24512);
        CHECK_THROWS(test.insert(-1, 12.2));
        CHECK_THROWS(test.insert(6, 124.12));
        CHECK_THROWS(test.insert(1232, 124));
    }
    SUBCASE("Simple T = char") {
        ArrayT<char> test(2);
        test.insert(1, 'a');
        CHECK(test.ssize() == 3);
        CHECK(test[0] == 0);
        CHECK(test[1] == 'a');
        CHECK(test[2] == 0);
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test[-1]);
        test.insert(0, '5');
        CHECK(test.ssize() == 4);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == '5');
        CHECK(test[1] == 0);
        CHECK(test[2] == 'a');
        CHECK(test[3] == 0);
        test.insert(4, 0);
        CHECK(test.ssize() == 5);
        CHECK_THROWS(test[5]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == '5');
        CHECK(test[1] == 0);
        CHECK(test[2] == 'a');
        CHECK(test[3] == 0);
        CHECK(test[4] == 0);
        CHECK_THROWS(test.insert(-1, 12.2));
        CHECK_THROWS(test.insert(6, 124.12));
        CHECK_THROWS(test.insert(1232, 124));
    }
    SUBCASE("Simple T = std::string") {
        ArrayT<std::string> test(2);
        test.insert(1, "a");
        CHECK(test.ssize() == 3);
        CHECK(test[0] == "");
        CHECK(test[1] == "a");
        CHECK(test[2] == "");
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test[-1]);
        test.insert(0, "1.77432asdsdasadssaddsa");
        CHECK(test.ssize() == 4);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == "1.77432asdsdasadssaddsa");
        CHECK(test[1] == "");
        CHECK(test[2] == "a");
        CHECK(test[3] == "");
        test.insert(4, "1");
        CHECK(test.ssize() == 5);
        CHECK_THROWS(test[5]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == "1.77432asdsdasadssaddsa");
        CHECK(test[1] == "");
        CHECK(test[2] == "a");
        CHECK(test[3] == "");
        CHECK(test[4] == "1");
        CHECK_THROWS(test.insert(-1, "12"));
        CHECK_THROWS(test.insert(6, "124"));
        CHECK_THROWS(test.insert(1232, "qwerty"));
    }
    SUBCASE("Simple T = BOOM(L)") {
        ArrayT<bool> test(2);
        test.insert(1, true);
        CHECK(test.ssize() == 3);
        CHECK(test[0] == 0);
        CHECK(test[1] == true);
        CHECK(test[2] == 0);
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test[-1]);
        test.insert(0, false);
        CHECK(test.ssize() == 4);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == false);
        CHECK(test[1] == 0);
        CHECK(test[2] == 1);
        CHECK(test[3] == 0);
        test.insert(4, 0);
        CHECK(test.ssize() == 5);
        CHECK_THROWS(test[5]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == 0);
        CHECK(test[1] == 0);
        CHECK(test[2] == true);
        CHECK(test[3] == 0);
        CHECK(test[4] == false);
        CHECK_THROWS(test.insert(-1, false));
        CHECK_THROWS(test.insert(6, false));
        CHECK_THROWS(test.insert(1232, true));
    }
    SUBCASE("Simple T = int") {
        ArrayT<int> test(2);
        test.insert(1, 1);
        CHECK(test.ssize() == 3);
        CHECK(test[0] == 0);
        CHECK(test[1] == 1);
        CHECK(test[2] == 0);
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test[-1]);
        test.insert(0, 1.7743);
        CHECK(test.ssize() == 4);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == 1);
        CHECK(test[1] == 0);
        CHECK(test[2] == 1);
        CHECK(test[3] == 0);
        test.insert(4, 24512);
        CHECK(test.ssize() == 5);
        CHECK_THROWS(test[5]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == 1);
        CHECK(test[1] == 0);
        CHECK(test[2] == 1);
        CHECK(test[3] == 0);
        CHECK(test[4] == 24512);
        CHECK_THROWS(test.insert(-1, 12.2));
        CHECK_THROWS(test.insert(6, 124));
        CHECK_THROWS(test.insert(1232, 124));
    }
    SUBCASE("Simple T = std::vector<std::string>") {
        ArrayT<std::vector<std::string>> test(2);
        test.insert(1, std::vector<std::string>{"1234", "LEVELUPLEVELUPLEVELUP"});
        CHECK(test.ssize() == 3);
        CHECK(test[0] == std::vector<std::string>(0));
        CHECK(test[1] == std::vector<std::string>{"1234", "LEVELUPLEVELUPLEVELUP"});
        CHECK(test[2] == std::vector<std::string>(0));
        CHECK_THROWS(test[3]);
        CHECK_THROWS(test[-1]);
        test.insert(0, std::vector<std::string>{"hihi", "hihihi", "HAHAHA"});
        CHECK(test.ssize() == 4);
        CHECK_THROWS(test[4]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == std::vector<std::string>{"hihi", "hihihi", "HAHAHA"});
        CHECK(test[1] == std::vector<std::string>(0));
        CHECK(test[2] == std::vector<std::string>{"1234", "LEVELUPLEVELUPLEVELUP"});
        CHECK(test[3] == std::vector<std::string>(0));
        test.insert(4, std::vector<std::string>{"STD::SET :)"});
        CHECK(test.ssize() == 5);
        CHECK_THROWS(test[5]);
        CHECK_THROWS(test[-1]);
        CHECK(test[0] == std::vector<std::string>{"hihi", "hihihi", "HAHAHA"});
        CHECK(test[1] == std::vector<std::string>(0));
        CHECK(test[2] == std::vector<std::string>{"1234", "LEVELUPLEVELUPLEVELUP"});
        CHECK(test[3] == std::vector<std::string>(0));
        CHECK(test[4] == std::vector<std::string>{"STD::SET :)"});
        CHECK_THROWS(test.insert(-1, std::vector<std::string>{"hihi", "hihihi", "HAHAHA"}));
        CHECK_THROWS(test.insert(6, std::vector<std::string>{"hihi", "hihihi", "HAHAHA"}));
        CHECK_THROWS(test.insert(1232, std::vector<std::string>{"hihi", "hihihi", "HAHAHA"}));
    }
    //SUBCASE("Simple T = Rational") {/////////////////////////////////////////////////
    //    ArrayT<Rational> test(2);
    //    test.insert(1, 1/3);
    //    CHECK(test.ssize() == 3);
    //    CHECK(test[0] == Rational(0/1));
    //    CHECK(test[1] == Rational(1/3));
    //    CHECK(test[2] == Rational(0/1));
    //    CHECK_THROWS(test[3]);
    //    CHECK_THROWS(test[-1]);
    //    test.insert(0, Rational(2/50));
    //    CHECK(test.ssize() == 4);
    //    CHECK_THROWS(test[4]);
    //    CHECK_THROWS(test[-1]);
    //    CHECK(test[0] == Rational(1/25));
    //    CHECK(test[1] == Rational(0 / 1));
    //    CHECK(test[2] == Rational(1 / 3));
    //    CHECK(test[3] == Rational(0 / 1));
    //    test.insert(4, Rational(24512, -2));
    //    CHECK(test.ssize() == 5);
    //    CHECK_THROWS(test[5]);
    //    CHECK_THROWS(test[-1]);
    //    CHECK(test[0] == Rational(1 / 25));
    //    CHECK(test[1] == Rational(0 / 1));
    //    CHECK(test[2] == Rational(1 / 3));
    //    CHECK(test[3] == Rational(0 / 1));
    //    CHECK(test[4] == Rational(-12256, 1));
    //    CHECK_THROWS(test.insert(-1, Rational(0 / 1)));
    //    CHECK_THROWS(test.insert(6, Rational(0 / 1)));
    //    CHECK_THROWS(test.insert(1232, Rational(0 / 1)));
    //}

    SUBCASE("Many inserts T = double") {
        ArrayT<double> a(3);
        a.insert(2, 2.3);
        a.insert(0, 3.7);
        a.insert(1, -4);
        a.insert(6, 7);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<double>{ 3.7, -4, 0, 2.3, 0, 7 });
        CHECK_THROWS(a[7]);
        CHECK_THROWS(a[-1]);
        CHECK_THROWS(a.insert(-1, 2));
        CHECK_THROWS(a.insert(8, 2));
        CHECK_THROWS(a.insert('b', 1));
        CHECK_THROWS(a.insert('b', 'a'));
    }
    //SUBCASE("Many inserts T = MatrixS") {////////////////////////////////////////
    //    ArrayT<MatrixS> a(3);
    //    a.insert(2, MatrixS(2,3));
    //    a.insert(0, MatrixS(3, 3));
    //    a.insert(1, MatrixS(100, 3));
    //    a.insert(6, MatrixS(123, 5));
    //    a.remove(2);
    //    CHECK(a.ssize() == 6);
    //    CHECK(a == ArrayT<MatrixS>{ MatrixS(3, 3), MatrixS(100, 3), MatrixS(0, 0), MatrixS(2, 3), MatrixS(0, 0), MatrixS(123, 5) });
    //    CHECK_THROWS(a[7]);
    //    CHECK_THROWS(a[-1]);
    //    CHECK_THROWS(a.insert(-1, MatrixS(123, 5)));
    //    CHECK_THROWS(a.insert(8, MatrixS(123, 5)));
    //    CHECK_THROWS(a.insert('b', MatrixS(123, 5)));
    //    CHECK_THROWS(a.insert('b', MatrixS(123, 5)));
    //}
    SUBCASE("Many inserts T = std::vector<long>") {
        ArrayT<std::vector<long>> a(3);
        a.insert(2, std::vector<long>{1234, 2345, 3456, 0});
        a.insert(0, std::vector<long>{124, 345, 456, 100});
        a.insert(1, std::vector<long>{-124, 345, -6456, 1234100});
        a.insert(6, std::vector<long>{-124, 345, 345, -124});
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<std::vector<long>>{ std::vector<long>{124, 345, 456, 100}, std::vector<long>{-124, 345, -6456, 1234100}, std::vector<long>(0), std::vector<long>{1234, 2345, 3456, 0}, std::vector<long>(0), std::vector<long>{-124, 345, 345, -124} });
        CHECK_THROWS(a[7]);
        CHECK_THROWS(a[-1]);
        CHECK_THROWS(a.insert(-1, std::vector<long>(0)));
        CHECK_THROWS(a.insert(8, std::vector<long>(0)));
        CHECK_THROWS(a.insert('b', std::vector<long>(0)));
        CHECK_THROWS(a.insert('b', std::vector<long>(0)));
    }
    SUBCASE("Many inserts T = int") {
        ArrayT<int> a(3);
        a.insert(2, 2.3);
        a.insert(0, 3.7);
        a.insert(1, -4);
        a.insert(6, 7);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<int>{ 3, -4, 0, 2, 0, 7 });
        CHECK_THROWS(a[7]);
        CHECK_THROWS(a[-1]);
        CHECK_THROWS(a.insert(-1, 2));
        CHECK_THROWS(a.insert(8, 2));
        CHECK_THROWS(a.insert('b', 1));
        CHECK_THROWS(a.insert('b', 'a'));
    }

    SUBCASE("Many inserts T = std::string") {
        ArrayT<std::string> a(3);
        a.insert(2, "2.3");
        a.insert(0, "abbbbc)");
        a.insert(1, "AXAXAXXAXAXAXAXAXAXAAXXAAXXAXAXAAXAXXAXAXAXAXA");
        a.insert(6, "1");
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<std::string>{ "abbbbc)", "AXAXAXXAXAXAXAXAXAXAAXXAAXXAXAXAAXAXXAXAXAXAXA", "", "2.3", "", "1" });
        CHECK_THROWS(a[7]);
        CHECK_THROWS(a[-1]);
        CHECK_THROWS(a.insert(-1, "2"));
        CHECK_THROWS(a.insert(8, "2"));
        CHECK_THROWS(a.insert('b', "1"));
        CHECK_THROWS(a.insert('b', "a"));
    }
    SUBCASE("Many inserts T = char") {
        ArrayT<char> a(3);
        a.insert(2, 'b');
        a.insert(0, '3');
        a.insert(1, 'X');
        a.insert(6, ',');
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<char>{ '3', 'X', 0, 'b', 0, ',' });
        CHECK_THROWS(a[7]);
        CHECK_THROWS(a[-1]);
        CHECK_THROWS(a.insert(-1, 0));
        CHECK_THROWS(a.insert(8, '1'));
        CHECK_THROWS(a.insert('b', 't'));
        CHECK_THROWS(a.insert('b', 'a'));
    }
    SUBCASE("Many inserts T = bool") {
        ArrayT<bool> a(3);
        a.insert(2, 1);
        a.insert(0, true);
        a.insert(1, 0);
        a.insert(6, true);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<bool>{ true, false, false, true, false, true });
        CHECK_THROWS(a[7]);
        CHECK_THROWS(a[-1]);
        CHECK_THROWS(a.insert(-1, true));
        CHECK_THROWS(a.insert(8, false));
        CHECK_THROWS(a.insert('b', false));
        CHECK_THROWS(a.insert('b', true));
    }
    
}

TEST_CASE("[arrayT] - ArrayT resize") {
    SUBCASE("T = double") {
        CHECK(ArrayT<double>().ssize() == 0);
        SUBCASE("Simple") {
            ArrayT<double> test;
            test.resize(2);
            CHECK(test.ssize() == 2);
            CHECK(test[0] == 0.0);
            CHECK(test[1] == 0.0);
            CHECK_THROWS(test.resize(0));
            CHECK_THROWS(test.resize(-1));
            CHECK_THROWS(test[2]);
            CHECK_THROWS(test[-1]);
            
            CHECK(test == ArrayT<double>(2));
        }
        SUBCASE("With auto init") {
            ArrayT<double> a(3);
            a[1] = 3;
            a[2] = -5.7;
            a.resize(5);
            CHECK(a.ssize() == 5);
            CHECK(a == ArrayT<double>{ 0.0, 3.0, -5.7, 0.0, 0 });
            CHECK_THROWS(a[5]);
            CHECK_THROWS(a.resize(0));
            a.resize(3);
            CHECK(a == ArrayT<double>{0.0, 3.0, -5.7});
            CHECK(a.ssize() == 3);
            CHECK_THROWS(a[3]);
            a.resize(2);
            CHECK(a == ArrayT<double>{0.0, 3.0});
            CHECK(a.ssize() == 2);
            CHECK_THROWS(a[2]);
            a.resize(7);
            CHECK(a == ArrayT<double>{0.0, 3.0, 0, 0, 0, 0, 0});
            CHECK(a.ssize() == 7);
            CHECK_THROWS(a[7]);
        }
    }
    //SUBCASE("T = ArrayD") {//////////////////////////////////////////////////////////////////////////////
    //    CHECK(ArrayT<ArrayD>().ssize() == 0);
    //    SUBCASE("Simple") {
    //        ArrayT<ArrayD> test;
    //        test.resize(2);
    //        CHECK(test.ssize() == 2);
    //        CHECK(test[0] == ArrayD(0));
    //        CHECK(test[1] == ArrayD(0));
    //        CHECK_THROWS(test.resize(0));
    //        CHECK_THROWS(test.resize(-1));
    //        CHECK_THROWS(test[2]);
    //        CHECK_THROWS(test[-1]);

    //        CHECK(test == ArrayT<ArrayD>(2));
    //    }
    //    SUBCASE("With auto init") {
    //        ArrayT<ArrayD> a(3);
    //        a[1] = ArrayD{1,3};
    //        a[2] = ArrayD{ 1, 134, 234 };
    //        a.resize(5);
    //        CHECK(a.ssize() == 5);
    //        CHECK(a == ArrayT<ArrayD>{ ArrayD(0), ArrayD{1,3}, ArrayD{1, 134, 234}, ArrayD(0), ArrayD(0) });
    //        CHECK_THROWS(a[5]);
    //        CHECK_THROWS(a.resize(0));
    //        a.resize(3);
    //        CHECK(a == ArrayT<ArrayD>{ ArrayD(0), ArrayD{ 1,3 }, ArrayD{ 1, 134, 234 }});
    //        CHECK(a.ssize() == 3);
    //        CHECK_THROWS(a[3]);
    //        a.resize(2);
    //        CHECK(a == ArrayT<ArrayD>{ArrayD(0), ArrayD{ 1,3 }});
    //        CHECK(a.ssize() == 2);
    //        CHECK_THROWS(a[2]);
    //        a.resize(7);
    //        CHECK(a == ArrayT<ArrayD>{ArrayD(0), ArrayD{ 1,3 }, ArrayD(0), ArrayD(0), ArrayD(0), ArrayD(0), ArrayD(0)});
    //        CHECK(a.ssize() == 7);
    //        CHECK_THROWS(a[7]);
    //    }
    //}
    SUBCASE("T = std::pair<int, double>") {
        CHECK(ArrayT<std::pair<int, double>>().ssize() == 0);
        SUBCASE("Simple") {
            ArrayT<std::pair<int, double>> test;
            test.resize(2);
            CHECK(test.ssize() == 2);
            CHECK(test[0] == std::pair<int, double>{0, 0.0});
            CHECK(test[1] == std::pair<int, double>{0, 0.0});
            CHECK_THROWS(test.resize(0));
            CHECK_THROWS(test.resize(-1));
            CHECK_THROWS(test[2]);
            CHECK_THROWS(test[-1]);

            CHECK(test == ArrayT<std::pair<int, double>>(2));
        }
        SUBCASE("With auto init") {
            ArrayT<std::pair<int, double>> a(3);
            a[1] = { 3, 5.7 };
            a[2] = { 1243,-5.7 };
            a.resize(5);
            CHECK(a.ssize() == 5);
            CHECK(a == ArrayT<std::pair<int, double>>{ {0, 0.0}, { 3, 5.7 }, { 1243,-5.7 }, { 0, 0.0 }, { 0, 0.0 } });
            CHECK_THROWS(a[5]);
            CHECK_THROWS(a.resize(0));
            a.resize(3);
            CHECK(a == ArrayT<std::pair<int, double>>{ {0, 0.0}, { 3, 5.7 }, { 1243,-5.7 }});
            CHECK(a.ssize() == 3);
            CHECK_THROWS(a[3]);
            a.resize(2);
            CHECK(a == ArrayT<std::pair<int, double>>{ {0, 0.0}, { 3, 5.7 }});
            CHECK(a.ssize() == 2);
            CHECK_THROWS(a[2]);
            a.resize(7);
            CHECK(a == ArrayT<std::pair<int, double>>{ {0, 0.0}, { 3, 5.7 }, { 0, 0.0 }, { 0, 0.0 }, { 0, 0.0 }, { 0, 0.0 }, { 0, 0.0 }});
            CHECK(a.ssize() == 7);
            CHECK_THROWS(a[7]);
        }
    }
    SUBCASE("T = char") {
        CHECK(ArrayT<char>().ssize() == 0);
        SUBCASE("Simple") {
            ArrayT<char> test;
            test.resize(2);
            CHECK(test.ssize() == 2);
            CHECK(test[0] == 0);
            CHECK(test[1] == 0);
            CHECK_THROWS(test.resize(0));
            CHECK_THROWS(test.resize(-1));
            CHECK_THROWS(test[2]);
            CHECK_THROWS(test[-1]);

            CHECK(test == ArrayT<char>(2));
        }
        SUBCASE("With auto init") {
            ArrayT<char> a(3);
            a[1] = '1';
            a[2] = 'a';
            a.resize(5);
            CHECK(a.ssize() == 5);
            CHECK(a == ArrayT<char>{ 0, '1', 'a', 0, 0 });
            CHECK_THROWS(a[5]);
            CHECK_THROWS(a.resize(0));
            a.resize(3);
            CHECK(a == ArrayT<char>{0, '1', 'a'});
            CHECK(a.ssize() == 3);
            CHECK_THROWS(a[3]);
            a.resize(2);
            CHECK(a == ArrayT<char>{0, '1'});
            CHECK(a.ssize() == 2);
            CHECK_THROWS(a[2]);
            a.resize(7);
            CHECK(a == ArrayT<char>{0, '1', 0, 0, 0, 0, 0});
            CHECK(a.ssize() == 7);
            CHECK_THROWS(a[7]);
        }
    }
    SUBCASE("T = int") {
        CHECK(ArrayT<int>().ssize() == 0);
        SUBCASE("Simple") {
            ArrayT<int> test;
            test.resize(2);
            CHECK(test.ssize() == 2);
            CHECK(test[0] == 0);
            CHECK(test[1] == 0);
            CHECK_THROWS(test.resize(0));
            CHECK_THROWS(test.resize(-1));
            CHECK_THROWS(test[2]);
            CHECK_THROWS(test[-1]);

            CHECK(test == ArrayT<int>(2));
        }
        SUBCASE("With auto init") {
            ArrayT<int> a(3);
            a[1] = 3;
            a[2] = -5.7;
            a[0] = 1.9;
            a.resize(5);
            CHECK(a.ssize() == 5);
            CHECK(a == ArrayT<int>{ 1, 3, -5, 0, 0 });
            CHECK_THROWS(a[5]);
            CHECK_THROWS(a.resize(0));
            a.resize(3);
            CHECK(a == ArrayT<int>{1, 3, -5});
            CHECK(a.ssize() == 3);
            CHECK_THROWS(a[3]);
            a.resize(2);
            CHECK(a == ArrayT<int>{1, 3});
            CHECK(a.ssize() == 2);
            CHECK_THROWS(a[2]);
            a.resize(7);
            CHECK(a == ArrayT<int>{1, 3, 0, 0, 0, 0, 0});
            CHECK(a.ssize() == 7);
            CHECK_THROWS(a[7]);
        }
    }
    SUBCASE("T = std::string") {
        CHECK(ArrayT<std::string>().ssize() == 0);
        SUBCASE("Simple") {
            ArrayT<std::string> test;
            test.resize(2);
            CHECK(test.ssize() == 2);
            CHECK(test[0] == "");
            CHECK(test[1] == "");
            CHECK_THROWS(test.resize(0));
            CHECK_THROWS(test.resize(-1));
            CHECK_THROWS(test[2]);
            CHECK_THROWS(test[-1]);

            CHECK(test == ArrayT<std::string>(2));
        }
        SUBCASE("With auto init") {
            ArrayT<std::string> a(3);
            a[1] = "Asssssemblerrrrrrrrrrrrr";
            a[2] = "a";
            a[0] = "1234";
            a.resize(5);
            CHECK(a.ssize() == 5);
            CHECK(a == ArrayT<std::string>{ "1234", "Asssssemblerrrrrrrrrrrrr", "a", "", "" });
            CHECK_THROWS(a[5]);
            CHECK_THROWS(a.resize(0));
            a.resize(3);
            CHECK(a == ArrayT<std::string>{"1234", "Asssssemblerrrrrrrrrrrrr", "a"});
            CHECK(a.ssize() == 3);
            CHECK_THROWS(a[3]);
            a.resize(2);
            CHECK(a == ArrayT<std::string>{"1234", "Asssssemblerrrrrrrrrrrrr"});
            CHECK(a.ssize() == 2);
            CHECK_THROWS(a[2]);
            a.resize(7);
            CHECK(a == ArrayT<std::string>{"1234", "Asssssemblerrrrrrrrrrrrr", "", "", "", "", ""});
            CHECK(a.ssize() == 7);
            CHECK_THROWS(a[7]);
        }
    }
    SUBCASE("T = bool") {
        CHECK(ArrayT<bool>().ssize() == 0);
        SUBCASE("Simple") {
            ArrayT<bool> test;
            test.resize(2);
            CHECK(test.ssize() == 2);
            CHECK(test[0] == false);
            CHECK(test[1] == 0);
            CHECK_THROWS(test.resize(0));
            CHECK_THROWS(test.resize(-1));
            CHECK_THROWS(test[2]);
            CHECK_THROWS(test[-1]);

            CHECK(test == ArrayT<bool>(2));
        }
        SUBCASE("With auto init") {
            ArrayT<bool> a(4);
            a[1] = true;
            a[2] = 1;
            a[0] = 0;
            a[3] = false;
            a.resize(5);
            CHECK(a.ssize() == 5);
            CHECK(a == ArrayT<bool>{ false, 1, true, 0, false });
            CHECK_THROWS(a[5]);
            CHECK_THROWS(a.resize(0));
            a.resize(3);
            CHECK(a == ArrayT<bool>{0, true, 1});
            CHECK(a.ssize() == 3);
            CHECK_THROWS(a[3]);
            a.resize(2);
            CHECK(a == ArrayT<bool>{false, 1});
            CHECK(a.ssize() == 2);
            CHECK_THROWS(a[2]);
            a.resize(7);
            CHECK(a == ArrayT<bool>{0, true, 0, false, false, 0, false});
            CHECK(a.ssize() == 7);
            CHECK_THROWS(a[7]);
        }
    }
}

TEST_CASE("[arrayt(d)] - ArrayT(D) push_back (ladno)") {
    SUBCASE("Simple") {
        ArrayT<double> a;
        a.push_back(1);
        a.push_back(2);
        CHECK(a.ssize() == 2);
        CHECK(a[0] == 1);
        CHECK(a[1] == 2);
        CHECK_THROWS(a[2]);
        CHECK_THROWS(a[-1]);
    }
    SUBCASE("not default") {
        ArrayT<double> a(3);
        a.push_back(2);
        a.push_back(3);
        CHECK(a.ssize() == 5);
        CHECK(a == ArrayT<double>{ 0, 0, 0, 2, 3 });
        CHECK_THROWS(a[5]);
        CHECK_THROWS(a[-1]);
    }
}

TEST_CASE("[arrayt] - ArrayT remove") {
    SUBCASE("Simple T = double") {
        ArrayT<double> a;
        CHECK_THROWS(a.remove(0));
        CHECK_THROWS(a.remove(2));
        CHECK_THROWS(a.remove(-1));
    }
    SUBCASE("Simple T = std::tuple<int, bool, std::string>") {
        ArrayT<std::tuple<int, bool, std::string>> a;
        CHECK_THROWS(a.remove(0));
        CHECK_THROWS(a.remove(2));
        CHECK_THROWS(a.remove(-1));
    }
    //SUBCASE("Simple T = MatrixS") {/////////////////////////
    //    ArrayT<MatrixS> a;
    //    CHECK_THROWS(a.remove(0));
    //    CHECK_THROWS(a.remove(2));
    //    CHECK_THROWS(a.remove(-1));
    //}
    SUBCASE("Simple T = std::string") {
        ArrayT<std::string> a;
        CHECK_THROWS(a.remove(0));
        CHECK_THROWS(a.remove(2));
        CHECK_THROWS(a.remove(-1));
    }
    SUBCASE("Simple T = int") {
        ArrayT<int> a;
        CHECK_THROWS(a.remove(0));
        CHECK_THROWS(a.remove(2));
        CHECK_THROWS(a.remove(-1));
    }
    SUBCASE("Simple T = char") {
        ArrayT<char> a;
        CHECK_THROWS(a.remove(0));
        CHECK_THROWS(a.remove(2));
        CHECK_THROWS(a.remove(-1));
    }
    SUBCASE("Simple T = bool") {
        ArrayT<bool> a;
        CHECK_THROWS(a.remove(0));
        CHECK_THROWS(a.remove(2));
        CHECK_THROWS(a.remove(-1));
    }
    SUBCASE("Complex T = double") {
        ArrayT<double> a(3);
        a.insert(3, 2.6);
        a.insert(0, 3.3);
        a.insert(1, -4);
        a.insert(6, 7.1234);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<double>{ 3.3, -4, 0.0, 0, 2.6, 7.1234 });
        a.remove(0);
        CHECK(a == ArrayT<double>{ -4, 0, 0.0, 2.6, 7.1234 });
        a.remove(4);
        CHECK(a == ArrayT<double>{ -4, 0, 0.0, 2.6});
        a.remove(1);
        CHECK(a == ArrayT<double>{ -4, 0.0, 2.6});
        a.remove(0);
        CHECK(a == ArrayT<double>{0.0, 2.6});
        CHECK_THROWS(a.remove(2));
    }
    //SUBCASE("Complex T = MatrixS") {///////////////////////////////////////////////////////////
    //    ArrayT<MatrixS> a(3);
    //    a.insert(3, MatrixS(0, 0));
    //    a.insert(0, MatrixS(2, 1));
    //    a.insert(1, MatrixS(4, 4));
    //    a.insert(6, MatrixS(3, 5));
    //    a.remove(2);
    //    CHECK(a.ssize() == 6);
    //    CHECK(a == ArrayT<MatrixS>{ MatrixS(2, 1), MatrixS(4, 4), MatrixS(0, 0), MatrixS(0, 0), MatrixS(0, 0), MatrixS(3, 5) });
    //    a.remove(0);
    //    CHECK(a == ArrayT<MatrixS>{ MatrixS(4, 4), MatrixS(0, 0), MatrixS(0, 0), MatrixS(0, 0), MatrixS(3, 5) });
    //    a.remove(4);
    //    CHECK(a == ArrayT<MatrixS>{ MatrixS(4, 4), MatrixS(0, 0), MatrixS(0, 0), MatrixS(0, 0)});
    //    a.remove(1);
    //    CHECK(a == ArrayT<MatrixS>{ MatrixS(4, 4), MatrixS(0, 0), MatrixS(0, 0)});
    //    a.remove(0);
    //    CHECK(a == ArrayT<MatrixS>{MatrixS(0, 0), MatrixS(0, 0)});
    //    CHECK_THROWS(a.remove(2));
    //}
    SUBCASE("Complex T = int") {
        ArrayT<int> a(3);
        a.insert(3, 2.6);
        a.insert(0, 3.3);
        a.insert(1, -4);
        a.insert(6, 7.1234);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<int>{ 3, -4, 0, 0, 2, 7 });
        a.remove(0);
        CHECK(a == ArrayT<int>{ -4, 0, 0, 2, 7 });
        a.remove(4);
        CHECK(a == ArrayT<int>{ -4, 0, 0, 2});
        a.remove(1);
        CHECK(a == ArrayT<int>{ -4, 0, 2});
        a.remove(0);
        CHECK(a == ArrayT<int>{0, 2});
        CHECK_THROWS(a.remove(2));
    }
    SUBCASE("Complex T = char") {
        ArrayT<char> a(3);
        a.insert(3, '1');
        a.insert(0, 'a');
        a.insert(1, 'B');
        a.insert(6, ',');
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<char>{ 'a', 'B', 0, 0, '1', ',' });
        a.remove(0);
        CHECK(a == ArrayT<char>{ 'B', 0, 0, '1', ','});
        a.remove(4);
        CHECK(a == ArrayT<char>{ 'B', 0, 0, '1'});
        a.remove(1);
        CHECK(a == ArrayT<char>{ 'B', 0, '1'});
        a.remove(0);
        CHECK(a == ArrayT<char>{0, '1'});
        CHECK_THROWS(a.remove(2));
    }
    SUBCASE("Complex T = bool") {
        ArrayT<bool> a(3);
        a.insert(3, 1);
        a.insert(0, true);
        a.insert(1, 0);
        a.insert(6, false);
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<bool>{ 1, false, false, 0, true, false });
        a.remove(0);
        CHECK(a == ArrayT<bool>{ false, false, false, true, false});
        a.remove(4);
        CHECK(a == ArrayT<bool>{ 0, 0, false, true});
        a.remove(1);
        CHECK(a == ArrayT<bool>{ 0, false, true});
        a.remove(0);
        CHECK(a == ArrayT<bool>{0, 1});
        CHECK_THROWS(a.remove(2));
    }
    SUBCASE("Complex T = std::string") {
        ArrayT<std::string> a(3);
        a.insert(3, "URAAAA");
        a.insert(0, "ArrayTrashTest");
        a.insert(1, "Have been");
        a.insert(6, "Completed");
        a.remove(2);
        CHECK(a.ssize() == 6);
        CHECK(a == ArrayT<std::string>{ "ArrayTrashTest", "Have been", "", "", "URAAAA", "Completed"});
        a.remove(0);
        CHECK(a == ArrayT<std::string>{ "Have been", "", "", "URAAAA", "Completed" });
        a.remove(4);
        CHECK(a == ArrayT<std::string>{ "Have been", "", "", "URAAAA"});
        a.remove(1);
        CHECK(a == ArrayT<std::string>{ "Have been", "", "URAAAA"});
        a.remove(0);
        CHECK(a == ArrayT<std::string>{"", "URAAAA"});
        CHECK_THROWS(a.remove(2));
    }
}