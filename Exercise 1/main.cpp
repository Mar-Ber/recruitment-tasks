#include "triangle.hpp"

int main() {

    triangle triangle1 {};
    triangle1.points[0] = {-2,6};
    triangle1.points[1] = {1,4};
    triangle1.points[2] = {3,7};

    triangle triangle2 {};
    triangle2.points[0] = {5,7};
    triangle2.points[1] = {4,5};
    triangle2.points[2] = {1,8};

    std::cout << isColliding(triangle1, triangle2) <<std::endl;

    return 0;
}
