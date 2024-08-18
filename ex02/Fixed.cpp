#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawValue(0) {}

Fixed::Fixed(float const value) {
    _rawValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& f) {
    *this = f;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& f) {
    if (this != &f) {
        _rawValue = f.getRawValue();
    }
    return *this;
}

bool Fixed::operator>(const Fixed& rhs) const {
    return _rawValue > rhs._rawValue;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return _rawValue < rhs._rawValue;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return _rawValue >= rhs._rawValue;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return _rawValue <= rhs._rawValue;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return _rawValue == rhs._rawValue;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return _rawValue != rhs._rawValue;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawValue(_rawValue + rhs.getRawValue());
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawValue(_rawValue - rhs.getRawValue());
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    result.setRawValue((_rawValue * rhs.getRawValue()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed result;
    result.setRawValue((_rawValue << _fractionalBits) / rhs.getRawValue());
    return result;
}

Fixed& Fixed::operator++() {
    ++_rawValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++_rawValue;
    return tmp;
}

Fixed& Fixed::operator--() {
    --_rawValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --_rawValue;
    return tmp;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
    return (lhs < rhs) ? lhs : rhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
    return (lhs < rhs) ? lhs : rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

int Fixed::getRawValue() const {
    return _rawValue;
}

void Fixed::setRawValue(int const raw) {
    _rawValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _rawValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
