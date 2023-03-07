#include<iostream>

using namespace std;

void printAddr(const int **p) {
    cout << "ptr = " << *p << endl;
    if (*p != nullptr) {
        cout << "val = " << **p << endl;
    }
}

/**
 * 常量指针（指向常量的指针，需要定义为常量类型的指针）
 *
 * 指针可以指向任意值
 * 不能通过指针修改变量的值（不能修改地址指向的值）
 */
int main() {
    int const *ptr;
    // *ptr = 10; //error
    printAddr(&ptr);
    int num = 100;
    ptr = &num;
    printAddr(&ptr);
    int num1 = 200;
    ptr = &num1;
    printAddr(&ptr);
    // 使用其他方式修改指针变量指向的值
    int *ptr1 = &num1;
    *ptr1 = 300;
    printAddr(&ptr);
}
