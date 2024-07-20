#pragma once
#include <iostream>

class IncompatibleDimException : public std::exception
{
private:
	std::string m_error;

public:
	IncompatibleDimException() : m_error("Incompatible dim exception.")
	{}

	const char* what() const throw() { return m_error.c_str(); }
};