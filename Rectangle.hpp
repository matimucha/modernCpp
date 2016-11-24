#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(Colors rectangleColor);
    Rectangle(double x, double y, Colors color = Colors::GREEN);
    Rectangle(const Rectangle & other);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
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
