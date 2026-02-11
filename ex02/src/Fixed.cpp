/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:43:34 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/11 21:02:57 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void)
	: rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
// Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
	// value = other.getRawBits();
	*this = other;
}

Fixed::Fixed(int const intValue)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits = intValue << NUMBER_OF_FRACTIONAL_BITS;
}

Fixed::Fixed(float const floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	int64_t	tmpBigInt;
	tmpBigInt = static_cast<int64_t>(std::roundf(floatValue
				* (1 << NUMBER_OF_FRACTIONAL_BITS)));
	this->rawBits = static_cast<int>(tmpBigInt);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->rawBits = other.rawBits;
	}
	return (*this);
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
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(rawBits) / (1 << NUMBER_OF_FRACTIONAL_BITS));
}

int Fixed::toInt(void) const
{
	return (rawBits >> NUMBER_OF_FRACTIONAL_BITS);
}
