// ********************************************************************
// CPSC2620 Spring 2016
// File Name: bank.cc 
// Purpose: Simulate customers entering the bank and
// the tellers servicing them to determine
// best customer processing policy
// Created on: March 11, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#include "bank.h"
#include<list>
#include<string>
using namespace std;

// A constructor that sets the number of tellers in the bank and a flag indicating
// if the the FCFS or SJF policy should be used. By default, a bank will have one
// teller and will use the FCFS policy.
Bank::Bank(Config c) { 
	c.customerPolicy = "FCFS";
	c.teller = 1;
	c.initialCustomer = 5;
	c.maxArrive = 5;
	c.maxTaskTime = 10;
}
void Bank::runSimulation() {
	Customer cust; // Customer object cust
	Config config; // Configuration object config
	queue<Customer> qWaiting; // represents a queue of people waiting
	priority_queue<Customer> pqWaiting; // Create priority queue container (sorts customer)
	list<Customer> atTeller; // load finished customer into list

	int taskTime = rand() % config.maxTaskTime + 1; // used for customer class method taskTime
	for (int i = 0; i < config.initialCustomer; i++) { // load up queue with initial customers
		cust.taskTime(taskTime); // Give each customer object a taskTime
		cust.enteredAt(480); // Initial customers waiting outside the bank before opening
		if (config.customerPolicy == "FCFS") {
			qWaiting.push(cust); // Push customers onto waiting queue
		}
		else { // (config.customerPolicy == "SJF")
			   // Push customers onto waiting priority queue
			pqWaiting.push(cust); 
		}	
	}
	int clock = 480; // Bank operation minutes
	while (clock != 0) {  // Start time loop for bank operation
		clock--; // Reduce bank operation time by a minute
		if (clock % 10 == 0) // Every 10 minutes add customers to queue
		{ 
			for (int i = 0; i < config.maxArrive; i++) 
			{
				cust.taskTime(taskTime); // customer time
				if (config.customerPolicy == "FCFS") {	   
				   qWaiting.push(cust); // add to queue of waiting customers
				}			
				else { // (config.customerPolicy == "SJF")
					 pqWaiting.push(cust); // add to priority queue of waiting customers
				}
			} // end of for loop
		} // end of if statement
	        while (atTeller.size() < config.teller) {
			for (auto it = atTeller.begin(); it!=atTeller.end(); ++it) 
			{
			   cust.servedAt(clock);
			   if (cust.finT <= clock) {
			      finished.push(cust); // queue for the finished customers
			   }
			   atTeller.push_back(cust);
			} // end of for loop		
		} // end of second while loop
	} // end of first while loop
	if (config.customerPolicy == "FCFS") {
		r.custTurnedAway = qWaiting.size();
		r.numCustServed = finished.size();
	}
	else { // (config.customerPolicy == "SJF") 
		r.custTurnedAway = pqWaiting.size();
	}
    simulationComplete = true;
}
Result Bank::results() {
   assert(simulationComplete == 1); // Check if simulation is complete
   r.avgCustTime = totalTaskTime / r.numCustServed;
   r.numCustServed = finished.size();
   return r; // return a Result object containing the results from the simualtion.
}