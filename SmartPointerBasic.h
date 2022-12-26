#pragma once
#include <iostream>
#include <memory>

class Cat
{
public:
	Cat(int nAge) :m_nAge{ nAge }
	{
		std::cout << "Cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "Cat destructor" << std::endl;
	}

private:
	int m_nAge;
};

void SmartPointerBasicTest()
{
	std::cout << "Before Scope" << std::endl;
	{
		// 유니크 포인터의 라이프 사이클은 스코프 베이스의 라이프 사이클이라고 생각하면 된다.
		std::unique_ptr<Cat> catPtr = std::make_unique<Cat>(3);
	}
	std::cout << "After Scope" << std::endl;
}