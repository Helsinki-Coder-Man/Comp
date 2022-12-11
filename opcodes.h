#include <string>
#include <map>

#define SEMI (short)0x0 // ;

//TYPES
#define INT (short)0x1
#define DOUBLE (short)0x2

#define EQUALS (short)0x3


struct {
std::map<const std::string, short> Opcodes { {";", 0x0}, {"int", 0x1}, {"double", 0x2}, {"=",0x3} };
} tok;
