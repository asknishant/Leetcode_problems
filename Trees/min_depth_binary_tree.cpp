//https://leetcode.com/problems/minimum-depth-of-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int minDepth(TreeNode* root) {
       // Base cases;
       if(root == NULL)
        return 0;
        
       if(root->left == NULL && root->right == NULL)
        return 1;
      
      int leftDepth = 0;
      int rightDepth = 0;
      
      if(root->left != NULL) leftDepth = 1 + minDepth(root->left);
      if(root->right != NULL) rightDepth = 1 + minDepth(root->right); 
      
      if(root->left == NULL || root->right == NULL)
        return max(leftDepth,rightDepth);
      return min(leftDepth,rightDepth);
    }   
};
