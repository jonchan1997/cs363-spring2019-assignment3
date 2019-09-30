#include "Add_Command.h"


Add_Command::Add_Command(Stack<int> & stack):Binary_Op_Command(stack)
{
}
Add_Command::~Add_Command (void)
{
    
}
int Add_Command::evaluate(int n1, int n2) const
{
    int result = n1 + n2;
    return result;
}