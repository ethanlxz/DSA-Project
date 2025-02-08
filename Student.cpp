#include "Header.hpp"

Student::Student()
{
	id = 0;
	fname = "default";
	lname = "default";
	gender = 'M';
	name = "default student";
	contactNum = "000-0000000";
	email = "default@gmail.com";
	bday = "00-00-0000";
	major = "default";
}

Student::Student(int _id, string f, string l, char g, string c, string e, string b, string major_)
{
	id = _id;
	fname = f;
	lname = l;
	gender = g;
	name = f + " " + l;
	contactNum = c;
	email = e;
	bday = b;
	major = major_;
}

string Student::getMajor()
{
	return major;
}

void Student::setMajor(string m)
{
	major = m;
}

Student::~Student()
{
}

void addStudent(sList *&head)
{
	std::string id, firstName, lastName, contactNum, email, dob, major;
	char gender;

	cout << "Enter First Name: ";
	getline(cin, firstName);
	cin.ignore();
	cout << "Enter Last Name: ";
	getline(cin, lastName);
	cin.ignore();
	cout << "Enter Gender (M/F): ";
	cin >> gender;
	cin.ignore();
	cout << "Enter Phone Number: ";
	getline(cin, contactNum);
	cin.ignore();
	cout << "Enter Email: ";
	getline(cin, email);
	cin.ignore();
	cout << "Enter Date Of Birth (DD-MM-YYYY): ";
	cin.ignore(); // To ignore the newline character left in the buffer
	getline(cin, dob);
	cout << "Enter your major: "; // To ignore the newline character left in the buffer
	getline(cin, major);

	addStudentToEnd(head, new sList(studID, firstName, lastName, gender, contactNum, email, dob, major));

	std::cout << "Student added successfully!\n";
	studID++;
	totalStudents++;
}

void addStudentToEnd(sList *&head, sList *newNode)
{
	if (head == NULL)
	{
		// If the list is empty, set the new node as the head
		head = newNode;
	}
	else
	{
		// Traverse to the end of the list
		sList *current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		// Link the new node at the end
		current->next = newNode;
	}
}
// Function to delete a student by name
void deleteStudent(sList *&head)
{
	int input;
	string name;
	cout << YELLOW << "Enter the full name / ID of the student to delete: " << WHITE; // Ask for the name of the student to delete
	cin.ignore();
	getline(cin, name);

	sList *current = head;
	sList *previous = nullptr;

	while (current != nullptr)
	{
		if (current->student->getName() == name || (to_string(current->student->getID()) == name))
		{
			if (previous == nullptr)
			{
				head = current->next; // Deleting the head
			}
			else
			{
				previous->next = current->next; // Bypass the current node
			}
			delete current; // Free memory
			cout << RED << "Student deleted successfully! Press any key to return\n" << WHITE;
			cin >> input;
			return;
		}
		previous = current;
		current = current->next;
	}
	cout << "Student not found!\n";
}

// Function to search for a student by ID using linear search
void searchStudent(sList *head)
{
	if (head == NULL)
	{
		int input;
		cout << RED "No students in the list. Press any key to return\n"
			 << WHITE;
		cin >> input;
		return;
	}

	string input;
	cout << "Enter Student ID or Name to search: ";
	cin.ignore();
	getline(cin, input);

	// Check if the input is a number (ID) or a name
	bool isID = all_of(input.begin(), input.end(), ::isdigit);

	sList *current = head;
	bool found = false;

	while (current != NULL)
	{
		if ((to_string(current->student->getID()) == input) ||
			(current->student->getName() == input))
		{

			int choice;
			found = true;

			do
			{
				cout << YELLOW;
				cout << "\n========== Student Profile ==========\n";
				cout << GREEN;
				cout << "1. ID: " << current->student->getID() << endl;
				cout << "2. Name: " << current->student->getName() << endl;
				cout << "3. Gender: " << current->student->getGender() << endl;
				cout << "4. Phone Number: " << current->student->getContactNum() << endl;
				cout << "5. Email: " << current->student->getEmail() << endl;
				cout << "6. Date Of Birth: " << current->student->getBday() << endl;
				cout << "7. Major: " << current->student->getMajor() << endl;

				cout << YELLOW;
				cout << "\nEnter the number you want to edit (2-6) or 0 to return to the menu: " << WHITE;
				cin >> choice;
				cin.ignore(); // Ignore newline left in buffer

				switch (choice)
				{
				case 0:
					cout << RED << "Returning to menu...\n"
						 << WHITE;
					return;

				case 2:
				{ // Edit Name
					string fName, lName;
					cout << "Enter new First Name: ";
					getline(cin, fName);
					current->student->setFname(fName);
					cout << "Enter new Last Name: ";
					getline(cin, lName);
					current->student->setLname(lName);
					current->student->setName();
					break;
				}

				case 3:
				{ // Edit Gender
					char gender;
					cout << "Enter new Gender (M/F): ";
					cin >> gender;
					current->student->setgender(gender);
					break;
				}

				case 4:
				{ // Edit Contact Number
					string contactNum;
					cout << "Enter new Contact Number: ";
					getline(cin, contactNum);
					current->student->setContactNum(contactNum);
					break;
				}

				case 5:
				{ // Edit Email
					string email;
					cout << "Enter new Email: ";
					getline(cin, email);
					current->student->setEmail(email);
					break;
				}

				case 6:
				{ // Edit Date of Birth
					string dob;
					cout << "Enter new Date of Birth (DD-MM-YYYY): ";
					getline(cin, dob);
					current->student->setBday(dob);
					break;
				}

				case 7:
				{ // Edit Major
					string major;
					cout << "Enter new Major: ";
					getline(cin, major);
					current->student->setMajor(major);
					break;
				}

				default:
					cout << RED << "Invalid choice! Please enter a number between 0 and 6.\n"
						 << WHITE;
				}

			} while (choice != 0);

			cout << GREEN << "Student details updated successfully!\n"
				 << WHITE;
			return;
		}
		current = current->next;
	}

	// If student not found, force user to press 0 to return to menu
	if (!found)
	{
		int back;

		cout << RED << "Student not found! \nPress any key to return." << WHITE;
		cin.ignore();
		cin >> back;
		return;
	}
}

// Function to display all students in the list
void displayStudents(sList *head)
{
	if (head == NULL)
	{
		int input;
		cout << RED "No students in the list. Press any key to return :" << WHITE;
		cin >> input;
		return;
	}

	int choice;
	while (1)
	{
		cout << YELLOW;
		std::cout << "\nSelect sorting option:\n";
		cout << GREEN;
		std::cout << "1. ID Ascending\n";
		std::cout << "2. ID Descending\n";
		std::cout << "3. Name Ascending\n";
		std::cout << "4. Name Descending\n";
		cout << YELLOW;
		std::cout << "Enter choice (1-4) or 0 to go back: " << WHITE;
		std::cin >> choice;

		if (choice == 0)
			return;
		else if (choice < 1 || choice > 4)
		{
			std::cout << RED << "Invalid choice! Try again.\n"<< WHITE;
		}
		else
		{
			head = mergeSort(head, choice); // Perform Merge Sort
			break;
		}
	}

	sList *current = head;
	int index = 1;
	const int idWidth = 6;
	const int nameWidth = 20;

	// Print the output of the display student list
	std::cout << YELLOW;
	std::cout << "-----------------------------------\n";
	std::cout << "| " << std::left << std::setw(idWidth) << "ID"
			  << " | " << std::setw(nameWidth) << "Name"
			  << " |\n";
	std::cout << "-----------------------------------\n";
	std::cout << GREEN;

	while (current)
	{
		std::cout << "| " << std::left << std::setw(idWidth) << current->student->getID()
				  << " | " << std::setw(nameWidth) << current->student->getName()
				  << " |\n";
		current = current->next;
	}

	std::cout << "-----------------------------------\n";

	int input;
	std::cout << "\nPress any key to return : " << WHITE;
	cin >> input;
	return;
}