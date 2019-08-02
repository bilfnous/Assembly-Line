/*
*	Assembly Line Milestone 3
*	Station.cpp
*	Date 2019-08-02
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/


#include "Station.h"

namespace sict {

	Station::Station(const std::string& string) : m_stationInventory(string) {
		m_stationName =  m_stationInventory.getName();
	}

	void Station::display(std::ostream& os) const {
		m_stationInventory.display(os);
	}

	void Station::fill(std::ostream& os) {
		if (!m_stationCustomerOrders.empty())
			m_stationCustomerOrders.front().fillItem(m_stationInventory, os);
	}
	
	const std::string& Station::getName() const {
		return m_stationInventory.getName();
	}

	bool Station::hasAnOrderToRelease() const {
		bool hasOrder = false;
		if (!m_stationCustomerOrders.empty()) {
			if (!m_stationInventory.getQuantity())
				hasOrder = true;
			else
				hasOrder = m_stationCustomerOrders.front().isItemFilled(m_stationName);
		}
		return hasOrder;
	}

	Station& Station::operator--() {
		--m_stationInventory;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		m_stationCustomerOrders.push_back(std::move(order));
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		bool filled = false;
		if (!m_stationCustomerOrders.empty()) {
			filled = m_stationCustomerOrders.front().isItemFilled(m_stationName);
			ready = std::move(m_stationCustomerOrders.front());
			m_stationCustomerOrders.erase(m_stationCustomerOrders.begin());
		}
		return filled;
	}

	void Station::validate(std::ostream & os) const {
		os << " getName(): " << m_stationInventory.getName() << std::endl;
		os << " getSerialNumber(): " << m_stationInventory.getSerialNumber() << std::endl;
		os << " getQuantity(): " << m_stationInventory.getQuantity() << std::endl;
	}

}