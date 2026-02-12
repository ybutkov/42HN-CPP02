/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:33:08 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/12 22:53:10 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
    const Fixed x;
    const Fixed y;
public:
    Point(float x=0.0f, float y=0.0f): x(x), y(y) {};
    Point(const Point& other): x(other.x), y(other.y) {};
    ~Point() = default;
    Point& operator=(const Point& other);
    const Fixed& getX() const;
    const Fixed& getY() const;
};
