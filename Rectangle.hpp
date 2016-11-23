#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y, Colors color = Colors::GREEN);
    Rectangle(const Rectangle & other);

    double getArea() const override;
    double getPerimeter() const override;
    double getX() const;
    double getY() const;
    uint getColor() const override;
    std::string getName() const override;
    void print() const override;

    Rectangle() = delete;

private:
    double x_;
    double y_;
};
