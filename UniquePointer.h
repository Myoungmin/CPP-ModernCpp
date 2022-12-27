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
	// �̷��� ��������� ����ũ �����ͷ� �����ϸ�,
	// ��� �����Ͱ� ����Ű�� ������Ʈ�� Ŭ���� ���� �����Ͱ� ����Ű�� ���� ��õ������ ������ �� �ִ�.
	// �׸��Ͽ� ������Ʈ�� ������ ����Ŭ�� ����� �ʿ䰡 �������� �ȴ�.
	std::unique_ptr<Animal> m_Animal;
};

void UniquePointerTest()
{
	std::unique_ptr<Cat> catPtr = std::make_unique<Cat>();
	// �Ʒ��� ������ ������ �߻��Ѵ�.
	// ����ũ �����ʹ� ������Ʈ�� �� ���� �����Ͱ� ����Ű�� ���� ������� �ʱ� �����̴�.
	//std::unique_ptr<Cat> catPtr1 = catPtr;

	// std::move�� ������ ������ �����ϴ�.
	std::unique_ptr<Cat> catPtr1 = std::move(catPtr);
}