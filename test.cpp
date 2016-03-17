#include <iostream>
#include <vector>
using namespace std;

/*

Node
- Node * left
- Node * right
- value

Given a binary search tree of Nodes, return the path that has the largest sum of values.
List<Node *>greatestSumPath(Node *root).

                        8
        -1                   10
            5 
                7

return [Node 8, Node -1, Node 5, Node 7]
*/


struct Node{
  Node* left;
  Node* right;
  int val;
  Node(int a): val(a), left(nullptr), right(nullptr) {}
};


int greatestSum(Node* root){
  if (!root) return 0;
  int left = greatestSum(root->left);
  int right = greatestSum(root->right);
  return std::max(left, right) + root->val;
}


vector<Node*> greatestSumPath(Node * root){
  vector<Node*> ans;
  if (!root) return ans;

  ans.push_back(root);
  while (root != nullptr){
    int left = greatestSum(root->left);
    int right = greatestSum(root->right);
    if (left > right){
      ans.push_back(root->left);
      root = root->left;
    }
    else{
      ans.push_back(root->right);
      root = root->right;
    }
  }
  return ans;
}


int main() {
  Node* root = new Node(8);
  Node* p1 = new Node(-1);
  Node* p2 = new Node(10);
  root->left = p1;
  root->right = p2;
  Node* p3 = new Node(5);
  Node* p4 = new Node(7);
  p1->right = p3;
  p3->right = p4;
  vector<Node*> greatPath;
  greatPath = greatestSumPath(root);
  
  for (auto p : greatPath){
    cout << p->val << endl;
  }
  
  return 0;
}


