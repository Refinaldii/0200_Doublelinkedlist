

#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};
Node* START = NULL;

void addNode(){
	Node* newNode = new Node();
	cout << "\nEnter the roll number of the student : ";
	cin >> newNode->noMhs;
	cout << "\nEnter the name of the student : ";
	cin >> newNode->name;

	if (START == NULL || newNode->noMhs <= START->noMhs) {
		if (START != NULL && newNode->noMhs == START->noMhs) {
			cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
			return;
		}
		newNode->next = START;

		if (START != NULL) {
			START->prev = newNode;
		}
		newNode->prev = NULL;
		START = newNode;
	}
	else {
		Node* current = START;
		Node* previous = NULL;

		while (current != NULL && current->noMhs < newNode->noMhs) {
			previous = current;
			current = current->next;
		}
		newNode->next = current;
		newNode->prev = previous;

		if (current != NULL) {
			current->prev = newNode;
		}
		if (previous != NULL) {
			previous->next = newNode;
		}
		else {
			START = newNode;
		}
	}
}
bool search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != rollNo) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void deleteNode() {
	Node* previous, * current;	
	int rollNo;

	cout << "\nEnter the roll number of the student whose record is to be deleted :";
	cin >> rollNo;	

	if (START == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	current = START;	
	previous = NULL;

	while (current != NULL && current->noMhs != rollNo) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << "\033[31the record with roll number" << rollNo << "not found\033[0m" << endl;
		return;
	}
	if (current == START) {
		START = START->next;	
		if (START != NULL) {
			START->prev = NULL;
		}
	}

	else {
		previous->next = current->next; {	
			current->next->prev = previous;
		}
	}
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
