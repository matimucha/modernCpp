#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(double r, Colors color = Colors::BLUE);
    Circle(const Circle & other);

    double getArea() const;
    double getPerimeter() const;
    double getRadius() const;
    std::string getName() const;
    void print() const;
    uint getColor() const;
    Circle() = delete; // doesn't allow to call default constructor
private:
    double r_;
};
