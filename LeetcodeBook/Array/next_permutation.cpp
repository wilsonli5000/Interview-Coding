#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
	Implement next permutation, which rearranges numbers into the lexicographically next greater permu- tation of numbers.
	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascend- ing order).
	Time complexity: O(n)
	Space Complexity: O(1)
	"}"{{}

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

bool nextPermutation(vector<int> & nums){
	if (nums.size() <= 1) return false;
	int n = nums.size();
	// traverse the array from right to left, all the numbers should be increasing, find the first decreasing number.
	int i = n - 2;
	while (i >= 0){
		if (nums[i] < nums[i + 1])
			break;
		i--;
	}
	// then if there is no such number, it means that the array is in its max permutation. then reverse the arrar.
	if ( i == -1){
		reverse(nums.begin(), nums.end());
		return true;
	}
	else{
		// traverse the array from right to left, find the first number which is bigger than nums[i], this is the pivot. then we swap them and reverse the rest of the part from nums[i].
		int pivot = n - 1;
		for (; pivot > i; pivot--){
			if (nums[pivot] > nums[i]){
				swap(nums[pivot], nums[i]);
				reverse(nums.begin() + i + 1, nums.end());
				return true;
			}
		}
		return false;
	}
	
}


int main(){
	vector<int> nums = {8,7,6,4,5,9,10};
	nextPermutation(nums);
	printVectorInt(nums);
}
