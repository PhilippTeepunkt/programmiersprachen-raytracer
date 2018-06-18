#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : Shape
{
    public:
        Sphere(glm::vec3 const& mid, double const& rad);
        glm::vec3 mid()const;
        double rad()const;
        double area()const override;
        double volume()const override;

    private:
        glm::vec3 mid_;
        double rad_;
};
#endif