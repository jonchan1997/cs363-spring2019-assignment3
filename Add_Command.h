#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

class Add_Command: public Binary_Op_Command
{
    public:
    /// Default constructor.
    Add_Command(Stack<int> & stack);
    /// Destructor.
    ~Add_Command(void);
    
    int evaluate(int n1, int n2) const;
    
};
#include "Add_Command.cpp"
#endif 
