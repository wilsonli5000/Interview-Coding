#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Set the rows or columns to 0 in matrix if there is a 0 in the row or column.
	Do it in place.
	Time complexity: O(m*n)
	Space complexity: O(1)

*/



void printVectorInt(const vector<int> & n){
	for (auto i : n)
		cout << i;
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

void setMatrix(vector<vector<int> > & matrix){
	const int m = matrix.size();
	const int n = matrix[0].size();
	//explicitly use two bools to store whether is there any 0 in 1st row to col.
	bool first_row = false, first_col = false;
	for (int i = 0; i < m; i++){
		if (matrix[i][0] == 0)
			first_col = true;
	}
	for (int j = 0; j < n; j++){
		if (matrix[0][j] == 0)
			first_row = true;
	}

	// use the first row and col to indicate whether is there any 0 in the row or col.
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			if (matrix[i][j] == 0){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}
	
	if (first_row){
		for (int j = 0; j < n; j++)
			matrix[0][j] = 0;
	}
	if (first_col){
		for (int i = 0; i < m; i++){
			matrix[i][0] = 0;
		}
	}
}


int main(){
	vector<vector<int> > matrix = {{1,2,3,4,5,2}, {2,3,4,5,3,1}, {0,3,4,5,0,2}, {1,2,0,3,4,2}};
	printMatrix(matrix);
	setMatrix(matrix);
	printMatrix(matrix);
}
