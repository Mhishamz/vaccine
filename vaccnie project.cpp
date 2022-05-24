// ConsoleApplication10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<string>
#include<conio.h>
#include"stdlib.h"
#include<list>
#include<fstream>

#include"C:\Users\J stock\Desktop\mohamed\second year\second term\datastructure\vaccin\vaccin\Data.h"
#include"C:\Users\J stock\Desktop\mohamed\second year\second term\datastructure\vaccin\vaccin\user.h"
#include"C:\Users\J stock\Desktop\mohamed\second year\second term\datastructure\vaccin\vaccin\admin.h"
#include "C:\Users\J stock\source\repos\vaccnie project\vaccnie project\Linkedlist.h"
///////////////////////////////// function‘s difinitions  //////////////////////////////////
void displayScreen(LinkedList& l, user& u, Data& d, admin& a);
void login(LinkedList& l, user& u, Data& d, admin& a);
void back_to_start();
void user_functions();
void choose();
void addinfile(LinkedList& l);
void addinprogram(LinkedList& l); 
void addforstat(LinkedList& l);
///////////////////////////////// global variables ////////////////////////////////////
user u;
LinkedList l;
Data d;
admin a;
int logged_in_user = 0;  // the linked list index of the user who is login 
#define MAX_LEN  60
#define gender_size 1
/////////////////////////////////////  main  /////////////////////////////////////////////////

using namespace std;
int main()
{
	addinprogram(l);
	displayScreen(l, u, d, a);
}

////////////////////////////////////////////////////////////////////////////////

void displayScreen(LinkedList& l, user& u, Data& d, admin& a)
{

	int i;
	char choice[1];

	do {
		cout << "--------------------- Welcome To Vaccine Tracking System ---------------------" << endl;
		cout << "1- signup             " << endl;
		cout << "2- login              " << endl;
		cout << "3- exit               " << endl;
		cout << "4- display statistics " << endl;
		cin >> choice;
		system("cls");
		i = atoi(choice);
		if (i == 1)
		{
			////////////////////////////////////////// sign up /////////////////////////////////////////
			cin.ignore();
			u.addInformation();
			//check if the id is unique
			if (!l.find(u.nationalId)) {
				l.Append(u);
				cout << endl << "Thank you for signing up ^-^" << endl << endl;
				system("pause");
				back_to_start();
			}
			else if (l.find(u.nationalId)) {
				cout << "National id is used !" << endl;
				cout << "please sign up again " << endl;

				system("pause");
				back_to_start();
			}

		}

		if (i == 2)
			/////////////////////////////////////// login ////////////////////////////////////////
			login(l, u, d, a);
		if (i == 3) {
			addinfile(l);
			addforstat(l);
			/////////////////////////////////////// exit ////////////////////////////////////////
			exit(0);
		}
		if (i == 4)
		{
			//////////////////////////////// display statistics ///////////////////////////////
			d.displayStatistics(l);
			cout << endl << endl;
			system("pause");
			back_to_start();
		}

	} while (i > 4 || i < 1);
}

/////////////////////////////////////////////////  login function  ////////////////////////////////////////////////////

void login(LinkedList& l, user& u, Data& d, admin& a)
{
	int choiceLogin = 0;
	int choiceInLogin = 0;
	string adminName;
	string adminPassword;
	string nationalId;
	string userPassword;
	do {
		cout << "1 - login as admin " << endl;
		cout << "2-  login as user  " << endl;
		cin >> choiceLogin;
		system("cls");
		switch (choiceLogin)
		{
			///////////////////////////////////////   login as an admin   //////////////////////////////////////////////////////
		case 1:
			cout << "Enter admin name     : "; cin >> adminName;
			cout << "Enter admin password : "; cin >> adminPassword;
			system("cls");
			if (adminName == "admin" && adminPassword == "admin")
			{
				do {
					cout << "1-View Records by ID    " << endl;
					cout << "2-Delete Records by ID  " << endl;
					cout << "3-Delete All Records " << endl;
					string id;
					cin >> choiceInLogin;
					system("cls");
					switch (choiceInLogin)
					{
					case 1:
						//////////////// admin : view records ////////////////
						cout << "Please Enter ID : "; cin >> id;
						a.viewRecords(id, l);
						cout << "To delete this user press 1, to back to start menu press any other number" << endl;
						char choice;
						cin >> choice;
						if (choice == '1')
							a.deleteRecords(id, l);
						else
							back_to_start();
						break;
					case 2:
						//////////////// admin : delete records ////////////////
						cout << "Please Enter ID : "; cin >> id;
						a.deleteRecords(id, l);
						break;
					case 3:a.deleteAllRecords(l);
						break;

					default:
						cout << "Enter Valid Value : " << endl;
					}
					break;
				} while (choiceInLogin >= 2 && choiceInLogin <= 1);
				system("pause");
				back_to_start();
				break;
			}
			//////////////////////////////////////// login as an user /////////////////////////////////////////
		case 2:
			cout << "Enter national id     : "; cin >> nationalId;
			cout << "Enter password        : "; cin >> userPassword;
			bool x = true;
			for (int i = 0; i < l.Length(); i++)
			{

				if (nationalId == l.At(i).nationalId && userPassword == l.At(i).password)
				{

					logged_in_user = i; //global variable to save the index of the logged in user
					user_functions();
					break;
					x = false;
				}
			}
			if (x)
			{
				cout << "USER NOT FOUND !" << endl;
				system("pause");
				back_to_start();
			}
			break;
		}
		break;
	} while (choiceLogin > 2 || choiceLogin < 1);

}

//////////////////////////////////////  back to start  ////////////////////////////////////////
void back_to_start() {

	system("cls");
	displayScreen(l, u, d, a);
}

//////////////////////////////////////  user functions  //////////////////////////////////////
void user_functions() {
	int ch;
	do {
		system("cls");
		cout << "1 - view my records        " << endl;
		cout << "2 - update my informations " << endl;
		cout << "3 - delte my records       " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			//////////////// user : view records ///////////////////
			l.At(logged_in_user).displayRecords();
			break;
		case 2:
			//////////////// user : update informations ////////////
			d.updateInformation(l, logged_in_user);
			choose();
			break;
		case 3: {
			//////////////// user : delete records ////////////
		
			l.DeleteAt(logged_in_user);
			system("pause");
			back_to_start();
			break;
		}
		default:
			cout << "Enter Valid Value " << endl;
			break;
		}
		break;
	} while (ch > 1 || ch < 3);
	choose();
}

////////////////////////////  choose function  //////////////////////////////////////
void choose() {
	cout << "To back to the last menu press 1\n" << "To back to start menu press 2" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
		user_functions();
	if (choice == 2)
		back_to_start();
	else
		back_to_start();
}


void addinfile(LinkedList& l) {
	ofstream tofile;
	tofile.open("list");
	if (tofile.fail())
	{
		cerr << "failed in openning file" << endl;
		exit(1);
	}
	tofile << l.Length() << endl;
	for (int i = 0; i < l.Length(); i++)
	{
		tofile << l.At(i).fullName<<endl << l.At(i).password << endl << l.At(i).country << endl << l.At(i).governorate << endl;
		tofile << l.At(i).age << endl << l.At(i).nationalId << endl << l.At(i).fullyVaccined << endl << l.At(i).isVaccined << endl;
		tofile << l.At(i).onWaiting << endl << l.At(i).gender << endl<<l.At(i).lives_in_egypt<<endl;

	}
	tofile.close();
	cout << "success" << endl;
}

void addinprogram(LinkedList& l) {
	ifstream fromfile;
	fromfile.open("list");
	if (fromfile.fail())
	{
		cerr << "failed in openning file" << endl;
		exit(1);
	}
	int numuser = 0,i=0;
	fromfile >> numuser;
			fromfile.ignore();

	while (i<numuser)
	{
		i++;
		user u1;
		fromfile.getline(u1.fullName, MAX_LEN);
		fromfile.getline(u1.password, MAX_LEN);
		fromfile.getline(u1.country, MAX_LEN);
		fromfile.getline(u1.governorate, MAX_LEN);
		fromfile >> u1.age;
		fromfile.ignore();

		fromfile >> u1.nationalId;
		fromfile.ignore();
		fromfile >> u1.fullyVaccined;
		fromfile.ignore();
		fromfile >> u1.isVaccined;
		fromfile.ignore();

		fromfile >> u1.onWaiting;
		fromfile.ignore();

		fromfile >> u1.gender;
		fromfile.ignore();

		fromfile >> u1.lives_in_egypt;
		fromfile.ignore();
		l.Append(u1);

	}
	fromfile.close();
}
void addforstat(LinkedList& l) {
	ofstream tofile;
	tofile.open("stat.txt");
	if (tofile.fail())
	{
		cerr << "failed in openning file" << endl;
		exit(1);
	}
	d.caLc_Statistics(l);
	
	tofile << d.nOfWaitingList << endl;
	tofile << d.nOfDose1 << endl;
	tofile << d.nOfFVaccined << endl;

	tofile << d.nOfMen << endl;
	tofile << d.nOfWomen << endl;
	tofile << d.nOfEgyptians << endl;
	tofile << d.nOfforigners << endl;

	tofile << d.nOfcairo << endl;
	tofile << d.nOfalex << endl;
	tofile << d.nOfmansora << endl;
	tofile << d.nOfsinai << endl;


	tofile.close();


}