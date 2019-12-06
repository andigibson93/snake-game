#include<iostream>
#include<iomanip>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int End = 70; //The finish line is at square 70, it is fixed to win the race

void moveTortoise (int *);
void moveHare (int *);
void printPosition (int, int);

//They should use pointer based pass by reference to modify thier position

int main () {

	//Our contenders begin the race at sqaure 1 of 70 squares
	int tortoise = 1;
	int hare = 1;

	srand(time(0)); //srand seeds the random number generator

	cout << "BANG !!!!\n" << "AND THEY'RE OFF !!!!\n"; //Begin the race by printing

	while (tortoise <= End && hare <= End){
		printPosition(tortoise, hare); //function call
		moveTortoise (&tortoise);
		moveHare (&hare);
		usleep(100000); // do nothing for one second (1000 ms)        

}
	//Test weather each animal has reached or passed square 70, if so print the winner and terminate the simulation
	if (tortoise >= End && hare >= End) {
		cout << "It's a tie"<< endl;
	} else if (tortoise >= End){
	    	cout << "TURTOISE WINS!!!YAY!!!"<< endl;
	} else if (hare >= End){
		cout << "Hare wins. Yuck." << endl;
	}
	return 0;
}

//End main function

void moveTortoise (int *tortoise) {
	//Generate the percentages in the preceding tables
	int i = 1 + rand()%10; // 1 <= i <= 10

	if (1 <= i && i <= 5) //Fast plod 50% when 1 <= i <= 5
	    *tortoise = *tortoise + 3; //move the tortoise 3 squares to the right
	else if (6 <= i && i <= 7) //Slip 20% when 6 <= i <=7
	    *tortoise = *tortoise - 6;  //move the tortoise 6 squares to the left
	else if (8 <= i && i <= 10) //Slow plod 30% when 8 <= i <=10
	    *tortoise = *tortoise + 1; //move the tortoise 1 square to the right or ++Tortoise
	//If an animal slips left before square 1, then move the animal back to square 1
	if (*tortoise < 1) *tortoise = 1;
}

//Use a similar technique to move the Hare
void moveHare (int *hare) {
	int i = 1+ rand()%10; //1 <= i <= 10

	if (3 <= i && i <= 4) //Big Hop 20% 
	    *hare = *hare + 9; // move the hare 9 squares to the right
	else if (5 == i) //Big slip 10% 
	    *hare = *hare - 12; // move the hare 12 squares to the left
	else if (6 <= i && i <= 8) // Small hop 30%
	    *hare = *hare + 1; //move the hare 1 square to the left or --Hare
	else if (9 <= i && i <= 10) // Small slip
	    *hare = *hare - 2; // move the hare 2 squares to the left
	//If an animal slips left before square 1, move the animal back to sqaure 1
	if (*hare < 1) *hare = 1;
}

void printPosition (int Tortoise, int Hare) {
	//For each tick of the clock, print a 70 position line showing the letter T , H and Ouch
	if(Tortoise < Hare){
	    cout<< setw(Tortoise) << "T" << setw(Hare-Tortoise) << "H "<<endl;
	} else if (Hare < Tortoise) {
	    cout<< setw(Hare)<< "H" << setw(Tortoise-Hare)<< "T" <<endl;
	} else {
	    cout<< setw(Hare) << "Ouch!!!" <<endl;
	}
}
