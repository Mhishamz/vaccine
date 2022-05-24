#pragma once
#include "C:\Users\J stock\source\repos\vaccnie project\vaccnie project\Linkedlist.h"
#include"user.h"
class Data
{
public:
	int nOfUsers = 0;
	int nOfEgyptians = 0;
	int nOfforigners = 0;
	int nOfDose1 = 0;
	int nOfFVaccined = 0;
	int nOfMen = 0;
	int nOfWomen = 0;
	int nOfWaitingList = 0;
	int nOfcairo = 0, nOfalex = 0, nOfmansora = 0, nOfsinai = 0;
	LinkedList users;
	queue<user> waitingList;
public:
	void add_to_waitingList(LinkedList& u);
	void displayStatistics(LinkedList& u);
	void caLc_Statistics(LinkedList& l);
	void updateInformation(LinkedList& l, int index);

};