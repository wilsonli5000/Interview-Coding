#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Rotate a matrix clockwise, in place. The matrix must be n*n.
	Time complexity: O(n^2)
	Space complexity: O(1)
*/



void printVectorInt(const vector<int> & n){
	for (auto i : n)
		cout << i;
}

void printMatrix(const vector<vector<int> > & n){
	for (auto i : n){
		printVectorInt(i);
		cout << "\n";
	}
}

void printMap(const unordered_map<int, vector<int> > & hash){
	for (auto itr : hash){
		cout << "key: " << itr.first << endl;
		printVectorInt(itr.second);
	}
}


bool rotateMatrix(vector<vector<int> > & matrix){
	if (matrix.size() == 0) return false;
	// first do a symmetric swap of elements.
	int n = matrix.size();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i; j++)
			swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
	}

	// then flip the rows.
	for (int i = 0; i < n / 2; i++){
		for (int j = 0; j < n; j++)
			swap(matrix[i][j], matrix[n - 1 - i][j]);
	}
	return true;
}


int main(){
	vector<vector<int> > matrix = {{1,2,3}, {2,3,4}, {4,5,6}};	
	rotateMatrix(matrix);
	printMatrix(matrix);
	
}
