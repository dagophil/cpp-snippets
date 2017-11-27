#pragma once

#include "binaryarchive.h"


template <typename T>
void BinaryOArchive::serialize(std::string const& fcr_name, T const& fcr_value)
{
	::serialize(*this, fcr_value);
}

template <typename T>
void BinaryIArchive::deserialize(std::string const& fcr_name, T & fr_value)
{
	::deserialize(*this, fr_value);
}
