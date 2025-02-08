#include "Header.hpp"

// Constructor for ADTqueue, initializes an empty queue
ADTqueue::ADTqueue()
{
	front_ = rear = NULL;
	count = 0;
}

// Checks if the queue is empty
bool ADTqueue::empty()
{
	return (front_ == NULL);
}

// Adds a new problem ticket to the queue
void ADTqueue::append(int id, const string &role, const string &problem)
{
	node *newNode = new node{id, role, problem, NULL};
	if (rear != NULL)
	{
		rear->next = newNode;
		rear = newNode;
	}
	else
	{
		front_ = rear = newNode;
	}
	count++;
}

// Removes the front problem ticket from the queue (serves the request)
void ADTqueue::serve()
{
	if (!empty())
	{
		node *temp = front_;
		front_ = front_->next;
		delete temp;
		count--;
		if (front_ == NULL)
			rear = NULL;
	}
}

// Returns the number of problem tickets in the queue
int ADTqueue::size()
{
	return count;
}

// Retrieves the problem description of the first ticket in the queue
string ADTqueue::front()
{
	return (front_ != NULL) ? front_->problem : "No Ticket Available";
}

// Displays all problem tickets in the queue
void ADTqueue::display()
{
	if (empty())
	{
		cout << RED << "No Ticket in the queue." << RESET << endl;
		return;
	}
	cout << GREEN << "You have " << size() << " tickets available:\n";

	const int noWidth = 5; // Defiing table size
	const int roleWidth = 12;
	const int idWidth = 6;
	const int problemWidth = 33;

	// Separate the table into columns with borders
	string Border = "+" + string(noWidth - 1, '-') + "+" +
					   string(roleWidth - 1, '-') + "+" +
					   string(idWidth - 1, '-') + "+" +
					   string(problemWidth - 1, '-') + "+";

	cout << Border << endl;
	cout << "| No.| Role      | ID  | Problem                        |" << endl;
	cout << Border << endl;

	node *temp = front_;
	int index = 1;

	while (temp != NULL)
	{
		cout << "| " << left << setw(noWidth - 2) << index
			 << "| " << setw(roleWidth - 2) << temp->role
			 << "| " << setw(idWidth - 2) << temp->id
			 << "| " << setw(problemWidth - 2) << temp->problem << "|" << endl;
		temp = temp->next;
		index++;
	}
	cout << Border << endl; // Print the bottom border
	cout << WHITE;
}

// Constructor for Admin, initializes the solved ticket count to zero
Admin::Admin() : solvedCount(0) {}

// Allows a user to submit a problem ticket, adding it to the queue
void Admin::submitProblem(int id, const string &role, const string &problem)
{
	problemQueue.append(id, role, problem);
	cout << GREEN << "Ticket submitted successfully!\n"
		 << RESET;
}

// Displays the current problem queue for the admin to view
void Admin::viewProblem()
{
	cout << YELLOW << "\n===== Ticket List =====\n"
		 << RESET;
	problemQueue.display();
	cout << YELLOW << "Press any key to return : " << RESET;
	string input;
	cin >> input;
	return;
}

// Allows the admin to solve problems one by one
void Admin::solveProblem()
{
	while (!problemQueue.empty())
	{
		cout << YELLOW << "\n===== Ticket to Solve (" << problemQueue.size() << " left) =====\n"
			 << RESET;
		cout << RED << "Current Issue: " << problemQueue.front() << "\n"
			 << RESET;
		cout << YELLOW << "Press 0 if the ticket is solved\n";
		cout << "Press 1 to go back\n"
			 << RESET;

		int choice;
		cin >> choice; // Get the user's choice

		if (choice == 0)
		{
			problemQueue.serve(); // Remove the ticket from the queue
			solvedCount++;
			cout << GREEN << "Issue solved!\n"
				 << RESET;
		}
		else if (choice == 1)
			return;
		else
		{
			cout << RED << "Invalid input. Please try again.\n"
				 << RESET;
		}
	}

	cout << RED << "No tickets to solve.\n"
		 << RESET;
	cout << YELLOW << "Press any key to return : " << RESET;
	string input;
	cin >> input;
	return;
}

// Function for students/teachers to submit a problem ticket
void submitTicket(Admin &ad, const string &role)
{
	int id;
	string problemDesc;

	cout << YELLOW << "\n====== Submit Ticket ======" << endl
		 << RESET;

	// Ask for the user ID
	cout <<  YELLOW << "Enter your " << role << " ID: " << RESET;
	cin >> id;
	cin.ignore(); // Clear the input buffer to prevent issues with getline

	// Ask for the problem description
	cout << YELLOW <<"Submit your problem (within 25 characters): " << RESET;
	getline(cin, problemDesc);

	if (problemDesc.length() > 25) // Check if the problem description is too long
		cout << RED << "Error: Problem description is too long!\n" << RESET;
	else if (!problemDesc.empty()) // Check if the problem description is not empty
		ad.submitProblem(id, role, problemDesc); // Submit the problem ticket
	else
		cout << RED << "Error: Problem description cannot be empty!\n" << RESET;
}
