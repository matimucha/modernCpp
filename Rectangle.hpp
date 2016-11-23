#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y, Colors color = Colors::GREEN);
    Rectangle(const Rectangle & other);

    double getArea() const;
    double getPerimeter() const;
    double getX() const;
    double getY() const;
    uint getColor() const;
    std::string getName() const;
    void print() const;

    Rectangle() = delete;

private:
    double x_;
    double y_;
};
