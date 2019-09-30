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

//wrapper
#include "Calculator.h"

//Required
#include <iostream>
#include <sstream>      // std::istringstream

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.
// I went ahead and moved the functions out of the driver
// Main function
int main(int argc, char* argv[])
{
	typedef Stack <int> stack;
	//typedef Array <int> Array;
	bool QUIT = false;
	std::string entry;
	stack * s = new stack();
	Stack_Expr_Command_Factory factory (*s);
	Array <Expr_Command *> postfix;
	Calculator Calc = Calculator();
	while(!(QUIT))
	{
		std::cout << "Please ENTER a CALCULATION or TYPE QUIT :" << std::endl;
		std::cout << std::endl;
		std::cout << "~";
		std::getline (std::cin >> std::skipws,entry);
		std::cout << std::endl;
		if((entry.compare("QUIT"))==0 || entry.compare("quit")==0)
		{
			s->~stack();
			factory.~Stack_Expr_Command_Factory();
			postfix.~Array();
			QUIT = true;
			break;
		}
		
		else
		{
			
			// evaluate postfix
			if(Calc.infix_to_postfix (entry, factory, postfix))
			{	
				// COMMENT You are not evaluating the postfix expression.
				//I implemented it in the wrapper.
				Calc.solve(postfix);
				std::cout << "Result:" << s->top () << std::endl;
				postfix.resize(0);
				s->clear();
			}
				
	
		}
	}
	
	return 0;


}