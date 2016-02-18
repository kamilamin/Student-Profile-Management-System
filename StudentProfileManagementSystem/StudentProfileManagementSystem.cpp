#include "stdafx.h"
#include<iostream>	// for input and output
#include<conio.h>	//for getting character
#include<iomanip>	//for setting width
#include<stdio.h>	// for seperate build-in functions
#include<fstream>	//for creating files for students
#include<string>	// for string input
using namespace std;

class Student
{
private:
	string fname;			//First name
	string mname;			//Middle name
	string lname, address;	//Last name and address
	string filename;		//Student file name
	char Dept[10];			//Student's department
	int Enroll;				//student's Enrollment Year
	int stdId;				//student's ID
	short age, day, year, month;	//student's DOB

public:
	Student();		//constructor
	~Student();		//destructor
	void Input();	//For registration 
	void Search();	//for searching student's information
	void Edit();	//for editing a current data
	void DisplayAll(); //Displays all  student data
	void Delete();	//delete current student data
};

int main()
{
	string d;
	system("cls");	//clears console screen
	system("Title Student Profile Management System");
	system("color 03");	//set color of text in console
	Student S;
	cout << "\n\n\n\n\t\t	Enter as User or Admin: ";
	cin >> d;
USER:
	{
		if (d == "user")// d == "user")
		{
			int ID;
			cout << "\t\t\tEnter Your ID number: ";
			cin >> ID;
			string id = to_string(ID);
			id.append(".txt");
			ifstream open(id);
			if (open.is_open())
			{
				system("cls");
				cout << "\t\t*********************************************\n";
				cout << "\t\t*		     WELLCOME USER	*\n";
				cout << "\t\t*********************************************\n";
				cout << "\t\t=============================================\n";
				cout << "\t\t     Student Profile Management System\n";
				cout << "\n\t\t\tEnter choices from below: " << endl;
				cout << "1.View an Student Data by ID number " << endl;
				cout << "2.Edit your existing Data " << endl;
				cout << "3.Display all Student." << endl;
				cout << "4.Delete your Personal's Data. " << endl;
				cout << "5.Logout " << endl;
				cout << "6.Exit \n" << endl;
				int choice;
				cout << "\tChoice :";
				cin >> choice;
				switch (choice)
				{
				case 1:
					S.Search();
					getch();
					goto USER;
					break;
				case 2:
					S.Edit();
					goto USER;
					break;
				case 3:
					S.DisplayAll();
					goto USER;
					break;
				case 4:
					S.Delete();
					goto USER;
					break;
				case 5:
					main();
					break;
				default:
					exit(0);
					break;
				}
			}
			else
			{
				cout << "\n\t\t\tYour are not registered.\n\t\t\tPlease contact the Admin\n";
				getch();
				main();
			}
		}
	}
ADMIN:
	{
		if (d == "Admin" || d == "admin")
		{
			system("cls");
			cout << "\t\t*********************************************\n";
			cout << "\t\t*       WELLCOME TO MEGA SOLUTIO8N          *\n";
			cout << "\t\t*********************************************\n";
			cout << "\t\t=============================================\n";
			cout << "\t\t     Student Profile Management System\n";
			cout << "\n\t\t\tEnter choices from below: " << endl;
			cout << "1.Input new Student " << endl;
			cout << "2.View an Student Data by ID number " << endl;
			cout << "3.Edit an existing Student's Data " << endl;
			cout << "4.Display all Student." << endl;
			cout << "5.Delete an existing Student's Data. " << endl;
			cout << "6.Logout " << endl;
			cout << "7.Exit\n" << endl;
			int choice;
			cout << "\tChoice :";
			cin >> choice;
			switch (choice)
			{
			case 1:
				S.Input();
				goto ADMIN;
				break;
			case 2:
				S.Search();
				getch();
				goto ADMIN;
				break;
			case 3:
				S.Edit();
				goto ADMIN;
				break;
			case 4:
				S.DisplayAll();
				goto ADMIN;
				break;
			case 5:
				S.Delete();
				goto ADMIN;
				break;
			case 6:
				main();
				break;
			default:
				exit(0);
				break;
			}
		}
	}
	system("pause");
}

Student::Student()
{
	cout << "\t\t*********************************************\n";
	cout << "\t\t*       WELLCOME TO MEGA SOLUTIO8N          *\n";
	cout << "\t\t*********************************************\n";
	cout << "\t\t=============================================\n";
	cout << "\t\t     Student Profile Management System\n";

}
Student::~Student()
{
}
void Student::Input()
{
	system("cls");	//clears console screen
	system("color 08");	//changes text color
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
	string stdId2 = to_string(stdId);	//changes stdID from int to string
	stdId2.append(".txt");				//adds ".txt" to end ofstring

	ofstream student(stdId2);			//creates student data to text file
	student << fname << " " << mname << " " << lname << " " << stdId << " " << Enroll << " " << age << " " << day << setw(2) << month
		<< " " << year << " " << Dept << endl;	//inputs data to file
	student.close();							//close the created file
	ofstream dir("Directory.txt", ios::app);	//create backup for student's data
	dir << fname << " " << mname << " " << lname << "   " << stdId << "   " << Enroll << " " << age << " " << day << " " << month
		<< " " << year << "  " << Dept << endl;	//inputs data to file
	dir.close();	//closes backup file
}
void Student::Search()
{
	system("cls");
	system("color 06");
	cout << "Enter Student ID number: ";	//needs ID for searching
	cin >> stdId;
	string stdId2 = to_string(stdId);
	stdId2.append(".txt");
	ifstream student(stdId2);
	while (student >> fname >> mname >> lname >> stdId >> Enroll >> age >> day >> month >> year >> Dept)	//Takes the entire data in the file
	{
		int mnameLength = mname.size();	//size of middle name 
		int lnameLength = lname.size(); //size of last name
		int fnameLength = fname.size(); //size of first name
		int TotalLength = fnameLength + mnameLength + lnameLength; // adds the size of name

		string answer;
		cout << "Is this correct Student[y/n] " << endl; // if correct data shown?
		cout << fname << " " << mname << " " << lname << " " << stdId << " " << age << " " << Dept << endl;
		cin >> answer;

		if (answer == "y")	//if yes then perform following
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
			cout << fname << " " << mname << " " << lname << "   " << stdId << "     " << Enroll << "      " << age << "      " << day << "-" << month << "-" << year << "  " << Dept << endl;
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
	ifstream dir("Directory.txt"); //checks backup file and prints all the data available in it.
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
	cout << "Enter Student ID to delete the Data: ";	//File of student to be deleted
	cin >> File;

	string empId = to_string(File);
	empId.append(".txt");
	const char *mycharp = empId.c_str();	//converst string to constant *char

	if (remove(mycharp) != 0)	//if file not available 
		cout << "Remove operation failed" << endl;
	else						//if file available
	{
		cout << File << " is being remove." << endl;
		_sleep(5000);	// time delay for pc
	}
	cout << File << " is Removed\n";
	getch();
}