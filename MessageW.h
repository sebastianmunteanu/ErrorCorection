#pragma once
#include <random>

int generate_random(int mLenght) {
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, mLenght);
	return distr(gen);
}

void corrup_message(std::string& message) {
	int placeToCorrupt = generate_random(message.length() - 1);
	message.at(placeToCorrupt) == '1' ?
		message.at(placeToCorrupt) = '0' :
		message.at(placeToCorrupt) = '1';
}

void from_message_to_matrix(const std::string& message, std::vector <std::vector <char>>& dValue, const int & numberOfLines) {
	int contor{ 0 };
	for (int i = 0; i < numberOfLines; i++) {
		std::vector <char> vInt;
		for (int j = 0; j < 7; j++) {
			vInt.push_back(message.at(contor++));
		}
		dValue.push_back(vInt);
	}
}

void lineError(const std::vector <std::vector <char>>& mValue, const std::vector <std::vector <char>>& dValue, int& lineE) {
	for (int i{ 0 }; i < mValue.size() - 1; i++) {
		if (mValue[i][7] != dValue[i][7]) {
			lineE = i;
			//std::cout << "Line with error is: " << lineE << std::endl;
			return;
		}
	}
}

void columnError(const std::vector <std::vector <char>>& mValue, const std::vector <std::vector <char>>& dValue, int& columnE) {
	for (int i{ 0 }; i < 7; i++) {
		if (mValue[mValue.size()-1][i] != dValue[mValue.size() - 1][i]) {
			columnE = i;
			//std::cout << "Column with error is: " << columnE << std::endl;
			return;
		}
	}
}

void identify_error(const std::vector <std::vector <char>>& mValue, std::vector <std::vector <char>>& dValue) {
	int lineE;
	int columnE;
	lineError(mValue, dValue, lineE);
	columnError(mValue, dValue, columnE);
	dValue[lineE][columnE] = '*';
}