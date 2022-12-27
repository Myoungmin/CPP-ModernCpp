#pragma once
#include <iostream>
#include <memory>

class Animal
{};

class Cat : public Animal
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

class Dog : public Animal
{};

class Zoo
{
public:
	Zoo(int n)
	{
		if (n == 1) m_Animal = std::make_unique<Cat>();
		else m_Animal = std::make_unique<Dog>();
	}

private:
	// 이렇게 멤버변수로 유니크 포인터로 설정하면,
	// 멤버 포인터가 가리키는 오브젝트를 클래스 밖의 포인터가 가리키는 것을 원천적으로 차단할 수 있다.
	// 그리하여 오브젝트의 라이프 사이클을 고려할 필요가 없어지게 된다.
	std::unique_ptr<Animal> m_Animal;
};

void UniquePointerTest()
{
	std::unique_ptr<Cat> catPtr = std::make_unique<Cat>();
	// 아래는 컴파일 에러가 발생한다.
	// 유니크 포인터는 오브젝트를 두 개의 포인터가 가리키는 것을 허용하지 않기 때문이다.
	//std::unique_ptr<Cat> catPtr1 = catPtr;

	// std::move로 소유권 이전은 가능하다.
	std::unique_ptr<Cat> catPtr1 = std::move(catPtr);
}