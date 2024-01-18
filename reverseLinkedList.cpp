#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;
void Reverse(struct Node* p) {
	if (p->next == NULL) {
		head = p;
		return;
	}
	Reverse(p->next);
	p->next->next = p;
	p->next = NULL;
	
}


struct Node* Reverse1(struct Node* head)
{
	struct Node *current, *prev, *next;
	current = head;
	prev = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}
Node* Insert(Node* head, int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) { temp1 = temp1->next; }
			temp1->next = temp;
		
	}
	return head;
}

void Print1(Node* head) {
	while (head != NULL) {
		cout<< head->data<<" ";
		head = head->next;
	}
	cout << endl;
}

void Print2(Node* p) {
	if (p == NULL) {
		cout << endl;
		return;
	}
	cout << p->data << " ";
	Print2(p->next);
}

int main() {
	struct Node* h = NULL;
	h = Insert(h, 2);
	h = Insert(h, 3);
	h = Insert(h, 4);
	h = Insert(h, 5);
	h = Insert(h, 6);
	Print2(h);
	Reverse(h);
	Print1(head);
	system("pause");
	return 0;
}