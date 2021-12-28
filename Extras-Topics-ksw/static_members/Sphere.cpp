#include <cmath>
#include <stdexcept>
#include <iostream>
#include "Sphere.h"

using namespace std;

Sphere::Sphere() :radius_(0), volume_(0){}

Sphere::Sphere(float radius):radius_(radius), volume_((4.0*PI_*pow(radius_,3))/3.0)  {
   if(radius<0) throw invalid_argument("Radius <0");
}

//getter for Radius
float Sphere::Radius() const { return radius_ ;}

//Getter for volume
float Sphere::Volume() const {return volume_ ;}

//Setter for Radius, volume
void Sphere::Radius(float radius){
   if(radius<0)
      throw invalid_argument("Radius <0");
   else
      radius_ = radius;
      volume_ = (4.0*PI_*pow(radius_,3))/3.0;

}

void Sphere::print_details(){
  cout<<"radius = "<<radius_<<" :volume ="<<volume_<<endl;
}
