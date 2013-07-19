//�����ü�������ָ���ѭ����������
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
		son->parent = father;//������weak_ptr,�������ö���1���޷��ͷ�new��
	}
	std::cout<<"end test.\n";
}


