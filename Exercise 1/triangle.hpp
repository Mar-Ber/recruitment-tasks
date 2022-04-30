#ifndef EXERCISE_1_TRIANGLE_HPP
#define EXERCISE_1_TRIANGLE_HPP

#include <iostream>
#include <array>

struct vec2
{
    float x, y;
};

struct triangle
{
    std::array<vec2, 3> points;
};

bool isColliding(const triangle & triangle1, const triangle & triangle2);
bool isTriangleLineColliding(const triangle & triangle2, const vec2 & point1, const vec2 & point2);
bool isLineLineColliding(const vec2 & point1, const vec2 & point2, const vec2 & point3, const vec2 & point4);
bool isPointInside(const triangle & triangle, const vec2 & point);

#endif //EXERCISE_1_TRIANGLE_HPP
