#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"

class Divide_Command: public Binary_Op_Command
{
    public:
    /// Default constructor.
    Divide_Command(Stack<int> & stack);
    /// Destructor.
    ~Divide_Command(void);

    int evaluate(int n1, int n2) const;
    
};
#include "Divide_Command.cpp"
#endif 
