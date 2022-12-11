#include "lex.hpp"
#include <iostream>

// variable
struct var
{	
	// name of variable
	std::string name;
	var(std::string nm) : name(nm) {}
//	int val;
};

std::vector<var> varBuff;

std::vector<unsigned int> opBuff;

static unsigned int T_Pos = 0;

// pointer to the "real" buffer so the program doesn't use copies. This improves performance (?)
struct std::vector<var>* varptr = &varBuff;

void opBuffGen()
{
	for(unsigned int i = 0; i < tokenBuff.size(); i++)
	{
		opBuff.push_back(opcval(tokenBuff[i]));
	}	
	
}

void variable()
{	
	bool isTerm = false;
	try
	{
		if(opBuff[T_Pos + 1] != SEMI || T_Pos == opBuff.size() - 1)
		{
		
			std::cout << "ERROR: No semi colon. ";
			return;
			isTerm = true;
		}

	/*	if(opBuff[T_Pos + 1] != EQUALS && !isTerm)
		{
			std::cout << "ERROR: No equals sign or Semi. ";
			return;
			isTerm = true;
		}
	*/

		var tempVarName(tokenBuff[T_Pos]); 
		varptr->push_back(tokenBuff[T_Pos]);

	

		// TODO allocate memory code generation etc
	} catch(std::exception& e)
	{
		std::cout << e.what();
	}
	
}

void type()
{
	std::cout << "\nDebug: " << T_Pos;

/*	if(T_Pos + 1 > opBuff.capacity()){
		std::cout << "ERROR!!!!!!!!!!!!!!!!!!";
		return;
	}
*/

	//	std::cout << "\n\nTESTTTTT: " <<opBuff[T_Pos] << '\n';
	switch(opBuff[T_Pos])
	{
		case 0x1:
			T_Pos++;
			type();
			
		break;

		case 0x2:
			T_Pos++;
			type();
		break;

		case 444:
		std::cout << "BLEH ";
			if(T_Pos == 0)
			{
				std::cout << "ERROR NO TYPE";
				return;
			}
			variable();
		break;

		default:
		T_Pos++;
	}
	return;
}


//TODO 
//- PAY MIND TO THIS FUNCTION
int main()
{
//	type(T_Pos);
	tokenize(input);
	opBuffGen();
	std::cout << "\nintput string: " << input << ' ' << opBuff[T_Pos];
	std::cout << "\nsize of tokbuf " << tokenBuff.size() << '\n';
	for(unsigned int i = 0; i < tokenBuff.size() ;i++)
	{
		std::cout << opBuff[i] << ' ' << tokenBuff[i] << " || ";
	}
	type();
	
}
