#include "binaryarchive.h"
#include "demoarchive.h"
#include "family.h"
#include "person.h"
#include "xmlarchive.h"
#include <iomanip>
#include <iostream>
#include <sstream>

#include "binaryarchive.inl"
#include "demoarchive.inl"
#include "xmlarchive.inl"


std::ostream& operator<<(std::ostream& fr_stream, std::vector<BYTE> const& fcr_vector)
{
	fr_stream << fcr_vector.size() << " bytes: ";
	fr_stream << std::hex;
	for (BYTE const x : fcr_vector)
	{
		fr_stream << std::setfill('0') << std::setw(2) << (int)x << " ";
	}
	fr_stream << std::dec;
	return fr_stream;
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
		auto const lc_result = l_oArchive.data();
		std::cout << "Result:\n";
		std::cout << lc_result << "\n";
		std::cout << "--\n";
		IArchive l_iArchive(lc_result);
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
		auto const lc_result = l_oArchive.data();
		std::cout << "Result:\n";
		std::cout << lc_result << "\n";
		std::cout << "--\n";
		IArchive l_iArchive(lc_result);
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
			Person("DaughterName", 10),
			1.234567890123456);
		std::cout << "Serializing Family:\n";
		std::cout << lc_oFamily << "\n";
		OArchive l_oArchive;
		l_oArchive.serialize("my_family", lc_oFamily);
		auto const lc_result = l_oArchive.data();
		std::cout << "Result:\n";
		std::cout << lc_result << "\n";
		std::cout << "--\n";
		IArchive l_iArchive(lc_result);
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
	test_archive<BinaryOArchive, BinaryIArchive>();
}
