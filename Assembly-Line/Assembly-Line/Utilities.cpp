/*
*	Assembly Line Milestone 1
*	Utilities.cpp
*	Date 2019-07-05
*	Auther B. Alfanous
*	b.alfanous@outlook.com
*/

/*
	The Utilities module is a support module that contains the functionality that is common
	across the system. All objects in the system parse string data in the same way,
	use the same delimiter and report data fields in tabular format.
*/

#include <iostream>
#include <string>
#include "Utilities.h"

namespace sict {

	char Utilities::m_delimiter = '\0';
	size_t Utilities::m_fieldWidth = { 0 };
	/*
		A default constructor that places the object in a safe empty state and initializes 
		its field width to a size that is less than the possible size of any token.
	*/
	Utilities::Utilities() {}

	/*
		- A modifier that receives a reference to an unmodifiable string str and a reference to a 
		position next_pos in that string. This function extracts the next token in the string 
		starting at the position next_pos, and ending immediately before the delimiter character. 
		- This function compares the size of the extracted token to the field width currently stored 
		in the object and if the size of the token is greater than that width increases that width. 
		- This function returns in next_pos the position of the next token in the string if one exists. 
		- If not, this function returns the position that is beyond the end of the string. 
		- This function reports an exception if one delimiter follows another without any token between them.
	*/
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string token = str.substr(next_pos);;
		size_t pos = token.find(m_delimiter);
		if (pos != std::string::npos) {
			token = token.substr(0, pos);
			next_pos += pos + 1;
		}
					
		return token;
	}

	/*
		A query that returns the delimiter character
	*/
	const char Utilities::getDelimiter() const {
		return m_delimiter;
	}

	/*
		A query that returns the field width for the current object
	*/
	size_t Utilities::getFieldWidth() const {
		return m_fieldWidth;
	}

	/*
		A modifier that set the delimiter character for all object of this class
	*/
	void Utilities::setDelimiter(const char d) {
		m_delimiter = d;
	}

	/*
		A modifier that set the field width for the current object
	*/
	void Utilities::setFieldWidth(size_t width) {
		m_fieldWidth = width;
	}

}
