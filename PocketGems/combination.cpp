//solution to https://leetcode.com/problems/combinations/
//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//use dfs.
using namespace std;

vector<vector<int>> combination(int n, int k){
	vector<vector<int>> ans;
	vector<int> path;
	
	dfs(k, n, path, ans, 1);
	return ans;
}

void dfs(int step, int n, vector<int> & path, vector<vector<int>> & ans, int pos){
	//we use step = target - accumulated sum as the terminate condition.
	//base case: when teh sum of numbers equals to target
	if (step == 0){
		std::sort(path.begin(), path.end());
		ans.push_back(path);
	}

	if (step > 0){
		for (int i = pos; i <= n; i++){
			path.push_back(i);
			dfs(step - 1, n, path, ans, i + 1);
			path.pop_back();
		}
	}
}