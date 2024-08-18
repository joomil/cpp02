#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value; // Stores the fixed-point number value
    static const int _fractional_bits = 8; // Number of fractional bits

public:
    Fixed(); // Default constructor
    Fixed(const Fixed&); // Copy constructor
    Fixed& operator=(const Fixed&); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits(void) const; // Returns the raw value of the fixed-point value
    void setRawBits(int const raw); // Sets the raw value of the fixed-point number
};

#endif // FIXED_HPP
