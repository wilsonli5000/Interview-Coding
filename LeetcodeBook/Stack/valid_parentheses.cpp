#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
	Given a string, determine whether is it valid. 
	Time complexity: O(n)
	Space complexity: O(n)

*/



bool isValid(string patern){
	if (patern.length() <= 1) return false;
	stack<char> s;
	for (int i = 0; i < patern.length(); i++){
		if (patern[i] == '(' || patern[i] == '[' || patern[i] == '{')
			s.push(patern[i]);
		else{
			switch (patern[i]){
				case ')':
					if (s.empty() || s.top() != '(')
						return false;
					break;
				
				case ']':
					if (s.empty() || s.top() != '[')
						return false;
					break;

				case '}':
					if (s.empty() || s.top() != '{')
						return false;
					break;
			}
			s.pop();
		}
	}
	return s.empty();
}


int main(){
	string patern = "((()))[][]{}{}{}()";
	if (isValid(patern))
		cout << "valid\n";
	else 
		cout << "invalid\n";

}
