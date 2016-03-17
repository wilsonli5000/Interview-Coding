#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> & dict){
	//create one more length to store position before string starts.
	vector<bool> ans(s.length() + 1, false);
	ans[0] = true;
	for (int i = 1; i <= s.length(); i++){
		for (int j = 0; j < i; j++){
			//if the current position is a break point and we can find this substring in dict. then we mark pos i as a new 
			// break point.
			if (ans[j] && dict.find(s.substr(j, i - j)) != dict.end()){
				ans[i] = true;
				break;
			}
		}
	}
	return ans.back();
}

int main(){
	string s = "leetcode";
	unordered_set<string> dict = {"leet", "code"};
	wordBreak(s, dict) == true ?  cout << "true\n" : cout << "false\n";
}