#include <iostream>

#include "mywidget.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>


int main(int argc, char *argv[])
{
	QApplication l_app(argc, argv);

	QFile l_stylesheetFile(":/main.css");
	if (l_stylesheetFile.open(QFile::ReadOnly | QFile::Text))
	{
		QTextStream l_stream(&l_stylesheetFile);
		l_app.setStyleSheet(l_stream.readAll());
	}
	else
	{
		std::cout << "Failed to open stylesheet file." << std::endl;
	}

	MyWidget l_widget;
	l_widget.show();
	return l_app.exec();
}
