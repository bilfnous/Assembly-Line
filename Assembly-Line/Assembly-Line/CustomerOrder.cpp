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

	size_t CustomerOrder::m_fieldWidth = 0;
	
	CustomerOrder::CustomerOrder() : m_itemInfo{ nullptr }, m_customerName{ "" }, m_productName{ "" }, m_itemsNum{ 0 } {}

	CustomerOrder::CustomerOrder(const std::string& record) : CustomerOrder() {
		Utilities utility;

		size_t delimiter_pos = record.find(utility.getDelimiter());
		m_customerName = record.substr(0, delimiter_pos);

		if (m_fieldWidth < utility.getFieldWidth())
			m_fieldWidth = utility.getFieldWidth();
		
		delimiter_pos++;
		m_productName = utility.extractToken(record, delimiter_pos);

		m_itemsNum = std::count(record.begin(), record.end(), utility.getDelimiter()) - 1;
		m_itemInfo = new ItemInfo[m_itemsNum];

		if (m_itemsNum >= 1) {
			for (size_t i = 0; i < m_itemsNum; i++)
				m_itemInfo[i].s_name = utility.extractToken(record, delimiter_pos);
		}
		else {
			throw "*** No items have been requested to be added. ***";
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) {
		*this = std::move(other);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) {
		if (this != &other) {
			m_customerName = other.m_customerName;
			m_productName = other.m_productName;
			m_itemsNum = other.m_itemsNum;
			m_itemInfo = other.m_itemInfo;
			other.m_itemInfo = { nullptr };
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		delete[] m_itemInfo;
		m_itemInfo = { nullptr };
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (size_t i = 0; i < m_itemsNum; i++) {
			if (item.getName() == m_itemInfo[i].s_name) {
				if (item.getQuantity() == 0)
					os << " Unable to fill " << m_customerName << " [" << m_productName << "][" << m_itemInfo[i].s_name << "][" << m_itemInfo[i].s_serialNumer << "] out of stock" << std::endl;
				else {
					if (m_itemInfo[i].s_filled)
						os << " Unable to fill " << m_customerName << " [" << m_productName << "][" << m_itemInfo[i].s_name << "][" << m_itemInfo[i].s_serialNumer << "] already filled" << std::endl;
					else {
						m_itemInfo[i].s_serialNumer = item.getSerialNumber();
						m_itemInfo[i].s_filled = true;
						item.operator--();
						os << " Filled " << m_customerName << " [" << m_productName << "][" << m_itemInfo[i].s_name << "][" << m_itemInfo[i].s_serialNumer << "]" << std::endl;
					}
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
