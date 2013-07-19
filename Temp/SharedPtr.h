#pragma once
/**
	智能指针——带引用计数的指针
*/
template<class T>
class SharedPtr
{
	T*ptr;//实际的指针
	unsigned int* use;//引用计数
	//减少引用计数
	void release()
	{
		if(!--*use)
		{
			delete ptr;
			delete use;
		}
	}
public:
	//初始化
	SharedPtr(T*p=0):ptr(p),use(new unsigned int(1))
	{}
	//解除指针
	~SharedPtr()
	{
		release();
	}
	//拷贝构造
	SharedPtr(const SharedPtr&p):ptr(p.ptr),use(p.use)
	{
		++*use;//指针拷贝增加引用计数
	}
	//指针赋值
	SharedPtr& operator= (const SharedPtr& rval)
	{
		++*rval.use;//引用计数累加
		release();//防止自身赋值，如果是自身赋值，上一句自加被抵消，如果修改指针则减少引用
		ptr=rval.ptr;
		use=rval.use;
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
		if(ptr)return ptr;
		throw std::runtime_error("null shared ptr!");

	}
	//获取引用计数
	unsigned int getUse()
	{
		return *use;
	}
	T* get()const
	{
		return ptr;
	}
	//重置
	void reset()
	{
		release();
		ptr=0;
		*use=1;
	}
};