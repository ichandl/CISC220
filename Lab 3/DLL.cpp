
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}
	void DLL::push(string n, string a, int m, int s) {  // does what you'd think
		DNode *temp = new DNode(n,a,m,s);

		if(first == NULL){
			first = temp;
			last = temp;
		} else{
			temp->prev = last;
			last = temp;
			last->prev->next = last;
		}

		numSongs++;
	}
	Song *DLL::pop() { //does what you'd think
		DNode *temp = last;
		if(last == first){
			last = NULL;
			numSongs--;
		} else{
			last = temp->prev;
			last->next = NULL;
			numSongs--;
		}

		Song *song = temp->song;
		delete[] temp;

		return song;
	}

	void DLL::printList() {
		DNode *temp = first;

		while(temp != NULL){
			temp->song->printSong();
			temp = temp->next;
		}
		cout << endl;
	}

	void DLL::moveUp(string s) {
		DNode *temp = first;

		while(temp->song->title != s){
			temp = temp->next;
		}

		DNode *temp2 = temp->prev;

		if(temp == first){
			first = temp->next;
			first->prev = NULL;
			temp->prev = last;
			last = temp;
			temp->next = NULL;
			temp->prev->next = temp;
		} else if(temp2 == first){
			first = temp;
			temp->next->prev = temp2;
			temp2->next = temp->next;
			temp->next = temp2;
			temp->prev = temp2->prev;
			temp2->prev = temp;
		} else if(temp == last){
			last = temp2;
			temp2->prev->next = temp;
			temp2->next = NULL;
			temp->next = temp2;
			temp->prev = temp2->prev;
			temp2->prev = temp;
		}else{
			temp->next->prev = temp2;
			temp2->prev->next = temp;
			temp2->next = temp->next;
			temp->next = temp2;
			temp->prev = temp2->prev;
			temp2->prev = temp;
		}
	}

	void DLL::listDuration(int *tm, int *ts) {
		DNode *temp = first;
		*tm = 0;
		*ts = 0;

		while(temp != NULL){
			*tm = *tm + temp->song->min;
			*ts = *ts + temp->song->sec;
			temp = temp->next;
		}
	}
	void DLL::moveDown(string s) {
		DNode *temp = first;

		while(temp->song->title != s){
			temp = temp->next;
		}

		DNode *temp2 = temp->next;

		if(temp == last){
			last = temp->prev;
			last->next = NULL;
			temp->next = first;
			first = temp;
			temp->prev = NULL;
			temp->next->prev = temp;
		} else if(temp2 == last){
			last = temp;
			temp->prev->next = temp2;
			temp2->prev = temp->prev;
			temp->prev = temp2;
			temp->next = temp2->next;
			temp2->next = temp;
		} else if(temp == first){
			temp2->next->prev = temp;
			first = temp2;;
			temp2->prev = NULL;
			temp->prev = temp2;
			temp->next = temp2->next;
			temp2->next = temp;
		} else{
			temp2->next->prev = temp;
			temp->prev->next = temp2;
			temp2->prev = temp->prev;
			temp->prev = temp2;
			temp->next = temp2->next;
			temp2->next = temp;
		}
	}
	void DLL::makeRandom() {
		int size = numSongs;
		DNode *temp = first;

		// Make the new list
		DNode *primero = NULL;
		DNode *temp2 = NULL;
		int a;

		//While the new list exists
		while(size > 0){
			//Select a random one from the list
			a = abs(rand()%size);
			temp = first;
			for(int i = 0; i < a; i++){
				temp = temp->next;
			}
			//At the end of the loop, we find the next song that we want
			remove(temp->song->title);
			size--;

			//Craft the new list
			if(primero == NULL){
				primero = temp;
				temp2 = temp;
				temp2->prev = NULL;

			} else{
				temp2->next = temp;
				temp2->next->prev = temp2;
				temp2 = temp2->next;
			}
		}

		first = primero;
		temp2->next = NULL;
		last = temp2;

	}
	int DLL::remove(string s) {  
		DNode *temp = first;
		int i = 0;

		while(temp->song->title != s){
			temp = temp->next;
			i++;
		}
//		Test case for first or last
		if(first == temp){
			first = temp->next;
			if(temp->next != NULL){
				temp->next->prev = NULL;
			}
		}else if(last == temp){
			last = temp->prev;
			temp->prev->next = NULL;
		}else{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}

		delete[] temp;
		numSongs--;
		return i;
	}


	DLL::~DLL(){
		while(numSongs > 0){
//			cout << numSongs << endl;
			pop();
		}
	}
