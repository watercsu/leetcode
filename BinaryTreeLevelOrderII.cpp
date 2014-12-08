/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ. */
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        vector<vector<int>>::iterator it;
        vector<int> level;
        queue<TreeNode*> q;
        
        if(!root) return ret;
        
        q.push(root);
        q.push(NULL);
        ret.push_back(vector<int>({root->val}));
        
        while(!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if(!tmp && !q.empty()) {
                q.push(NULL);
                it = ret.begin();
                ret.insert(it,level);
                level.clear();
            } else if(tmp)
            {
                if(tmp->left) {
                    level.push_back(tmp->left->val);
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    level.push_back(tmp->right->val);
                    q.push(tmp->right);
                }
            }
        }
        return ret;
    }
};
