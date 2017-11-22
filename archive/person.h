#pragma once


#include <iosfwd>
#include <string>


class Person
{
public:
	Person(std::string const& fcr_name = "", int const fc_age = 0);
	std::string const& getcrName() const;
	std::string & getrName();
	int getAge() const;
	int& getrAge();
private:
	std::string m_name;
	int m_age;
};


std::ostream& operator<<(std::ostream& fr_stream, Person const& fcr_person);


template <typename t_archive>
void serialize(t_archive & fr_archive, Person const& fcr_p)
{
	fr_archive.serialize("name", fcr_p.getcrName());
	fr_archive.serialize("age", fcr_p.getAge());
}


template <typename t_archive>
void deserialize(t_archive & fr_archive, Person & fr_p)
{
	fr_archive.deserialize("name", fr_p.getrName());
	fr_archive.deserialize("age", fr_p.getrAge());
}
