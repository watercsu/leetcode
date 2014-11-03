/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

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
  */

/**
* Definition for binary tree*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
		 if (root == NULL)
			 return true;

		 stack<TreeNode*> leftStack;
		 stack<TreeNode*> rightStack;
		 vector<string> leftVec;
		 vector<string> rightVec;
		 TreeNode* p = root;
		 leftStack.push(p);
		 rightStack.push(p);
		 leftVec.push_back(to_string(p->val));
		 rightVec.push_back(to_string(p->val));
		 p = root->left;
		 TreeNode* q = root->right;
		 int i=0;
		 int j=0;

		 while (p || leftStack.size()>1 || q || rightStack.size()>1)
		 {
			 if (p)
			 {
				 leftVec.push_back(to_string(p->val));
				 i++;
				 leftStack.push(p);
				 p = p->left;
			 }
			 else if (leftStack.size()>1)
			 {
				 leftVec.push_back("#");
				 i++;
				 p = leftStack.top();
				 leftStack.pop();
				 p = p->right;
			 };
			 if (q)
			 {
				 rightVec.push_back(to_string(q->val));
				 j++;
				 rightStack.push(q);
				 q = q->right;
			 }
			 else if (rightStack.size()>1)
			 {
				 rightVec.push_back("#");
				 j++;
				 q = rightStack.top();
				 rightStack.pop();
				 q = q->left;
			 }

			 if (leftVec.size() != rightVec.size() || leftVec[i] != rightVec[j])
				 return false;
		 }

		 return true;
	 }
};
