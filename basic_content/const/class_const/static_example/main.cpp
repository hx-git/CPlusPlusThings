#include<iostream>
#include"apple.cpp"
using namespace std;
const int Apple::apple_number=10;
int Apple::ap=666;
Apple::Apple(int i)
{

}
int Apple::add(int num){
    take(num);
}
int Apple::add(int num) const{
    take(num);
}
void Apple::take(int num) const
{
    cout<<"take func "<<num<<endl;
}
int Apple::getCount() const
{
    take(1);
//    add(); // error 不能调用非const函数
    return apple_number;
}
int main(){
    Apple a(2);
    cout<<a.getCount()<<endl;
    cout<<a.ap<<endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}
