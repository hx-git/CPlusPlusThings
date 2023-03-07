#include<iostream>

using namespace std;

int main() {
    int num = 0;
    int *const ptr = &num; // const指针必须初始化
    *ptr = 100; // 可以通过指针修改值
    // *ptr = &num; // 指针不能修改
    int *t = &num;
    *t = 1;
    cout << *ptr << endl;
}
