#include <string>
#include <fstream>
#include <iostream>

// Loads a file and returns its contents
std::string loadFile(std::string fileName) {
	std::fstream ifs(fileName);
	std::string contents(
		(std::istreambuf_iterator<char>(ifs) ),
		(std::istreambuf_iterator<char>())
	);
	
	return contents;
}