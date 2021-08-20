#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge_sort(vector<int>& a);
void merge(vector<int>& a, vector<int>& tmp, int low, int mid, int high);
void merge_sort(vector<int>& a, vector<int>tmp, int low, int high);

void bottom2upper_merge(vector<int>& a);
void bottom2upper_merge(vector<int>& a, vector<int>& tmp);

int main() {
    vector<int> a(10);
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    //merge_sort(a);
    bottom2upper_merge(a);

    for (int j = 0; j < 10; j++)
        cout << a[j] << " ";
    return 0;
}

void merge_sort(vector<int>& a) {
    vector<int> tmp(a.size());
    size_t sz = a.size() - 1;
    int size = (int)sz;
    merge_sort(a, tmp, 0, size);
}

void merge(vector<int>& a, vector<int>& tmp, int low, int mid, int high) {
    int lowEnd = mid - 1;
    int tmpPos = low;
    int num = high - low + 1;

    while (low <= lowEnd && mid <= high) {
        if (a[low] < a[mid]) {
            tmp[tmpPos] = move(a[low]);
            low++;
        }
        else {
            tmp[tmpPos] = move(a[mid]);
            mid++;
        }
        tmpPos++;
    }

    while (low <= lowEnd) {
        tmp[tmpPos] = move(a[low]);
        low++;
        tmpPos++;
    }
    while (mid <= high) {
        tmp[tmpPos] = move(a[mid]);
        mid++;
        tmpPos++;
    }

    //之前没注意，就是 for 循环出问题了，因为 low 的值已经修改过了

    for (int i = 1; i <= num; ++i, --high)
        a[high] = move(tmp[high]);
}

void merge_sort(vector<int>& a, vector<int>tmp, int low, int high) {
    if (low == high) return;
    int mid = (low + high) / 2;
    merge_sort(a, tmp, low, mid);
    merge_sort(a, tmp, mid + 1, high);
    merge(a, tmp, low, mid + 1, high);
}

//以下是归并排序的一些改进
//自底向上的归并排序，从小数组开始，然后再合并成大的已排序的数组

void bottom2upper_merge(vector<int>& a) {
    vector<int> tmp(a.size());
    bottom2upper_merge(a, tmp);
}

void bottom2upper_merge(vector<int>& a, vector<int>& tmp) {
    int size = a.size();
    for (int i = 1; i < size; i = i + i)
        for (int j = 0; j < size - i; j += 2 * i)
            merge(a, tmp, j, j + i, min(j + 2 * i - 1, size - 1));
}