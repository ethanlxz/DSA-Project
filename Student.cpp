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
void displayStudents(sList *&head) {
    if (!head) {
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

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice! Displaying unsorted list.\n";
    } else {
        head = mergeSort(head, choice); // 调用归并排序
    }

    sList *current = head;
    int index = 1;
    std::cout << "\n--- Student List ---\n";
    while (current) {
        std::cout << index++ << ". " << current->student->getID() 
                  << " - " << current->student->getName() << std::endl;
        current = current->next;
    }
}

// 合并两个已排序的链表
sList* mergeSorted(sList* left, sList* right, int option) {
    if (!left) return right;
    if (!right) return left;

    sList* result = nullptr;

    if (option == 1) { // 按 ID 升序
        if (left->student->getID() <= right->student->getID()) {
            result = left;
            result->next = mergeSorted(left->next, right, option);
        } else {
            result = right;
            result->next = mergeSorted(left, right->next, option);
        }
    } else if (option == 2) { // 按 ID 降序
        if (left->student->getID() >= right->student->getID()) {
            result = left;
            result->next = mergeSorted(left->next, right, option);
        } else {
            result = right;
            result->next = mergeSorted(left, right->next, option);
        }
    } else if (option == 3) { // 按名字升序
        if (left->student->getName() <= right->student->getName()) {
            result = left;
            result->next = mergeSorted(left->next, right, option);
        } else {
            result = right;
            result->next = mergeSorted(left, right->next, option);
        }
    } else if (option == 4) { // 按名字降序
        if (left->student->getName() >= right->student->getName()) {
            result = left;
            result->next = mergeSorted(left->next, right, option);
        } else {
            result = right;
            result->next = mergeSorted(left, right->next, option);
        }
    }
    return result;
}

// 拆分链表
void splitList(sList* source, sList** front, sList** back) {
    if (!source || !source->next) {
        *front = source;
        *back = nullptr;
        return;
    }
    sList* slow = source;
    sList* fast = source->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

// 归并排序
sList* mergeSort(sList* head, int option) {
    if (!head || !head->next) return head;

    sList* left;
    sList* right;
    splitList(head, &left, &right);

    left = mergeSort(left, option);
    right = mergeSort(right, option);

    return mergeSorted(left, right, option);
}