#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

#define random(a,b) (((double)rand()/RAND_MAX)*(b-a)+a)

//分治法，先划分成两块，每块内部继续划分和排序，排好的都堆在其中一侧
//以下是递增序排列

template <typename T>
int partition(T* a, int p, int r) {
    T x = a[r], tmp;
    int i = p - 1, j = p;
    for (; j <= r - 1; j++) {
        if (a[j] <= x) {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    i = i + 1;
    tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    return i;
}

template <typename T>
void quickSort(T* a, int p, int r) {
    if (p >= r) return;
    int q;
    q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
}

//产生一个 [a, b] 区间内的随机数

int Random(int a, int b) {
    double r = random(a, b);
    return int(r > 0 ? floor(r + 0.5) : ceil(r - 0.5));     //四舍五入
}

template <typename T>
void randomized_quickSort(T* a, int number) {
    if (number == 0) return;
    int x = Random(0, number - 1);
    T tmp = a[number - 1];
    a[number - 1] = a[x];
    a[x] = tmp;
    quickSort(a, 0, number);
}