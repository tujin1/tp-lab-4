#include "Automata.h"
#include <iostream>
#include <string>
using namespace std;
void a() {
		Automata aut;
		aut.on();
		aut.printMenu();
		aut.printState();
		aut.coin(50);
		aut.choice(2);
		aut.off();
	}

	int main() {
		a();
		
		system("pause");
	}