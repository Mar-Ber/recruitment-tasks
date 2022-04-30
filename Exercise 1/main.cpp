#include "triangle.hpp"

int main() {

    triangle triangle1 {};
    triangle1.points[0] = {1,3};
    triangle1.points[1] = {6,2};
    triangle1.points[2] = {3,6};

    triangle triangle2 {};
    triangle2.points[0] = {4,3};
    triangle2.points[1] = {4,4};
    triangle2.points[2] = {3,4};

    std::cout << "Triangle 1: " << "{" << triangle1.points[0].x << ", " <<triangle1.points[0].y << "}, "<<
              "{" << triangle1.points[1].x << ", " <<triangle1.points[1].y << "}, "<<
              "{" << triangle1.points[2].x << ", " <<triangle1.points[2].y << "}"<< std::endl;

    std::cout << "Triangle 2: " << "{" << triangle2.points[0].x << ", " <<triangle2.points[0].y << "}, "<<
              "{" << triangle2.points[1].x << ", " <<triangle2.points[1].y << "}, "<<
              "{" << triangle2.points[2].x << ", " <<triangle2.points[2].y << "}"<< std::endl;

    std::cout << "isColliding: " << isColliding(triangle1, triangle2) << std::endl;

    return 0;
}
