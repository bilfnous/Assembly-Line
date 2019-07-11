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
		static size_t m_fieldWidth; 
		static char m_delimiter; //???	

	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};

}

#endif
