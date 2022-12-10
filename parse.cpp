#include "lex.hpp"
#include <iostream>

std::vector<unsigned int> opBuff;

unsigned int T_Pos = 0;

void opBuffGen()
{
	for(unsigned int i = 0; i < tokenBuff.size(); i++)
	{
		opBuff.push_back(opcval(tokenBuff[i]));
	}	
	
}


int type(unsigned int offset);

int variable()
{
//	int left = 
	
	//Add code generation
	T_Pos += 1;
	return 99; 
}


//TODO 
//- PAY MIND TO THIS FUNCTION
int main()
{
//	type(T_Pos);
	tokenize(input);
	for(unsigned int i = 0; i < tokenBuff.size() ;i++)
	{
		std::cout << (short)opcval(tokenBuff[i]) << ' ' << tokenBuff[i] << " END ";
	}
}
