//solution to https://leetcode.com/problems/combination-sum-iii/
//input: candidate numbers are 1-9, each number can be only used once. can only use k numbers for target n.
//output: all possible combinations, in ascending order. no duplicates.
//use dfs.
using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(k, n, path, ans, 0);
    return ans;
}
    
void dfs(int step, int residual, vector<int> & path, vector<vector<int>> & ans, int pos){
	//we use step = target - accumulated sum as the terminate condition.
	//base case: when teh sum of numbers equals to target
	if (step == 0 && residual == 0){
		std::sort(path.begin(), path.end());
		ans.push_back(path);
	}

	if (step > 0){
		for (int i = pos; i <= 9; i++){
			//if i == 0 and path is empty, then we can't set 0 as the first number. 
			//corner case.
		    if (path.empty() && i == 0)
		        continue;
			if (i <= residual){
				path.push_back(i);
				dfs(step - 1, residual - i, path, ans, i + 1);
				path.pop_back();
			}
		}
	}
}