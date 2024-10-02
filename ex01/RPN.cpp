#include "RPN.hpp"

#include "ArgPN.hpp"

#include <sstream>
#include <stack>

RPN::RPN() {
}

RPN::RPN( const RPN &other ) {
  *this = other;
}

RPN::~RPN() {
}

RPN &RPN::operator=( const RPN &other ) {
  ( void ) other;
  return *this;
}

int RPN::calculate( const std::string &input ) const {
  std::stack<ArgPN>  stack;
  std::istringstream iss( input );

  std::string        token;

  while ( std::getline( iss, token, ' ' ) ) {
    ArgPN arg( token );

    if ( arg.isNumber() ) {
      stack.push( arg );
    } else if ( arg.isOperand() ) {
      if ( stack.size() < 2 ) {
        throw std::exception();
      }

      ArgPN a = stack.top();
      stack.pop();
      ArgPN b = stack.top();
      stack.pop();

      if ( arg.getValue() == '+' ) {
        stack.push( ArgPN( b.getValue() + a.getValue() ) );
      } else if ( arg.getValue() == '-' ) {
        stack.push( ArgPN( b.getValue() - a.getValue() ) );
      } else if ( arg.getValue() == '*' ) {
        stack.push( ArgPN( b.getValue() * a.getValue() ) );
      } else if ( arg.getValue() == '/' ) {
        stack.push( ArgPN( b.getValue() / a.getValue() ) );
      }
    }
  }
  if ( stack.size() != 1 ) {
    throw std::exception();
  }
  return stack.top().getValue();
}
