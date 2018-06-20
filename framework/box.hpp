#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"
#include <iostream>

class Box : public Shape
{
    public:
        Box(glm::vec3 const& min, glm::vec3 const& max);
        Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Color const& color);
        glm::vec3 min()const;
        glm::vec3 max()const;
        double area()const override;
        double volume()const override;
        std::ostream& print(std::ostream& os)const override;
    
    private:
        glm::vec3 min_;
        glm::vec3 max_;
        
};
#endif