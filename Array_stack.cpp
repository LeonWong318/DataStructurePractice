#include<iostream>
using namespace std;
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x) {
	if (top == MAX_SIZE - 1) {
		cout << "Error: stack overflow" << endl;
		return;
	}
	A[++top] = x;
}
void Pop() {
	if (top == -1) {
		cout << "Error: No element to pop" << endl;
		return;
	}
	top--;
}
int Top() {
	return A[top];
}

void Print() {
	for (int i = 0; i < top + 1; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int main1() {
	Push(5);
	Push(3);
	Push(10);
	Pop();

	Print();
	system("pause");
	return 0;
}