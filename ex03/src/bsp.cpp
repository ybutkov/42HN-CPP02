/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:44:27 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/12 23:53:57 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

namespace
{

Fixed	sign(const Point &p1, const Point &p2, const Point &p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) 
         - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

} // namespace

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool hasNeg, hasPos;
    Fixed fixedZero(0);

	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);
	hasNeg = (d1 < fixedZero) || (d2 < fixedZero) || (d3 < fixedZero);
	hasPos = (d1 > fixedZero) || (d2 > fixedZero) || (d3 > fixedZero);
	return (!(hasNeg && hasPos) && (d1 != fixedZero && d2 != fixedZero && d3 != fixedZero));
}
