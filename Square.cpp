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

double Square::getArea() const noexcept
{
    return getX() * getX();
}

double Square::getPerimeter() const noexcept
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

void Square::print() const
{
    std::cout << getName() << ":    x: " << getX()
              << ", area: " << getArea()
              << ", perimeter: " << getPerimeter() << std::endl;
}
