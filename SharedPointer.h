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
	std::shared_ptr<Cat> m_pFriend;

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

// shared_ptr를 사용하였을 때 메모리 릭이 발생할 수 있는 상황
void CircularReferenceTest1()
{
	{
		std::shared_ptr<Cat> normalPtr = std::make_shared<Cat>();
		std::shared_ptr<Cat> circularReferencePtr = std::make_shared<Cat>();
		// 멤버 shared_ptr에 자기 자신을 대입
		circularReferencePtr->m_pVar = circularReferencePtr;

		std::cout << "normalPtr count: " << normalPtr.use_count() << std::endl;
		std::cout << "circularReferencePtr count: " << circularReferencePtr.use_count() << std::endl;
	}
	// Scope를 벗어나도 소멸자가 호출되지 않고 메모리 릭이 발생한다.
	// Circular Reference가 생겨서 Scope를 벗어나도 참조가 1개가 남아있어 해제가 안된다.

	std::cout << "CircularReferenceTest End" << std::endl;
}

// shared_ptr를 사용할 때 가장 많이 하는 실수
void CircularReferenceTest2()
{
	std::shared_ptr<Cat> pKitty = std::make_shared<Cat>();
	std::shared_ptr<Cat> pNabi = std::make_shared<Cat>();

	// 서로를 가리키게 하여 메모리 릭이 발생
	pKitty->m_pFriend = pNabi;
	pNabi->m_pFriend = pKitty;
}