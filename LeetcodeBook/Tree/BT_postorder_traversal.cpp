#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
	Left tree, then right tree, then root.
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

// Do it smartly, do a preorder traversal but with right nodes first, then reverse the whole vector.
vector<int> postorder(TreeNode* root){
	vector<int> ans;
	if (!root) return ans;
	TreeNode* cur;
	stack<TreeNode*> stack;
	stack.push(root);

	while (!stack.empty()){
		cur = stack.top();
		stack.pop();
		ans.push_back(cur->val);
		// Here push left child node first.
		if (cur->left)
			stack.push(cur->left);
		if (cur->right)
			stack.push(cur->right);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}



int main(){
	TreeNode* root = defineTree();
	vector<int> ans = postorder(root);
	printVectorInt(ans);
}
