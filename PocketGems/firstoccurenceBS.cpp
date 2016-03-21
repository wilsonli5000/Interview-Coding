#include <iostream>
#include <vector>

using namespace std;


int binarySearch(vector<int> nums, int tar){
	int l = 0, r = nums.size(), first = -1; 
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (tar > nums[mid])
			l = mid + 1;
		else if (tar < nums[mid])
			r = mid - 1;
		else{
			first = mid;
			r = mid - 1;
		}
	}
	return first;
}

int main(){
	vector<int> nums = {1,1,1,2,3};
	int first = binarySearch(nums, 1);
	cout << first << "\n";
}