/*Doubly Linked List Implementation*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;// global variable--pointer to head node
struct Node* GetNewNode(int x) {
	struct Node* newNode = new Node;
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;

}

void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	while (temp->next != NULL) temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	

}

void Print() {
	struct Node* temp = head;
	cout << "Forward: ";
	while (temp != NULL) {
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << endl;
}

void ReversePrint() {
	struct Node* temp = head;
	if (temp == NULL) return;
	while (temp -> next != NULL) {
		temp = temp->next;
	}
	cout << "Reverse: ";
	while (temp != NULL) {
		cout << temp->data<<" ";
		temp = temp->prev;
	}
	cout << endl;
}

int main() {
	head = NULL;
	InsertAtHead(2); Print();ReversePrint();
	InsertAtHead(4); Print();ReversePrint();
	InsertAtHead(6); Print();ReversePrint();
	InsertAtHead(8); Print();ReversePrint();



	InsertAtTail(2);
	InsertAtTail(4);
	InsertAtTail(6);
	InsertAtTail(7);
	InsertAtTail(8);
	Print();
	system("pause");
	return 0;
}