#pragma once

#include "Rectangle.hpp"

class Square final : public Rectangle
{
public:
    Square(double x, Colors color = Colors::RED);
    Square(const Square & other);

    double getArea() const override;
    double getPerimeter() const override;
    std::string getName() const override;
    void print() const override;
    uint getColor() const override;
    Square() = delete;

private:
    double getY() = delete; // should not have Y dimension
};
