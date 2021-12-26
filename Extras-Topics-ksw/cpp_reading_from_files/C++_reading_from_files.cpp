#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;



int main(){
  string fname = "names.txt";
  ifstream fileObj1(fname);

  //=========================== Read file using >> + char ======================
  cout<<"\n --------Read file using >> + char: --------\n";
  vector<char> characters1;
  char temp_char1;
  while(fileObj1>>temp_char1){
    characters1.push_back(temp_char1);
  }
  //NOTE: without this fileObj1.close(), the fileObj1.open will not work properly
  fileObj1.close();

  cout<<">>+char:Print one read at a time: Notice that it reads one character at a time \n";
  for(int i =0; i <characters1.size(); i++)
    cout<<characters1[i]<<endl;
  cout<<endl;

  cout<<">>+char:Print everything that has been read: Notice that NO WHITE SPACES have been read. (so >>+char and >>+string produces same end result)  \n";
  for(int i =0; i <characters1.size(); i++)
    cout<<characters1[i];
  cout<<endl;


  //=========================== Read file using >> + string ====================
  cout<<"\n --------Read file using >> + string: -------\n";
  fileObj1.open(fname);
  string temp_str1;
  vector<string> strings1;
  while(fileObj1>>temp_str1){
    strings1.push_back(temp_str1);
  }
  fileObj1.close();

  cout<<">> + string:Print one read at a time: Notice that it reads one string at a time \n";
  //Print what you've Read
  //Note: this is another way of iterating through vectors
  //Note  cannot be declared earlier. It has to be declared now
  for(string iter_str1:strings1)
    cout<<iter_str1<<endl;
  cout<<endl;

  cout<<">> + string:Print everything that has been read: Notice that NO WHITE SPACES have been read. (so >>+char and >>+string produces same end result) \n";
  for(string iter_str1:strings1)
    cout<<iter_str1;
  cout<<endl;



  //================= Read file using get (get returns char) ===================
  cout<<"\n --------Read file <fileobj>.get() (get returns char type only, it doesn't return string) -------\n";
  fileObj1.open(fname);
  vector<char> characters2;
  char char2;

  char2 =fileObj1.get();
  cout<<"\nchar2="<<char2<<endl;
  characters2.push_back(char2);
  char2 =fileObj1.get();
  cout<<"char2="<<char2<<endl;
  characters2.push_back(char2);

  int count= 0;
  //Note:   while(char2 = fileObj1.get()) does nit work;
  while(fileObj1){
    char2 = fileObj1.get();
    characters2.push_back(char2);
    count++;
  }
  fileObj1.close();

  cout<<"<fileobj>.get():Print one read at a time: Notice that it reads one character at a time \n";
  //Note: this is another way of iterating through vectors
  //Note temp_char cannot be declared earlier. It has to be declared now
  for(char temp_char:characters2)
    cout<<temp_char<<endl;
  cout<<endl;

  cout<<"<fileobj>.get():Print everything that has been read: Notice that white spaces have been read. So this is the ONLY method that reads the file as is \n";
  for(char temp_char:characters2)
    cout<<temp_char;
  cout<<endl;


  //======================== Read file using getline + string ==================
  cout<<"\n --------Read file using getline + string : -------\n";
  fileObj1.open(fname);
  string temp_str2;
  vector<string> strings2;
  while(getline(fileObj1,temp_str2)){
    strings2.push_back(temp_str2);
  }
  fileObj1.close();

  cout<<"<getline(<fileObj1>,<string_name>):Print one read at a time: Notice that it reads one line  at a time \n";
  //Print what you've Read
  //Note: this is another way of iterating through vectors
  //Note  cannot be declared earlier. It has to be declared now
  for(string iter_str2:strings2)
    cout<<iter_str2<<endl;
  cout<<endl;

  cout<<"<getline(<fileObj1>,<string_name>):Print everything that has been read:";
  cout<<"Notice that white spaces within every line have been read, but the enter at the end of the line has not been read.\n";
  cout<<"So getline() does not read the file as is \n";
  for(string iter_str2:strings2)
    cout<<iter_str2;
  cout<<endl;



}
