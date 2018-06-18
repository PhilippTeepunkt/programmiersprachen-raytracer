#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <cmath>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("general tests","[shapes]")
{
  SECTION("constructors")
  {
    glm::vec3 mid{0.0,0.0,0.0};
    double radius{2.5};
    glm::vec3 max{3.0,-3.0,3.0};

    Sphere s1{mid,radius};
    Box b1{mid,max};

    REQUIRE(s1.mid().x==mid.x); 
    REQUIRE(s1.mid().y==mid.y);
    REQUIRE(s1.mid().z==mid.z);

    REQUIRE(s1.rad()==2.5);

    REQUIRE(b1.min().x==mid.x);
    REQUIRE(b1.min().y==mid.y);
    REQUIRE(b1.min().z== mid.z);

    REQUIRE(b1.max().x==max.x);
    REQUIRE(b1.max().y==max.y);
    REQUIRE(b1.max().z== max.z);
  }

  SECTION("sphere methods")
  {
    glm::vec3 mid{0.0,0.0,0.0};
    double radius{3.5};
    Sphere s2{mid,radius};
    REQUIRE(s2.area()==Approx(153.938));
    REQUIRE(s2.volume()==Approx(179.594));
  }

  SECTION("box methods")
  {
    glm::vec3 min2{1.0,1.0,1.0};
    glm::vec3 max2{-3.0,-3.0,-3.0};
    Box b2{min2,max2};
    REQUIRE(b2.area()==Approx(96.0));
    REQUIRE(b2.volume()==Approx(64));
  }
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
