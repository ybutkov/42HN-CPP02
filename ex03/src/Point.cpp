/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:39:03 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/12 22:54:35 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point& Point::operator=(const Point& other)
{
    if (this == &other) return *this;
    // This is not good
    const_cast<Fixed&>(x) = other.x;
    const_cast<Fixed&>(y) = other.y;
    return *this;
}

const Fixed& Point::getX() const
{
    return this->x;
}

const Fixed& Point::getY() const
{
    return this->y;
}
