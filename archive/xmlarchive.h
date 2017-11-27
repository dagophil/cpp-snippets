#pragma once


#include <iosfwd>
#include <stdexcept>
#include <string>


namespace Xml
{
	static std::string const sc_xmlVersionTag {"<?xml version=\"1.0\"?>"};
}


class XmlOArchive
{
public:
	template <typename T>
	void serialize(std::string const& fcr_name, T const& fcr_value);

	std::string const& data() const;

private:
	std::string getCurrentIndentation() const;
	void beginSerializeGroup(std::string const& fcr_name);
	void endSerializeGroup(std::string const& fcr_name);
	void beginSerializeValue();
	void endSerializeValue();

	unsigned int m_level {0};
	std::string m_xmlString {Xml::sc_xmlVersionTag};
	bool m_justWrittenValue {false};

	friend void serialize(XmlOArchive& fr_archive, int const fc_value);
	friend void serialize(XmlOArchive& fr_archive, std::string const& fcr_value);
	friend void serialize(XmlOArchive& fr_archive, double const fc_value);
};

void serialize(XmlOArchive& fr_archive, int const fc_value);
void serialize(XmlOArchive& fr_archive, std::string const& fcr_value);
void serialize(XmlOArchive& fr_archive, double const fc_value);


class XmlIArchive
{
public:
	XmlIArchive(std::string const& fcr_xmlString);

	template <typename T>
	void deserialize(std::string const& fcr_name, T & fr_value);

private:
	void skipWhiteSpace();
	void beginDeserializeGroup(std::string const& fcr_name);
	void endDeserializeGroup(std::string const& fcr_name);
	std::string beginDeserializeValue();
	void endDeserializeValue(std::string const& fcr_valueString);

	std::string const mc_xmlString;
	size_t m_currentIndex {0};

	friend void deserialize(XmlIArchive& fr_archive, int& fr_value);
	friend void deserialize(XmlIArchive& fr_archive, std::string& fr_value);
	friend void deserialize(XmlIArchive& fr_archive, double& fr_value);
};

void deserialize(XmlIArchive& fr_archive, int& fr_value);
void deserialize(XmlIArchive& fr_archive, std::string& fr_value);
void deserialize(XmlIArchive& fr_archive, double& fr_value);


class XmlParseError : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};
