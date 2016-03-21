#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
	Plus one to the number represented by a string.
	Time complexity: O(n)
	Space complexity: O(1)

*/



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



// simple program, use carry bit to do addition just like numbers.
bool plusOne(string & num){
	if (num.length() == 0) return false;
	int n = num.length();
	int carry = 1;
	for (int i = n - 1; i >= 0; i--){
		int tmp = num[i] - '0' + carry;
		num[i] = tmp % 10 + '0';
		carry = tmp / 10;
		}
	if (carry)
		num = "1" + num;
	return true;
}


int main(){
	string num = "99999";
	plusOne(num);
	cout << num << endl;
}
