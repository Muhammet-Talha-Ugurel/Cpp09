#include "ArgPN.hpp"
#include <exception>

ArgPN::ArgPN() {
	throw std::exception();
}

ArgPN::~ArgPN() {
}

ArgPN::ArgPN( const ArgPN &other ) {
	*this = other;
}

ArgPN &ArgPN::operator=( const ArgPN &other ) {
	_type = other._type;
	_value = other._value;
	return *this;
}

ArgPN::ArgPN( int value ) {
	_type = ARGPN_NUMBER;
	_value = value;
}

ArgPN::ArgPN( const std::string &str ) {
	if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/') {
		_type = ARGPN_OPERAND;
		_value = str[0];
	} else if (str[0] >= '0' && str[0] <= '9') {
		_type = ARGPN_NUMBER;
		_value = std::stoi(str);
	} else {
		throw std::exception();
	}
}

ArgPN::ArgPN( const char *str ) {
	*this = ArgPN(std::string(str));
}

bool ArgPN::isNumber() const {
	return _type == ARGPN_NUMBER;
}

bool ArgPN::isOperand() const {
	return _type == ARGPN_OPERAND;
}

int ArgPN::getValue() const {
	return _value;
}
