#include <iostream>
using namespace std;

struct Hero {
	string name;
	int age;
	string sex;
};

void BubbleSort(struct Hero h[], int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1;j++) {
			if (h[j].age > h[j + 1].age) {
				struct Hero temp = h[j];
				h[j] = h[j + 1];
				h[j + 1] = temp;
			}
		}
	}
}

void Print(struct Hero h[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Name: " << h[i].name << " Age: " << h[i].age << " Sex: " << h[i].sex << endl;
	}

}

int main() {

	struct Hero h[5] = {
		{"A", 70, "M"},
		{"B", 50, "M"},
		{"C", 66, "M"},
		{"D", 18, "M"},
		{"E", 25, "F"},
	};

	int len = sizeof(h) / sizeof(h[0]);
	Print(h, len);
	cout << endl;
	BubbleSort(h, len);
	Print(h, len);

	system("pause");
	return 0;
}