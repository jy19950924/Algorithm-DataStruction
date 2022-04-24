//
// Created by dell on 2022/4/24.
//
#include"public.h"

void NetherlandsFlags(vector<int> &arr, int target) {
    int leftRange = -1;// 可以将leftRange,rightRange变量参数化
    int rightRange = arr.size();
    int cur = 0;
    while (cur < rightRange) {
        if (arr[cur] < target) {
            swap(arr[++leftRange], arr[cur++]);
        } else if (arr[cur] > target) {
            swap(arr[--rightRange], arr[cur]);
        } else {
            cur++;
        }
    }
}


int main() {
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> arr(n, 0);
    for_each(arr.begin(), arr.end(), [](int &t) {
        cin >> t;
    });

    NetherlandsFlags(arr, target);

    for_each(arr.begin(), arr.end(), [](int t) {
        cout << t << ' ';
    });
    cout << endl;
    return 0;
}

