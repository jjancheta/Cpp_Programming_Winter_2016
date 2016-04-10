// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: ErrorMessage.h
// Milestone: 2


#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>

namespace sict{
	class ErrorMessage{
		char* message_;
	public:
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		virtual ~ErrorMessage();
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);		
		void clear();
		bool isClear() const;
		void message(const char* value);
		const char* message() const;
		std::ostream& write(std::ostream& ostr)const;
	};

	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& out);

}
#endif

