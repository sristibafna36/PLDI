#ifndef PARSER_H
#define PARSER_H

typedef struct symtab
{
  char *name;
  char *type;
  char *initial_value;
  int size;
  int offset;
  char *nested;

} symboltable;

/* Support for Lazy TAC generation through Quad array */

#define NSYMS 100

symboltable symtab[NSYMS];

char *gentemp();

void emit_binary(
    char *s1,  // Result
    char *s2,  // Arg 1
    char c,    // Operator
    char *s3); // Arg 2

void emit_unary(
    char *s1, // Result
    char *s2, // Arg 1
    char c);  // Operator

void emit_copy(
    char *s1,  // Result
    char *s2); // Arg 1

char *symlook(char *);

void print_symbol_table();

typedef struct quad_tag
{
  char *op_type, *op, *result, *arg1, *arg2;
} quad;

quad *qArray[NSYMS];

quad *new_quad_binary(char *s1, char *s2, char *s3, char *s4);

quad *new_quad_unary(char *s1, char *s2, char *s3);

void print_quad(quad *q);

void print_quad_table();

void print_tac();

union var_value
{
  /* data */
  int int_val;
  char *char_val;
};

char *convert_int_to_string(int);
int convert_string_to_int(char *);

symboltable *sym_update(char *name, char *attr, union var_value new_val);

symboltable *symfind(char *);

#endif