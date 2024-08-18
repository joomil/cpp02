#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath> // For roundf()
#include <iostream>

class Fixed {
private:
    int _value; // Stores the fixed-point number value
    static const int _fractional_bits = 8; // Number of fractional bits

public:
    Fixed(); // Default constructor
    Fixed(int const val); // Constructor taking an integer
    Fixed(float const val); // Constructor taking a float
    Fixed(const Fixed&); // Copy constructor
    Fixed& operator=(const Fixed&); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits(void) const; // Returns the raw value of the fixed-point value
    void setRawBits(int const raw); // Sets the raw value of the fixed-point number

    float toFloat(void) const; // Converts to float
    int toInt(void) const; // Converts to int

    friend std::ostream& operator<<(std::ostream& os, const Fixed& f); // Overloaded insertion operator
};

#endif // FIXED_HPP
