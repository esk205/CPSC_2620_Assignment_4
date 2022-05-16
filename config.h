// ********************************************************************
// CPSC2620 Spring 2016
// File Name: config.h
// Purpose: This file allows for "easy" configuration of the programs
// options such as customer policy and how many tellers are available
// Created on: Mar 11, 2016
// Author: Michael Wynnychuk
// Notes:
// ********************************************************************
#ifndef CONFIG_H
#define CONFIG_H
#include<iostream>
#include<string>
using namespace std;

class Config { // stores the configuration of one simulation.
public:
    Config(int TELLER = 1, int INITIALCUSTOMER = 5, string CUSTOMERPOLICY = "FCFS", int MAXARRIVE = 5, int MAXTASKTIME = 10) 
	{
		teller = TELLER;
		initialCustomer = INITIALCUSTOMER;
		customerPolicy = CUSTOMERPOLICY; // FCFS = First Come First Serve, SJF = Shortest Job First
		maxArrive = MAXARRIVE;
		maxTaskTime = MAXTASKTIME;
	}
	int teller; // number of tellers
	int initialCustomer; // initial amount of customers
	int maxArrive; // maximum customers that can arrive at 10 minutes
	int maxTaskTime; // maxTaskTime that a customer can have at the teller
	string customerPolicy; // FCFS (1) by default or the user selects SJF (0)
private:
	friend ostream& operator<<(ostream& out, const Config config) {
		out << "Tellers# " << config.teller << " " << "Customers#";
		out << config.initialCustomer;
		out << " ";
		out << "Policy";
		out << config.customerPolicy;
		out << endl;
		return out;
	}
};
#endif

