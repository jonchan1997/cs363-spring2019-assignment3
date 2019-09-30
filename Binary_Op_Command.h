#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command: public Expr_Command
{
    public:
    /// Default constructor.
    Binary_Op_Command(Stack<int> & s);
    /// Destructor.
    ~Binary_Op_Command(void);

     //Define Binary
    void execute(void);

    //Evaluate
    virtual int evaluate (int n1, int n2) const = 0;


    protected:
    Stack<int> * stack_;
    
};
#include "Binary_Op_Command.cpp"
#endif 