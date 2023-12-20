#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************************************/
/* These are the methods you are to write for a BST           */
/* More Detailed Instructions can be found in the doc and in  */
/* the BST.hpp file                                           */
/**************************************************************/

BST::BST(string n, string st, string descr, bool Xtra) {
	root = new BSTNode(n, st, descr);
	Xt = Xtra;
}


bool BST::insert(string n, string st, string descr) {
	if(root == NULL){
		root = new BSTNode(n, st, descr);
	} else{
		BSTNode *tmp = root;
		//Seraches for open spot, in the correct direction
		while((n > tmp->animal->name && tmp->right != NULL) || (n < tmp->animal->name && tmp->left != NULL)){
			if(n > tmp->animal->name){
				tmp = tmp->right;
			}else if(n < tmp->animal->name){
				tmp = tmp->left;
			}
		}
		// Insert at the correct spot
		if(n > tmp->animal->name){
			tmp->right = new BSTNode(n, st, descr);
			tmp->right->parent = tmp;
			setHeight(tmp->right);
		} else{
			tmp->left = new BSTNode(n, st, descr);
			tmp->left->parent = tmp;
			setHeight(tmp->left);
		}
	}

	return true;
}

BSTNode *BST::find(string n) {
	BSTNode *tmp = root;
	while(tmp->animal->name != n){
		cout << tmp->animal->name << endl;
		if(n > tmp->animal->name){
			tmp = tmp->right;
		}else{
			tmp = tmp->left;
		}
	}
//	cout << "find completed";
	return tmp;
}

void BST::updateStatus(string name, string st) {
	BSTNode *tmp = find(name);

	tmp->animal->status = st;
}
void BST::printTreeIO(BSTNode *tmp) {
	if(tmp == NULL){
		return;
	}

	printTreeIO(tmp->left);

	tmp->printNode(Xt);

	printTreeIO(tmp->right);
}

void BST::printTreePre(BSTNode *tmp) {
	if(tmp == NULL){
		return;
	}
	tmp->printNode(Xt);

	printTreeIO(tmp->left);


	printTreeIO(tmp->right);
}

void BST::printTreePost(BSTNode *tmp) {
	if(tmp == NULL){
			return;
		}
	printTreeIO(tmp->left);


	printTreeIO(tmp->right);

	tmp->printNode(Xt);
}

void BST::setHeight(BSTNode *tmp) {
	int count = 0;

	//Counts up
	while(tmp != NULL){
		if(tmp->height < count){
			tmp->height = count;
		}
		tmp = tmp->parent;
		count++;
	}

	//Counts Down
}

BSTNode *BST::removeNoKids(BSTNode *tmp) {
	//Change Parent
	if(tmp->parent->left == tmp){
		tmp->parent->left = NULL;
	}else{
		tmp->parent->right = NULL;
	}
	return tmp;
}

BSTNode *BST::removeOneKid(BSTNode *tmp,bool leftFlag) {
	if(tmp->parent->left == tmp && tmp->left != NULL){
		tmp->parent->left = tmp->left;
		tmp->left->parent = tmp->parent;
	}else if(tmp->parent->left == tmp && tmp->right != NULL){
		tmp->parent->left = tmp->right;
		tmp->right->parent = tmp->parent;
	}else if(tmp->parent->right == tmp && tmp->left != NULL){
		tmp->parent->right = tmp->left;
		tmp->left->parent = tmp->parent;
	}else{
		tmp->parent->right = tmp->right;
		tmp->right->parent = tmp->parent;
	}
	return tmp;
}
BSTNode *BST::remove(string s) {
	cout << "0";
	BSTNode *tmp = find(s);
	cout << "a";

	if(tmp->left == NULL && tmp->right == NULL){
		removeNoKids(tmp);
	}else if(tmp->left == NULL || tmp->right == NULL){
		removeOneKid(tmp, 1);
	}else{
		cout << "b";
		BSTNode *tmp2 = tmp->right;
		while(tmp2->left != NULL){
			tmp2 = tmp2->left;
		}

		if(tmp2->left == NULL && tmp2->right == NULL){
			tmp2 = removeNoKids(tmp2);
		}else{
			tmp2 = removeOneKid(tmp2, 1);
		}

		if(tmp2->parent != NULL){
			if(tmp->parent->left == tmp){
				tmp->parent->left = tmp2;
			}else{
				tmp->parent->right = tmp2;
			}

			tmp2->parent = tmp->parent;
			tmp2->left = tmp->left;
			tmp2->right = tmp->right;
		}
	}

	return tmp;
}

/**************** Written for you  ***********************/

BST::BST(bool Xtra) {
	root = NULL;
	Xt = Xtra;
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(BSTNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode(Xt);
		delete(tmp);
	}
}
void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}






