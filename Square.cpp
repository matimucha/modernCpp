#include "Square.hpp"
#include <iostream>

Square::Square(double x, Colors rectangleColor)
    : Rectangle(x, x)
{
    color = rectangleColor;
}

Square::Square(const Square &other)
    : Rectangle(other.getX(), other.getX())
{}

double Square::getArea()
{
    return getX() * getX();
}

double Square::getPerimeter()
{
    return 4 * getX();
}

uint Square::getColor() const
{
    return Shape::getColor();
}

std::string Square::getName() const
{
    return "Square";
}

void Square::print()
{
    std::cout << getName() << ":    x: " << getX()
              << ", area: " << getArea()
              << ", perimeter: " << getPerimeter() << std::endl;
}
