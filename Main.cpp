#include "Header.hpp"

int studID = 1;
int teacherID = 1;
int totalStudents = 0;
int totalTeachers = 0;

void create10Student(sList *&head)
{
	string firstNames[10] = {"Ethan", "Alex", "Cheah", "Law", "Charlie", "Diana", "Dickson", "Fiona", "George", "Hannah"};
    string lastNames[10] = {"Law", "Tew", "Xiao You", "Yong Soon", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
	for (int i = 0; i < 10; i++)
	{
		addStudentToEnd(head, new sList(studID, firstNames[i],  lastNames[i], 'M', "0123-3455", "test@gmail.com", "12-12-2000", "Diploma in IT"));
		studID++;
		totalStudents++;
	}
}

void create10Teacher(tList *&head)
{
	string firstNames[10] = {"Ethan", "Alex", "Cheah", "Law", "Charlie", "Diana", "Dickson", "Fiona", "George", "Hannah"};
    string lastNames[10] = {"Law", "Tew", "Xiao You", "Yong Soon", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

	for (int i = 0; i < 10; i++)
	{
		addTeacherToEnd(head, new tList(teacherID, firstNames[i], lastNames[i], 'M', "0123-3455", "test@gmail.com", "12-12-2000"));
		teacherID++;
		totalTeachers++;
	}
}

void studentMenu(sList *&student, Admin &admin)
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
		cout << "4. Search/Edit Student" << endl;
		cout << "5. Submit Ticket" << endl;
		cout << "6. Exit" << endl;
		cout << YELLOW;
		cout << "Enter your option (1-6)" << endl;
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
			submitTicket(admin, "Student");
			break;
		case 6:
			exit = 0;
			break;
		default:
			cout << RED <<"Invalid choice. Please try again." << WHITE << endl;
			break;
		}
	}
}

void teacherMenu(tList *&teacher, Admin &admin)
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
		cout << "4. Search/Exit Teacher" << endl;
		cout << "5. Submit Ticket" << endl;
		cout << "6. Exit" << endl;
		cout << YELLOW;
		cout << "Enter your option (1-6)" << endl;
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
			displayTeacher(teacher);
			break;
		case 4:
			searchTeacher(teacher);
			break;
		case 5:
			submitTicket(admin, "Teacher");
		case 6:
			exit = 0;
			break;

		default:
			cout << RED <<"Invalid choice. Please try again." << WHITE << endl;
			break;
		}
	}
}

void adminMenu(Admin &admin) {
    int exit = 1;
    while (exit) {
        int choice;
        cout << YELLOW;
        cout << "\n========== Admin Menu ==========\n";
        cout << GREEN;
        cout << "1. View Problem\n";
        cout << "2. Solve Problem\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cout << YELLOW;
        cin >> choice;
        cout << RESET;

        switch (choice) {
            case 1: 
                admin.viewProblem(); 
                break;
            case 2: 
                admin.solveProblem(); 
                break;
            case 3: 
                exit = 0; 
                break;
            default: 
                cout << RED << "Invalid choice. Please try again.\n" << WHITE; 
                break;
        }
    }
}


void menu(sList *&student, tList *&teacher, Admin &admin)
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
			studentMenu(student,admin);
			break;
		case 2:
			teacherMenu(teacher,admin);
			break;
		case 3:
			adminMenu(admin);
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

	Admin admin;

	create10Student(student);
	create10Teacher(teacher);

	menu(student, teacher, admin);
}