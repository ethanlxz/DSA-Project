#include "./Header.hpp"

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

Student::~Student()
{
}

string Student::getMajor() {
	return major;
}

void addStudent(sList *&head)
{
	std::string id, firstName, lastName, contactNum, email, dob, major;
	char gender;

	studID++;
	totalStudents++;

	std::cout << "Enter First Name: ";
	std::cin >> firstName;
	std::cin.ignore();
	std::cout << "Enter Last Name: ";
	std::cin >> lastName;
	std::cin.ignore();
	std::cout << "Enter Gender (M/F): ";
	std::cin >> gender;
	std::cin.ignore();
	std::cout << "Enter Phone Number: ";
	std::cin >> contactNum;
	std::cin.ignore();
	std::cout << "Enter Email: ";
	std::cin >> email;
	std::cin.ignore();
	std::cout << "Enter Date Of Birth (DD-MM-YYYY): ";
	std::cin.ignore(); // To ignore the newline character left in the buffer
	std::getline(std::cin, dob);
	std::cout << "Enter your major: ";
	std::cin.ignore(); // To ignore the newline character left in the buffer
	std::getline(std::cin, major);

	addStudentToEnd(head, new sList(studID, firstName, lastName, gender, contactNum, email, dob, major));

	std::cout << "Student added successfully!\n";
}

void addStudentToEnd(sList *&head, sList *newNode)
{
	if (head == NULL)  // If the list is empty, set the new node as the head
		head = newNode;
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
	std::string name;
	std::cout << "Enter the full name of the student to delete: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	sList *current = head;
	sList *previous = nullptr;

	while (current != nullptr)
	{
		if (current->student->getName() == name)
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
			std::cout << "Student deleted successfully!\n";
			totalStudents--;
			return;
		}
		previous = current;
		current = current->next;
	}
	std::cout << "Student not found!\n";
}

void editStudent(sList *&head, int id) {
    sList *current = head;
    while (current) {
        if (current->student->getID() == id) {
            std::cout << "\nEditing Student: " << current->student->getName() << "\n";

            int editChoice;
            std::cout << "Choose the information to edit:\n";
            std::cout << "1. First Name\n";
            std::cout << "2. Last Name\n";
            std::cout << "3. Gender\n";
            std::cout << "4. Phone Number\n";
            std::cout << "5. Email\n";
            std::cout << "6. Date of Birth\n";
            std::cout << "7. Major\n";
            std::cout << "Enter choice: ";
            std::cin >> editChoice;

            std::string newInput;
            char newGender;
            switch (editChoice) {
                case 1: // First Name
                    std::cout << "Enter new First Name: ";
                    std::cin >> newInput;
                    current->student->setFname(newInput);
                    break;
                case 2: // Last Name
                    std::cout << "Enter new Last Name: ";
                    std::cin >> newInput;
                    current->student->setLname(newInput);
                    break;
                case 3: // Gender
                    std::cout << "Enter new Gender (M/F): ";
                    std::cin >> newGender;
                    current->student->setgender(newGender);
                    break;
                case 4: // Phone Number
                    std::cout << "Enter new Phone Number: ";
                    std::cin >> newInput;
                    current->student->setContactNum(newInput);
                    break;
                case 5: // Email
                    std::cout << "Enter new Email: ";
                    std::cin >> newInput;
                    current->student->setEmail(newInput);
                    break;
                case 6: // Date of Birth
                    std::cout << "Enter new Date of Birth (DD-MM-YYYY): ";
                    std::cin >> newInput;
                    current->student->setBday(newInput);
                    break;
                case 7: // Major
                    std::cout << "Enter new Major: ";
                    std::cin >> newInput;
                    // You should add a method to set major if necessary
                    // current->student->setMajor(newInput);
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }

            std::cout << "Student information updated successfully.\n";
            return;
        }
        current = current->next;
    }

    std::cout << "Student not found!\n";
}

// Function to display all students in the list
void displayStudents(sList *&head)
{
	if (!head)
	{
		std::cout << "No students in the list.\n";
		return;
	}

	int choice;
	std::cout << "\nSelect sorting option:\n";
	std::cout << "1. ID Ascending\n";
	std::cout << "2. ID Descending\n";
	std::cout << "3. Name Ascending\n";
	std::cout << "4. Name Descending\n";
	std::cout << "Enter choice: ";
	std::cin >> choice;

	if (choice < 1 || choice > 4)
	{
		std::cout << "Invalid choice! Displaying unsorted list.\n";
	}
	else
	{
		head = mergeSort(head, choice); // Perform Merge Sort
	}

	sList *current = head;
	int index = 1;
    const int idWidth = 6;
    const int nameWidth = 20;

    // Print the output of the display student list
    std::cout << "-----------------------------------\n";
    std::cout << "| " << std::left << std::setw(idWidth) << "ID" 
              << " | " << std::setw(nameWidth) << "Name"
              << " |\n";
    std::cout << "-----------------------------------\n";

    while (current) {
        std::cout << "| " << std::left << std::setw(idWidth) << current->student->getID() 
                  << " | " << std::setw(nameWidth) << current->student->getName() 
                  << " |\n";
        current = current->next;
    }

    std::cout << "-----------------------------------\n";

	int input;
    std::cout << "\nPress any key to return ";
	cin >> input;
	return;
}

// Merge the Sort
sList *mergeSorted(sList *left, sList *right, int option)
{
	if (!left)
		return right;
	if (!right)
		return left;

	sList *result = nullptr;

	if (option == 1)
	{ // Sort the Id accendingly
		if (left->student->getID() <= right->student->getID())
		{
			result = left;
			result->next = mergeSorted(left->next, right, option);
		}
		else
		{
			result = right;
			result->next = mergeSorted(left, right->next, option);
		}
	}
	else if (option == 2)
	{ // Sort the ID descendingly
		if (left->student->getID() >= right->student->getID())
		{
			result = left;
			result->next = mergeSorted(left->next, right, option);
		}
		else
		{
			result = right;
			result->next = mergeSorted(left, right->next, option);
		}
	}
	else if (option == 3)
	{ // Sort the Name accendingly
		if (left->student->getName() <= right->student->getName())
		{
			result = left;
			result->next = mergeSorted(left->next, right, option);
		}
		else
		{
			result = right;
			result->next = mergeSorted(left, right->next, option);
		}
	}
	else if (option == 4)
	{ // Sort the Name descendingly
		if (left->student->getName() >= right->student->getName())
		{
			result = left;
			result->next = mergeSorted(left->next, right, option);
		}
		else
		{
			result = right;
			result->next = mergeSorted(left, right->next, option);
		}
	}
	return result;
}

// split the list
void splitList(sList *source, sList **front, sList **back)
{
	if (!source || !source->next)
	{
		*front = source;
		*back = nullptr;
		return;
	}
	sList *slow = source;
	sList *fast = source->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	*front = source;
	*back = slow->next;
	slow->next = nullptr;
}

// merge the whole sort
sList *mergeSort(sList *head, int option)
{
	if (!head || !head->next)
		return head;

	sList *left;
	sList *right;
	splitList(head, &left, &right);

	left = mergeSort(left, option);
	right = mergeSort(right, option);

	return mergeSorted(left, right, option);
}