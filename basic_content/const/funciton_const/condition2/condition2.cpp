#include<iostream>

using namespace std;

/**
 * 如果变量是常量，
 * 变量的指针需要定义为常量类型
 */
int main() {
    const int num = 100;
    int *const ptr0 = &num; // error! const int* -> int*
    int* ptr1 = &num;
    const int* ptr2 = &num; // 值为常量
    const int *const ptr3 = &num; // 值为常量 指针本身也为常量
    cout << *ptr0 << endl;
}
