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

namespace Unknown {
    inline AST_node Unknown() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
}

namespace Pre_processor {
    // PRE-PROCESSORS:
    inline AST_node Seize() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Liberate() {
        AST_node pre_process_liberate;
        return pre_process_liberate;
    }
    inline AST_node Banish() {
        AST_node pre_process_banish;
        return pre_process_banish;
    }
    inline AST_node Force() {
        AST_node pre_process_force;
        return pre_process_force;
    }
};

namespace Primitive_type {
    namespace Numeric_type {
        // Integer:
        inline AST_node byte()
        {
            AST_node pre_process_byte;
            return pre_process_byte;
        }
        inline AST_node Short()
        {
            AST_node pre_process_short;
            return pre_process_short;
        }
        inline AST_node Int()
        {
            AST_node pre_process_int;
            return pre_process_int;
        }
        inline AST_node Long()
        {
            AST_node pre_process_long;
            return pre_process_long;
        }
        // Floating point:
        inline AST_node Float()
        {
            AST_node pre_process_float;
            return pre_process_float;
        }
        inline AST_node Double()
        {
            AST_node pre_process_double;
            return pre_process_double;
        }
    }

    inline AST_node Boolean()
    {
        AST_node pre_process_boolean;
        return pre_process_boolean;
    }
    inline AST_node Char()
    {
        AST_node pre_process_char;
        return pre_process_char;
    }
    inline AST_node Void()
    {
        AST_node pre_process_void;
        return pre_process_void;
    }

}

namespace Nonprimitive_type {
    inline AST_node String()
    {
        AST_node pre_process_string;
        return pre_process_string;
    }
}

namespace Conditional_statement {
    inline AST_node If()
    {
        AST_node pre_process_if;
        return pre_process_if;
    }
    inline AST_node Else()
    {
        AST_node pre_process_else;
        return pre_process_else;
    }
    inline AST_node Switch()
    {
        AST_node pre_process_switch;
        return pre_process_switch;
    }
}

namespace Loop {
    inline AST_node While()
    {
        AST_node pre_process_while;
        return pre_process_while;
    }
    inline AST_node Loop()
    {
        AST_node pre_process_loop;
        return pre_process_loop;
    }
    inline AST_node For()
    {
        AST_node pre_process_for;
        return pre_process_for;
    }
}

namespace Control_flow_statement {
    inline AST_node Continue()
    {
        AST_node pre_process_continue;
        return pre_process_continue;
    }
    inline AST_node Break()
    {
        AST_node pre_process_break;
        return pre_process_break;
    }
}

namespace IO {
    inline AST_node Log()
    {
        AST_node pre_process_log;
        return pre_process_log;
    }
    inline AST_node Formatted_Log()
    {
        AST_node pre_process_formatted_log;
        return pre_process_formatted_log;
    }
    inline AST_node Read()
    {
        AST_node pre_process_read;
        return pre_process_read;
    }
    inline AST_node Formatted_Read()
    {
        AST_node pre_process_formatted_read;
        return pre_process_formatted_read;
    }
    inline AST_node Write()
    {
        AST_node pre_process_write;
        return pre_process_write;
    }
    inline AST_node Formatted_Write()
    {
        AST_node pre_process_formatted_write;
        return pre_process_formatted_write;
    }
    // NOTE (MISSING)
    // FILE_TOKEN (MISSING)
}

namespace Symbol {
    inline AST_node Dot()
    {
        AST_node pre_process_dot;
        return pre_process_dot;
    }
    inline AST_node Comma()
    {
        AST_node pre_process_comma;
        return pre_process_comma;
    }
    inline AST_node Colon()
    {
        AST_node pre_process_colon;
        return pre_process_colon;
    }
    inline AST_node Semicolon()
    {
        AST_node pre_process_semicolon;
        return pre_process_semicolon;
    }
    inline AST_node Questionmark()
    {
        AST_node pre_process_questionmark;
        return pre_process_questionmark;
    }
    inline AST_node Exclamationpoint()
    {
        AST_node pre_process_questionmark;
        return pre_process_questionmark;
    }
    inline AST_node Single_Qoute() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Double_Qoute() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Left_Parenthesis() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Right_Parenthesis() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Left_Curlybracket() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Right_Curlybracket() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Left_Bracket() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Right_Bracket() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Line() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Hash() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node At_Symbol() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Dollar() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Reference_Symbol() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Procent_Symbol() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node And_Symbol() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Underline() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Back_Slash() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Backtick() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Circumflex() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Tilde() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Section_Symbol() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Plus() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Minus() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Astrisk() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Forward_Slash() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Less_Than() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Greater_Than() {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
}

namespace Complex_type {
    inline AST_node Struct()
    {
        AST_node pre_process_struct;
        return pre_process_struct;
    }
    inline AST_node Class()
    {
        AST_node pre_process_class;
        return pre_process_class;
    }
    inline AST_node Enum()
    {
        AST_node pre_process_enum;
        return pre_process_enum;
    }
}

namespace Function {
    inline AST_node Main() {
        AST_node pre_process_main;
        return pre_process_main;
    }
    inline AST_node Function() {
        AST_node pre_process_function;
        return pre_process_function;
    }
    inline AST_node Return() {
        AST_node pre_process_return;
        return pre_process_return;
    }
}

namespace Scope {
    inline AST_node Using()
    {
        AST_node pre_process_using;
        return pre_process_using;
    }
    inline AST_node Namespace()
    {
        AST_node pre_process_namespace;
        return pre_process_namespace;
    }
    inline AST_node Enum()
    {
        AST_node pre_process_enum;
        return pre_process_enum;
    }
}

namespace Native_namespace {
    inline AST_node Basic_Namespace()
    {
        AST_node pre_process_basic_namespace;
        return pre_process_basic_namespace;
    }
}

namespace Attribute {
    inline AST_node Global() {
        AST_node pre_process_global;
        return pre_process_global;
    }
    inline AST_node Static() {
        AST_node pre_process_static;
        return pre_process_static;
    }
    inline AST_node Const() {
        AST_node pre_process_const;
        return pre_process_const;
    }
    inline AST_node Unsigned()
    {
        AST_node pre_process_unsigned;
        return pre_process_unsigned;
    }
}