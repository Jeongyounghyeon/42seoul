#include <iostream>
#include <fstream>
#include <cstdlib>

#define DATA_PATH "data.csv"

#include "BitcoinExchange.hpp"

void vaildArgument(int argc);
void openFile(char* filePath, std::ifstream& ifs);

int main(int argc, char* argv[]) {
	std::ifstream data;
	std::ifstream input;

	try {
		vaildArgument(argc);
		openFile((char*)DATA_PATH, data);
		openFile(argv[1], input);
		BitcoinExchange::exchange(data, input);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(1);
	}

	return 0;
}

void vaildArgument(int argc) {
	if (argc != 2)
		throw std::runtime_error("Please input one argument");
}

void openFile(char* filePath, std::ifstream& ifs) {
	ifs.open(filePath, std::ifstream::in);

	if (!ifs.is_open())
		throw std::runtime_error("Could not open file");
}
