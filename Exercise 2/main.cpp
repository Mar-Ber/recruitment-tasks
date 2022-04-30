#include <SFML/Graphics.hpp>
#include "collision_detection.hpp"

int main()
{
    const int windowWidth = 640;
    const int windowHeight = 480;
    const int frameRate = 30;
    const float radius = 50.0;
    const float rectangleWidth = 200.0;
    const float rectangleHeight = 50.0;
    const float rectPositionWidth = 420.0;
    const float rectPositionHeight = 240.0;
    const float alpha = 5.0;
    const float thickness = 2.0;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Intersecting");
    window.setFramerateLimit(frameRate);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color(255,0,0));
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(thickness);
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(windowWidth/2.f, windowHeight/2.f);

    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color(255,150,150));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(thickness);
    rectangle.setSize(sf::Vector2f(rectangleWidth,rectangleHeight));
    rectangle.setOrigin(rectangleWidth/2.f, rectangleHeight/2.f);
    rectangle.setPosition(rectPositionWidth, rectPositionHeight);

    sf::CircleShape dot;
    dot.setFillColor(sf::Color::Black);
    dot.setRadius(thickness);
    dot.setOrigin(thickness, thickness);
    dot.setPosition(rectPositionWidth, rectPositionHeight);

    sf::CircleShape border;
    border.setFillColor(sf::Color(0,0,0,0));
    border.setOutlineColor(sf::Color(0,0,0,255));
    border.setOutlineThickness(thickness);
    border.setRadius(radius);
    border.setOrigin(radius, radius);
    border.setPosition(windowWidth/2.f, windowHeight/2.f);

    const auto pi = (float) std::acos(-1);
    float rect_x = rectPositionWidth, rect_y = rectPositionHeight;
    float relativePrevCircle_x = windowWidth/2.f, relativePrevCircle_y = windowHeight/2.f;
    float relativeCircle_x = windowWidth/2.f, relativeCircle_y = windowHeight/2.f;

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            rectangle.rotate(-alpha);

            relativeCircle_x = rect_x + (relativePrevCircle_x-rect_x) * std::cos(-alpha*pi/180) - (relativePrevCircle_y-rect_y) * std::sin(-alpha*pi/180);
            relativeCircle_y = rect_y + (relativePrevCircle_x-rect_x) * std::sin(-alpha*pi/180) + (relativePrevCircle_y-rect_y) * std::cos(-alpha*pi/180);
            relativePrevCircle_x = relativeCircle_x;
            relativePrevCircle_y = relativeCircle_y;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            rectangle.rotate(alpha);

            relativeCircle_x = rect_x + (relativePrevCircle_x-rect_x) * std::cos(alpha*pi/180) - (relativePrevCircle_y-rect_y) * std::sin(alpha*pi/180);
            relativeCircle_y = rect_y + (relativePrevCircle_x-rect_x) * std::sin(alpha*pi/180) + (relativePrevCircle_y-rect_y) * std::cos(alpha*pi/180);
            relativePrevCircle_x = relativeCircle_x;
            relativePrevCircle_y = relativeCircle_y;
        }

        if (isCircleRectangleColliding(relativeCircle_x, relativeCircle_y, radius+thickness,
                                      rectPositionWidth-rectangleWidth/2.f, rectPositionHeight-rectangleHeight/2.f,
                                      rectangleWidth,rectangleHeight)) {
            circle.setFillColor(sf::Color(0,200,0));
            rectangle.setFillColor(sf::Color(128,250,0));
        }
        else {
            circle.setFillColor(sf::Color(255,0,0));
            rectangle.setFillColor(sf::Color(255,150,150));
        }

        window.clear(sf::Color::White);
        window.draw(circle);
        window.draw(rectangle);
        window.draw(dot);
        window.draw(border);
        window.display();
    }
}