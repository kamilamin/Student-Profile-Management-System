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
	int Enroll;
	int stdId;
	int age,day,year,month;
	
public:
	Student();
	~Student();
	void Input()
	{
		system("cls");
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

		string stdId2 = to_string(stdId);
		stdId2.append(".txt");

		ofstream newemployee(stdId2);
		newemployee << fname << " " << mname << " " << lname << " " << stdId << " " << Enroll << " " << age << setw(8) << day << setw(2) << month
					<< setw(2) << year << endl;
		newemployee.close();
		ofstream dir("Directory.txt", ios::app);
		dir << fname << " " << mname << " " << lname << " " << stdId << " " << Enroll << " " << age << " " << day << setw(2) << month
			<< setw(2) << year << endl; dir.close();
	}
	void Search()
	{
		system("cls");
		//	int thrw;
		cout << "Enter Employee ID number: ";
		cin >> stdId;
		string stdId2 = to_string(stdId);
		stdId2.append(".txt");
		ifstream employee(stdId2);
		while (employee >> fname >> mname >> lname >> stdId >> Enroll >> age >> day >> month >> year)
		{
			int mnameLength = mname.size();
			int lnameLength = lname.size();
			int fnameLength = fname.size();
			int TotalLength = fnameLength + mnameLength + lnameLength;

			string answer;
			cout << "Is this correct Employee[y/n] " << endl;
			cout << fname << " " << mname << " " << lname << " " << stdId  << " " << age << endl;
			cin >> answer;

			if (answer == "y")
			{
				system("cls");
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

				cout << "Enrolled   Age   Date of Birth" << endl;
				for (int y = 1; y < TotalLength + 20; y++)
				{
					cout << "--";
				}

				cout << " " << endl;
				cout << fname << " " << mname << " " << lname << " " << setw(3) << stdId << setw(3) << " " << Enroll << "      " << age << "    " << day << "-" << month << "-" << year << endl;
			}
		}
	}
	void Edit()
	{
		system("cls");
		string newfname;
		string newmname;
		string newlname;
		string decision;
		string filename;
		double salary, newsalary;
		int age, newage;
		//int thrw;

		cout << "Enter the Employee Number, whose data you want to edit: ";
		cin >> stdId;

		string stdId2 = to_string(stdId);
		stdId2.append(".txt");

		ifstream employee1(stdId2);
		while (employee1 >> fname >> mname >> lname >> stdId >> salary >> age)
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

				cout << "Age ";
				for (int z = 1; z < 2; z++)
				{
					cout << " ";
				}

				cout << "Salary ";
				cout << "ID# " << endl;
				for (int y = 1; y < TotalLength + 20; y++)
				{
					cout << "-";
				}
				cout << " " << endl;
				cout << fname << " " << mname << " " << lname << " " << age << "   " << salary << "  " << stdId << endl;

				cout << "Enter new First Name:";
				cin >> newfname;
				cout << "Enter new Middle Name:";
				cin >> newmname;
				cout << "Enter new last Name:";
				cin >> newlname;
				cout << "Enter new Age:";
				cin >> newage;
				cout << "Enter new Salary:";
				cin >> newsalary;
			}
			if (decision == "n")

			employee1.close();
			ofstream employee2(stdId2);
			employee2 << newfname << newmname << newlname << stdId << newsalary << newage << endl;
			employee2.close();
		}

	}
	void DisplayAll()
	{
		system("cls");
		cout << "Entire Employee Database " << endl;
		cout << "------------------------ " << endl;
		ifstream dir("Directory.txt");
		while (dir >> fname >> mname >> lname >> age >> stdId >> Enroll)
		{
			cout << fname << " " << mname << " " << lname << " " << age << " " << Enroll << " " << stdId << endl;
		}
		system("Pause");
	}
	void Delete()
	{
		system("cls");
		int File;
		cout << "Enter Employee ID to delete the Data: ";
		cin >> File;

		string empId = to_string(File);
		empId.append(".txt");
		const char *mycharp = empId.c_str();

		if (remove(mycharp) != 0)
			cout << "Remove operation failed" << endl;
		else
		{
			_sleep(5000);
			cout << File << " has been removed." << endl;
		}
		
	}
};

Student::Student()
{
}

Student::~Student()
{
}
int main()
{
	system("cls");
	system("Title Employee Database program");
	system("color 03");
	cout << "\n\t\t\tEnter choices from below: " << endl;
	cout << "1.Input new Employee " << endl;
	cout << "2.View an Employee Data by ID number " << endl;
	cout << "3.Edit an existing Employee Data " << endl;
	cout << "4.Display all Employee." << endl;
	cout << "5.Delete an existing Employee Data. " << endl;
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
}

