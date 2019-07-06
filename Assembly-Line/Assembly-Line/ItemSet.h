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

namespace sict {

	class ItemSet {

	public:
		ItemSet(const std::string*);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getSerialNumber() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};

}

#endif
