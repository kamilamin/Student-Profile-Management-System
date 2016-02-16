#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;

class Student
{
private:
	string fname;
	string mname;
	string lname,address;
	string filename;
	char Dept[10];
	int Enroll;
	int stdId;
	short age,day,year,month;
	
public:
	Student();
	~Student();
	void Input();
	void Search();
	void Edit();
	void DisplayAll();
	void Delete();
};

Student::Student()
{
}
Student::~Student()
{
}
void Student::Input()
{
	system("cls");
	system("color 08");
	cout << "Enter Student ID: ";
	cin >> stdId;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Middle Name: ";
	cin >> mname;
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter Date of Birth..\n";
	cout << "\t Day: ";
	cin >> day;
	cout << "\t Month: ";
	cin >> month;
	cout << "\t Year: ";
	cin >> year;
	cout << "Enter Student Age: ";
	cin >> age;
	cout << "Enter Enrollment year: ";
	cin >> Enroll;
	cout << "Enter Department: ";
	cin >> Dept;
	string stdId2 = to_string(stdId);
	stdId2.append(".txt");

	ofstream student(stdId2);
	student << fname << " " << mname << " " << lname << " " << stdId << " " << Enroll << " " << age << " " << day << setw(2) << month
		<< " " << year << " " << Dept << endl;
	student.close();
	ofstream dir("Directory.txt", ios::app);
	dir << fname << " " << mname << " " << lname << "   " << stdId << "   " << Enroll << " " << age << " " << day << " " << month
		<< " " << year << "  " << Dept << endl;
	dir.close();
}
void Student::Search()
{
	system("cls");
	system("color 06");
	cout << "Enter Student ID number: ";
	cin >> stdId;
	string stdId2 = to_string(stdId);
	stdId2.append(".txt");
	ifstream student(stdId2);
	while (student >> fname >> mname >> lname >> stdId >> Enroll >> age >> day >> month  >> year >> Dept)
	{
		int mnameLength = mname.size();
		int lnameLength = lname.size();
		int fnameLength = fname.size();
		int TotalLength = fnameLength + mnameLength + lnameLength;

		string answer;
		cout << "Is this correct Student[y/n] " << endl;
		cout << fname << " " << mname << " " << lname << " " << stdId << " " << age << " " << Dept << endl;
		cin >> answer;

		if (answer == "y")
		{
			system("cls");
			cout << "Name";
			for (int y = 1; y < TotalLength; y++)
			{
				cout << " ";
			}

			cout << " ID ";
			for (int z = 1; z < 2; z++)
			{
				cout << "";
			}

			cout << "Enrolled   Age   Date of Birth   Department" << endl;
			for (int y = 1; y < TotalLength + 20; y++)
			{
				cout << "--";
			}

			cout << " " << endl;
			cout << fname << " " << mname << " " << lname << "   " << stdId << "     " << Enroll << "      " << age << "      " << day << "-" << month << "-" << year  <<"  "<< Dept << endl;
		}
	}
}
void Student::Edit()
{
	system("cls");
	string newfname;
	string newmname;
	string newlname;
	string decision;
	string filename;
	int age, newage;
	//int thrw;

	cout << "Enter the Employee Number, whose data you want to edit: ";
	cin >> stdId;

	string stdId2 = to_string(stdId);
	stdId2.append(".txt");

	ifstream student(stdId2);
	while (student >> fname >> mname >> lname >> stdId >> Enroll >> age >> day >> month >> year >> Dept)
	{
		cout << "Is this the Employee that you wish to edit? [y/n]: " << endl;
		cout << fname << " " << mname << " " << lname << endl;
		cin >> decision;
		if (decision == "y")
		{
			system("cls");
			cout << "Current Information: " << endl;

			int mnameLength = mname.size();
			int lnameLength = lname.size();
			int fnameLength = fname.size();
			int TotalLength = fnameLength + mnameLength + lnameLength;

			cout << "Name";
			for (int y = 1; y < TotalLength; y++)
			{
				cout << " ";
			}
			
			cout << " ID: ";
			for (int z = 1; z < 2; z++)
			{
				cout << "";
			}

			cout << "Enrolled   Age   Date of Birth   Department" << endl;
			for (int y = 1; y < TotalLength + 20; y++)
			{
				cout << "--";
			}
		
			cout << " " << endl;
			cout << fname << " " << mname << " " << lname << " " << setw(3) << stdId << setw(3) << " " << Enroll << "      " << age << "    " << day << "-" << month << "-" << year << Dept << endl;
		}
		if (decision == "n")
			student.close();
		ofstream student1(stdId2);
		student1 << fname << " " << mname << " " << lname << " " << stdId << " " << Enroll << " " << age << setw(8) << day << setw(2) << month
			<< setw(2) << year << setw(3) << Dept << endl;
		student1.close();
	}
}
void Student::DisplayAll()
{
	system("cls");
	system("color 03");
	cout << "Entire Student Database " << endl;
	cout << "------------------------ " << endl;
	ifstream dir("Directory.txt");
	system("cls");
	cout << "Name";
	for (int y = 1; y < 18; y++)
	{
		cout << " ";
	}

	cout << " ID  ";
	for (int z = 1; z < 2; z++)
	{
		cout << "";
	}

	cout << "Enrolled   Age   Date of Birth   Department" << endl;
	for (int y = 1; y < 20 + 20; y++)
	{
		cout << "--";
	}
	cout << endl;
	while (dir >> fname >> mname >> lname >> stdId >> Enroll >> age >> day >> month >> year >> Dept)
	{
		cout << fname << " " << mname << " " << lname << "   " << stdId << "    " << Enroll << "      " << age << "     " << day << "-" << month
			<< "-" << year << setw(11) << Dept << endl;
	}
	system("Pause");
}
void Student::Delete()
{
	system("cls");
	system("color B");
	int File;
	cout << "Enter Student ID to delete the Data: ";
	cin >> File;

	string empId = to_string(File);
	empId.append(".txt");
	const char *mycharp = empId.c_str();

	if (remove(mycharp) != 0)
		cout << "Remove operation failed" << endl;
	else
	{
		cout << File << " has been removed." << endl;
		_sleep(5000);

	}

}
int main()
{
	system("cls");
	system("Title Student Profile Management System");
	system("color 03");
	cout << "\t\t********************************************\n";
	cout << "\t\t*       WELLCOME TO MEGA SOLUTION          *\n";
	cout << "\t\t********************************************\n";
	cout << "\t\t=============================================\n";
	cout << "\t\t     Student Profile Management System\n";
	cout << "\n\t\t\tEnter choices from below: " << endl;
	cout << "1.Input new Student " << endl;
	cout << "2.View an Student Data by ID number " << endl;
	cout << "3.Edit an existing Student Data " << endl;
	cout << "4.Display all Student." << endl;
	cout << "5.Delete an existing Student Data. " << endl;
	cout << "6.Exit \n" << endl;
	Student S;
	int choice;
	cout << "\tChoice :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		S.Input();
		main();
		break;
	case 2:
		S.Search();
		getch();
		main();
		break;
	case 3:
		S.Edit();
		main();
		break;
	case 4:
		S.DisplayAll();
		main();
		break;
	case 5:
		S.Delete();
		main();
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}