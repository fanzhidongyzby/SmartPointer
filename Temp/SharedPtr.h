#pragma once
/**
	����ָ�롪�������ü�����ָ��
*/
template<class T>
class SharedPtr
{
	T*ptr;//ʵ�ʵ�ָ��
	unsigned int* use;//���ü���
	//�������ü���
	void release()
	{
		if(!--*use)
		{
			delete ptr;
			delete use;
		}
	}
public:
	//��ʼ��
	SharedPtr(T*p=0):ptr(p),use(new unsigned int(1))
	{}
	//���ָ��
	~SharedPtr()
	{
		release();
	}
	//��������
	SharedPtr(const SharedPtr&p):ptr(p.ptr),use(p.use)
	{
		++*use;//ָ�뿽���������ü���
	}
	//ָ�븳ֵ
	SharedPtr& operator= (const SharedPtr& rval)
	{
		++*rval.use;//���ü����ۼ�
		release();//��ֹ����ֵ�����������ֵ����һ���Լӱ�����������޸�ָ�����������
		ptr=rval.ptr;
		use=rval.use;
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
		if(ptr)return ptr;
		throw std::runtime_error("null shared ptr!");

	}
	//��ȡ���ü���
	unsigned int getUse()
	{
		return *use;
	}
	T* get()const
	{
		return ptr;
	}
	//����
	void reset()
	{
		release();
		ptr=0;
		*use=1;
	}
};