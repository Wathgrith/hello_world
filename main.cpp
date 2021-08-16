#include <iostream>
#include <vector>
using namespace std;

//思路是将 a[i] 插入到其左侧的合适的位置，同时比 a[i] 大的数值都向左移动一格
// vector 类的数值传递要用 move()

void insert_sort(vector<int> &a){
    for (int i = 0; i < int(a.size()); i++){
        int tmp = move(a[i]);
        int j;
        for (j = i; j > 0 && tmp < a[j - 1]; j--)
             a[j] = move(a[j - 1]);
        a[j] = move(tmp);
    }
    for (int i = 0; i < int(a.size()); i++)
        cout << a[i] << " ";
}

//思路是将每次扫描发现的最小元素挪到未确定排序区域的最左边即 a[i] 处

void select_sort(vector<int> &a){
    for (int i = 0; i < int(a.size()); i++){
        int min = move(a[i]);
        int j, num;
        for (j = i; j < int(a.size()); j++){ //不要把 if 内容放进循环第二句里，会直接导致循环不彻底
            if (min >= a[j]){
                min = move(a[j]);
                num = j;
            }
        }
        int tmp = move(a[i]);
        a[num] = move(tmp);
        a[i] = move(min);
    }

    for (int i = 0; i < int(a.size()); i++)
        cout << a[i] << " ";
}

void shell_sort(vector<int> &a){
    int size = a.size();
    int h = 1;
    while (h <= size / 3)
        h = 2 * h + 1;
    
    while (h >= 1){
        for (int i = h; i < size; i++){
            int tmp;
            for (int j = i; j >= h && a[j] < a[j - h]; j += h){
                    tmp = move(a[j]);
                    a[j] = move(a[j + h]);
                    a[j + h] = move(tmp);
            }
        }
        h = h / 3;
    }

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}

int main(){
    vector<int> a(15);
    for (int i = 0; i < 15; i++)
        cin >> a[i];
    insert_sort(a);
    cout << endl;
    select_sort(a);
    cout << endl;
    shell_sort(a);
    return 0;
}