#pragma once
#include "SharedPtr.h"
/**
	����ָ�롪�������ü�����ָ��
*/
template<class T>
class WeakPtr
{
	T*ptr;//ʵ�ʵ�ָ��
public:
	//��ʼ��
	WeakPtr(T*p=0):ptr(p)
	{}
	WeakPtr(const SharedPtr<T>& sp):ptr(sp.get())
	{}
	//��������
	WeakPtr(const WeakPtr&p):ptr(p.ptr)
	{}
	//ָ�븳ֵ
	WeakPtr& operator= (const WeakPtr& rval)
	{
		ptr=rval.ptr;
		return *this;
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
		return ptr;
	}
	//����
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