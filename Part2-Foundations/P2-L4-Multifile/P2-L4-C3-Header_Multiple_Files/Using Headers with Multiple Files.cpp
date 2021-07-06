
#ifndef VECT_ADD_ONE_H
#define VECT_ADD_ONE_H

#include <vector>
using std::vector;

// AddOneToEach method declaration.
void AddOneToEach(vector<int> &v);

#endif

#include "vect_add_one.h"

void AddOneToEach(vector<int> &v) 
{
    for (auto& i: v) {
        i++;
    }
}

#ifndef INCREMENT_AND_SUM_H
#define INCREMENT_AND_SUM_H

#include <vector>
using std::vector;

// IncrementAndComputeVectorSum method declaration.
int IncrementAndComputeVectorSum(vector<int> v);

#endif

#include "vect_add_one.h"

int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;
    AddOneToEach(v);

    for (auto i: v) {
        total += i;
    }
    return total;
}

#include <iostream>
#include <vector>
#include "increment_and_sum.h"
using std::vector;
using std::cout;

int main() 
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}
