//=================================
// include guard
#ifndef __COMPLEXFRIENDFUNCTIONS_H_INCLUDED__
#define __COMPLEXFRIENDFUNCTIONS_H_INCLUDED__

//=================================
// forward declared dependencies


//=================================
// included dependencies
#include "Complex.h"


//=================================
// the actual functions


//Functions for those applications that need to deal with multiple class objects(These will be used as friends)
Complex add     (const Complex &A, const Complex&B);
Complex subtract(const Complex &A, const Complex&B); 
Complex dot     (const Complex &A, const Complex&B); 

Complex operator+(const Complex &A, const Complex&B);
Complex operator.(const Complex &A, const Complex&B); 
Complex operator-(const Complex &A, const Complex&B);


#endif //__COMPLEXFRIENDFUNCTIONS_H_INCLUDED__
