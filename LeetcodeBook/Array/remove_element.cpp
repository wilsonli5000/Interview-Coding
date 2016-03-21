#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Remove all elements in place in an unordered array. Return the new length.
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

int removeElement(vector<int> & nums, int target){
	if (!nums.size()) return -1;
	int pointer = 0;
	for (int i = 0; i < nums.size(); i++){
		if (nums[i] != target)
			nums[pointer++] = nums[i];
	}
	return pointer;
}


int main(){
	vector<int> nums = {1,1,1,3,4,5,2,6,7,2,4,5};
	vector<int> n (nums.begin(), nums.begin() + removeElement(nums, 1));
	printVectorInt(n);

}
