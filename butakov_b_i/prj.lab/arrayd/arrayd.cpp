#include <arrayd/arrayd.hpp>
#include <iostream>

// создание, доступ к обьектам и resize
// проверка доступа к элементам по индексу с исключениями
// нулевые double лежат

//remove



ArrayD::ArrayD() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 1;
}

ArrayD::ArrayD(const ArrayD& rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = new double[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; i += 1) {
        data_[i] = rhs.data_[i];
    }
}

ArrayD::ArrayD(std::initializer_list<double> lst) {
    size_ = lst.size();
    capacity_ = size_;
    data_ = new double[capacity_];
    std::copy(lst.begin(), lst.end(), data_);
}

ArrayD::ArrayD(const std::ptrdiff_t size) {
    size_ = size;
    data_ = new double[size];
    for (int i = 0; i < size; i += 1) {
        data_[i] = 0.0;
    }
    capacity_ = size;
}

ArrayD::~ArrayD() {
    delete[] data_;
}

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] data_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    data_ = new double[capacity_];
    for (int i = 0; i < size_; i += 1) {
        data_[i] = rhs.data_[i];
    }
    
    return *this;
}

double& ArrayD::operator[](const std::ptrdiff_t i) {
    if (i < 0 || i >= size_ || (i == 0 && size_ == 0)) {
        throw std::out_of_range("Going outside the array");
    }
    return data_[i];
}

const double& ArrayD::operator[](const std::ptrdiff_t i) const {
    if (i < 0 || i >= size_ || (i == 0 && size_ == 0)) {
        throw std::out_of_range("Going outside the array");
    }
    return data_[i];
}

void ArrayD::push_back(const double val) {
    if (size_ == capacity_) {
        capacity_ += 1;
    }
    size_ += 1;
    double* new_data = new double[size_];
    for (int i = 0; i < size_ - 1; i += 1) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    new_data[size_ - 1] = val;
    data_ = new_data;
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return size_;
}

void ArrayD::insert(std::ptrdiff_t i, const double val) {
    if (i < 0 || i > size_) {
        throw std::invalid_argument("Going outside the array");
    }
    else {
        if (size_ == capacity_) {
            capacity_ *= 2;
        }
        double* new_data = new double[capacity_];
        std::copy(data_, data_ + i, new_data);
        new_data[i] = val;
        std::copy(data_ + i, data_ + size_, new_data + i + 1);
        delete[] data_;
        data_ = new_data;
        size_ += 1;
    }
}

void ArrayD::remove(const std::ptrdiff_t i) {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("Going outside the array");
    }
    else {
        double* new_data = new double[capacity_];
        std::copy(data_, data_ + i, new_data);
        std::copy(data_ + i + 1, data_ + size_, new_data + i);
        delete[] data_;
        data_ = new_data;
        size_ -= 1;
    }
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    if (new_size <= 0) {
        throw std::invalid_argument("size <= 0");
    }
    else {
        if (new_size > size_) {
            double* new_data = new double[new_size];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
            for (int i = size_; i < new_size; i += 1) {
                new_data[i] = 0.0;
            }
            size_ = new_size;
            capacity_ = new_size;
        }
        else if (new_size < size_) {
            double* new_data = new double[new_size];
            for (int i = 0; i < new_size; i += 1) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            size_ = new_size;
            capacity_ = new_size;
        }
    }
}

bool ArrayD::operator==(const ArrayD& rhs) const noexcept {
    if (size_ != rhs.size_) {
        return false;
    }
    else {
        for (int i = 0; i < size_; i += 1) {
            if (data_[i] != rhs.data_[i]) {
                return false;
            }
        }
    }
    return true;
}
