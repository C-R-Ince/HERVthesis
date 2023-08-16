//============================================================================
// Name        : Tm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : For reverse complementing and primer Tm Calc.
//============================================================================

#include <iostream>
using namespace std;

string primerInput (){
	string primer;
	cout << "Enter your primer here:\nThe Primer must only consist of the letters A, T, G, and C, and must be capitalised" << endl;
    //string primer = "TTGGGCCATTATTAAAGCAA";
	cin >> primer;

	return primer;
}

string reverseComplement(string primer){

	cout << "Does the primer need to be reverse complement?" << endl;
	cout << "1 = yes, 0 = no" << endl;
	int input;
	cin >> input;

		switch(input){
		case 1:
			reverse(primer.begin(), primer.end());
			    for (std::size_t i = 0; i < primer.length(); ++i){
			        switch (primer[i]){
			        case 'A':
			            primer[i] = 'T';
			            break;
			        case 'C':
			            primer[i] = 'G';
			            break;
			        case 'G':
			            primer[i] = 'C';
			            break;
			        case 'T':
			            primer[i] = 'A';
			            break;}
			    }
			    cout << primer << endl;
			    return primer;
			    break;
		case 0:
			cout << primer << endl;
			return primer;
			break;
		default:
			cout << "Incorrect value, please run again" << endl;
		}
}

float GCcalc(string primer) {

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

    float percentGC = GCcount / Totalbp * 100;

    cout << "-----------------------------------" << endl;
    cout << "Total Primer length is " << Totalbp << endl;
    cout << "There are " << Gcount << " G bases, ";
    cout << "and " << Ccount << " C bases" << endl;
    cout << "GC content is " << GCcount << " of " << Totalbp << " bases." << endl;
    cout << "GC percent is " << percentGC << "%" << endl;
    cout << "-----------------------------------" << endl;


    return GCcount;
}


void tmCalcLessThan14(float GCcount, float ATcount) {
	float tmGC = 4 * GCcount;
	// cout << "int tmGC is " << tmGC << endl;

	float tmAT = 2 * ATcount;
//	cout << "int tmAT is " << tmAT << endl;

	float finalTm = tmGC + tmAT;

	cout <<  "The Primer Tm is roughly " << finalTm << "°C";

	}

void tmCalcGreaterThan14(float percentGC, float Totalbp){
	cout << "Primer is greater than 13bp" << endl;
	float finalTm = 69.3 + (0.41 * percentGC) - (650 / Totalbp);
	cout <<"percentGC is " << percentGC << endl;
	cout << "Primer Tm is roughly equal to " << finalTm << "°C";
}

int main()
{

	string primer = primerInput();
	string RCprimer = reverseComplement(primer);


    float Totalbp = RCprimer.length();
    float GCcount = GCcalc(RCprimer);
    int ATcount = Totalbp - GCcount;
    float percentGC = GCcount / Totalbp * 100;
    // cout << "Percent GC " << percentGC << endl;

	if(Totalbp < 14) {
		cout << "Primer is under 14bp" << endl;
		tmCalcLessThan14(GCcount, ATcount);
	} else tmCalcGreaterThan14(percentGC, Totalbp);


    return 0;
}

//string primer = "TTGGGCCATTATTAAAGCAA";
