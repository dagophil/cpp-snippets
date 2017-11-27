#include "binaryarchive.h"
#include <cstdint>
#include <ostream>


namespace
{
	template <typename T>
	void writeBinary(T const& fr_value, std::vector<BYTE> & fr_out)
	{
		BYTE const* const lcpc_byteValues = reinterpret_cast<BYTE const*>(&fr_value);
		for (size_t i = 0; i < sizeof(T); ++i)
		{
			fr_out.push_back(lcpc_byteValues[i]);
		}
	}

	template <>
	void writeBinary<std::string>(std::string const& fcr_value, std::vector<BYTE> & fr_out)
	{
		for (auto const c : fcr_value)
		{
			fr_out.push_back(c);
		}
	}

	template <typename T>
	void readBinary(std::vector<BYTE> const& fcr_data, size_t & fr_index, T & fr_value)
	{
		T const* const lcpc_value = reinterpret_cast<T const*>(&fcr_data[fr_index]);
		fr_value = *lcpc_value;
		fr_index += sizeof(T);
	}

	template <>
	void readBinary<std::string>(std::vector<BYTE> const& fcr_data, size_t & fr_index, std::string & fr_value)
	{
		for (size_t i = 0; i < fr_value.size(); ++i)
		{
			fr_value[i] = fcr_data[fr_index+i];
		}
		fr_index += fr_value.size();
	}
}

std::vector<BYTE> const& BinaryOArchive::data() const
{
	return m_buffer;
}

void serialize(BinaryOArchive& fr_archive, int const fc_value)
{
	auto const lc_value = static_cast<int64_t>(fc_value);
	writeBinary(lc_value, fr_archive.m_buffer);
}

void serialize(BinaryOArchive& fr_archive, std::string const& fcr_value)
{
	auto const lc_size = static_cast<uint64_t>(fcr_value.size());
	writeBinary(lc_size, fr_archive.m_buffer);
	writeBinary(fcr_value, fr_archive.m_buffer);
}

void serialize(BinaryOArchive& fr_archive, double const fc_value)
{
	// assume fixed sizeof(double)
	writeBinary(fc_value, fr_archive.m_buffer);
}


BinaryIArchive::BinaryIArchive(std::vector<BYTE> const& fcr_data)
	:
	mc_data(fcr_data)
{
}

void deserialize(BinaryIArchive& fr_archive, int& fr_value)
{
	int64_t l_value = 0;
	readBinary(fr_archive.mc_data, fr_archive.m_currentIndex, l_value);
	fr_value = static_cast<int>(l_value);
}

void deserialize(BinaryIArchive& fr_archive, std::string& fr_value)
{
	uint64_t l_size = 0;
	readBinary(fr_archive.mc_data, fr_archive.m_currentIndex, l_size);
	fr_value.resize(static_cast<size_t>(l_size));
	readBinary(fr_archive.mc_data, fr_archive.m_currentIndex, fr_value);
}

void deserialize(BinaryIArchive& fr_archive, double& fr_value)
{
	// assume fixed sizeof(double)
	readBinary(fr_archive.mc_data, fr_archive.m_currentIndex, fr_value);
}
