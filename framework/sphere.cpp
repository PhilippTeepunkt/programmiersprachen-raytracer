#include "sphere.hpp"
#include <cmath>
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"
#include <iostream>
#include "Ray.hpp"
#include <glm/gtx/intersect.hpp>

Sphere::Sphere(glm::vec3 const& mid,double const& rad):
    Shape{},
    rad_{rad},
    mid_{mid}
{};

Sphere::Sphere(glm::vec3 const& mid, double const& rad,std::string const& name, Color const& color):
    Shape{name,color},
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

std::ostream& Sphere::print(std::ostream& os)const
{
    Shape::print(os);
    os<<"Area: "<<area()<<"FE,\n";
    os<<"Volume: "<<volume()<<"VE, \n";
    os<<"Radius: "<<rad_<<",\n";
    os<<"Center: ("<<mid_.x<<","<<mid_.y<<","<<mid_.z<<"),\n";
    return os;
}

bool Sphere::intersect(Ray const& ray,float& distance)const
{
    return glm::intersectRaySphere(ray.origin,ray.direction,mid_,rad_*rad_,distance);   
}