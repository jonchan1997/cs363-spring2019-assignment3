#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

class Subtract_Command: public Binary_Op_Command
{
    public:
    /// Default constructor.
    Subtract_Command(Stack<int> & stack);
    /// Destructor.
    ~Subtract_Command(void);
    
    int evaluate(int n1, int n2) const;
};
#include "Subtract_Command.cpp"
#endif 
