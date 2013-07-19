//带引用计数智能指针的循环引用问题
#include <string>
#include <iostream>
using namespace std;
#include "SharedPtr.h"
#include"WeakPtr.h"

class parent;
class children;

typedef SharedPtr<parent> parent_ptr;
typedef SharedPtr<children> children_ptr;

class parent
{
public:
	~parent() { cout <<"destroying parent\n"; }

public:
	children_ptr children;
};

class children
{
public:
	~children() { cout <<"destroying children\n"; }
public:
	WeakPtr<parent> parent;
};


void test_circle()
{
	std::cout<<"begin test...\n";
	{
		parent_ptr father(new parent);
		children_ptr son(new children);

		father->children = son;
		son->parent = father;//若不是weak_ptr,最后的引用都是1，无法释放new！
	}
	std::cout<<"end test.\n";
}


