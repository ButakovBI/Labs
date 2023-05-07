#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.hpp>

#include <sstream>

TEST_CASE("[rational] - Rational ctor") {
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational(3) == Rational(3, 1));
    CHECK(Rational(-3) == Rational(-3, 1));
    CHECK(Rational(10, 6) == Rational(5, 3));
    CHECK(Rational(-10, 6) == Rational(-5, 3));
    CHECK(Rational(10, -6) == Rational(-5, 3));
    CHECK(Rational(-10, -6) == Rational(5, 3));
    CHECK_THROWS(Rational(1, 0));
}
TEST_CASE("[rational] - Rational constructor") {
    Rational r(3, 4);
    REQUIRE(r.num() == 3);
    REQUIRE(r.denom() == 4);
}
TEST_CASE("[rational] - Rational operator +") {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational sum = r1 + r2;
    REQUIRE(sum.num() == 5);
    REQUIRE(sum.denom() == 6);
}

TEST_CASE("[rational] - Rational operator +=") {
    SUBCASE("at all") {
        Rational r1(15, 25);
        Rational r2(1, 5);
        r1 += r2;
        REQUIRE(r1.num() == 4);
        REQUIRE(r1.denom() == 5);
    }
    SUBCASE("throws") {
        CHECK_THROWS(Rational(3, 10) += Rational(1, 0));
    }
}

TEST_CASE("[rational] - Rational operator -") {
    Rational r1(3, 4);
    Rational r2(1, 4);
    Rational diff = r1 - r2;
    REQUIRE(diff.num() == 1);
    REQUIRE(diff.denom() == 2);
}

TEST_CASE("[rational] - Rational operator -=") {
    Rational r1(15, 25);
    Rational r2(2, 10);
    r1 -= r2;
    REQUIRE(r1.num() == 2);
    REQUIRE(r1.denom() == 5);
}

TEST_CASE("[rational] - Rational operator -=") {
    Rational r1(15, 25);
    Rational r2(-2, 10);
    r1 -= r2;
    REQUIRE(r1.num() == 4);
    REQUIRE(r1.denom() == 5);
}

TEST_CASE("[rational] - Rational operator *") {
    Rational r1(3, 4);
    Rational r2(2, 3);
    Rational prod = r1 * r2;
    REQUIRE(prod.num() == 1);
    REQUIRE(prod.denom() == 2);
}

TEST_CASE("[rational] - Rational operator *") {
    Rational r1(3, 4);
    Rational r2(0, 3);
    Rational prod = r1 * r2;
    REQUIRE(prod.num() == 0);
    REQUIRE(prod.denom() == 1);
}

TEST_CASE("[rational] - Rational operator *=") {
    Rational r1(15, 25);
    Rational r2(1, 5);
    r1 *= r2;
    REQUIRE(r1.num() == 3);
    REQUIRE(r1.denom() == 25);
}

TEST_CASE("[rational] - Rational operator *=") {
    Rational r1(15, 25);
    Rational r2(0, 5);
    r1 *= r2;
    REQUIRE(r1.num() == 0);
    REQUIRE(r1.denom() == 1);
}

TEST_CASE("[rational] - Rational operator /") {
    Rational r1(3, 4);
    Rational r2(2, 3);
    Rational div = r1 / r2;
    REQUIRE(div.num() == 9);
    REQUIRE(div.denom() == 8);
}

TEST_CASE("[rational] - Rational operator /") {
    Rational r1(3, 4);
    Rational r2(0, 3);
    CHECK_THROWS(r1 / r2);
}

TEST_CASE("[rational] - Rational operator /=") {
    Rational r1(15, 25);
    Rational r2(1, 5);
    r1 /= r2;
    REQUIRE(r1.num() == 3);
    REQUIRE(r1.denom() == 1);
}

TEST_CASE("[rational] - Rational operator /=") {
    Rational r1(15, 25);
    Rational r2(0, 5);
    CHECK_THROWS(r1 /= r2);
}

TEST_CASE("[rational] - Rational operator >>") {
    std::stringstream ss1("32/40");
    Rational r1;
    ss1 >> r1;
    REQUIRE(r1.num() == 4);
    REQUIRE(r1.denom() == 5);

    std::stringstream ss2("-32/40");
    Rational r2;
    ss2 >> r2;
    REQUIRE(r2.num() == -4);
    REQUIRE(r2.denom() == 5);

    std::stringstream ss3("32/-40");
    Rational r3;
    ss3 >> r3;
    REQUIRE(ss3.fail());

    std::stringstream ss4("20.1a/12");
    Rational r4;
    ss4 >> r4;
    REQUIRE(ss4.fail());

    std::stringstream ss5("20/21.7");
    Rational r5;
    ss5 >> r5;
    CHECK(r5 == Rational(20, 21));

    std::stringstream ss6("21/0");
    Rational r6;
    ss6 >> r6;
    REQUIRE(ss6.fail());

    std::stringstream ss7("21/a");
    Rational r7;
    ss7 >> r7;
    REQUIRE(ss7.fail());

    std::stringstream ss8("b/a");
    Rational r8;
    ss8 >> r8;
    REQUIRE(ss8.fail());

    std::stringstream ss9("0/a");
    Rational r9;
    ss9 >> r9;
    REQUIRE(ss9.fail());

    std::stringstream ss10("21/2/3");
    Rational r10;
    ss10 >> r10;
    CHECK(r10 == Rational(21, 2));

    std::stringstream ss11("0/5/a");
    Rational r11;
    ss11 >> r11;
    CHECK(r11 == Rational(0, 1));

    std::stringstream ss12("abs");
    Rational r12;
    ss12 >> r12;
    REQUIRE(ss12.fail());

    std::stringstream ss13("0/0");
    Rational r13;
    ss13 >> r13;
    REQUIRE(ss13.fail());

    std::stringstream ss14("abc/2");
    Rational r14;
    ss14 >> r14;
    REQUIRE(ss14.fail());

    std::stringstream ss15("2  / 1");
    Rational r15;
    ss15 >> r15;
    REQUIRE(ss15.fail());

    std::stringstream ss16("4/ 2");
    Rational r16;
    ss16 >> r16;
    REQUIRE(ss16.fail());

    std::stringstream ss17("10             /5");
    Rational r17;
    ss17 >> r17;
    REQUIRE(ss17.fail());

    std::stringstream ss18("0/20");
    Rational r18;
    ss18 >> r18;
    REQUIRE(r18.num() == 0);
    REQUIRE(r18.denom() == 1);

    std::stringstream ss19("1/20");
    Rational r19;
    ss19 >> r19;
    REQUIRE(r19.num() == 1);
    REQUIRE(r19.denom() == 20);

    std::stringstream ss21("1/");
    Rational r21;
    ss21 >> r21;
    REQUIRE(ss21.fail());

    std::stringstream ss22("/20");
    Rational r22;
    ss22 >> r22;
    REQUIRE(ss22.fail());

    std::stringstream ss23("/");
    Rational r23;
    ss23 >> r23;
    REQUIRE(ss23.fail());

    std::stringstream ss24("//");
    Rational r24;
    ss24 >> r24;
    REQUIRE(ss24.fail());

    std::stringstream ss26("2/20");
    Rational r26;
    ss26 >> r26;
    REQUIRE(r26.num() == 1);
    REQUIRE(r26.denom() == 10);
    REQUIRE(!ss26.fail());

    std::stringstream ss27("-/20");
    Rational r27;
    ss27 >> r27;
    REQUIRE(ss27.fail());

    std::stringstream ss28("20/-");
    Rational r28;
    ss28 >> r28;
    REQUIRE(ss28.fail());

    std::stringstream ss29("--/20");
    Rational r29;
    ss29 >> r29;
    REQUIRE(ss29.fail());

    std::stringstream ss30("-2/2---");
    Rational r30;
    ss30 >> r30;
    CHECK(r30 == Rational(-1, 1));

    std::stringstream ss31("-2.0/2");
    Rational r31;
    ss31 >> r31;
    REQUIRE(ss31.fail());

}
TEST_CASE("[rational] - Rational::operator>>") {
    SUBCASE("") {
        std::istringstream input("32/423");
        Rational r;
        input >> r;
        REQUIRE(r == Rational(32, 423));
        REQUIRE(input.fail() == false);
    }
    SUBCASE("") {
        std::istringstream input("-12/3");
        Rational r;
        input >> r;
        REQUIRE(r == Rational(-4, 1));
        REQUIRE(input.fail() == false);
    }
    SUBCASE("") {
        std::istringstream input("33                 /                    1243");
        REQUIRE(input.good());
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("-3 / -1");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("1.3 / 4.2");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("12/-2");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("-/5");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("-0/5");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == false);
        REQUIRE(r == Rational(0));
    }
    SUBCASE("") {
        std::istringstream input("555555");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("/55555");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("3/4.2");
        Rational r;
        input >> r;
        CHECK(r == Rational(3, 4));
    }
    SUBCASE("") {
        std::istringstream input("1/0");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("        ");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);

    }
}



TEST_CASE("[rational] - Rational operator <<") {
    std::stringstream ss;
    Rational r(3, 4);
    ss << r;
    REQUIRE(ss.str() == "3/4");
}
TEST_CASE("[rational] - Rational normalize function") {
    Rational r(6, 8);
    REQUIRE(r.num() == 3);
    REQUIRE(r.denom() == 4);
}
TEST_CASE("[rational] - Rational operator ==") {
    Rational r1(1, 2);
    Rational r2(2, 4);
    REQUIRE(r1 == r2);
}
TEST_CASE("[rational] - Rational operator !=") {
    Rational r1(1, 2);
    Rational r2(3, 4);
    REQUIRE(r1 != r2);
}
TEST_CASE("[rational] - Rational operator <") {
    Rational r1(1, 2);
    Rational r2(3, 4);
    REQUIRE(r1 < r2);
}
TEST_CASE("[rational] - Rational operator >") {
    Rational r1(3, 4);
    Rational r2(1, 2);
    REQUIRE(r1 > r2);
}
TEST_CASE("[rational] - Rational operator <=") {
    Rational r1(1, 2);
    Rational r2(2, 4);
    REQUIRE(r1 <= r2);
}
TEST_CASE("[rational] - Rational operator >=") {
    Rational r1(3, 4);
    Rational r2(1, 2);
    REQUIRE(r1 >= r2);
}
TEST_CASE("[rational] - Rational operator =") {
    Rational r1(1, 2);
    Rational r2(3, 4);
    r1 = r2;
    REQUIRE(r1.num() == 3);
    REQUIRE(r1.denom() == 4);
}

TEST_CASE("[rational] - Rational operator bool") {
    Rational r1(15, 25);
    REQUIRE((r1.num() != 0) == true);
}

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>
//
//#include <rational/rational.hpp>



TEST_CASE("[rational] - Rational ctor") {
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational(3) == Rational(3, 1));
    CHECK(Rational(-3) == Rational(-3, 1));
    CHECK(Rational(10, 6) == Rational(5, 3));
    CHECK(Rational(-10, 6) == Rational(-5, 3));
    CHECK(Rational(10, -6) == Rational(-5, 3));
    CHECK(Rational(-10, -6) == Rational(5, 3));
    CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("[rational] - Rational add") {
    CHECK(Rational(3, 2) + Rational(5, 7) == Rational(31, 14));
    CHECK(Rational(5, 7) + Rational(3, 2) == Rational(31, 14));
    CHECK(Rational() + Rational() == Rational());
    CHECK(Rational() + Rational(29, 41) == Rational(29, 41));
    CHECK(Rational(5, 1) + Rational(3, 2) == Rational(13, 2));
}

TEST_CASE("[rational] - Rational subtract") {
    CHECK(Rational(31, 14) - Rational(5, 7) == Rational(3, 2));
    CHECK(Rational(25, 7) - Rational(2, 9) == Rational(211, 63));
    CHECK(Rational(2, 3) - Rational(7, 4) == Rational(-13, 12));
}

TEST_CASE("[rational] - Rational division") {
    CHECK(Rational(5, 2) / Rational(5, 2) == Rational(1, 1));
    CHECK(Rational(3, 2) / Rational(9, 8) == Rational(4, 3));
    CHECK_THROWS(Rational(3, 2) / Rational(5, 0));
}

TEST_CASE("[rational] - Rational minus") {
    CHECK(-Rational() == Rational());
    CHECK(Rational(-5, 3) == -Rational(5, 3));
    CHECK(Rational(25, 7) == -(-(Rational(25, 7))));
    CHECK(Rational(29, 41) == -Rational(-29, 41));
}

TEST_CASE("[rational] - I/O") {

    SUBCASE("Output") {

        std::stringstream sstrm;

        SUBCASE("Simple") {
            sstrm << Rational(23, 7);
            CHECK(sstrm.str() == "23/7");
        }

        sstrm.clear();

        SUBCASE("Default constructor") {
            sstrm << Rational();
            CHECK(sstrm.str() == "0/1");
        }

        sstrm.clear();


        SUBCASE("Negative") {
            sstrm << -Rational(3, 8);
            CHECK(sstrm.str() == "-3/8");
        }

        sstrm.clear();

        SUBCASE("Negative with reduce") {
            sstrm << Rational(-8, 2);
            CHECK(sstrm.str() == "-4/1");
        }

    }

    SUBCASE("Correct inputs") {

        Rational r;
        std::stringstream sstrm;
        std::stringstream stream;

        SUBCASE("Simple") {
            sstrm.str("2/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(2, 3));
        }

        sstrm.clear();

        SUBCASE("Input with reducing") {
            sstrm.str("36/48");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(3, 4));
        }

        sstrm.clear();

        SUBCASE("Negative input") {
            sstrm.str("-8/7");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-8, 7));
        }
        sstrm.clear();
    }
    

    SUBCASE("Correct inputs with extra spaces on begin and trash on end") {

        Rational r;
        std::stringstream sstrm;

        SUBCASE("Extra spaces on begin") {
            sstrm.str(" 1/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra extra spaces on begin") {
            sstrm.str("    -3/4");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-3, 4));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends") {
            sstrm.str("5/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(5, 9));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends and negative number") {
            sstrm.str(" -3/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(-1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on begin and trash on end") {
            sstrm.str(" 23/7abc");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);//////////
            CHECK(r == Rational(23, 7));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on end") {
            sstrm.str("3/7 ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(3, 7));
        }

        sstrm.clear();

        SUBCASE("Trash on end") {
            sstrm.str("9/2&");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);///////
            CHECK(r == Rational(9, 2));
        }
    }

    SUBCASE("Uncorrect inputs") {
        Rational r;
        int b;
        std::stringstream sstrm;
        std::stringstream stream;

        SUBCASE("Trash") {
            sstrm.str("kek");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Bad delimiter") {
            sstrm.str("5\\3");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Numerator is trash") {
            sstrm.str("a/3");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Denominator is trash") {
            sstrm.str("3/*");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Spaces between 1") {
            sstrm.str("3 /2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Spaces between 2") {
            sstrm.str("3/ 2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Spaces between 3") {
            sstrm.str("3 / 2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Denominator is negative") {
            sstrm.str("3/-2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("INT") {
            sstrm.str("12");
            sstrm >> b;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
        }
        SUBCASE("INT") {
            int c;
            int d;
            stream.str("7a");
            stream >> c;
            CHECK(stream.rdstate() == std::ios_base::goodbit);
            CHECK(c == 7);
            
        }

        SUBCASE("2 int") {
            int int1;
            stream.str("abc8");
            stream >> int1;
            CHECK(stream.rdstate() == std::ios_base::failbit);
        }
        stream.clear();

        SUBCASE("2 inputs") {
            Rational r2;
            Rational r3;
            Rational r4;
            stream.str("8/7 -7/6 1/2");
            stream >> r2 >> r3 >> r4;
            CHECK(stream.rdstate() == std::ios_base::eofbit);
            CHECK(r2 == Rational(8, 7));
            CHECK(r3 == Rational(-7, 6));
            CHECK(r4 == Rational(1, 2));
        }
        stream.clear();
        
        sstrm.clear();

        SUBCASE("") {
            sstrm.str("a/a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("1a/a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("a1/a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

         sstrm.clear();

        SUBCASE("") {
            sstrm.str("1/a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("1/a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("a/1");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("a/1a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("a/a1");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("-1/a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("-1/-a");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("-1a/2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("-1/a2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("1/a3");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("-10/a3");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("3/7 a");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(3, 7));
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("-3/7 ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(-3, 7));
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("3/7 2/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(3, 7));
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("4/7--");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(4, 7));
        }

        sstrm.clear();

        SUBCASE("") {
            sstrm.str("3/7 21/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(3, 7));
        }

        sstrm.clear();

        SUBCASE("Extra extra spaces on begin") {
            sstrm.str("-30/4");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-15, 2));
        }

        sstrm.clear();

        SUBCASE("Extra extra spaces on begin") {
            sstrm.str("  -30/4");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-15, 2));
        }

        stream.clear();

        SUBCASE("3 inputs") {
            Rational r2;
            Rational r3;
            Rational r4;
            stream.str("8/7 -a/6 1/2");
            stream >> r2 >> r3 >> r4;
            CHECK(stream.rdstate() == std::ios_base::failbit);
            CHECK(r2 == Rational(8, 7));
        }

        stream.clear();

        SUBCASE("3 inputs") {
            Rational r2;
            Rational r3;
            Rational r4;
            stream.str("a/7 -7/6 1/2    ");
            stream >> r2 >> r3 >> r4;
            CHECK(stream.rdstate() == std::ios_base::failbit);
        }

        stream.clear();

        SUBCASE("inputs int") {
            int a = 0, b = 0, c = 0;
            stream.str("8 7 a");
            stream >> a >> b >> c;
            CHECK(stream.rdstate() == std::ios_base::failbit);
            CHECK(a == 8);
            CHECK(b == 7);
        }

        stream.clear();

        SUBCASE("3 inputs") {
            Rational r2;
            Rational r3;
            Rational r4;
            stream.str("8/7 7/6 a/2");
            stream >> r2 >> r3 >> r4;
            CHECK(stream.rdstate() == std::ios_base::failbit);
            CHECK(r2 == Rational(8, 7));
            CHECK(r3 == Rational(7, 6));
        }

        stream.clear();

        SUBCASE("3 inputs") {
            Rational r2;
            Rational r3;
            Rational r4;
            stream.str("8/7 -7/6 -a/2");
            stream >> r2 >> r3 >> r4;
            CHECK(stream.rdstate() == std::ios_base::failbit);
            CHECK(r2 == Rational(8, 7));
            CHECK(r3 == Rational(-7, 6));
        }

        stream.clear();

        SUBCASE("3 inputs") {
            Rational r2;
            Rational r3;
            Rational r4;
            stream.str("8/7 -7/6 -a/2 ");
            stream >> r2 >> r3 >> r4;
            CHECK(stream.rdstate() == std::ios_base::failbit);
            CHECK(r2 == Rational(8, 7));
            CHECK(r3 == Rational(-7, 6));
        }

        sstrm.clear();

        SUBCASE("Trash on end") {
            sstrm.str("9/2&");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);///////
            CHECK(r == Rational(9, 2));
        }

        stream.clear();

        SUBCASE("3 inputs") {
            Rational r2;
            int b = 0;
            double c = 0;
            stream.str("8/7 -7 6.2 ");
            stream >> r2 >> b >> c;
            CHECK(stream.rdstate() == std::ios_base::goodbit);
            CHECK(r2 == Rational(8, 7));
            CHECK(b == -7);
            CHECK(c == 6.2);
        }

        
    }
}

TEST_CASE("[rational] - Rational ctor") {

    //standart tests
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational(3) == Rational(3, 1));
    CHECK(Rational(-3) == Rational(-3, 1));
    CHECK(Rational(10, 6) == Rational(5, 3));
    CHECK(Rational(-10, 6) == Rational(-5, 3));
    CHECK(Rational(10, -6) == Rational(-5, 3));
    CHECK(Rational(-10, -6) == Rational(5, 3));
    CHECK_THROWS(Rational(1, 0));

    //new tests
    CHECK(Rational(4) != Rational(4.0, 2));
    CHECK((Rational(2, 5) + Rational(1, 10)) == Rational(1, 2));
    CHECK((Rational(2, 5) - Rational(-1, 10)) == Rational(1, 2));
    CHECK((Rational(2, -3) + Rational(-1)) != Rational(1, 2));
    CHECK(-Rational() == Rational());
    CHECK(-Rational(7, 19) == Rational(7, -19));
    CHECK(Rational(5, 100) * Rational(20, 3) == -Rational(-1, 3));
    CHECK(Rational(3, 17) / Rational(6, 17) == Rational(1, 2));
    CHECK(Rational() == false);
    CHECK(Rational(1) == true);
    CHECK(Rational(7));
    CHECK(Rational(3, 9) > Rational(2, 7));
    CHECK(Rational(7, 9) < Rational(1));
    CHECK(Rational(7, 9) >= Rational(14, 18));
    CHECK(Rational(7, 9) >= Rational(14, 19));
    CHECK(Rational(7, 9) <= Rational(14, 18));
    CHECK(Rational(7, 9) <= Rational(14, 17));


}

//tests of monkey

TEST_CASE("[rational] - I/O") {


    SUBCASE("Output") {

        std::stringstream sstrm;

        SUBCASE("Simple") {
            sstrm << Rational(23, 7);
            CHECK(sstrm.str() == "23/7");
        }

        sstrm.clear();

        SUBCASE("Default constructor") {
            sstrm << Rational();
            CHECK(sstrm.str() == "0/1");
        }

        sstrm.clear();


        SUBCASE("Negative") {
            sstrm << -Rational(3, 8);
            CHECK(sstrm.str() == "-3/8");
        }

        sstrm.clear();

        SUBCASE("Negative with reduce") {
            sstrm << Rational(-8, 2);
            CHECK(sstrm.str() == "-4/1");
        }

    }

    SUBCASE("Correct inputs") {

        Rational r;
        std::stringstream sstrm;

        SUBCASE("Simple") {
            sstrm.str("2/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(2, 3));
        }

        sstrm.clear();

        SUBCASE("Input with reducing") {
            sstrm.str("36/48");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(3, 4));
        }

        sstrm.clear();

        SUBCASE("Negative input") {
            sstrm.str("-8/7");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-8, 7));
        }
    }

    SUBCASE("Correct inputs with extra spaces on begin and trash on end") {

        Rational r;
        std::stringstream sstrm;

        SUBCASE("Extra spaces on begin") {
            sstrm.str(" 1/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra extra spaces on begin") {
            sstrm.str("   -3/4");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-3, 4));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends") {
            sstrm.str(" 5/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(5, 9));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends and negative number") {
            sstrm.str(" -3/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(-1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on begin and trash on end") {
            sstrm.str(" 23/9abc");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(23, 9));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on end") {
            sstrm.str("3/7 ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(3, 7));
        }

        sstrm.clear();

        SUBCASE("Trash on end") {
            sstrm.str("9/2&");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(9, 2));
        }
    }

    SUBCASE("Uncorrect inputs") {
        Rational r;
        std::stringstream sstrm;

        SUBCASE("Trash") {
            sstrm.str("kek");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Bad delimiter") {
            sstrm.str("5\\3");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Numerator is trash") {
            sstrm.str("a/3");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Denominator is trash") {
            sstrm.str("3/*");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Spaces between 1") {
            sstrm.str("3 /2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Spaces between 2") {
            sstrm.str("3/ 2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Spaces between 3") {
            sstrm.str("3 / 2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

        sstrm.clear();

        SUBCASE("Denominator is negative") {
            sstrm.str("3/-2");
            sstrm >> r;
            CHECK(sstrm.fail());
            CHECK(!sstrm.bad());
        }

    }

    SUBCASE("2 inputs") {

        Rational r2;
        Rational r3;
        std::stringstream sstrm;

        sstrm.str("8/7 7/6");
        sstrm >> r2 >> r3;
        CHECK(sstrm.rdstate() == std::ios_base::eofbit);
        CHECK(r2 == Rational(8, 7));
        CHECK(r3 == Rational(7, 6));
    }
}

// and other tests....

TEST_CASE("[rational] - Rational constructor") {
    Rational r(3, 4);
    REQUIRE(r.num() == 3);
    REQUIRE(r.denom() == 4);
}
TEST_CASE("[rational] - Rational operator +") {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational sum = r1 + r2;
    REQUIRE(sum.num() == 5);
    REQUIRE(sum.denom() == 6);
}

TEST_CASE("[rational] - Rational operator +=") {
    SUBCASE("at all") {
        Rational r1(15, 25);
        Rational r2(1, 5);
        r1 += r2;
        REQUIRE(r1.num() == 4);
        REQUIRE(r1.denom() == 5);
    }
    SUBCASE("throws") {
        CHECK_THROWS(Rational(3, 10) += Rational(1, 0));
    }
}

TEST_CASE("[rational] - Rational operator -") {
    Rational r1(3, 4);
    Rational r2(1, 4);
    Rational diff = r1 - r2;
    REQUIRE(diff.num() == 1);
    REQUIRE(diff.denom() == 2);
}

TEST_CASE("[rational] - Rational operator -=") {
    Rational r1(15, 25);
    Rational r2(2, 10);
    r1 -= r2;
    REQUIRE(r1.num() == 2);
    REQUIRE(r1.denom() == 5);
}

TEST_CASE("[rational] - Rational operator -=") {
    Rational r1(15, 25);
    Rational r2(-2, 10);
    r1 -= r2;
    REQUIRE(r1.num() == 4);
    REQUIRE(r1.denom() == 5);
}

TEST_CASE("[rational] - Rational operator *") {
    Rational r1(3, 4);
    Rational r2(2, 3);
    Rational prod = r1 * r2;
    REQUIRE(prod.num() == 1);
    REQUIRE(prod.denom() == 2);
}

TEST_CASE("[rational] - Rational operator *") {
    Rational r1(3, 4);
    Rational r2(0, 3);
    Rational prod = r1 * r2;
    REQUIRE(prod.num() == 0);
    REQUIRE(prod.denom() == 1);
}

TEST_CASE("[rational] - Rational operator *=") {
    Rational r1(15, 25);
    Rational r2(1, 5);
    r1 *= r2;
    REQUIRE(r1.num() == 3);
    REQUIRE(r1.denom() == 25);
}

TEST_CASE("[rational] - Rational operator *=") {
    Rational r1(15, 25);
    Rational r2(0, 5);
    r1 *= r2;
    REQUIRE(r1.num() == 0);
    REQUIRE(r1.denom() == 1);
}

TEST_CASE("[rational] - Rational operator /") {
    Rational r1(3, 4);
    Rational r2(2, 3);
    Rational div = r1 / r2;
    REQUIRE(div.num() == 9);
    REQUIRE(div.denom() == 8);
}

TEST_CASE("[rational] - Rational operator /") {
    Rational r1(3, 4);
    Rational r2(0, 3);
    CHECK_THROWS(r1 / r2);
}

TEST_CASE("[rational] - Rational operator /=") {
    Rational r1(15, 25);
    Rational r2(1, 5);
    r1 /= r2;
    REQUIRE(r1.num() == 3);
    REQUIRE(r1.denom() == 1);
}

TEST_CASE("[rational] - Rational operator /=") {
    Rational r1(15, 25);
    Rational r2(0, 5);
    CHECK_THROWS(r1 /= r2);
}

TEST_CASE("[rational] - Rational operator >>") {
    std::stringstream ss1("32/40");
    Rational r1;
    ss1 >> r1;
    REQUIRE(r1.num() == 4);
    REQUIRE(r1.denom() == 5);

    std::stringstream ss2("-32/40");
    Rational r2;
    ss2 >> r2;
    REQUIRE(r2.num() == -4);
    REQUIRE(r2.denom() == 5);

    std::stringstream ss3("32/-40");
    Rational r3;
    ss3 >> r3;
    REQUIRE(ss3.fail());

    std::stringstream ss4("20.1a/12");
    Rational r4;
    ss4 >> r4;
    REQUIRE(ss4.fail());

    std::stringstream ss5("20/21.7");
    Rational r5;
    ss5 >> r5;
    CHECK(r5 == Rational(20, 21));

    std::stringstream ss6("21/0");
    Rational r6;
    ss6 >> r6;
    REQUIRE(ss6.fail());

    std::stringstream ss7("21/a");
    Rational r7;
    ss7 >> r7;
    REQUIRE(ss7.fail());

    std::stringstream ss8("b/a");
    Rational r8;
    ss8 >> r8;
    REQUIRE(ss8.fail());

    std::stringstream ss9("0/a");
    Rational r9;
    ss9 >> r9;
    REQUIRE(ss9.fail());

    std::stringstream ss10("21/2/3");
    Rational r10;
    ss10 >> r10;
    CHECK(r10 == Rational(21, 2));
    std::stringstream ss11("0/5/a");
    Rational r11;
    ss11 >> r11;
    CHECK(r11 == Rational(0, 1));

    std::stringstream ss12("abs");
    Rational r12;
    ss12 >> r12;
    REQUIRE(ss12.fail());

    std::stringstream ss13("0/0");
    Rational r13;
    ss13 >> r13;
    REQUIRE(ss13.fail());

    std::stringstream ss14("abc/2");
    Rational r14;
    ss14 >> r14;
    REQUIRE(ss14.fail());

    std::stringstream ss15("2  / 1");
    Rational r15;
    ss15 >> r15;
    REQUIRE(ss15.fail());

    std::stringstream ss16("4/ 2");
    Rational r16;
    ss16 >> r16;
    REQUIRE(ss16.fail());

    std::stringstream ss17("10             /5");
    Rational r17;
    ss17 >> r17;
    REQUIRE(ss17.fail());

    std::stringstream ss18("0/20");
    Rational r18;
    ss18 >> r18;
    REQUIRE(r18.num() == 0);
    REQUIRE(r18.denom() == 1);

    std::stringstream ss19("1/20");
    Rational r19;
    ss19 >> r19;
    REQUIRE(r19.num() == 1);
    REQUIRE(r19.denom() == 20);

    std::stringstream ss21("1/");
    Rational r21;
    ss21 >> r21;
    REQUIRE(ss21.fail());

    std::stringstream ss22("/20");
    Rational r22;
    ss22 >> r22;
    REQUIRE(ss22.fail());

    std::stringstream ss23("/");
    Rational r23;
    ss23 >> r23;
    REQUIRE(ss23.fail());

    std::stringstream ss24("//");
    Rational r24;
    ss24 >> r24;
    REQUIRE(ss24.fail());

    std::stringstream ss26("2/20");
    Rational r26;
    ss26 >> r26;
    REQUIRE(r26.num() == 1);
    REQUIRE(r26.denom() == 10);
    REQUIRE(!ss26.fail());

    std::stringstream ss27("-/20");
    Rational r27;
    ss27 >> r27;
    REQUIRE(ss27.fail());

    std::stringstream ss28("20/-");
    Rational r28;
    ss28 >> r28;
    REQUIRE(ss28.fail());

    std::stringstream ss29("--/20");
    Rational r29;
    ss29 >> r29;
    REQUIRE(ss29.fail());

    std::stringstream ss30("-2/2---");
    Rational r30;
    ss30 >> r30;
    CHECK(r30 == Rational(-1, 1));

    std::stringstream ss31("-2.0/2");
    Rational r31;
    ss31 >> r31;
    REQUIRE(ss31.fail());

}
TEST_CASE("[rational] - Rational::operator>>") {
    SUBCASE("") {
        std::istringstream input("32/423");
        Rational r;
        input >> r;
        REQUIRE(r == Rational(32, 423));
        REQUIRE(input.fail() == false);
    }
    SUBCASE("") {
        std::istringstream input("-12/3");
        Rational r;
        input >> r;
        REQUIRE(r == Rational(-4, 1));
        REQUIRE(input.fail() == false);
    }
    SUBCASE("") {
        std::istringstream input("33                 /                    1243");
        REQUIRE(input.good());
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("-3 / -1");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("1.3 / 4.2");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("12/-2");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("-/5");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("-0/5");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == false);
        REQUIRE(r == Rational(0));
    }
    SUBCASE("") {
        std::istringstream input("555555");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("/55555");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("3/4.2");
        Rational r;
        input >> r;
        CHECK(r == Rational(3, 4));
    }
    SUBCASE("") {
        std::istringstream input("1/0");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);
    }
    SUBCASE("") {
        std::istringstream input("        ");
        Rational r;
        input >> r;
        REQUIRE(input.fail() == true);

    }
}



TEST_CASE("[rational] - Rational operator <<") {
    std::stringstream ss;
    Rational r(3, 4);
    ss << r;
    REQUIRE(ss.str() == "3/4");
}
TEST_CASE("[rational] - Rational normalize function") {
    Rational r(6, 8);
    REQUIRE(r.num() == 3);
    REQUIRE(r.denom() == 4);
}
TEST_CASE("[rational] - Rational operator ==") {
    Rational r1(1, 2);
    Rational r2(2, 4);
    REQUIRE(r1 == r2);
}
TEST_CASE("[rational] - Rational operator !=") {
    Rational r1(1, 2);
    Rational r2(3, 4);
    REQUIRE(r1 != r2);
}
TEST_CASE("[rational] - Rational operator <") {
    Rational r1(1, 2);
    Rational r2(3, 4);
    REQUIRE(r1 < r2);
}
TEST_CASE("[rational] - Rational operator >") {
    Rational r1(3, 4);
    Rational r2(1, 2);
    REQUIRE(r1 > r2);
}
TEST_CASE("[rational] - Rational operator <=") {
    Rational r1(1, 2);
    Rational r2(2, 4);
    REQUIRE(r1 <= r2);
}
TEST_CASE("[rational] - Rational operator >=") {
    Rational r1(3, 4);
    Rational r2(1, 2);
    REQUIRE(r1 >= r2);
}
TEST_CASE("[rational] - Rational operator =") {
    Rational r1(1, 2);
    Rational r2(3, 4);
    r1 = r2;
    REQUIRE(r1.num() == 3);
    REQUIRE(r1.denom() == 4);
}

TEST_CASE("[rational] - Rational operator bool") {
    Rational r1(15, 25);
    REQUIRE((r1.num() != 0) == true);
}
