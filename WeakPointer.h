#pragma once
#include <iostream>
#include <memory>

class Cat
{
public:
	Cat() :m_nAge{ 1 }
	{
		std::cout << "Cat constructor" << std::endl;
	}

	void speak()
	{
		std::cout << "My Age : " << m_nAge << std::endl;
	}

	~Cat()
	{
		std::cout << "Cat destructor" << std::endl;
	}

	// ������Ʈ�� ������ ����Ŭ�� ��� ������ ������ ���� �ʰ� �Ǳ⶧���� �޸� ���� �������ش�.
	std::weak_ptr<Cat> m_pFriend;
private:
	int m_nAge;
};

void WeakPointerTest1()
{
	std::weak_ptr<Cat> wPtr;
	{
		std::shared_ptr<Cat> sPtr = std::make_shared<Cat>();
		wPtr = sPtr;
		// Weak Pointer�� �Ȱ��� ������Ʈ�� ����Ű�� �־ count�� 1�̴�.
		std::cout << "count: " << sPtr.use_count() << std::endl;

		// if ������ shared_ptr�� �ϳ��� �����Ǿ���.
		if (const auto spt = wPtr.lock())
		{
			// count ������ ���� ��µȴ�.
			std::cout << "count: " << spt.use_count() << std::endl;
			// weak_ptr�κ��� ���� ������� shared_ptr�� ������Ʈ�� ����Ѵ�.
			spt->speak();
		}
	}
}

// shared_ptr �������� ��� weak_ptr�� valid�� ������Ʈ�� ����Ű�� �ʴ´�.
void WeakPointerTest2()
{
	std::weak_ptr<Cat> wPtr;
	{
		std::shared_ptr<Cat> sPtr = std::make_shared<Cat>();
		wPtr = sPtr;
	}
	if (const auto spt = wPtr.lock())
	{
		std::cout << "count: " << spt.use_count() << std::endl;
		spt->speak();
	}
	else
	{
		std::cout << "pointing nothing" << std::endl;
	}
}