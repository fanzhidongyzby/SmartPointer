#include<iostream>
#include<memory>
using namespace std;
void test_autoPtr()
{

	auto_ptr<int> a1(new int(42));
	auto_ptr<int> a2=a1;//控制权转移
	cout<<*a2<<endl;
	cout<<*a1<<endl;//失去控制权，出错
}