#include "Dog.hpp"
#include <iostream>
using namespace std;

	Dog::Dog(string n){
		Dog::name = n;
		Dog::strength = 50;
		Dog::x = 0;
		Dog::y = 1;
	}

	Dog::Dog(){
		Dog::name = "John";
		Dog::strength = 50;
		Dog::x = 0;
		Dog::y = 2;
	}

	bool Dog::changeStrength(int amt){
		Dog::strength += amt;

		if(Dog::strength <= 0){
			Dog::die();
			return 0;
		}else{
			return 1;
		}
	}

	void Dog::die(){
		cout << endl << "GAME OVER" << endl << endl;
	}

	void Dog::printDog(){
		cout << "Name: " << Dog::name << endl;
		cout << "Strength: " << Dog::strength << endl;
		cout << "Position: " << Dog::x << " " << Dog::y << endl;
	}

	void Dog::won(){
		cout << endl << "Yippie!" << endl << endl;
	}

	void Dog::reset(){
		Dog::strength = 50;
		Dog::x = 0;
		Dog::y = 1;
	}
