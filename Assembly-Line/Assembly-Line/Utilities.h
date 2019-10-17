/*
*	Assembly Line Milestone 1
*	Utilities.h
*	Date 2019-07-05
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

namespace sict {
	
	class Utilities {
		size_t m_fieldWidth; // maximum field width needed 
		static char m_delimiter; // field delimiter character	

	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		static void setDelimiter(const char d);
		const char getDelimiter() const;
		void setFieldWidth(size_t);
		size_t getFieldWidth() const;
	};
}

#endif
