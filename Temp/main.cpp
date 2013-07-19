#include<iostream>
using namespace std;
#include"SharedPtr.h"
#include"WeakPtr.h"
void test_circle();
void test_shared_ptr()
{
	SharedPtr<int>p1(new int(42));
	SharedPtr<int>p2;
	p2.reset();
	cout<<p1.getUse()<<endl;
}
int main()
{
	test_circle();
	return 0;
}

