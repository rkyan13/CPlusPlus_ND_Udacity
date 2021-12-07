
#include <cassert>

class Date {

 private:
  int day{1};
  int month{1};
  int year{0};

 public:
  int Day() { return day; }
  void Day(int d) {
    if (d >= 1 && d <= 31) day = d;
  }
  int Month() { return month; }
  void Month(int m) {
    if (m >= 1 && m <= 12) month = m;
  }
  int Year() { return year; }
  void Year(int y) { year = y; }

  Date(int day, int month, int year){
      //Note you can use this->, but it is unnecessary
      this->Day(day);
      this->Month(month);
      this->Year(year);
  }

};

// Test in main
int main() {
  Date date(8,6,1981);
  assert(date.Day() == 8);
  assert(date.Month() == 6);
  assert(date.Year() == 1981);
}
