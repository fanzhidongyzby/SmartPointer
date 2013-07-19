#pragma once
/**
	����ָ�롪��������ָ�룬��������ʧ�����ڴ�
*/
template<class T>
class ScopePtr
{
	T*ptr;//ʵ�ʵ�ָ��
	//��������
	ScopePtr(const ScopePtr&p)
	{}
	//ָ�븳ֵ
	ScopePtr& operator= (const ScopePtr& rval)
	{}
public:
	//��ʼ��
	ScopePtr(T*p):ptr(p)
	{}
	//���ָ��
	~ScopePtr()
	{
		delete ptr;
	}	
	//*����
	T& operator*()
	{
		if(ptr)return *ptr;
		throw std::runtime_error("null shared ptr!");
	}
	//->����
	T* operator->()
	{
		if(ptr)return ptr;
		throw std::runtime_error("null shared ptr!");

	}
	T* get()const
	{
		return ptr;
	}
};

void test_scope()
{
	ScopePtr<int>scp(new int);
}