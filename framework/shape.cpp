#include "shape.hpp"
#include "color.hpp"
#include <iostream>
#include <string>

Shape::Shape():
    name_{"noname"},
    color_{Color{0.0f,0.0f,0.0f}}
{
    std::cout<<"Base constructor called.\n";
};

Shape::Shape(std::string const& name,Color const& color):
    name_{name},
    color_{color}
{
    std::cout<<"Base constructor called.\n";
};

Shape::~Shape()
{
    std::cout<<"Base destructor called.\n";
};

std::string Shape::name()const
{return name_;};

Color Shape::color()const
{return color_;};

std::ostream& Shape::print(std::ostream& os)const{
    return os<<"Shape name: "<<name_<<",\n"<<"Shape color: "<<color_;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
    return s.print(os);
}