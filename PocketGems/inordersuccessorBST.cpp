

using namespace std;


struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
	if (!root) return nullptr;
	/*make use of the property of BST. if the p's value is bigger than the root value, 
	then the successor of p must be in the right subtree. so we recursively call the 
	function by passing the right node of root.
	*/
	if (root->val <= p->val)
		return inorderSuccessor(root->right, p);
	/*if the p's value is smaller than the root value, then successor of p must be 
	in the left tree or the root itself. So if the left returned result is null, then it must be the root 
	or doesn't even exist.
	*/
	else{
		TreeNode* l = inorderSuccessor(root->left, p);
		return (!l ? root : l);
	}
	return nullptr;
}


//iterative

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* n){
	if (!root) return nullptr;
	if (n->right){
		return minVal(n->right);
	}
	TreeNode* ans = nullptr;
	while (root){
		if (n->val < root->val){
			ans = root;
			root = root->left;
		}
		else if (n->val > root->val)
			root = root->right;
		else
			break;
	}
	return ans;
}

// if there is no root node give

struct TreeNode {  
    int val;  
    TreeNode* left;  
    TreeNode* right;  
    TreeNode* parent;  
    TreeNode(int x): val(x), left(nullptr), right(nullptr), parent(nullptr) {}      // constructor   
};  


// with parent node  
TreeNode* inorderSuccessor(TreeNode* n) {  
    // step 1 of the algorithm  
    if (n->right != nullptr) {  
        return minVal(n->right);  
    }  
  
    // step 2 of the algorithm  
    TreeNode* p = n->parent;  
    while (p != nullptr and n != p->left) {  
        n = p;  
        p = p->parent;  
    }  
    return p;  
};  
  
TreeNode* minVal(TreeNode* n) {  
    TreeNode* cur = n;  
    while (cur->left != nullptr) {  
        cur = cur->left;  
    }  
    return cur;  
}  