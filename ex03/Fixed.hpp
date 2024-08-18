#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _rawValue; // Corrected to match usage in Fixed.cpp
    static const int _fractionalBits = 8; // Ensure this matches your fixed-point representation

public:
    Fixed();
    Fixed(int const rawValue);
    Fixed(float const value);
    Fixed(const Fixed&);
    Fixed& operator=(const Fixed&);
    ~Fixed();

    // Getter functions
    int getRawValue() const;
    float floatValue() const;
    int getRawBits() const; // Added declaration

    // Setter functions
    void setRawValue(int const rawValue);
    void setRawBits(int const raw); // Added declaration

    // Arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(float scalar) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(float scalar) const;

    // Comparison operators
    bool operator==(const Fixed& rhs) const;

    // Conversion functions
    float toFloat() const; // Added declaration
    int toInt() const; // Added declaration

    // Output stream operator
    friend std::ostream& operator<<(std::ostream&, const Fixed&);
};

#endif // FIXED_HPP
