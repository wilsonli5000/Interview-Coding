//solution to https://leetcode.com/problems/combination-sum-ii/
//input: vector of cadidate integers, each number can be only used once.
//output: all possible combinations, in ascending order. no duplicates.
//use dfs.
using namespace std;

vector<vector<int>> combination_sum2(vector<int> & candidates, int target){
	vector<vector<int>> ans;
	vetcor<int> path;
	//first so
	std::sort(candidates.begin(), candidates.end());
	//here we use pos to eliminate duplicates. eg. if the input is [1, 2], target = 3, then we need 
	//[1,1,1], [1,2]. But if we start traverse candidates from the beginning every time, when the algorithm
	//uses [2] as the first number, it will add [1] and we will eventually have two [1, 2].
	dfs(candidates, target, path, ans, 0);
	return ans;
}

//pass path by reference is for space saving.
void dfs(const vector<int> & candidates, int step, vetcor<int> & path, vector<vector<int>> & ans, int pos){
	//we use step = target - accumulated sum as the terminate condition.
	//base case: when teh sum of numbers equals to target
	if (step == 0){
		std::sort(path.begin(), path.end());
		ans.push_back(path);
	}

	if (step > 0){
		for (int i = pos; i < candidates.size(); i++){
			if (candidates[i] <= step){
				if (i > pos && candidates[i] == candidates[i - 1])
					continue;
				path.push_back(candidates[i]);
				dfs(candidates, step - candidates[i], path, ans, i + 1);
				path.pop_back();
			}
		}
	}
}