#include <iostream>
#include <vector>

using namespace std;

/*
	Search element in a rotated sorted array. No duplicates.
	Return index if found. Return -1 otherwise.

*/

// use binary serach to search the pivot.
int search(const vector<int> & nums, int pivot){
	if (nums.size() == 0) return -1;
	int l = 0, r = nums.size() - 1; 
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (nums[l] < nums[mid])
			r = mid - 1;
		else if (nums[mid] > pivot)
			l = mid + 1;
		else 
			return mid;
	}
	return -1;
}




int main(){
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int index = search(nums, 0);
	cout << index << endl;
}
