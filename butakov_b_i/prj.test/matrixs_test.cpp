#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include <matrixs/matrixs.hpp>

#include <sstream>


TEST_CASE("[matrixs] - MatrixS ctor") {
    MatrixS m({ 3, 4 });
    CHECK(m.nRows() == 3);
    CHECK(m.nCols() == 4);
    CHECK(m.at(2, 3) == 0);
    CHECK_THROWS(m.at(3, 3));
    CHECK_THROWS(m.at(2, 4));
    CHECK_THROWS(MatrixS({ 0, -2 }));
    CHECK_THROWS(MatrixS({ -1, -1 }));
    CHECK_THROWS(MatrixS({ -2, 4 }));
    MatrixS a;
    CHECK(a.ssize() == std::make_tuple(0, 0));
    CHECK(a.nRows() == 0);
    CHECK(a.nCols() == 0);
    CHECK_THROWS(a.at(0, 0));
    MatrixS b(m);
    CHECK(b.nRows() == 3);
    CHECK(b.nCols() == 4);
    CHECK(b.at(2, 3) == 0);
    CHECK_THROWS(b.at(3, 3));
    CHECK_THROWS(b.at(2, 4));
    MatrixS c = b;
    CHECK(c.nRows() == 3);
    CHECK(c.nCols() == 4);
    CHECK(c.at(2, 3) == 0);
    CHECK_THROWS(c.at(3, 3));
    CHECK_THROWS(c.at(2, 4));

    
}

TEST_CASE("[matrixs] - at") {
    MatrixS m({ 3, 4 });
    CHECK(m.at({ 1, 2 }) == 0);
    CHECK(m.at(1, 3) == 0);
    CHECK_THROWS(m.at({ 3, 3 }));
    CHECK_THROWS(m.at(2, 4));
    CHECK_THROWS(m.at({ 3, 4 }));
    CHECK_THROWS(m.at({ -1, 3 }));
    CHECK_THROWS(m.at({ 0, -1 }));
    m.at({ 1, 2 }) = 3;
    CHECK(m.at({ 1, 2 }) == 3);

}

TEST_CASE("[matrixs] - operator =") {
    MatrixS m(3, 4);
    MatrixS megamatrix({ 100, 102 });
    megamatrix.at({ 99, 101 }) = 5;
    megamatrix.at(31, 70) = 4;
    m = megamatrix;
    CHECK(m.nRows() == 100);
    CHECK(m.nCols() == 102);
    CHECK(m.at( 99, 101 ) == 5);
    CHECK(m.at({ 31, 70 }) == 4);
    

}

TEST_CASE("[matrixs] - resize") {
    SUBCASE("new_size < size") {
        MatrixS m({ 3, 4 });
        m.at({ 0, 1 }) = 37;
        m.resize({ 1, 2 });
        m.resize(1, 2);
        CHECK(m.nRows() == 1);
        CHECK(m.nCols() == 2);
        CHECK(m.at({ 0, 1 }) == 37);
        CHECK(m.at( 0, 0 ) == 0);
        CHECK_THROWS(m.at({ 1, 2 }));
        CHECK_THROWS(m.at({ 2, 1 }));
        CHECK_THROWS(m.at({ 1, 1 }));
    }
    SUBCASE("new_size < size") {
        MatrixS m({ 3, 4 });
        m.at({ 0, 1 }) = 37;
        m.resize(10, 9);
        CHECK(m.nRows() == 10);
        CHECK(m.nCols() == 9);
        CHECK(m.at({ 0, 1 }) == 37);
        CHECK(m.at({ 0, 0 }) == 0);
        CHECK(m.at({ 5, 7 }) == 0);
        CHECK(0 == m.at({ 9, 8 }));
        CHECK_THROWS(m.at({ 10, 2 }));
        CHECK_THROWS(m.at({ 2, 9 }));
        m.resize(2, 15);
        CHECK(m.nRows() == 2);
        CHECK(m.nCols() == 15);
        CHECK(m.at({ 0, 1 }) == 37);
        CHECK(m.at({ 0, 0 }) == 0);
        CHECK(m.at({ 1, 14 }) == 0);
        CHECK_THROWS(m.at({ 2, 15 }));
        CHECK_THROWS(m.at({ 2, 5 }));
        CHECK_THROWS(m.at({ 1, 15 }));
        m.resize(15, 2);
        CHECK(m.ssize() == std::make_tuple(15, 2));
        CHECK(m.ssize() == std::make_tuple(m.nRows(), m.nCols()));
        CHECK(m.nRows() == 15);
        CHECK(m.nCols() == 2);
        CHECK(m.at({ 0, 1 }) == 37);
        CHECK(m.at({ 0, 0 }) == 0);
        CHECK(m.at({ 14, 1 }) == 0);
        CHECK_THROWS(m.at({ 2, 15 }));
        CHECK_THROWS(m.at({ 2, 5 }));
        CHECK_THROWS(m.at({ 15, 1 }));
    }

}



// Test constructor with size parameter
TEST_CASE("MatrixSTest, ConstructorWithSizeParameter") {
    MatrixS m2(3, 2);
    CHECK(m2.ssize() == std::make_tuple(m2.nRows(), m2.nCols()));
    
    CHECK(m2.ssize() == std::make_tuple(3, 2));
}

// Test copy constructor
TEST_CASE("MatrixSTest, CopyConstructor") {
    MatrixS m2(3, 2);
    m2.at(1, 1) = 5;
    MatrixS m3(m2);
    CHECK(m3.at(1, 1) == 5);
}

// Test assignment operator
TEST_CASE("MatrixSTest, AssignmentOperator") {
    MatrixS m2(3, 2);
    m2.at(1, 1) = 5;
    MatrixS m4;
    m4 = m2;
    CHECK(m4.at(1, 1) == 5);
}

// Test resizing matrix
TEST_CASE("MatrixSTest, ResizeMatrix") {
    MatrixS m2(3, 2);
    m2.resize(2, 4);
    CHECK(m2.ssize() == std::make_tuple(2, 4));
}

// Test accessing elements using at() function
TEST_CASE("MatrixSTest, AccessElementsWithAtFunction") {
    MatrixS m2(2, 2);
    m2.at(0, 0) = 1;
    m2.at(0, 1) = 2;
    m2.at(1, 0) = 3;
    m2.at(1, 1) = 4;
    CHECK(m2.at(0, 0) == 1);
    CHECK(m2.at(0, 1) == 2);
    CHECK(m2.at(1, 0) == 3);
    CHECK(m2.at(1, 1) == 4);
}

// Test accessing elements using invalid indices
TEST_CASE("MatrixSTest, AccessElementsWithInvalidIndices") {
    MatrixS m2(2, 2);
    bool exception_caught = false;
    try {
        m2.at(2, 0);
    }
    catch (const std::out_of_range& e) {
        exception_caught = true;
    }
    CHECK(exception_caught);
}

// Test accessing elements using const object
TEST_CASE("MatrixSTest, AccessElementsWithConstObject") {
    const MatrixS m5(2, 2);
    CHECK(m5.at(1, 1) == 0);
}

// Test resizing matrix with negative size
TEST_CASE("MatrixSTest, ResizeMatrixWithNegativeSize") {
    MatrixS m2(2, 2);

    CHECK_THROWS(m2.resize(-1, 2));
    
}

// Test accessing elements using invalid indices after resizing
TEST_CASE("MatrixSTest, AccessElementsWithInvalidIndicesAfterResizing") {
    MatrixS m2(2, 2);
    m2.resize(2, 4);
    bool exception_caught = false;
    try {
        m2.at(2, 0);
    }
    catch (const std::out_of_range& e) {
        exception_caught = true;
    }
    CHECK(exception_caught);
}
