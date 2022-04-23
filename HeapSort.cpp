#include"public.h"

// 下沉
void heapify(vector<int> &arr, int index, int heapSize) {
    int leftChild = 2 * index + 1;
    while (leftChild < heapSize) {
        int maxChildIndex =
                leftChild + 1 < heapSize && arr[leftChild] < arr[leftChild + 1] ? leftChild + 1L : leftChild;
        int maxIndex = arr[maxChildIndex] > arr[index] ? maxChildIndex : index;
        if (maxIndex == index) return;
        swap(arr[maxIndex], arr[index]);
        index = maxIndex;
        leftChild = 2 * index + 1;
    }
    for_each(arr.begin(), arr.end(), [](int &t) {
        cout << t << ' ';
    });
    cout << endl;
}

// 上浮 --- 插入生成 大顶堆
void heapInsert(vector<int> &arr, int insertIndex) {// 代表有效的范围 包含该位置
    int fatherIndex = (insertIndex - 1) / 2;
    // 0 的父节点只能是它自己
    while (arr[insertIndex] > arr[fatherIndex]) { // 相等时说明该节点为0节点
        swap(arr[fatherIndex], arr[insertIndex]);
        insertIndex = fatherIndex;
        fatherIndex = (insertIndex - 1) / 2;
    }
}

void HeapSort(vector<int> &arr) {
    if (arr.empty() || arr.size() == 1)return;
    for (int i = arr.size() - 1; i >= 0; i--) {
        heapify(arr, i, arr.size());
    }
    int tail = arr.size() - 1;
    while (tail > 0) {
        swap(arr[tail], arr[0]);
        heapify(arr,0,tail);
        tail--;
    }
}


int main() {
    int n = 0;

    cin >> n;
    vector<int> arr(n, 0);
    for_each(arr.begin(), arr.end(), [](int &t) {
        cin >> t;
    });


    HeapSort(arr);


    for_each(arr.begin(), arr.end(), [](int &t) {
        cout << t << ' ';
    });
    cout << endl;
}