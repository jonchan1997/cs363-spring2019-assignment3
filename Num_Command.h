#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Num_Command: public Expr_Command
{
    public:
    Num_Command (Stack <int> & s, int n);
    ~Num_Command(void);

     //Define Binary
    void execute(void);


    protected:
    Stack<int> * stack_;
    int number_;
    
};
#include "Num_Command.cpp"
#endif 