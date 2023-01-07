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

	// 오브젝트의 라이프 사이클은 멤버 변수의 영향을 받지 않게 되기때문에 메모리 릭을 방지해준다.
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
		// Weak Pointer가 똑같은 오브젝트를 가리키고 있어도 count가 1이다.
		std::cout << "count: " << sPtr.use_count() << std::endl;

		// if 문에서 shared_ptr이 하나가 생성되었다.
		if (const auto spt = wPtr.lock())
		{
			// count 증가한 것이 출력된다.
			std::cout << "count: " << spt.use_count() << std::endl;
			// weak_ptr로부터 새로 만들어진 shared_ptr로 오브젝트를 사용한다.
			spt->speak();
		}
	}
}

// shared_ptr 스코프를 벗어나 weak_ptr가 valid한 오브젝트를 가리키지 않는다.
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