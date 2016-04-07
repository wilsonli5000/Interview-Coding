#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*


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


int main(){

}
