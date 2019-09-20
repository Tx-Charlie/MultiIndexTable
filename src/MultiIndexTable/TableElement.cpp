#include "TableElement.hpp"

TableElement::TableElement(int id, std::string name, double value) : m_id(id), m_name(name), m_value(value)
{}

bool TableElement::operator < (const TableElement &other)
{
	if( m_id != other.m_id)
		return m_id < other.m_id;

	if( m_name != other.m_name)
		return m_name < other.m_name;

	return m_value > other.m_value;
}
