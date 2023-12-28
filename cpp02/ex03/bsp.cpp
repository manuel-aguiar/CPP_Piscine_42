/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:16:55 by codespace         #+#    #+#             */
/*   Updated: 2023/12/28 13:45:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*

https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle

*/


/*
function ptInTriangle(p, p0, p1, p2) {
    var A = 1/2 * (-p1.y * p2.x + p0.y * (-p1.x + p2.x) + p0.x * (p1.y - p2.y) + p1.x * p2.y);
    var sign = A < 0 ? -1 : 1;
    var s = (p0.y * p2.x - p0.x * p2.y + (p2.y - p0.y) * p.x + (p0.x - p2.x) * p.y) * sign;
    var t = (p0.x * p1.y - p0.y * p1.x + (p0.y - p1.y) * p.x + (p1.x - p0.x) * p.y) * sign;

    return s > 0 && t > 0 && (s + t) < 2 * A * sign;
}
*/


bool	bsp(const Point& target, const Point& a, const Point& b, const Point& c)
{
	Fixed tx = target.get_x();
	Fixed ty = target.get_y();
	Fixed ax = a.get_x();
	Fixed ay = a.get_y();
	Fixed bx = b.get_x();
	Fixed by = b.get_y();
	Fixed cx = c.get_x();
	Fixed cy = c.get_y();

    Fixed A = 1/2 * (by.toFloat() * -1 * cx + ay * (-bx + cx) + ax * (by - cy) + bx * cy);
    int sign = A < 0 ? -1 : 1;
    Fixed s = (ay * cx - ax * cy + (cy - ay) * tx + (ax - cx) * ty) * sign;
    Fixed t = (ax * by - ay * bx + (ay - by) * tx + (bx - ax) * ty) * sign;

    return (s > 0 && t > 0 && (s + t) < 2 * A * sign);
}
