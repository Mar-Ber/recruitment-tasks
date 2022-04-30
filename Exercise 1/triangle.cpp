#include "triangle.hpp"

bool isColliding(const triangle & triangle1, const triangle & triangle2) {
    int j = 0;
    for (int i=0; i<3; i++) {
        if (i == 2)
            j = 0;
        else
            j = i+1;

        vec2 point1 = triangle1.points[i];
        vec2 point2 = triangle1.points[j];

        if (isTriangleLineColliding(triangle2, point1, point2)) return true;

        if (isPointInside(triangle1, triangle2.points[0])) return true;
        if (isPointInside(triangle2, triangle1.points[0])) return true;
    }
    return false;
}

bool isTriangleLineColliding(const triangle & triangle, const vec2 & point1, const vec2 & point2) {
    int j = 0;
    for (int i=0; i<3; i++) {
        if (i == 2)
            j = 0;
        else
            j = i+1;

        vec2 point3 = triangle.points[i];
        vec2 point4 = triangle.points[j];

        if (isLineLineColliding(point1, point2, point3, point4)) return true;
    }
    return false;
}

bool isLineLineColliding(const vec2 & point1, const vec2 & point2, const vec2 & point3, const vec2 & point4) {
    float uA = ((point4.x-point3.x)*(point1.y-point3.y) - (point4.y-point3.y)*(point1.x-point3.x)) /
            ((point4.y-point3.y)*(point2.x-point1.x) - (point4.x-point3.x)*(point2.y-point1.y));
    float uB = ((point2.x-point1.x)*(point1.y-point3.y) - (point2.y-point1.y)*(point1.x-point3.x)) /
            ((point4.y-point3.y)*(point2.x-point1.x) - (point4.x-point3.x)*(point2.y-point1.y));

    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
        return true;
    }
    return false;
}

bool isPointInside(const triangle & triangle, const vec2 & point) {
    bool state = false;
    int j = 0;
    for (int i=0; i<3; i++) {
        if (i == 2)
            j = 0;
        else
            j = i+1;

        vec2 point1 = triangle.points[i];
        vec2 point2 = triangle.points[j];

        if (((point1.y > point.y && point2.y < point.y) || (point1.y < point.y && point2.y > point.y)) &&
            (point.x < (point2.x-point1.x)*(point.y-point1.y) / (point2.y-point1.y)+point1.x))
            state = !state;
    }
    return state;
}