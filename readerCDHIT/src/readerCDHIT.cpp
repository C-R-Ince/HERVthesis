//============================================================================
// Name        : readerCDHIT.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>


using namespace std;

string clusterNumber;


int main() {

	//cout << "/Users/dkz974/Documents/Sub_2011/Env/Sub_2011_Env_8.clstr" << endl;

	string fileLocation;
	ifstream clusterFile;

	cout << "Enter clstr file location" << endl;
	getline(cin, fileLocation);

	clusterFile.open(fileLocation);
	if (clusterFile.good()) {
		cout << "File found!\n" << endl;
	} else {
		cout << "Error! File not found! \nPlease enter a file path: " << endl;
		getline(cin, fileLocation);
	}

	int fileLength = fileLocation.length();
	fileLength = fileLength - 6;
	fileLocation.erase(fileLength);

	string newFileLocation = fileLocation + "_clstr.csv";

	ofstream newClusterFile;
	newClusterFile.open(newFileLocation);
	newClusterFile << "Gene" << ", " << "Cluster" << ", " << "Number within Cluster" << ", " << "Nucleotides"
			<< ", " << "Object" << ", "
					"at" << ", " << "Stat" << endl; //Header row

	cout << "Enter gene: " << endl;
	string gene;
	cin >> gene;

	string line;

	while (getline(clusterFile, line)) {
		string lineChar;
		lineChar = line.at(0);

		if (lineChar == ">") {
			//clstrNumber(line);
			clusterNumber = line;
			clusterNumber.erase(0, 1); //removes ">"

		} if (lineChar == "0" || lineChar == "1" || lineChar == "2"
				|| lineChar == "3" || lineChar == "4" || lineChar == "5"
				|| lineChar == "6" || lineChar == "7" || lineChar == "8"
				|| lineChar == "9") {
			line.erase(remove(line.begin(), line.end(), ','), line.end());
		    replace(line.begin(), line.end(), '	', ',');
		    replace(line.begin(), line.end(), ' ', ',');

			newClusterFile << gene << ", " << clusterNumber << ", " << line << endl;

	}
	}

		string outputFile = "open " + newFileLocation;
		const char *openFile = outputFile.c_str();
		system(openFile);

	return 0;
}
