#include "demoarchive.h"
#include "xmlarchive.h"
#include "family.h"
#include "person.h"
#include <iostream>
#include <sstream>

#include "demoarchive.inl"
#include "xmlarchive.inl"


namespace
{
	template <typename T>
	std::string toString(T const& fcr_value)
	{
		std::stringstream l_ss;
		l_ss << fcr_value;
		return l_ss.str();
	}
}


template <typename OArchive, typename IArchive>
void test_archive()
{
	{
		std::cout << "----------------------------------------\n";
		int const lc_oInt = 5;
		std::cout << "Serializing int:\n";
		std::cout << lc_oInt << "\n";
		OArchive l_oArchive;
		l_oArchive.serialize("my_int", lc_oInt);
		std::string const lc_resultString = toString(l_oArchive);
		std::cout << "Result:\n";
		std::cout << lc_resultString << "\n";
		std::cout << "--\n";
		IArchive l_iArchive(lc_resultString);
		int l_iInt = 0;
		l_iArchive.deserialize("my_int", l_iInt);
		std::cout << "Deserialized result:\n";
		std::cout << l_iInt << "\n";
	}
	{
		std::cout << "----------------------------------------\n";
		Person const lc_oPerson("Tom", 20);
		std::cout << "Serializing Person:\n";
		std::cout << lc_oPerson << "\n";
		OArchive l_oArchive;
		l_oArchive.serialize("my_person", lc_oPerson);
		std::string const lc_resultString = toString(l_oArchive);
		std::cout << "Result:\n";
		std::cout << lc_resultString << "\n";
		std::cout << "--\n";
		IArchive l_iArchive(lc_resultString);
		Person l_iPerson;
		l_iArchive.deserialize("my_person", l_iPerson);
		std::cout << "Deserialized result:\n";
		std::cout << l_iPerson << "\n";
	}
	{
		std::cout << "----------------------------------------\n";
		Family const lc_oFamily(
			Person("FatherName", 40),
			Person("MotherName", 40),
			Person("SonName", 10),
			Person("DaughterName", 10));
		std::cout << "Serializing Family:\n";
		std::cout << lc_oFamily << "\n";
		OArchive l_oArchive;
		l_oArchive.serialize("my_family", lc_oFamily);
		std::string const lc_resultString = toString(l_oArchive);
		std::cout << "Result:\n";
		std::cout << lc_resultString << "\n";
		std::cout << "--\n";
		IArchive l_iArchive(lc_resultString);
		Family l_iFamily;
		l_iArchive.deserialize("my_family", l_iFamily);
		std::cout << "Deserialized result:\n";
		std::cout << l_iFamily << "\n";
	}
}


int main()
{
	test_archive<DemoArchive, DemoArchive>();
	test_archive<XmlOArchive, XmlIArchive>();
}
