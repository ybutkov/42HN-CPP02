/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:39:55 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/11 00:06:14 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	static constexpr int NUMBER_OF_FRACTIONAL_BITS = 8;
	int rawBits;

  public:
	Fixed();
	Fixed(int const intValue);
	Fixed(float const floatValue);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
