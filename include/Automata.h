#include <iostream>
#include <string>
using namespace std;
enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
private:
	int cash;
	string menu[5];
	int prices[5];
	STATES state;
	void cook(int);
	void finish();
	
 public:
	Automata();
	string on();         
	string off();      
	int coin(int);          
	void printMenu();      
    string printState();  
	void choice(int);  
    void check(int);        
	void cancel();         

};



