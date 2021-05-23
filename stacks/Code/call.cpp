// Run in repl.it:
// clang++-7 -pthread -std=c++17 -o call call.cpp; ./call < call_test1.in

#include <iostream>
#include <string>
#include <cassert>
#include<bits/stdc++.h>
#include "dlist.h"
using namespace std;
/*
 * Format of input line:
 *
 *  <timestamp> <Name> <status> <duration>
 *
 * Note: first four fields terminated by whitespace
 *       request terminated by newline.
 *
 * Format of input file:
 * 
 * A single line with the number of requests
 * zero or more input lines followed by EOF.
 */

enum Status {
  NONE = 0, SILVER = 1, GOLD = 2, PLATINUM = 3
};

struct reqNode {
  int         timestamp;
  std::string name;
  std::string status;
  int         duration;
};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/***************************************************
 * INSTRUCTOR NOTE: Implement the functions below. *
 **************************************************/

// EFFECTS: Reads and parses each request from the standard input stream
// std::cin. For each request, creates a reqNode struct and enqueues their
// pointers in the requests queue, which is a Dlist of pointers to reqNode
// structs. 
void ObtainRequests(Dlist<reqNode*> &requests) {
  // Implement this function.
  int total_requests;
  std::cin>>total_requests;
  for(int i=0;i<total_requests;i++){
  	reqNode *newNode = new reqNode;
  	int timestamp;
  	std::cin>>timestamp;
  	newNode->timestamp = timestamp;
  	
	std::string name;
  	std::cin>>name;
  	newNode->name = name;
  	
  	std::string status;
	std::cin>>status;
	newNode->status = status;
  	
  	int duration;
  	std::cin>>duration;
  	newNode->duration = duration;
  	
  	requests.InsertBack(newNode);
  	
  }
}

// EFFECTS: Insert any callers with timestamps equal to the tick number
// (the clock param) into their appropriate queues. When a caller is
// inserted, you should print a message that exactly matches the following 
// example (with the correct name and status):
// 
// Call from Jeff a silver member
//
//
// You can get the appropriate status by calling status_names[status]. 
// Note: If two (or more) calls have the same timestamp, they should be
// printed in input file-order, not in priority-order.
void InsertRequests(Dlist<reqNode*> requests, Dlist<reqNode*> queues[], int clock, std::string status_names[]) {
  // Implement this function.
  int count=0;
  while(!requests.IsEmpty()){

  	reqNode *newNode = new reqNode;
  	newNode = requests.RemoveFront();

  	if(newNode->timestamp == clock){
  		if(newNode->status == "platinum"){
  			queues[3].InsertBack(newNode);

		}
		else if(newNode->status == "gold"){
			queues[2].InsertBack(newNode);

		}
		else if(newNode->status == "silver"){
			queues[1].InsertBack(newNode);

		}
		else if(newNode->status == "none"){
			queues[0].InsertBack(newNode);
		}
    if(newNode->status=="none")
      std::cout<<"Call from "<<newNode->name<<" a regular member\n";
    else
  		std::cout<<"Call from "<<newNode->name<<" a "<<newNode->status<<" member\n";
	  }
  }
}

// EFFECTS: Simulate the actions of the agent at this tick. The agent must
// follow these rules:
// 1. If the agent is not busy, the agent checks each queue, in priority order
// from Platinum to None. If the agent finds a call, the agent answers the
// call, and you should print a message that exactly matches the following 
// example (with the correct name):
// 
// Answering call from Jeff
// 
// We will need to decrement time_agent_busy by 1. 
// 
// 2. If the agent was already busy at the beginning of this tick, the agent
// continues servicing the current client. You will need to decrement
// time_agent_busy by 1. 
// 
// 3. If the agent is not busy, and there are no current calls, the agent
// does nothing. 
//
// If all calls have been placed, answered, and completed, then return true
// to end the program. Otherwise, return false.
bool SimulateAgent(Dlist<reqNode*> &requests, Dlist<reqNode*> queues[], int &time_agent_busy) {
  // Implement this function.
  if(time_agent_busy==0){
  	    for(int i = 3;i>=0;i--){
              if(!queues[i].IsEmpty() && time_agent_busy==0){
                reqNode *newNode = new reqNode;
                newNode = queues[i].RemoveFront();
                time_agent_busy=newNode->duration;
              std::cout<<"Answering call from "<<newNode->name<<"\n";
            }
      }
  }
  if(queues[0].IsEmpty()&&queues[1].IsEmpty()&&queues[2].IsEmpty()&&queues[3].IsEmpty()){
  	return true;
  }
  else{
  	return false;
  }
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  // The current time, starting at tick 0. 
  int clock = 0;

  // The remaining time that the agent is busy with the current
  // caller, or 0 if the agent is not busy. 
  int time_agent_busy = 0;

  // An array of four queues, one for each status: regular, silver,
  // gold, platinum. Each queue is a DList of pointers to reqNode
  // structs. 
  Dlist<reqNode*> queues[4]; 

  // A queue of requests matching the input. The queue is a DList of 
  // pointers to reqNode structs.
  Dlist<reqNode*> requests;
  // Flag for whether or not the program should terminate. 
  bool done = false;

  // Array of status name strings for each Status. 
  std::string status_names[4];
  status_names[NONE] = "regular";
  status_names[SILVER] = "silver";
  status_names[GOLD] = "gold";
  status_names[PLATINUM] = "platinum";

  // Run call center simulation.
  ObtainRequests(requests);
  while (!done) {
    std::cout << "Starting tick #" << clock << std::endl;
    
    InsertRequests(requests, queues, clock, status_names);
    done = SimulateAgent(requests, queues, time_agent_busy);
    time_agent_busy--;
    clock++;
  }
  std::cout << "Starting tick #" << clock << std::endl;
  return 0;
}