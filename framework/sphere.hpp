#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"
#include <iostream>

class Sphere : public Shape
{
    public:
        Sphere(glm::vec3 const& mid, double const& rad);
        Sphere(glm::vec3 const& mid, double const& rad,std::string const& name, Color const& color);
        glm::vec3 mid()const;
        double rad()const;
        double area()const override;
        double volume()const override;

        std::ostream& print(std::ostream& os)const override;

    private:
        glm::vec3 mid_;
        double rad_;
};
#endif