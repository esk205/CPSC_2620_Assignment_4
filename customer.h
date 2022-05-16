// ********************************************************************
// CPSC2620 Spring 2016
// File Name: customer.h
// Purpose: Represents the customer in the bank.
// Created on: March 11, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<stdlib.h>
#include<cassert>
	
class Customer { // represents a customer of the bank.
  public:
    Customer(int = 5);        // Constuctor customer taskTime is 5 minutes
	int   taskTime(int);      // returns the length of time (in minutes) of the customer's task.
	int   waitTime(int);      // returns the length of time (in minutes) the customer waited since they arrived until they were served
	int   finishTime(int);    // returns when (in minutes) the customer will be finished with their task in the bank.
	void  enteredAt(int);     // records the time (in minutes) when the customer entered the bank.
	void  servedAt(int);      // records the time (in minutes) when the customer is served by a teller.
	int   time, enterTime, servedTime;
	int   taskT, finT, waitT;
	bool  served;
};
#endif
Customer::Customer(int task) {
   taskT = task; // default customer taskTime is 5 minutes
}
int Customer::taskTime(int taskT) {
   return taskT;
}
int Customer::waitTime(int waitT) {
   assert(served);
   return waitT;
}
int Customer::finishTime(int finT) {
   assert(served);
   return finT + enterTime;
}
void Customer::enteredAt(int clock) {
   served = false;
   enterTime = clock;	
}
void Customer::servedAt(int clock) { // records the time (in minutes) when the customer is served by a teller.
   served = true;
   servedTime = clock;
}
bool operator<(const Customer c1, const Customer c2) {
   return (c1.taskT < c2.taskT);
}

