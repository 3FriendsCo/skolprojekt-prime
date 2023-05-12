#pragma once
#include <string>
#include <vector>

namespace Node
{
    enum type
    {
        UNKNOWN,
        IDENTIFIER,

        ENUM_DEFINITION,
        ENUM_DECLARATION,

        STRUCT_DEFINITION,
        STRUCT_DECLARATION,

        UNION_DEFINITION,
        UNION_DECLARATION,

        CLASS_DEFINITION,
        CLASS_DECLARATION,
        CONSTRUCTOR_DEFINITION,
        CONSTRUCTOR_DECLARATION,
        DESTRUCTOR_DEFINITION,
        DESTRUCTOR_DECLARATION,

        FUNCTION_DEFINITION,
        FUNCTION_DECLARATION,
        MAIN_DEFINITION,
        RETURN_STATEMENT,
        FUNCTION_CALL,

        LAMBDA_DEFINITION,
        LAMBDA_DECLARATION,
        LAMBDA_CALL,

        STR_DEFINITION,
        CHAR_DEFINITION,
        INT_DEFINITION,
        FLOAT_DEFINITION,
        DOUBLE_DEFINITION,
        BOOL_DEFINITION,

        ARRAY_DEFINITION,
        LIST_DEFINITION,

    };
    struct node
    {
        type _type;
        std::string value;
        std::vector<node *> children;
        node *parent;
        // std::string LLVM_IR;
    };
}

class Program : public Node::node
{
};

class End_of_statement : public Node::node
{
};

class End_of_line : public Node::node
{
};

class End_of_file : public Node::node
{
};

class Unknown : public Node::node
{
};

class Expr_node : public Node::node
{
    Node::node LHS, RHS;
};

class Definition_node : public Node::node
{
};

class Binary_Expr_node : Expr_node
{
};

class Function_Def_node : public Definition_node
{
};
