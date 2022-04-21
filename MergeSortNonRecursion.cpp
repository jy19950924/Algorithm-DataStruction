#include"public.h"

int main(){
	int n = 0;
	cin >> n;
	vector<int> arr(n , 0);
	for_each(arr.begin() , arr.end() , [](int& t){
		cin >> t;
		});
	vector<int> help(n , 0);
	for(int stepLen =1;stepLen<n;stepLen+=2){
		int i = 0;
		for(; i+stepLen <n; i += stepLen){// 确保存在 右数列 且有效
			int leftBeginPos = i;
			int leftEndPos = i + stepLen - 1;
			int rightBeginPos = leftEndPos + 1;
			int rightEndPos = rightBeginPos + stepLen - 1 < n ? (rightBeginPos + stepLen - 1) : n - 1;// 存在右数列，但是不保证右数列一定是满足stepLen长度的
			while(leftBeginPos <= leftEndPos && rightBeginPos <= rightEndPos){
				help[i++] = arr[leftBeginPos] < arr[rightBeginPos] ? arr[leftBeginPos++] : arr[rightBeginPos++];
			}
			while(leftBeginPos <= leftEndPos){
				help[i++] = arr[leftBeginPos++];
			}
			while(rightBeginPos <= rightEndPos){
				help[i++] = arr[rightBeginPos++];
			}
			for(int j = 0; j < i; j++){ // 修改原数组中值
				arr[j] = help[j];
			}
		}
	}
	for_each(arr.begin() , arr.end() , [](int t){
		cout << t << ' ';
		});
	cout << endl;

}