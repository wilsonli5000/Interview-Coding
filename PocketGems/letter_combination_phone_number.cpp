//solution to https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//input: phone button diagram.
//output: all possible combinations for a number button combo.
//use dfs.

using namespace std;

vector<string> lookuptable = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> letterCombinations(string digits){
	string path;
	vector<string> ans;

	if (digits.length() == 0) return ans;
	dfs(digits, path, ans, 0);
	return ans;
}

void dfs(string digits, string path, vector<string> & ans, int step){
	if (step == digits.length())
		ans.push_back(path);
	else{
		//here, use step as the iterator which walks through the lookup table for each number in digits.
		for (int i = 0; i < lookuptable[digits[step] - '0'].length(); i++){
			dfs(digits, path + lookuptable[digits[step] - '0'][i], ans, step + 1);
		}
	}
}