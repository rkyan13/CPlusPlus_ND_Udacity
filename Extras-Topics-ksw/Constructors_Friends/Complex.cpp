#include <iostream>
#include "Complex.h"
#include "ComplexFriendFunctions.h"
using namespace std;

//Default Constructor using initalization list
Complex::Complex():a(0.0), b(0.0) {}

//Convert constructor using initalization list
Complex::Complex(float r, float i):a(r), b(i){}

//Copy constructor using initialization list
Complex::Complex(const Complex &C):a(C.a), b(C.b){}

//Setters
void Complex::real(float a){this->a = a;}
void Complex::imaginary(float b){this->b = b;}

//Getters
float Complex::real(){return a;}
float Complex::imaginary(){return b;}

//Arithmetic Operations on Complex Numbers   
//Add
void Complex::addComplex(const Complex &C){
   this->a += C.a;
   this->b += C.b;
}

//Subtract
void Complex::subtractComplex(const Complex &C){
   this->a -= C.a;
   this->b -= C.b;
}

//Dot Product
void Complex::dotComplex(const Complex &C){
   this->a *= C.a;
   this->b *= C.b;
}

//Display
void Complex::display(){
   cout<<"\n Complex#:"<<a<<"+i"<<b;
}





 
