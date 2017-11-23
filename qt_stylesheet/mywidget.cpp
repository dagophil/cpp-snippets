#include "mywidget.h"
#include "ui_mywidget.h"


MyWidget::MyWidget()
	:
	mup_ui(new Ui::MyWidgetUi())
{
	mup_ui->setupUi(this);
}


MyWidget::~MyWidget()
{
}
