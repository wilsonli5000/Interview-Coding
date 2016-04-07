#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
	Left tree first, then root, then right tree.
	Time complexity: O(n)
	Space complexity: O(n)

*/

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value):val(value), left(nullptr), right(nullptr){}
};

void printVectorInt(const vector<int> & n){
	for (auto i : n)
		cout << i << endl;
}

TreeNode* defineTree(){
	TreeNode* root = new TreeNode(3);
	TreeNode* l1 = new TreeNode(2);
	TreeNode* l2 = new TreeNode(1);
	root->left = l1;
	l1->left = l2;
	TreeNode* r1 = new TreeNode(7);
	root->right = r1;
	TreeNode* r2 = new TreeNode(4);
	l1->right = r2;
	TreeNode* l3 = new TreeNode(5);
	TreeNode* r3 = new TreeNode(6);
	r2->left = l3;
	r2->right = r3;
	TreeNode* r4 = new TreeNode(8);
	r1->right = r4;
	TreeNode* l4 = new TreeNode(9);
	r4->left = l4;
	return root;
}

vector<int> preorder(TreeNode* root){
	vector<int> ans;
	if (!root) return ans;
	TreeNode* cur = root;
	stack<TreeNode*> stack;

	while (!stack.empty() || cur){
		if (cur){
			// Save all the root nodes for use.
			stack.push(cur);
			cur = cur->left;
		}
		else{
			// when we reach the leaf node, we start to save the value and travel to right trees.
			cur = stack.top();
			stack.pop();
			ans.push_back(cur->val);
			cur = cur->right;
		}
	}
	return ans;
}



int main(){
	TreeNode* root = defineTree();
	vector<int> ans = preorder(root);
	printVectorInt(ans);
}
