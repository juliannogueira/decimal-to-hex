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

	int temp = decimal,
	    length,
	    currentRemainder,
	    currentValue,
	    previousValue;

	// The values stored in this vector will be converted to hex symbols
	std::vector <int> remainders;

	// Calculate the number of digits in the integer
	if(temp == 0){ length = 0; }
	else{
		for(length = 0; temp > 0; length++){
			temp = temp / 10;
		}
	}

	std::cout << std::endl << "Number of digits: " << length;

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

	for(int i = 0; i < remainders.size(); i++){
		std::cout << std::endl << remainders[i];
	}
}

int main(){
	int decimal;

	std::cout << std::endl << "Enter an integer: ";
	std::cin >> decimal;

	decimalToHex(decimal);
	
	return 0;
}

