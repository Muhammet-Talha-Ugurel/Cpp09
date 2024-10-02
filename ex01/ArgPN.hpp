#ifndef ARGPN_HPP
#define ARGPN_HPP

#include <string>
#pragma once

#define ARGPN_NUMBER    0
#define ARGPN_OPERAND 1

class ArgPN {
  private:
    int _type;
    unsigned int _value;

  public:
    ArgPN();
    ~ArgPN();
    ArgPN( const ArgPN &other );
    ArgPN &operator=( const ArgPN &other );
    ArgPN( const std::string &str );
    ArgPN( const char *str );
    ArgPN( int value );

    bool isNumber() const;
    bool isOperand() const;

    int getValue() const;
};

#endif
