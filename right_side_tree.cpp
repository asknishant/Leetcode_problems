
 //Definition for a binary tree node.
 
 



//   Given a binary tree, imagine yourself standing on the right side of it,
//    return the values of the nodes you can see ordered from top to bottom.
   
   
//    Example:

//   Input: [1,2,3,null,5,null,4]
//   Output: [1, 3, 4]
//   Explanation:

//                         1            <---
//                       /  \
//                     2     3         <---
//                    / \     \
//                   23  5     4       <---
//                       /     /
//                       8     7       <---
//                     /      
//                     9  
                
//   [9]    
//   Output : [3,4,7,9]     
//   APPROACH IS:
  
//   first take up the root at each level and go for it's right child everytime.
//   if(root->right == NULL but root->left != NULL)
//     pass the root->left at the recursive defi.
    
    
//  [8,7]
//  coverings :: [8,7]
//  [1,3,4,7]

// */


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
          return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        ans.push_back(root->val);
        
        while(q.empty() == false){
          vector<TreeNode*> coverings;
          for(auto x = q.front(); q.empty() == false;  ) {
            if(x->left != NULL) coverings.push_back(x->left);
            if(x->right != NULL) coverings.push_back(x->right);
            x.pop();
            x = q.front();
          }
          if(coverings.size() > 0)
            ans.push_back(coverings[coverings.size()-1]->val);
          
          for(auto x : coverings)
            q.push(x);
        }
        
        return ans;
    }
};

// Recursive CPP program for level
// order traversal of Binary Tree 
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, 
pointer to left child 
and a pointer to right child */
class node 
{ 
	public:
	int data; 
	node* left, *right; 
}; 

/* Function protoypes */
void printGivenLevel(node* root, int level); 
int height(node* node); 
node* newNode(int data); 

/* Function to print level 
order traversal a tree*/
void printLevelOrder(node* root) 
{ 
	int h = height(root); 
	int i; 
	for (i = 1; i <= h; i++) 
		printGivenLevel(root, i); 
} 

/* Print nodes at a given level */
void printGivenLevel(node* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
		cout << root->data << " "; 
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
} 


/* Driver code*/
int main() 
{ 
	node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	cout << "Level Order traversal of binary tree is \n"; 
	printLevelOrder(root); 

	return 0; 
} 

// This code is contributed by rathbhupendra


int main() {
  TreeNode* root = new TreeNode(1,new TreeNode(2,nullptr,new TreeNode(5)),new TreeNode(3,nullptr,new TreeNode(5)));
  Solution s;
  vector<int> ans = s.rightSideView(root);
  
  cout << "Asnwer is :" << endl;
  for(auto x : ans){
    cout << x << " ";
  }
  
  return 0;
}
