#pragma once
#include<iostream>
#include"user.h"
#include"Data.h"
using namespace std;
class admin
{

public:
	void viewRecords(string &nId, LinkedList&  u);
	void deleteRecords(string &id, LinkedList& u);
	void deleteAllRecords(LinkedList& u);
};

