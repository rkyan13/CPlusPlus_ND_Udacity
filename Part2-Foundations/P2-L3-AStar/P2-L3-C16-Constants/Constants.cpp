
#include <iostream>

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                          // "But I promise not to change it after it is initialized."
    
    constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."
    
    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";
}

int main()
{
    const int i = 2; // "I promise not to change this."
    i++;             // "I just broke my promise."
}

int main()
{
    constexpr int i = 2;  // "i can be evaluated at compile time."
    i++;                  // "But changing a constexpr variable triggers an error."
}

#include <iostream>

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    constexpr int j = i * 2;  // "j can only be evaluated at run time."
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."
}

#include <iostream>
#include <vector>

int sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i : v)
        sum += i;
    return sum;
}

int main()
{
    std::vector<int> v {0, 1, 2, 3, 4};
    std::cout << sum(v) << "\n";
}
