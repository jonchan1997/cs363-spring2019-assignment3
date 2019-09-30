#include "Calculator.h"
#include "Stack.h"
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <cctype>

Calculator::Calculator()
{
}
Calculator::~Calculator()
{

}
int Calculator::prec(char input) 
{ 
	switch(input)
	{
		case '^':
			return 4;
		case '*':
		case '/':
			return 3;
		case '+':
		case '-':
			return 2;
		case '(':
			return 1;
		default:
			return -1;
	}

} 
bool Calculator::infix_to_postfix (const std::string & infix,Expr_Command_Factory & factory, Array <Expr_Command *> & postfix) 
{
	std::istringstream input(infix); // create a input stream parser std::string token;
	Expr_Command * cmd = 0; // created command object
	int place = 0;
	Stack <Expr_Command *> temp;
	Stack <int> order;
	//int t= 0;
	bool parentheses = false;
	std::string s_token;
	while (getline(input,s_token,' ' ))
	{
		if(s_token.empty())
		{
			continue;
		}
		int token = 0;
		char c_token = '\0';
		bool i_digit = false;
		//bool i_alpha = 
		try 
		{
			i_digit =isdigit(s_token.at(0));
			if(s_token.length() > 1)
			{
				i_digit =isdigit(s_token.at(1));	
			}
		}
		catch(const std::out_of_range&)
		{
			i_digit= false;
		}
		if(i_digit)
		{
			token= std::stoi(s_token);
		}
		else
		{
			c_token = s_token.at(0);
		}
		place = prec(c_token);
		switch(c_token)
		{
			case '(': // code to be executed if token = (
				order.push(place);
				parentheses = true;
				break;
			case '^': // code to be executed if token = ^
				exit(1);
				break;
			case '*': // code to be executed if token = *
				cmd = factory.create_multiply_command ();
				break;
			case '/': // code to be executed if token = /
				cmd = factory.create_divide_command ();
				break;
			case '+': // code to be executed if token = +
				cmd = factory.create_add_command ();
				break;
			case '-': // code to be executed if token = -
				cmd = factory.create_subtract_command ();
				break;
			case ')':
				
				while(order.top() != 1)
				{
					postfix.resize(postfix.size() + 1);
					postfix.set(postfix.size() - 1, temp.top());
					temp.pop();
					order.pop();
				}
				order.pop();
				parentheses = false;
				break;
			default: // code to be executed if token is number
				if(i_digit)
				{
					cmd = factory.create_number_command (token);
					postfix.resize(postfix.size() + 1);
					postfix.set(postfix.size() - 1, cmd);
				}
				break;
		}
		if (!(i_digit) && c_token != ')' && c_token != '(' && c_token != '\0')
		{
			while(!(temp.is_empty()) && order.top() >= place)
			{
				postfix.resize(postfix.size() + 1);
				postfix.set(postfix.size() - 1, temp.top());
				temp.pop();
				order.pop();
			}
			temp.push(cmd);
			order.push(place);
		}
		
	}
	if(parentheses)	
	{
		std::cout <<  "Failure to use proper syntax!(parentheses)"<< temp.size() << std::endl;
		return false;
	}	
	if(!(temp.is_empty()))
	{	
		for(size_t b = postfix.size(); temp.size() > 0; b++ )
		{
			postfix.resize(postfix.size() + 1);
			postfix.set(b, temp.top());
			temp.pop();
			order.pop();
		}
	}
	return true;
}
void Calculator::solve(Array <Expr_Command *> & postfix)
{
    for(size_t b= 0; b < postfix.size(); b++)
	{
		postfix.get(b)->execute();
	}

}