#include <iostream>
using namespace std;

struct Student
{
	string name;
	int score;
};

struct Teacher {
	string name;
	struct Student stu[5];	
};

void allocateSpace(struct Teacher tea[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < len; i++) {
		tea[i].name = "Teacher_";
		tea[i].name += nameSeed[i];

		for (int j = 0; j < 5; j++) {
			tea[i].stu[j].name = "Student_";
			tea[i].stu[j].name += nameSeed[j];
			int random = rand() % 61 +40; 
			tea[i].stu[j].score = random;
		}
		
	}
}

void PrintInfo(struct Teacher tea[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Teacher's name" << tea[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t Student's name" << tea[i].stu[j].name << 
				" Score:" << tea[i].stu[j].score << endl;
			
		}
	}
}

int main() {
	struct Teacher tea[3];
	int len = sizeof(tea) / sizeof(tea[0]);
	allocateSpace(tea, len);
	PrintInfo(tea, len);
	system("pause");
	return 0;
}