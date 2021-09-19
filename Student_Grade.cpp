#include<stdio.h>
#include <string.h>
#define SIZE 100

struct Student {
	char name[20];
	int midtermGrade;
	int finalGrade;
};
int displayMenu();
void checkPassword();
void addStudent(struct Student s[], int* currentPtr);
void removeStudent(struct Student s[], int* currentPtr);
void display(struct Student s[], int* currentPtr);
void sortName(struct Student s[], int* currentPtr);
void sortMidtermGrade(struct Student s[], int* currentPtr);
void sortFinalGrade(struct Student s[], int* currentPtr);
void findMean(struct Student s[], int* currentPtr);
void findAvg(struct Student s[], int* currentPtr);

	int main()
{
	int choice;
	int done = 0;
	struct Student s[SIZE];
	int currentSize = 0;
	checkPassword();
	do {
		choice = displayMenu();
		switch (choice) 
		{
		case 1: checkPassword();
			break;
		case 2: addStudent(s, &currentSize);
			break;
		case 3: removeStudent(s, &currentSize);
			break;
		case 4: display(s, &currentSize);
			break;
		case 5: sortName(s, &currentSize);
			break;
		case 6: sortMidtermGrade(s, &currentSize);
			break;
		case 7: sortFinalGrade(s, &currentSize);
			break;
		case 8: findMean(s, &currentSize);
			break;
		case 9: findAvg(s, &currentSize);
			break;
		case 10: done = 1;
			break;
		}

	} while (!done);
		return 0;
}
	

	

	void checkPassword()
	{
	char password[] = "Secret";
	char pass[20];
	do {
		printf("Enter password: ");
		gets_s( pass);
	}while (strcmp(password, pass));
	printf("Password is correct.\n");
		
	}

int displayMenu() {
	int choice;
	printf("1 - Check the password.\n");
	printf("2 - Add a student to the array.\n");
	printf("3 - Remove a student from the array.\n");
	printf("4 - Display.\n");
	printf("5 - Sort based on names.\n");
	printf("6 - Sort based on Midterm.\n");
	printf("7 - Sort based on Final.\n");
	printf("8 - Finding Mean.\n");
	printf("9 - Finding Average.\n");
	printf("10 - Exiting.\n");
	printf("\n\n Enter choice: ");
	scanf_s("%d", &choice);
	return choice;
}

void addStudent(struct Student s[], int* currentPtr)
{
	char tempName[20];
	printf("Enter name: ");
	gets_s(tempName);
	strcpy_s(s[*currentPtr].name, sizeof(tempName),tempName);
	printf("\nEnter midterm grade: ");
	scanf_s("%d", &s[*currentPtr].midtermGrade);
	printf("Enter final grade: ");
	scanf_s("%d", &s[*currentPtr].finalGrade);
	*currentPtr = *currentPtr + 1;
}

void display(struct Student s[], int* currentPtr)
{
	for (int i = 0; i < *currentPtr; i++) {
		printf("%10s%10d%10d", s[*currentPtr].name, s[*currentPtr].midtermGrade, s[*currentPtr].finalGrade);
	}

}
void sortName(struct Student s[], int *currentPtr) {
	for (int i = 0; i < *currentPtr ; i++)
	{
		for (int j = 0; j < i - 1; j++) {
			if (strcmp(s[j].name, s[j + 1].name) > 0)
			{
				struct Student temp = s[i];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}
void sortMidtermGrade(struct Student s[], int* currentPtr) {
	for (int i = 0; i < *currentPtr; i++)
	{
		for (int j = 0; j < i - 1; j++) {
			if (s[j].midtermGrade > s[j+1].midtermGrade)
			{
				struct Student temp = s[i];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}

		}
	}
}
void sortFinalGrade(struct Student s[], int* currentPtr) {
	for (int i = 0; i < *currentPtr; i++)
	{
		for (int j = 0; j < i - 1; j++) {
			if (s[j].finalGrade > s[j + 1].finalGrade)
			{
				struct Student temp = s[i];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}

		}
	}
}


void removeStudent(struct Student s[], int* currentPtr)
{
	printf("Enter name to remove: ");
	char tempName[20];
	int index = *currentPtr;
	gets_s( tempName);
	for (int i = 0; i < *currentPtr; i++) {
		if (strcmp(s[index].name, tempName) == 0)
		{
			s[i] = s[index-1] ;
			strcpy_s(s[index-1].name, "\0");
			s[index - 1].midtermGrade = NULL;
			s[index - 1].finalGrade = NULL;
			*currentPtr = *currentPtr - 1;
		}
		else {
			printf("\nCould not fint that name in the list");
		}

	}

	
}
void findAvg(struct Student s[], int* currentPtr){
	int sum = 0;
	int count = *currentPtr;
	for (int i = 0; i < *currentPtr; i++) {
		sum = sum + s[*currentPtr].finalGrade;		
	}
	double ave = (double) sum/count;
	printf("The average grade for final exam is :%.2lf", ave);
}
void findMean(struct Student s[], int* currentPtr) {
	int sum = 0;
	int count = *currentPtr;
	int mean;
	if (count % 2 == 1) {
		mean = (count - 1) / 2;
		printf("The mean grade for final exam is :%d", s[mean].finalGrade);
	}
	else {
		int pos1 = count / 2;
		int pos2 = (count - 1) / 2;
		double meanGrade = (double)((s[pos1].finalGrade + s[pos2].finalGrade) / 2);
		printf("The mean grade for final exam is :%.2lf", meanGrade);
	}
		
	for (int i = 0; i < *currentPtr; i++) {
		sum = sum + s[*currentPtr].finalGrade;
		count = count + 1;
	}
	double ave = (double)sum / count;
	printf("The average grade for final exam is :%.2lf", ave);
}