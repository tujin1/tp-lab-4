#include "gtest/gtest.h"

#include <string>
#include "Automata.h"
TEST(automata, function_coin) {
  	Automata aut;
  	aut.on();
 	EXPECT_EQ(10, aut.coin(10));
    EXPECT_EQ(20, aut.coin(10));
}
TEST(automata, function_on){
	Automata aut;
	string expect="privet";
	EXPECT_EQ(expect,aut.on());
}
TEST(automata, function_off){
	Automata aut;
	string expect="poka";
	EXPECT_EQ(expect,aut.off());
}
TEST(automata, function_printState){
    Automata aut;
	aut.on();
	EXPECT_EQ("wait",aut.printState());
	aut.coin(50);
    EXPECT_EQ("accept",aut.printState());
}