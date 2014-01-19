#include "Point.h"

Point operator+(Point a, Point b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(Point a, Point b) {
    return {a.x-b.x, a.y-b.y};
}

Point operator*(Point a, double b) {
    return {a.x*b, a.y*b};
}

Point operator*(double b, Point a) {
    return a*b;
}

double abs(Point a) {
    return sqrt(a.x*a.x + a.y*a.y);
}