#pragma once

#include "xmlarchive.h"


template <typename T>
void XmlOArchive::serialize(std::string const& fcr_name, T const& fcr_value)
{
	beginSerializeGroup(fcr_name);
	::serialize(*this, fcr_value);
	endSerializeGroup(fcr_name);
}


template <typename T>
void XmlIArchive::deserialize(std::string const& fcr_name, T & fr_value)
{
	beginDeserializeGroup(fcr_name);
	::deserialize(*this, fr_value);
	endDeserializeGroup(fcr_name);
}
