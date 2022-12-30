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

	std::shared_ptr<Cat> m_pVar;

private:
	int m_nAge;
};

void SharedPointerTest()
{
	std::shared_ptr<Cat> catPtr = std::make_shared<Cat>();
	std::cout << "count: " << catPtr.use_count() << std::endl;
	
	// ���۷��� ī��Ʈ ����
	std::shared_ptr<Cat> catPtr1 = catPtr;
	std::cout << "count: " << catPtr.use_count() << std::endl;
}

// shared_ptr�� ����Ͽ��� �� �޸� ���� �߻��� �� �ִ� ��Ȳ
void CircularReferenceTest()
{
	{
		std::shared_ptr<Cat> normalPtr = std::make_shared<Cat>();
		std::shared_ptr<Cat> circularReferencePtr = std::make_shared<Cat>();
		// ��� shared_ptr�� �ڱ� �ڽ��� ����
		circularReferencePtr->m_pVar = circularReferencePtr;

		std::cout << "normalPtr count: " << normalPtr.use_count() << std::endl;
		std::cout << "circularReferencePtr count: " << circularReferencePtr.use_count() << std::endl;
	}
	// Scope�� ����� �Ҹ��ڰ� ȣ����� �ʰ� �޸� ���� �߻��Ѵ�.
	// Circular Reference�� ���ܼ� Scope�� ����� ������ 1���� �����־� ������ �ȵȴ�.

	std::cout << "CircularReferenceTest End" << std::endl;
}