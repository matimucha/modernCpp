#pragma once

#include <string>

enum Colors : unsigned char
{
    RED = 10,
    GREEN = 20,
    BLUE = 30
};

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string getName() const;
    virtual void print() const;
    virtual uint getColor() const;
protected:
    Colors color;
};
