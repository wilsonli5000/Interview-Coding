#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Trap rain water. Given an array, find the max volume of rain watre can be trapped.
	Time complexty: O(n)
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

// the volume can be trapped in each height equals to min(max_left, max_right) - height.
// so we have to find the max left and max right of each grid.
int trapRainwater(const vector<int> & height){
	if (height.size() <= 2) return 0;
	int n = height.size();
	vector<int> maxLeft (n, 0);
	vector<int> maxRight (n, 0);
	//traverse from left to right, record the max left high wall of each height.
	//traverse from right to left, record the max right high wall of each height.
	for (int i = 1; i < height.size(); i++){
		maxLeft[i] = std::max(maxLeft[i - 1], height[i - 1]);
		maxRight[n - i - 1] = std::max(maxRight[n - i], height[n - i]);
	}

	int sum = 0;
	for (int i = 0; i < height.size(); i++){
		int wall = std::min(maxRight[i], maxLeft[i]);
		wall > height[i] ? sum += wall - height[i] : sum += 0 ;
	}
	return sum;
}

int main(){
	vector<int> grid = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << trapRainwater(grid) << endl;
}
