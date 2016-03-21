#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle){
	if (haystack.length() < needle.length())
		return -1;
	int i = 0;
	while (i <= haystack.length() - needle.length()){
		if (haystack.compare(i, needle.length(), needle) == 0) 
			return i;
		i++;
	}
	return -1;
}

int main(){
	string haystack = "abcdefghijsbcde";
	string needle = "bc";
	int pos = strStr(haystack, needle);
	cout << pos << endl;
}