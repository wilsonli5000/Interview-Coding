#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Given an unsorted array, return the longest consecutive array. doesn't say whether has duplicates.
	eg. [100, 4, 1, 200, 3, 2] return [1, 2, 3, 4]
	Time complexity: O(n)

*/

// Given an unsorted array, first think sorting it. Time complexity will be O(nlog(n)). But O(n) is desired, so use hash table.
// Record the length of longest consecutive sequence of each number, save in hashtable.
// If we don't consider duplicates, then we can simplly store the length as the value. 
// If we consider duplicate, then we store the return vector as the value.
// If all values in the array are disconsecutuve, then we return the first number.

vector<int> longestConsecutive(const vector<int> & nums){
	if (nums.size() <= 1) return nums;
	// traverse one time to save numbers as the key.
	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); i++){
		hash[nums[i]] = 1;
	}

	int max = 0, index = -1;
	// then update the value of each key. it stores the length of longest sequence starts with this number.
	for (int i = 0; i  < nums.size(); i++){
		int temp = nums[i];
		while (hash.find(temp + 1) != hash.end()){
			temp++;
			hash[nums[i]]++;
		}
		if (hash[nums[i]] > max){
			max = hash[nums[i]];
			index = nums[i];
		}
	}

	vector<int> ans;
	if (index == -1) return ans;
	else{
		for (int i = 0; i < max; i++){
			ans.push_back(index + i);
		}
		return ans;
	}
}

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

vector<int> longestConsecutiveDuplicate(const vector<int> & nums){
	if (nums.size() <= 1) return nums;
	// traverse one time to save numbers as the key. Save itself as the value vector, include duplicates.
	unordered_map<int, vector<int> > hash;
	//use -1 as the flag that this key han't be updated.
	for (int i = 0; i < nums.size(); i++){
		vector<int> ans = {-1, nums[i]};
		if (hash.find(nums[i]) != hash.end())
			hash[nums[i]].push_back(nums[i]);
		else
			hash[nums[i]] = ans;
	}	
	int max = 0, index = -1;
	// then update the value of each key. it stores the vector as the value. first check the flag, if -1, then update, if not, then skip.
	for (int i = 0; i  < nums.size(); i++){
		int temp = nums[i];
		// this is used to skip duplicate keys.
		if (hash[temp][0] != -1) continue;
		while (hash.find(temp + 1) != hash.end()){
			hash[nums[i]].push_back(++temp);
		}
		hash[nums[i]].erase(hash[nums[i]].begin());
		if (hash[nums[i]].size() > max){
			max = hash[nums[i]].size();
			index = nums[i];
		}
	}

	vector<int> empty;
	return index == -1 ? empty : hash[index];
}



int main(){
	vector<int> nums = {100, 200, 1, 1, 3, 4, 2};
	vector<int> ans = longestConsecutiveDuplicate(nums);
	printVectorInt(ans);
}
