cmake_minimum_required(VERSION 3.7)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)


add_executable(main
	main.cpp
	mywidget.h
	mywidget.cpp
	mywidget.ui
	resources.qrc
)

target_link_libraries(main
	Qt5::Widgets
)
