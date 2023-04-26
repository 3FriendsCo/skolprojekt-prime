#pragma once
#include <vector>

enum AST_node_type{
    AST_UNKNOWN = -1,
    AST_END_OF_FILE,
    AST_SEMICOLON,

    AST_SEIZE,
    AST_LIBERATE,
    AST_BANISH,


    AST_TOK_NUMBER,


    AST_TOK_PLUS,
    AST_TOK_MINUS,
    AST_TOK_MULTIPLY,
    AST_TOK_DIVIDE,
    AST_TOK_MODULUS,


    AST_TOK_LPAREN,
    AST_TOK_RPAREN,

    AST_STATEMENTS,

    AST_INT,
    AST_FLOAT,
    AST_DOUBLE,
    AST_LONG,
    AST_CHAR,
    AST_STRING,


    //AST_NULL_PTR, AST_VOID_PTR, AST_INT_PTR, AST_CHAR_PTR,
    AST_CLASS,
    AST_FUNCTION,


    AST_MESSAGE,
    AST_LOG,
};

struct AST_node {
    AST_node_type type;
    int value;
    std::vector<AST_node*> children;
};

class Pre_processor {
    
};