#include "Binary_Op_Command.h"


Binary_Op_Command::Binary_Op_Command(Stack<int> & s):Expr_Command(), stack_(&s)
{
   /** int * copy_data = new int[s.size()];
    size_t r = s.size()-1;
    for(size_t i = 0; i < s.size(); i++)
    {
        copy_data[i]=s.top();
        s.pop(); 
    }
    for(size_t p = 0; p < this->stack_.size(); p++)
    {
        this->stack_.push(copy_data[r]);
        r--;
    }
    delete [] copy_data;*/
    
}
Binary_Op_Command::~Binary_Op_Command()
{
}
void Binary_Op_Command::execute()
{
    int n1 = this->stack_->top();
    this->stack_->pop(); 
    int n2 = this->stack_->top();
    this->stack_->pop();
    int result = this->evaluate(n1, n2);
    this->stack_->push(result);
}