#include "Header.hpp"

int studID = 1;
int teacherID = 0;
int totalStudents = 0;
int totalTeachers = 0;

void create10Student(sList *&head)
{
	for (int i = 0; i < 10; i++)
	{
		addStudentToEnd(head, new sList(studID, "test", "student", 'M', "0123-3455", "test@gmail.com", "12-12-2000"));
		studID++;
		totalStudents++;
	}
}

void create10Teacher(tList *&head)
{
	for (int i = 0; i < 10; i++)
	{
		addTeacherToEnd(head, new tList(studID, "test", "teacher", 'M', "0123-3455", "test@gmail.com", "12-12-2000"));
		teacherID++;
		totalTeachers++;
	}
}

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
			displayStudents(student);
			break;
		case 4:
			searchStudent(student);
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

void teacherMenu(tList *&teacher)
{
	int exit = 1;
	while (exit)
	{

		int choice;

		cout << YELLOW;
		cout << "\n========== Teacher Menu ==========" << endl;
		cout << GREEN;
		cout << "1. Add Teacher" << endl;
		cout << "2. Remove Teacher" << endl;
		cout << "3. Display Teacher" << endl;
		cout << "4. Search Teacher" << endl;
		cout << "5. Exit" << endl;
		cout << YELLOW;
		cout << "Enter the number you want to go" << endl;
		cout << RESET;
		cin >> choice;
		switch (choice)
		{
		case 1:
			addTeacher(teacher);
			break;
		case 2:
			deleteTeacher(teacher);
			break;
		case 3:
			cout << "Displaying all teachers" << endl;
			break;
		case 4:
			searchTeacher(teacher);
			break;
		case 5:
			cout << "Exiting teacher menu." << endl;
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
			teacherMenu(teacher);
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
	sList *student = NULL;
	tList *teacher = NULL;

	create10Student(student);
	create10Teacher(teacher);

	menu(student, teacher);
}