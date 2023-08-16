//============================================================================
// Name        : batchPrimerTm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//File header conventions
#include <iostream>
using namespace std;


string defineGene(){
	cout << "Define gene: " << endl;
	string gene;
	cin >> gene;

	return gene;
}


string defineCluster(){
	cout << "Define the Cluster number outputted by CD-HIT \nCl:";
	string clusterNumb;
	cin >> clusterNumb;

	return clusterNumb;
}

string defineVirRef(){
	cout << "Define reference: " << endl;
	string virRef;
	cin >> virRef;

	return virRef;
}

string definePrimerSet(){
	cout << "Define Primer set" << endl;
	string primerSet;
	cin >> primerSet;
	
	return primerSet;
}

string defineFwdOrRev(){
	cout << "Are the primers Forward or Reverse? \nf: Forward, r: Reverse" << endl;
	string fwdOrRev;
	cin >> fwdOrRev;

	if(fwdOrRev == "f" || fwdOrRev == "F"){
		fwdOrRev = "Fwd";
	} else if (fwdOrRev == "r" || fwdOrRev == "R"){
		fwdOrRev = "Rev";
	} else {
		cout << "Invalid entry" << endl;
		defineFwdOrRev();
	}

	return fwdOrRev;
}

string defineTotalSeqOfGene(){
	cout << "Number of total sequences in the gene?" << endl;
	string totalSeqGene;
	cin >> totalSeqGene;

	return totalSeqGene;
}

string definetotalSeqOfClus(){
	cout << "Number of sequences in the CD-HIT cluster?" << endl;
	string totalSeqClus;
	cin >> totalSeqClus;
	
	return totalSeqClus;
}


