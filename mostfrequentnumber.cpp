#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


int mostFrequentNumber(vector<int> numbers){
	if (numbers.size() == 0) return -1;
	unordered_map<int,int> hash;
	for (int i = 0; i < numbers.size(); i++){
		if (hash.find(numbers[i]) != hash.end())
			hash[numbers[i]]++;
		else
			hash[numbers[i]] = 1;
	}
	int ans = -1;
	for (auto i : hash){
		if (i.second > ans)
			ans = i.second;
	}
	return ans == -1 ? 0 : ans;
}

int main(){
	vector<int> num = {1,1,1,1,1,2,2,4,5,6};
	cout << mostFrequentNumber(num) << endl;
}

//top k version

map<int,int> m;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printelements(vector<int> &temp,int k){
    for(int i=0;i<=k;++i){
        cout<<temp[i]<<endl;
    }
} 

int partition(vector<int> &a, int low,int high){
    int pivot = high-1;
    int i=low-1;
    for(int j=low;j<high-1;j++){
        if(m[a[j]]>=m[a[pivot]]){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    i++;
    swap(&a[i],&a[pivot]);
    return i;
}

void quickselect(vector<int> &temp,int low,int high,int k){
    if(low>high){
        return ;
    }
    int pivot=partition(temp,low,high);
    if(k==pivot){
        printelements(temp,k);
        return;
    }
    else if(k<pivot){
        quickselect(temp,low,pivot,k);
    }
    else{
        quickselect(temp,pivot+1,high,k);
    }
}

void topKelements(vector<int> a, int k){
    if(k<0)return ;
    int n = a.size();
    map<int, int> hash;
    for(int i=0;i<n;i++){
        if(m.find(a[i])!=m.end()){
            m[a[i]]++;
        }
        else{
            m[a[i]] = 1;
        }
    }
    vector<int> temp;
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();++it){
        temp.push_back(it->first);
    }
    k=min(k,(int)temp.size()-1);
    quickselect(temp,0,temp.size(),k);
}

int main() {
    int a[] = {1,2,3,4,1,1,2,3,4,4,4,1};
    int k = 2;
    topKelements(a,12,k-1);
}