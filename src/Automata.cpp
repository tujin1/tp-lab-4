#include "Automata.h"
#include <iostream>
#include <string>
using namespace std;

void cook(int n) {
	state = COOK;
	cout << menu[n - 1] << " is cooking:wait....";
	finish();

};
void finish() 
{ cout << " Done! " << endl; state = WAIT;
  cout << "take your change: " << cash << endl; cash = 0;
}

void cancel() {
	if (state == CHECK || state == ACCEPT) {
		state = WAIT;
	}
}
Automata() {
	state = OFF;
	menu[0] = { "Voda" };
	menu[1] = { "Vodka" };
	menu[2] = { "Sok" };
	menu[3] = { "Chay" };
	menu[4] = { "Herba" };
	prices[0] = { 10 };
	prices[1] = { 20 };
	prices[2] = { 30 };
	prices[3] = { 40 };
	prices[4] = { 50 };
	state = OFF;
	cash = 0;
}
string  on() {
	if (state == OFF) {
		state = WAIT;
		return "privet";
	}

}
string off() {
	if (state == WAIT)
	{
		state = OFF;
		return "poka";
	}

}
int coin(int count) {
	if ((state == WAIT) || (state == ACCEPT)) {
		state = ACCEPT;
		cash += count;
		return cash;
	}


}
void printMenu() {
	if (state != OFF) {
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ":" << menu[i] << "(" << prices[i] << ")" << endl;
		}
	}
}
string printState() {
	if (state != OFF) {
		if (state == WAIT) { return "wait" };
		if (state == ACCEPT) { return "accept" };
		if (state == CHECK) { return "check" };
		if (state == COOK) { return "cook" };
	}
	}
void choice(int n) {
	if (state == ACCEPT) {
		cash -= prices[n - 1];
		state = CHECK;
		check(n);
	};
};
void check(int n) {
	if (state == ACCEPT || state == CHECK) {
		if (cash >= prices[n - 1]) {
			cook(n);
		}


		else {
			cout << "not enough money" << endl;
			cancel();
		}
	}
}