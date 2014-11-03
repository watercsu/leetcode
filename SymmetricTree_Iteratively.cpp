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

		 while (p || leftStack.size()>1)
		 {
			 if (p)
			 {
				 leftVec.push_back(to_string(p->val));
				 leftStack.push(p);
				 p = p->left;
			 }
			 else
			 {
				 leftVec.push_back("#");
				 p = leftStack.top();
				 leftStack.pop();
				 p = p->right;
			 }
		 }
		 while (q || rightStack.size()>1)
		 {
			 if (q)
			 {
				 rightVec.push_back(to_string(q->val));
				 rightStack.push(q);
				 q = q->right;
			 }
			 else
			 {
				 rightVec.push_back("#");
				 q = rightStack.top();
				 rightStack.pop();
				 q = q->left;
			 }
		 }
		 if (leftVec.size() != rightVec.size())
			 return false;
		 for (int i = 0, j = 0; i<leftVec.size(), j<leftVec.size(); i++, j++)
		 {
			 if (leftVec[i]!=rightVec[j])
				 return false;
		 }
		 return true;
	 };
