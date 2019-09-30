#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_
class Expr_Command
{
    public:
    /// Default constructor.
    Expr_Command(void);
    /// Default deconstructor.
    ~Expr_Command(void);
    //Execute
    virtual void execute(void) = 0;
};

#include "Expr_Command.cpp"

#endif   // !defined _COMMAND_H_
