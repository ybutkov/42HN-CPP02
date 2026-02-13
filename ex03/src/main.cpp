/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:49:45 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/13 16:32:33 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

namespace
{
void	testBspFunc(Point const &a, Point const &b, Point const &c,
		Point const &point, bool expected, int numberOfTests)
{
	bool result = bsp(a, b, c, point);
	std::cout << "Test " << numberOfTests << ": point is "
			  << (result ? "inside: " : "outside: ")
			  << (result == expected ? "OK" : "FAIL")
			  << std::endl;
}

} // end namespace

int	main(void)
{
	Point a(1.0f, 1.0f);
	Point b(6.0f, 2.0f);
	Point c(3.0f, 7.0f);
  
	testBspFunc(a, b, c, Point(3.0f, 3.0f), true, 1); 		// clearly inside
	testBspFunc(a, b, c, Point(0.0f, 0.0f), false, 2);		// outside
	testBspFunc(a, b, c, Point(1.0f, 1.0f), false, 3);		// at vertex a
	testBspFunc(a, b, c, Point(6.0f, 2.0f), false, 4);		// at vertex b
	testBspFunc(a, b, c, Point(3.0f, 7.0f), false, 5);		// at vertex c
	testBspFunc(a, b, c, Point(3.5f, 1.5f), false, 6);		// midpoint on edge ab
	testBspFunc(a, b, c, Point(4.5f, 4.5f), false, 7);		// midpoint on edge bc
	testBspFunc(a, b, c, Point(2.0f, 4.0f), false, 8);		// midpoint on edge ca
	testBspFunc(a, b, c, Point(3.0f, 2.0f), true, 9);		// near edge but inside
	testBspFunc(a, b, c, Point(10.0f, 10.0f), false, 10);	// far outside
  
	return (0);
}
