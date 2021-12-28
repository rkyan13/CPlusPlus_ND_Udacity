
#include <cassert>
#include <iostream>

// TODO: Define public accessors and mutators for the private member variables
struct Date {
 
 private:
  int day{1};
  int month{1};
  int year{0};
 
 public:
 //Create Setters(accessors) for the above variables
 //Note that these setters are called Day, Month, Year: Don't confuse these with Constructors which would be Date()  .
 //Setters are for individual member variables day, month year. Constructors are for the entire class itself. so constructor would be Date()
 void Day(int day)    {this->day = day;}
 void Month(int month){this->month = month;}
 void Year(int year)  {this->year = year;}
 //Create Getters(mutators) for the above variables. 
 //Note that setters and getters have the same name, which is the capitalised version of the variable name:(sth new for me. a new way for naming setters and getters)
 //Also no need to use this->day/ this->month /this->year in the return statement
 int  Day()           {return day;}
 int  Month()         {return month;}
 int  Year()          {return year;} 
};

int main() {
  Date date;
  date.Day(29);
  date.Month(8);
  date.Year(1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}
