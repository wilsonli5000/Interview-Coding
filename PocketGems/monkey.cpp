#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int x, int y){
		x = x;
		y = y;
	};
};


static int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int countPoints(int k, Point p ){
	vector<Point> set(INT_MAX);
	queue<Point> queue;
	queue.push(p);
	while (!queue.empty()){
		Point cp = queue.front();
		queue.pop();
		//if this node is unqualified.
		if (std::find(set.begin(), set.end(), cp) != set.end() || cp.x + cp.y > k)
			continue;
		//if the node is good to use. 
		set.push_back(cp);
		for (int i = 0; i < 4; i++){
			Point np = Point(cp.x + dir[i][0], cp.y + dir[i][1]);
			if (std::find(set.begin(), set.end(), np) == set.end())
				queue.push(np);
		}
	}
	return set.size();
}

int main(){
	Point p = Point(0, 0);
	int points = countPoints(19, p);
	cout << "number of points: " << points << endl;
}