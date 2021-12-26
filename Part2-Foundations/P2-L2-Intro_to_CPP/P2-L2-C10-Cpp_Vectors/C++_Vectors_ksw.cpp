#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using namespace std;

void print1d_a(vector<int> const &v){
  for(int i=0; i<v.size(); i++)
      cout<<v.at(i)<<" ";
  cout<<endl;
}

void print1d_b(vector<int> const &v){
  for(int i=0; i<v.size(); i++)
      cout<<v[i]<<" ";
  cout<<endl;
}


void print2d_a(vector<vector<int>> const &v){
  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size();j++){
      cout<<v.at(i).at(j)<<" ";
    }
      cout<<endl;
  }
    cout<<endl;
}

void print2d_b(vector<vector<int>> const &v){
  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size();j++){
      cout<<v[i][j]<<" ";
    }
      cout<<endl;
  }
    cout<<endl;
}

int main() {
    // Declare ,initialize and print 1d vector
    vector<int> v1={1,2,3};
    v1.push_back(4);
    cout<<"\n v1:print1d_a: ";
    print1d_a(v1);
    cout<<"\n v1:print1d_b: ";
    print1d_b(v1);

    // Declare ,initialize and print 1d vector
    vector<vector<int>> v2={{1,2,3},
                           {4,5,6},
                           {7,8,9}};
    v2.push_back({10,11,12});
    cout<<"\n v2.size() :"<<v2.size()<<"\n";
    cout<<"\n v2:print1d_a: \n";
    print2d_a(v2);
    cout<<"\n v2:print1d_b: \n";
    print2d_b(v2);
  }
