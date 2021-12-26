#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include "Maze.h"
using namespace std;

int main() {

  string board_fname = "1.board";
  int start[2] = {0,0};
  int goal[2]  = {4,5};
  Maze my_maze(board_fname, start[0], start[1], goal[0], goal[1]);
  my_maze.printAsInt("board");
  my_maze.printAsEmoji("board");
  my_maze.seek_goal();
  my_maze.printAsEmoji("lcost_evaluated");
  my_maze.printAsEmoji("actually_landed");
}
