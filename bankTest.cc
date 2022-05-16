// ********************************************************************
// CPSC2620 Spring 2016
// File Name: bankTest.cc
// Purpose: Tests the bank program and it's associate mini-programs
// Created on: Mar 11, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#include"bank.h"
#include <iomanip>

using namespace std;

int main() {
   typedef map<Result, Config>m;
	Config c1{1, 10, "SJF", 5, 10} ,    c2{1, 10, "FCFS", 5, 10};
	Config c3{2, 10, "SJF", 5, 10} ,    c4{2, 10, "FCFS", 5, 10};
        Config c5{3, 10, "FCFS", 5, 10},c6{3, 10, "FCFS", 5, 10};
	Config a[6] = {c1, c2, c3, c4, c5, c6};
	m mapz;      
	
	for(int i = 0; i < 6; i++) { // Display results for config file
	   Result res;
	   Bank b(a[i]);
	   b.runSimulation();
	   res = b.results();
	   mapz[res] = a[i];
	}

	cout << setw(35) <<  "Result" << setw(35) << "Configuration " << endl;
	cout << setw(35) << "--------" << setw(35) << "------------" << endl;
	for(auto mapItem : mapz) {
	   cout << mapItem.first << " " << mapItem.second << endl;
	}
	return 0;
}

