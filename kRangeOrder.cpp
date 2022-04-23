//
// Created by dell on 2022/4/23.
//
//题目：已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，
//并且k相对于数组来说比较小，请选择一个合适的排序算法针对这个数据进行排序
#include"public.h"

void heapify(vector<int> &arr, int heapSize, int index) { // 小根堆  O(logN)
    int leftChildIndex = index * 2 + 1;
    while (leftChildIndex < heapSize) {
        int maxIndex =
                (leftChildIndex + 1 < heapSize) && arr[leftChildIndex + 1] < arr[leftChildIndex] ? leftChildIndex + 1
                                                                                                 : leftChildIndex;
        maxIndex = (arr[maxIndex] > arr[index]) ? index : maxIndex;
        if (maxIndex == index)return;

        swap(arr[maxIndex], arr[index]);
        index = maxIndex;
        leftChildIndex = index * 2 + 1;
    }
}


int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for_each(arr.begin(), arr.end(), [](int &t) {
        cin >> t;
    });
    int i = 0;
    for (; i < arr.size() - k; i++) {// 代表 滑动窗口 的开始节点 [i,i+k)
        for (int j = i + k; j >= i; j--) {
            heapify(arr, j, i); // 形成小根堆
        }
    }
    // 最后剩下k个值，排序即可
    // 小根堆化
    for(int index =i;index<arr.size();index++){
        for (int heapIndex =arr.size()-1;heapIndex>=index;heapIndex--){
            heapify(arr,arr.size(),heapIndex);
        }
    }

    for_each(arr.begin(),arr.end(),[](int& t){
        cout<<t<<' ';
    });
    cout<<endl;
}


// java 方法可进行改写后，利用对数器进行测试
//public class HeapSortDemo01 {
//public static void main(String[] args) {
//        int[] arr = {1, 5, 4, 3, 6, 8, 10, 101, 55};
//        sort(arr, 5);
//        System.out.println(Arrays.toString(arr));
//    }
//
//public static void sort(int[] arr, int k) {
//        /*
//         * 解题思路：
//         * 1、已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，
//         * 可以得出，取数组中的前K个数，必然存在整个数组中的最小值
//         * 2、将前k个数加入小根堆中，通过边弹边取的方式，即可有序
//         */
//        // 将前K个数压入小根堆中
//        int index = 0;
//        PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
//        for (; index <= Math.min(arr.length - 1, k); index++) {
//            heap.add(arr[index]);
//        }
//        int i = 0;
//        for (; index <= arr.length - 1; i++, index++) {
//            heap.add(arr[index]);
//            arr[i] = heap.poll();
//        }
//        // 弹出剩余数
//        while (!heap.isEmpty()) {
//            arr[i++] = heap.poll();
//        }
//    }
