#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include "color.hpp"
#include <iostream>

class Shape
{
    public:
        Shape();
        Shape(std::string const& name,Color const& color);
        virtual ~Shape();

        virtual double area()const = 0;
        virtual double volume()const = 0;
        std::string name()const;
        Color color()const;

        virtual std::ostream& print(std::ostream& os)const;

    private:
        std::string name_;
        Color color_;   
};

std::ostream& operator<<(std::ostream& os, Shape const& s);
#endif

