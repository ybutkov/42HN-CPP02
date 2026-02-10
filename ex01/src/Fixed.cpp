/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:43:34 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/11 00:11:55 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): rawBits (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
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
	rawBits = static_cast<int>(std::roundf(floatValue * (1 << NUMBER_OF_FRACTIONAL_BITS)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;	
	if (this != &other)
	{
		this->rawBits = other.rawBits;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return os << fixed.toFloat();
}
	
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;	
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits) / (1 << NUMBER_OF_FRACTIONAL_BITS);
}

int Fixed::toInt(void ) const
{
		return rawBits >> NUMBER_OF_FRACTIONAL_BITS;
}
