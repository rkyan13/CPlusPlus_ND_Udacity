#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(){
  vector <vector<int>> v = {{0,1,2,3},
                            {10,11,12,13,14,15},
                            {100,101}};

  cout<<"Printing out the values of 2d vector V."<<endl;
  cout<<"Notice that each row can be of different lengths(just like python lists !!!). This is pretty powerful!"<<endl;
  for (vector<int> row:v){
    for(int x: row){
      cout<<x<<" ";
    }
    cout<<endl;
  }

}
