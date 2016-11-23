#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(double r, Colors color = Colors::BLUE);
    Circle(const Circle & other);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    std::string getName() const override;
    void print() const override;
    uint getColor() const override;
    [[deprecated("Please use M_PI instead")]] double getPi() const;
    Circle() = delete; // doesn't allow to call default constructor
private:
    double r_;
};
