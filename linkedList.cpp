#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char** arvg)
{
	struct node{
		int data;
		node* next;
		node* prev;

};

node* head;
node* tail;
node* n;

n = new node;
n -> data = 1;
n ->prev = NULL;
head = n;
tail = n;

return 0;

}