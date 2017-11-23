#pragma once


#include <QWidget>
#include <memory>


namespace Ui { class MyWidgetUi; }


class MyWidget : public QWidget
{
public:
	MyWidget();
	~MyWidget();
private:
	std::unique_ptr<Ui::MyWidgetUi> mup_ui;
};
