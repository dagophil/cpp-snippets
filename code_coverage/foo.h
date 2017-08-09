#ifndef FOO_H
#define FOO_H

#include <iostream>

class Foo
{
public:

	void foo0();
	void foo1();

	void bar0()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	void bar1()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

};

#endif
