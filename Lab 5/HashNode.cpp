

#include "HashMap.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



hashNode::hashNode(string s){
	keyword = s;
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(){
	keyword = "";
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(string s, string v){
	keyword = s;
	values = new string[100];
	values[0] = v;
	valuesSize = 100;
	currSize = 1;
}
void hashNode::addValue(string v) {
	// adding a valu to the end of the value array associated 
	// with a key

	//Add To Bottom
	for(int i = 0; i < valuesSize; i++){
		if(values[i] == ""){
			values[i] = v;
			currSize++;
			break;
		}
	}

	//Check for Size
	if(currSize >= valuesSize){
		dblArray();
	}
}
void hashNode::dblArray() {
	//Push Over
	valuesSize = valuesSize * 2;
	string *valuesNew = new string[valuesSize];
	for(int i = 0; i < valuesSize; i++){
		if(values[i] == ""){
			break;
		}else{
			valuesNew[i] = values[i];
		}
	}

	//Transfer
	values = valuesNew;

}

string hashNode::getRandValue() {
	//Every key has a values array - an array of words that 
	// follow that key in the text document.  You're going to 
	//randomly select one of those words and return it.  That 
	//will be the word that follows your key in your output 
	//function, and it will also be the next key.

//	cout << "RandValue" << endl;
	int index = rand()%currSize;
//	cout << "Node Info: " << currSize << endl << keyword << endl << values[0] << endl << index << endl;
	return values[index];
}
