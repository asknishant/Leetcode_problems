/**
// UNIQUE PATHS

  A robot is located at the top-left corner of a m x n grid 
  (marked 'Start' in the diagram below).

  The robot can only move either down or right at any point in time. 
  The robot is trying to reach the bottom-right corner of the grid 
  (marked 'Finish' in the diagram below).

  How many possible unique paths are there?
  
  (You can see this at diagram via Slack)
  Input: m = 3, n = 7
  Output: 28
  
  Input: m = 7, n = 3
  Output: 28
  
  Input: m = 3, n = 3
  Output: 6
  
  Constraints:
  1 <= m, n <= 100
  It's guaranteed that the answer will be less than or equal to 2 * 109
  
  // Desciption:
  
  if you have 2 x 3 then
  
  * X X 
  X X T

  
  Output : 3
  
  output - 2;
  
  f(i,j) = f(i+1,j) + f(i,j+1),
  
  X X
  X X
  APPORACH:
  
  f(i,j) how many paths -> target.(m-1,n-1) right?
  
  
  X X
  
  X
  X
 
  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int paths(int m,int n,int i, int j, vector<vector<int>>& dp) {
      // Base case
      if(i > m-1 || j > n-1)
        return 0;
        
       // When target is found!!
      if(i == m-1 and j == n-1)
        return 1;
      
      if(dp[i][j] != 0)
        return dp[i][j];
    
      return dp[i][j] = paths(m,n,i+1,j,dp) + paths(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        vector<vector<int>> dp( m , vector<int> (n, 0));        
        paths(m,n,0,0,dp);
        return dp[0][0];
    }
};

int main() {
  Solution s;
  cout << "Answer is :" << s.uniquePaths(7,3) << endl;
	return 0;
}
