#include "Num_Command.h"


Num_Command::Num_Command(Stack<int> & s, int n):Expr_Command(), stack_(&s), number_(n)
{
   
}
Num_Command::~Num_Command()
{
}
void Num_Command::execute()
{
   this->stack_->push(this->number_);
}