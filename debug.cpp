#include <iostream>
using namespace std;
//please debug the following three programs.

//P1: this program is used to determine whether the input is divisible by 8.
bool f(int t){
	return !(t & 7);
}

//P2: the problem is it will get a warning and the compiler doesn't know which to execute first
//this is called unsequenced problem.
/*
uint v[10];
uint i = 0;
while (i < 10)
	v[i] = i++;
*/
//P3: the program determines whether the input number is 2^n
bool f_2(uint n){
	return (n & (n - 1)) == 0;
}

int main(){
	int t = 15;
	//cout << f_2(t);
	uint v[10];
	uint i = 0;
	while (i < 10){
		v[i] = i++;
		cout << v[i];
	}
	return 0;
}
