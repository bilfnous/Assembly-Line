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
#include "ItemSet.h"

namespace sict {

	/*
		A constructor that receives a reference to an unmodifiable string, 
		extracts 4 tokens from the string, populates the object with those tokens 
		and determines the field width to be used in displaying data for all objects of the class.
	*/
	ItemSet::ItemSet(const std::string*) {}

	/*
		A query that returns a reference to the name of the item
	*/
	const std::string& ItemSet::getName() const {}

	/*
		A query that returns the serial number of the item
	*/
	const unsigned int ItemSet::getSerialNumber() const {}

	/*
		A query that returns the remaining number of items in the set
	*/
	const unsigned int ItemSet::getSerialNumber() const {}

	/*
		a prefix decrement operator that reduces the number of items in 
		stock by one and increases the serial number by one.
	*/
	ItemSet& ItemSet::operator--() {}

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
	void ItemSet::display(std::ostream& os, bool full) const {}

}

