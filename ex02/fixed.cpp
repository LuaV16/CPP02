#include "fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(n << fracBits);
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    int raw;

    raw = roundf(n * 256);
    setRawBits(raw);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;  
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.value;
    return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
    if (this->value > other.value)
        return (true);
    else
        return (false);
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->value < other.value)
        return (true);
    else
        return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->value >= other.value)
        return (true);
    else
        return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->value <= other.value)
        return (true);
    else
        return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->value == other.value)
        return (true);
    else
        return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->value != other.value)
        return (true);
    else
        return (false);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->value + other.value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->value - other.value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->value * other.value) >> 8);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->value << 8) / other.value);
    return (result);
}

Fixed& Fixed::operator++()
{
    this->value = this->value + 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed prev(*this);
    this->value = this->value + 1;
    return (prev);
}

Fixed& Fixed::operator--()
{
    this->value = this->value - 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed prev(*this);
    this->value = this->value - 1;
    return (prev);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float Fixed::toFloat( void ) const
{
    return (this->value / 256.0f);
}

int Fixed::toInt( void ) const
{
    return (this->value >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

Fixed& Fixed::min(Fixed& ref1, Fixed& ref2)
{
    if (ref1 < ref2)
        return (ref1);
    else
        return (ref2);
}

const Fixed& Fixed::min(const Fixed& ref1, const Fixed& ref2)
{
    if (ref1 < ref2)
        return (ref1);
    else
        return (ref2);
}

Fixed& Fixed::max(Fixed& ref1, Fixed& ref2)
{
    if (ref1 > ref2)
        return (ref1);
    else
        return (ref2);
}

const Fixed& Fixed::max(const Fixed& ref1, const Fixed& ref2)
{
    if (ref1 > ref2)
        return (ref1);
    else
        return (ref2);
}