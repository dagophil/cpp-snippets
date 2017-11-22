#include "demoarchive.h"
#include <iostream>


std::ostream& operator<<(std::ostream& fr_stream, DemoArchive const& fcr_archive)
{
	fr_stream << "< DemoArchive >";
	return fr_stream;
}


void serialize(DemoArchive& fr_archive, int const fc_value)
{
	std::cout << "STORE VALUE (int) " << fc_value << std::endl;
}

void serialize(DemoArchive& fr_archive, std::string const& fcr_value)
{
	std::cout << "STORE VALUE (std::string) " << fcr_value << std::endl;
}


void deserialize(DemoArchive& fr_archive, int& fr_value)
{
	std::cout << "LOAD VALUE (int)" << std::endl;
}

void deserialize(DemoArchive& fr_archive, std::string& fr_value)
{
	std::cout << "LOAD VALUE (std::string)" << std::endl;
}
