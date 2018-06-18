#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : Shape
{
    public:
    
        Box(glm::vec3 const& min, glm::vec3 const& max);
        glm::vec3 min()const;
        glm::vec3 max()const;
        double area()const override;
        double volume()const override;
    
    private:
        glm::vec3 min_;
        glm::vec3 max_;
        
};

#endif