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

    //Create the following matrices/2d Vectors: heuristic ,landed & parent
    for(int i =0; i<board.size(); i++){
       vector<Cell>  landed_row;
       vector<int>   heuristic_row;
       vector<int>   landing_cost_row;
       vector<tuple<int,int>> parent_row;
       for(int j=0; j<board[0].size(); j++){
          landed_row.push_back(board[i][j]);
          parent_row.push_back(make_tuple(-1,-1));
          if(board[i][j]== Cell::kEmpty){
             heuristic_row.push_back(abs(i-start_x)+ abs(j-start_y));
             landing_cost_row.push_back(0);
          }
          else if(board[i][j]== Cell::kObstacle){
             heuristic_row.push_back(9999);
             landing_cost_row.push_back(9999);
          }
       }//eof for j
       landed.push_back(landed_row);
       heuristic.push_back(heuristic_row);
       landing_cost.push_back(landing_cost_row);
       parent.push_back(parent_row);
    }//eof for i
    //Set the parents of the startign node to -99,-99 (i.e. Unknown)
    parent[start_x][start_y]    = make_tuple(-99,-99);

    toexpand_list.push_back(start);
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


void Maze::printBoardAsInt(){
  cout<<"\n Printing Board as Int"<<endl;
  for(vector<Cell> row:board){
    for(Cell cell:row){
       if(cell == Cell::kEmpty)
         cout<<"0 ";
       else
         cout<<"1 ";
    }
    cout<<endl;
  }
}

void Maze::printBoardAsEmoji(){
  cout<<"\n Printing Board as Emoji"<<endl;
  for(vector<Cell> row:board){
    for(Cell cell:row){
       if(cell == Cell::kEmpty)
         cout<<" 0 ";
       else
         cout<<"⛰️  ";
     }
     cout<<endl;
   }
}

void Maze::seek_goal(){
  if(this->start == this->goal){
    this->final_list.push_back(this->start);
    search_complete = true;
    goal_reached    = true;
    cout<<"Start same as Goal ! Exiting ";
    return;
  }
  else{
    current = start;
    search_complete = false;
    goal_reached    = false;
    while(search_complete == false){
      current = toexpand_list.pop_front();
      expand(current);
    }
    //After exiting while loop- check if goal was reached
    if(goal_reached == true){
      cout<<"Goal-reached"<<endl;
    }
    else{
      cout<<"Search complete, but Goal cannot be reached !";
    }

  }
}

void Maze::expand(tuple<int,int> current){
   int curr_row  = get<0>(current);
   int curr_col  = get<1>(current);
   int curr_cost = landing_cost[curr_row][curr_col];

   num_valid_neighbors = 0;
   goal_reached        = false ;
   search_complete     = false ;
   temp_toexpand_list.clear();
   temp_cost.clear();
   for(int direction =0;direction<4 && goal_reached == false; direction++){
     switch(direction) {
       //Go Down
       case(0):
          {
          int down_row = curr_row+1;
          int down_col = curr_col;
          if((down_row<board.size())&&(landed[down_row][down_col]==Cell::kEmpty)){
            update_neighbor_cell_details(down_row, down_col, curr_cost);
          }
          }
          break;
        //Go Right
        case(1):
           {
           int right_row = curr_row;
           int right_col = curr_col+1;
           if((right_col<board[0].size())&&(landed[right_row][right_col]==Cell::kEmpty)){
              update_neighbor_cell_details(right_row, right_col, curr_cost);
           }
           }
           break;
        //Go Up
        case(2):
           {
           int up_row = curr_row-1;
           int up_col = curr_col;
           if((up_row>=0)&&(landed[up_row][up_col]==Cell::kEmpty)){
             update_neighbor_cell_details(up_row, up_col, curr_cost);
           }
           }
           break;
        //Go Left
        case(3):
          {
          int left_row = curr_row;
          int left_col = curr_col-1;
          if((left_col>=0)&&(landed[left_row][left_col]==Cell::kEmpty)){
            update_neighbor_cell_details(left_row, left_col, curr_cost);
          }
          }
          break;
     }//Eof switch i
   }//EOF for(int i =0;i<4 && goal_reached == false; i++)

   //If goal_reached : exit
   if(goal_reached == true){
      search_complete = true;
      return;
   }
   else{
     //Sort the temp_toexpand_list based on temp_cost and update the toexpand_list
     //Create a tracking index vector
     vector<int> temp_idx;
     for(int k=0; k<num_valid_neighbors; k++){
       temp_idx.push_back(k);
     }
     //Create temp_cost, temp_idx vector pairs
     vector<pair <int,int>> cost_idx_vect_pair;
     for(int k =0; k<temp_cost.size(); k++){
        cost_idx_vect_pair.push_back(make_pair(temp_cost[k],temp_idx[k]));
     }

     //Sort by temp_cost
     sort(cost_idx_vect_pair.begin(), cost_idx_vect_pair.end());

     //Use the sorted temp_idx to push to the toexpand_list from the temp_toexpand_list
     for(int k =0; k<cost_idx_vect_pair.size(); k++){
        int cost = cost_idx_vect_pair[k].first;
        int idx  = cost_idx_vect_pair[k].second;
        toexpand_list.push_back(temp_toexpand_list[idx]);
     }


   }
}//EOF Maze::expand(tuple<int,int> current)

void Maze::update_neighbor_cell_details(int neigh_row, int neigh_col, int curr_cost) {
   tuple<int,int> cell_idx(neigh_row, neigh_col);
   landed[neigh_row][neigh_col]       = Cell::kLanded;
   int cell_cost                      = curr_cost + heuristic[neigh_row][neigh_col];
   landing_cost[neigh_row][neigh_col] = cell_cost ;
   parent[neigh_row][neigh_col]       = make_tuple(neigh_row, neigh_col);
   //Check if the down cell is the goal or not
   if(cell_idx == goal){
      goal_reached    = true;
      search_complete = true;
      final_list.push_back(cell_idx);
   }
   else {
      num_valid_neighbors+=1;
      temp_toexpand_list.push_back(cell_idx);
      temp_cost.push_back(cell_cost);
   }

   return;
}
