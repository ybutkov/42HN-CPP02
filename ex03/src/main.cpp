/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:49:45 by ybutkov           #+#    #+#             */
/*   Updated: 2026/02/13 16:22:00 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

namespace
{
  void testBspFunc(Point& a, Point& b, Point& c, Point point, bool expected, int numberOfTests)
  {
    bool result = bsp(a, b, c, point);
    std::cout << "Test "<< numberOfTests << ": point is " 
              << (result ? "inside: " : "outside: ")
              << (result == expected ? "OK" : "FAIL")
              << std::endl;  
  }
  
} // end namespace

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

  testBspFunc(a, b, c, Point(5, 5), true, 1);
  testBspFunc(a, b, c, Point(15.0f, 5.0f), false, 1);
  testBspFunc(a, b, c, Point(5.0f, 0.0f), false, 1);

  testBspFunc(a, b, c, Point(5, 5), true, 1);
  testBspFunc(a, b, c, Point(0, 10), false, 2);
  testBspFunc(a, b, c, Point(0, 0), false, 3);
  testBspFunc(a, b, c, Point(10, 0), false, 4);
  testBspFunc(a, b, c, Point(5, 10), false, 5);
  testBspFunc(a, b, c, Point(5, 0), false, 6);
  testBspFunc(a, b, c, Point(7.5, 5), false, 7);
  testBspFunc(a, b, c, Point(2.5, 5), false, 8);
  testBspFunc(a, b, c, Point(5, 3), true, 9);
  testBspFunc(a, b, c, Point(-10, -10), false, 10);
	
	return 0;
}
