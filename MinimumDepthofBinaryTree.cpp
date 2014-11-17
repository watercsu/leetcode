/* Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
       if(!root) return 0;
       if(!root->left && !root->right) {
           return 1;
       }
       int leftDepth=INT_MAX, rightDepth=INT_MAX;
       if(root->left) {
           leftDepth = 1+minDepth(root->left);
       }
       if(root->right) {
           rightDepth = 1+minDepth(root->right);
       }
       return leftDepth<rightDepth? leftDepth:rightDepth;
    }
};
