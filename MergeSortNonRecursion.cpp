#include"public.h"

void merge(int beginPos , int endPos , vector<int>& arr){
	if(beginPos > endPos) return;
	int mediumPos = beginPos + ((endPos - beginPos) >> 1);
	int p1 = beginPos;
	int p2 = mediumPos + 1;
	vector<int> alter;
	while(p1 <= mediumPos && p2 <= endPos){
		alter.push_back(arr[p1] < arr[p2] ? arr[p1++] : arr[p2++]);
	}
	while(p1 <= mediumPos){
		alter.push_back(arr[p1++]);
	}
	while(p2 <= endPos){
		alter.push_back(arr[p2++]);
	}
	for(int i = 0; i < alter.size(); i++){
		arr[beginPos + i] = alter[i];
	}
}
int main(){
	int n = 0;
	cin >> n;
	vector<int> arr(n , 0);
	for_each(arr.begin() , arr.end() , [](int& t){
		cin >> t;
		});

	int stepLen = 2;
	while(stepLen < n){
		int i = 0;
		for(; (i+stepLen-1) <n; i += stepLen){
			merge(i , i + stepLen - 1 , arr);
		}
		merge(i , n - 1 , arr);// 0-7 8-15  8 10   16
		stepLen *= 2;
	}
	merge(0 , n - 1 , arr);
	
	for_each(arr.begin() , arr.end() , [](int t){
		cout << t << ' ';
		});
	cout << endl;

}