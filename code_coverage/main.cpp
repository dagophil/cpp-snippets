#include "foo.h"


void baz()
{
	std::cout << __FUNCTION__ << std::endl;
}


int main()
{
	Foo f;
	f.foo0();
	f.foo0();
	f.bar0();
}
