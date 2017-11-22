cmake_minimum_required(VERSION 3.3)

project(Archive)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
	main.cpp
	demoarchive.h
	demoarchive.cpp
	demoarchive.inl
	xmlarchive.h
	xmlarchive.cpp
	xmlarchive.inl
	family.h
	family.cpp
	person.h
	person.cpp)
