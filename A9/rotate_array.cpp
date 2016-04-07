#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* 

	Given an array with chars, rotate the array rightwards k times. 
	Time complexity: O(n)
	Space complexity: O(1)
*/


void printVector(const vector<char> & v){
	for (auto c : v)
		cout << c << " ";
	cout << endl;
}


// The first method: reverse the first n - k elements, then reverse the rest, then all of them.
void rotateArray1(vector<char> & chars, int step){
	if (chars.size() == 0 || step <= 0)
		return;
	int n = chars.size();
	step = step % n;
	reverse(chars.begin(), chars.begin() + n - step);
	reverse(chars.begin() + n - step, chars.end());
	reverse(chars.begin(), chars.end());
	return;
}

// The second method: 
void rotateArray2(vector<char> & chars, int step){
	if (chars.size() == 0 || step <= 0)
		return;
	int n = chars.size();
	step = step % n;
	int rotate_count = 0;
    int start = 0;
    int cur = 0;
    char next = chars[0];
    char tmp;
    // Keep rotating the elements until we have rotated n 
    // different elements.
    int count = 0;
    while (rotate_count < n){
        cout << "current: " << cur << endl;
        tmp = chars[(cur + step) % n];
        chars[(cur + step) % n] = next;
        next = tmp;
        cout << "next: " << next << endl;
        cur = (cur + step) % n;
        rotate_count++;
        count++;
        cout << "inner loop: " << count << endl;
        printVector(chars);
        // Stop rotating the elements when we finish one cycle, 
        // i.e., we return to start.
    }
}
/*
current: 0
numToBeRotated: D
inner loop: 1
A B C A E F G 
current: 3
numToBeRotated: G
inner loop: 2
A B C A E F D 
current: 6
numToBeRotated: C
inner loop: 3
A B G A E F D 
current: 2
numToBeRotated: F
inner loop: 4
A B G A E C D 
current: 5
numToBeRotated: B
inner loop: 5
A F G A E C D 
current: 1
numToBeRotated: E
inner loop: 6
A F G A B C D 
current: 4
numToBeRotated: A
inner loop: 7
E F G A B C D
*/

int main(){
	vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int step = 5;
	//rotateArray1(chars, step);
	rotateArray2(chars, step);
	//printVector(chars);
	return 0;

}