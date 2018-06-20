#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <cmath>
#include "../framework/sphere.hpp"
#include "../framework/box.hpp"
#include "../framework/color.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("general tests","[shapes]")
{
  SECTION("constructors")
  {
    glm::vec3 mid{0.0,0.0,0.0};
    double radius{2.5};
    glm::vec3 max{3.0,-3.0,3.0};
    Color color{1.0f,0.0f,0.0f};

    Sphere s1{mid,radius,"Sphere1",color};
    Box b1{mid,max};

    REQUIRE(s1.mid().x==mid.x); 
    REQUIRE(s1.mid().y==mid.y);
    REQUIRE(s1.mid().z==mid.z);

    REQUIRE(s1.rad()==2.5);
    REQUIRE(s1.color().r==1.0f);
    REQUIRE(s1.name().compare("Sphere1")==0.0);

    REQUIRE(b1.min().x==mid.x);
    REQUIRE(b1.min().y==mid.y);
    REQUIRE(b1.min().z==mid.z);

    REQUIRE(b1.max().x==max.x);
    REQUIRE(b1.max().y==max.y);
    REQUIRE(b1.max().z==max.z);

    REQUIRE(b1.name().compare("noname")==0.0);
    REQUIRE(b1.color().r==0.0f);
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

TEST_CASE("operator and print","[shapes]")
{
  glm::vec3 mid3{0.0,0.0,0.0};
  double radius3{3.5};
  Sphere s3{mid3,radius3};

  glm::vec3 min3{1.0,1.0,1.0};
  glm::vec3 max3{-3.0,-3.0,-3.0};
  Box b3{min3,max3};

  std::cout<<s3<<"\n";
  std::cout<<b3<<"\n";
}

TEST_CASE("intersect_ray_sphere","[intersect]")
{
  //Ray
  glm::vec3 ray_origin{0.0f,0.0f,0.0f};
  //ray direction has to be normalized!
  //you can use: 
  //v=glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f,0.0f,1.0f};

  //Sphere
  glm::vec3 sphere_center{0.0f,0.0f,5.0f};
  float sphere_radius{1.0f};

  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
    ray_origin,
    ray_direction,
    sphere_center,
    sphere_radius*sphere_radius, //squared radius!!
    distance);

  REQUIRE(distance == Approx(4.0f));

  //Custom spheres
  glm::vec3 mid4{0.0,0.0,5.0};
  double radius4{1.0};
  Color color4{1.0f,0.0f,0.0f};
  Sphere s4{mid4,radius4,"Sphere2",color4};

  float distance2 = 0.0f;
  REQUIRE(!s4.intersect(Ray{},distance));
  REQUIRE(distance == Approx(-4.0f));

  glm::vec3 mid5{0.0,0.0,-5.0};
  double radius5{1.0};
  Color color5{1.0f,1.0f,0.0f};
  Sphere s5{mid5,radius5,"Sphere3",color5};
  
  REQUIRE(s5.intersect(Ray{},distance));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
