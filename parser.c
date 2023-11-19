#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

extern void yyerror(char *s);

/* Look-up Symbol Table */
char *symlook(char *s)
{
  char *p;
  struct symtab *sp;
  for (sp = symtab; sp < &symtab[NSYMS]; sp++)
  {
    /* is it already here? */
    if (sp->name && !strcmp(sp->name, s))
      return s;
    if (!sp->name)
    {
      /* is it free */
      sp->name = strdup(s);
      return s;
    }
    /* otherwise continue to next */
  }
  // yerror("Too many symbols");
  return NULL;
  // exit(1); /* cannot continue */
} /* symlook */

// symfind returns sp if found, NULL otherwise
symboltable *symfind(char *s)
{
  symboltable *sp;
  for (sp = symtab; sp < &symtab[NSYMS]; sp++)
  {
    /* is it already here? */
    if (sp->name && !strcmp(sp->name, s))
      return sp;
    /* otherwise continue to next */
  }
  // yerror("Too many symbols");
  return NULL;
  // exit(1); /* cannot continue */
} /* symfind */

/* Update Symbol Table */
symboltable *sym_update(char *name, char *attr, union var_value new_val)
{
  symboltable *sp;
  for (sp = symtab; sp < &symtab[NSYMS]; sp++)
  {
    if (sp->name && !strcmp(sp->name, name))
    {
      if (!strcmp(attr, "type"))
      {
        sp->type = new_val.char_val;
        if (!strcmp(new_val.char_val, "INT"))
          sp->size = 4;
        else if (!strcmp(new_val.char_val, "CHAR"))
          sp->size = 1;
        else if (!strcmp(new_val.char_val, "VOID"))
          sp->size = 0;
        else
          sp->size = 0;
      }
      else if (!strcmp(attr, "initial_value"))
      {
        // sp->value = new_val.int_val;
        sp->initial_value = new_val.char_val;
        // sp->value = new_val.char_val;
      }
      else if (!strcmp(attr, "offset"))
      {
        sp->offset = new_val.int_val;
      }
      else
      {
        yyerror("Invalid attribute");
        exit(1);
      }
      return sp;
    }
    if (!sp->name)
    {
    }
    /* otherwise continue to next */
  }

} /* update */

void print_symbol_table()
{
  printf("\nSymbol Table:\n");
  int i;
  for (i = 0; i < NSYMS; i++)
  {
    if (symtab[i].name)
    {
      printf("Entry %d:\t name = %s\t type = %s\t initial_value = %s\t size = %d\t offset = %d\t nested table = %s\n", i, symtab[i].name, symtab[i].type, symtab[i].initial_value, symtab[i].size, symtab[i].offset, symtab[i].nested);
    }
  }
}

/* Generate temporary variable */
char *gentemp(char *val)
{
  static int c = 0; /* Temp counter */
  char *str[10];    /* Temp name */
  /* Generate temp name */
  sprintf(str, "t%02d", c++);
  /* Add temporary to symtab */
  symlook(str);

  union var_value new_val;
  new_val.char_val = val;

  sym_update(str, "initial_value", new_val);

  return strdup(str);
}

char *convert_int_to_string(int num)
{
  char *str = (char *)malloc(100 * sizeof(char));
  sprintf(str, "%d", num);
  return str;
}

int convert_string_to_int(char *str)
{
  int num = atoi(str);
  return num;
}

quad *new_quad_binary(char *s1, char *s2, char *s3, char *s4)
{
  quad *q = (quad *)malloc(sizeof(quad));
  q->op_type = "binary";
  q->result = strdup(s1);
  q->op = strdup(s2);
  q->arg1 = strdup(s3);
  q->arg2 = strdup(s4);
  return q;
}

quad *new_quad_unary(char *s1, char *s2, char *s3)
{
  quad *q = (quad *)malloc(sizeof(quad));
  q->op_type = "unary";
  q->result = strdup(s1);
  q->op = strdup(s2);
  q->arg1 = strdup(s3);
  q->arg2 = 0;
  return q;
}

void print_quad(quad *q)
{
  if (q->op_type == "binary")
  {
    printf("%s = %s %s %s\n", q->result, q->arg1, q->op, q->arg2);
  }
  else if (q->op_type == "unary")
  {
    printf("%s %s %s\n", q->result, q->op, q->arg1);
  }
}

void print_quad_table()
{
  printf("\nQuad Table:\n");
  int i;
  extern int quadPtr;
  for (i = 0; i < quadPtr; i++)
  {
    if (qArray[i]->result)
    {
      printf("Address %d:\t result: %s\t arg1: %s\t op: %s\t arg2: %s\n", i, qArray[i]->result, qArray[i]->arg1, qArray[i]->op, qArray[i]->arg2);
    }
  }
}

void print_tac()
{
  printf("\nTAC:\n");
  extern int quadPtr;
  for (int i = 0; i < quadPtr; ++i)
  {
    print_quad(qArray[i]);
  }
}
