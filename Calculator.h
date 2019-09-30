#ifndef _Calculator_H_
#define _Calculator_H_


//Previous Assignments
#include "Base_Array.h"
#include "Array.h"
#include "Stack.h"

//Command Pattern
#include "Expr_Command.h"
#include "Num_Command.h"
#include "Binary_Op_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"

//Factory
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"

//Wrapper
#include "Calculator.h"

//Required
#include <iostream>
#include <sstream>      // std::istringstream
class Calculator
{
    public:
        Calculator();
        ~Calculator(void);
        void solve(Array <Expr_Command *> & postfix);
        bool infix_to_postfix (const std::string & infix,Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);
    private:
    int prec(char input);
    bool isDigit(char c_input, int i_input);

};

#include "Calculator.cpp"

#endif
