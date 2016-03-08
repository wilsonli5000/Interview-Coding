//solution to https://leetcode.com/problems/factor-combinations/
//input: a number n.
//output: all possible factor combinations without duplicates, factors bigger than 1 smaller than n.
//use dfs.

using namespace std;

vector<vector<int>> getFactors(int n){
	vector<vector<int>> ans;
	vector<int> path;

	if (n <= 3) return ans;
	dfs(n, path, ans, 2);
	return ans;
}

void dfs(int residual, vector<int> & path, vector<vector<int>> & ans, int pos){
	if (residual == 1 && path.size() >= 2)
		ans.push_back(path);
	
	if (residual > 1){
	    //here we set i to be <= residual to save a lot of iterations.
		for (int i = pos; i <= residual; i++){
			if (residual % i == 0){
				path.push_back(i);
				dfs(residual / i, path, ans, i);
				path.pop_back();
			}
		}
	}
}