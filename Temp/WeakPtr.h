#pragma once
#include "SharedPtr.h"
/**
	智能指针——无引用计数的指针
*/
template<class T>
class WeakPtr
{
	T*ptr;//实际的指针
public:
	//初始化
	WeakPtr(T*p=0):ptr(p)
	{}
	WeakPtr(const SharedPtr<T>& sp):ptr(sp.get())
	{}
	//拷贝构造
	WeakPtr(const WeakPtr&p):ptr(p.ptr)
	{}
	//指针赋值
	WeakPtr& operator= (const WeakPtr& rval)
	{
		ptr=rval.ptr;
		return *this;
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
		return ptr;
	}
	//重置
	void reset()
	{
		ptr=0;
	}
	SharedPtr<T> lock()const
	{
		SharedPtr<T> sp(ptr);
		return sp;
	}
};