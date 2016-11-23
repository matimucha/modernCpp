#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x, Colors color = Colors::RED);
    Square(const Square & other);

    double getArea();
    double getPerimeter();
    std::string getName() const;
    void print();
    uint getColor() const;
    Square() = delete;

private:
    double getY() = delete; // should not have Y dimension
};
