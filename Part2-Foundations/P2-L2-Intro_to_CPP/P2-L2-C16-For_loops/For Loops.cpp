
#include <iostream>
using std::cout;

int main() {
    for (int i=0; i < 5; i++) {
      cout << i << "\n";
    }
}

#include <iostream>
using std::cout;

int main() {
    auto i = 1;

    // Post-increment assigns i to c and then increments i.
    auto c = i++;

    cout << "Post-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";
    cout << "The value of i is: " << i << "\n";
    cout << "\n";

    // Reset i to 1.
    i = 1;

    // Pre-increment increments i, then assigns to c.
    c = ++i;

    cout << "Pre-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";
    cout << "The value of i is: " << i << "\n";
    cout << "\n";

    // Decrement i;
    i--;
    cout << "Decrement example:" << "\n";
    cout << "The value of i is: " << i << "\n";
}

#include <iostream>
using std::cout;

int main() {
    // Add your code here.
    
}

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
    // Add your code here.
    vector<int> a {1, 2, 3, 4, 5};
    for (int i: a) {
        cout << i << "\n";
    }
}

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
    // Add your code here.
    vector<vector<int>> b {{1, 2},
                           {3, 4},
                           {5, 6}};

    // Write your double loop here.
    
}
