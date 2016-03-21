#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
	Give N children some candy. Each kid at lease 1 candy. Each kid with higher rating gets more candy than its neighbor.
	Time complexity: O(n)
	Space complexity: O(n)

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

void printMatrix(const vector<vector<int> > & n){
	for (auto i : n){
		printVectorInt(i);
		cout << "\n";
	}
}

int candy(const vector<int> & ratings){
	int n = ratings.size();
	vector<int> candy (n, 1);
	//traverse from left to right.
	for (int i = 1, increment = 1; i < n; i++){
		// use increment to store the extra candy should give because of all the kids to the left. Think about the case [1,2,3,4,1,2].
		if (ratings[i] > ratings[i - 1])
			candy[i] = std::max(increment++, candy[i]);
		else 
			increment = 1;
	}

	for (int i = n - 2, increment = 1; i >= 0; i--){
		if (ratings[i] > ratings[i + 1])
			candy[i] = std::max(increment++, candy[i]);
		else
			increment = 1;
	}
	//return accumulate(candy.begin(), candy.end(), n);
}


int main(){
	vector<int> ratings = {1,2,3,4,3,2,1};
	cout << candy(ratings) << endl;
}
