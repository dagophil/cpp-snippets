#include "xmlarchive.h"
#include <iostream>


std::string XmlOArchive::getCurrentIndentation() const
{
	std::string l_indentation;
	for (unsigned int i = 0; i < m_level; ++i)
	{
		l_indentation += "  ";
	}
	return l_indentation;
}

void XmlOArchive::beginSerializeGroup(std::string const& fcr_name)
{
	m_xmlString += "\n" + getCurrentIndentation() + "<" + fcr_name + ">";
	++m_level;
}

void XmlOArchive::endSerializeGroup(std::string const& fcr_name)
{
	--m_level;
	if (!m_justWrittenValue)
	{
		m_xmlString += "\n" + getCurrentIndentation();
	}
	m_justWrittenValue = false;
	m_xmlString += "</" + fcr_name + ">";
}

void XmlOArchive::beginSerializeValue()
{
}

void XmlOArchive::endSerializeValue()
{
	m_justWrittenValue = true;
}

std::ostream& operator<<(std::ostream& fr_stream, XmlOArchive const& fcr_archive)
{
	fr_stream << fcr_archive.m_xmlString;
	return fr_stream;
}

void serialize(XmlOArchive& fr_archive, int const fc_value)
{
	fr_archive.beginSerializeValue();
	fr_archive.m_xmlString += std::to_string(fc_value);
	fr_archive.endSerializeValue();
}

void serialize(XmlOArchive& fr_archive, std::string const& fcr_value)
{
	fr_archive.beginSerializeValue();
	fr_archive.m_xmlString += fcr_value;
	fr_archive.endSerializeValue();
}


XmlIArchive::XmlIArchive(std::string const& fcr_xmlString)
	:
	mc_xmlString(fcr_xmlString)
{
	skipWhiteSpace();
	std::string const lc_versionTag =
		mc_xmlString.substr(m_currentIndex, Xml::sc_xmlVersionTag.size());
	if (Xml::sc_xmlVersionTag != lc_versionTag)
	{
		throw XmlParseError("Expected tag \"" + Xml::sc_xmlVersionTag + "\", found \"" + lc_versionTag + "\".");
	}
	m_currentIndex += Xml::sc_xmlVersionTag.size();
}

void XmlIArchive::skipWhiteSpace()
{
	m_currentIndex = mc_xmlString.find_first_not_of(" \t\r\n", m_currentIndex);
}

void XmlIArchive::beginDeserializeGroup(std::string const& fcr_name)
{
	skipWhiteSpace();
	std::string const lc_beginTagExpected =
		"<" + fcr_name + ">";
	std::string const lc_beginTag =
		mc_xmlString.substr(m_currentIndex, 2+fcr_name.size());
	if (lc_beginTagExpected != lc_beginTag)
	{
		throw XmlParseError("Expected tag \"" + lc_beginTagExpected + "\", found \"" + lc_beginTag + "\".");
	}
	m_currentIndex += lc_beginTag.size();
}

void XmlIArchive::endDeserializeGroup(std::string const& fcr_name)
{
	skipWhiteSpace();
	std::string const lc_endTagExpected =
		"</" + fcr_name + ">";
	std::string const lc_endTag =
		mc_xmlString.substr(m_currentIndex, 3+fcr_name.size());
	if (lc_endTagExpected != lc_endTag)
	{
		throw XmlParseError("Expected tag \"" + lc_endTagExpected + "\", found \"" + lc_endTag + "\".");
	}
	m_currentIndex += lc_endTag.size();
}

std::string XmlIArchive::beginDeserializeValue()
{
	size_t const lc_endIndex = mc_xmlString.find('<', m_currentIndex);
	return mc_xmlString.substr(m_currentIndex, lc_endIndex-m_currentIndex);
}

void XmlIArchive::endDeserializeValue(std::string const& fcr_valueString)
{
	m_currentIndex += fcr_valueString.size();
}

void deserialize(XmlIArchive& fr_archive, int& fr_value)
{
	std::string const lc_valueString = fr_archive.beginDeserializeValue();
	fr_value = std::stoi(lc_valueString);
	fr_archive.endDeserializeValue(lc_valueString);
}

void deserialize(XmlIArchive& fr_archive, std::string& fr_value)
{
	std::string const lc_valueString = fr_archive.beginDeserializeValue();
	fr_value = lc_valueString;
	fr_archive.endDeserializeValue(lc_valueString);
}
