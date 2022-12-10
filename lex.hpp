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
		while(lineEntry < input.length())
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
					line++;
					return;
					break;
			}

			
			
			buff += str[lineEntry];
			lineEntry++;
	
		}
		lineEntry = 0;
		line++;
	}	
}

short opcval(const std::string& token){
	try
	{
		return tok.Opcodes[token];
	}catch(std::exception& e)
	{
		return 444;		
	}
}
#endif
