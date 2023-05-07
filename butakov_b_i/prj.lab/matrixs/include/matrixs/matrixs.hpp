#pragma once
#ifndef MATRIXS_MATRIXS_HPP_18032023 
#define MATRIXS_MATRIXS_HPP_18032023

#include <iosfwd>
#include <utility>
#include <cstddef>
#include <iostream>
#include <vector>

class MatrixS {
public:
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

public:
    explicit MatrixS(const SizeType& size = { 0, 0 });
    MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n);
    ~MatrixS();

    MatrixS(const MatrixS& other);
    MatrixS& operator=(const MatrixS& other);

    int& at(const SizeType& elem);
    const int& at(const SizeType& elem) const;
    int& at(const std::ptrdiff_t i, const std::ptrdiff_t j);
    const int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) const;

    void resize(const SizeType& new_size);
    void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);

    const SizeType& ssize() const noexcept;

    std::ptrdiff_t nRows() const noexcept;

    std::ptrdiff_t nCols() const noexcept;


private:

    SizeType size_ = { 0, 0 };

    int** data_ = nullptr;

};

#endif