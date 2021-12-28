#include<iostream>
using namespace std;

class Date{
   private:
      int day;
      int month;
      int year;
   public:
      Date(int d, int m, int y);
}

//Using scope resolution operator::

//CONSTRUCTORS:Using initializtion lists. 
//NOTE: intialise in the same order of declaration. i.e. day, month, year

//DEFAULT Constructor: Using Initialization Lists
Date::Date():day(1), month(1), year(1){}

//CONVERT Constructor: Using Initialization Lists for day and month
Date::Date(int d, int m, int y):day(d), month(m){
    if(y>0)
       year= y;
    else
       year = 1;
}

//Setters: Setters allow the use of invariants. While initialization lists don't
void Date::Day(int d){day = d;}
void Date::Month(int m){month = m;}
void Date::Year(int y){year =y;}

//Getters



int main{


}

