#include <iostream>

// this program takes in a decimal number as input and outputs the
// binary representation of that number.
// In example, input: 2, output: 10

void printBinary(int decimal) {
	if (decimal == 1) {
		std::cout << "1";
	} else if (decimal == 0) {
		std::cout << "0";
	} else {
		printBinary(decimal/2);
		if (decimal%2 == 0) {
			std::cout << "0";
		} else {
			std::cout << "1";
		}
	}
}

int main() {
	int input;
	std::cout << "Decimal number: ";
	std::cin >> input;
	std::cout << std::endl << "Binary number: ";
	printBinary(input);
	std::cout << std::endl;
	return 0;
}
