#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* link;
};

Node* top = NULL;

void Push(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->link = top;
	top = temp;
	
}
void Pop() {
	Node* temp;
	if (top == NULL) return;
	temp = top;
	top = temp->link;
	delete(temp);
}

int Top() {
	return top->data;
}

bool IsEmpty() {
	return top == NULL;
}

void Print() {
	Node* temp = top;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}

int main() {
	Push(1);
	Push(5);
	Print();
	Pop();
	Pop();
	Print();
	Push(5);
	bool a = IsEmpty();
	cout << a << endl;
	system("pause");
	return 0;
}