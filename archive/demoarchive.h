#pragma once


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

	std::string data() const;
};

void serialize(DemoArchive& fr_archive, int const fc_value);
void serialize(DemoArchive& fr_archive, std::string const& fcr_value);
void serialize(DemoArchive& fr_archive, double const fc_value);

void deserialize(DemoArchive& fr_archive, int& fr_value);
void deserialize(DemoArchive& fr_archive, std::string& fr_value);
void deserialize(DemoArchive& fr_archive, double& fr_value);
