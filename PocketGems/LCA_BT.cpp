#include <iostream>


using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* LCABT(TreeNode* root, TreeNode* p, TreeNode* q){
	
	if (!root) return nullptr;
	if (root = p || root = q) return root;
	TreeNode* l = LCABT(root->left, p, q);
	TreeNode* r = LCABT(root->right, p, q);
	if (l && r)
		//means not the same value.
		return root;
	else
		return l == nullptr ? r : l;
}