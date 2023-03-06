#include<iostream>
using namespace std;

// 不能使用 void* 保存
int main(){
    const int p = 10;
    const void *vp = &p;
    void *vp = &p; //error
}
