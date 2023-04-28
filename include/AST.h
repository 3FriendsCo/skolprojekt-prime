#pragma once
#include <vector>
#include "error.h"
#include "token.h"

enum AST_node_type{
    AST_UNKNOWN = -1,
    AST_STATEMENT_TERMINATOR,

    AST_EOF,
    AST_PREPROCESSOR
};

struct AST_node {
    AST_node_type type;
    Token_type token_type;
    std::string value;
    std::vector<AST_node*> children;
};

void expects() {
    //expects the next token to be a certain type
}

namespace Unknown {
    inline AST_node Unknown(std::vector<AST_node>* AST) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
}

namespace Pre_processor {
    inline void Seize(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        int error_code;
        //missplaced preprocessor
        //"seize": Preprocessor that binds file to start in a group of files
        //move the preprocessor to start of file
        if(true) {
            // ERROR HANDLING
            prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
        } else if(true) {
            // ERROR HANDLING
            // ...
            prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
        } else {
            AST->emplace_back(AST_node{AST_PREPROCESSOR, SEIZE, "seize"});
        }
        prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
    }
    inline int Liberate(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        int error_code;
        //missplaced preprocessor
        //"seize": Preprocessor that binds file to start in a group of files
        //move the preprocessor to start of file
        if(true) {
            // ERROR HANDLING
            prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
        } else if(true) {
            // ERROR HANDLING
            // ...
            prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
        } else {
            AST->emplace_back(AST_node{AST_PREPROCESSOR, LIBERATE, "liberate"});
        }
        prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
    }
    inline int Banish(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        int error_code;
        //missplaced preprocessor
        //"seize": Preprocessor that binds file to start in a group of files
        //move the preprocessor to start of file
        if(true) {
            // ERROR HANDLING
            prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
        } else if(true) {
            // ERROR HANDLING
            // ...
            prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
        } else {
            std::vector<AST_node*> ere;
            AST->emplace_back(AST_node{AST_PREPROCESSOR, BANISH, "banish", ere});
        }
        prime_error::parser::log_error(compiletime_start, error_code, current_pos, row, current_char, line);
    }
    inline AST_node Force(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_force;
        return pre_process_force;
    }
};

namespace Primitive_type {
    namespace Numeric_type {
        // Integer:
        inline AST_node byte(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
        {
            AST_node pre_process_byte;
            return pre_process_byte;
        }
        inline AST_node Short(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
        {
            AST_node pre_process_short;
            return pre_process_short;
        }
        inline AST_node Int(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
        {
            AST_node pre_process_int;
            return pre_process_int;
        }
        inline AST_node Long(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
        {
            AST_node pre_process_long;
            return pre_process_long;
        }
        // Floating point:
        inline AST_node Float(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
        {
            AST_node pre_process_float;
            return pre_process_float;
        }
        inline AST_node Double(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
        {
            AST_node pre_process_double;
            return pre_process_double;
        }
    }

    inline AST_node Boolean(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_boolean;
        return pre_process_boolean;
    }
    inline AST_node Char(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_char;
        return pre_process_char;
    }
    inline AST_node Void(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_void;
        return pre_process_void;
    }

}

namespace Nonprimitive_type {
    inline AST_node String(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_string;
        return pre_process_string;
    }
}

namespace Conditional_statement {
    inline AST_node If(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_if;
        return pre_process_if;
    }
    inline AST_node Else(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_else;
        return pre_process_else;
    }
    inline AST_node Switch(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_switch;
        return pre_process_switch;
    }
}

namespace Loop {
    inline AST_node While(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_while;
        return pre_process_while;
    }
    inline AST_node Loop(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_loop;
        return pre_process_loop;
    }
    inline AST_node For(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_for;
        return pre_process_for;
    }
}

namespace Control_flow_statement {
    inline AST_node Continue(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_continue;
        return pre_process_continue;
    }
    inline AST_node Break(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_break;
        return pre_process_break;
    }
}

namespace IO {
    inline AST_node Log(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_log;
        return pre_process_log;
    }
    inline AST_node Formatted_Log(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_formatted_log;
        return pre_process_formatted_log;
    }
    inline AST_node Read(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_read;
        return pre_process_read;
    }
    inline AST_node Formatted_Read(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_formatted_read;
        return pre_process_formatted_read;
    }
    inline AST_node Write(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_write;
        return pre_process_write;
    }
    inline AST_node Formatted_Write(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_formatted_write;
        return pre_process_formatted_write;
    }
    // NOTE (MISSING)
    // FILE_TOKEN (MISSING)
}

namespace Symbol {
    inline AST_node Dot(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_dot;
        return pre_process_dot;
    }
    inline AST_node Comma(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_comma;
        return pre_process_comma;
    }
    inline AST_node Colon(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_colon;
        return pre_process_colon;
    }
    inline AST_node Semicolon(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_semicolon;
        return pre_process_semicolon;
    }
    inline AST_node Questionmark(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_questionmark;
        return pre_process_questionmark;
    }
    inline AST_node Exclamationpoint(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_questionmark;
        return pre_process_questionmark;
    }
    inline AST_node Single_Qoute(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Double_Qoute(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Left_Parenthesis(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Right_Parenthesis(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Left_Curlybracket(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Right_Curlybracket(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Left_Bracket(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Right_Bracket(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Line(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Hash(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node At_Symbol(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Dollar(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Reference_Symbol(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Procent_Symbol(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node And_Symbol(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Underline(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Back_Slash(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Backtick(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Circumflex(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Tilde(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Section_Symbol(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Plus(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Minus(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Astrisk(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Forward_Slash(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Less_Than(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
    inline AST_node Greater_Than(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_seize;
        return pre_process_seize;
    }
}

namespace Complex_type {
    inline AST_node Struct(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_struct;
        return pre_process_struct;
    }
    inline AST_node Class(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_class;
        return pre_process_class;
    }
    inline AST_node Enum(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_enum;
        return pre_process_enum;
    }
}

namespace Function {
    inline AST_node Main(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_main;
        return pre_process_main;
    }
    inline AST_node Function(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_function;
        return pre_process_function;
    }
    inline AST_node Return(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_return;
        return pre_process_return;
    }
}

namespace Scope {
    inline AST_node Using(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_using;
        return pre_process_using;
    }
    inline AST_node Namespace(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_namespace;
        return pre_process_namespace;
    }
    inline AST_node Enum(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_enum;
        return pre_process_enum;
    }
}

namespace Native_namespace {
    inline AST_node Basic_Namespace(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_basic_namespace;
        return pre_process_basic_namespace;
    }
}

namespace Attribute {
    inline AST_node Global(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_global;
        return pre_process_global;
    }
    inline AST_node Static(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_static;
        return pre_process_static;
    }
    inline AST_node Const(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line) {
        AST_node pre_process_const;
        return pre_process_const;
    }
    inline AST_node Unsigned(std::vector<AST_node>* AST, clock_t& compiletime_start, int current_pos, int row, char current_char, const std::string& line)
    {
        AST_node pre_process_unsigned;
        return pre_process_unsigned;
    }
}