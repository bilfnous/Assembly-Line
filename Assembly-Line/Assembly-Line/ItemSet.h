/*
*	Assembly Line Milestone 1
*	ItemSet.h
*	Date 2019-07-05
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include <string>
#include "Utilities.h"

namespace sict {

	class ItemSet {
		
		std::string m_name;
		std::string m_description;
		unsigned int m_serialNumber;
		unsigned int m_quantity;
		Utilities mo_utility;

	public:
		ItemSet(const std::string&);
		ItemSet(ItemSet&&);
		ItemSet(const ItemSet&) = delete;
		ItemSet& operator=(const ItemSet&) = delete;
		ItemSet& operator=(ItemSet&&) = delete;
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full = true) const;
	};

}

#endif
