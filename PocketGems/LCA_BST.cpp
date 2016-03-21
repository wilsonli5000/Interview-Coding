#include <iostream>


using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* LCABST(TreeNode* root, TreeNode* p, TreeNode* q){
	/*Well, remember to take advantage of the property of binary search trees, 
	which is, node -> left -> val < node -> val < node -> right -> val. Moreover, 
	both p and q will be the descendants of the root of the subtree that contains both of them. 
	And the root with the largest depth is just the lowest common ancestor. 
	This idea can be turned into the following simple iterative code.
	*/
	if (!root) return nullptr;
	if (root = p || root = q) return root;
	TreeNode* cur = root;
	while (1){
		if (p -> val < cur -> val && q ->val < cur ->val)
			cur = cur -> left;
		else if (p -> val > cur -> val && q->val > cur->val)
			cur = cur->right;
		else
			return cur;
	}
}