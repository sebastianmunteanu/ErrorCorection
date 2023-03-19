#pragma once

#include "XoR.h";

void extra_column_and_line(std::vector <std::vector <char>>& mValue) {
	//extra linie
	std::vector <char> extraLine;
	for (int i = 0; i < 8; i++) {
		extraLine.push_back(NULL);
	}
	mValue.push_back(extraLine);

	//extra coloana
	for (int i = 0; i < mValue.size() - 1; i++) {
		mValue.at(i).push_back(NULL);
	}
}

void print(const std::vector <std::vector <char>>& mValue) {
	for (auto x : mValue) {
		for (char p : x) {
			std::cout << p;
		}
		std::cout << std::endl;
	}
}

void print_with_lines(const std::vector <std::vector <char>>& mValue) {
	for (int i = 0; i < mValue.size(); i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 7) {
				std::cout << "|";
			}
			std::cout << mValue[i][j];
		}
		if (i == mValue.size() - 2) {
			std::cout << std::endl;
			for (int k = 0; k < 9; k++) {
				std::cout << "-";
			}
		}
		std::cout << std::endl;
	}
}

void XoR_line(std::vector <std::vector <char>>& mValue) {
	int i = 0;
	XoR calculateValue = XoR();
	for (auto& x : mValue) {
		if (i == 3) {
			return;
		}
		x.at(7) = calculateValue.stringValueCalc(x);
		i++;
	}
}

void XoR_column(std::vector <std::vector <char>>& mValue) {
	XoR Xor = XoR();
	char result = NULL;
	for (int i = 0; i < 7; i++) {
		result = mValue[0][i];
		for (int j = 1; j < mValue.size() - 1; j++) {
			result = Xor.twoValuesCalc(result, mValue[j][i]);
		}
		mValue[mValue.size() - 1][i] = result;
	}
}

void XoR_corener_bit(std::vector <std::vector <char>>& mValue) {
	XoR Xor = XoR();
	char columnValue = mValue[0][7];
	char lineValue = mValue[mValue.size()-1][0];
	for (int i = 1; i < mValue.size() - 1; i++) {
		columnValue = Xor.twoValuesCalc(columnValue, mValue[i][7]);
	}
	for (int j = 1; j < 7; j++) {
		lineValue = Xor.twoValuesCalc(lineValue, mValue[mValue.size() - 1][j]);
	}
	try {
		if (columnValue != lineValue) {
			std::string errorMessage = "XoR calculation corner bit error";
			throw errorMessage;
		}
		else {
			mValue[mValue.size() - 1][7] = columnValue;
		}
	}
	catch (std::string e) {
		std::cout << e << std::endl;
	}
}

void clacul_XoR(std::vector <std::vector <char>>& mValue) {
	XoR_line(mValue);
	XoR_column(mValue);
	XoR_corener_bit(mValue);
}

