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
	string menu[5] = { "Voda", "Vodka     ", "Chay  ", "Moloko" ,"Sok"};    
	int prices[5] = { 10, 20, 30, 40,50 };    
	STATES state = off;  
	void cook(int);
	void finish();

 public:
	Automata();
	char on();         
	char off();      
	int coin(int);          
	void printMenu();      
	string printState();  
	void choice(int);  
    void check(int);        
	void cancel();         

};



