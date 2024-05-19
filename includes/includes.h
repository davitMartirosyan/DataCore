#ifndef INCLUDES_H
#define INCLUDES_H

#define __DATABASE__ "./db/db.sql"
#define __METADATA__ "./meta/"

#define __DATABASE_FORMAT__ "%d:%d:%s:%s:%s\n"
#define __SET__ " \n\t\r\b"

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <readline/readline.h>
#include "./structs.h"
#include "../libft/libft.h"

//CRUDLS - > Create - Retrieve - Update - Delete - List - Sort

//Orion
Orion       *dc_query(table_t *table, char *query);

//void
void        dc_create(table_t *table, char *query);
void        dc_add(table_t *table, char *query);
void        dc_retrieve(table_t *table, char *query);
void        dc_update(table_t *table, char *query);
void        dc_delete(table_t *table, char *query);
void        dc_list(table_t *table, char *query);
void        dc_sort(table_t *table, char *query);


//table : utils
table_t     *dc_init(char *db);
void        dc_cleanup(table_t **table);
void        __construct(table_t **table);
void        __destruct(table_t **table);


//tokenization
query_t     *lexer(char *query);
int         expansion(query_t *tok, char *query, int*i);
int         identify(query_t *tok, char *query, int *i);
void        addword(query_t *tok, char *query, int *i);
int         checkFields(char **fields, int size);
int         isValid(char *field);
int         validType(char *type);

// void        expansionopen(query_t *tok, char *query, int *i);
// void        expansionclose(query_t *tok, char *query, int *i);
// void        addexpfield(query_t *tok, char *query, int *i);

querytok_t  *create_node(char *word, type_t type);
void        append_node(querytok_t **tokens, char *word, type_t type);
void        print_tokens(querytok_t *toks);


//Garbage collector
void		free_fields(char ***field);

// void        create_node(querytok_t **tokens, char *word, type_t type);

#endif
