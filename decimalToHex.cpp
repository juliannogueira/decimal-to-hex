/**************************************************************************************************
 * * Program: decimalToHex.cpp
 * * Author: Julian Torres
 * * Date: 04 January 2020
 * * Description: This program is used to convert an unsigned integer, represented in decimal
 * *		  notation, to hexidecimal notation.
 * ************************************************************************************************/

#include <iostream>

void decimalToHex(int decimal);

void decimalToHex(int decimal){
	char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
			'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	int temp = decimal,
	    length;

	// Calculate the number of digits in the integer
	if(temp == 0){ length = 0; }
	else{
		for(length = 0; temp > 0; length++){
			temp = temp / 10;
		}
	}

	std::cout << std::endl << "Number of digits: " << length;
}

int main(){
	int decimal;

	std::cout << std::endl << "Enter an integer: ";
	std::cin >> decimal;

	decimalToHex(decimal);

	return 0;
}

