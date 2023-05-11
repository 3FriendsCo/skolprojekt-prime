#pragma once
<<<<<<< HEAD

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
=======
>>>>>>> e17ec5651b43b7ad83b9660336f09d712037329e
