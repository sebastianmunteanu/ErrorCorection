#pragma once

#include <fstream>

bool check_multiple_of_seven(int& numberOfLines, std::string& initialMessage) {
	std::ifstream date;
	std::string input;
	date.open("Text.txt");
	try {
		std::string message{ "" };
		if (date.is_open()) {
			date >> input;
		} else { 
			message = "Error to open file";
			throw message;
		}
		if (input.length() % 7 != 0) {
			message = "Invalid input. String isn't multiple of 7";
			throw message;
		}
		else {
			numberOfLines = input.length() / 7;
			initialMessage = input;
		}
	}
	catch (std::string message) {
		std::cout << message << std::endl;
		date.close();
		return false;
	}
	date.close();
	return true;
}

bool read_from_file(std::vector <std::vector <char>>& mValue, std::string& initialMessage, int& numberOfLines) {
	std::ifstream date;
	date.open("Text.txt");
	if (date.is_open()) {
		//verificare fisier ok si multiplu de 7
		//citire numar de linii si input msg
		if (!check_multiple_of_seven(numberOfLines, initialMessage)) {
			return false;
		}
		for (int i = 0; i < numberOfLines; i++) {
			std::vector <char> vInt;
			for (int j = 0; j < 7; j++) {
				char value;
				date >> value;
				if (value != '0' && value != '1') {
					std::cout << "Invalid input. String with invalid char.\n";
					mValue.clear();
					date.close();
					return false;
				}
				else {
					vInt.push_back(value);
				}
			}
			mValue.push_back(vInt);
		}
		date.close();
	}
	else {
		std::cout << "Error to open file";
		return false;
	}
	return true;
}