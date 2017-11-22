#pragma once


#include "person.h"
#include <iosfwd>


class Family
{
public:
	Family(Person const& fcr_father = Person(),
		Person const& fcr_mother = Person(),
		Person const& fcr_son = Person(),
		Person const& fcr_daughter = Person());
	Person const& getcrFather() const;
	Person & getrFather();
	Person const& getcrMother() const;
	Person & getrMother();
	Person const& getcrSon() const;
	Person & getrSon();
	Person const& getcrDaughter() const;
	Person & getrDaughter();
private:
	Person m_father;
	Person m_mother;
	Person m_son;
	Person m_daughter;
};


std::ostream& operator<<(std::ostream& fr_stream, Family const& fcr_family);


template <typename t_archive>
void serialize(t_archive & fr_archive, Family const& fcr_f)
{
	fr_archive.serialize("father", fcr_f.getcrFather());
	fr_archive.serialize("mother", fcr_f.getcrMother());
	fr_archive.serialize("son", fcr_f.getcrSon());
	fr_archive.serialize("daughter", fcr_f.getcrDaughter());
}


template <typename t_archive>
void deserialize(t_archive & fr_archive, Family & fr_f)
{
	fr_archive.deserialize("father", fr_f.getrFather());
	fr_archive.deserialize("mother", fr_f.getrMother());
	fr_archive.deserialize("son", fr_f.getrSon());
	fr_archive.deserialize("daughter", fr_f.getrDaughter());
}
