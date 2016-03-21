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

int gasStation(vector<int> & gas, vector<int> & cost){
	// use current to store the gas remained when arriving gas station[i].
	// use total to store the total gas remained when go around a circle.
	int current = 0, total = 0, j = -1;
	for (int i = 0; i < gas.size(); i++){
		current += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (current < 0){
			j = i;
			current = 0;
		}
	}
	// if we remain some gas after the circle, then return teh index.
	return total >= 0 ? j + 1 : -1;
}

int main(){

}
