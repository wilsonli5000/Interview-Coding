#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct TreeNode{
	char name;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char c){
		name = c;
		left = nullptr;
		right = nullptr;
	} 
};

TreeNode* ternarytotree(string s){
	//invalid strings
	int n = s.length();
	if (n < 1)
		return nullptr;

	stack<TreeNode*> parent;
	TreeNode * root = new TreeNode(s[0]);
	parent.push(root);
	for (int i = 1; i < n - 1; i += 2){
		if (s[i] == '?'){
			TreeNode* l = new TreeNode(s[i + 1]);
			parent.top()->left = l;
			parent.push(l);
		}
		else if (s[i] == ':'){
			TreeNode* r = new TreeNode(s[i + 1]);
			parent.pop();
			while (parent.top()->right != nullptr)
				parent.pop();
			parent.top()->right = r;
		}
	}
	return root;
}


int main(){
	string s = "a?b?c:d:e";
	TreeNode* node = ternarytotree(s);
	cout << "root " << node->name << endl;
	cout << "left " << node->left->name << endl;
	cout << "right " << node->right->name << endl;
}