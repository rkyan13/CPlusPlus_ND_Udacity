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
    enum class Cell{kEmpty, kObstacle, kLanded};
    tuple<int,int> start;
    tuple<int,int> goal;
    tuple<int,int> current;
    vector<vector<Cell>>   board;
    vector<vector<Cell>>   landed;
    vector<vector<int>>    heuristic;
    vector<vector<int>>    landing_cost;
    vector<vector<tuple<int,int>>> parent;
    deque<tuple<int,int>>          toexpand_list;
    vector<tuple<int,int>>         final_list;
    int num_landings;

    bool search_complete ;
    bool goal_reached    ;
    int  num_valid_neighbors;
    deque<tuple<int,int>>    temp_toexpand_list;
    vector<int>              temp_cost;



  private:
    vector<Cell>  ParseLine(string &this_line);
    void          ParseFile(string  file_name);
    void update_neighbor_cell_details(int neigh_row, int neigh_col, int curr_cost);
    void expand(tuple<int,int> current);

  public:
    Maze(string file_name, int start_x, int start_y, int goal_x, int goal_y);
    void printBoardAsInt();
    void printBoardAsEmoji();
    void seek_goal();
};

#endif
