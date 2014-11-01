/**Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ**/

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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        return isSymmetric(root->left,root->right);
    }
    
    bool isSymmetric(TreeNode *node1,TreeNode *node2) {
        if(node1==NULL || node2==NULL)
            return node1==node2;
        if(node1->val != node2->val)
            return false;
        return isSymmetric(node1->left,node2->right)&&isSymmetric(node1->right,node2->left);
    }
};
