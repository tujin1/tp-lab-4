#include "Automata.h"
#include <iostream>
#include <string>
using namespace std;

AAutomata::Automata() {
	state = OFF;
	cash = 0;
}
  void  Automata::on() {
	if (state == OFF) {
		state = WAIT;
		cout<<"privet";
	}

}
void Automata::off() {
	if (state == WAIT)
	{
		state = OFF;
		cout << "poka";
	}

}
int Automata::coin(int count) {
	if ((state == WAIT) || (state == ACCEPT)) {
		state = ACCEPT;
		cash += count;
		cout << "Dengi:" << cash << endl;
		cout << "Done?Yes(1) or No(0)?" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			Automata::coin(count);
		}
		
	}; return 0;
}
void Automata::printMenu() {
	if (state != OFF) {
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ".:" << menu[i] << "(" << prices[i] << ")" << endl;
		}
	}
}
void Automata::printState() {
	if (state == WAIT) { cout << "wait"; };
	if (state == ACCEPT) { cout << "accept"; };
	if (state == CHECK) { cout << "check"; };
	if (state == COOK) { cout << "cook"; };
}
void Automata::choice(int n) {
	if (state == ACCEPT) {
		state = CHECK;
		Automata::check(n);
	};
};
void Automata::check(int n) {
	if (cash >= prices[n - 1]) {
		cout << "Are you sure ?Yes(1) or No(0)" << endl;
		int k;
		cin >> k;
		if (k == 1) { Automata::cook(n); }
		else {
			cout << "Chto togda?" << endl; cin >> k; Automata::choice(k);
		}
	}
	else {
		cout << "not enough money. give me more" << endl;
		int l;
		cin >> l;
		cash += l;
		Automata::check(n);
	}
}
	void Automata::cook(int n) {
		state = COOK;
		cout << menu[n - 1] << "cooking:wait....";
		Automata::finish();

	};
	void Automata::finish() { state == WAIT; cout << "Give me money of leave. Yes(1) or No(0)?"; int k; cin >> k; if (k > 0) { Automata::coin(k); } else { cout << "take your change"; cash = 0; Automata::off(); }; }
	void Automata::cancel() {
		if ((state == CHECK) || (state == ACCEPT)) { state == WAIT; cash = 0; };
	};