#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command: public Binary_Op_Command
{
    public:
    /// Default constructor.
    Multiply_Command(Stack<int> & stack);
    /// Destructor.
    ~Multiply_Command(void);
    
    int evaluate(int n1, int n2) const;
};
#include "Multiply_Command.cpp"
#endif 
