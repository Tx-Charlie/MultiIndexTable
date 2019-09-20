#include "TestWidget.hpp"
#include "ui_TestWidget.h"

TestWidget::TestWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TestWidget)
{
	ui->setupUi(this);

	ui->m_table_view->setModel( &m_table_model );
}

TestWidget::~TestWidget()
{
	delete ui;
}
