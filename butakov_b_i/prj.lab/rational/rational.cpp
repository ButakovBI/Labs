// Copyright 2023 by butakov_b_i under Free Public License 1.0.0

#include <rational/rational.hpp>
#include <iostream>
#include <stdexcept>
#include <string>


Rational::Rational(const int32_t num) noexcept {
    num_ = num;
    den_ = 1;
    normalize();
}

Rational::Rational(const int32_t num, const int32_t denom) {
    num_ = num;
    if (denom == 0) {
        throw std::out_of_range("Denominator can't be zero");
    }
    den_ = denom;
    if (num > 0 && denom < 0) {
        num_ = -num;
        den_ = -denom;
    }
    else if (num < 0 && denom < 0) {
        num_ = -num;
        den_ = -denom;
    }
    normalize();
}

int32_t gcd(int32_t a, int32_t b) {
    return (b == 0) ? a : gcd(b, a % b);
}

void Rational::normalize() noexcept {
    int g = gcd(abs(num_), abs(den_));

    if (num_ < 0 && den_ < 0) {
        num_ = num_ * -1;
        den_ = den_ * -1;
    }
    else if (num_ < 0 || den_ < 0) {
        num_ = abs(num_) * -1;
        den_ = abs(den_);
    }

    num_ /= g;
    den_ /= g;
}

Rational Rational::operator-() const noexcept {
    return Rational(-num(), denom());
}


bool Rational::operator==(const Rational& rhs) const noexcept {
    return (num() == rhs.num() && denom() == rhs.denom());
}

bool Rational::operator!=(const Rational& rhs) const noexcept {
    return (num() != rhs.num() || denom() != rhs.denom());
}

bool Rational::operator>(const Rational& rhs) const noexcept {
    return (num() * rhs.denom() > denom() * rhs.num());
}

bool Rational::operator<(const Rational& rhs) const noexcept {
    return (num() * rhs.denom() < denom() * rhs.num());
}

bool Rational::operator>=(const Rational& rhs) const noexcept {
    return (num() * rhs.denom() >= denom() * rhs.num());
}

bool Rational::operator<=(const Rational& rhs) const noexcept {
    return (num() * rhs.denom() <= denom() * rhs.num());
}

Rational::operator bool() const noexcept {
    return (num_ != 0);
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num_ = num() * rhs.denom() + denom() * rhs.num();
    den_ = denom() * rhs.denom();
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num() * rhs.denom() - denom() * rhs.num();
    den_ = denom() * rhs.denom();
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ = num() * rhs.num();
    den_ = denom() * rhs.denom();
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num() == 0) {
        throw std::invalid_argument("Division by zero");
    }
    num_ = num() * rhs.denom();
    den_ = denom() * rhs.num();
    normalize();
    return *this;
}

std::istream& Rational::read_from(std::istream& istrm) noexcept {

    int32_t numerator = 0;
    char del = '0';
    int32_t denumerator = 0;

    istrm >> numerator;

    char trash = istrm.get();

    if (trash == ' ') {
        istrm.setstate(std::ios_base::failbit);
    }
    else {
        istrm.putback(trash);
        istrm >> del;
        if (del == Rational::delimiter_) {
            char trash = istrm.get();
            if (trash == ' ' || trash == '-') {
                istrm.setstate(std::ios_base::failbit);
            }
            else {
                istrm.putback(trash);
                num_ = numerator;
                istrm >> denumerator;
                if (denumerator != 0) {
                    den_ = denumerator;
                    normalize();
                }
                else {
                    istrm.setstate(std::ios_base::failbit);
                }
            }
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& Rational::write_to(std::ostream& ostrm) const noexcept {
    ostrm << num_ << delimiter_ << den_;
    return ostrm;
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
    return rhs.read_from(istrm);
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    return rhs.write_to(ostrm);
}





