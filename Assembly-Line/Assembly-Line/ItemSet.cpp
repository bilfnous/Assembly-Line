/*
*	Assembly Line Milestone 1
*	ItemSet.cpp
*	Date 2019-07-05
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

/*
	ItemSet manages the stock inventory of a particular item.	
*/

#include <iostream>
#include <iomanip>
#include "ItemSet.h"

namespace sict {

	/*
		A constructor that receives a reference to an unmodifiable string, 
		extracts 4 tokens from the string, populates the object with those tokens 
		and determines the field width to be used in displaying data for all objects of the class.
	*/
	ItemSet::ItemSet(const std::string& record) {
		//size_t next_pos = record.find(mo_utility.getDelimiter());
		//m_name = record.substr(0, next_pos);

		size_t next_pos = 0;
		m_name = mo_utility.extractToken(record, next_pos);
		m_serialNumber = std::stoul(mo_utility.extractToken(record, next_pos));	// extract token and convert from string to ulong
		m_quantity = std::stoi(mo_utility.extractToken(record, next_pos));
		m_description = mo_utility.extractToken(record, next_pos);

		// update the utility fieldWidth with the largest name's length
		if (mo_utility.getFieldWidth() < m_name.length())
			mo_utility.setFieldWidth(m_name.length());
	}

	ItemSet::ItemSet(ItemSet && other) {
		if (this != &other)	{
			m_name = other.m_name;
			m_description = other.m_description;
			m_serialNumber = other.m_serialNumber;
			m_quantity = other.m_quantity;

			other.m_name = { "" };
			other.m_description = { "" };
			other.m_serialNumber = { 0 };
			other.m_quantity = { 0 };
		}
	}


	/*
		A query that returns a reference to the name of the item
	*/
	const std::string& ItemSet::getName() const {
		return m_name;
	}

	/*
		A query that returns the serial number of the item
	*/
	const unsigned int ItemSet::getSerialNumber() const {
		return m_serialNumber;
	}

	/*
		A query that returns the remaining number of items in the set
	*/
	const unsigned int ItemSet::getQuantity() const {
		return m_quantity;
	}

	/*
		a prefix decrement operator that reduces the number of items in 
		stock by one and increases the serial number by one.
	*/
	ItemSet& ItemSet::operator--() {
		m_quantity--;
		m_serialNumber++;

		return *this;
	}

	/*
		a query that receives a reference to an std::ostream object os and 
		a Boolean full and inserts the data for the current object into stream os. 
		If the Boolean is false the data consists of the name of the items in the set 
		and the next serial number to be assigned. If the Boolean is true, the data 
		consists of the name, serial number quantity in stock and the description of
		the items in the set (as shown above). The field width for the name is just
		large enough to display the largest name. The field width for the serial number 
		is 5 with ‘0’ fill and the field width for the quantity in stock is 3 left-justified. 
		Fields are separated by a single blank character.
	*/
	void ItemSet::display(std::ostream& os, bool full) const {
		size_t fw = mo_utility.getFieldWidth();

		if (full)
			os << std::left << std::setw(fw) << m_name << " [" << std::setw(5) << m_serialNumber << "] Quantity " << std::setw(3) << m_quantity << std::right << " Description: " << m_description << std::endl;
	}

}

