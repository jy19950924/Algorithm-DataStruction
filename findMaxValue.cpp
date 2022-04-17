

#include "public.h"


int getMax(int begin , int end , vector<int>& arr){
	if(begin == end)
		return arr[begin];
	int medium = begin + (end - begin) / 2;
	int frontMax = getMax(begin , medium , arr);
	int backMax = getMax(medium+1 , end , arr);
	if(frontMax > backMax)
		return frontMax;
	else
		return backMax;
}

int main(){
	int n = 0;
	cin >> n;
	vector<int> arr(n , 0);
	for_each(arr.begin() , arr.end() , [&](int& t){
		cin >> t;
		});
	
	cout << getMax(0 , arr.size() - 1 , arr) << endl;

	return 0;
}