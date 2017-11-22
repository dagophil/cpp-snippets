#pragma once


#include <iosfwd>
#include <string>


class DemoArchive
{
public:
	DemoArchive(std::string const& fcr_input = "")
	{}

	template <typename T>
	void serialize(std::string const& fcr_name, T const& fcr_value);

	template <typename T>
	void deserialize(std::string const& fcr_name, T & fr_value);
};


std::ostream& operator<<(std::ostream& fr_stream, DemoArchive const& fcr_archive);


void serialize(DemoArchive& fr_archive, int const fc_value);
void serialize(DemoArchive& fr_archive, std::string const& fcr_value);

void deserialize(DemoArchive& fr_archive, int& fr_value);
void deserialize(DemoArchive& fr_archive, std::string& fr_value);
