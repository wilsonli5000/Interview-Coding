#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Give unsorted array and a target, return all indexes of numbers add up to target in pairs. index have to be in order. In this solution, we consider duplicate numbers, but don't consider case like 2+2 = 4. Then we can use set. 
	Time Complexity: O(n)
	Space Complexity: O(n)

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

vector<vector<int> > twoSum(const vector<int> & nums, int target){
	vector<vector<int> > ans;
	if (nums.size() < 2) return ans;

	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); i++)
		hash[nums[i]] = i;

	for (int i = 0; i < nums.size(); i++){
		int diff = target - nums[i];
		if (hash.find(diff) != hash.end()){
			vector<int> v = {i};
			if (hash[diff] > i)
				v.push_back(hash[diff]);
			else if (hash[diff] < i)
				v.insert(v.begin(), hash[diff]);
			else 
				continue;
			ans.push_back(v);
		}
	}
	return ans;
}


int main(){
	vector<int> nums = {10, 1, 1, 2, 3, 7, 2};
	vector<vector<int> > v = twoSum(nums, 4);
	for (auto vv : v){
		cout << "pair: \n";
		printVectorInt(vv);
	}

}
