/*
*	Assembly Line Milestone 3
*	Station.cpp
*	Date 2019-08-02
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/


#include "Station.h"

namespace sict {

	// constructor passes record to item subobject
	Station::Station(const std::string& string) : mo_stationInventory(string) {}

	void Station::display(std::ostream& os) const {
		mo_stationInventory.display(os);
	}

	void Station::fill(std::ostream& os) {
		if (!m_stationCustomerOrders.empty()) {
			auto itr = m_stationCustomerOrders.begin();
			if (!(*itr).isFilled()) {
				(*itr).fillItem(mo_stationInventory, os);
			}
		}
	}

	const std::string& Station::getName() const {
		return mo_stationInventory.getName();
	}

	bool Station::hasAnOrderToRelease() const {
		bool hasOrder = false;
		if (!m_stationCustomerOrders.empty()) {
			// order at the start of the queue
			auto it = m_stationCustomerOrders.begin();
			return (*it).isItemFilled(mo_stationInventory.getName()) || mo_stationInventory.getQuantity() == 0;
		}
		return hasOrder;
	}

	Station& Station::operator--() {
		--mo_stationInventory;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		m_stationCustomerOrders.push_back(std::move(order));
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		bool filled = false;
		if (!m_stationCustomerOrders.empty()) {
			auto it = m_stationCustomerOrders.begin();
			bool isFilled = (*it).isFilled();
			CustomerOrder order = std::move((*it));
			m_stationCustomerOrders.pop_front();
			ready = std::move(order);
		}
		return filled;
	}

	void Station::validate(std::ostream & os) const {
		os << " getName(): " << mo_stationInventory.getName() << std::endl;
		os << " getSerialNumber(): " << mo_stationInventory.getSerialNumber() << std::endl;
		os << " getQuantity(): " << mo_stationInventory.getQuantity() << std::endl;
	}

}