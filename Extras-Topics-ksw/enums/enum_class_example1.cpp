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

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Defining enum1 Gender
    enum Gender { Male,
                  Female };

    // Creating Gender type variable
    Gender gender = Male;

    // creating a variable Male
    // this will throw error
    int Male = 10;

    cout << gender << endl;

    return 0;
}
