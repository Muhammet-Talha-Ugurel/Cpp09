#include "RPN.hpp"

#include <iostream>

int main( int argc, char **argv ) {
	if (argc == 1) {
		std::cerr << "Usage: " << argv[0] << " [args]" << std::endl;
		return 1;
	}

	RPN rpn = RPN();

	try {
		std::cout << rpn.calculate(argv[1]) << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
