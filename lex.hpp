#ifndef LEX_HPP
#define LEX_HPP

#include <iostream>
#include <string>
#include <vector>
#include "opcodes.h"
#define MAX_LINES 1

unsigned int line = 0;
int lineEntry = 0;
std::string input = "int x;";
std::string buff = "";
std::vector<std::string> tokenBuff;

void tokenize(const std::string& str)
{
	while(line < MAX_LINES){
		while(lineEntry < str.length())
		{
		//	std::cout << itr;

			switch(str[lineEntry])
			{
				case ' ':
					tokenBuff.push_back(buff);
					buff = "";
					lineEntry++;
					break;

				case ';':
					tokenBuff.push_back(buff);
					tokenBuff.push_back(";");
					line++; // NOT TO BE HANDLED HERE!!!!!!
					return;
					break;
			}

			
			
			buff += str[lineEntry];
			std::cout << '\n' << lineEntry;
			if(lineEntry == str.length() - 1)
			{
					tokenBuff.push_back(buff);
					buff = "";
					return;
			}

			lineEntry++;
		}
		lineEntry = 0;
		line++; //TODO LINE HANDLING IN TOKENIZE IS TEMP
	}	
}

short opcval(const std::string& token){
	try
	{
		std::map<const std::string, short>::iterator itr;
		itr = tok.Opcodes.find(token);

		if(itr == tok.Opcodes.end())
		return 444;

		return tok.Opcodes[token];
	}catch(std::exception& e)
	{
		return -1;		
	}
}
#endif
