#ifndef POINT_H
#define	POINT_H

#include <cmath>

struct Point {
    double x, y;
};
Point operator+(Point a, Point b);
Point operator-(Point a, Point b);
Point operator*(Point a, double b);
Point operator*(double b, Point a);
double abs(Point a);

#endif	/* POINT_H */

