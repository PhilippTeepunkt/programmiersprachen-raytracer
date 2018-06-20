#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <string>
#include "color.hpp"

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
    Shape(),
    min_{min},
    max_{max}
{};

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Color const& color):
    Shape(name,color),
    min_{min},
    max_{max}
{};

//getter
glm::vec3 Box::min()const
{
    return min_;
}

glm::vec3 Box::max()const
{
    return max_;
}

//overided methods of base class
double Box::area()const
{
    double length{abs(max_.x-min_.x)};
    double width{abs(max_.y-min_.y)};
    double height{abs(max_.z-min_.z)};
    return 2*(length*width)+2*(length*height)+2*(width*height);
}

double Box::volume()const
{
    double length{abs(max_.x-min_.x)};
    double width{abs(max_.y-min_.y)};
    double height{abs(max_.z-min_.z)};
    return length*width*height;
}

std::ostream& Box::print(std::ostream& os)const
{
    os<<"Name: "<<name()<<",\n";
    os<<"Color: "<<color()<<",\n";
    os<<"Area: "<<area()<<"FE,\n";
    os<<"Volume: "<<volume()<<"VE, \n";
    os<<"Minimum: ("<<min_.x<<","<<min_.y<<","<<min_.z<<",\n";
    os<<"Maximum: ("<<max_.x<<","<<max_.y<<","<<max_.z<<",\n";
    return os;
}