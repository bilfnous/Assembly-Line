/*
*	Assembly Line Milestone 3
*	Station.h
*	Date 2019-08-02
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <queue>
#include <iostream>
#include <string>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {

	class Station {
		
		std::deque<CustomerOrder> m_stationCustomerOrders; // orders currently at this Station
		ItemSet mo_stationInventory; // item stocked at this Station

	public:
		Station(const std::string&);
		Station(const Station&) = delete;
		Station& operator=(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(Station&&) = delete;

		void display(std::ostream&) const;
		void fill(std::ostream&);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
	};

}

#endif
