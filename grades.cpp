#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>

using namespace std;

#define COUNT 2

struct StudentData
{
	char firstName[50];
	char lastName[50];
	int  score;
	char grade;
};

// Asks user for 1 student information
StudentData readStudentData()
{
	StudentData student;
	cout << "Enter first name: ";
	cin.getline(student.firstName, 50);
	cout << "Enter last name: ";
	cin.getline(student.lastName, 50);
	cout << "Enter score (0-100): ";
	cin >> student.score;
	cin.ignore();

	return student;
}

// loops through all students and asks for each student's information
void readAllData(StudentData students[])
{
	for (int i = 0; i < COUNT; ++i)
	{
		cout << "Student #" << (i+1) << endl;
		students[i] = readStudentData();
		cout << endl;
	}
}

// Output students' information
void outputAll(StudentData students[])
{
	cout << "Last Name   First name  Test Score  Grade" << endl;
	for (int i = 0; i < COUNT; ++i)
	{
		printf("%-12s%-12s%-12d%c\n", students[i].lastName, students[i].firstName, students[i].score, students[i].grade);
	}
	cout << endl;
}

// calculates and assigns grades
void assignGrades(StudentData students[])
{
	for (int i = 0; i < COUNT; ++i)
	{
		if (students[i].score >= 90)
			students[i].grade = 'A';
		else if (students[i].score >= 80)
			students[i].grade = 'B';
		else if (students[i].score >= 70)
			students[i].grade = 'C';
		else if (students[i].score >= 60)
			students[i].grade = 'D';
		else if (students[i].score >= 50)
			students[i].grade = 'E';
		else
			students[i].grade = 'F';
	}
}

// searches for the highest score
int getHighestScore(StudentData students[])
{
	// at first 1st student score is the highest
	int highestScore = students[0].score;
	for (int i = 1; i < COUNT; ++i)
	{
		if (highestScore < students[i].score)
			highestScore = students[i].score;
	}

	return highestScore;
}

// print highest score students
void printHighestScoreStudents(StudentData students[], int highestScore)
{
	cout << "Students with the highest score of " << highestScore << ":"<< endl;
	for (int i = 0; i < COUNT; ++i)
	{
		if (highestScore == students[i].score)
			cout << students[i].lastName << ", " << students[i].firstName << endl;
	}
	cout << endl;
}

int main()
{
	StudentData students[COUNT];
	readAllData(students);

	assignGrades(students);
	int highestScore = getHighestScore(students);
	printHighestScoreStudents(students, highestScore);
	outputAll(students);

	system("PAUSE");
	return 0;
}
