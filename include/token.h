#pragma once
#include <unordered_map>
#include <string>

enum Token_type{
    UNKNOWN = -5,
    IDENTIFIER = -4,

    MESSAGE = -3,
    CHARACTER = -2,
    SPACE = -1,

    SEIZE = 0,
    LIBERATE = 1,
    BANISH = 2,
    
    GLOBAL = 3,STATIC = 4,CONST = 5,
    MAIN = 6,FUNCTION = 7,RETURN = 8,
    USING = 9,
    ENUM = 10,NAMESPACE = 11,STRUCT = 12,CLASS = 13,
    UNSIGNED = 14,SHORT = 15,INT = 16,LONG = 17,FLOAT = 18,DOUBLE = 19,BOOLEAN = 20,CHAR = 21,STRING = 22,
    IF = 23,ELSE = 24,
    CONTINUE = 25,BREAK = 26,
    WHILE = 27,LOOP = 28,FOR = 29,
    SWITCH = 30,

    BASIC_NAMESPACE = 31,

    LOG = 32,FORMATED_LOG = 33,READ = 34,FORMATED_READ = 35,WRITE = 36,FORMATED_WRITE = 37,

    // Keyword to be added:
    NUMBER = 100,
    END = 1000,
    CLOSE = 2312,

    DOT = 101,
    COMMA = 102,
    COLON = 103,
    SEMICOLON = 104,
    QUESTIONMARK = 105,EXCLAMATIONPOINT = 106,
    
    SINGLE_QOUTE = 107,DOUBLE_QOUTE = 108,
   
    L_PAREN = 109,R_PAREN = 110,

    L_CURLBRACKET = 111,R_CURLBRACKET = 112,L_BRACKET = 113,R_BRACKET = 114,
    LINE = 115,
    HASH = 116,
    AT_S = 117,
    DOLLAR = 118,
    REFERENCE_S = 119,
    PROCENT_S = 120,

    AND_S = 121,
    UNDERLINE = 122,
    B_SLASH = 123,
    BACKTICK = 124,
    CIRCUMFLEX = 125,
    TILDE = 126,
    SECTION_S = 127,
    PLUS = 128,
    MINUS = 129,
    ASTRISK = 130,
    DIVIDE = 131,
   
    LESS_THAN = 132,GREATER_THAN = 133
};

Token_type match_to_prime_keyword(const std::string &keyword) {
    static const std::unordered_map<std::string, Token_type> prime_keywords = {
        {"seize", SEIZE}, {"liberate", LIBERATE}, {"banish", BANISH},
        {"global", GLOBAL}, {"static", STATIC}, {"const", CONST},
        {"main", MAIN}, {"fn", FUNCTION}, {"return", RETURN},
        {"using", USING},
        {"enum", ENUM}, {"namespace", NAMESPACE}, {"struct", STRUCT}, {"class", CLASS},
        {"unsigned", UNSIGNED}, {"short", SHORT}, {"int", INT}, {"long", LONG},
        {"float", FLOAT}, {"double", DOUBLE}, {"boolean", BOOLEAN},
        {"char", CHAR}, {"string", STRING},
        {"if", IF}, {"else", ELSE},
        {"continue", CONTINUE}, {"break", BREAK},
        {"while", WHILE}, {"loop", LOOP}, {"for", FOR},
        {"switch", SWITCH},
        
        {"bas", BASIC_NAMESPACE},
        {"log", LOG}, {"logf", FORMATED_LOG}, {"read", READ}, {"readf", FORMATED_READ},
        {"write", WRITE}, {"writef", FORMATED_WRITE}, {"file", NUMBER},

        {".", DOT}, {",", COMMA}, {":", COLON}, {";", SEMICOLON},
        {"?", QUESTIONMARK}, {"!", EXCLAMATIONPOINT},
        {"'", SINGLE_QOUTE}, {"\"", DOUBLE_QOUTE},
        {"(", L_PAREN}, {")", R_PAREN},
        {"{", L_CURLBRACKET}, {"}", R_CURLBRACKET},
        {"[", L_BRACKET}, {"]", R_BRACKET},
        {"|", LINE}, {"#", HASH}, {"@", AT_S}, {"$", DOLLAR}, {"¤", REFERENCE_S},
        {"%", PROCENT_S}, {"&", AND_S}, {"_", UNDERLINE}, {"\\", B_SLASH},
        {"`", BACKTICK}, {"^", CIRCUMFLEX}, {"~", TILDE}, {"§", SECTION_S},
        {"+", PLUS}, {"-", MINUS}, {"*", ASTRISK}, {"/", DIVIDE},
        {"<", LESS_THAN}, {">", GREATER_THAN}
    };

    auto it = prime_keywords.find(keyword);
    return it != prime_keywords.end() ? it->second : UNKNOWN;
}