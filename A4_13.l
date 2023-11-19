%option yylineno
%{
#include "y.tab.h"
#include "parser.h"
%}
/* Regular Expression Definitions */

VOID "void"
CHAR "char"
INT "int"
IF "if"
ELSE "else"
FOR "for"
RETURN "return"
IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*
INTCONSTANT 0|[+|\-]?[1-9][0-9]* 
LEADINGZERO [0]+[1-9]*

PUNCTUATOR (\[|\]|\(|\)|\{|\}?|\*|\+|-|\/|%|!|\?|<|>|:|,)
PERCENTAGE '%'
SEMICOLON ';'
POINT "->"
EQ "=="
NEQ "!="
LE "<="
GE ">="
AND "&&"
OR "||"
WS [ \t\n]+

CCHARSOURCE [^'\\]
ESCAPECHAR [\\][fbav?trn'\\]
CCHAR {CCHARSOURCE}|{ESCAPECHAR}
CCHARSEQ {CCHAR}+
CHARCONSTANT '{CCHARSEQ}+'

SCHARSOURCE [^"\\]
SCHAR {SCHARSOURCE}|{ESCAPECHAR}
SCHARSEQ {SCHAR}+
STRNGLTRL \"{SCHARSEQ}+\"

MULTILINECOMM \/\([^]|\+[^/]\)\*+\/
SINGLELINECOMM \/\/.*\n
COMMENT {MULTILINECOMM}|{SINGLELINECOMM}

NEWLINE \n

/* Definitions of Rules \& Actions */
%%
\=                  { return ASSIGN; }
\;                  { return SEMICOLON; }
{VOID}              { return VOID; }
{CHAR}              { return CHAR; }
{INT}               { return INT; }
{IF}                { return IF; }
{ELSE}              { return ELSE; }
{FOR}               { return FOR; }
{RETURN}            { return RETURN; } 
{IDENTIFIER}        { yylval.strval = symlook(yytext); return IDENTIFIER; }
{INTCONSTANT}       { yylval.intval = atoi(yytext); return INTCONSTANT; }
{LEADINGZERO}       { /* Do nothing */; }
\%                  { return PERCENTAGE; }
\-\>                { return POINT; }
\=\=                { return EQ; }
\!\=                { return NEQ; }
\<\=                { return LE; }
\>\=                { return GE; }
\>                  { return GT; }
\<                  { return LT; }
\&\&                { return AND; }
\|\|                { return OR; }
\&                  { return UAND; }
\*                  { return MULT; }
\+                  { return PLUS; }
\-                  { return MINUS; }
\/                  { return DIV; }
\!                  { return NOT; }
\?                  { return QUESTION; }
\:                  { return COLON; }
\,                  { return COMMA; }
\)                  { return RPAREN; }
\(                  { return LPAREN; }
\]                  { return RBRACKET; }
\[                  { return LBRACKET; }
\}                  { return RBRACE; }
\{                  { return LBRACE; }

{PUNCTUATOR}        { /* Do nothing */;}
{CHARCONSTANT}      { return CHARCONSTANT; }
{STRNGLTRL}         { return STRNGLTRL; }
{NEWLINE}           { /* Do nothing */; }
{COMMENT}           { /* Do nothing */; }
{WS}                { /* Do nothing */; }
%%
/* C Functions */

int yywrap() {
    return 1;
}
