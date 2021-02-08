#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

inline void readfile(string file_name, string file_extention) {
	char data[100];
	string filename(file_name + "." + file_extention);
	ifstream file;
	file.open(filename);
	file >> data;
	cout << data;
}

inline void writefile(string file_name, string extention, string contents) {
	ofstream file(file_name + "." + extention);
	file << contents;
	file.close();
}
