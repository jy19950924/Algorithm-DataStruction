//
// Created by dell on 2022/4/25.
//
// 类似荷兰国旗问题，需要返回相等区间

#include "public.h"

pair<int, int> NetherlandsFlags(vector<int> &arr, int target) {
    int leftRange = -1;
    int rightRange = arr.size();
    int index = leftRange + 1;
    while (index < rightRange) {
        if (arr[index] < target) {
            swap(arr[index++], arr[++leftRange]);
        } else if (arr[index] > target) {
            swap(arr[index], arr[--rightRange]);
        } else {
            index++;
        }
    }
    if (++leftRange > --rightRange)return pair<int, int>(-1, -1);

    return pair<int, int>(leftRange, rightRange);
}

//16 3
//11 7 13 5 15 5 13 16 15 3 8 11 10 0 18 6
int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for_each(arr.begin(), arr.end(), [](int &t) {
        cin >> t;
    });

    pair<int, int> equalRange = NetherlandsFlags(arr, k);

    cout << equalRange.first << ' ' << equalRange.second << endl;
}