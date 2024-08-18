#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(float const value);
    Fixed(const Fixed& f);
    ~Fixed();

    Fixed& operator=(const Fixed& f);

    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    Fixed& operator++(); // Pre-increment
    Fixed operator++(int); // Post-increment
    Fixed& operator--(); // Pre-decrement
    Fixed operator--(int); // Post-decrement

    static Fixed& min(Fixed& lhs, Fixed& rhs);
    static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
    static Fixed& max(Fixed& lhs, Fixed& rhs);
    static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

    int getRawValue() const;
    void setRawValue(int const raw);

    float toFloat() const;
    int toInt() const;

private:
    int _rawValue;
    static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
