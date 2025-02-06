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
void addTeacher(tList *&head) {
    std::string firstName, lastName, contactNum, email, dob;
    char gender;

    teacherID++;
    totalTeachers++;

    std::cout << "Enter First Name: ";
    std::cin >> firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;
    std::cout << "Enter Gender (M/F): ";
    std::cin >> gender;
    std::cout << "Enter Phone Number: ";
    std::cin >> contactNum;
    std::cout << "Enter Email: ";
    std::cin >> email;
    std::cout << "Enter Date Of Birth (DD-MM-YYYY): ";
    std::cin.ignore(); // To ignore the newline character left in the buffer
    std::getline(std::cin, dob);

    addTeacherToEnd(head, new tList(teacherID, firstName, lastName, gender, contactNum, email, dob));

    std::cout << "Teacher added successfully!\n";
}


// Function to add a new teacher node to the end of the list
void addTeacherToEnd(tList *&head, tList *newNode) {
    if (head == nullptr) {
        // If the list is empty, set the new node as the head
        head = newNode;
    } else {
        // Traverse to the end of the list
        tList *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Link the new node at the end
        current->next = newNode;
    }
}

// Function to delete a teacher by name
void deleteTeacher(tList *&head) {
    std::string name;
    std::cout << "Enter the full name of the teacher to delete: ";
    std::cin.ignore(); 
    std::getline(std::cin, name); 

    tList *current = head; 
    tList *previous = nullptr; 

    while (current != nullptr) {
        // Check if the current teacher's name matches the input name
        if (current->teacher->getName() == name) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                // Bypass the current node
                previous->next = current->next;
            }
            delete current; 
            std::cout << "Teacher deleted successfully!\n";
            return; // Exit the function after deletion
        }
        previous = current; // Move to the next node
        current = current->next;
    }
    std::cout << "Teacher not found!\n"; 
}

// Function to search for a teacher by ID using linear search
void searchTeacher(tList *head) {
    if (head == nullptr) {
        std::cout << "No teachers in the list.\n";
        return;
    }

    std::string input;
    std::cout << "Enter Teacher ID or Name to search: ";
    std::cin.ignore(); 
    std::getline(std::cin, input);

    // Check if input is a number (ID) or a name
    bool isID = std::all_of(input.begin(), input.end(), ::isdigit);

    tList *current = head;
    bool found = false;

    while (current != nullptr) {
        if ((isID && std::to_string(current->teacher->getID()) == input) || 
            (!isID && current->teacher->getName() == input)) {

            int choice;
            found = true;

            do {
                std::cout << "\n========== Teacher Profile ==========\n";
                std::cout << "1. ID: " << current->teacher->getID() << std::endl;
                std::cout << "2. Name: " << current->teacher->getName() << std::endl;
                std::cout << "3. Gender: " << current->teacher->getGender() << std::endl;
                std::cout << "4. Phone Number: " << current->teacher->getContactNum() << std::endl;
                std::cout << "5. Email: " << current->teacher->getEmail() << std::endl;
                std::cout << "6. Date Of Birth: " << current->teacher->getBday() << std::endl;

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
                        current->teacher->setFname(fName);
                        std::cout << "Enter new Last Name: ";
                        std::cin >> lName;
                        current->teacher->setLname(lName);
                        current->teacher->setName(); // Update full name
                        break;
                    }

                    case 3: { // Edit Gender
                        char gender;
                        std::cout << "Enter new Gender (M/F): ";
                        std::cin >> gender;
                        current->teacher->setgender(gender);
                        break;
                    }

                    case 4: { // Edit Contact Number
                        std::string contactNum;
                        std::cout << "Enter new Contact Number: ";
                        std::cin >> contactNum;
                        current->teacher->setContactNum(contactNum);
                        break;
                    }

                    case 5: { // Edit Email
                        std::string email;
                        std::cout << "Enter new Email: ";
                        std::cin >> email;
                        current->teacher->setEmail(email);
                        break;
                    }

                    case 6: { // Edit Date of Birth
                        std::string dob;
                        std::cout << "Enter new Date of Birth (DD-MM-YYYY): ";
                        std::cin >> dob;
                        current->teacher->setBday(dob);
                        break;
                    }

                    default:
                        std::cout << "Invalid choice! Please enter a number between 0 and 6.\n";
                }

            } while (choice != 0);

            std::cout << "Teacher details updated successfully!\n";
            return;
        }
        current = current->next;
    }

    // If teacher not found, force user to press 0 to return to menu
    if (!found) {
        int back;
        do {
            std::cout << "Teacher not found! \nEnter 0 to go back to menu: ";
            std::cin >> back;
        } while (back != 0);
    }
}