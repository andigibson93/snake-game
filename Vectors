#include<iostream>
#include<string>
#include<vector>
#include "student.h"
using namespace std;

void printStats(vector<Student*>& students) {

	int minTestScore = 100;
	int maxTestScore = 0;
	int sumTestScore = 0;

	for(int i = 0; i <students.size(); i++)
	{
		cout << i << " running " <<endl;
		int score = students.at(i)->getTestScore();
		cout << i << " ... " <<endl;
		minTestScore = (score < minTestScore) ? score : minTestScore;
		maxTestScore = (score > maxTestScore) ? score : maxTestScore;
		sumTestScore += score;
	}

	double avgScore = ((double)sumTestScore) / ((double)students.size());

	cout<< "============Class Statistics===========" << endl;
	cout << "Number of Students in the class: " << students.size() << endl;
	cout << "Class Average: " << avgScore << endl;
	cout << "Maximum Test Score: " << maxTestScore << endl;
	cout << "Minimum Test Score: " << minTestScore << endl;
}

int main(){

	int numberOfStudents;
	cout << "Enter number of students: ";
	cin >> numberOfStudents;


	vector<Student*> students;
	string name;
	int testscore;

	for (int i = 0; i < numberOfStudents; i++) {
		cout << "Enter student " << i + 1 << " out of " << numberOfStudents << endl;
		cout << "Enter student name: ";
		cin >> name;
		cout << "Entre test score: ";
		cin >> testscore;

		students.push_back(new Student(name, testscore));
	}

	cout <<"\nName    "<< "Test Score    "<< "Grade" << endl;
	cout <<"====    "<<"==========    " <<"=====\n" <<endl;
	

	printStats(students);
}
