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

namespace sict {
	
	class CustomerOrder {
	
		/*
			Nested object that holds information about an Item
		*/
		struct ItemInfo {
			std::string s_name;
			int s_serialNumer;
			bool s_filled;
			ItemInfo() : s_name{ "" }, s_serialNumer{ 0 }, s_filled{false} {}
		};

		ItemInfo* m_itemInfo;
		std::string m_customerName;
		std::string m_productName;
		size_t m_itemsNum;
		static size_t m_fieldWidth;

	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&);
		CustomerOrder& operator=(CustomerOrder&&);
		~CustomerOrder();
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
	};
}

#endif // SICT_CUSTOMERORDER_H
