#ifndef TABLEMODEL_HPP
#define TABLEMODEL_HPP

#include <QAbstractTableModel>
#include "TableElement.hpp"

class TableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit TableModel( QObject *parent = nullptr);
	~TableModel();


	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int rowCount( const QModelIndex &parent = QModelIndex()) const;
	int columnCount( const QModelIndex &parent = QModelIndex()) const;
	void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

	TableElement* pickFromContainer( int index ) const;


private:
	TableContainer m_container;

	int m_sort_mode;
	//sort mode
	// 1 / -1: by id
	// 2 / -2: by name
	// 3 / -3: by value

	const ContainerSortBy_id &m_container_by_id = m_container.get<1>();
	const ContainerSortBy_name &m_container_by_name = m_container.get<2>();
	const ContainerSortBy_value &m_container_by_value = m_container.get<3>();
};

#endif // TABLEMODEL_HPP
