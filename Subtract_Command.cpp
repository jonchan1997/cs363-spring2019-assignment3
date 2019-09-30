#include "Subtract_Command.h"


Subtract_Command::Subtract_Command(Stack<int> & stack):Binary_Op_Command(stack)
{
	
}
Subtract_Command::~Subtract_Command(void)
{
}
int Subtract_Command::evaluate(int n1, int n2) const
{
    int result = n2 - n1;
    return result;
}