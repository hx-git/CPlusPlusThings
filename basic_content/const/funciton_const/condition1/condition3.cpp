#include<iostream>

using namespace std;

int main() {
    const int *ptr;
    int val = 3;
    ptr = &val; //ok
    // 通过另一个地址变量，修改值
    int *ptr1 = &val;
    *ptr1 = 4;
    cout << *ptr << endl;
}
