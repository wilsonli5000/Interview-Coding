#include <vector>
#include <iostream>

using namespace std;

/* 
	Given a sorted array, remove duplicates in place. Each number is allowed at most twice.
	Return a position which is the end of the modified array.
	Time Complexity: O(n)
	Space Complexity: O(1)
*/

// short version. can generalize.
int removeDuplicateShort(vector<int> & nums){
	if (nums.size() <= 2) return 0;
	int pointer = 2;
	for (int i = 2; i < nums.size(); i++){
		if (nums[i] != nums[pointer - 2])
			nums[pointer++] = nums[i];
	}
	return pointer - 1;
}

// use an explicit counter. not so good.
int removeDuplicate2(vector<int> & nums){
	if (nums.size() <= 2) return 0;
	int pointer = 0, counter = 1;
	for (int i = 1; i < nums.size(); i++){
		if (nums[i] == nums[i - 1])
			counter++;
		else 
			counter = 1;
		if (counter <= 2)
			nums[++pointer] = nums[i];
	}
	return pointer;
}

int main(){
	vector<int> nums = {1,1,1,2,2,2,3,4,5,5,6,6,6,6,7,8,8,8,8};
	int pos = removeDuplicate2(nums);
	//output the unique part.
	for (int i = 0; i <= pos; i++){
		cout << nums[i] << endl;
	}
}

