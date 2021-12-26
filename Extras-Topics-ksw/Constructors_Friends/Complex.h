//=================================
// include guard
#ifndef __COMPLEX_H_INCLUDED__
#define __COMPLEX_H_INCLUDED__

//=================================
// forward declared dependencies


//=================================
// included dependencies
#include "ComplexFriendFunctions.h"


//=================================
// the actual class


class Complex{
   private:
      //the complex number os a+ib
      float a;
      float b;
   public:
      //constructors
      //Default constructor: can/cannot have arguments. but if it has arguments you must provide default values to it
      //If it does not have default values, it is not called default constructor. It is called Convert Constructor
      Complex();
   
      //Convert Constructor: Converts other variable to private
      Complex(float x, float y);

      //Copy Constructor: Copies over another complex 
      Complex(const Complex &C);

      //Setters 
      void real(float a);
      void imaginary(float b);

      //Getters
      int  real();
      int  imaginary();

      //Arithmetic Operations on Complex Numbers   
      //Add
      void addComplex(const Complex &C);
      
      //Subtract
      void subtractComplex(const Complex &C);
      
      //Dot Product
      void dotProduct(const Complex &C);

      //Display
      void display();
 
   
   //NOTE: Friend functions are not part of the public members. They are outside of it
   //Friend functions for those applications that need to deal with multiple class objects
   friend Complex add     (const Complex &A, const Complex&B);
   friend Complex subtract(const Complex &A, const Complex&B); 
   friend Complex dot     (const Complex &A, const Complex&B); 

   friend Complex operator+(const Complex &A, const Complex&B);
   friend Complex operator.(const Complex &A, const Complex&B); 
   friend Complex operator-(const Complex &A, const Complex&B);    
      
};

#endif //__MYCLASS_H_INCLUDED__ 









 
