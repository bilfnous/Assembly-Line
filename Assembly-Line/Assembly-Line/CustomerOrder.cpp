/*
*	Assembly Line Milestone 2
*	CustomerOrder.cpp
*	Date 2019-07-19
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"

namespace sict {

	unsigned int CustomerOrder::m_fieldWidth{0u};

	CustomerOrder::CustomerOrder(const std::string& record) {
		if (!record.empty()) {
			size_t next_pos = 0;

			m_customerName = mo_utility.extractToken(record, next_pos);

			if (m_fieldWidth < mo_utility.getFieldWidth()) {
				m_fieldWidth = (unsigned int)mo_utility.getFieldWidth();
			}

			if (next_pos != std::string::npos) {
				m_productName = mo_utility.extractToken(record, next_pos);
			}

			// extracts the remainder of the record
			std::string strItems = record.substr(next_pos, record.length() - next_pos);
			m_itemsNum = (unsigned int)(std::count(strItems.begin(), strItems.end(), mo_utility.getDelimiter())) + 1;

			// allocate memory for the item list for this order
			ms_itemList = new ItemInfo * [m_itemsNum];
			// store the item information for this order
			for (unsigned int x = 0; (x < m_itemsNum) && (next_pos != std::string::npos); x++)
				ms_itemList[x] = new ItemInfo(mo_utility.extractToken(record, next_pos));
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
		*this = std::move(other);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
		if (this != &other) {
			if (ms_itemList) {
				for (unsigned int x = 0; x < m_itemsNum; ++x)
					delete ms_itemList[x];
				delete[] ms_itemList;
			}
			m_customerName = other.m_customerName;
			m_productName = other.m_productName;
			m_itemsNum = other.m_itemsNum;
			m_fieldWidth = other.m_fieldWidth;
			ms_itemList = other.ms_itemList;
			other.ms_itemList = nullptr;
			other.m_itemsNum = 0;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		if (ms_itemList) {
			for (unsigned int x = 0; x < m_itemsNum; ++x)
				delete ms_itemList[x];
			delete[] ms_itemList;
		}
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		// Loop through the itemlist information and find the corresponding item
		for (unsigned int i = 0; i < m_itemsNum; i++) {
			if (ms_itemList[i]->s_itemName == item.getName()) {
				if ((item.getQuantity() > 0) && (!ms_itemList[i]->s_filled)) {
					ms_itemList[i]->s_serialNumer = item.getSerialNumber();
					ms_itemList[i]->s_filled = true;
					os << " Filled " << m_customerName << " [" << m_productName << "][" << ms_itemList[i]->s_itemName << "]" <<
						"[" << ms_itemList[i]->s_serialNumer << "]" << std::endl;
					--item;
				}
				else if (ms_itemList[i]->s_filled) {
					os << " Unable to fill " << m_customerName << " [" << m_productName << "][" << ms_itemList[i]->s_itemName << "]" <<
						"[" << ms_itemList[i]->s_serialNumer << "] already filled" << std::endl;
				}
				else {
					os << " Unable to fill " << m_customerName << " [" << m_productName << "][" << ms_itemList[i]->s_itemName << "]" <<
						"[" << ms_itemList[i]->s_serialNumer << "] out of stock" << std::endl;
				}
			}
		}
	}

	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < m_itemsNum; ++i)
			if (!m_itemInfo[i].s_filled)
				return false;
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_itemsNum; i++) {
			if (m_itemInfo[i].s_name == itemName) {
				if (!m_itemInfo->s_filled)
					return false;
			}
		}
		return true;
	}

	std::string CustomerOrder::getNameProduct() const {
		return std::string(m_customerName) + "[" + std::string(m_productName) + "]";
	}

	void CustomerOrder::display(std::ostream & os, bool showDetail) const {
		os << std::left << std::setw(m_fieldWidth) << m_customerName << " [" << m_productName << "]" << std::endl;
		if (!showDetail) {

			for (size_t i = 0; i < m_itemsNum; i++) {
				os << std::setfill(' ') << std::setw(m_fieldWidth + 1) << "    " << std::right << m_itemInfo[i].s_name << std::endl;
			}
		}
	}

}
