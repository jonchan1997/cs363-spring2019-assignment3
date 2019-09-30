#include "Multiply_Command.h"

Multiply_Command::Multiply_Command(Stack<int> & stack):Binary_Op_Command(stack)
{

}
Multiply_Command::~Multiply_Command(void)
{

}

int Multiply_Command::evaluate(int n1, int n2) const
{
    int result = n1 * n2;
    return result;
}