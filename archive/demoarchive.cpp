#include "demoarchive.h"
#include <iostream>


std::string DemoArchive::data() const
{
	return "< DemoArchive >";
}

void serialize(DemoArchive& fr_archive, int const fc_value)
{
	std::cout << "STORE VALUE (int) " << fc_value << std::endl;
}

void serialize(DemoArchive& fr_archive, std::string const& fcr_value)
{
	std::cout << "STORE VALUE (std::string) " << fcr_value << std::endl;
}

void serialize(DemoArchive& fr_archive, double const fc_value)
{
	std::cout << "STORE VALUE (double) " << fc_value << std::endl;
}

void deserialize(DemoArchive& fr_archive, int& fr_value)
{
	std::cout << "LOAD VALUE (int)" << std::endl;
}

void deserialize(DemoArchive& fr_archive, std::string& fr_value)
{
	std::cout << "LOAD VALUE (std::string)" << std::endl;
}

void deserialize(DemoArchive& fr_archive, double& fr_value)
{
	std::cout << "LOAD VALUE (double)" << std::endl;
}
