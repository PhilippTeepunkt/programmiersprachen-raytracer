#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include "color.hpp"

class Shape
{
    public:

        Shape(std::string const& name,Color const& color):
            name_{name},
            color_{color}
        {};

        Shape():
            name_{"noname"},
            color_{Color{0.0f,0.0f,0.0f}}
        {};

        virtual double area()const = 0;
        virtual double volume()const = 0;
        std::string name()const{return name_;};
        Color color()const{return color_;};

    private:
        std::string name_;
        Color color_;   
};

#endif

