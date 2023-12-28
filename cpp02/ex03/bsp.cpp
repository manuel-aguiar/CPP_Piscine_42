/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:16:55 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 14:21:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle

function ptInTriangle(p, p0, p1, p2) {
    var A = 1/2 * (-p1.y * p2.x + p0.y * (-p1.x + p2.x) + p0.x * (p1.y - p2.y) + p1.x * p2.y);
    var sign = A < 0 ? -1 : 1;
    var s = (p0.y * p2.x - p0.x * p2.y + (p2.y - p0.y) * p.x + (p0.x - p2.x) * p.y) * sign;
    var t = (p0.x * p1.y - p0.y * p1.x + (p0.y - p1.y) * p.x + (p1.x - p0.x) * p.y) * sign;

    return s > 0 && t > 0 && (s + t) < 2 * A * sign;
}

	this solution is more efficient than the sum of the 3 sub triangle areas
		totally less intuitive than sum of 3 sub-triangles
	it involves barycentric coordinates (good luck with that)

	I don't understand it so i won't use it :) here it is (using <= to account for points on the edges themselves):
	bool	bsp(const Point& target, const Point& a, const Point& b, const Point& c)
	{
		const Fixed& tx = target.get_x();
		const Fixed& ty = target.get_y();
		const Fixed& ax = a.get_x();
		const Fixed& ay = a.get_y();
		const Fixed& bx = b.get_x();
		const Fixed& by = b.get_y();
		const Fixed& cx = c.get_x();
		const Fixed& cy = c.get_y();

		Fixed A = ((by * (-1)) * cx + ay * ((bx * (-1)) + cx) + ax * (by - cy) + bx * cy) * 0.5f;
		int sign = A < 0 ? -1 : 1;
		Fixed s = (ay * cx - ax * cy + (cy - ay) * tx + (ax - cx) * ty) * sign;
		Fixed t = (ax * by - ay * bx + (ay - by) * tx + (bx - ax) * ty) * sign;

		return (s >= 0 && t >= 0 && (s + t) <= (A * 2 * sign));
	}

	Easier, sum of the 3 sub triangles (target and 2 out of 3 edges) must equal the area of
	the triangle formed by all the edges. So in total we calculate 4 triangles,
	more operations than the optimal solution

	Area of a triangle:
	The formula of area of triangle formula in coordinate geometry is:
	A = (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|,
	where (x1,y1),(x2,y2), and (x3,y3) are the coordinates of vertices of the triangle.


*/

#include "Point.hpp"

Fixed	triangle_area(const Point& a, const Point& b, const Point& c)
{
	const Fixed& ax = a.get_x();
	const Fixed& ay = a.get_y();
	const Fixed& bx = b.get_x();
	const Fixed& by = b.get_y();
	const Fixed& cx = c.get_x();
	const Fixed& cy = c.get_y();

	Fixed A = Fixed::abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) * 0.5f;
	return (A);
}

bool	bsp(const Point& target, const Point& a, const Point& b, const Point& c)
{
	Fixed all_areas[4];

	all_areas[0] = triangle_area(a, b, c);
	all_areas[1] = triangle_area(target, a, b);
	all_areas[2] = triangle_area(target, b, c);
	all_areas[3] = triangle_area(target, a, c);

    return (all_areas[0] == (all_areas[1] + all_areas[2] + all_areas[3]));
}
