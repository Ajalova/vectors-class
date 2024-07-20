#pragma once
#include <iostream>

class OutOfRangeException : public std::exception
{
	private:
		std::string m_error;

	public:
		OutOfRangeException(): m_error("Out of range exception.")
		{}

		const char* what() const throw() { return m_error.c_str(); }
	};