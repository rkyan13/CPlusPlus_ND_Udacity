#include<iostream>
#include "Sphere.h"
using namespace std;

int main(){
  Sphere my_sphereA(1.0);
  cout<<"my_sphereA details:";
  my_sphereA.print_details();

  Sphere my_sphereB(2.0);
  cout<<"\nmy_sphereB details:";
  my_sphereB.print_details();

  Sphere my_sphere2;
  cout<<"\nmy_sphere2 details: non parameterised constructor:";
  my_sphere2.print_details();
  my_sphere2.Radius(1.0);
  cout<<"my_sphere2 details: after setting radius:";
  my_sphere2.print_details();

  Sphere my_sphere3;
  cout<<"\nmy_sphere3 details: non parameterised constructor:";
  my_sphere3.print_details();
  my_sphere3.Radius(2.0);
  cout<<"my_sphere3 details: after setting radius:";
  my_sphere3.print_details();

}




,,,,,
