#include "TableModel.hpp"

TableModel::TableModel( QObject *parent) : QAbstractTableModel(parent), m_sort_mode(1)
{
	// Example:
	m_container.push_back( new TableElement());
	m_container.push_back( new TableElement( 1, "Test1", 1));
	m_container.push_back( new TableElement( 101, "Charlie", -1));
	m_container.push_back( new TableElement( 102, "Delta", -10));
	m_container.push_back( new TableElement( 2, "Test2", 1));
	m_container.push_back( new TableElement( 1000, "Echo", 10.0));
	m_container.push_back( new TableElement( 1030, "Foxtrot", 233));
}

TableModel::~TableModel()
{
	for(TableContainer::iterator it = m_container.begin(); it != m_container.end(); ++it)
		delete (*it);

	m_container.clear();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
	if( role == Qt::DisplayRole)
	{
		if( 0 <= index.row() && index.row() < m_container.size())
		{
			TableElement* tmp_element = this->pickFromContainer( index.row() );
			switch( index.column() )
			{
				case 0: return QVariant( tmp_element->m_id );
				case 1: return QVariant( tmp_element->m_name.c_str());
				case 2: return QVariant( tmp_element->m_value);
				default: break;
			}
		}
	}

	return QVariant();
}

int TableModel::rowCount(const QModelIndex &parent) const
{	return int(m_container.size());	}

int TableModel::columnCount(const QModelIndex &parent) const
{	return TableElement::COLUMN_COUNT;	}

void TableModel::sort(int column, Qt::SortOrder order)
{
	this->beginResetModel();

	m_sort_mode = column + 1;
	if(order == Qt::AscendingOrder)
		m_sort_mode = -m_sort_mode;

	this->endResetModel();
}

// pickup element in each column
TableElement* TableModel::pickFromContainer(int index) const
{
	switch(  m_sort_mode )
	{
		case 1:	return *(m_container_by_id.nth(index));
		case -1:	return *(m_container_by_id.nth( m_container.size() - index - 1));

		case 2:	return *(m_container_by_name.nth(index));
		case -2:	return *(m_container_by_name.nth( m_container.size() - index - 1));

		case 3:	return *(m_container_by_value.nth(index));
		case -3:	return *(m_container_by_value.nth( m_container.size() - index - 1));

		default: return *(m_container_by_id.nth(index));
	}
}
