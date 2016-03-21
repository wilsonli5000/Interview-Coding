#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Given an array, every element occurs exactly three times, except one. Find it.
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

int singleNumber2(const vector<int> & nums){
	// create a vector which stores the occurence of 1 in each bit position of an integer.
	vector<int> count (sizeof(int) * 8, 0);
	// then traverse each number in the array and update the count vector if there is a 1 in the correpsonding bit position.
	// and we take the mod of 3 each time as the final bit in that position. The bit vector consists the integer.
	for (int i = 0; i < nums.size(); i++){
		for (int j = 0; j < count.size(); j++){
			count[j] += (nums[i] >> j) & 1;
			count[j] %= 3;
		}
	}
	int ans = 0;
	for (int i = 0; i < count.size(); i++)
		ans += (count[i] << i);
	return ans;


}

int main(){
	vector<int> nums = {1,1,1,2,2,2,3,4,4,4,5,5,5};
	cout << singleNumber2(nums) << endl;
}
