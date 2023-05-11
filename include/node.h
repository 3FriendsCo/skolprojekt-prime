#pragma once
#include <string>
#include <vector>

namespace Node {
    struct node
    {
        std::vector<node *> children;
        node *parent;
        // std::string LLVM_IR;
    };
}

class Program : public Node::node {

};

class End_of_statement : public Node::node {

};

class End_of_line : public Node::node {

};

class End_of_file : public Node::node {

};

class Unknown : public Node::node {

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
