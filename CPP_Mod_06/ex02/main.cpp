#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base	*create(int	num)
{
	if (num == 0)
	{
		std::cout << "creating a class A!" << std::endl;
		return (new A);
	}
	else if (num == 1)
	{
		std::cout << "creating a class B!" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "creating a class C!" << std::endl;
		return (new C);
	}
}

void checkPtr(Base *basePtr)
{
	if (dynamic_cast<A*>(basePtr))
		std::cout << "Pointer is a class A" << std::endl;
	else if (dynamic_cast<B*>(basePtr))
		std::cout << "Pointer is a class B" << std::endl;
	else if (dynamic_cast<C*>(basePtr))
		std::cout << "Pointer is a class C" << std::endl;
	else
		std::cout << "Type could not be recognized!" << std::endl;
}

void checkRef(Base &baseRef)
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(baseRef));
		std::cout << "Reference is a class A" << std::endl;
	}
	catch (...)
	{
		try
		{
			static_cast<void>(dynamic_cast<B&>(baseRef));
			std::cout << "Reference is a class B" << std::endl;
		}
		catch (...)
		{
			try
			{
				static_cast<void>(dynamic_cast<C&>(baseRef));
				std::cout << "Reference is a class C" << std::endl;
			}
			catch (...)
			{
				std::cerr << "Type could not be recognized!" << std::endl;
			}
		}
	}
}

int main(void)
{

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int num = std::rand() % 3;

	Base	*basePtr;
	basePtr = create(num);
	Base	&baseRef = *basePtr;
	checkPtr(basePtr);
	checkRef(baseRef);
	delete basePtr;
	return 0;
}
