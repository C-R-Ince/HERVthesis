//============================================================================
// Name        : primerReporter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include "bptFileName.h"
#include <fstream>
#include <cassert>

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
		primerDet << percentGC << ", " << Totalbp << ", " << finalTm << endl;

		string primerDetails = primerDet.str();
		return primerDetails;

	} else {
		float finalTm = 69.3 + (0.41 * percentGC) - (650 / Totalbp);

		ostringstream primerDet;
		primerDet << percentGC << ", " << Totalbp << ", " << finalTm;

		string primerDetails = primerDet.str();
		return primerDetails;
	}
}

string fileSetup(){

	string saveLocation = " ";
	string filePath = " ";
	string confirm = " ";

	cout << "Please enter the file path where the files will be saved: " << endl;

	cin >> saveLocation;

	char lastLetter = saveLocation.back();
	string ss(1, lastLetter);

	if (ss == "/") {
		cout
				<< "The files will be saved at: " + saveLocation
						+ " \nIs this correct? (Y/N)" << endl;
	} else {
		cout
				<< "The files will be saved at: " + saveLocation
						+ "/ \nIs this correct? (Y/N)" << endl;
	}

	cin >> confirm;

	if (confirm == "Y" || confirm == "y"){
		if (ss == "/") {
		filePath = saveLocation;
		} else {
			filePath = saveLocation + "/";
		}
	} else {
		cout << "Setup failed. Please try again." << endl;
		return fileSetup();
	}

	return filePath;

}
///Users/dkz974/Downloads/
// + "/batchPrimerDesign/"

char nth_letter(int n){
	n--;
    assert(n >= 1 && n <= 26);
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
}

int main() {


	cout << " ---------------------------------" << endl;
	cout << "┆ Welcome to Batch Primer Design! ┆\n --------------------------------- \n \n";


	string fileSetupLocation;

	fileSetupLocation = fileSetup();
	string tempPrimerLocation = fileSetupLocation + "tempPrimerFile.txt";

	ofstream tempPrimer;
	tempPrimer.open(tempPrimerLocation);
	tempPrimer << "Please enter the primer sequences in this file. With a primer on each line" << endl;

	string openTempPrimerLocation = "open " + tempPrimerLocation;
	const char* openTempPrimer = openTempPrimerLocation.c_str();
	system(openTempPrimer);


	string gene = defineGene();
	string cluster = defineCluster();
	string virRef = defineVirRef();
	string primerSet = definePrimerSet();
	string fwdRev = defineFwdOrRev();

	string totalSeqInCl = definetotalSeqOfClus();
	string totalSeqInGe = defineTotalSeqOfGene();
	tempPrimer.close();
	//creates new file
	string fileName = gene + "_Cluster" + cluster + "_" + virRef + "_PrimerSet" + primerSet + "_" + fwdRev + ".csv";
	cout << fileName << endl;
	tempPrimer.close();

	fstream primerFile;
	primerFile.open(tempPrimerLocation);
	ofstream newPrimerFile;

	newPrimerFile.open(fileSetupLocation + fileName);
	//Headers
	newPrimerFile << "Gene, Primer Name, Cluster, Reference, Primer Set, Forward or Reverse, Primer Seq., Percentage GC, Total bp, Tm°C, Coverage in Cluster, Number of Sequences in Cluster, Percent Coverage of Cluster %, Number of Sequences in Gene, Percent Coverage of Gene %, Other Notes" << endl;

	int lines = 1;
	string primer;
	while (!primerFile.eof()) {
	    getline(primerFile, primer);
	    if (primer.empty()) {
	    	continue;
	    } else {
		if (primer == "Please enter the primer sequences in this file. With a primer on each line"){
			continue;
		} else {
		lines++;
		char primerLabel = nth_letter(lines);
		string line = to_string(lines);

		newPrimerFile << gene << ", " <<
				gene << "_" << "Cl" << cluster << "_" << fwdRev << "_" << primerLabel //Primer Name
				<< ", Cl" << cluster << ", " << virRef << ", "
				<< primerSet << ", " << fwdRev << ", ";
		newPrimerFile << primer << ", ";
		string primerDetails = tmCalc(primer);
		newPrimerFile << primerDetails;
		//Coverage in Cluster, Number of Sequences in Cluster, Percent Coverage of Cluster %
		newPrimerFile << ", " << "null" << ", " << totalSeqInCl << ", =$J" << line << "/" << totalSeqInCl << "*100";
		//Number of Sequences in Gene, Percent Coverage in Gene
		newPrimerFile << ", " << totalSeqInGe << ", =$J" << line << "/" << totalSeqInGe << "*100" << ", " << endl;
		}
	    }
	}

	cout << "\n \n \n \nFile created! \nLocation: " << fileSetupLocation + "/" + fileName;

	string outputFileB = "open " + fileSetupLocation + fileName;
	const char* openFileB = outputFileB.c_str();
	system(openFileB);

	void close();


	cout << "\n \nPROGRAM END" << endl;

	return 0;
}
