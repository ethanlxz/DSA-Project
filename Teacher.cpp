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

void displayTeacher(tList *&head) {
    if (!head) {
        std::cout << "No teachers in the list.\n";
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

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice! Displaying unsorted list.\n";
    } else {
        head = insertionSort(head, choice);  // Perform insertion sort
    }

    // Display sorted teacher list
    tList *current = head;
    int index = 1;
    const int idWidth = 6;
    const int nameWidth = 20;

    // Print the display Teacher List
    std::cout << "-----------------------------------\n";
    std::cout << "| " << std::left << std::setw(idWidth) << "ID" 
              << " | " << std::setw(nameWidth) << "Name"
              << " |\n";
    std::cout << "-----------------------------------\n";

    while (current) {
        std::cout << "| " << std::left << std::setw(idWidth) << current->teacher->getID() 
                  << " | " << std::setw(nameWidth) << current->teacher->getName() 
                  << " |\n";
        current = current->next;
    }

    std::cout << "-----------------------------------\n";
}

// Insertion Sort for sorting the teacher list
tList* insertionSort(tList* head, int option) {
    if (!head || !head->next) return head;  // Empty list or single node

    tList* sorted = nullptr;  // Head of the sorted list
    tList* current = head;  // Traverse the original list

    while (current) {
        tList* nextNode = current->next;  // Save the next node
        sorted = insertSorted(sorted, current, option);
        current = nextNode;
    }

    return sorted;
}

// Insert a node into the sorted linked list
tList* insertSorted(tList* head, tList* newNode, int option) {
    if (!head || compare(head, newNode, option)) {
        newNode->next = head;
        return newNode;
    }

    tList* current = head;
    while (current->next && !compare(current->next, newNode, option)) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Comparison function for sorting
bool compare(tList* a, tList* b, int option) {
    if (option == 1) return a->teacher->getID() > b->teacher->getID(); // ID Ascending
    if (option == 2) return a->teacher->getID() < b->teacher->getID(); // ID Descending
    if (option == 3) return a->teacher->getName() > b->teacher->getName(); // Name Ascending
    if (option == 4) return a->teacher->getName() < b->teacher->getName(); // Name Descending
    return false;
}