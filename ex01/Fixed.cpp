#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    _value = 0;
}

// Constructor taking an integer
Fixed::Fixed(int const val) {
    std::cout << "Int constructor called\n";
    _value = roundf(val * pow(2, _fractional_bits));
}

// Constructor taking a float
Fixed::Fixed(float const val) {
    std::cout << "Float constructor called\n";
    _value = roundf(val * pow(2, _fractional_bits));
}

// Copy constructor
Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called\n";
    _value = f._value;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called\n";
    if (this!= &f) {
        _value = f._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

// Member function to get the raw value
int Fixed::getRawBits(void) const {
    return _value;
}

// Member function to set the raw value
void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// Converts to float
float Fixed::toFloat(void) const {
    return (_value / pow(2, _fractional_bits));
}

// Converts to int
int Fixed::toInt(void) const {
    return _value / pow(2, _fractional_bits);
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
