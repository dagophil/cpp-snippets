#pragma once

#include "demoarchive.h"


template <typename T>
void DemoArchive::serialize(std::string const& fcr_name, T const& fcr_value)
{
	std::cout << "BEGIN STORE GROUP " << fcr_name << std::endl;
	::serialize(*this, fcr_value);
	std::cout << "END STORE GROUP " << fcr_name << std::endl;
}

template <typename T>
void DemoArchive::deserialize(std::string const& fcr_name, T & fr_value)
{
	std::cout << "BEGIN LOAD GROUP " << fcr_name << std::endl;
	::deserialize(*this, fr_value);
	std::cout << "END LOAD GROUP " << fcr_name << std::endl;
}
