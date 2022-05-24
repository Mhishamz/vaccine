#include "Data.h"
#include"user.h"


void Data::add_to_waitingList(LinkedList& u)
{
	for (int i = 0; i < u.Length(); i++)
	{
		if (u.At(i).onWaiting) {
			waitingList.push(u.At(i));
		}
	}
}
void Data::displayStatistics(LinkedList& u)
{
	caLc_Statistics(u);
	nOfUsers = u.Length();
	cout << "Number Of Users                         :  " << nOfUsers << endl;
	cout << "Number Of Users Who Take Dose 1         :  " << nOfDose1 << endl;
	cout << "Number Of Users Who is Fully Vaccined   :  " << nOfFVaccined << endl;
	cout << "Number Of Users Whose gender is Male    :  " << nOfMen << endl;
	cout << "Number Of Users Whose gender is Female  :  " << nOfWomen << endl;
	cout << "Number Of Users on The Waiting List     :  " << nOfWaitingList << endl;
	cout << "------------------------------------------------------------------------ " << endl;
	cout << "                             percentages of Egyptians                                " << endl;
	cout << "------------------------------------------------------------------------ " << endl;
	if (nOfEgyptians > 0) {
		cout << "Percentage of Users who Take Dose 1          = " << ((float)nOfDose1 / (float)nOfEgyptians) * 100 << "%" << endl;
		cout << "Percentage of Users who is Fully Vaccined    = " << ((float)nOfFVaccined / (float)nOfEgyptians) * 100 << "%" << endl;
		cout << "Percentage of Users who is Male              = " << ((float)nOfMen / (float)nOfEgyptians) * 100 << "%" << endl;
		cout << "Percentage of Users who is Female            = " << ((float)nOfWomen / (float)nOfEgyptians) * 100 << "%" << endl;
		cout << "Percentage of Users who is On Waiting list   = " << ((float)nOfWaitingList / (float)nOfEgyptians) * 100 << "%" << endl;
	}
	else
		cout << "No egyptians ";

}
void Data::caLc_Statistics(LinkedList& l)
{
	nOfDose1 = 0;
	nOfEgyptians = 0;
	nOfforigners = 0;
	nOfFVaccined = 0;
	nOfMen = 0;
	nOfUsers = 0;
	nOfWaitingList = 0;
	nOfWomen = 0;
	nOfcairo = 0, nOfalex = 0, nOfmansora = 0, nOfsinai = 0;
	for (int i = 0; i < l.Length(); i++)
	{
		if (l.At(i).is_egyptian()) {
			nOfEgyptians++;
			if (l.At(i).isVaccined)
			{
				nOfDose1++;
			}
			else if (l.At(i).fullyVaccined)
			{
				nOfFVaccined++;
			}
			else if (l.At(i).onWaiting) {
				nOfWaitingList++;
			}
			if (l.At(i).gender == 'M' || l.At(i).gender == 'm')
			{
				nOfMen++;
			}
			else if (l.At(i).gender == 'F' || l.At(i).gender == 'f')
			{
				nOfWomen++;
			}
			string s = l.At(i).governorate;

			if (s == "cairo")
			{
				nOfcairo++;
			}
			else if (s == "alex")
			{
				nOfalex++;
			}
			else if (s== "mansora")
			{
				nOfmansora++;
			}
			else if (s == "sinai")
			{
				nOfsinai++;
			}
		}
		else
			nOfforigners++;
	}

}
void Data::updateInformation(LinkedList& l, int index) {
	//fe el describtion maktoob : users may edit " any " of their informations
	int ch;
	user u;
	u = l.At(index);
	do {
		system("cls");
		cout << "1- tap to edit country     " << endl;
		cout << "2- tap to edit governorate " << endl;
		cout << "3- tap to edit password    " << endl;
		cout << "4- tap to edit your name    " << endl;
		cout << "5- tap to edit age    " << endl;
		cout << "6- tap to edit gender    " << endl;
		cout << "7- tap to edit National id " << endl;
		cout << "8-change vaccine state   " << endl;

		cin >> ch;
		int i = 0;
		cin.ignore();
		if (ch == 1)
		{
			//لو هو مصري وغير البلد خلاها مش مصر عايزينه ميتحسبلوش استات ولو هو مش مصري وبقا مصري يتحسبله استات 
			cout << "Enter Country       : ";    cin.getline(u.country, MAX_LEN);
			string egy;
			egy = u.country;
			if (egy == "egypt" || egy == "Egypt") {
				do {
					cout << "press 1 : if you live in egypt " << endl << "press 2 : if you live abroad " << endl;
					cin >> i;
					if (i == 1) {
						u.lives_in_egypt = true;
						break;
					}
					if (i == 2) {
						u.lives_in_egypt = false;
						break;
					}
				} while (i < 1 || i > 2);
				break;
			}
		}
		else if (ch == 2)
		{
			if (!u.is_egyptian()) {
				cout << "sorry, only egyptians can write and update thier governorate " << endl;
			}
			else
				cout << "New Governorate :"; cin >> u.governorate;
			break;
		}
		else if (ch == 3)
		{
			cout << "password :";   cin >> u.password;
			break;
		}
		else if (ch == 4)
		{
			cin.ignore();
			cout << "New name :";    cin.getline(u.fullName, MAX_LEN);
			break;
		}
		else if (ch == 5)
		{
			cout << "New age :";   cin >> u.age;
			break;
		}
		else if (ch == 6)
		{
			cout << "Enter gender (M / F)" << endl;
			cout << "New gender :";   cin >> u.gender;
			break;
		}
		else if (ch == 7)
		{
			cout << "New National id :";   cin >> u.nationalId;
			break;
		}
		else if (ch == 8)
		{
			cout << "--------------------------------------------------------------- " << endl;
			cout << "is vaccined Dose 1 ?  select 1  " << endl;;
			cout << "is Fully Vaccined ?   seelct 2  " << endl;
			cout << "not vaccined yet      select 3  " << endl;
			int ch;
			do {
				cin >> ch;
				switch (ch)
				{
				case 1:
					u.isVaccined = true;
					u.fullyVaccined = false;
					u.onWaiting = false;
					break;
				case 2:
					u.fullyVaccined = true;
					u.isVaccined = false;
					u.onWaiting = false;
					break;
				case 3:
					u.onWaiting = true;
					u.isVaccined = false;
					u.fullyVaccined = false;
					break;
				default:
					cout << "Enter valid Number !! " << endl;
				}
			} while (ch > 3 || ch < 1);
		}

		else {
			cout << "Enter valid value " << endl;
		}


	} while (ch < 1 || ch > 8);
	l.DeleteAt(index);
	l.InsertAt(index, u);
}