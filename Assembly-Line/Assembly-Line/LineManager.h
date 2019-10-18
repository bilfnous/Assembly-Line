/*
*	Assembly Line Milestone 3
*	LineManager.h
*	Date 2019-08-02
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

#ifndef SICT_LineManager_H
#define SICT_LineManager_H

#include "CustomerOrder.h"
#include "Station.h"

namespace sict {

	class LineManager {

		std::vector<Station*> m_lineStationAddr;
		std::vector<size_t> m_nextStation;
		std::deque<CustomerOrder> m_ordersToFill; // Customer Orders to be filled
		std::deque<CustomerOrder> m_complete;  // Customer Orders filled
		std::deque<CustomerOrder> m_incomplete; // Customer Orders incomplete due to inventory shortage
		const size_t m_customerOrders;          // number of Customer orders loaded
		size_t m_lastStation;
		const size_t m_startIndex;

	public:
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, const size_t, std::ostream&);
		void display(std::ostream&) const;
		bool run(std::ostream&);
	};
}

#endif
