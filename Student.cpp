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
}

Student::Student(int _id, string f, string l,char g, string c, string e, string b)
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

Student::~Student()
{
}


void addStudent(sList *&head) {
    std::string id, firstName, lastName, contactNum, email, dob;
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

	addStudentToEnd(head, new sList(studID, firstName, lastName, gender, contactNum, email, dob));

    std::cout << "Student added successfully!\n";
}

void addStudentToEnd(sList *&head, sList *newNode) {
    if (head == NULL) {
        // If the list is empty, set the new node as the head
        head = newNode;
    } else {
        // Traverse to the end of the list
        sList *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Link the new node at the end
        current->next = newNode;
    }

}
// Function to delete a student by name
void deleteStudent(sList *&head) {
    std::string name;
    std::cout << "Enter the full name of the student to delete: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    sList *current = head;
    sList *previous = nullptr;

    while (current != nullptr) {
        if (current->student->getName() == name) {
            if (previous == nullptr) {
                head = current->next; // Deleting the head
            } else {
                previous->next = current->next; // Bypass the current node
            }
            delete current; // Free memory
            std::cout << "Student deleted successfully!\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    std::cout << "Student not found!\n";
}

// Function to display all students in the list
void displayStudents(sList *head) {
    if (head == nullptr) {
        std::cout << "No students in the list.\n";
        return;
    }

    sList *current = head;
    int index = 0; // Start numbering from 1

    cout << "\n--- Student List ---\n";
    while (current != NULL) {
		index++;
        cout << index << ". ";
        cout << current->student->getName(); // Display student details
        cout << endl; // Add a newline for better readability
        current = current->next;
    }
}

// Function to search for a student by ID using linear search
void searchStudent(sList *head) {
    if (head == NULL) {
        std::cout << "No students in the list.\n";
        return;
    }

    int searchID;
    std::cout << "Enter the Student ID to search for: ";
    std::cin >> searchID;

    sList *current = head;

    while (current != NULL) {
        if (current->student->getID() == searchID) { // Compare student ID
            std::cout << "\nStudent Found:\n";
            std::cout << "ID: " << current->student->getID() << std::endl;
            std::cout << "Name: " << current->student->getName() << std::endl;
            std::cout << "Gender: " << current->student->getGender() << std::endl;
            std::cout << "Phone: " << current->student->getContactNum() << std::endl;
            std::cout << "Email: " << current->student->getEmail() << std::endl;
            std::cout << "Date Of Birth: " << current->student->getBday() << std::endl;
            return; // Exit function once found
        }
        current = current->next;
    }

    std::cout << "Student with ID " << searchID << " not found!\n";
}
