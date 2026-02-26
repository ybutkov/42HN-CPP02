/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:49:45 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/26 23:11:05 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <iomanip>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

namespace
{
void	testBspFunc(Point const &a, Point const &b, Point const &c,
		Point const &point, bool expected, int numberOfTests)
{
	bool result = bsp(a, b, c, point);
	std::cout << "Test " 
			  << std::setw(2)
			  << numberOfTests << ": point is "
			  << std::setw(10)
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

	// Second triangle
	Point d(50.0f, 50.0f);
	Point e(60.0f, 51.0f);
	Point f(55.0f, 57.0f);

	testBspFunc(d, e, f, Point(55.0f, 53.0f), true, 11);	// inside
	testBspFunc(d, e, f, Point(52.0f, 52.0f), true, 12);	// inside left
	testBspFunc(d, e, f, Point(58.0f, 52.0f), true, 13);	// inside right
	testBspFunc(d, e, f, Point(55.0f, 50.5f), false, 14);	// on edge
	testBspFunc(d, e, f, Point(40.0f, 40.0f), false, 15);	// far outside

	// Third triangle
	Point g(100.0f, 100.0f);
	Point h(110.0f, 102.0f);
	Point i(105.0f, 107.0f);

	testBspFunc(g, h, i, Point(105.0f, 103.0f), true, 16);	// inside
	testBspFunc(g, h, i, Point(102.0f, 102.0f), true, 17);	// inside left
	testBspFunc(g, h, i, Point(108.0f, 102.0f), true, 18);	// inside right
	testBspFunc(g, h, i, Point(105.0f, 100.5f), false, 19);	// on edge
	testBspFunc(g, h, i, Point(90.0f, 90.0f), false, 20);	// far outside
  
	return (0);
}
