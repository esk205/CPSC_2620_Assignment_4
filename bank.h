// ********************************************************************
// CPSC2620 Spring 2016
// File Name: bank.h
// Purpose: Define Bank class with its members and methods
// Created on: Mar 11, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#ifndef BANK_H
#define BANK_H
#include "config.h"
#include "customer.h"
#include "result.h"
#include <map>
#include <list>
#include <queue>
#include <assert.h>
#include <string>
using namespace std;

class Bank {
  public :
	// Sets the number of tellers in the bank and a flag indicating if the the FCFS or SJF policy should
	// be used. By default, a bank will have one
	// teller and will use the FCFS policy.

	 Bank(Config C);
	 // The method takes in the number of initial customers that
	 // will be waiting for the bank to open, the
	 // maximum number of customers that can arrive every 10 miutes (default 1), and
	 // the maximum length of time(in minutes) a customer will need from a teller
	 // (default 1).
	void runSimulation();

	// A public method "results" with no parameters that returns a Result object 
	// containing the results from the simualtion.
	Result results();
  private :
	int  waitTime; // how long a customer has waited before being served
	bool simulationComplete; // bank simulation complete
	bool tellerAvailable; // used to tell if teller is available
	int totalTaskTime;
	Result r;
	queue<Customer> finished;
};
//#include "./bank.cc"
#endif
