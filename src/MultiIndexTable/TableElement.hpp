#ifndef TABLEELEMENT_HPP
#define TABLEELEMENT_HPP

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ranked_index.hpp>
#include <boost/multi_index/member.hpp>

#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/ranked_index_fwd.hpp>

#include <string>

struct TableElement
{
	TableElement( int id = 0, std::string name = "nameless", double value = 0);

	bool operator < (const TableElement &other);

	int m_id;
	std::string m_name;
	double m_value;

	static const int COLUMN_COUNT = 3;
};

// define list
typedef boost::multi_index_container<
		TableElement*,
		boost::multi_index::indexed_by<
			boost::multi_index::sequenced<>,
			boost::multi_index::ranked_unique< boost::multi_index::member<TableElement, int , &TableElement::m_id> >,
			boost::multi_index::ranked_non_unique< boost::multi_index::member<TableElement, std::string, &TableElement::m_name> >,
			boost::multi_index::ranked_non_unique< boost::multi_index::member<TableElement, double, &TableElement::m_value> >
		>
	>
TableContainer;

// sort by:

typedef TableContainer::nth_index<1>::type ContainerSortBy_id;
typedef ContainerSortBy_id::iterator ContainerSortBy_id_Iterator;

typedef TableContainer::nth_index<2>::type ContainerSortBy_name;
typedef ContainerSortBy_name::iterator ContainerSortBy_name_Iterator;

typedef TableContainer::nth_index<3>::type ContainerSortBy_value;
typedef ContainerSortBy_value::iterator ContainerSortBy_value_Iterator;

#endif // TABLEELEMENT_HPP
