/**************************************************************************************************
 * * Program: decimalToHex.cpp
 * * Author: Julian Torres
 * * Date: 04 January 2020
 * * Description: This program is used to convert an unsigned integer, represented in decimal
 * *		  notation, to hexadecimal notation.
 * ************************************************************************************************/

#include <iostream>
#include <vector>

void decimalToHex(int decimal);

void decimalToHex(int decimal){
	char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
			'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	char hexValue;

	int temp = decimal,
	    numberOfDigits,
	    currentRemainder,
	    currentValue,
	    previousValue;

	// The values stored in this vector will be converted to hex symbols
	std::vector <int> remainders;

	// This vector contains the hexadecimal converted remainder values
	std::vector <char> hexValues;

	// Calculate the number of digits in the integer
	if(temp == 0){ numberOfDigits = 0; }

	// This does not affect the conversion, but I initially thought it would be necessary to
	// capture the number of digits. However, I will keep this in the program in case a use is
	// developed later.
	else{
		for(numberOfDigits = 0; temp > 0; numberOfDigits++){
			temp = temp / 10;
		}
	}

	previousValue = decimal;
	currentValue = decimal / 16;
	currentRemainder = previousValue % 16;

	remainders.push_back(currentRemainder);

	// Continue operations until integer division reaches a floor of 0, indicating the last
	// remainder is to be calculated.
	while(currentValue != 0){
		previousValue = currentValue;
		currentValue = previousValue / 16;
		currentRemainder = previousValue % 16;

		remainders.push_back(currentRemainder);
	}

	for(int index = 0; index < remainders.size(); index++){
		hexValue = hex[remainders[index]];
		hexValues.push_back(hexValue);
	}

	// Display the hexadecimal converted value
	std::cout << std::endl << "Passed decimal value: " << decimal;
	std::cout << std::endl << "Hexadecimal converted value: ";

	for(int index = hexValues.size() - 1; index >= 0; index--){
		std::cout << hexValues[index];
	}

	std::cout << std::endl;
}

int main(){
	int decimal;

	std::cout << std::endl << "Enter an integer: ";
	std::cin >> decimal;

	decimalToHex(decimal);
	
	return 0;
}

