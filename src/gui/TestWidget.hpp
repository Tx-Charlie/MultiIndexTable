#ifndef TESTWIDGET_HPP
#define TESTWIDGET_HPP

#include <QWidget>
#include "TableModel.hpp"

namespace Ui {
class TestWidget;
}

class TestWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TestWidget(QWidget *parent = nullptr);
	~TestWidget();

private:
	Ui::TestWidget *ui;

	TableModel m_table_model;
};

#endif // TESTWIDGET_HPP
