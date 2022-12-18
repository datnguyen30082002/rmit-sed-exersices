#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Household
{
public:
	string name;
	Household *next = nullptr; // Declare next pointer

	Household(string name = "") : name(name) {}
};

// Traversal function
void traversal(Household *oriHousehold)
{
	// Show linked list
	Household *tmp = oriHousehold;

	while (tmp != nullptr)
	{
		cout << tmp->name;
		tmp = tmp->next;

		if (tmp != nullptr)
			cout << " ---> ";
	}
}

// Search by name function
Household *findByName(Household *oriHousehold, string name)
{
	if (oriHousehold == nullptr)
	{
		cout << "\n List is empty";
		return new Household("");
	}

	Household *tmp = oriHousehold;

	while (tmp != nullptr)
	{
		if (tmp->name.compare(name) == 0)
			return tmp;

		tmp = tmp->next;
	}

	return new Household("");
}

// Find previous node function
Household *findPreviousNode(Household *oriHousehold, string name)
{
	if (oriHousehold == nullptr)
	{
		cout << "\n List is empty";
		return new Household("");
	}

	Household *tmp = oriHousehold;

	while (tmp != nullptr)
	{
		if (tmp->next != nullptr && tmp->next->name.compare(name) == 0)
			return tmp;

		tmp = tmp->next;
	}

	return new Household("");
}

// Search by index function
Household findByIndex(Household *oriHousehold, int index)
{
	if (oriHousehold == nullptr)
	{
		cout << "\n List is empty";
		return Household("");
	}

	Household *tmp = oriHousehold;
	int position = 0;

	while (tmp != nullptr)
	{
		if (position == index)
			return *tmp;

		tmp = tmp->next;
		position++;
	}

	return Household("");
}

// Find last node function
Household *findLastNode(Household *oriHousehold)
{
	if (oriHousehold == nullptr)
	{
		cout << "\n List is empty";
		return new Household("");
	}

	Household *tmp = oriHousehold;

	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}

	return tmp;
}

// Find the penultimate node function
Household *findPenultimateNode(Household *oriHousehold)
{
	if (oriHousehold == nullptr)
	{
		cout << "\n List is empty";
		return new Household("");
	}

	Household *tmp = oriHousehold;

	while (tmp->next->next != nullptr)
	{
		tmp = tmp->next;
	}

	return tmp;
}

/*Add node function*/
// Add element at the begin
void addElementAtBegin(Household *oriHousehold, Household node1)
{
	node1.next = oriHousehold;
	oriHousehold = &node1;

	// Show linked list
	Household *tmp = oriHousehold;

	while (tmp != nullptr)
	{
		cout << tmp->name;
		tmp = tmp->next;

		if (tmp != nullptr)
			cout << " ---> ";
	}
}

// Add element at the end
void addElementAtEnd(Household *oriHousehold, Household node2)
{
	// Find last node
	Household *lastNode = findLastNode(oriHousehold);

	// Connect last node to new node
	lastNode->next = &node2;
	node2.next = nullptr;

	// Show linked list
	Household *tmp = oriHousehold;

	// Print linked list
	while (tmp != nullptr)
	{
		cout << tmp->name;
		tmp = tmp->next;

		if (tmp != nullptr)
			cout << " ---> ";
	}
}

// Add element in the middle
void addElementAtMiddle(Household *oriHousehold, string name, Household nodex)
{
	Household *find = findByName(oriHousehold, name);

	nodex.next = find->next;
	find->next = &nodex;

	// Show linked list
	Household *tmp = oriHousehold;

	// Print linked list
	while (tmp != nullptr)
	{
		cout << tmp->name;
		tmp = tmp->next;

		if (tmp != nullptr)
			cout << " ---> ";
	}
}

/*Delete node*/
// Delete node at the end
void deleteLastNode(Household **oriHousehold)
{
	// Find the penultimate node
	Household *penultimateNode = findPenultimateNode(*oriHousehold);

	// Connect penultimate node
	penultimateNode->next = penultimateNode->next->next;

	// Show linked list
	Household *tmp = *oriHousehold;

	// Print linked list
	while (tmp != nullptr)
	{
		cout << tmp->name;
		tmp = tmp->next;

		if (tmp != nullptr)
			cout << " ---> ";
	}
}

// Delete node at the begin
void deleteFirstNode(Household *oriHousehold)
{
	// Connect node
	oriHousehold = oriHousehold->next;

	// Call traversal function
	traversal(oriHousehold);
}

// Delete node at the middle
void deleteMiddleNode(Household *oriHousehold, string name)
{
	Household *prevNode = findPreviousNode(oriHousehold, name);

	prevNode->next = prevNode->next->next;
	traversal(oriHousehold);
}

/*Swap node*/
// Swap function
void swapNode(Household **oriHousehold, Household X, Household Y)
{
	// Nothing to do if x and y are same
	if (X.name.compare(Y.name) == 0)
	{
		cout << "X and Y are the same" << endl;
		return;
	}

	// Search for x (keep track of prevX and CurrentX)
	Household *prevX = nullptr, *currentX = *oriHousehold;
	while (currentX && currentX->name.compare(X.name) != 0)
	{
		prevX = currentX;
		currentX = currentX->next;
	}

	// Search for y (keep track of prevY and CurrentY)
	Household *prevY = nullptr, *currentY = *oriHousehold;
	while (currentY && currentY->name.compare(Y.name) != 0)
	{
		prevY = currentY;
		currentY = currentY->next;
	}

	// If either x or y is not present, nothing to do
	if (currentX == nullptr || currentY == nullptr)
	{
		cout << "There is no either X or Y" << endl;
		return;
	}

	// If x is not head of linked list
	if (prevX != nullptr)
		prevX->next = currentY;
	else // make y as a new head
		*oriHousehold = currentY;

	// If y is not head of linked list
	if (prevY != nullptr)
		prevY->next = currentX;
	else // make x as a new head
		*oriHousehold = currentX;

	// Swap two nodes
	Household *temp = currentY->next;
	currentY->next = currentX->next;
	currentX->next = temp;

	cout << "\n\n swapNode \n";
	traversal(*oriHousehold);
}

/*Sorting*/
// Sorting in descending order
void sortDescendingOrder(Household *oriHousehold)
{
	Household *p, *q;

	for (p = oriHousehold; p != nullptr; p = p->next)
	{
		for (q = p->next; q != nullptr; q = q->next)
		{
			if (p->name.compare(q->name) < 0)
			{
				swapNode(&oriHousehold, *p, *q);
			}
		}
		cout << "\n p.name = " << p->name << "\n";
	}

	cout << "\n sortDescendingOrder \n";
	traversal(oriHousehold);
}

int main()
{
	// Initialize nodes
	Household household1("House hold 1"), household2("House hold 2"), household3("House hold 3");
	Household household4("House hold 4"), household5("House hold 5"), household6("House hold 6");

	// Set house hold 1 as the original household
	Household *oriHousehold = &household1;

	// Connect nodes
	household1.next = &household2;
	household2.next = &household3;
	household3.next = &household4;
	household4.next = &household5;
	household5.next = &household6;
	household6.next = nullptr;

	traversal(oriHousehold);

	// Household find = findByName(oriHousehold, "House hold 1");
	// if (find.name.compare("") == 0)
	//     cout << "\n Not found";
	// else
	//     cout << "\n Found";

	// Household find2 = findByIndex(oriHousehold, 666);
	// if (find2.name.compare("") == 0)
	//     cout << "\n Not found";
	// else
	//     cout << "\n Found, name = " << find2.name;

	Household household0("New element");
	// addElementAtBegin(oriHousehold, household0);

	Household householdLast("Last element");
	// addElementAtEnd(oriHousehold, householdLast);

	// string name;
	// cout << "Enter node's name: ";
	// getline(cin, name);

	// addElementAtMiddle(oriHousehold, name, householdLast);

	// deleteLastNode(&oriHousehold);
	// deleteFirstNode(oriHousehold);

	string name = "House hold 3";
	// Household *find2 = findByNextName(oriHousehold, name);
	// if (find2->name.compare("") == 0)
	//     cout << "\n Not found";
	// else
	//     cout << "\n Found, name = " << find2->name;

	// deleteMiddleNode(oriHousehold, name);

	// Household householdX("House hold 11"), householdY("House hold 1");
	// swapNode(&oriHousehold, householdX, householdY);

	sortDescendingOrder(oriHousehold);
}
