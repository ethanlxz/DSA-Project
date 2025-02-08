#include "Header.hpp"

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
