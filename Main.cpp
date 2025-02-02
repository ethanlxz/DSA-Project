#include "Header.hpp"	

int studID = 0;
int teachID = 0;
int totalStudents = 0;
int totalTeachers = 0;

void studentMenu(sList *&student)
{
	int exit = 1;
	while (exit)
	{

		int choice;

		cout << YELLOW;
		cout << "\n========== Student Menu ==========" << endl;
		cout << GREEN;
		cout << "1. Add Student" << endl;
		cout << "2. Remove Student" << endl;
		cout << "3. Display Student" << endl;
		cout << "4. Search Student" << endl;
		cout << "5. Exit" << endl;
		cout << YELLOW;
		cout << "Enter the number you want to go" << endl;
		cout << RESET;
		cin >> choice;
		switch (choice)
		{
		case 1:
			addStudent(student);
			break;
		case 2:
			deleteStudent(student);
			break;
		case 3:
			cout << "Displaying all students" << endl;
			break;
		case 4:
			cout << "Searching for student" << endl;
			break;
		case 5:
			cout << "Exiting student menu." << endl;
			exit = 0;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
}

void menu(sList *&student, tList *&teacher)
{
	int choice;
	while (1)
	{
		cout << YELLOW;
		cout << "  __  __  _        _    ___  _  _   ___ " << endl;
		cout << " |  \\/  |(_) _ _  (_)  / __|| |(_) / __|" << endl;
		cout << " | |\\/| || || ' \\ | | | (__ | || || (__ " << endl;
		cout << " |_|  |_||_||_||_||_|  \\___||_||_| \\___|" << endl;
		cout << "                                        " << endl;
		cout << "Welcome to Mini CliC!" << endl;
		cout << "Please select your role:" << endl;
		cout << GREEN;
		cout << "1. Student" << endl;
		cout << "2. Teacher" << endl;
		cout << "3. Admin" << endl;
		cout << "4. Exit" << endl;
		cout << RESET;
		cin >> choice;
		switch (choice)
		{
		case 1:
			studentMenu(student);
			break;
		case 2:
			cout << "Teacher Menu" << endl;
			break;
		case 3:
			cout << "Admin Menu" << endl;
			break;
		}
		if (choice == 4)
			break;
	}
}

int main()
{
	sList *student = nullptr;
	tList *teacher = nullptr;

	menu(student, teacher);
}