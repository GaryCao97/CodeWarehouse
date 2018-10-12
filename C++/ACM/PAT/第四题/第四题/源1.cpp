#include <iostream>
#include <cstring>
typedef struct Student{
	char name[11];
	char num[11];
	int score;
}Student;
int main(){
	int i, n;
	struct Student Student[2];
	Student[0].score = -1;
	Student[1].score = 101;
	scanf("%d", &n);
	for (i = 0; i<n; i++){
		char name[11], num[11];
		int score;
		scanf("%s %s %d", name, num, &score);
		if (score>Student[0].score){
			strcpy(Student[0].name, name);
			strcpy(Student[0].num, num);
			Student[0].score = score;
		}
		if (score<Student[1].score){
			strcpy(Student[1].name, name);
			strcpy(Student[1].num, num);
			Student[1].score = score;
		}
	}
	printf("%s %s\n", Student[0].name, Student[0].num);
	printf("%s %s", Student[1].name, Student[1].num);
	return 0;
}