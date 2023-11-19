/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     CHAR = 259,
     VOID = 260,
     IF = 261,
     ELSE = 262,
     FOR = 263,
     RETURN = 264,
     IDENTIFIER = 265,
     PUNCT = 266,
     OR = 267,
     AND = 268,
     LE = 269,
     GE = 270,
     EQ = 271,
     NEQ = 272,
     POINT = 273,
     ASSIGN = 274,
     SEMICOLON = 275,
     LPAREN = 276,
     RPAREN = 277,
     LBRACKET = 278,
     RBRACKET = 279,
     COMMA = 280,
     LBRACE = 281,
     RBRACE = 282,
     MULT = 283,
     UAND = 284,
     PLUS = 285,
     MINUS = 286,
     PERCENTAGE = 287,
     NOT = 288,
     DIV = 289,
     LT = 290,
     GT = 291,
     QUESTION = 292,
     COLON = 293,
     CHARCONSTANT = 294,
     STRNGLTRL = 295,
     INTCONSTANT = 296,
     LOWER_THAN_ELSE = 297
   };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define VOID 260
#define IF 261
#define ELSE 262
#define FOR 263
#define RETURN 264
#define IDENTIFIER 265
#define PUNCT 266
#define OR 267
#define AND 268
#define LE 269
#define GE 270
#define EQ 271
#define NEQ 272
#define POINT 273
#define ASSIGN 274
#define SEMICOLON 275
#define LPAREN 276
#define RPAREN 277
#define LBRACKET 278
#define RBRACKET 279
#define COMMA 280
#define LBRACE 281
#define RBRACE 282
#define MULT 283
#define UAND 284
#define PLUS 285
#define MINUS 286
#define PERCENTAGE 287
#define NOT 288
#define DIV 289
#define LT 290
#define GT 291
#define QUESTION 292
#define COLON 293
#define CHARCONSTANT 294
#define STRNGLTRL 295
#define INTCONSTANT 296
#define LOWER_THAN_ELSE 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "A4_13.y"
{ // Placeholder for a value
	int intval;
  char* strval;
	struct symtab *symp;
}
/* Line 1529 of yacc.c.  */
#line 139 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

