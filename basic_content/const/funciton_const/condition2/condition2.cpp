#include<iostream>

using namespace std;

int main() {
    const int num = 0;
    int *const ptr = &num; // error! const int* -> int*
    const int *const ptr1 = &num; // 正确
    cout << *ptr << endl;
}
