#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Given an array, every element occurs exactly even number of time, except one. Find it.
	Time complexity: O(n)
	Space complexity: O(1)
	
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

void printMatrix(const vector<vector<int> > & n){
	for (auto i : n){
		printVectorInt(i);
		cout << "\n";
	}
}

int singleNumber(const vector<int> & nums){
	int mask = 0;
	for (int i = 0; i < nums.size(); i++){
		mask ^= nums[i];
	}
	return mask;
}

int main(){
	vector<int> nums = {1,1,2,2,3,4,4,5,5};
	cout << singleNumber(nums) << endl;
}
