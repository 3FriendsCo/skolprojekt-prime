#pragma once

namespace Node {
    enum type {
        UNKNOWN
    };
    struct node
    {
        type type;
        std::string value;
        std::vector<node *> children;
        node *parent;
        // std::string LLVM_IR;
    };
}

class Expr_node : public Node::node
{
    Node::node LHS, RHS;
};

class Definition_node : public Node::node
{
    
};

class Binary_Expr_node : Expr_node
{
    //
};

class Function_Def_node : public Definition_node
{
};