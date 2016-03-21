#include <iostream>
#include <vector>

using namespace std;

/*

	Given two sorted arrays, find the kth smallest (largest) value. 
	Words for finding median.
	Time complexity: O(log(m + n))
	Space complexity: 

*/

// the algorithm works because each time, we delete k/2 elements from either A or B.
int kthsmallest(const vector<int> & A, int m, const vector<int> & B, int n, int k){
	// for coding simplicity, always set m <= n.
	if (m > n) return kthsmallest(B, n, A, m, k);
	// if A is empty, then just return the kth of B. 
	if (m == 0) return B[k - 1];
	// if k == 1, then no need for k /2 and loop again.
	if (k == 1) return std::min(A[0], B[0]);
	// here, index_b != min(k / 2, n). this is because we want two parts of the arrays can give us whole array with length k.
	int ia = std::min(k / 2, m), ib = k - ia;
	// the 1st condition, A[ia - 1] < B[ib - 1], then we delete the first part of A. 
	if (A[ia - 1] < B[ib - 1]){
		vector<int> A_n (A.begin() + ia, A.end());
		return kthsmallest(A_n, m - ia, B, n, k - ia);
	}
	else if (A[ia - 1] > B[ib - 1]){
		vector<int> B_n (B.begin() + ib, B.end());
		return kthsmallest(A, m, B_n, n - ib, k - ib);
	}
	else 
		return A[ia - 1];
}


double findMedian(const vector<int> & nums1, const vector<int> & nums2){
	int m = nums1.size(), n = nums2.size(), total = m + n;
	if (total % 2 == 0)
		return double(kthsmallest(nums1, m, nums2, n, total / 2 + 1) + kthsmallest(nums1, m, nums2, n, total / 2)) / 2;
	else
		return double(kthsmallest(nums1, m, nums2, n, total / 2));
} 



int main(){
	vector<int> nums1 = {1,1,1,1,3,4,5,6,9};
	vector<int> nums2 = {4,5,6,7,8,8,8,8,12};
	double median = findMedian(nums1, nums2);
	cout << median << endl;

}
