/*
*	Assembly Line Milestone 2
*	CustomerOrder.h
*	Date 2019-07-19
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDER_H

#include <string>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	
	class CustomerOrder {
	
		/*
			Nested object that holds information about an Item
		*/
		struct ItemInfo {
			std::string s_itemName;
			int s_serialNumer{0u};
			bool s_filled{false};
			ItemInfo(const std::string& src) : s_itemName(src) {};
		}** ms_itemList{ nullptr };

		std::string m_customerName = "";
		std::string m_productName = "";
		unsigned int m_itemsNum{0u};
		static unsigned int m_fieldWidth;
		Utilities mo_utility;

	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
		~CustomerOrder();
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
	};
}

#endif // SICT_CUSTOMERORDER_H
