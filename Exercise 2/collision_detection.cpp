#include "collision_detection.hpp"

bool isCircleRectangleColliding(float circle_x, float circle_y, float radius,
                                float rectangle_x, float rectangle_y, float rectangleWidth, float rectangleHeight) {
    float edge_x = circle_x;
    float edge_y = circle_y;

    if (circle_x < rectangle_x)
        edge_x = rectangle_x;
    else if (circle_x > rectangle_x + rectangleWidth)
        edge_x = rectangle_x + rectangleWidth;
    if (circle_y < rectangle_y)
        edge_y = rectangle_y;
    else if (circle_y > rectangle_y + rectangleHeight)
        edge_y = rectangle_y + rectangleHeight;

    float length_x = circle_x - edge_x;
    float length_y = circle_y - edge_y;
    float length = std::sqrt((length_x * length_x) + (length_y * length_y));

    if (length <= radius) return true;
    else return false;
}