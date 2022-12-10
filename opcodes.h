#include <string>
#include <map>

#define SEMI 0 // ;

//TYPES
#define INT 1
#define DOUBLE 2

#define EQUALS 3

#define VAR 99

struct {
std::map<const std::string, short> Opcodes { {";", 0x0}, {"int", 0x1}, {"double", 0x2}, {"=",0x3} };
} tok;
