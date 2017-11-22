#include "family.h"
#include <ostream>


Family::Family(
	Person const& fcr_father,
	Person const& fcr_mother,
	Person const& fcr_son,
	Person const& fcr_daughter)
	:
	m_father(fcr_father),
	m_mother(fcr_mother),
	m_son(fcr_son),
	m_daughter(fcr_daughter)
{
}

Person const& Family::getcrFather() const
{
	return m_father;
}

Person & Family::getrFather()
{
	return m_father;
}

Person const& Family::getcrMother() const
{
	return m_mother;
}

Person & Family::getrMother()
{
	return m_mother;
}

Person const& Family::getcrSon() const
{
	return m_son;
}

Person & Family::getrSon()
{
	return m_son;
}

Person const& Family::getcrDaughter() const
{
	return m_daughter;
}

Person & Family::getrDaughter()
{
	return m_daughter;
}

std::ostream& operator<<(std::ostream& fr_stream, Family const& fcr_family)
{
	fr_stream << "Family(father=" << fcr_family.getcrFather()
		<< ", mother=" << fcr_family.getcrMother()
		<< ", son=" << fcr_family.getcrSon()
		<< ", daughter=" << fcr_family.getcrDaughter()
		<< ")";
	return fr_stream;
}
