#include "Divide_Command.h"


Divide_Command::Divide_Command(Stack<int> & stack):Binary_Op_Command(stack)
{
	
}
Divide_Command::~Divide_Command(void)
{
}
int Divide_Command::evaluate(int n1, int n2) const
{
    int result = n2 / n1;
    return result;
}