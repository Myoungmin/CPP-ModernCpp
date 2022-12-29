#pragma once
#include <iostream>
#include <memory>

class Cat
{
public:
	Cat() :m_nAge{ 0 }
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

void SharedPointerTest()
{
	std::shared_ptr<Cat> catPtr = std::make_shared<Cat>();
	std::cout << "count: " << catPtr.use_count() << std::endl;
	
	// 레퍼런스 카운트 증가
	std::shared_ptr<Cat> catPtr1 = catPtr;
	std::cout << "count: " << catPtr.use_count() << std::endl;
}