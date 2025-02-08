#include "Header.hpp"

Teacher::Teacher()
{
	id = 0;
	fname = "default";
	lname = "default";
	gender = 'M';
	name = "default teacher";
	contactNum = "000-0000000";
	email = "default@gmail.com";
	bday = "00-00-0000";
}

Teacher::Teacher(int _id, string f, string l, char g, string c, string e, string b)
{
	id = _id;
	fname = f;
	lname = l;
	gender = g;
	name = f + " " + l;
	contactNum = c;
	email = e;
	bday = b;
}

Teacher::~Teacher()
{
}

// Function to add a new teacher
void addTeacher(tList *&head)
{
	string firstName, lastName, contactNum, email, dob;
	char gender;

	teacherID++;
	totalTeachers++;

	cout << "Enter First Name: ";
	cin >> firstName;
	cout << "Enter Last Name: ";
	cin >> lastName;
	cout << "Enter Gender (M/F): ";
	cin >> gender;
	cout << "Enter Phone Number: ";
	cin >> contactNum;
	cout << "Enter Email: ";
	cin >> email;
	cout << "Enter Date Of Birth (DD-MM-YYYY): ";
	cin.ignore(); // To ignore the newline character left in the buffer
	getline(cin, dob);

	addTeacherToEnd(head, new tList(teacherID, firstName, lastName, gender, contactNum, email, dob));

	cout << GREEN << "Teacher added successfully!\n"
		 << WHITE;
}

// Function to add a new teacher node to the end of the list
void addTeacherToEnd(tList *&head, tList *newNode)
{
	if (head == nullptr)
	{
		// If the list is empty, set the new node as the head
		head = newNode;
	}
	else
	{
		// Traverse to the end of the list
		tList *current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		// Link the new node at the end
		current->next = newNode;
	}
}

// Function to delete a teacher by name
void deleteTeacher(tList *&head)
{
	string name;
	cout << "Enter the full name of the teacher to delete: ";
	cin.ignore();
	getline(cin, name);

	tList *current = head;
	tList *previous = nullptr;

	while (current != nullptr)
	{
		// Check if the current teacher's name matches the input name
		if (current->teacher->getName() == name)
		{
			if (previous == nullptr)
			{
				head = current->next;
			}
			else
			{
				// Bypass the current node
				previous->next = current->next;
			}
			delete current;
			cout << "Teacher deleted successfully!\n";
			return; // Exit the function after deletion
		}
		previous = current; // Move to the next node
		current = current->next;
	}
	cout << "Teacher not found!\n";
}

// Function to search for a teacher by ID using linear search
void searchTeacher(tList *head)
{
	if (head == NULL)
	{
		int input;
		cout << RED "No teachers in the list. Press any key to return :" << WHITE;
		cin >> input;
		return;
	}

	string input;
	cout << "Enter Teacher ID or Name to search: ";
	cin.ignore();
	getline(cin, input);

	tList *current = head;
	bool found = false;

	while (current != nullptr)
	{
		if ((to_string(current->teacher->getID()) == input) ||
			(current->teacher->getName() == input))
		{

			int choice;
			found = true;

			do
			{
				cout << YELLOW;
				cout << "\n========== Teacher Profile ==========\n";
				cout << GREEN;
				cout << "1. ID: " << current->teacher->getID() << endl;
				cout << "2. Name: " << current->teacher->getName() << endl;
				cout << "3. Gender: " << current->teacher->getGender() << endl;
				cout << "4. Phone Number: " << current->teacher->getContactNum() << endl;
				cout << "5. Email: " << current->teacher->getEmail() << endl;
				cout << "6. Date Of Birth: " << current->teacher->getBday() << endl;

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
					cin >> fName;
					current->teacher->setFname(fName);
					cout << "Enter new Last Name: ";
					cin >> lName;
					current->teacher->setLname(lName);
					current->teacher->setName(); // Update full name
					break;
				}

				case 3:
				{ // Edit Gender
					char gender;
					cout << "Enter new Gender (M/F): ";
					cin >> gender;
					current->teacher->setgender(gender);
					break;
				}

				case 4:
				{ // Edit Contact Number
					string contactNum;
					cout << "Enter new Contact Number: ";
					cin >> contactNum;
					current->teacher->setContactNum(contactNum);
					break;
				}

				case 5:
				{ // Edit Email
					string email;
					cout << "Enter new Email: ";
					cin >> email;
					current->teacher->setEmail(email);
					break;
				}

				case 6:
				{ // Edit Date of Birth
					string dob;
					cout << "Enter new Date of Birth (DD-MM-YYYY): ";
					cin >> dob;
					current->teacher->setBday(dob);
					break;
				}

				default:
					cout << RED << "Invalid choice! Please enter a number between 0 and 6.\n"
						 << WHITE;
				}

			} while (choice != 0);

			cout << GREEN << "Teacher details updated successfully!\n"
				 << WHITE;
			return;
		}
		current = current->next;
	}

	// If teacher not found, force user to press 0 to return to menu
	if (!found)
	{
		int back;
		cout << RED << "Teacher not found! \nEnter 0 to go back to menu: " << WHITE;
		cin >> back;
		return;
	}
}

// Function to display all teachers in the list
void displayTeacher(tList *&head)
{
	if (head == NULL)
	{
		int input;
		cout << RED "No teachers in the list. Press any key to return :" << WHITE;
		cin >> input;
		return;
	}

	while (1)
	{
	int choice;
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
		std::cout << RED <<"Invalid choice! Try again.\n" << WHITE;
	}
	else
	{
		head = insertionSort(head, choice); // Perform insertion sort
		break;
	}
	}

	// Display sorted teacher list
	tList *current = head;
	int index = 1;
	const int idWidth = 6;
	const int nameWidth = 20;

	// Print the display Teacher List
	cout << YELLOW;
	std::cout << "-----------------------------------\n";
	std::cout << "| " << std::left << std::setw(idWidth) << "ID"
			  << " | " << std::setw(nameWidth) << "Name"
			  << " |\n";
	std::cout << "-----------------------------------\n";
	std::cout << GREEN;

	while (current)
	{
		std::cout << "| " << std::left << std::setw(idWidth) << current->teacher->getID()
				  << " | " << std::setw(nameWidth) << current->teacher->getName()
				  << " |\n";
		current = current->next;
	}

	std::cout << "-----------------------------------\n";

	int input;
	std::cout << YELLOW << "\nPress any key to return : " << WHITE;
	cin >> input;
	return;
}