/*
*	Assembly Line Milestone 3
*	LineManager.cpp
*	Date 2019-08-02
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

#include "LineManager.h"

namespace sict {

	LineManager::LineManager(std::vector<Station*>& stationAddresses, std::vector<size_t>& indexNextStation, std::vector<CustomerOrder>& customerOrders, size_t indexStartingStation, std::ostream& os)
		: m_stationAddresses{ stationAddresses }, m_indexStartingStation{ indexStartingStation } {

		for (auto& customerOrder : customerOrders)
			m_ordersToFill.push_back(std::move(customerOrder));

		m_indexLastStation = createAssemblyOrder(indexNextStation, indexStartingStation);

		m_indexNextStation = indexNextStation;
		m_orderSize = m_ordersToFill.size();
	}

	size_t LineManager::createAssemblyOrder(std::vector<size_t>& indexNextStation, size_t indexStartingStation) {
		m_stationOrder.push_back(indexStartingStation);

		for (size_t i = 0; i < indexNextStation.size(); ++i) {
			m_stationOrder.push_back(indexNextStation[indexStartingStation]);
			indexStartingStation = indexNextStation[indexStartingStation];
		}

		return m_stationOrder.back();
	}

	void LineManager::display(std::ostream& os) const {
		os << "COMPLETED ORDERS" << std::endl;
		for (auto& i : m_complete)
			i.display(os, true);
		os << std::endl;

		os << "INCOMPLETE ORDERS" << std::endl;
		for (auto& i : m_incomplete)
			i.display(os, true);
	}

	bool LineManager::run(std::ostream& os) {
		// if there is an incoming CustomerOrder add it to Station [startIndex]
		if (!m_ordersToFill.empty()) {
			*m_lineStationAddr[m_startIndex] += std::move(m_ordersToFill.back());
			m_ordersToFill.pop_back();
		}

		// fill one customer order at each station
		for (size_t x = 0; x < m_lineStationAddr.size(); x++) {
			m_lineStationAddr[x]->fill(os);
		}

		// move customer orders forward
		for (size_t i = 0; i < m_lineStationAddr.size(); ++i) {
			if (m_lineStationAddr[i]->hasAnOrderToRelease()) {
				CustomerOrder order;
				bool complete = m_lineStationAddr[i]->pop(order);
				os << " --> " << order.getNameProduct() << " moved from " << m_lineStationAddr[i]->getName() << " to ";
				if (i != m_lastStation) {
					os << m_lineStationAddr[m_nextStation[i]]->getName() << std::endl;
					*m_lineStationAddr[m_nextStation[i]] += std::move(order);
				}
				else if (complete) {
					os << "Completed Set" << std::endl;
					m_complete.push_back(std::move(order));
				}
				else {
					os << "Incomplete Set" << std::endl;
					m_incomplete.push_back(std::move(order));
				}
			}
		}

		return (m_complete.size() + m_incomplete.size()) == m_customerOrders;
	}

}