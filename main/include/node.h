#pragma once

struct AST_node
{
    AST_type type;
    std::string value;
    std::vector<AST_node *> children;
    AST_node *parent;
    // std::string LLVM_IR;
};

class Expr_node : public AST_node
{
    token LHS, RHS;
};

class Definition_node : public AST_node
{
    
};

class Binary_Expr_node : Expr_node
{
    //
};

class Function_Def_node : public Definition_node
{
};