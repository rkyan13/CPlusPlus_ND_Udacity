/*
The following code(and/or) info is from Geek for Geeks . I have just used it here for my understanding
*/

/*
enum_class_example1.cpp versus enum_class_example2.cpp
While using enum you cannot say int Male = 10;
But When using enum class you can say int Male =10 (advantage)
*/

/*Also note on <bits/stdc++.h>

<bits/stdc++.h> in C++
Difficulty Level : Basic
Last Updated : 10 Dec, 2018
It is basically a header file that includes every standard library. In programming contests, using this file is a good idea, when you want to reduce the time wasted in doing chores; especially when your rank is time sensitive.
In programming contests, people do focus more on finding the algorithm to solve a problem than on software engineering. From, software engineering perspective, it is a good idea to minimize the include. If you use it actually includes a lot of files, which your program may not need, thus increases both compile time and program size unnecessarily.
*/


// C++ program to demonstrate working
// of Enum Classes

#include <iostream>
using namespace std;

int main()
{

    enum class Color { Red,
                       Green,
                       Blue };
    enum class Color2 { Red,
                        Black,
                        White };
    enum class People { Good,
                        Bad };

    // An enum value can now be used
    // to create variables
    int Green = 10;

    // Instantiating the Enum Class
    Color x = Color::Green;

    // Comparison now is completely type-safe
    if (x == Color::Red)
        cout << "It's Red\n";
    else
        cout << "It's not Red\n";

    People p = People::Good;

    if (p == People::Bad)
        cout << "Bad people\n";
    else
        cout << "Good people\n";

    // gives an error
    // if(x == p)
    // cout<<"red is equal to good";

    // won't work as there is no
    // implicit conversion to int
    // cout<< x;

    cout << int(x);

    return 0;
}
