#include <vector>
#include <iostream>

using namespace std;

/* 
	Given a sorted array, remove duplicates in place. 
	Return a position which is the end of the modified array.
	Time Complexity: O(n)
	Space Complexity: O(1)
*/

int removeDuplicate(vector<int> & nums){
	if (nums.size() <= 1) return 0;
	int pointer = 0;
	for (int i = 1; i < nums.size(); i++){
		if (nums[i] != nums[i - 1])
			nums[++pointer] = nums[i];
	}
	return pointer;
}

int main(){
	vector<int> nums = {1,1,1,2,2,2,3,4,5,5,6,6,6,6,7,8,8,8,8};
	int pos = removeDuplicate(nums);
	//output the unique part.
	for (int i = 0; i <= pos; i++){
		cout << nums[i] << endl;
	}
}

