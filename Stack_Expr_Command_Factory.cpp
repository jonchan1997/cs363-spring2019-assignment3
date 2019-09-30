#include "Stack_Expr_Command_Factory.h"
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack<int> & s):Expr_Command_Factory (),stack_(&s)
{

}
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory()
{

}
Num_Command * Stack_Expr_Command_Factory::create_number_command (int num)
{
    return new Num_Command(*this->stack_, num);
}
Add_Command * Stack_Expr_Command_Factory::create_add_command ()
{
    return new Add_Command(*this->stack_);
}
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command ()
{
    return new Subtract_Command(*this->stack_);
}
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command ()
{
    return new Multiply_Command(*this->stack_);
}
Divide_Command * Stack_Expr_Command_Factory::create_divide_command ()
{
    return new Divide_Command(*this->stack_);
}