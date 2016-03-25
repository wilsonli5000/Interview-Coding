#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
	Given a parentheses string which only has '(' and ')'. Return the longest valid parentheses length.
	Time cpmplexity: O(n)
	Spcae complexity: O(n)

*/


int longestValidParentheses(string s){
	if (s.length() < 2) return 0;
	// use a last variable to store the position of the last un-matched right parentheses. This is the indicator of the left end. 
	int max_len = 0, last = -1;
	// use a stack to store the position of left parenthesis. Pop the position whenever this parenthesis is matched. Then whenever we reach the end of pairs, we can know the length of the pairs.
	stack<int> left;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(')
			left.push(i);
		else{
			// if we encounter a right un-matched parentheses, we store its position as the last left end of the next valid parenthese pair.
			if (left.empty())
				last = i;
			else{
				left.pop();
				// if left is empty after popping, then we know that last is the left end of this valid parentheses pair.
				if (left.empty())
					max_len = max(max_len, i - last);
				// if left is not empty, then the length of the current pair is the from the last un-matched postion in the left stack.
				else
					max_len = max(max_len, i - left.top());
			}
		}
	}
	return max_len;

}

int main(){
	string s = ")()())";
	cout << longestValidParentheses(s) << endl;
}
