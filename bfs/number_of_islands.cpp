/**
 Question :: 
 
Given an m x n 2d grid map of '1's (land) and '0's (water),
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume 
all four edges of the grid are all surrounded by water.

Example 1:

// count : answer <int> = 0+1 = 1+1 = 2 + 1 = 3

grid = [
  [true,true,"0","0","0"],
  [true,true,"0","0","0"],
  ["0","0",true,"0","0"],
  ["0","0","0",true,true]
]

grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

grid = [
  ["p","p","0",1","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

AGENDA :

// instead we have make visited to be 'p'

if it is not visted and it's a '1'


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    void adjacent(vector<vector<char>>& grid,int row,int col){
      
      //Base case
      
      if( row < 0 || col < 0 || row > grid.size()-1 or col > grid[0].size()-1 or grid[row][col] == '0' or grid[row][col] == 'p') {
        return;
      }
  
      
     
      if(grid[row][col] == '1') {
        grid[row][col] = 'p';
      } 
      
      adjacent(grid,row+1,col);
      adjacent(grid,row,col+1);
      adjacent(grid,row-1,col);
      adjacent(grid,row,col-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++) {
          for(int j=0;j<grid[i].size(); j++) {
            if(grid[i][j] == '1') {
              count++;
              adjacent(grid,i,j);
            }
          }
        }
        
        return count;
    }
};

int main() {
	Solution s;
  vector<vector<char>> grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
  };
  cout << "Answer is :" << s.numIslands(grid) << endl;
	return 0;
}

// https://leetcode.com/problems/number-of-islands/
