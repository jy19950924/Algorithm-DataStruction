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
		for(; i+stepLen <n; i += stepLen){// ȷ������ ������ ����Ч
			int leftBeginPos = i;
			int leftEndPos = i + stepLen - 1;
			int rightBeginPos = leftEndPos + 1;
			int rightEndPos = rightBeginPos + stepLen - 1 < n ? (rightBeginPos + stepLen - 1) : n - 1;// ���������У����ǲ���֤������һ��������stepLen���ȵ�
			while(leftBeginPos <= leftEndPos && rightBeginPos <= rightEndPos){
				help[i++] = arr[leftBeginPos] < arr[rightBeginPos] ? arr[leftBeginPos++] : arr[rightBeginPos++];
			}
			while(leftBeginPos <= leftEndPos){
				help[i++] = arr[leftBeginPos++];
			}
			while(rightBeginPos <= rightEndPos){
				help[i++] = arr[rightBeginPos++];
			}
			for(int j = 0; j < i; j++){ // �޸�ԭ������ֵ
				arr[j] = help[j];
			}
		}
	}
	for_each(arr.begin() , arr.end() , [](int t){
		cout << t << ' ';
		});
	cout << endl;

}