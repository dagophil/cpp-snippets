#pragma once


#include <iosfwd>
#include <vector>


typedef unsigned char BYTE;


class BinaryOArchive
{
public:
	template <typename T>
	void serialize(std::string const& fcr_name, T const& fcr_value);

	std::vector<BYTE> const& data() const;

private:

	std::vector<BYTE> m_buffer;

	friend void serialize(BinaryOArchive& fr_archive, int const fc_value);
	friend void serialize(BinaryOArchive& fr_archive, std::string const& fcr_value);
	friend void serialize(BinaryOArchive& fr_archive, double const fc_value);
};

void serialize(BinaryOArchive& fr_archive, int const fc_value);
void serialize(BinaryOArchive& fr_archive, std::string const& fcr_value);
void serialize(BinaryOArchive& fr_archive, double const fc_value);


class BinaryIArchive
{
public:
	BinaryIArchive(std::vector<BYTE> const& fcr_data);

	template <typename T>
	void deserialize(std::string const& fcr_name, T & fr_value);

private:

	std::vector<BYTE> const mc_data;
	size_t m_currentIndex {0};

	friend void deserialize(BinaryIArchive& fr_archive, int& fr_value);
	friend void deserialize(BinaryIArchive& fr_archive, std::string& fr_value);
	friend void deserialize(BinaryIArchive& fr_archive, double& fr_value);
};

void deserialize(BinaryIArchive& fr_archive, int& fr_value);
void deserialize(BinaryIArchive& fr_archive, std::string& fr_value);
void deserialize(BinaryIArchive& fr_archive, double& fr_value);
