/**
 * @file vptr1.cpp
 * @brief C++虚函数vptr和vtable
 * 编译：g++ -g -o vptr vptr1.cpp -std=c++11
 * @author 光城
 * @version v1
 * @date 2019-07-20
 */

#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * @brief 函数指针
 */
typedef void (*Fun)();


/**
 * @brief 基类
 */
class Base {
public:
    Base() {};

    virtual void fun1() {
        cout << "Base::fun1()" << endl;
    }

    virtual void fun2() {
        cout << "Base::fun2()" << endl;
    }

    virtual void fun3() {}

    ~Base() {};
};


/**
 * @brief 派生类
 */
class Derived : public Base {
public:
    Derived() {};

    void fun1() {
        cout << "Derived::fun1()" << endl;
    }

    void fun2() {
        cout << "Derived::fun2()" << endl;
    }

    ~Derived() {};
};

/**
 * @brief 获取vptr地址与func地址,vptr指向的是一块内存，这块内存存放的是虚函数地址，这块内存就是我们所说的虚表
 *
 * @param obj
 * @param offset
 *
 * @return 
 */
Fun getAddr(void *obj, unsigned int offset) {
    cout << "=======================" << endl;
    void *vptr_addr = (void *) *(unsigned long *) obj;  // 64位操作系统，占8字节，通过*(unsigned long *)obj取出前8字节，即vptr指针
    printf("vptr_addr:%p\n", vptr_addr);

    /**
     * @brief 通过vptr指针访问virtual table，因为虚拟表中每个元素(虚函数指针)在64位编译器下是8个字节，因此通过*(unsigned long *)vptr_addr取出前8字节，
     * 后面加上偏移量就是每个函数的地址！
     */
    void *func_addr = (void *) *((unsigned long *) vptr_addr + offset);
    printf("func_addr:%p\n", func_addr);
    return (Fun) func_addr;
}

Fun getAddr2(void *obj, unsigned int offset) {
    cout << "==========vptr=============" << endl;
    long long *ptr = reinterpret_cast<long long *>(obj);
    cout << "ptr = " << ptr << endl;
    long long *vptr = reinterpret_cast<long long *>(*ptr);
    cout << "vptr = " << vptr << endl;
    Fun fun = reinterpret_cast<Fun>(vptr[offset]);
    printf("func_addr:%p\n", fun);
    return fun;
}

int main(void) {
    Base ptr; // 基类实例
    ptr.fun1();

    Base *pt = new Derived(); // 基类指针指向派生类实例
    pt->fun1();

    Base &pp1 = ptr; // 基类引用指向基类实例
    pp1.fun1();

    Derived d; // 派生类实例
    Base &pp2 = d; // 基类引用指向派生类实例
    pp2.fun1();

    // 手动查找vptr 和 vtable
    Fun f1 = getAddr2(pt, 0);
    (*f1)();
    Fun f2 = getAddr2(pt, 1);
    (*f2)();

    delete pt;
    return 0;
}
