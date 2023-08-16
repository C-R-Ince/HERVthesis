//============================================================================
// Name        : TmCalcMulti.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

void fileInput(ifstream &fileCSV) {
	string fileLocation;
	do {
		cout << "Enter file location:" << endl;
		cin >> fileLocation;
		cout << endl;
		fileCSV.open(fileLocation.c_str());
		if (fileCSV.fail()) {
			cout << "Error, please enter a valid file path!" << endl;
			continue;
		} break;
	} while (true);
	cout << "File found!\n";
	cout << " " << endl;
}

string tmCalc(string primer) {
	char G = 'G';
	char C = 'C';

	int Gcount = 0;
	for (int i = 0; (i = primer.find(G, i)) != std::string::npos; i++) {
		Gcount++;
	}

	int Ccount = 0;
	for (int i = 0; (i = primer.find(C, i)) != std::string::npos; i++) {
		Ccount++;
	}

	float GCcount = Gcount + Ccount;

	float Totalbp = primer.length();

	float ATcount = Totalbp - GCcount;

	float percentGC = GCcount / Totalbp * 100;


	if (Totalbp < 14) {
		float tmGC = 4 * GCcount;
		float tmAT = 2 * ATcount;
		float finalTm = tmGC + tmAT;

		ostringstream primerDet;
		primerDet << "GC% " << percentGC << ", Tbp: " << Totalbp << ", Tm: " << finalTm << endl;

		string primerDetails = primerDet.str();
		return primerDetails;

	} else {
		float finalTm = 69.3 + (0.41 * percentGC) - (650 / Totalbp);
		ostringstream primerDet;
		//primerDet << percentGC << ", " << Totalbp << ", " << finalTm;
		primerDet << finalTm;
		string primerDetails = primerDet.str();
		return primerDetails;
	}
}

int main() {
	cout << "----------------------\n ";
	ifstream primerCSV;

	fileInput(primerCSV);


	int rowCount = 0;
	string line;
	int rowIdx = 0;
	//int colNum = 7;


	while (getline(primerCSV, line)) {
		rowCount++;
	}

	vector<string> data[rowCount];

	primerCSV.clear();
	primerCSV.seekg(primerCSV.beg);

	while (getline(primerCSV, line)) {
		line.erase(remove(line.begin(), line.end(), '\"'), line.end());
		stringstream ssin(line);
		string value;
		while (getline(ssin, value, ',')) {  //for every value in that stream (ie: every cell on that row)
			data[rowIdx].push_back(value); //add that value at the end of the current row in our table
		}
		rowIdx++;   //increment row number before reading in next line
	}
	primerCSV.close();

	//Now you can choose to access the data however you like.
	//If you want to printout only column 7...

	int colNum = 5;  //set this number to the column you want to printout
	int colNum2 = 7;
	int rowNumber = 0;

	for (int row = 0; row < rowCount; row++) {

		if(row == 0){
			//cout << "╒═════════════════════════════════════════════════════════════╕" << endl;
			cout << "  " << data[row][colNum] << "\t    ";
			cout << "  " << data[row][colNum2] << "\t\t\t   ";
			cout << "Primer Tm" << endl;
			//cout << "---------------------------------------------------------" << endl;
			cout << "╘═════════════════════════════════════════════════════════════╛" << endl;
			//cout << "▂ ▃ ▄ ▅ ▆ ▇ █ █ ▇ ▆ ▅ ▄ ▃ ▂▂ ▃ ▄ ▅ ▆ ▇ █ █ ▇ ▆ ▅ ▄ ▃ ▂" << endl;
		}
		if(row > 0){
			cout << "  " << data[row][colNum] << "\t\t║   ";
			cout << "  " << data[row][colNum2] << "    ║    ";
			stringstream ss(data[row][colNum2]);
			string primerDetails = tmCalc(ss.str());
			cout << primerDetails << endl;
			rowNumber++;
			if(rowNumber == 2){
				rowNumber = 0;
				//cout << "└---------------║-----------------------------║---------------┘" << endl;
				cout << "└───────────────║─────────────────────────────║───────────────┘" << endl;

			}
		}
	}
	cout << endl;

	return 0;
}
//║ ╒══════╕ ╘══════╛ ┊ ┊ ┊ ┊ └──────┘ ╰┈┈┈┈╯ └ ┛
///Users/dkz974/Desktop/Primers_Sub_2011_Gag_Cl10_16p13_annotations.csv

