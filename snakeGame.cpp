#include<iostream>
#include<stdlib.h> // system interaction
#include<ncurses.h> // for drawing in place
#include<ctime>

using namespace std;

#define KEY_UP 65 //#define is a macro and key_up is replaced by 65 when compiling
#define KEY_DOWN 66 //these are the arrow keys from ascii
#define KEY_LEFT 68
#define KEY_RIGHT 67

const int max_x = 150; //replace 80 by max_x. how many characters/wide the screen is
const int max_y = 40;
const double refresh_time = 0.04; //how often the dot moves in the program

struct Position
{

int x, y;

};


char *msg = "neutral";

Position snakePosition;
Position snakeDirection;

int quitGame = 0; // = 0 means false, so dont quit the game

void drawScreen(Position *snakePos); //functions prototypes
void handleInput();
void update();
void init();


int main() {
	init(); //call function 

	clock_t gameTime = clock(); // get the current time. Its a function call to the library ctimeeifjccgicdrdnbvrenuhtbenglbekdfcvhteivgretun

	double timeInSeconds;
	int c = 0;

	while (!quitGame) {		
		handleInput();

		timeInSeconds = (double)(clock() - gameTime) / (double) CLOCKS_PER_SEC;
		if (timeInSeconds > refresh_time) {			
			update();
			drawScreen(&snakePosition);
			gameTime = clock();
		}
	}

	refresh();    
	clrtoeol();
	endwin();
	cout << "goodbye";

	system ("pause");
	return 0;
}

void init() {
	initscr(); //initialize if you want to use the library ncurses
	clear(); // clear the old screen
	noecho(); // don't write command stuff to the console
	nodelay(stdscr, true); // don't block on getch
	cbreak();	/* Line buffering disabled. pass on everything */
	
	start_color(); //enables the color mode	
	init_pair(1, COLOR_GREEN, COLOR_BLACK); // red font, black background
	init_pair(2, COLOR_YELLOW, COLOR_BLACK); // green font, black background
	snakeDirection.x = 1;
	snakeDirection.y = 0;
}


void update() {
	snakePosition.x += snakeDirection.x;
	snakePosition.y += snakeDirection.y;

	if (snakePosition.x > max_x ) {
		snakePosition.x = 0;
	
	} else if (snakePosition.x < 0) {
		snakePosition.x = max_x;
	
	} else if (snakePosition.y > max_y) {
		snakePosition.y = 0;

	}else if (snakePosition.y < 0) {
		snakePosition.y = max_y;
	}
}

void handleInput() {
	int c=getch(); //retuns the last character pressed on the keyboard
		if (c>0) {
		switch(c) {
		    case KEY_UP:
		        snakeDirection.x = 0;
				snakeDirection.y = -1;
		        break;
		    case KEY_DOWN:
		        snakeDirection.x = 0;
				snakeDirection.y = 1;
		        break;
		    case KEY_RIGHT:
		    	snakeDirection.x = 1;
				snakeDirection.y = 0;
		    	break;
		    case KEY_LEFT:
		    	snakeDirection.x = -1;
				snakeDirection.y = 0;
		    	break;
		    case 'q':
		    	quitGame = 1;
		    	break;
		}
	}
}


void drawScreen(Position *snakePos) {
	refresh();
	clear();	
	attron(COLOR_PAIR(2));
	mvprintw(0, 5, "%s", msg);
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(1));	
	mvprintw(snakePos->y, snakePos->x, "*");
	attroff(COLOR_PAIR(1));

	mvprintw(3, 0, "Hey Andi");
}
