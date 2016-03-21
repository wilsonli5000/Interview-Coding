#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	A stair has n steps. Climb 1 or 2 steo everytime, return how many ways can you reach the top.
	Time complexity: O()
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

// two ways for each step, either from n - 1 to n or from n - 2 to n.
// Fibonachi sequence. f(n) = f(n - 1) + f(n - 2).
int climbStairs(int n){
	if (n == 0) return 1;
	if (n == 1) return 1;
	return climbStairs(n - 1) + climbStairs(n - 2);
}


int main(){
	cout << climbStairs(5) << "\n";
}
