#include "person.h"
#include <ostream>


Person::Person(
	std::string const& fcr_name,
	int const fc_age)
	:
m_name(fcr_name),
	m_age(fc_age)
{
}

std::string const& Person::getcrName() const
{
	return m_name;
}

std::string & Person::getrName()
{
	return m_name;
}

int Person::getAge() const
{
	return m_age;
}

int & Person::getrAge()
{
	return m_age;
}

std::ostream& operator<<(std::ostream& fr_stream, Person const& fcr_person)
{
	fr_stream << "Person(name=\"" << fcr_person.getcrName() << "\", age=" << fcr_person.getAge() << ")";
	return fr_stream;
}
