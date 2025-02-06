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

    std::string input;
    std::cout << "Enter Student ID or Name to search: ";
    std::cin.ignore(); 
    std::getline(std::cin, input);

    // Check if the input is a number (ID) or a name
    bool isID = std::all_of(input.begin(), input.end(), ::isdigit);

    sList *current = head;
    bool found = false;

    while (current != NULL) {
        if ((isID && std::to_string(current->student->getID()) == input) || 
            (!isID && current->student->getName() == input)) {

            int choice;
            found = true;

            do {
                std::cout << "\n========== Student Profile ==========\n";
                std::cout << "1. ID: " << current->student->getID() << std::endl;
                std::cout << "2. Name: " << current->student->getName() << std::endl;
                std::cout << "3. Gender: " << current->student->getGender() << std::endl;
                std::cout << "4. Phone Number: " << current->student->getContactNum() << std::endl;
                std::cout << "5. Email: " << current->student->getEmail() << std::endl;
                std::cout << "6. Date Of Birth: " << current->student->getBday() << std::endl;

                std::cout << "\nEnter the number you want to edit (2-6) or 0 to return to the menu: ";
                std::cin >> choice;
                std::cin.ignore();  // Ignore newline left in buffer

                switch (choice) {
                    case 0:
                        std::cout << "Returning to menu...\n";
                        return;

                    case 2: { // Edit Name
                        std::string fName, lName;
                        std::cout << "Enter new First Name: ";
                        std::cin >> fName;
                        current->student->setFname(fName);
                        std::cout << "Enter new Last Name: ";
                        std::cin >> lName;
                        current->student->setLname(lName);
                        current->student->setName();
                        break;
                    }

                    case 3: { // Edit Gender
                        char gender;
                        std::cout << "Enter new Gender (M/F): ";
                        std::cin >> gender;
                        current->student->setgender(gender);
                        break;
                    }

                    case 4: { // Edit Contact Number
                        std::string contactNum;
                        std::cout << "Enter new Contact Number: ";
                        std::cin >> contactNum;
                        current->student->setContactNum(contactNum);
                        break;
                    }

                    case 5: { // Edit Email
                        std::string email;
                        std::cout << "Enter new Email: ";
                        std::cin >> email;
                        current->student->setEmail(email);
                        break;
                    }

                    case 6: { // Edit Date of Birth
                        std::string dob;
                        std::cout << "Enter new Date of Birth (DD-MM-YYYY): ";
                        std::cin >> dob;
                        current->student->setBday(dob);
                        break;
                    }

                    default:
                        std::cout << "Invalid choice! Please enter a number between 0 and 6.\n";
                }

            } while (choice != 0);

            std::cout << "Student details updated successfully!\n";
            return;
        }
        current = current->next;
    }

    // If student not found, force user to press 0 to return to menu
    if (!found) {
        int back;
        do {
            std::cout << "Student not found! \nEnter 0 to go back to menu: ";
			cin.ignore();
            std::cin >> back;
        } while (back != 0);
    }
}