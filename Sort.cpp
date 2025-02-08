#include "Header.hpp"


// Merge Sort for sorting the student list


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