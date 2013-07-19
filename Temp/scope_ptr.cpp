#pragma once
/**
	智能指针——作用域指针，作用域消失销毁内存
*/
template<class T>
class ScopePtr
{
	T*ptr;//实际的指针
	//拷贝构造
	ScopePtr(const ScopePtr&p)
	{}
	//指针赋值
	ScopePtr& operator= (const ScopePtr& rval)
	{}
public:
	//初始化
	ScopePtr(T*p):ptr(p)
	{}
	//解除指针
	~ScopePtr()
	{
		delete ptr;
	}	
	//*运算
	T& operator*()
	{
		if(ptr)return *ptr;
		throw std::runtime_error("null shared ptr!");
	}
	//->运算
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