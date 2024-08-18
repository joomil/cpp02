#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called\n";
    _value = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called\n";
    _value = f._value;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called\n";
    if (this!= &f) { // Protect against invalid self-assignment
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
    std::cout << "getRawBits member function called\n";
    return _value;
}

// Member function to set the raw value
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    _value = raw;
}
