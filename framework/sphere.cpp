#include "sphere.hpp"
#include "shape.hpp"
#include <cmath>
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"

Sphere::Sphere(glm::vec3 const& mid,double const& rad):
    Shape(),
    rad_{rad},
    mid_{mid}
{};

Sphere::Sphere(glm::vec3 const& mid, double const& rad,std::string const& name, Color const& color):
    Shape(name,color),
    rad_{rad},
    mid_{mid}
{};

//getter
double Sphere::rad()const
{
    return rad_;
}

glm::vec3 Sphere::mid()const
{
    return mid_;
}

//overided methods of base class 
double Sphere::area()const
{
    return 4*M_PI*pow(rad_,2);
}

double Sphere::volume()const
{
    return (4.0/3.0)*M_PI*pow(rad_,3);
}