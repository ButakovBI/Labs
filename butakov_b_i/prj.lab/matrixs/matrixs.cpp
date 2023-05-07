#include <matrixs/matrixs.hpp>

using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

MatrixS::MatrixS(const SizeType& size) {
    std::ptrdiff_t rows = std::get<0>(size);
    std::ptrdiff_t cols = std::get<1>(size);
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Wrong rows or cols");
    }
    data_ = new int* [rows];
    for (int i = 0; i < rows; i += 1) {
        data_[i] = new int[cols];
        for (int j = 0; j < cols; j += 1) {
            data_[i][j] = 0;
        }
    }
    size_ = size;
}


MatrixS::MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n) {
    std::ptrdiff_t rows = m;
    std::ptrdiff_t cols = n;
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Wrong rows or cols");
    }
    data_ = new int* [rows];
    for (int i = 0; i < rows; i += 1) {
        data_[i] = new int[cols];
        for (int j = 0; j < cols; j += 1) {
            data_[i][j] = 0;
        }
    }
    size_ = std::make_tuple(rows, cols);
}

MatrixS::~MatrixS() {
    for (int i = 0; i < nRows(); i += 1) {
        delete[] data_[i];
    }
    delete[] data_;
}

MatrixS::MatrixS(const MatrixS& other) {
    int** new_data_ = new int* [other.nRows()];
    for (int i = 0; i < other.nRows(); i += 1) {
        new_data_[i] = new int[other.nCols()];
        for (int j = 0; j < other.nCols(); j += 1) {
            new_data_[i][j] = other.data_[i][j];
        }
    }
    for (int i = 0; i < nRows(); i += 1) {
        delete[] data_[i];
    }
    delete[] data_;

    data_ = new_data_;
    size_ = other.size_;
}

MatrixS& MatrixS::operator=(const MatrixS& rhs) {
    if (this == &rhs) {
        return *this;
    }
    else {
        
        for (int i = 0; i < nRows(); i += 1) {
            delete[] data_[i];
        }
        delete[] data_;

       
        data_ = new int* [rhs.nRows()];
        for (int i = 0; i < rhs.nRows(); i += 1) {
            data_[i] = new int[rhs.nCols()];
            for (int j = 0; j < rhs.nCols(); j += 1) {
                data_[i][j] = rhs.data_[i][j];
            }
        }
        
        size_ = std::make_tuple(rhs.nRows(), rhs.nCols());

    }
    return *this;
    
}

int& MatrixS::at(const SizeType& elem) {
    std::ptrdiff_t row = std::get<0>(elem);
    std::ptrdiff_t col = std::get<1>(elem);
    if (row < 0 || row >= nRows() || col < 0 || col >= nCols()) {
        throw std::out_of_range("Going outside the matrix");
    }
    return data_[row][col];
}

const int& MatrixS::at(const SizeType& elem) const {
    std::ptrdiff_t row = std::get<0>(elem);
    std::ptrdiff_t col = std::get<1>(elem);
    if (row < 0 || row >= nRows() || col < 0 || col >= nCols()) {
        throw std::out_of_range("Going outside the matrix");
    }
    return data_[row][col];
}

int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    std::ptrdiff_t row = i;
    std::ptrdiff_t col = j;
    if (row < 0 || row >= nRows() || col < 0 || col >= nCols()) {
        throw std::out_of_range("Going outside the matrix");
    }
    return data_[row][col];
}

const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
    std::ptrdiff_t row = i;
    std::ptrdiff_t col = j;
    if (row < 0 || row >= nRows() || col < 0 || col >= nCols()) {
        throw std::out_of_range("Going outside the matrix");
    }
    return data_[row][col];
}

const SizeType& MatrixS::ssize() const noexcept {
    return size_;
}

void MatrixS::resize(const SizeType& new_size) {
    std::ptrdiff_t new_rows = std::get<0>(new_size);
    std::ptrdiff_t new_cols = std::get<1>(new_size);

    if (new_rows == nRows() && new_cols == nCols()) {
        return;
    }

    if (new_rows <= 0 || new_cols <= 0) {
        throw std::invalid_argument("new_rows <= 0 or new_cols <= 0");
    }
    else {
        int** new_data = new int* [new_rows];
        for (int i = 0; i < new_rows; i += 1) {
            new_data[i] = new int[new_cols];
            for (int j = 0; j < new_cols; j += 1) {
                new_data[i][j] = 0;
            }
        }
        for (int i = 0; i < std::min(nRows(), new_rows); i += 1) {
            for (int j = 0; j < std::min(nCols(), new_cols); j += 1) {
                new_data[i][j] = data_[i][j];
            }
        }
        for (int i = 0; i < nRows(); i += 1) {
            delete[] data_[i];
        }
        delete[] data_;

        data_ = new_data;
        size_ = std::make_tuple(new_rows, new_cols);
    }

}

void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    std::ptrdiff_t new_rows = i;
    std::ptrdiff_t new_cols = j;

    if (new_rows == nRows() && new_cols == nCols()) {
        return;
    }

    if (new_rows <= 0 || new_cols <= 0) {
        throw std::invalid_argument("new_rows <= 0 or new_cols <= 0");
    }
    else {
        int** new_data = new int* [new_rows];
        for (int i = 0; i < new_rows; i += 1) {
            new_data[i] = new int[new_cols];
            for (int j = 0; j < new_cols; j += 1) {
                new_data[i][j] = 0;
            }
        }
        for (int i = 0; i < std::min(nRows(), new_rows); i += 1) {
            for (int j = 0; j < std::min(nCols(), new_cols); j += 1) {
                new_data[i][j] = data_[i][j];
            }
        }
        for (int i = 0; i < nRows(); i += 1) {
            delete[] data_[i];
        }
        delete[] data_;

        data_ = new_data;
        size_ = std::make_tuple(new_rows, new_cols);

    }
}

std::ptrdiff_t MatrixS::nRows() const noexcept {
    return std::get<0>(size_);
}

std::ptrdiff_t MatrixS::nCols() const noexcept {
    return std::get<1>(size_);
}

