//https://leetcode.com/problems/container-with-most-water

/**
  Container With Most Water.
  
  Given n non-negative integers a1, a2, ..., an , 
  where each represents a point at coordinate (i, ai). 
  n vertical lines are drawn such that the two endpoints of the 
  line i is at (i, ai) and (i, 0). Find two lines, which, 
  together with the x-axis forms a container, such that the 
  container contains the most water.

  Notice that you may not slant the container.
  
  Input: height = [1,8,6,2,5,4,8,3,7]
  Output: 49
  Explanation: The above vertical lines are represented by array 
  [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) 
  the container can contain is 49.

  Input: height = [1,1]
  Output: 1

  Input: height = [4,3,2,1,4]
  Output: 16

  Input: height = [1,2,1]
  Output: 2

 

  Constraints:

  n = height.length
  2 <= n <= 3 * 104
  0 <= height[i] <= 3 * 104   
*/    

/*
  soln ;-
    [4,3,2,1,4]
      min(4,3)*(2-1)
*/

#include <bits/stdc++.h>
using namespace std;

// O{N} -- Optimal Solution approach.

// Input: height = [1,8,6,2,5,4,8,3,7]

  //  3 6 _______ 5 3
//   l           r 


class Solution {
public:
    int maxArea(vector<int>& height) {
      int l = 0;
      int r = height.size() - 1;
      int mx = INT_MIN;
      while(l < r) {
        int area = min(height[l],height[r]) * (r-l);
        if(height[l] > height[r]) {
          r--;
        } else {
          l++;
        }
        mx = max(mx,area);
      }
      return mx;
    }
};

int main() {
  Solution s;
  vector<int> height = {1,8,6,2,5,4,8,3,7};
  
  cout << "Answer is: " << s.maxArea(height) << endl;
  return 0;
}

// https://leetcode.com/problems/container-with-most-water/
