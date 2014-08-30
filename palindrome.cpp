#include <iostream>
#include <math.h>

// function to check whether the input string is a palindrome or not

bool isPalindrome(std::string input) {
	for (int i = 0; i < floor(input.length() / 2); i++) {
		if (input[i] != input[input.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	std::string input;
	std::cin >> input;

	if (isPalindrome(input)) {
		std::cout << input << " is a palindrome." << std::endl;
	} else {
		std::cout << input << " is not a palindrome." << std::endl;
	}

	return 0;
}
