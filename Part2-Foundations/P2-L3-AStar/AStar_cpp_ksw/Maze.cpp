#include<iostream>
#include<vector>
#include<vector>
#include<deque>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<tuple>
#include <algorithm>

#include "Maze.h"

using namespace std;

Maze::Maze(string file_name, int start_x, int start_y, int goal_x, int goal_y){
    //This loads the value into board
    ParseFile(file_name);

    start = make_tuple(start_x, start_y);
    goal  = make_tuple(goal_x, goal_y);

    //Create the following matrices/2d Vectors: heuristic ,lcost_evaluated & parent
    for(int i =0; i<board.size(); i++){
       vector<Cell>  lcost_evaluated_row;
       vector<Cell>  actually_landed_row;
       vector<int>   heuristic_row;
       vector<int>   landing_cost_row;
       vector<tuple<int,int>> parent_row;
       for(int j=0; j<board[0].size(); j++){
          lcost_evaluated_row.push_back(board[i][j]);
          actually_landed_row.push_back(board[i][j]);
          parent_row.push_back(make_tuple(-1,-1));
          if(board[i][j]== Cell::kEmpty){
             //heuristic_row.push_back((i-goal_x)*(i-goal_x)+ (j-goal_y)*(j-goal_y));
             heuristic_row.push_back(abs(pow(i-goal_x,3))+ abs(pow(j-goal_y,3)));
             landing_cost_row.push_back(0);
          }
          else if(board[i][j]== Cell::kObstacle){
             heuristic_row.push_back(9999);
             landing_cost_row.push_back(-1);
          }
       }//eof for j
       lcost_evaluated.push_back(lcost_evaluated_row);
       actually_landed.push_back(actually_landed_row);
       heuristic.push_back(heuristic_row);
       landing_cost.push_back(landing_cost_row);
       parent.push_back(parent_row);
    }//eof for i
    //Set the parents of the startign node to -99,-99 (i.e. Unknown)
    parent[start_x][start_y]    = make_tuple(-99,-99);
    lcost_evaluated[start_x][start_x]    = Cell::kLanded;


    num_landings =0;
}//eof Maze::Maze

vector<Maze::Cell> Maze::ParseLine(string &this_line){
  stringstream sso(this_line);
  vector<Cell> row;
  int x;
  char c;
  while(sso>>x>>c && c==','){
     row.push_back(Cell(x));
  }
  return row;
}


void Maze::ParseFile(string file_name){
  ifstream file_obj;
  file_obj.open(file_name);

  //-------- Parse the txt file ---------------------
  board.clear();
  string this_line;
  stringstream sso;
  vector<Cell> row;
  while(getline(file_obj, this_line)){
    row = ParseLine(this_line);
    board.push_back(row);
  }
  //-------- Done parsing the text file --------------
  file_obj.close();
}


void Maze::printAsInt(string str){
  vector<vector<Cell>> *matrix;
  if(str =="lcost_evaluated")
      matrix = &lcost_evaluated;
  else
     matrix = &board;
  cout<<"\n Printing "<<str<<" as Int"<<endl;
  for(vector<Cell> row:*matrix){
    for(Cell cell:row){
       if(cell == Cell::kEmpty)
         cout<<" 0 ";
       else if(cell == Cell::kObstacle)
         cout<<" 1 ";
       else if(cell == Cell::kLanded)
           cout<<"-1 ";
    }
    cout<<endl;
  }
}

void Maze::printAsEmoji(string str){
  vector<vector<Cell>> *vect2D_Cell;
  vector<vector<int>>  *vect2D_int;
  int print_type;
  if(str =="board"){
     vect2D_Cell = &board;
     print_type =1;
  }
  else if(str =="lcost_evaluated"){
     vect2D_Cell = &lcost_evaluated;
     print_type =1;
  }
  else if(str =="actually_landed"){
     vect2D_Cell = &actually_landed;
     print_type =1;
  }
  else if(str =="heuristic"){
     vect2D_int = &heuristic;
     print_type =2;
  }
  else if(str =="landing_cost"){
     vect2D_int = &landing_cost;
     print_type =2;
  }


  cout<<"\n Printing "<<str<<" as Emoji"<<endl;
  switch(print_type){
    case(1):
        for(vector<Cell> row:*vect2D_Cell){
          for(Cell cell:row){
             if(cell == Cell::kEmpty)
                cout<<" 0 ";
             else if(cell == Cell::kObstacle)
                cout<<"⛰️  ";
             else if(cell == Cell::kLanded)
                cout<<"😀 ";
           }
           cout<<endl;
         }
         break;
     case(2):
         for(vector<int> row:*vect2D_int){
           for(int x:row){
              cout<<x<<"\t";
           }
            cout<<endl;
         }
          break;

  }//eof switch
}//EOF printAsEmoji(string str)

void Maze::seek_goal(){
  cout<<"SEEEEEEK \n";
  if(this->start == this->goal){
    this->final_list.push_back(this->start);
    search_complete = true;
    goal_reached    = true;
    cout<<"Start same as Goal ! Exiting ";
    return;
  }
  else{
    search_complete = false;
    goal_reached    = false;
    toexpand_list.push_back(start);
    toexpand_cost.push_back(0);

    while(search_complete == false){
      current = toexpand_list.front();
      //Now that the first value has been read into current, delete it
      toexpand_list.pop_front();
      toexpand_cost.pop_front();
      //Expand it
      expand(current);
      //printAsEmoji("heuristic");
      printAsEmoji("landing_cost");
      if(toexpand_list.size()==0)
         search_complete = true;
    }

    //After exiting while loop(which means search was completed)- check if goal was reached
    if(goal_reached == true){
      cout<<"Goal-reached \n"<<endl;
    }
    else{
      cout<<"Search complete, but Goal cannot be reached ! \n";
    }

  }
}

void Maze::expand(tuple<int,int> current){
   int curr_row  = get<0>(current);
   int curr_col  = get<1>(current);
   int curr_cost = landing_cost[curr_row][curr_col];
   cout<<"\n\nExpanding ["<<curr_row<<","<<curr_col<<"]"<<" :curr_cost ="<<curr_cost <<"\n";
   actually_landed[curr_row][curr_col]=Cell::kLanded;
   num_valid_neighbors = 0;
   goal_reached        = false ;

   for(int direction =0;direction<4 && goal_reached == false; direction++){
     switch(direction) {
       //Go Down
       case(0):
          {
          int down_row = curr_row+1;
          int down_col = curr_col;
          if((down_row<board.size())&&(lcost_evaluated[down_row][down_col]==Cell::kEmpty)){
            cout<<"expand:Going down \n";
            update_neighbor_cell_details(down_row, down_col, curr_cost);
          }
          }
          break;
        //Go Right
        case(1):
           {
           int right_row = curr_row;
           int right_col = curr_col+1;
           if((right_col<board[0].size())&&(lcost_evaluated[right_row][right_col]==Cell::kEmpty)){
              cout<<"expand:Going Right \n";
              update_neighbor_cell_details(right_row, right_col, curr_cost);
           }
           }
           break;
        //Go Up
        case(2):
           {
           int up_row = curr_row-1;
           int up_col = curr_col;
           if((up_row>=0)&&(lcost_evaluated[up_row][up_col]==Cell::kEmpty)){
             cout<<"expand: Going Up \n";
             update_neighbor_cell_details(up_row, up_col, curr_cost);
           }
           }
           break;
        //Go Left
        case(3):
          {
          int left_row = curr_row;
          int left_col = curr_col-1;
          if((left_col>=0)&&(lcost_evaluated[left_row][left_col]==Cell::kEmpty)){
            cout<<"expand: Going Left \n";
            update_neighbor_cell_details(left_row, left_col, curr_cost);
          }
          }
          break;
     }//Eof switch i
   }//EOF for(int i =0;i<4 && goal_reached == false; i++)

   //If goal_reached : exit
   if(goal_reached == true){
      cout<<"expand:goal_reached\n";
      search_complete = true;
      return;
   }
   else if(num_valid_neighbors==0){
     //there is nothing to do in this case
     cout<<"expand:no valid neighbors\n";
     return;
   }
   else{
     //Sort the temp_toexpand_list based on toexpand_cost and update the toexpand_list
     //Create a tracking index vector
     cout<<"expand:1 or more valid neighbors \n";
     vector<int> toexpand_idx;
     for(int k=0; k<toexpand_list.size(); k++){
       toexpand_idx.push_back(k);
     }
     //Create toexpand_cost, toexpand_idx vector pairs
     vector<pair <int,int>> cost_idx_vect_pair;
     for(int k =0; k<toexpand_cost.size(); k++){
        cost_idx_vect_pair.push_back(make_pair(toexpand_cost[k],toexpand_idx[k]));
     }

     //Sort by toexpand_cost
     sort(cost_idx_vect_pair.begin(), cost_idx_vect_pair.end());

     deque<tuple<int,int>> unsorted_toexpand_list = toexpand_list;
     deque<int>            unsorted_toexpand_cost = toexpand_cost;
     toexpand_list.clear();
     toexpand_cost.clear();

     //Use the sorted toexpand_idx to push to the toexpand_list from the temp_toexpand_list
     for(int k =0; k<cost_idx_vect_pair.size(); k++){
        int cost = cost_idx_vect_pair[k].first;
        int idx  = cost_idx_vect_pair[k].second;
        toexpand_list.push_back(unsorted_toexpand_list[idx]);
        toexpand_cost.push_back(unsorted_toexpand_cost[idx]);
     }

     return;
   }
}//EOF Maze::expand(tuple<int,int> current)

void Maze::update_neighbor_cell_details(int neigh_row, int neigh_col, int curr_cost) {
   tuple<int,int> cell_idx(neigh_row, neigh_col);
   lcost_evaluated[neigh_row][neigh_col]       = Cell::kLanded;
   int cell_cost                      = curr_cost + heuristic[neigh_row][neigh_col];
   landing_cost[neigh_row][neigh_col] = cell_cost ;
   parent[neigh_row][neigh_col]       = make_tuple(neigh_row, neigh_col);
   //Check if the down cell is the goal or not
   if(cell_idx == goal){
      goal_reached    = true;
      search_complete = true;
      cout<<"update_neighbor_cell_details: Goal reaced, search complete \n";
   }
   else {
      num_valid_neighbors+=1;
      toexpand_list.push_back(cell_idx);
      toexpand_cost.push_back(cell_cost);
   }

   return;
}

/*
void Maze::print_toexpand_list(string str){
  deque<tuple<int,int>> *list;
  if(str="temp")
     list = &temp_toexpand_list
  else
     list = &toexpand_list


}
*/
