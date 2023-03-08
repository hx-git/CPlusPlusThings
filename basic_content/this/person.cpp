#include<iostream>
#include<cstring>

using namespace std;

class Person {
public:
    typedef enum {
        BOY = 0,
        GIRL
    } SexType;

    Person(char *n, int a, SexType s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
        sex = s;
    }

    int get_age() const {
        return this->age;
    }

    // 返回一个拷贝对象?
    Person add_age(int a) {
        age += a;
        return *this;
    }

    // 返回一个引用，地址和this相同
    Person &add_age2(int a) {
        age += a;
        return *this;
    }

    // 返回地址
    Person *add_age3(int age) {
        this->age += age;
        return this;
    }

    ~Person() {
        delete[] name;
    }

private:
    char *name;
    int age;
    SexType sex;
};


int main() {
    Person p("Tom", 20, Person::BOY);

    Person p1 = p.add_age(10);
    Person &p2 = p.add_age2(2);
    Person p3 = p.add_age2(3);
    Person *p4 = p.add_age3(4);

    cout << " p = " << &p << endl << "p1 = " << &p1 << endl << "p2 = " << &p2 << endl;
    cout << "p3 = " << &p3 << endl;
    cout << "p4 = " << p4 << endl;

    cout << p.get_age() << endl;
    p1.get_age();
    p2.get_age();
    p3.get_age();
    p4->get_age();
    return 0;
}
