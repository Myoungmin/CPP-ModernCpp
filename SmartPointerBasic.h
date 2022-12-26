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
		// ����ũ �������� ������ ����Ŭ�� ������ ���̽��� ������ ����Ŭ�̶�� �����ϸ� �ȴ�.
		std::unique_ptr<Cat> catPtr = std::make_unique<Cat>(3);
	}
	std::cout << "After Scope" << std::endl;
}