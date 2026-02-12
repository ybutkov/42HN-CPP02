/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:43:34 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/11 22:45:04 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <limits>

Fixed::Fixed(void): rawBits(0) {}

Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits) {}

Fixed::Fixed(int const intValue): rawBits(intValue << NUMBER_OF_FRACTIONAL_BITS) {}

Fixed::Fixed(float const floatValue)
{
	int64_t	tmpBigInt;
	tmpBigInt = static_cast<int64_t>(std::roundf(floatValue
				* (1LL << NUMBER_OF_FRACTIONAL_BITS)));
	this->rawBits = static_cast<int>(tmpBigInt);
}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->rawBits = other.rawBits;
	}
	return (*this);
}

Fixed& Fixed::operator++()
{
	rawBits++;
	return *this;	
}

Fixed Fixed::operator++(int)
{
	Fixed res = *this;
	++*this;
	return res;
}

Fixed& Fixed::operator--()
{
	rawBits--;
	return *this;	
}

Fixed Fixed::operator--(int)
{
	Fixed res = *this;
	--*this;
	return res;
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->rawBits < other.rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->rawBits <= other.rawBits);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->rawBits > other.rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->rawBits >= other.rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->rawBits == other.rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->rawBits != other.rawBits);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed	res;
	res.rawBits = this->rawBits + other.rawBits;
	return (res);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed	res;
	res.rawBits = this->rawBits - other.rawBits;
	return (res);
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed	res;
	int64_t	tmpBigInt;
	tmpBigInt = static_cast<int64_t>(this->rawBits)
		* static_cast<int64_t>(other.rawBits);
	res.rawBits = static_cast<int>(tmpBigInt >> NUMBER_OF_FRACTIONAL_BITS);
	return (res);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.rawBits == 0)
		return (Fixed(std::numeric_limits<int>::max() >> NUMBER_OF_FRACTIONAL_BITS));
	Fixed	res;
	int64_t	tmpBigInt;
	tmpBigInt = (static_cast<int64_t>(this->rawBits) << NUMBER_OF_FRACTIONAL_BITS)
		/ other.rawBits;
	res.rawBits = static_cast<int>(tmpBigInt);
	return (res);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}

int Fixed::getRawBits(void) const
{
	return (rawBits);
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(static_cast<double>(rawBits) / (1LL << NUMBER_OF_FRACTIONAL_BITS)));
}

int Fixed::toInt(void) const
{
	return (rawBits >> NUMBER_OF_FRACTIONAL_BITS);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}
