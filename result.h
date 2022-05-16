// ********************************************************************
// CPSC2620 Spring 2016
// File Name: result.h
// Purpose: Display results of simulation
// Created on: Mar 11, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#ifndef RESULT_H
#define RESULT_H
#include"bank.h"
using namespace std;

class Result {  //stores the results from one simulation
public:
	int    numCustServed; // number of customers served
	int    custTurnedAway; // customers that were not served
	double avgTime; // 
	double avgCustTime; // average overall time all customers spent
	int    fiveLessCust; // Customer finished in less than 5 minutes
	int    sixTenCust; // Customer finished within 6 to 10 minutes
	int    elevenTwentyCust; // Customer finished between 11 to 20 minutes
	int    twentyOneToSixtyCust; // Customer finish between 21 to 60 minutes
	int    moreThanSixtyCust; // Customer waiting for more than 60 minutes
private:	
};
ostream& operator<<(ostream& out,const Result& r) {
	out << " "<< r.numCustServed << " " << " " << r.custTurnedAway << " " 
	    << " " << r.avgCustTime  << " " << r.fiveLessCust <<  " " << endl;
	out << " " << r.sixTenCust   << " " << r.elevenTwentyCust << " " << r.twentyOneToSixtyCust 
	    << " " << r.twentyOneToSixtyCust << " " << r.moreThanSixtyCust << endl;
	return out;
}
bool operator<(const Result& r1,const Result& r2)
{
  // if(r1.custTurnedAway == r2.custTurnedAway && r1.numCustServed == r2.numCustServed) {
    //  return r1.avgCustTime < r2.avgCustTime;
  // }
   if(r1.numCustServed == r2.numCustServed) {
      return r1.custTurnedAway < r2.custTurnedAway;
   }
   else if (r1.numCustServed < r2.numCustServed) { 
      return true;
   }
   else {
      return false;
   }
}
#endif
