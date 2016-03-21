#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	The set        ⋯    contains a total of n! unique permutations.
	By listing and labeling all of the permutations in order, We get the following sequence (ie, for n = 3):
       
	Given n and k, return the kth permutation sequence. Note: Given n will be between 1 and 9 inclusive.

*/



void printVectorInt(const vector<int> & n){
	for (auto i : n)
		cout << i << endl;
}

void printMap(const unordered_map<int, vector<int> > & hash){
	for (auto itr : hash){
		cout << "key: " << itr.first << endl;
		printVectorInt(itr.second);
	}
}

int fac(int k){
	int ans = 1;
	for (int i = 1; i <= k; i++)
		ans *= i;
	return ans;
}

vector<int> nums = {1,2,3,4,5,6,7,8,9};
vector<int> permutationSequence(int n, int k){
	vector<int> ans;
	if (k > fac(n)) return ans;
	--k;
	// construct the sequence by digits, from left to right.
	// digit[i] = k / fac(n - 1 - i);
	// then update k = k % fac(n - 1 - i);
	for (int i = 0; i < n; i++){
		int factor = fac(n - 1 - i);
		ans.push_back(nums[k / factor]);
		nums.erase(nums.begin() + k /factor);
		k %= factor;
	}
	return ans;
}


int main(){
	vector<int> nums = permutationSequence(3, 2);
	printVectorInt(nums);
}
