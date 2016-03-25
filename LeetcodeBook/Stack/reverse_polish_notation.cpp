#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

/*
  Given a reverse polish notation, do the arithmatic.
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9;
  ["4", "13". "5", "/", "+"] -> (4 + (13 / 5)) -> 6;
  Time complexity: O(n)
  Space complexity: O(logn)

*/



void printStack(stack<int> s){
  if (s.empty()) return;
  while (!s.empty()){
    cout << s.top() << endl;
    s.pop();
  }
}


int reversePolishNotation(vector<string> & notation){
  // assume that the notation is valid.
  stack<int> s;
  for (int i = 0; i < notation.size(); i++){
    if (notation[i] != "+" && notation[i] != "-" && notation[i] != "*" && notation[i] != "/")
      s.push(stoi(notation[i], nullptr, 10));
    else{
      int num1 = s.top();
      s.pop();
      int num2 = s.top();
      s.pop();
      if (notation[i] == "+")
          s.push(num1 + num2);
      else if (notation[i] == "-")
          s.push(num2 - num1);
      else if (notation[i] == "*")
          s.push(num1 * num2);
      else if (notation[i] == "/")
          s.push(int(num2 / num1));
    }
  }
  // determine whether the result is valid.
  if (s.size() != 1) return INT_MIN;
  else return s.top();
}

int main(){
  vector<string> s = {"4", "13", "5", "/", "+"};
  cout << reversePolishNotation(s) << endl;
}
