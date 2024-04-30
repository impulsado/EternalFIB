#include <sstream>
#include "utils.hh"

bool isDigit(char c)
{
    return '0' <= c and c <= '9';
}

bool isNumber(string s)
{
    if (int(s.size()) == 0) return false;
	for (int i = 0; i < int(s.size()); ++i)
        if (not isDigit(s[i]))
            return false;
    return true;
}

bool isLowercaseLetter(char c)
{
    return 'a' <= c and c <= 'z';
}

bool isVariable(string s)
{
    if (int(s.size()) == 0) return false;
	for (int i = 0; i < int(s.size()); ++i)
        if (not isLowercaseLetter(s[i]))
            return false;
    return true;
}

int mystoi(string s)
{
    istringstream mycin(s);
    int x;
    mycin >> x;
    return x;
}
