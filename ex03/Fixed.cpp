#include "Fixed.hpp"
#include <cmath> // For std::pow

// Custom round function
static int customRound(float value) {
    return (value >= 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
}

// Constructors
Fixed::Fixed() : _rawValue(0) {} // Default constructor
Fixed::Fixed(int const rawValue) : _rawValue(rawValue) {} // Constructor with raw value
Fixed::Fixed(float const value) : _rawValue(customRound(value * std::pow(2, _fractionalBits))) {} // Now correctly includes cmath
Fixed::Fixed(const Fixed& f) : _rawValue(f._rawValue) {} // Copy constructor

// Assignment operator
Fixed& Fixed::operator=(const Fixed& f) {
    if (this != &f) {
        _rawValue = f._rawValue;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {}

// Getter functions
int Fixed::getRawValue() const { return _rawValue; }
float Fixed::toFloat() const { return static_cast<float>(_rawValue) / std::pow(2, _fractionalBits); }
int Fixed::toInt() const { return _rawValue; } // Placeholder, adjust as needed

// Setter functions
void Fixed::setRawValue(int const rawValue) { _rawValue = rawValue; }
void Fixed::setRawBits(int const raw) { _rawValue = raw; } // Assuming this is what you meant by setRawBits

// Arithmetic operators
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

Fixed Fixed::operator*(float scalar) const {
    Fixed result;
    result.setRawValue(_rawValue * scalar);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const { // New operator implementation
    Fixed result;
    result.setRawValue(_rawValue * rhs.getRawValue());
    return result;
}

Fixed Fixed::operator/(float scalar) const {
    Fixed result;
    result.setRawValue(_rawValue / scalar);
    return result;
}

// Comparison operators
bool Fixed::operator==(const Fixed& rhs) const {
    return _rawValue == rhs.getRawValue();
}

// Output stream operator (placeholder, adjust as needed)
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
