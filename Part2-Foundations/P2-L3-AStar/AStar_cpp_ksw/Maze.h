//Maze.h
#ifndef MAZE_H
#define MAZE_H

#include<vector>
#include<tuple>
#include<deque>
#include<string>
using namespace std;

class Maze{
  private:
    enum class Cell{ kLanded =-1, kEmpty =0, kObstacle =1 };
    tuple<int,int> start;
    tuple<int,int> goal;
    vector<vector<Cell>>   board;
    vector<vector<Cell>>   lcost_evaluated;
    vector<vector<Cell>>   actually_landed;
    vector<vector<int>>    heuristic;
    vector<vector<int>>    landing_cost;
    vector<vector<tuple<int,int>>> parent;
    deque<tuple<int,int>>          toexpand_list;
    deque<int>                     toexpand_cost;
    vector<tuple<int,int>>         final_list;
    int num_landings;

    bool search_complete ;
    bool goal_reached    ;
    tuple<int,int> current;
    int  num_valid_neighbors;




  private:
    vector<Cell>  ParseLine(string &this_line);
    void          ParseFile(string  file_name);
    void update_neighbor_cell_details(int neigh_row, int neigh_col, int curr_cost);
    void expand(tuple<int,int> current);

  public:
    Maze(string file_name, int start_x, int start_y, int goal_x, int goal_y);
    void printAsInt(string str);
    void printAsEmoji(string str);
    void seek_goal();
};

#endif
