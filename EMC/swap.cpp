#include <iostream>

using namespace std;

void swap(int & a, int & b){
	a += b;		// a = a + b;
	b -= a;		// b = b - a - b = -a;
	b = -b;		// b = a;
	a -= b;		// a = a + b - a = b;
}

int main(){
	int a = 12, b = -8;
	swap(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}