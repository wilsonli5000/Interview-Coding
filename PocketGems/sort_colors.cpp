#include <iostream>
#include <vector>

using namespace std;


int threewayquick(vector<int> & colors, int p){
	int l = 0, r = colors.size() - 1, i = 0, pivot = p;
	while(i >= l && i <= r){
		if (colors[i] < pivot && i != l)
			std::swap(colors[i], colors[l++]);
		else if (colors[i] > pivot && i != r)
			std::swap(colors[i], colors[r--]);
		else i++;
	}
	return i;
}

int main(){
	std::vector<int> colors = {0, 1, 2, 1, 1, 0, 0, 2, 0, 1, 3};
	int pos = threewayquick(colors, 1);
	vector<int> newcolor (colors.begin() + pos, colors.end());
	colors.erase(colors.begin() + pos, colors.end());
	pos = threewayquick(newcolor, 2);
	colors.insert(colors.end(), newcolor.begin(), newcolor.end());
	for (auto c : colors){
		cout << c << "\n";
	}
}