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

	// all ItemSet objects have common field widths
	// name field width is that of larger name
	unsigned int ItemSet::m_fieldwidth{0u};
	const unsigned int CODE_WIDTH = 5;
	const unsigned int QUAN_WIDTH = 3;

	/*
		A constructor that receives a reference to an unmodifiable string, 
		extracts 4 tokens from the string, populates the object with those tokens 
		and determines the field width to be used in displaying data for all objects of the class.
	*/
	ItemSet::ItemSet(const std::string& record) {
		size_t next_pos = 0;

		if (!record.empty()) {
			m_name = mo_utility.extractToken(record, next_pos);

			if (m_fieldwidth < mo_utility.getFieldWidth()) {
				m_fieldwidth = (unsigned int)mo_utility.getFieldWidth();
			}

			if (next_pos != std::string::npos) {
				std::string tmp = mo_utility.extractToken(record, next_pos);
				m_serialNumber = atoi(tmp.c_str());
			}

			if (next_pos != std::string::npos) {
				std::string tmp = mo_utility.extractToken(record, next_pos);
				m_quantity = atoi(tmp.c_str());
			}

			if (next_pos != std::string::npos) {
				m_description = mo_utility.extractToken(record, next_pos);
			}
		}
	}

	
	ItemSet::ItemSet(ItemSet && other) noexcept {
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
		if (m_quantity > 0) {
			m_quantity--;
			m_serialNumber++;
		}
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
		os << std::setw(m_fieldwidth) << std::setfill(' ') << std::left << m_name
			<< " "
			<< "[" << std::setw(CODE_WIDTH) << std::setfill('0') << std::right << m_serialNumber << "]";

		if (full) {
			os << " " << "Quantity " << std::setw(QUAN_WIDTH) << std::setfill(' ') << std::left << m_quantity
				<< " Description: " << m_description;
		}

		os << std::endl;
	}

}

