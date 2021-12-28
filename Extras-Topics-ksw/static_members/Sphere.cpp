#include <cmath>
#include <stdexcept>
#include <iostream>
#include "Sphere.h"

using namespace std;

/*
NOTE: on Static member variables
------------------  HOW STATIC MEMBER VARIABLES WORK ------------------
Static member variables are like global variables (like the global variables in main ! WOW thats an aha moment)
It is initialized before any object of this class is being created.
In fact static members exist even if no objects of the class have been instantiated!
Much like global variables, they are created when the program starts, and destroyed when the program ends.
(so that means The space is allocated  even before main starts !!!  )
It is visible only within the class, but its lifetime is the entire program
(and the above is true for the static member functions :


------------------ WHERE TO DEFINE  STATIC MEMBER VARIABLES ------------------
You have to define and initialize a static member variable somewhere in your code, at the top level
(outside of any function), the same way you define and initialize a global variable. The compiler
will ensure that the initialization is done before your program starts executing at the main function.
In this definition and initialization line, you provide the full name of the static member variable
using the class scope operator: The best place to define the static member variable is near the
beginning of the .cpp file that goes with the header file that contains the class declaration

------------------ DEFINING STATIC MEMBER VARIABLES ------------------
Yes, this looks odd because the definition and initialization statement appears to be accessing a
private member variable from outside the class. Yes, it is doing just that. But you have to be able
to define the member variable somehow, even if it is private. So this exception to the access rules is
allowed. But now you can no longer refer to the member variable in other ways because it is private:
*/
int Sphere::count =0;

Sphere::Sphere() :radius_(0), volume_(0){count++;}

Sphere::Sphere(float radius):radius_(radius), volume_((4.0*PI_*pow(radius_,3))/3.0)  {
   if(radius<0) throw invalid_argument("Radius <0");
   count++;
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
  cout<<"radius = "<<radius_<<", :volume ="<<volume_<<", :#of spheres invoked so far = "<<count<<endl;
}
